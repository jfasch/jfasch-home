.. ot-topic:: cmake.advanced.language.variables
   :dependencies: cmake.advanced.language.basics
.. include:: <mmlalias.txt>

Variables
=========

.. contents::
   :local:

.. sidebar:: Documentation

   * `man -s 7 cmake-language
     <https://cmake.org/cmake/help/latest/manual/cmake-language.7.html>`__
   * `man -s 7 cmake-variables
     <https://cmake.org/cmake/help/latest/manual/cmake-variables.7.html>`__

Setting, And Variable Names
---------------------------

.. sidebar:: Documentation

   * `set <https://cmake.org/cmake/help/latest/command/set.html>`__
   * `unset
     <https://cmake.org/cmake/help/latest/command/unset.html>`__

* Variable names are case-sensitive

  .. literalinclude:: code/set.cmake
     :caption: :download:`set.cmake (download)
  	     <code/set.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P set.cmake
     :cwd: code
     :shell:

* Cannot contain whitespace

  .. literalinclude:: code/set-whitespace.cmake
     :caption: :download:`set-whitespace.cmake (download)
  	     <code/set-whitespace.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P set-whitespace.cmake
     :cwd: code

Empty/Undefined Variables
-------------------------

.. sidebar:: See also

   * :doc:`../if-and-conditions/topic`
   * :doc:`../datatypes/topic`

.. sidebar:: See also

   * :doc:`../datatypes/topic`

* Empty variable

  .. literalinclude:: code/empty-variable.cmake
     :caption: :download:`empty-variable.cmake (download)
	       <code/empty-variable.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P empty-variable.cmake
     :cwd: code

* Undefined variable

  .. literalinclude:: code/undefined-variable.cmake
     :caption: :download:`undefined-variable.cmake (download)
  	     <code/undefined-variable.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P undefined-variable.cmake
     :cwd: code

Removing Variables
------------------

.. sidebar:: Documentation

   * `set <https://cmake.org/cmake/help/latest/command/set.html>`__
   * `unset
     <https://cmake.org/cmake/help/latest/command/unset.html>`__

Variables can be removed at runtime

* Preferred: `unset
  <https://cmake.org/cmake/help/latest/command/unset.html>`__ (less
  confusing to readers)

  .. literalinclude:: code/unset-variable-unset.cmake
     :caption: :download:`unset-variable-unset.cmake (download)
  	     <code/unset-variable-unset.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P unset-variable-unset.cmake
     :cwd: code

* `set <https://cmake.org/cmake/help/latest/command/set.html>`__ with
  no value

  .. literalinclude:: code/unset-variable-set.cmake
     :caption: :download:`unset-variable-set.cmake (download)
  	     <code/unset-variable-set.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P unset-variable-set.cmake
     :cwd: code

Checking Emptyness And Definedness
----------------------------------

.. sidebar:: See also

   * :doc:`../if-and-conditions/topic`

.. sidebar:: Documentation

   * `if <https://cmake.org/cmake/help/latest/command/if.html>`__

Emptyness and definedness are often considered equivalent but aren't -
there's a subtle difference.

* Checking string length

  .. literalinclude:: code/empty-variable-check.cmake
     :caption: :download:`empty-variable-check.cmake (download)
	       <code/empty-variable-check.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P empty-variable-check.cmake
     :cwd: code

Indirect Variables
------------------

* Variables contain strings
* Some variables contain variable names

  .. literalinclude:: code/indirect-variable.cmake
     :caption: :download:`indirect-variable.cmake (download)
  	       <code/indirect-variable.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P indirect-variable.cmake
     :cwd: code

