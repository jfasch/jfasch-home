.. include:: <mmlalias.txt>


Agenda: CMake (2023-11-27)
==========================

.. contents::
   :local:

.. sidebar::

   * :doc:`Main Training Page <index>`
   * :doc:`/trainings/repertoire/misc/cmake` (Course description)

Toolchain Introduction
----------------------

What are the problems that CMake solves?

* Compiler
* Linker
* Search paths: header files, libraries
* Dependencies

How are these solved by CMake? Present a trivial one-level-only CMake
project where compilation and linking happens.

Project Structure, Dependencies
-------------------------------

As projects become larger, structure is in order. Present a typical
project structure where there are separate directories for

* Libraries/Modules
* Executables
* Data files

External Dependencies
---------------------

CMake has so-called "Find Modules" to incorporate code that is not
built by the project, but only used by it. 

* Quickly introduce what that is
* Provide a number of examples
* See how a project can react if one such external dependency is not
  found (optional code)

Code Generators
---------------

Traditionally, lexers and parser generators (just as a typical
example) generate code that has to be built by the project.

* Show what problems arise when such generators are used naively
* Show how generators are integrated in a CMake project

Automatic Testing
-----------------

Today's software standards dictate that a project use unit testing
(see for example :doc:`/trainings/material/soup/misc/unittest/index`). See
how that can be integrated with CMake.

Installation And Deployment
---------------------------

* *Installation* is referred to as locally building code inside the
  build directory, and that transferring the artifact (executables and
  libraries, usually) into a well-known location where they are found
  by others.
* *Deployment* usually means *packaging* a project, and making it
  available for installation on other machines - often together with
  *cross compiliation*
