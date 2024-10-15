.. include:: <mmlalias.txt>


Yocto
=====

.. contents::
   :local:

Basic Information
-----------------

* https://docs.yoctoproject.org/dunfell/what-i-wish-id-known.html
* https://docs.yoctoproject.org/ref-manual/system-requirements.html#fedora-packages

  .. code-block:: console

     $ sudo dnf install gawk make wget tar bzip2 gzip python3 unzip perl patch diffutils diffstat git cpp gcc gcc-c++ glibc-devel texinfo chrpath ccache perl-Data-Dumper perl-Text-ParseWords perl-Thread-Queue perl-bignum socat python3-pexpect findutils which file cpio python python3-pip xz python3-GitPython python3-jinja2 rpcgen perl-FindBin perl-File-Compare perl-File-Copy perl-locale zstd lz4 hostname glibc-langpack-en libacl

* Releases: https://wiki.yoctoproject.org/wiki/Releases

  |longrightarrow| ``scarthgap`` (latest LTS)

First Build
-----------

* First build (machine ``qemux86-64``)
  https://docs.yoctoproject.org/brief-yoctoprojectqs/index.html

Next Steps
----------

* Machine ``aarch64``, qemu
* Strip down, omit e.g. wayland and all that