Danger: Lookup Scope
--------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/linux/basics/intro/environment`

There are multiple kinds of variables,

* Normal variables, referenced with ``${NAME}``
* Environment variables, referenced with ``$ENV{NAME}``. Environment
  variables are provided by the *operating system*. See
  :ref:`environment-variables`, and also
  :doc:`/trainings/material/soup/linux/basics/intro/environment`)
* Cache variables, referenced with ``$CACHE{NAME}``. In short, cache
  variable are used to store variables *persistently*. See
  :ref:`cache-variables`.

.. attention::

   It's not always clear what you get when you say ``${NAME}`` though!
   See :ref:`scope`.

.. _environment-variables:

Environment Variables
---------------------

* Environment are an OS concept
* Inherited from parent to child process
* Modification only affects child processes
* |longrightarrow| *no* subsequent cmake runs!

Usage

* Accessing environment variables

  .. literalinclude:: code/env-print-path.cmake
     :caption: :download:`env-print-path.cmake (download)
  	     <code/env-print-path.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P env-print-path.cmake
     :cwd: code

* Setting environment variables. Because environment variables are
  inherited to child processes, those are only visible by children
  created during the CMake run.

  .. literalinclude:: code/env-set.cmake
     :caption: :download:`env-set.cmake (download)
  	     <code/env-set.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P env-set.cmake
     :cwd: code


.. _cache-variables:

Cache Variables
---------------

.. sidebar:: Documentation

   * `set(... CACHE ...)
     <https://cmake.org/cmake/help/latest/command/set.html#set-cache-entry>`__

* Persistent variables
* Visible in a *project*, across CMake runs
* |longrightarrow| ``CMakeCache.txt`` in the build directory

.. literalinclude:: code/project-cache/CMakeLists.txt
   :caption: :download:`CMakeLists.txt (download)
             <code/project-cache/CMakeLists.txt>`
   :language: cmake

* First run

  .. code-block:: console
  
     $ mkdir /tmp/cmake-demo
     $ cmake -B /tmp/cmake-demo/ -S ./code/project-cache/
     ...
     setting some_variable the first time
     Normal variable: value
     Cache variable: value
     ...

* Second run   

  .. code-block:: console
  
     $ cmake -B /tmp/cmake-demo/ -S ./code/project-cache/
     ...
     Normal variable: value
     Cache variable: value
     ...

.. _scope:

Scopes: Function Scope
----------------------

.. sidebar:: See also

   * :doc:`../functions-and-macros/topic`

* Local variables

  .. literalinclude:: code/scopes-function-local-scope.cmake
     :caption: :download:`scopes-function-local-scope.cmake (download)
  	     <code/scopes-function-local-scope.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P scopes-function-local-scope.cmake
     :cwd: code

* Global variables (well, and directory scope?)

  .. literalinclude:: code/scopes-function-global-scope.cmake
     :caption: :download:`scopes-function-global-scope.cmake
  	     (download) <code/scopes-function-global-scope.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P scopes-function-global-scope.cmake
     :cwd: code

* Intermediate scope. Calling function inherits its variables into
  called function.

  .. literalinclude:: code/scopes-function-local-scope-longer-call-chain.cmake
     :caption: :download:`scopes-function-local-scope-longer-call-chain.cmake
  	       (download) <code/scopes-function-local-scope-longer-call-chain.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P scopes-function-local-scope-longer-call-chain.cmake
     :cwd: code

Scopes: Directory Scope
-----------------------

* Variables are not only "inherited" across function 
* Also across directories

Given the project structure,

.. code-block:: text

   directory-scope/
   ├── CMakeLists.txt
   └── subdirectory
       └── CMakeLists.txt

Lets say the top level ``CMakeLists.txt`` has

.. code-block:: cmake

   set(some_variable "value")
   add_subdirectory(subdirectory)

and ``subdirectory/CMakeLists.txt`` has

.. code-block:: cmake

   message("subdirectory: \${some_variable}: ${some_variable}")

A CMake run would print,

.. code-block:: console

   $ cmake -B /tmp/cmake-demo/ -S ./code/directory-scope
   ...
   subdirectory: ${some_variable}: value
   ...
