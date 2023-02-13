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

   **Download**: 

   * `armv8-rpi4-linux-gnueabihf.tar.xz
     <https://drive.google.com/file/d/1FJvnLGbHwAABy0DgVfRvSqDnuqK5aloZ/view?usp=share_link>`__

* `Download
  <https://drive.google.com/file/d/1FJvnLGbHwAABy0DgVfRvSqDnuqK5aloZ/view?usp=share_link>`__
  the toolchain archive (a whopping 70MB), and unpack to
  ``<toolchain-dir>``
* Modify ``PATH`` (best permanently in ``~/.bashrc``). Make sure that
  ``<toolchain-dir>`` is given as **absolute path** (:doc:`see here
  </trainings/material/soup/linux/basics/shell/paths>`).

.. code-block:: console

   $ export PATH=<toolchain-dir>/armv8-rpi4-linux-gnueabihf/bin:$PATH

Establish CMake Toolchain File
------------------------------

.. sidebar::

   **Documentation**

   * :doc:`../cross/group`

   **CMake Toolchain File**

   * :download:`toolchain file <armv8-rpi4-linux-gnueabihf.cmake>`

* Download (best into ``<toolchain-dir>``) :download:`toolchain file
  <armv8-rpi4-linux-gnueabihf.cmake>`
* Open it with a text editor, and modify the folling lines to point to
  your toolchain

  .. code-block:: text

     set(CMAKE_FIND_ROOT_PATH <toolchain-dir>/armv8-rpi4-linux-gnueabihf/armv8-rpi4-linux-gnueabihf/sysroot)
     set(CMAKE_SYSROOT <toolchain-dir>/armv8-rpi4-linux-gnueabihf/armv8-rpi4-linux-gnueabihf/sysroot)

* Build your project with it (:doc:`../cross/group`)
