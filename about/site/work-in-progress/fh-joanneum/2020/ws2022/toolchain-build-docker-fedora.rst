.. include:: <mmlalias.txt>

Build Toolchain Using Docker (Fedora)
=====================================

.. contents::
   :local:

.. sidebar::

   **Documentation**

   * https://lynxbee.com/how-to-run-ubuntu-18-04-in-docker-container/#.Y3p9kn7MJEY

Install And Run Docker
----------------------

.. code-block:: console

   # dnf -y install dnf-plugins-core
   # dnf config-manager --add-repo https://download.docker.com/linux/fedora/docker-ce.repo
   # dnf install docker-ce docker-ce-cli containerd.io docker-compose-plugin
   # systemctl start docker
   # docker enable hello-world
   # docker run hello-world

Create Ubuntu Images (18.04 and 20.04)
--------------------------------------

.. code-block:: console

   # docker search ubuntu
   NAME                             DESCRIPTION                                     STARS     OFFICIAL   AUTOMATED
   ubuntu                           Ubuntu is a Debian-based Linux operating sys…   15244     [OK]       
   ...

Dockerhub: available tags for ``ubuntu`` image:
https://hub.docker.com/_/ubuntu |longrightarrow| ``18.04``,
``20.04``.

.. code-block:: console

   # docker create ubuntu:18.04
   # docker create ubuntu:20.04

Create Docker Volume
--------------------

.. code-block:: console

   # docker volume create raspi-toolchains     

Container Work
--------------

Command To Run Container On Volumes
...................................

* Containers are run as root
* The command to run a shell inside a container, we'll use the
  following command to run a shell in it

  .. code-block:: console
  
     # docker run \
           --interactive --tty \
	   --name raspi-toolchain-ubuntu-18.04 \
	   --mount source=raspi-toolchains,target=/var/raspi-toolchains \
	   ubuntu:18.04 \
	   /bin/bash

* Alias it, possibly making it into a script sometime

  .. code-block:: console
  
     # alias sh_18_04=\
           docker run \
               --interactive --tty \
	       --name raspi-toolchain-ubuntu-18.04 \
	       --mount source=raspi-toolchains,target=/var/raspi-toolchains \
	       ubuntu:18.04 \
	       /bin/bash

Setup container
...............

.. code-block:: console

   # sh_18_04

* Update
  
  .. code-block:: console
  
     # apt update
     # apt install -y gcc g++ gperf bison flex texinfo help2man make libncurses5-dev \
           python3-dev autoconf automake libtool libtool-bin gawk wget bzip2 xz-utils unzip \
           patch libstdc++6 rsync git meson ninja-build

* Create ``build`` user, and ``su`` into it
  
  .. code-block:: console
  
     # useradd --home-dir /home/jfasch --create-home --shell /bin/bash build
     # chown -R build:build /var/raspi-toolchains
     # su - build
     $

We will work as user ``build`` from now on.
  
Install ``autoconf 2.71``
-------------------------

``crosstool-ng`` wants ``>= 2.71``, so we have to install that
manually.

.. code-block:: console

   $ mkdir /var/raspi-toolchains/18.04
   $ cd /var/raspi-toolchains/18.04
   $ wget http://ftp.gnu.org/gnu/autoconf/autoconf-2.71.tar.xz
   $ tar xf autoconf-2.71.tar.xz
   $ cd autoconf-2.71
   $ ./configure --prefix=/var/raspi-toolchains/18.04/autoconf-2.71-install
   $ make
   $ make install
  
Point ``$PATH`` to it

.. code-block:: console

   $ export PATH=/var/raspi-toolchains/18.04/autoconf-2.71-install/bin:$PATH
  
Install ``crosstool-ng``
------------------------

Best to install from their `Git repo
<https://github.com/crosstool-ng/crosstool-ng>`__. (I had ``zlib``
version issues/Fedora with the release version that were solve in
Git.)

.. code-block:: console

   $ git clone https://github.com/crosstool-ng/crosstool-ng
   $ cd crosstool-ng/
   $ ./bootstrap 
   $ ./configure --prefix=/var/raspi-toolchains/18.04/crosstool-ng-install
   $ make
   $ make install

Point ``$PATH`` to it

.. code-block:: console

   $ export PATH=/var/raspi-toolchains/18.04/crosstool-ng-install/bin:$PATH
         
Build Toolchain
---------------

``crosstool-ng`` Toolchain Build
................................

Continue with :doc:`/blog/2022/09/cross-raspi` ...
  
.. code-block:: console

   $ mkdir toolchain-build
   $ cd toolchain-build/
   $ ct-ng armv8-rpi4-linux-gnueabihf
   $ ct-ng menuconfig
   ... select glibc version 2.28 ...
   $ ct-ng build

Builds into ``$HOME/x-tools`` by default

.. code-block:: console

   $ ls ~/x-tools
   armv8-rpi4-linux-gnueabihf

Create Toolchain Archive
........................

* Tar from ``~/x-tools``
* Into
  ``/var/raspi-toolchains/18.04/armv8-rpi4-linux-gnueabihf.tar.bxz``

.. code-block:: console

   $ tar --create --xz \
         --file /var/raspi-toolchains/18.04/armv8-rpi4-linux-gnueabihf.tar.bxz \
         --directory ~/x-tools \
         armv8-rpi4-linux-gnueabihf/

Install Toolchain On Host
-------------------------

* Docker volume's ``/var/raspi-toolchains/18.04`` is in
  ``/var/lib/docker/volumes/raspi-toolchains/_data/18.04``

.. code-block:: console

   # ls -l /var/lib/docker/volumes/raspi-toolchains/_data/18.04
   -rw-rw-r--. 1 jfasch jfasch 78683068 Nov 21 13:02 armv8-rpi4-linux-gnueabihf.tar.xz
   drwxr-xr-x. 1 jfasch jfasch      596 Nov 21 10:04 autoconf-2.71
   drwxrwxr-x. 1 jfasch jfasch       16 Nov 21 10:04 autoconf-2-71-install
   -rw-rw-r--. 1 jfasch jfasch  1292296 Jan 28  2021 autoconf-2.71.tar.xz
   drwxrwxr-x. 1 jfasch jfasch      686 Nov 21 10:12 crosstool-ng
   drwxrwxr-x. 1 jfasch jfasch       30 Nov 21 10:13 crosstool-ng-install
   drwxrwxr-x. 1 jfasch jfasch       80 Nov 21 10:16 toolchain-build

.. note::

   (Inside the container user ``build`` has UID 1000. This is why we
   see ``jfasch`` on the host which has UID 1000 there. I'll continue
   as ``root`` to cover the general case.)

* Copy archive over, as root

  .. code-block:: console

     $ sudo cp /var/lib/docker/volumes/raspi-toolchains/_data/18.04/armv8-rpi4-linux-gnueabihf.tar.xz ~
     $ sudo chown jfasch:jfasch ~/armv8-rpi4-linux-gnueabihf.tar.xz

* Unpack, as ``jfasch``, into, e.g. ``~/Programs``

  .. code-block:: console

     $ tar --extract --xz \
     --file ~/armv8-rpi4-linux-gnueabihf.tar.xz \
     --directory ~/Programs

* Point ``$PATH`` into it (best done into ``~/.bashrc``)

  export PATH=$HOME/Programs/armv8-rpi4-linux-gnueabihf/bin:$PATH

