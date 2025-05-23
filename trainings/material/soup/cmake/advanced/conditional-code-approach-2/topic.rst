.. include:: <mmlalias.txt>

Optional Code, Approach 2: Pushing Optionality Down In Module *Interface*
=========================================================================

.. contents::
   :local:

.. sidebar::

   **Source**

   .. code-block:: console

      12-conditional-code-approach-2/
      ├── CMakeLists.txt
      ├── DemoConfig.h.in
      ├── bin
      │   ├── CMakeLists.txt
      │   ├── hello-first.cpp
      │   └── hello-second.cpp
      ├── blacklist
      │   ├── blacklist.cpp
      │   ├── blacklist.h
      │   └── CMakeLists.txt
      └── libhello
          ├── CMakeLists.txt
          ├── greeter.h
          ├── greeter-name.cpp
          ├── greeter-name.h
          ├── greeter-simple.cpp
          └── greeter-simple.h
      
   * :download:`code/CMakeLists.txt`
   * :download:`code/DemoConfig.h.in`
   * :download:`code/bin/CMakeLists.txt`
   * :download:`code/bin/hello-first.cpp`
   * :download:`code/bin/hello-second.cpp`
   * :download:`code/libhello/CMakeLists.txt`
   * :download:`code/libhello/greeter.h`
   * :download:`code/libhello/greeter-simple.h`
   * :download:`code/libhello/greeter-simple.cpp`
   * :download:`code/libhello/greeter-name.cpp`
   * :download:`code/libhello/greeter-name.h`
   * :download:`code/blacklist/CMakeLists.txt`
   * :download:`code/blacklist/blacklist.h`
   * :download:`code/blacklist/blacklist.cpp`

Remove Too Much CMake Optionality
---------------------------------

* Remove optional descending from toplevel ``CMakeLists.txt``
* Remove optional dependency from ``libhello``
* Remove ``DEMO_USE_BLACKLIST`` from ``DemoConfig.h.in``
* Test (|longrightarrow| macro not defined)

  .. code-block:: console

     $ cmake -DUSE_BLACKLIST=ON  ~/work/jfasch-home/trainings/material/soup/cmake/code/
     $ make
     greeter-name.h:8:3: error: #error DEMO_USE_BLACKLIST not defined
     8 | # error DEMO_USE_BLACKLIST not defined
       |   ^~~~~

* How to solve? Where to define macro?

``TARGET_COMPILE_DEFINITIONS()`` (``backlist`` Availablility)
-------------------------------------------------------------

.. sidebar:: 
   
   **Documentation**

   * `TARGET_COMPILE_DEFINITIONS()
     <https://cmake.org/cmake/help/latest/command/target_compile_definitions.html>`__
   * `TARGET_COMPILE_OPTIONS()
     <https://cmake.org/cmake/help/latest/command/target_compile_options.html>`__

* Let ``blacklist`` announce its availability to its dependers
* |longrightarrow| ``TARGET_COMPILE_DEFINITIONS()``

  .. code-block:: console
     :caption: ``blacklist/CMakeLists.txt``

     TARGET_COMPILE_DEFINITIONS(blacklist PUBLIC DEMO_USE_BLACKLIST=1)

* Test

  * ``cmake -DUSE_BLACKLIST=ON ...`` |longrightarrow| works
  * ``cmake -DUSE_BLACKLIST=OFF ...`` |longrightarrow| blacklist still
    used (obviously, because we always announce is as ``1``)

* |longrightarrow| put optionality in ``blacklist``

Push Optionality Down In ``blacklist`` (|longrightarrow| ``INTERFACE`` Targets)
-------------------------------------------------------------------------------

* Naive approach

  .. code-block:: console

     IF (${USE_BLACKLIST})
       ADD_LIBRARY(blacklist blacklist.cpp)
     
       TARGET_INCLUDE_DIRECTORIES(blacklist PUBLIC .)
       TARGET_COMPILE_DEFINITIONS(blacklist PUBLIC DEMO_USE_BLACKLIST=1)
     ELSE()
       TARGET_COMPILE_DEFINITIONS(blacklist PUBLIC DEMO_USE_BLACKLIST=0)
     ENDIF()

  .. code-block:: console

     $ cmake -DUSE_BLACKLIST=OFF  ~/work/jfasch-home/trainings/material/soup/cmake/code/
     CMake Error at blacklist/CMakeLists.txt:7 (TARGET_COMPILE_DEFINITIONS):
       Cannot specify compile definitions for target "blacklist" which is not
       built by this project.
     
     -- Configuring incomplete, errors occurred!

* ``INTERFACE`` targets: dependency nodes, but without anything that's
  built
* Can have dependencies itself (``TARGET_LINK_LIBRARIES()``)
* Ours has ``TARGET_COMPILE_DEFINITIONS()``

  .. code-block:: console

     IF (${USE_BLACKLIST})
       ADD_LIBRARY(blacklist blacklist.cpp)
     
       TARGET_INCLUDE_DIRECTORIES(blacklist PUBLIC .)
       TARGET_COMPILE_DEFINITIONS(
             blacklist INTERFACE DEMO_USE_BLACKLIST=1) # <--- INTERFACE: propagate-only
     ELSE()
       ADD_LIBRARY(blacklist INTERFACE)                # <--- INTERFACE: there is no library here
       TARGET_COMPILE_DEFINITIONS(
             blacklist INTERFACE DEMO_USE_BLACKLIST=0) # <--- INTERFACE: propagate-only
     ENDIF()

Good Or Bad?
------------

*Is this better than the other approach?*

* It is more flexible
* Optionality is local, between *provider* (``blacklist``) and
  *consumer* (``libhello``)
* Is it simpler? *Probably not!*
