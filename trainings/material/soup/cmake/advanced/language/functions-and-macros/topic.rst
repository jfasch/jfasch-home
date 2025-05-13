.. include:: <mmlalias.txt>


Functions And Macros
====================

.. contents::
   :local:

.. sidebar:: Documentation

   * `function
     <https://cmake.org/cmake/help/latest/command/function.html>`__

Simplest Of Functions
---------------------

.. literalinclude:: code/function-simple.cmake
   :caption: :download:`function-simple.cmake (download) <code/function-simple.cmake>`
   :language: cmake

.. command-output:: cmake -P function-simple.cmake
   :cwd: code
   :shell:

Function Scope
--------------

.. sidebar:: See also

   * :doc:`../variables/topic`

* Variables are local to a function

  .. literalinclude:: code/function-scope.cmake
     :caption: :download:`function-scope.cmake (download)
               <code/function-scope.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P function-scope.cmake
     :cwd: code
     :shell:

* Caller's (parent's) variables are visible inside a function

  .. literalinclude:: code/function-scope-parent.cmake
     :caption: :download:`function-scope-parent.cmake (download)
               <code/function-scope-parent.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P function-scope-parent.cmake
     :cwd: code
     :shell:

* Function cannot modify caller's variables |longrightarrow| *function
  scope is a copy of caller's scope*

Function Scope: And Nested Function?
------------------------------------

.. sidebar:: See also

   * :doc:`../variables/topic`

* Calling functions inherit their scope into called functions

  .. literalinclude:: code/function-nested-scope.cmake
     :caption: :download:`function-nested-scope.cmake (download) <code/function-nested-scope.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P function-nested-scope.cmake
     :cwd: code
     :shell:

Passing Parameters In
---------------------

.. sidebar:: See also

   * :doc:`../variables/topic`

* In function "body", formal parameters (e.g. ``param``) are treated
  just like :doc:`variables <../variables/topic>`

  .. literalinclude:: code/function-one-parameter.cmake
     :caption: :download:`function-one-parameter.cmake (download) <code/function-one-parameter.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P function-one-parameter.cmake
     :cwd: code
     :shell:

* Superfluous parameters are discarded |longrightarrow| *quoting!*

  .. literalinclude:: code/function-one-parameter-passed-two.cmake
     :caption: :download:`function-one-parameter-passed-two.cmake
               (download)
               <code/function-one-parameter-passed-two.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P function-one-parameter-passed-two.cmake
     :cwd: code
     :shell:
  
* ... whereas missing parameters cause a CMake error

  .. literalinclude:: code/function-one-parameter-passed-none.cmake
     :caption: :download:`function-one-parameter-passed-none.cmake
               (download)
               <code/function-one-parameter-passed-none.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P function-one-parameter-passed-none.cmake
     :returncode: 1
     :cwd: code
     :shell:

* This is a function that takes two formal parameters

  .. literalinclude:: code/function-two-parameters.cmake
     :caption: :download:`function-two-parameters.cmake (download)
               <code/function-two-parameters.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P function-two-parameters.cmake
     :cwd: code
     :shell:

Parameters: ``ARGC``, ``ARGV``, ``ARGVn``, ``ARGN``
---------------------------------------------------

* ``ARGC``: number of arguments passed

  .. literalinclude:: code/function-argc.cmake
     :caption: :download:`function-argc.cmake (download)
               <code/function-argc.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P function-argc.cmake
     :cwd: code
     :shell:

* ``ARGV``: list of all arguments

  .. literalinclude:: code/function-argv.cmake
     :caption: :download:`function-argv.cmake (download)
               <code/function-argv.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P function-argv.cmake
     :cwd: code
     :shell:

* ``ARGVn``: referencing arguments by position (invalid position
  |longrightarrow| empty/undefined)

  .. literalinclude:: code/function-argvn.cmake
     :caption: :download:`function-argvn.cmake (download)
               <code/function-argvn.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P function-argvn.cmake
     :cwd: code
     :shell:

* ``ARGN``: arguments past the last formal argument

  .. literalinclude:: code/function-argn.cmake
     :caption: :download:`function-argn.cmake (download)
	       <code/function-argn.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P function-argn.cmake
     :cwd: code
     :shell:

And Output Variables? Return Values?
------------------------------------

.. sidebar:: Documentation

   * `set <https://cmake.org/cmake/help/latest/command/set.html>`__

* There is no ``return`` statement
* |longrightarrow| functions aren't expressions
* No "output" parameters (like references in C++, or pointers in C)
* ... but there is ``set(... PARENT_SCOPE)``

``PARENT_SCOPE`` Examples
-------------------------

* Creating a variable in caller scope just because we can

  .. literalinclude:: code/function-reaching-out.cmake
     :caption: :download:`function-reaching-out.cmake (download)
               <code/function-reaching-out.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P function-reaching-out.cmake
     :cwd: code
     :shell:

* Modifying a variable passed in by the caller ("output variable",
  "pass by reference")

  .. literalinclude:: code/function-output-parameter.cmake
     :caption: :download:`function-output-parameter.cmake (download)
               <code/function-output-parameter.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P function-output-parameter.cmake
     :cwd: code
     :shell:

* Popular trick, used by many CMake functions: set multiple variables
  *with the same prefix* in caller scope

  .. literalinclude:: code/function-reaching-out-stem.cmake
     :caption: :download:`function-reaching-out-stem.cmake (download) <code/function-reaching-out-stem.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P function-reaching-out-stem.cmake
     :cwd: code
     :shell:

Passing Any Number Of Parameters
--------------------------------

* Special parameters ``ARGC`` (number of arguments) and ``ARGV`` (of
  list type)

  .. literalinclude:: code/function-varargs.cmake
     :caption: :download:`function-varargs.cmake (download) <code/function-varargs.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P function-varargs.cmake
     :cwd: code
     :shell:

* Accessing parameters by position

  .. literalinclude:: code/function-varargs-by-position.cmake
     :caption: :download:`function-varargs-by-position.cmake
               (download) <code/function-varargs-by-position.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P function-varargs-by-position.cmake
     :cwd: code
     :shell:

Fancy Parameter Parsing: ``cmake_parse_arguments()``
----------------------------------------------------

.. sidebar:: Documentation

   * `cmake_parse_arguments
     <https://cmake.org/cmake/help/latest/command/cmake_parse_arguments.html>`__

.. literalinclude:: code/function-parse-args.cmake
   :caption: :download:`function-parse-args.cmake (download) <code/function-parse-args.cmake>`
   :language: cmake

.. command-output:: cmake -P function-parse-args.cmake
   :cwd: code
   :shell:

And Macros?
-----------

* Just like functions
* ... only without own scope
* |longrightarrow| share caller's scope

.. literalinclude:: code/macro-simple.cmake
   :caption: :download:`macro-simple.cmake (download)
             <code/macro-simple.cmake>`
   :language: cmake

.. command-output:: cmake -P macro-simple.cmake
   :cwd: code
   :shell:
