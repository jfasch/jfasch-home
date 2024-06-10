.. ot-topic:: cmake.advanced.language_basics.if_and_conditions
   :dependencies: cmake.advanced.language_basics.variables
.. include:: <mmlalias.txt>


CMake: ``if``, And Conditions
=============================

.. contents::
   :local:

``if`` Syntax
-------------

.. sidebar:: Documentation

   * `if <https://cmake.org/cmake/help/latest/command/if.html>`__

* Much like in other languages

  .. literalinclude:: code/if-good.cmake
     :caption: :download:`if-good.cmake (download)
  	     <code/if-good.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P if-good.cmake
     :cwd: code
     :shell:

* **Much complexity in the evaluation of the condition**
* The following holds true for ``if()``, ``elseif()``, and ``while()``

Predefined Conditions: String Comparison
----------------------------------------

.. sidebar:: Documentation

   * `if (Comparisons)
     <https://cmake.org/cmake/help/latest/command/if.html#comparisons>`__

* Lexicographic comparison, e.g. ``STRLESS``

  .. literalinclude:: code/if-strless.cmake
     :caption: :download:`if-strless.cmake (download)
  	     <code/if-strless.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P if-strless.cmake
     :cwd: code
     :shell:

* Numerical comparison, e.g. ``LESS``

  .. literalinclude:: code/if-less.cmake
     :caption: :download:`if-less.cmake (download)
  	     <code/if-less.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P if-less.cmake
     :cwd: code
     :shell:

Pitfalls: Variables Are Strings, And CMake Does Not Care
--------------------------------------------------------

* Comparing apples and oranges: *no runtime error*
* CMake just says "no"

.. literalinclude:: code/if-less-mismatch.cmake
   :caption: :download:`if-less-mismatch.cmake (download)
	     <code/if-less-mismatch.cmake>`
   :language: cmake

.. command-output:: cmake -P if-less-mismatch.cmake
   :cwd: code
   :shell:

.. danger:: Be careful! Test!!

Predefined Conditions: File System
----------------------------------

.. sidebar:: Documentation

   * `if (File Operations)
     <https://cmake.org/cmake/help/latest/command/if.html#file-operations>`__
   * `if (Path Comparisons)
     <https://cmake.org/cmake/help/latest/command/if.html#path-comparisons>`__

* File existence, etc.

  .. literalinclude:: code/if-file-exists-and-is-directory.cmake
     :caption: :download:`if-file-exists-and-is-directory.cmake
  	     (download) <code/if-file-exists-and-is-directory.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P if-file-exists-and-is-directory.cmake
     :cwd: code
     :shell:

* Path comparison

  .. literalinclude:: code/if-path-comparison.cmake
     :caption: :download:`if-path-comparison.cmake
  	     (download) <code/if-path-comparison.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P if-path-comparison.cmake
     :cwd: code
     :shell:
  
Policies?
---------

.. sidebar:: Documentation

   * `cmake_policy()
     <https://cmake.org/cmake/help/latest/command/cmake_policy.html>`__

*Concrete problem*: in the above code snippet, CMake version 3.27.7
(``cmake --version``) failed to recognise the ``PATH_EQUAL`` operator,
with a message saying something about policy ``CMP0139``.

.. command-output:: cmake --help-policy CMP0139
   :cwd: code
   :shell:

*Solution*: set the damn policy

.. code-block:: cmake

   cmake_policy(SET CMP0139 NEW)           # <--- argh!

.. note::

   * Try not to set policies in any of the 100 ``CMakeLists.txt``
     files in your project
   * Reserve the toplevel ``CMakeLists.txt`` for such administrative
     tasks

Miscellaneous Checks (Some Rather Advanced)
-------------------------------------------

.. sidebar:: Documentation

   * `if (Existence Checks)
     <https://cmake.org/cmake/help/latest/command/if.html#existence-checks>`__

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cmake/advanced/conditional-code-approach-1/topic`
   * :doc:`/trainings/material/soup/cmake/advanced/conditional-code-approach-2/topic`
   * :doc:`/trainings/material/soup/cmake/advanced/conditional-code-problem/topic`


* Is a variable defined? *Note: a variable may be defined but empty*

  .. literalinclude:: code/if-defined.cmake
     :caption: :download:`if-defined.cmake (download)
	       <code/if-defined.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P if-defined.cmake
     :cwd: code
     :shell:

