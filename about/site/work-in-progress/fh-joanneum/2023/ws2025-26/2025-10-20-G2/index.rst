.. include:: <mmlalias.txt>


2025-10-20 (3 Exc G2): File I/O (Exercise)
==========================================

* See
  :doc:`/trainings/material/soup/linux/sysprog/file-io/basics-exercise-copy/exercise`
  for the programming exercise
* Create a CMake managed project to build this program (and possibly
  keep it for future programs of this sort).

  Here is an example ``CMakeLists.txt`` file for a project where
  everything is put in the toplevel directory.

  .. code-block:: text
     :caption: ``CMakeLists.txt``

     cmake_minimum_required(VERSION 3.16)
     project(ec2-exercises)
     
     # compiler options. (we only check for gcc)
     if (${CMAKE_COMPILER_IS_GNUCC})
       set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g3 -Wall -Werror")
       set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O0 -g3 -Wall -Werror")
     endif()

     add_executable(cp-for-the-poor cp-for-the-poor.cpp)
