.. ot-topic:: cxx11.new_language_features.concepts.intro

.. include:: <mmlalias.txt>


Concepts: Overview
==================

.. contents::
   :local:

.. sidebar::

   **Documentation**

   * `Constraints and Concepts
     <https://en.cppreference.com/w/cpp/language/constraints>`__
   * <concepts>: `Standard library header
     <https://en.cppreference.com/w/cpp/header/concepts>`__

Motivation
----------

* Error messages on failed template instantiations are brutal
* |longrightarrow| Solution needed
* Template metaprogramming is *not* a solution

  * Few people are able to understand it 
  * ... let alone read it

* Enter *Concepts*
* Relatively easy language to formulate what's needed for successful
  substitution
* Let's walk through a simple example: using the ``std::integral``
  concept from ``<concepts>``

No Problem: Template Instantiation Chosen By Parameter Type
-----------------------------------------------------------

.. toctree::
   :hidden:

   intro/toolcase-1-conceptless

.. sidebar::

   **Source**

   * :doc:`intro/toolcase-1-conceptless`

.. code-block:: c++

   template <typename T>
   bool is_even(T num)
   {
       return (num % 2) == 0;
   }
   
   is_even(3);
   is_even(4UL);
   is_even(4L);

* Everything fine
* Template used with compatible types (compatible?)
* |longrightarrow| no errors

Problem: Template Instantiation Chosen By Parameter Type
--------------------------------------------------------

.. toctree::
   :hidden:

   intro/toolcase-2-conceptless-error

.. sidebar::

   **Source**

   * :doc:`intro/toolcase-2-conceptless-error`

.. code-block:: c++

   is_even(1.5);

* Not fine
* ``%`` not defined for floating point numbers
* Template instantiated nonetheless
* |longrightarrow| Error (possibly deep down complicated code)
* |longrightarrow| User can only guess

.. code-block:: console

   toolcase-2-conceptless-error.cpp: In instantiation of ‘bool is_even(T) [with T = double]’:
   toolcase-2-conceptless-error.cpp:11:25:   required from here
   toolcase-2-conceptless-error.cpp:6:17: error: invalid operands of types ‘double’ and ‘int’ to binary ‘operator%’
       6 |     return (num % 2) == 0;
         |            ~~~~~^~~~

Concepts To The Rescue
----------------------

.. toctree::
   :hidden:

   intro/toolcase-3-concept-integral

.. sidebar::

   **Documentation**

   * `std::integral <https://en.cppreference.com/w/cpp/concepts/integral>`__

   **Source**

   * :doc:`intro/toolcase-3-concept-integral`

* Implicit constraint: ``%`` is only defined for integral types
* Why not make that constraint *explicit*?
* A case for ``<concepts>``
* |longrightarrow| ``std::integral``

.. code-block:: c++

   template <typename T>
   requires std::integral<T>
   bool is_even(T num) { /*...*/ }

* Gives the following compiler error 
* Have to read carefully though

.. code-block:: console

   toolcase-3-concept-integral.cpp:13:25: error: no matching function for call to ‘is_even(double)’
      13 |     std::cout << is_even(1.5) << std::endl;
         |                  ~~~~~~~^~~~~
   toolcase-3-concept-integral.cpp:6:6: note: candidate: ‘template<class T>  requires  integral<T> bool is_even(T)’
       6 | bool is_even(T num)
         |      ^~~~~~~
   toolcase-3-concept-integral.cpp:6:6: note:   template argument deduction/substitution failed:
   toolcase-3-concept-integral.cpp:6:6: note: constraints not satisfied            # <--- HERE!!!
   In file included from toolcase-3-concept-integral.cpp:1:
   /usr/include/c++/12/concepts: In substitution of ‘template<class T>  requires  integral<T> bool is_even(T) [with T = double]’:
   toolcase-3-concept-integral.cpp:13:25:   required from here
   /usr/include/c++/12/concepts:100:13:   required for the satisfaction of ‘integral<T>’ [with T = double]
   /usr/include/c++/12/concepts:100:24: note: the expression ‘is_integral_v<_Tp> [with _Tp = double]’ evaluated to ‘false’
     100 |     concept integral = is_integral_v<_Tp>;
         |                        ^~~~~~~~~~~~~~~~~~

Syntactic Variations
--------------------

Apparently C++ does not follow rule 13 of "The Zen of Python":

   | There should be one-- and preferably only one --obvious way to do
   | it.

.. code-block:: c++

   template <typename T>
   bool is_even(T num) requires std::integral<T>          // <--- same, but different
   {
       return (num % 2) == 0;
   }

* Cool: instead of ``typename``

.. code-block:: c++

   template <std::integral T>                             // <--- cool
   bool is_even(T num)
   {
       return (num % 2) == 0;
   }

.. sidebar::

   **Documentation**

   * `Function template
     <https://en.cppreference.com/w/cpp/language/function_template>`__

* Really cool: *Abbreviated Function Template*

.. code-block:: c++

   bool is_even(std::integral auto num)                   // <--- cool: abbreviated function template
   {                                                      //      (with constraint std::integral)
       return (num % 2) == 0;
   }
