Cross Toolchain Setup
=====================

.. contents::
   :local:

Download And Install Toolchain Archive
--------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/toolchain/raspberry-pi/toolchain-build-docker-fedora`

   **Download**: 

   * `armv8-rpi4-linux-gnueabihf.tar.xz
     <https://drive.google.com/file/d/18rcwS-NgWpDLG3p_VuWA9srW2pUH33mh/view?usp=share_link>`__

* `Download
  <https://drive.google.com/file/d/18rcwS-NgWpDLG3p_VuWA9srW2pUH33mh/view?usp=share_link>`__
  the toolchain archive (whopping 70MB), and unpack to
  ``<toolchain-dir>``
* Modify ``PATH`` (best permanently in ``~/.bashrc``). Make sure that
  ``<toolchain-dir>`` is given as **absolute path** (:doc:`see here
  </trainings/material/soup/linux/basics/shell/paths>`).

.. code-block:: console

   $ export PATH=<toolchain-dir>/armv8-rpi4-linux-gnueabihf/bin:$PATH

Establish CMake Toolchain File
------------------------------

* Download (best into ``<toolchain-dir>``) :download:`toolchain file
  <armv8-rpi4-linux-gnueabihf.cmake>`
* Open it with a text editor, and modify the folling lines to point to
  your toolchain

  .. code-block:: text

     set(CMAKE_FIND_ROOT_PATH <toolchain-dir>/armv8-rpi4-linux-gnueabihf/armv8-rpi4-linux-gnueabihf/sysroot)
     set(CMAKE_SYSROOT <toolchain-dir>/armv8-rpi4-linux-gnueabihf/armv8-rpi4-linux-gnueabihf/sysroot)

* Build your project with it

  * :doc:`/trainings/material/soup/linux/toolchain/cmake/cross`
