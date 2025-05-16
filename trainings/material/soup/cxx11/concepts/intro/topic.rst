.. include:: <mmlalias.txt>


Concepts: Overview
==================

.. contents::
   :local:

.. sidebar::

   **Documentation**

   * `Constraints and concepts (since C++20)
     <https://en.cppreference.com/w/cpp/language/constraints>`__
   * `Concepts library (since C++20)
     <https://en.cppreference.com/w/cpp/concepts>`__
   * <concepts>: `Standard library header
     <https://en.cppreference.com/w/cpp/header/concepts>`__

Motivation
----------

* Error messages on failed template instantiations are brutal
* |longrightarrow| Solution needed
* Template metaprogramming is *not* a solution

  * Few people are able to understand it 
  * ... let alone read it

* Enter *Concepts*: compiletime template parameter validation
* Relatively easy language to formulate what's needed for successful
  substitution
* Let's walk through a simple example: using the ``std::integral``
  concept from ``<concepts>``

No Problem: Template Instantiation Chosen By Parameter Type
-----------------------------------------------------------

* Everything fine
* Template used with compatible types (compatible?)
* |longrightarrow| no errors

.. literalinclude:: code/is-even-no-concept-ok.cpp
   :caption: :download:`code/is-even-no-concept-ok.cpp`
   :language: c++

Problem: Template Instantiation Chosen By Parameter Type
--------------------------------------------------------

* Not fine
* ``%`` not defined for floating point numbers
* Template instantiated nonetheless
* |longrightarrow| Error (possibly deep down complicated code)
* |longrightarrow| User can only guess

.. literalinclude:: code/is-even-no-concept-error.cpp
   :caption: :download:`code/is-even-no-concept-error.cpp`
   :language: c++

.. code-block:: console

   In instantiation of ‘bool is_even(T) [with T = double]’:
      required from here
   error: invalid operands of types ‘double’ and ‘int’ to binary ‘operator%’
       6 |     return (num % 2) == 0;
         |            ~~~~~^~~~
   

Concepts To The Rescue
----------------------

.. sidebar::

   **Documentation**

   * `std::integral <https://en.cppreference.com/w/cpp/concepts/integral>`__
   * `Concepts library (since C++20)
     <https://en.cppreference.com/w/cpp/concepts>`__

* Implicit constraint: ``%`` is only defined for integral types
* Why not make that constraint *explicit*?
* A case for ``<concepts>``
* |longrightarrow| ``std::integral``

.. literalinclude:: code/is-even-concept-canonical.cpp
   :caption: :download:`code/is-even-concept-canonical.cpp`
   :language: c++

.. code-block:: console

   note: constraints not satisfied
      required from here                                  # <-- watch out for this
   /usr/include/c++/13/concepts:100:13:   required for the satisfaction of ‘integral<T>’ [with T = double]
   /usr/include/c++/13/concepts:100:24: note: the expression ‘is_integral_v<_Tp> [with _Tp = double]’ evaluated to ‘false’
     100 |     concept integral = is_integral_v<_Tp>;
         |                        ^~~~~~~~~~~~~~~~~~

Alternative Concept Syntaxes
----------------------------

C++ does not follow rule 13 of "The Zen of Python":

   | There should be one-- and preferably only one --obvious way to do
   | it.

.. literalinclude:: code/is-even-concept-post-prototype.cpp
   :caption: :download:`code/is-even-concept-post-prototype.cpp`
   :language: c++

.. literalinclude:: code/is-even-concept-at-param.cpp
   :caption: :download:`code/is-even-concept-at-param.cpp`
   :language: c++

.. literalinclude:: code/is-even-concept-abbrev-func-template.cpp
   :caption: :download:`code/is-even-concept-abbrev-func-template.cpp`
   :language: c++
