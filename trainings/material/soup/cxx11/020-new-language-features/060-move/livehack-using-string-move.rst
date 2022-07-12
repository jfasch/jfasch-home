.. ot-topic:: cxx11.new_language_features.move.livehack_using_string_move
   :dependencies: cxx11.new_language_features.move.livehack_string_move,
		  cxx11.new_language_features.move.overview

.. include:: <mmlalias.txt>


Using Move Semantics In Own Code
================================

.. contents::
   :local:

Using ``String``: ``class Person``
----------------------------------

* Idea: constructor taking person's ``firstname`` and ``lastname``
* Passing temporaries right into members |longrightarrow| implement
  move constructor

.. literalinclude:: code/person-10.h
   :caption: :download:`code/person-10.h`
   :language: c++

.. literalinclude:: code/person-suite-bogus.cpp
   :caption: :download:`code/person-suite-bogus.cpp`
   :language: c++

.. code-block:: console

   code/person-10.h:9:7: error: use of deleted function ‘String::String(const String&)’
       9 |     : firstname(firstname), lastname(lastname) {}
         |       ^~~~~~~~~~~~~~~~~~~~

What?
-----

.. sidebar:: 

   **See also**

   * :ref:`Lvalue definition <lvalue-definition>`
   * :ref:`Rvalue reference parameters are lvalues
     <use-of-rvalue-inside-function>`

* Remember: inside a function, :ref:`rvalue reference parameters are
  lvalues <use-of-rvalue-inside-function>`
* They have names

  * |longrightarrow| can determine its address
  * ... which is the :ref:`definition of an lvalue
    <lvalue-definition>`

* Solution: convert into rvalue reference
* |longrightarrow| ``std::move``

Using Rvalue References Inside Function: ``std::move``
------------------------------------------------------

jjjjj
