Course Preparation
==================

.. contents::
   :local:

Source Tree Preparation
-----------------------

* Copy entire tree over

  .. code-block:: console
     
     $ cp -r code/ ~/tmp/COURSE           # <--- insert course name

* Remove what's to be created by trainees

  .. code-block:: console
     
     $ cd ~/tmp/COURSE
     $ rm -r heating/ programs/ singleton/ libtrainee/* tests-trainee/*

* Create ``libtrainee`` skeleton

  .. code-block:: text
     
     $ cat > libtrainee/CMakeLists.txt <<EOF
     ADD_LIBRARY(
       design-patterns-trainee
     
       trainee-dummy.h
       trainee-dummy.cpp
     )  
     TARGET_INCLUDE_DIRECTORIES(design-patterns-trainee PUBLIC .)
     TARGET_LINK_LIBRARIES(design-patterns-trainee design-patterns-trainer)
     EOF

  Save as ``libtrainee/trainee-dummy.h``:

  .. literalinclude:: code/libtrainee/trainee-dummy.h
     :caption: :download:`code/libtrainee/trainee-dummy.h`
     :language: c++

  Save as ``libtrainee/trainee-dummy.cpp``:

  .. literalinclude:: code/libtrainee/trainee-dummy.cpp
     :caption: :download:`code/libtrainee/trainee-dummy.cpp`
     :language: c++

* Create ``tests-trainee`` skeleton

  .. code-block:: text

     $ cat > tests-trainee/CMakeLists.txt <<EOF
     ADD_EXECUTABLE(
       design-patterns-c++-trainee-exercises-suite
     
       trainee-dummy-suite.cpp
     )
     
     TARGET_LINK_LIBRARIES(
       design-patterns-c++-trainee-exercises-suite
     
       gtest_main 
       design-patterns-trainee
       design-patterns-trainer
       Threads::Threads
     )
     EOF

  Save as ``tests-trainee/trainee-dummy-suite.cpp``:

  .. literalinclude:: code/tests-trainee/trainee-dummy-suite.cpp
     :caption: :download:`code/tests-trainee/trainee-dummy-suite.cpp`
     :language: c++

* Replace toplevel ``CMakeLists.txt`` with following content

  .. code-block:: text
  
     CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
     PROJECT(COURSE)                        # <--- insert course name
     
     FIND_PACKAGE(Threads REQUIRED)
     set(CMAKE_CXX_STANDARD 17)             # <--- which standard?
     
     # compiler options. (we only check for gcc)
     if (${CMAKE_COMPILER_IS_GNUCC})
       set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g3 -Wall -Werror")
       set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g3 -Wall -Werror")
     endif()

     
     ADD_SUBDIRECTORY(googletest)
     
     ADD_SUBDIRECTORY(libtrainer)
     ADD_SUBDIRECTORY(tests-trainer)
     
     ADD_SUBDIRECTORY(libtrainee)
     ADD_SUBDIRECTORY(tests-trainee)

* Add ``README.rst``

  .. code-block:: rst

     .. code-block:: console
     
        $ git clone https://github.com/jfasch/COURSE
        $ cd COURSE
        $ git submodule init
        $ git submodule update

Git-ish Setup
-------------

* Init Repository

  .. code-block:: console

     $ git init
  
* Submodules

  .. code-block:: console

     $ git submodule add https://github.com/google/googletest
