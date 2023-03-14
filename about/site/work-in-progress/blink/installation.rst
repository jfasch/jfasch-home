Installing Prerequisites
========================

.. contents::
   :local:

``libgpiod``
------------

Argh: python 3.9 first!
.......................

sudo apt install libffi-dev

wget  https://www.python.org/ftp/python/3.11.1/Python-3.11.1.tar.xz

tar xf ... && cd ...

configure --prefix ...  # try out of source!

make -j5



Prerequisites
.............

Fedora
``````
.. code-block:: console

   $ sudo dnf install autoconf-archive

Raspberry OS
````````````

Pi ``autoconf`` is still at version 2.69, ``libgpiod`` requires 2.70
(I guess). Don't want to go through the process of autotooling on the
Pi anyway, because the plan of autotools is to create a portable
``configure`` script, and a tarball containing all that's necessary.

**Steps**

* Proceed through the PC build below. Be aware that ``--enable-tools``
  is necessary to create tarballs.
* Once everything is built,

  .. code-block:: console

     $ pwd         # <--- in the build directory
     /home/jfasch/tmp/libgpiod-build
     $ make dist
     $ ls -1 ls -l libgpiod-*.tar.gz
     libgpiod-2.0.tar.gz

* Transfer that file to the Pi, and unpack it
* Configure the package just like you did for the PC native version
  (maybe with a different install prefix)

  .. code-block:: console

     $ /home/jfasch/work/libgpiod/configure --enable-bindings-cxx --enable-bindings-python  --enable-tools --prefix=...
     $ make

* Install into wherever, but set ``PYTHONPATH`` accordingly (the
  ``make install`` error message will describe)

  .. code-block:: console

     $ PYTHONPATH=/home/jfasch/blink/install/lib/python3.7/site-packages:$PYTHONPATH make install

Clone, and Massage
..................

.. code-block:: console

   $ git clone https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git

``autogen.sh`` does a ``configure`` step (in the source directory!) by
default; using ``NOCONFIGURE=yes`` to suppress it.

.. code-block:: console

   $ NOCONFIGURE=yes ./autogen.sh
   ... better now ...

Build
-----

.. code-block:: console

   $ mkdir ~/tmp/libgpiod-build/
   $ cd ~/tmp/libgpiod-build/

.. code-block:: console

   $ pwd         # <--- in the build directory
   /home/jfasch/tmp/libgpiod-build
   $ /home/jfasch/work/libgpiod/configure --enable-bindings-cxx --enable-bindings-python  --enable-tools --prefix=/home/jfasch/install/libgpiod
   $ make
   $ make install
