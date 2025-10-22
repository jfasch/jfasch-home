.. include:: <mmlalias.txt>


2025-10-21 (3 Exc G1): File I/O (Exercise)
==========================================

Requirement
-----------

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

For The New Ones
----------------

* Create one dedicated directory for the exercise, say
  ``~/My-Projects/the-new-ones/``
* Into this directory, put the required minimal set of files: the
  ``CMakeLists.txt`` from above (note that the file is not
  ``cp-for-the-poor.cpp``, fix that), and a minimal program source
  file in C++, like

  .. code-block:: c++
     :caption: ``main.cpp``

     int main()
     {
         return 0;
     }

* The directory now should look like follows:

  .. code-block:: console
  
     $ tree ~/My-Projects/the-new-ones/
     the-new-ones/
     ├── CMakeLists.txt
     └── main.cpp

* Create a *build directory* that is associated with the source
  directory, like ``~/My-Builds/the-new-ones-x86_64``
* Change into that directory, and create the build ``Makefile``

  .. code-block:: console

     $ cd ~/My-Builds/the-new-ones-x86_64
     $ cmake ~/My-Projects/the-new-ones/
     ...

  Now you see one ``Makefile`` in your build directory (and some other
  stuff that you can ignore)
* Invoke ``make`` to do the final build which creates your program.

  .. code-block:: console

     $ make
     ...

  Now, if all went well, you should see one file named ``main`` (or
  ``cp-for-the-poor`` if you haven't modified the ``CMakeLists.txt``
  example from above).

