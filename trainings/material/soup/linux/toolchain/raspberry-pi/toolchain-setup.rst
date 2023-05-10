.. ot-topic:: linux.toolchain.raspi.toolchain_setup
   :dependencies: linux.toolchain.cross.basics

.. include:: <mmlalias.txt>


Cross Toolchain Setup
=====================

.. contents::
   :local:

Download And Install Toolchain Archive
--------------------------------------

.. sidebar::

   **See also**

   * :doc:`toolchain-build-docker-fedora`
   * :doc:`/trainings/material/soup/linux/basics/archiving-compression/group`

   **Download**: 

   * `armv8-rpi4-linux-gnueabihf.tar.xz
     <https://drive.google.com/file/d/1YAlNEQT9UY-z-nVWX-U55i0Zl1TNUfjB/view?usp=share_link>`__

* `Download
  <https://drive.google.com/file/d/1YAlNEQT9UY-z-nVWX-U55i0Zl1TNUfjB/view?usp=share_link>`__
  the toolchain archive (a whopping 70MB), and :doc:`unpack
  </trainings/material/soup/linux/basics/archiving-compression/group>`
  to ``<toolchain-dir>``

Establish CMake Toolchain File
------------------------------

.. sidebar::

   **Documentation**

   * :doc:`../cross/group`

   **CMake Toolchain File**

   * :download:`toolchain file <armv8-rpi4-linux-gnueabihf.cmake>`

* Download (best into ``<toolchain-dir>``) :download:`toolchain file
  <armv8-rpi4-linux-gnueabihf.cmake>`
* Open it with a text editor, and modify the following lines to point
  to your toolchain

  .. code-block:: text

     set(TOOLCHAIN_BASE_DIR /home/jfasch/x-tools/armv8-rpi4-linux-gnueabihf)

* Build your project with it (:doc:`../cmake/cross`)
