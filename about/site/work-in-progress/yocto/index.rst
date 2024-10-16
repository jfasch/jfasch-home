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

* Change into ``~/My-Projects/yocto``
* use poky@HEAD

  .. code-block:: console

     $ git clone https://git.yoctoproject.org/poky

* Create raspberry build directory

  .. code-block:: console

     $ pwd
     /home/jfasch/My-Projects/yocto
     $ . poky/oe-init-build-env raspberry
     ... blah ...
     $ pwd
     /home/jfasch/My-Projects/yocto/raspberry

* Get ``meta-raspberrypi`` 

  .. code-block:: console

     $ git clone https://github.com/agherzan/meta-raspberrypi

* Add ``meta-raspberrypi`` to layers

  In ``conf/bblayers.conf``, add

  .. code-block:: console

     BBLAYERS += " ${TOPDIR}/meta-raspberrypi"

* Share download and sstate

  In ``conf/local.conf``, add the following lines

  .. code-block:: console

     DL_DIR = "${HOME}/My-Projects/yocto/DOWNLOAD
     SSTATE_DIR = "${HOME}/My-Projects/yocto/SSTATE"

* Define machine type to build for (``raspberrypi4-64``)

  In ``conf/local.conf``, add

  .. code-block:: console

     MACHINE = "raspberrypi4-64"

* Build-and-fix loop

  .. code-block:: console

     $ bitbake core-image-base

  Add to ``conf/local.conf``

  * https://github.com/RPi-Distro/firmware-nonfree/issues/29

    .. code-block:: console
  
       LICENSE_FLAGS_ACCEPTED = "synaptics-killswitch"



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

QEMU
....

* Machine ``aarch64``, qemu
* Emulating devices:
  https://qemu-project.gitlab.io/qemu/system/device-emulation.html
