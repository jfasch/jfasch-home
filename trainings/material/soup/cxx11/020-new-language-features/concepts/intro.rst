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

Motivation
----------

* Error messages failed template instantiations are brutal
* |longrightarrow| Solution needed
* Template metaprogramming is *not* a solution

  * Few people are able to understand it 
  * ... let alone read it

* Enter *Concepts*
* Relatively easy language to formulate what's needed for successful
  substitution
* Let's walk through an initial concept by example ...

Starting Point: Good Old Function
---------------------------------

.. toctree::
   :hidden:

   intro/example-1-good-old-func

.. sidebar::

   **Source**

   * :doc:`intro/example-1-good-old-func`

* N-dimensional hypotenuse
* ``std::vector<double>``
* Using index based iteration, only too keep requirements to a minimum
* Requirements

  * ``.size()``
  * ``.operator[]()``

Need Template
-------------

.. toctree::
   :hidden:

   intro/example-2-need-template

.. sidebar::

   **Source**

   * :doc:`intro/example-2-need-template`

* ``point2d``: members ``x, y`` (and potentially some operations on a
  point, but that is not the point here)
* How to fit that into ``hypotenuse()``?
* |longrightarrow| implement what's *required* by ``hypotenuse()``
  (``.size()`` and ``.operator[]()``)
* |longrightarrow| Turn ``hypotenuse()`` into a template
* *Straightforward*

Error: Requirement Not Fulfilled
--------------------------------

* Uncomment ``.size()``
* Error message is relatively clear (see below)
* ``error: ‘const class point2d’ has no member named ‘size’``
* Can be worse though; for example if helper types (possibly nested a
  dozen levels deep) are instantiated by the implementation

.. code-block:: console

   example-3-requirement-not-fulfilled.cpp: In instantiation of ‘double hypotenuse(const V&) [with V = point2d]’:
   example-3-requirement-not-fulfilled.cpp:39:28:   required from here
   example-3-requirement-not-fulfilled.cpp:9:26: error: ‘const class point2d’ has no member named ‘size’
       9 |     for (size_t i=0; i<v.size(); ++i)
         |                        ~~^~~~

Concept: ``has_size``
---------------------

.. toctree::
   :hidden:

   intro/example-4-concept-has-size

.. sidebar::

   **Source**

   * :doc:`intro/example-4-concept-has-size`

* Implement concept ``has_size``
* Requires that any object of ``V`` has a ``.size()`` method
* |longrightarrow| i.e. the expression ``v.size()`` compiles

.. code-block:: c++

   template <typename V>
   concept has_size = requires(V v) {
       v.size();
   };

* Concept usage: good old full explicit template

.. code-block:: c++

   template <typename V>
   requires has_size<V>
   double hypotenuse(const V& v) { /*...*/ }

* Concept usage: good old full explicit template (after declaration)

.. code-block:: c++

   template <typename V>
   double hypotenuse(const V& v) requires has_size<V> { /*...*/ }

* Concept usage: abbreviated function templates

.. code-block:: c++

   double hypotenuse(const has_size auto& v) { /*...*/ }

