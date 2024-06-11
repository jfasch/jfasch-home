.. ot-topic:: cmake.advanced.language.basics
.. include:: <mmlalias.txt>

Language Basics
===============

.. contents::
   :local:

Single Line Comments
--------------------

* Like in C++ (well, approximately |:face_with_raised_eyebrow:|)
* Single-line comments

.. literalinclude:: code/comments/single-line-comment-whole.cmake
   :language: cmake

.. literalinclude:: code/comments/single-line-comment-rest-of-line.cmake
   :language: cmake

Multiline Comments ("Bracketed Comments")
-----------------------------------------

* Start with a hash ("#"), two opening square brackets ("["),
  interleaved with any number of equal signs ("=")
* Closed with the same pattern, only with closing square brackets
  ("]")

.. literalinclude:: code/comments/single-line-comment-bracketed-simple.cmake
   :language: cmake

* Nesting of comments possible by varying the number of equal signs

.. literalinclude:: code/comments/single-line-comment-bracketed-nested.cmake
   :language: cmake

* Trick: turning multiline nested comments into live code -
  *comment out the comment*

.. literalinclude:: code/comments/single-line-comment-bracketed-nested-trick.cmake
   :language: cmake

Command Execution
-----------------

.. sidebar:: See also

   * :doc:`../functions-and-macros/topic`

* Command names are case insensitive (arguments are just strings, so
  sensitivity depends upon what the command wants from them)
* Arguments are separated by whitespaces
* Example: command ``message`` invoked with two arguments

.. literalinclude:: code/commands/sample-invocation.cmake
   :language: cmake

outputs

.. code-block:: text

   ...
   helloworld
   helloworld
   helloworld
   ...

Commands: String *Evaluation*, And Quoting
------------------------------------------

* When are aruments quoted?
* |longrightarrow| when you want *evaluation*
* |longrightarrow| interpolation of variables into them

Different argument type

* Bracketed arguments
* Quoted arguments
* Unquoted arguments

Commands: Bracketed Arguments
-----------------------------

* Passing multiline strings into commands
* Much like multiline comments
* Of limited use - pre-formatted text blocks, at most

.. literalinclude:: code/commands/bracket.cmake
   :language: cmake

* No string interpolation occurs

.. literalinclude:: code/commands/bracket-no-evaluate.cmake
   :caption: `bracket-no-evaluate.cmake
             <code/commands/bracket-no-evaluate.cmake>`
   :language: cmake

.. code-block:: console

   $ cmake -P bracket-no-evaluate.cmake
   the variable
   ${some_variable} is not interpolated

Commands: Quoted Arguments
--------------------------

.. sidebar:: See also

   * :doc:`../datatypes/topic`

* C-like escape chararcters

  .. literalinclude:: code/commands/quoted-c-escapes.cmake
     :caption: :download:`quoted-c-escapes.cmake (download)
  	     <code/commands/quoted-c-escapes.cmake>`
     :language: text
  
  .. command-output:: cmake -P quoted-c-escapes.cmake
     :cwd: code/commands
     :shell:

* Multiline strings

  .. literalinclude:: code/commands/multiline-strings.cmake
     :caption: :download:`multiline-strings.cmake (download)
  	     <code/commands/multiline-strings.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P multiline-strings.cmake
     :cwd: code/commands
     :shell:

* Variable expansion

  .. literalinclude:: code/commands/variable-expansion.cmake
     :caption: :download:`variable-expansion.cmake (download)
  	     <code/commands/variable-expansion.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P variable-expansion.cmake
     :cwd: code/commands
     :shell:

Commands: Unquoted Arguments
----------------------------

.. attention:: Always Quote Arguments

   * Unquoted arguments, if used correctly, can save a few keystrokes
   * It's just hard to use unquoted arguments correctly
   * |longrightarrow| **Try to always quote your arguments!**

* Correct usage example

  .. literalinclude:: code/commands/unquoted-arguments-correct.cmake
     :caption: :download:`unquoted-arguments-correct.cmake (download)
  	     <code/commands/unquoted-arguments-correct.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P unquoted-arguments-correct.cmake
     :cwd: code/commands
     :shell:

* List confusion

  Lists are strings that are separated by " " (or ``;``)

  .. literalinclude:: code/commands/unquoted-arguments-list.cmake
     :caption: :download:`unquoted-arguments-list.cmake (download)
  	     <code/commands/unquoted-arguments-list.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P unquoted-arguments-list.cmake
     :cwd: code/commands
     :shell:
