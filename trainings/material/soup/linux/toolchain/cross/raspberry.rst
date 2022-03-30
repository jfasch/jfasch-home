.. ot-topic:: linux.toolchain.cross.raspberry
   :dependencies: linux.toolchain.cross.basics,
		  linux.ssh.basics,
		  linux.ssh.scp,
		  linux.basics.archiving_compression.tar,
		  linux.basics.intro.environment

.. include:: <mmlalias.txt>


The Raspberry Toolchain
=======================

Toolchains are always a pain in the butt. Here's a writeup (as of
2022-03-29) of something that I found workable.

* It is not clean. The ``sysroot`` is not usually copied over from the
  existing target.
* By no way it gives insight into the black art of toolchain-making.
* I have no idea why the Linaro toolchain works for our ``sysroot``,
  and Fedora's ``gcc-arm-linux-gnu`` doesn't.

.. contents::
   :local:

Create a ``sysroot``
--------------------

.. sidebar::

   **Topics**

   * :doc:`../../ssh/basics`
   * :doc:`../../basics/archiving-compression/tar`

   **Documentation**

   * `man -s 1 tar
     <https://man7.org/linux/man-pages/man1/tar.1.html>`__

Lacking a precomposed ``sysroot`` that only contains what we need, we
copy over a minimal set of artifacts from the target. By trial and
error we can come up for the following remote directories that we copy
into the host's ``sysroot``,

* ``/usr/lib/arm-linux-gnueabihf``
* ``/usr/lib/gcc/arm-linux-gnueabihf``
* ``/usr/include``
* ``/lib/arm-linux-gnueabihf``

We use :doc:`SSH remote command execution <../../ssh/basics>` in a pipe
to

* Create a :doc:`tar <../../basics/archiving-compression/tar>` archive
  containing these directories, remotely
* Compress that archive onto the wire, remotely
* Uncompress from the wire, locally
* Unpack that, locally, into a directory of our choice. Lets use
  ``~/cross/`` to keep things in order.

.. code-block:: console

   $ mkdir -p ~/cross/sysroots/raspberry
   $ ssh  me@target 'tar -c -f - /usr/lib/arm-linux-gnueabihf /usr/lib/gcc/arm-linux-gnueabihf /usr/include /lib/arm-linux-gnueabihf | xz --compress' | \
        xz --decompress | \
	tar -C ~/cross/sysroots/raspberry -x -f -

Download And Unpack Linaro Toolchain
------------------------------------

.. sidebar:: 

   **Links**

   * `Linaro homepage <https://www.linaro.org/>`__
   * `Linaro toolchain download
     <https://snapshots.linaro.org/gnu-toolchain/>`__

* Download tarball (I chose the lastest). Be sure to pick the one that
  runs on ``x86_64``, not the ``aarch64`` one.

  .. code-block:: console

     $ wget -o ~/Downloads/gcc-linaro-12.0.1-2022.02-x86_64_arm-linux-gnueabihf.tar.xz \
          https://snapshots.linaro.org/gnu-toolchain/12.0-2022.02-1/arm-linux-gnueabihf/gcc-linaro-12.0.1-2022.02-x86_64_arm-linux-gnueabihf.tar.xz

* Unpack into ``~/cross/toolchains``

  .. code-block:: console

     $ mkdir -p ~/cross/toolchains
     $ tar -C ~/cross/toolchains -J -x -f ~/Downloads/gcc-linaro-12.0.1-2022.02-x86_64_arm-linux-gnueabihf.tar.xz

Test Cross Build
----------------

What We Have
............

* The target's libraries and header files in ``~/cross/sysroots/raspberry/``,

  .. code-block:: console

     $ ls -l ~/cross/sysroots/raspberry/
     total 0
     drwxrwxr-x. 1 jfasch jfasch 38 Mar 29 19:00 lib
     drwxrwxr-x. 1 jfasch jfasch 20 Mar 29 18:59 usr
  
* The cross toolchain in
  ``~/cross/toolchains/gcc-linaro-12.0.1-2022.02-x86_64_arm-linux-gnueabihf/``

  .. code-block:: console

     $ ls -l ~/cross/toolchains/gcc-linaro-12.0.1-2022.02-x86_64_arm-linux-gnueabihf/
     total 12
     drwxr-xr-x. 1 jfasch jfasch    40 Feb  5 23:47 arm-linux-gnueabihf
     drwxr-xr-x. 1 jfasch jfasch  1706 Feb  5 23:54 bin
     -rw-r--r--. 1 jfasch jfasch 10552 Feb  5 23:53 gcc-linaro-12.0.1-2022.02-linux-manifest.txt
     drwxr-xr-x. 1 jfasch jfasch    72 Feb  5 23:49 include
     drwxr-xr-x. 1 jfasch jfasch   168 Feb  5 23:54 lib
     drwxr-xr-x. 1 jfasch jfasch     6 Feb  5 23:32 libexec
     drwxr-xr-x. 1 jfasch jfasch    58 Feb  5 23:49 share

  It's the ``bin/`` subdirectory that contains the compiler, ``gcc``,
  and the other toolchain programs. All properly prefixed with
  ``arm-linux-gnueabihf-`` to distinguish them from toolchains for
  other architectures.

  .. code-block:: console

     $ ls -l ~/cross/toolchains/gcc-linaro-12.0.1-2022.02-x86_64_arm-linux-gnueabihf/bin/
     total 73812
     ...
     -rwxr-xr-x. 1 jfasch jfasch  1107168 Feb  5 23:54 arm-linux-gnueabihf-ar
     -rwxr-xr-x. 1 jfasch jfasch  1481768 Feb  5 23:54 arm-linux-gnueabihf-gcc
     -rwxr-xr-x. 1 jfasch jfasch  1968456 Feb  5 23:54 arm-linux-gnueabihf-ld
     -rwxr-xr-x. 1 jfasch jfasch  1091864 Feb  5 23:54 arm-linux-gnueabihf-nm
     -rwxr-xr-x. 1 jfasch jfasch  1030432 Feb  5 23:54 arm-linux-gnueabihf-readelf
     -rwxr-xr-x. 1 jfasch jfasch  1221816 Feb  5 23:54 arm-linux-gnueabihf-strip
     ...


Use Cross Compiler To Build Against ``sysroot``
...............................................

.. literalinclude:: ../jfasch-home-linux-toolchain/cross-basics/hello-single.c
   :caption: :download:`../jfasch-home-linux-toolchain/cross-basics/hello-single.c`
   :language: c

Run our cross compiler to compile and link that source code, against
the Raspberry situation that we have. This is where it all comes
together.

.. code-block:: console

   $ ~/cross/toolchains/gcc-linaro-12.0.1-2022.02-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc \
          --sysroot ~/cross/sysroots/raspberry \
	  -o hello-single hello-single.c 

Copy the executable over, and run it,

.. code-block:: console

   $ scp hello-single jfasch@target:
   $ ssh jfasch@target ./hello-single 
   Hello World

Voila! It works for the simplest case.

Adjust ``$PATH`` To Point To Toolchain
--------------------------------------

.. sidebar::

   **Topics**

   * :doc:`/trainings/material/soup/linux/basics/intro/environment`

Add toolchain's program directory to your ``$PATH`` environment
variable (you might want to add it to your ``~/.bashrc`` file, and
:doc:`re-source that
</trainings/material/soup/linux/basics/intro/environment>`),

.. code-block:: console

   $ PATH=/home/jfasch/cross/toolchains/gcc-linaro-12.0.1-2022.02-x86_64_arm-linux-gnueabihf/bin:$PATH
   $ export PATH

With this, you are now to just say,

.. code-block:: console

   $ arm-linux-gnueabihf-gcc --sysroot ~/cross/sysroots/raspberry -o hello-single hello-single.c 
