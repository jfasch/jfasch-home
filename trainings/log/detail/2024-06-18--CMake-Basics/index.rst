.. include:: <mmlalias.txt>


CMake: An Introduction (2024-06-18)
===================================

.. contents::
   :local:

.. sidebar::

   **Course Times**

   * 2024-06-18, 9:00

   **Github Repository**

   * https://github.com/jfasch/2024-06-18

   **See also**

   * :doc:`/trainings/repertoire/misc/cmake` (Course description)
   * :doc:`/trainings/material/soup/cmake/group` (Course material)

* :doc:`/trainings/material/soup/cmake/intro/basics`
* :doc:`/trainings/material/soup/cmake/intro/libraries`
* :doc:`/trainings/material/soup/cmake/intro/shared-libraries`
* :doc:`/trainings/material/soup/cmake/intro/installation`
* :doc:`/trainings/material/soup/cmake/intro/structure`
* Exercise: see
  https://github.com/jfasch/2024-06-18/tree/main/exercise
* :doc:`/trainings/material/soup/cmake/intro/cxx-and-rants`
* Cross development

  * :doc:`/trainings/material/soup/linux/toolchain/cross/basics`
  * :doc:`/trainings/material/soup/linux/toolchain/cmake/cross`
  * Sample CMake toolchain file `here
    <https://github.com/jfasch/2024-06-18/blob/main/CMake/armv8-rpi4-linux-gnueabihf.cmake>`__

* :doc:`/trainings/material/soup/cmake/advanced/targets-properties/topic`
* :doc:`/trainings/material/soup/cmake/advanced/external-dependencies/topic`

  * Add MQTT logic to `exercise project
    <https://github.com/jfasch/2024-06-18/tree/main/exercise>`__
    |longrightarrow| need to know about `mosquitto
    <https://mosquitto.org/>`__ installation (include path, library)
  * Handwritten (simplistic) find module: `FileMosquitto.cmake
    <https://github.com/jfasch/2024-06-18/blob/main/exercise/CMake/FindMosquitto.cmake>`__
  * Find mosquitto in `toplevel CMakeLists.txt
    <https://github.com/jfasch/2024-06-18/blob/main/exercise/CMakeLists.txt>`__
    
    .. code-block:: cmake

       list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake")
       find_package(Mosquitto)

  * Add dependency in `base CMakeLists.txt
    <https://github.com/jfasch/2024-06-18/blob/main/exercise/toolcase/base/CMakeLists.txt>`__

    .. code-block:: cmake

       target_link_libraries(base Mosquitto::Mosquitto)
