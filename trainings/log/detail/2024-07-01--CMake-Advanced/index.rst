.. include:: <mmlalias.txt>


CMake: Advanced Topics (2024-07-01)
===================================

.. toctree::
   :hidden:

   agenda

.. sidebar::

   **Github Repository**

   * https://github.com/jfasch/2024-07-01

   **Original Agenda** 

   * :doc:`agenda`

   **Windows Users**

   * :doc:`/trainings/material/soup/linux/basics/intro/wsl`
   * `Windows Subsystem for Linux (WSL)
     <https://learn.microsoft.com/en-us/windows/wsl/>`__
   * `VSCode: Developing in WSL
     <https://code.visualstudio.com/docs/remote/wsl>`__
   * `VSCode: Remote Development using SSH
     <https://code.visualstudio.com/docs/remote/ssh>`__


.. contents::
   :local:


Day 1
-----

Basics
......

From :doc:`/trainings/material/soup/cmake/intro/group`

* :doc:`/trainings/material/soup/cmake/intro/basics`
* :doc:`/trainings/material/soup/cmake/intro/libraries`
* :doc:`/trainings/material/soup/cmake/intro/shared-libraries`
* :doc:`/trainings/material/soup/cmake/intro/installation`
* :doc:`/trainings/material/soup/cmake/intro/structure`
* :doc:`/trainings/material/soup/cmake/intro/cxx-and-rants`

Exercise: Build It!
...................

Add CMake build to existing source code in
https://github.com/jfasch/2024-07-01/tree/main/exercises/straightforward

Dependencies, Dependencies, Properties, ...
...........................................

* :doc:`/trainings/material/soup/cmake/advanced/targets-properties/topic`
* :doc:`/trainings/material/soup/cmake/advanced/targets-properties/screenplay`

Day 2
-----

The CMake Language
..................

From :doc:`/trainings/material/soup/cmake/advanced/language/group`

* :doc:`/trainings/material/soup/cmake/advanced/language/basics/topic`
* :doc:`/trainings/material/soup/cmake/advanced/language/variables/topic`
* :doc:`/trainings/material/soup/cmake/advanced/language/if-and-conditions/topic`
* :doc:`/trainings/material/soup/cmake/advanced/language/datatypes/topic`
* :doc:`/trainings/material/soup/cmake/advanced/language/file-etc/topic`
* Exercise

  Write a CMake script (see
  :doc:`/trainings/material/soup/cmake/advanced/language/scripts/topic`)
  that receives as input parameters

  * A directory name ``INPUT_DIR``
  * A filename ``OUTPUT_FILE``

  It reads all directory entries from ``INPUT_DIR``, transforms those
  names into their filename-only part (e.g. ``/a/b/c.txt`` ->
  ``c.txt``), and writes those names to ``OUTPUT_FILE``

* :doc:`/trainings/material/soup/cmake/advanced/language/functions-and-macros/topic`
* :doc:`/trainings/material/soup/cmake/advanced/language/scripts/topic`

Day 3
-----

Morning Awakening
.................

* :doc:`/trainings/material/soup/cmake/advanced/library-function/screenplay`

External Dependencies
.....................

From :doc:`/trainings/material/soup/cmake/advanced/group` ...

* :doc:`/trainings/material/soup/cmake/advanced/external-dependencies/screenplay-sqlite3`
* :doc:`/trainings/material/soup/cmake/advanced/external-dependencies/screenplay-sqlite3-optional-graph`
* :doc:`/trainings/material/soup/cmake/advanced/external-dependencies/screenplay-sqlite3-optional-configured-file`
* :doc:`/trainings/material/soup/cmake/advanced/external-dependencies/screenplay-mosquitto`

Code Generators
...............

* :doc:`/trainings/material/soup/cmake/advanced/code-generators/screenplay`

Unit Tests
..........

* :doc:`/trainings/material/soup/cmake/advanced/testing/topic`
