.. ot-topic:: cmake.advanced.configure_file
   :dependencies: cmake.intro.cxx_and_rants
.. include:: <mmlalias.txt>

"Configured" Header Files
=========================

.. contents::
   :local:

.. sidebar::

   **Source**

   .. code-block:: console

      10-configure-file/
      ├── CMakeLists.txt
      ├── DemoConfig.h.in
      ├── bin
      │   ├── CMakeLists.txt
      │   ├── hello-first.cpp
      │   └── hello-second.cpp
      └── libhello
          ├── CMakeLists.txt
          ├── greeter.h
          ├── greeter-name.cpp
          ├── greeter-name.h
          ├── greeter-simple.cpp
          └── greeter-simple.h

   * :download:`10-configure-file/CMakeLists.txt`
   * :download:`10-configure-file/DemoConfig.h.in`
   * :download:`10-configure-file/libhello/CMakeLists.txt`
   * :download:`10-configure-file/libhello/greeter.h`
   * :download:`10-configure-file/libhello/greeter-simple.h`
   * :download:`10-configure-file/libhello/greeter-simple.cpp`
   * :download:`10-configure-file/libhello/greeter-name.cpp`
   * :download:`10-configure-file/libhello/greeter-name.h`
   * :download:`10-configure-file/bin/CMakeLists.txt`
   * :download:`10-configure-file/bin/hello-second.cpp`
   * :download:`10-configure-file/bin/hello-first.cpp`
      
Problem
-------

.. sidebar::

   **Documentation**

   * `PROJECT()
     <https://cmake.org/cmake/help/latest/command/project.html>`__
   * `CONFIGURE_FILE()
     <https://cmake.org/cmake/help/latest/command/configure_file.html>`__

* Want to output project version in executables
* |longrightarrow| Set version using ``PROJECT()``
* Output using ``MESSAGE()``

  .. code-block:: console
  
     PROJECT(Demo VERSION 42.666)
     MESSAGE(DEBUG "Major: ${Demo_VERSION_MAJOR}")
     MESSAGE(DEBUG "Major: ${Demo_VERSION_MINOR}")

* Question: how to make those available to compiled code?
* Answer: ``CONFIGURE_FILE()``

Configured Files
----------------

.. sidebar::

   **Documentation**

   * `CONFIGURE_FILE()
     <https://cmake.org/cmake/help/latest/command/configure_file.html>`__
   * `CMAKE_CURRENT_BINARY_DIR
     <https://cmake.org/cmake/help/latest/variable/CMAKE_CURRENT_BINARY_DIR.html>`__

* Header file *template* that contains CMake variable substitutions

  .. literalinclude:: 10-configure-file/DemoConfig.h.in
     :language: c++
     :caption: :download:`10-configure-file/DemoConfig.h.in`

* Let CMake perform substitutions

  .. code-block:: console
  
     CONFIGURE_FILE(DemoConfig.h.in DemoConfig.h)

* Converted to ``${CMAKE_CURRENT_BINARY_DIR}/DemoConfig.h``

Use In Compiled Code
--------------------

.. sidebar::

   **Documentation**

   * `INCLUDE_DIRECTORIES()
     <https://cmake.org/cmake/help/latest/command/include_directories.html>`__

* Pick up CMake variables from configure file
  (:download:`10-configure-file/bin/hello-first.cpp` and
  :download:`10-configure-file/bin/hello-second.cpp`)

  .. code-block:: c++
  
     #include <DemoConfig.h>
     // ...
     std::cout << "Version " << DEMO_MAJOR << '.' << DEMO_MINOR << std::endl;

* Does not compile |longrightarrow| include path missing

  .. code-block:: console
  
     bin/hello-first.cpp:4:10: fatal error: DemoConfig.h: No such file or directory
         4 | #include <DemoConfig.h>
           |          ^~~~~~~~~~~~~~
   
* Solution: set include path *for all* (to add a dependency would be
  overkill but could be done)

  .. code-block:: console
     :caption: Toplevel ``CMakeLists.txt``
 
     INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