* Does a target exist?

  .. literalinclude:: code/if-target.cmake
     :caption: :download:`if-target.cmake (download)
	       <code/if-target.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P if-target.cmake
     :cwd: code
     :shell:

  .. note::

     * Targets are *architecturally relevant*
     * Properties are probably a better way to communicate
       optionality.

Condition Evaluation (Where The Mess Begins): What's Boolean?
-------------------------------------------------------------

So far, we only used strings in the examples 

.. attention::

   * *Rule*: use strings explicitly as much as you can in your CMake code

     * This keeps you mentally sane
     * This will help colleagues understand your code

   * *Rule*: set policy ``CMP0012`` to ``NEW``

* ``if`` (and ``while``, for that matter) exists in CMake for a long
  time
* |longrightarrow| long before ``${NAME}`` has been considered the way
  to go for *variable references*
* |longrightarrow| *confusion*
* ``if`` understands "literals"/"constants" |longrightarrow| there is
  no such definition in the language, it just happened

Dereferencing Unquoted Variable Names
-------------------------------------

.. literalinclude:: code/if-unquoted.cmake
   :caption: :download:`if-unquoted.cmake (download)
	     <code/if-unquoted.cmake>`
   :language: cmake

.. command-output:: cmake -P if-unquoted.cmake
   :cwd: code
   :shell:

.. _bool-literals:

"Boolean" Variables: Weirdly Interpreted Strings
------------------------------------------------

.. sidebar:: Documentation

   * `if (Basic Expressions)
     <https://cmake.org/cmake/help/latest/command/if.html#basic-expressions>`__

* First: there is no boolean type
* |longrightarrow| only strings that are interpreted *somehow*

  * ``1``, ``ON``, ``YES``, ``TRUE``, ``Y`` (case-insensitively) are
    interpreted as boolean true
  * ``0``, ``OFF``, ``NO``, ``FALSE``, ``N``, ``IGNORE``,
    ``NOTFOUND``, the empty string, or ends in the suffix
    ``-NOTFOUND`` (case-insensitively) are interpreted as boolean
    false.

* |longrightarrow| *please listen, and suffer*
* A naive approach would be to pretend to not know all that ...

  .. literalinclude:: code/if-bool-naive.cmake
     :caption: :download:`if-bool-naive.cmake (download)
	       <code/if-bool-naive.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P if-bool-naive.cmake
     :cwd: code
     :shell:

* But this is not how CMake wants it

  .. literalinclude:: code/if-bool-cmake.cmake
     :caption: :download:`if-bool-cmake.cmake (download)
	       <code/if-bool-cmake.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P if-bool-cmake.cmake
     :cwd: code
     :shell:

.. attention::

   All would be well if that was all. But we have no such luck.

Pitfall: Evaluation Until There Is No More
------------------------------------------

* When CMake evaluates ("interpolates", "expands") strings, it does so
  until there's nothing left.
* ... which can lead to surprising results
* The following evaluates to the plain string ``"boolean_variable"``,
  which is turn is recognized by CMake as a variable reference

.. literalinclude:: code/if-boolshit-expand-loop.cmake
   :caption: :download:`if-boolshit-expand-loop.cmake (download)
	     <code/if-boolshit-expand-loop.cmake>`
   :language: cmake

.. command-output:: cmake -P if-boolshit-expand-loop.cmake
   :cwd: code
   :shell:

Pitfall: Evaluation Of Unquoted Arguments
-----------------------------------------

* Undefined variables evaluate to boolean false. Just like before,
  quoting evaluates until there is no more

  * ``"${foo}"`` evaluates to ``"bar"``
  * ... which is then taken by ``if`` as an unquoted reference to
    variable ``bar``
  * ``bar`` is not defined which evaluates to boolean false

  .. literalinclude:: code/if-boolshit-par-excellence-ok.cmake
     :caption: :download:`if-boolshit-par-excellence-ok.cmake (download)
  	     <code/if-boolshit-par-excellence-ok.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P if-boolshit-par-excellence-ok.cmake
     :cwd: code
     :shell:

* **Biggest crap ever seen**: unquoted variable references are special

  * ``foo`` evaluates to ``"bar"``
  * ``"bar"`` is not equal to one of the *false* literals (remember
    :ref:`bool-literals`)
  * |longrightarrow| hence it can only mean **boolean true**

  .. literalinclude:: code/if-boolshit-par-excellence.cmake
     :caption: :download:`if-boolshit-par-excellence.cmake (download)
	       <code/if-boolshit-par-excellence.cmake>`
     :language: cmake
  
  .. command-output:: cmake -P if-boolshit-par-excellence.cmake
     :cwd: code
     :shell:
