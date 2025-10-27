.. include:: <mmlalias.txt>


CMake
=====

.. topic:: Course info

   .. list-table::
      :align: left

      * * **Duration**
	* 1-2 days
      * * **Language**
	* Trainer language is English or German
      * * **Related**
	* * :doc:`/trainings/repertoire/misc/make`
      * * **Booking**
	* :doc:`/trainings/info`

As if :doc:`C </trainings/repertoire/c-like/c>` and :doc:`C++
</trainings/repertoire/c-like/cxx>` weren't complicated enough,
building programs written in those languages is even more complicated.

:doc:`(GNU-)Make </trainings/repertoire/misc/make>`, a low-level build
tool to manage some of the intricacies of the build, has been invented
rather early in history. Today it is considered the "assembly language
of a build".

.. image:: logo.jpg
   :alt: CMake Logo
   :align: left
   :scale: 50%

A number of higher level tools have been designed, to manage most of
the rest of the build intricacies, together with some that ``make``
has created on its own. One of these tools, `CMake
<https://cmake.org/>`__, is introduced in this course.

Target Audience
---------------

**Software developers**, mostly. Every developer of a team is
concerned about the structure of the project that is maintained by the
team. The project's modules and their interdependencies have to be
understood. CMake, if used judiciously, can be used to clearly define
project structure.

Recommended Prior Knowledge
---------------------------

* C or C++ is recommended, obviously. It is good to understand what
  C's ``#include`` directive does (see
  :doc:`/trainings/material/soup/c/040-functions-and-program-structure/index`
  for ``#include`` and more).
* A rudimentary understanding of the Unix shell is also helpful (see
  :doc:`/trainings/repertoire/linux-prog/linux-basics` for Shell topics,
  and more)

Contents
--------

.. toctree::
   :maxdepth: 1

   intro/index
   advanced/index

.. Toolchain Introduction
.. ......................
.. 
.. What are the problems that CMake solves?
.. 
.. * Compiler
.. * Linker
.. * Search paths: header files, libraries
.. * Dependencies
.. 
.. How are these solved by CMake? Present a trivial one-level-only CMake
.. project where compilation and linking happens.
.. 
.. Project Structure, Dependencies
.. ...............................
.. 
.. As projects become larger, structure is in order. Present a typical
.. project structure where there are separate directories for
.. 
.. * Libraries/Modules
.. * Executables
.. * Data files
.. 
.. External Dependencies
.. .....................
.. 
.. CMake has so-called "Find Modules" to incorporate code that is not
.. *owned* by the project, but only *used* by it.
.. 
.. * Quickly introduce what that is
.. * Provide a number of examples
.. * See how a project can react if one such external dependency is not
..   found (optional code)
.. 
.. Code Generators
.. ...............
.. 
.. Traditionally, lexers and parser generators (just as a typical
.. example) generate code that has to be built by the project.
.. 
.. * Show what problems arise when such generators are use naively
.. * Show how generators are integrated in a CMake project
.. 
.. Automatic Testing
.. .................
.. 
.. Today's software standards dictate that a project use unit testing
.. (see for example :doc:`/trainings/material/soup/misc/unittest/index`). See
.. how that can be integrated with CMake.
.. 
.. Installation And Deployment
.. ...........................
.. 
.. * *Installation* is referred to as locally building code inside the
..   build directory, and that transferring the artifact (executables and
..   libraries, usually) into a well-known location where they are found
..   by others.
.. * *Deployment* usually means *packaging* a project, and making it
..   available for installation on other machines - often together with
..   *cross compiliation*
