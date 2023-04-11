Installing Prerequisites
========================

.. contents::
   :local:

``libgpiod``
------------

A pure Pi-local build is not easily possible: Pi ``autoconf`` is still
at version 2.69, and ``libgpiod`` requires 2.70 (I guess). Don't want
to go through the process of autotooling on the Pi anyway, because the
plan of autotools is to create a portable ``configure`` script, and a
tarball containing all that's necessary.

Fedora: Prepare Tarballs
........................

* ``autoconf-archive`` is required because ``libgpiod`` uses M4 macros
  that are not present in stock ``autoconf``.

  .. code-block:: console

     $ sudo dnf install autoconf-archive

* Clone; I use ``master`` branch for no apparent reason (except that
  it works, maybe)

  .. code-block:: console
  
     $ pwd
     /home/jfasch/work/blink

     $ git clone https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git
     $ cd libgpiod
     $ git branch -a
     * master
       remotes/origin/HEAD -> origin/master
       remotes/origin/master
       remotes/origin/v0.1.x
       remotes/origin/v0.2.x
       remotes/origin/v0.3.x
       remotes/origin/v1.0.x
       remotes/origin/v1.1.x
       remotes/origin/v1.2.x
       remotes/origin/v1.3.x
       remotes/origin/v1.4.x
       remotes/origin/v1.5.x
       remotes/origin/v1.6.x
       remotes/origin/v2.0.x

* Create autotoolery

  ``autogen.sh`` does a ``configure`` step (*in the source
  directory!*) by default; use ``NOCONFIGURE=yes`` to suppress that

  .. code-block:: console
  
     $ pwd
     /home/jfasch/work/blink/libgpiod
  
     $ NOCONFIGURE=yes ./autogen.sh
     ... better now ...

* Create build directory, build locally

  To create tarballs for the final Pi build, we need to build locally
  first: manual pages are created by simply absorbing the tools
  output.

  Be aware that ``--enable-tools`` is necessary to create tarballs.

  .. code-block:: console
  
     $ pwd
     /home/jfasch/work/blink/libgpiod

     $ mkdir ../libgpiod-build
     $ cd ../libgpiod-build

  .. code-block:: console
  
     $ pwd
     /home/jfasch/work/blink/libgpiod-build

     $ ../libgpiod/configure --enable-tools
     $ make all dist-xz

  All we need from this step is ``libgpiod-2.1.tar.xz``:

  .. code-block:: console
  
     $ ls -l libgpiod-2.1.tar.xz 
     -rw-r--r--. 1 jfasch jfasch 406332 Apr  5 15:42 libgpiod-2.1.tar.xz

  Transfer tarball over to Pi:

  .. code-block:: console

     $ scp /home/jfasch/work/blink/libgpiod-build/libgpiod-2.1.tar.xz 192.168.1.82:

On The Pi: Build And Install
............................

* Prerequisites: ``setuptools``

  .. code-block:: console

     $ sudo apt install python3-pip
     $ python -m pip install setuptools 

  (Actually, ``setuptools`` is installed along with ``pip``)

* Build and install ``libgpiod`` (might want to omit
  ``--enable-bindings-cxx``)

  .. code-block:: console

     $ pwd
     /home/jfasch/blink

     $ tar xf ~/libgpiod-2.1.tar.xz
     $ cd libgpiod-2.1/
     $ ./configure --enable-bindings-cxx --enable-bindings-python  --enable-tools --prefix=/home/jfasch/blink/install
     $ make
     $ make install

* Point ``PYTHONPATH`` and ``LD_LIBRARY_PATH``

  .. code-block:: console

     $ export PYTHONPATH=/home/jfasch/blink/install/lib/python3.9/site-packages/gpiod-2.0.0-py3.9-linux-aarch64.egg/
     $ export LD_LIBRARY_PATH=/home/jfasch/blink/install/lib

