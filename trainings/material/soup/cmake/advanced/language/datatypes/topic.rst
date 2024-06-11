.. ot-topic:: cmake.advanced.language.datatypes
   :dependencies: cmake.advanced.language.variables
.. include:: <mmlalias.txt>

Datatypes
=========

.. contents::
   :local:

There Are No Datatypes, Basta
-----------------------------

.. sidebar:: See also

   * :doc:`../if-and-conditions/topic`

* Everything is a string
* Can be interpreted as numeric, boolean, path, ... (see
  :doc:`../if-and-conditions/topic` for full ranting)
* My impressions is: although other languages are not typed either, no
  language does a job as bad as CMake's (even the good ol' shell is
  somewhat cool)
* Not all is as hard as ``if`` booleans though
* "Methods" provided for strings that are interpreted as

  * Strings
  * Lists
  * Regular expressions
  * ...

* *Complication*: where methods in other languages have return values
  (such as a str.substring(0,5)), CMake sets *output variables* (there
  is no return value in the language)
* *Rule*: variable names are passed to method *unquoted*

  .. code-block:: cmake

     string(APPEND variable "value")

Strings
-------

.. sidebar:: Documentation

   * `string
     <https://cmake.org/cmake/help/latest/command/string.html>`__

* Many methods for string modification |longrightarrow| variable
  passed *unquoted* (c/f "per-reference")
* Many mehtods for string examination |longrightarrow| variable passed
  *quoted* (c/f "per-copy")

Strings: In-Place Modification Of A Variable (Use Unquoted Names)
-----------------------------------------------------------------

* Variable is passed for modification
* |longrightarrow| per-reference
* |longrightarrow| unquoted

.. literalinclude:: code/string-inplace-simple.cmake
   :caption: :download:`string-inplace-simple.cmake (download)
	     <code/string-inplace-simple.cmake>`
   :language: cmake

.. command-output:: cmake -P string-inplace-simple.cmake
   :cwd: code
   :shell:

Pitfall: In-Place Modification Of Undefined Variable
----------------------------------------------------

Appending to an undefined variable *creates* that variable

.. literalinclude:: code/string-append-undefined.cmake
   :caption: :download:`string-append-undefined.cmake (download) <code/string-append-undefined.cmake>`
   :language: cmake

.. command-output:: cmake -P string-append-undefined.cmake
   :cwd: code
   :shell:

.. attention::

   This is not only true for string operations, but is a pattern
   across the language!

Pitfall: Quoted Variable Names For In-Place Modification
--------------------------------------------------------

Passing a variable in quotes (``"${some_variable}"``) is rarely what's
wanted

* Evaluates ``"${some_variable}"``
* Operates on that variable
* |longrightarrow| undefined, mostly

.. literalinclude:: code/string-pitfall-quote-varname.cmake
   :caption: :download:`string-pitfall-quote-varname.cmake (download)
             <code/string-pitfall-quote-varname.cmake>`
   :language: cmake

.. command-output:: cmake -P string-pitfall-quote-varname.cmake
   :cwd: code
   :shell:

Strings: Non-Modifying Operations (Use Quoted Names)
----------------------------------------------------

* Non-modifying methods work best on copies of variables
* |longrightarrow| quoting/evaluation
* *Note* how the to-be-created output variable is passwd

.. literalinclude:: code/string-substring.cmake
   :caption: :download:`string-substring.cmake (download)
             <code/string-substring.cmake>`
   :language: cmake

.. command-output:: cmake -P string-substring.cmake
   :cwd: code
   :shell:

Pitfall: Unquoted Variable Names For Non-Modifying Operations
-------------------------------------------------------------

.. literalinclude:: code/string-substring-unquoted.cmake
   :caption: :download:`string-substring-unquoted.cmake (download)
             <code/string-substring-unquoted.cmake>`
   :language: cmake

.. command-output:: cmake -P string-substring-unquoted.cmake
   :cwd: code
   :shell:

Strings: Methods, By Example
----------------------------

.. sidebar:: Documentation

   * `string
     <https://cmake.org/cmake/help/latest/command/string.html>`__

* Find a substring (returns position)

  .. literalinclude:: code/string-substring.cmake
     :caption: :download:`string-substring.cmake (download)
               <code/string-substring.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P string-substring.cmake
     :cwd: code
     :shell:
    
  .. literalinclude:: code/string-substring-reverse.cmake
     :caption: :download:`string-substring.cmake (download)
               <code/string-substring.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P string-substring-reverse.cmake
     :cwd: code
     :shell:
  
* Joining a number of strings

  .. literalinclude:: code/string-join.cmake
     :caption: :download:`string-join.cmake (download)
               <code/string-join.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P string-join.cmake
     :cwd: code
     :shell:

* Comparing strings (and storing a boolean value for later use)

  .. literalinclude:: code/string-compare.cmake
     :caption: :download:`string-compare.cmake (download)
               <code/string-compare.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P string-compare.cmake
     :cwd: code
     :shell:

Lists
-----

.. sidebar:: Documentation

   * `list <https://cmake.org/cmake/help/latest/command/list.html>`__

* A list is a string where the list items are separated with
  semicolons (``";"``)
* Created using ``set()`` ...

  .. literalinclude:: code/list-create-with-set.cmake
     :caption: :download:`list-create-with-set.cmake (download)
  	     <code/list-create-with-set.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P list-create-with-set.cmake
     :cwd: code
     :shell:

* ... or with any of the modifying list commands

  .. literalinclude:: code/list-create-with-append.cmake
     :caption: :download:`list-create-with-append.cmake (download)
  	     <code/list-create-with-append.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P list-create-with-append.cmake
     :cwd: code
     :shell:

* Various commands (``message()``) take lists, implicitly. Best by
  example.

  .. literalinclude:: code/list-message.cmake
     :caption: :download:`list-message.cmake (download)<code/list-message.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P list-message.cmake
     :cwd: code
     :shell:

Lists: Iteration (``foreach`` Loop)
-----------------------------------

.. sidebar:: See also

   * :doc:`../foreach/topic`

* ``foreach()`` operates on *elements*, not on lists (see :doc:`../foreach/topic`)
* Separators can either be spaces (``" "``) or semicolons (``";"``)
* |longrightarrow| Unquoted string reference (clearly |:pig:|)

.. literalinclude:: code/list-iterate.cmake
   :caption: :download:`list-iterate.cmake (download)
             <code/list-iterate.cmake>`
   :language: cmake

.. command-output:: cmake -P list-iterate.cmake
   :cwd: code
   :shell:

Lists: Methods, By Example
--------------------------

* Appending elements to a list

  .. literalinclude:: code/list-append.cmake
     :caption: :download:`list-append.cmake (download)
               <code/list-append.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P list-append.cmake
     :cwd: code
     :shell:
    
* Length of a list

  .. literalinclude:: code/list-length.cmake
     :caption: :download:`list-length.cmake (download)
               <code/list-length.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P list-length.cmake
     :cwd: code
     :shell:

* Remove element at position

  .. literalinclude:: code/list-remove-at.cmake
     :caption: :download:`list-remove-at.cmake (download)
               <code/list-remove-at.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P list-remove-at.cmake
     :cwd: code
     :shell:
