.. include:: <mmlalias.txt>


Cross Development
=================

.. contents::
   :local:


Native Compilation
------------------

* Compiler runs on a machine, say ``x86_64``
* Produces code *for that machine*
* Uses header files and libraries from that machine
* Default *paths* for headers and libraries

  * ``/usr/include``: e.g. ``#include <stdio.h>`` is found as
    ``/usr/include/stdio.h``
  * ``/usr/lib``, ``/lib64``, ...: e.g. ``-lpthread`` ("linker, please
    go find me the ``pthread`` library") is resolved to
    ``/lib64/libpthread.so``

Cross?
------

.. sidebar::

   **See also**

   * :doc:`/blog/2022/09/cross-raspi`
   * :doc:`/trainings/material/soup/linux/toolchain/raspberry-pi/toolchain-build-docker-fedora`

* Compiler runs on *host* machine (e.g. ``x86_64``)
* Produces code for the *target* machine (e.g. ``armv7l``)

**Simple?** |longrightarrow| No

* Code must be built against *target situation*
* Header files and libraries
* |longrightarrow| must be available on *host*

  * |longrightarrow| ``sysroot``

* Must match the target situation |longrightarrow| binary
  compatibility
* Statically linked cross build generally ok
* *But:* shared libraries are a continuous source of pain

**Challenges**

* Cross compiler: finding or building one that works

  * Trial and error, mostly
  * Building one: `crosstool-ng <https://crosstool-ng.github.io/>`__
  * Using a metadistribution like `Yocto
    <https://www.yoctoproject.org/>`__: gives you a cross toolchain as
    by-product of creating the *target rootfilesystem*

* ``sysroot``

  * Target root filesystem, in principle
  * Ideally stripped down to a miniumum

    * Don't need target *executables* on the host, for example (they
      won't run)

  * Ideally a by-product of root filesystem creation

Example: Cross Toolchain And ``sysroot`` Built With `crosstool-ng <https://crosstool-ng.github.io/>`__
------------------------------------------------------------------------------------------------------

.. sidebar:: See also

   * :doc:`/blog/2022/09/cross-raspi`

By default, ``ct-ng`` installs the toolchain/sysroot combo in
``~/x-tools/``

.. code-block:: console
   :caption: The Cross-Raspberry top directory

   $ ls -l ~/x-tools/
   ...
   dr-xr-xr-x. 1 jfasch jfasch      128 Apr 17  2023 armv8-rpi4-linux-gnueabihf
   ...

Structure is a bit confusing,

.. code-block:: console

   $ ls -l ~/x-tools/armv8-rpi4-linux-gnueabihf
   total 1660
   dr-xr-xr-x. 1 jfasch jfasch      60 Apr 17  2023 armv8-rpi4-linux-gnueabihf
   dr-xr-xr-x. 1 jfasch jfasch    2364 Apr 17  2023 bin
   -r--r--r--. 1 jfasch jfasch 1697265 Apr 17  2023 build.log.bz2
   dr-xr-xr-x. 1 jfasch jfasch       0 Apr 17  2023 include
   dr-xr-xr-x. 1 jfasch jfasch      98 Apr 17  2023 lib
   dr-xr-xr-x. 1 jfasch jfasch       6 Apr 17  2023 libexec
   dr-xr-xr-x. 1 jfasch jfasch      42 Apr 17  2023 share

Toolchain in ``bin/``
---------------------

.. code-block:: console

   $ ls -l ~/x-tools/armv8-rpi4-linux-gnueabihf/bin/
   ...
   -r-xr-xr-x. 2 jfasch jfasch  1078248 Apr 17  2023 armv8-rpi4-linux-gnueabihf-ar
   -r-xr-xr-x. 2 jfasch jfasch  1260352 Apr 17  2023 armv8-rpi4-linux-gnueabihf-g++
   -r-xr-xr-x. 2 jfasch jfasch  1256256 Apr 17  2023 armv8-rpi4-linux-gnueabihf-gcc
   -r-xr-xr-x. 1 jfasch jfasch      143 Apr 17  2023 armv8-rpi4-linux-gnueabihf-ld
   ...

Runs on the PC,

.. code-block:: console

   $ file ~/x-tools/armv8-rpi4-linux-gnueabihf/bin/armv8-rpi4-linux-gnueabihf-gcc
   /home/jfasch/x-tools/armv8-rpi4-linux-gnueabihf/bin/armv8-rpi4-linux-gnueabihf-gcc: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 3.2.0, BuildID[sha1]=a5540938c2c36ad2bb371ccfdeaee5e7dbc8d512, stripped

Produces output for the Raspberry Pi (``armv8``),

.. code-block:: console

   $ ~/x-tools/armv8-rpi4-linux-gnueabihf/bin/armv8-rpi4-linux-gnueabihf-gcc --verbose
   ...
   Target: armv8-rpi4-linux-gnueabihf
   ...

``sysroot`` in ``armv8-rpi4-linux-gnueabihf/sysroot/``
------------------------------------------------------

.. code-block:: console

   $ ls -l ~/x-tools/armv8-rpi4-linux-gnueabihf/armv8-rpi4-linux-gnueabihf/sysroot/
   total 0
   dr-xr-xr-x. 1 jfasch jfasch    6 Apr 17  2023 etc
   dr-xr-xr-x. 1 jfasch jfasch 1654 Apr 17  2023 lib
   dr-xr-xr-x. 1 jfasch jfasch   22 Apr 17  2023 sbin
   dr-xr-xr-x. 1 jfasch jfasch   58 Apr 17  2023 usr
   dr-xr-xr-x. 1 jfasch jfasch    4 Apr 17  2023 var

* The situation on the target, made available on the host
* Usually a single tree, containing a subset of the target's *root
  filesystem*

Cross Build
-----------

.. literalinclude:: hello.c
   :caption: :download:`hello.c (download) <hello.c>`
   :language: c

.. code-block:: console

   $ ~/x-tools/armv8-rpi4-linux-gnueabihf/bin/armv8-rpi4-linux-gnueabihf-gcc \
       --sysroot ~/x-tools/armv8-rpi4-linux-gnueabihf/armv8-rpi4-linux-gnueabihf/sysroot \
       -o hello \
       hello.c 

Produces a *target* executable,

.. code-block:: console

   $ file hello 
   /tmp/hello: ELF 32-bit LSB executable, ARM, EABI5 version 1 (SYSV), dynamically linked, interpreter /lib/ld-linux-armhf.so.3, for GNU/Linux 6.0.2, with debug_info, not stripped

Does not run on a PC (QEMU?),

.. code-block:: console

   $ ./hello 
   qemu-arm-static: Could not open '/lib/ld-linux-armhf.so.3': No such file or directory

Which shared libraries is it linked against?

.. code-block:: console

   $ ldd hello
         not a dynamic executable

Ah, wrong ``ldd``: use the cross ``ldd`` to view dependencies,

.. code-block:: console

   $ ~/x-tools/armv8-rpi4-linux-gnueabihf/bin/armv8-rpi4-linux-gnueabihf-ldd --root ~/x-tools/armv8-rpi4-linux-gnueabihf/armv8-rpi4-linux-gnueabihf/sysroot hello
           libc.so.6 => /lib/libc.so.6 (0xdeadbeef)
	   ld-linux-armhf.so.3 => /lib/ld-linux-armhf.so.3 (0xdeadbeef)

Copy to the target, and execute,

.. code-block:: console

   $ scp hello my.target.com:
   $ ssh my.target.com ./hello
   Hello World

