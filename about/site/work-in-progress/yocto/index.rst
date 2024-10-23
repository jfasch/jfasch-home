.. include:: <mmlalias.txt>


Yocto
=====

.. contents::
   :local:

Basic Information
-----------------

* https://docs.yoctoproject.org/brief-yoctoprojectqs/index.html
* https://docs.yoctoproject.org/dunfell/what-i-wish-id-known.html
* https://docs.yoctoproject.org/ref-manual/system-requirements.html#fedora-packages

  .. code-block:: console

     $ sudo dnf install gawk make wget tar bzip2 gzip python3 unzip perl patch diffutils diffstat git cpp gcc gcc-c++ glibc-devel texinfo chrpath ccache perl-Data-Dumper perl-Text-ParseWords perl-Thread-Queue perl-bignum socat python3-pexpect findutils which file cpio python python3-pip xz python3-GitPython python3-jinja2 rpcgen perl-FindBin perl-File-Compare perl-File-Copy perl-locale zstd lz4 hostname glibc-langpack-en libacl

* Releases: https://wiki.yoctoproject.org/wiki/Releases

  |longrightarrow| ``scarthgap`` (latest LTS)

Raspberry Build
---------------

.. sidebar::

   * `meta-raspberrypi
     <https://github.com/agherzan/meta-raspberrypi>`__

Project Setup
.............

* Change into ``~/My-Projects/yocto``
* use ``poky@HEAD``

  .. code-block:: console

     $ git clone https://git.yoctoproject.org/poky

* Create ``raspberrypi3-64`` build directory

  .. code-block:: console

     $ pwd
     ~/My-Projects/yocto
     $ . poky/oe-init-build-env raspberrypi3-64
     ... blah ...
     $ pwd
     ~/My-Projects/yocto/raspberrypi3-64

* Set machine type that we build for

  In ``~/My-Projects/yocto/raspberry3-build/conf/local.conf``, add the
  following line

  .. code-block:: console
 
     MACHINE = "raspberrypi3-64"

* Get ``meta-raspberrypi``

  .. code-block:: console

     $ cd ~/My-Projects/yocto
     $ git clone https://github.com/agherzan/meta-raspberrypi

* Add ``meta-raspberrypi`` to layers

  In ``~/My-Projects/yocto/raspberry3-build/conf/bblayers.conf``, add

  .. code-block:: console

     BBLAYERS += " ${HOME}/My-Projects/yocto/meta-raspberrypi"

* Share download and sstate directories (for repeated builds, and in
  case we want to build for a Pi4)

  In ``~/My-Projects/yocto/raspberry3-build/conf/local.conf``, add the
  following lines

  .. code-block:: console

     DL_DIR = "${HOME}/My-Projects/yocto/DOWNLOAD
     SSTATE_DIR = "${HOME}/My-Projects/yocto/SSTATE"

Build/Fix Loop
..............

* Build

  .. code-block:: console

     $ pwd
     ~/My-Projects/yocto/raspberrypi3-64
     $ bitbake core-image-base

* Fix. Add to ``~/My-Projects/yocto/raspberry3-build/conf/local.conf``

  .. code-block:: console
  
     LICENSE_FLAGS_ACCEPTED = "synaptics-killswitch"

Todo
....

* Add systemd unit that enlarges rootfs to take available SD card
  space (at first boot only, ideally)

  .. code-block:: console

     $ parted /dev/mmcblk0 'resizepart 2 100%'
     $ resize2fs /dev/mmcblk0p2


Next Steps
----------

Yocto
.....

* externalize build directory:
  https://docs.yoctoproject.org/ref-manual/terms.html#term-Build-Directory
* common sstate cache and download:
  https://bootlin.com/blog/yocto-sharing-the-sstate-cache-and-download-directories/
* build raspberry image: https://github.com/agherzan/meta-raspberrypi
* use systemd:
  https://docs.yoctoproject.org/next/dev-manual/init-manager.html
* Strip down, omit e.g. wayland and all that
* version controlling my own config:
  https://unix.stackexchange.com/questions/626496/what-is-the-right-way-to-store-bitbake-configuration-under-git
* https://git.openembedded.org/meta-openembedded

Python
......

* `Packaging and installing own Python program for/on Yocto
  <https://stackoverflow.com/questions/76529171/packaging-and-installing-own-python-program-for-on-yocto>`__

QEMU
....

* Machine ``aarch64``, qemu
* Emulating devices:
  https://qemu-project.gitlab.io/qemu/system/device-emulation.html
