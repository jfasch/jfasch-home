.. include:: <mmlalias.txt>

Optional Code: Problem Definition, ``OPTION()``
===============================================

.. contents::
   :local:

Problem
-------

* ``hello-second`` licensing requirements
* Must pay extra $$ to be able to greet "Joerg" (and a number of other
  blacklisted names)
* |longrightarrow| separate builds

  * One that ignores a blacklist (pay extra $$)
  * One in the public domain, with restrictions

Solution: Add An Option
-----------------------

.. sidebar:: 

   **Documentation**

   * `OPTION()
     <https://cmake.org/cmake/help/latest/command/option.html>`__
   * `IF (and conditionals)
     <https://cmake.org/cmake/help/latest/command/if.html>`__

* Goal: add option ``USE_BLACKLIST`` to be used like

  .. code-block:: console

     $ cmake -DUSE_BLACKLIST=ON ...
     $ cmake -DUSE_BLACKLIST=OFF ...

* Implementation: manyfold; see below

Define Option ``USE_BLACKLIST``; Option Usage, Cache
----------------------------------------------------

* Define option

  .. code-block:: console
     :caption: Toplevel ``CMakeLists.txt``
  
     OPTION(USE_BLACKLIST "Refuse to greet blacklisted names" ON)

* Default: ``ON``

.. code-block:: console

   $ cmake -L ~/work/jfasch-home/trainings/material/soup/cmake/code/
   ...
   USE_BLACKLIST:BOOL=ON
   ...

* Set to ``OFF``

.. code-block:: console

   $ cmake -DUSE_BLACKLIST=OFF  ~/work/jfasch-home/trainings/material/soup/cmake/code/
   ...

* Value of ``USE_BLACKLIST`` is persisted ("cached")

.. code-block:: console

   $ cmake -L ~/work/jfasch-home/trainings/material/soup/cmake/code/
   ...
   USE_BLACKLIST:BOOL=OFF
   ...

Option Handling: Many Approaches
--------------------------------

.. sidebar:: 

   **Documentation**

   * `TARGET_INCLUDE_DIRECTORIES()
     <https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories>`__
   * `TARGET_COMPILE_DEFINITIONS()
     <https://cmake.org/cmake/help/latest/command/target_compile_definitions.html#command:target_compile_definitions>`__

* Question: what to when ``USE_BLACKLIST`` is ``ON`` or ``OFF``
* *Note that this is programming!*
* |longrightarrow| should not be taken lightly
* Here we present two alternative approaches

#. Approach 1: globally define flags at CMake and C (macro) levels

   * CMake variable ``USE_BLACKLIST`` from option, re-used downwards
   * C macro ``MACRO_USE_BLACKLIST`` in ``DemoConfig.h.in``
   * *Optionally* descend into ``blacklist`` directory
   * *Conditionals* at CMake and C level everywhere

#. Approach 2: optionally make ``blacklist`` an ``INTERFACE`` library

   * If not ``USE_BLACKLIST``, make ``blacklist`` an ``INTERFACE``
     library
   * Use ``TARGET_COMPILE_DEFINITIONS()`` and
     ``TARGET_INCLUDE_DIRECTORIES()`` to announce (non-)presence of
     ``blacklist``

