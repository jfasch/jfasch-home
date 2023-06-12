.. ot-topic:: cxx11.new_language_features.concepts.writing_concepts
   :dependencies: cxx11.new_language_features.concepts.intro

.. include:: <mmlalias.txt>


Writing Your Own Concepts
=========================

.. contents::
   :local:

Starting Point: Good Old Function
---------------------------------

.. toctree::
   :hidden:

   writing-concepts/example-1-good-old-func

.. sidebar::

   **Source**

   * :doc:`writing-concepts/example-1-good-old-func`

* N-dimensional hypotenuse
* ``std::vector<double>``
* Using index based iteration, only too keep requirements to a minimum
* Requirements

  * ``.size()``
  * ``.operator[]()``

.. code-block:: c++

   double hypotenuse(const std::vector<double>& v)
   {
       double sumsq = 0;
       for (size_t i=0; i<v.size(); ++i)                  // <--- vector has .size()
           sumsq += v[i]*v[i];                            // <--- vector has []
       return std::sqrt(sumsq);
   }

Need Template
-------------

.. toctree::
   :hidden:

   writing-concepts/example-2-need-template

.. sidebar::

   **Source**

   * :doc:`writing-concepts/example-2-need-template`

* ``point2d``: members ``x, y`` (and potentially some operations on a
  point, but that is not the point here)
* How to fit that into ``hypotenuse()``?
* |longrightarrow| implement what's *required* by ``hypotenuse()``
  (``.size()`` and ``.operator[]()``)
* |longrightarrow| Turn ``hypotenuse()`` into a template
* *Straightforward*

.. code-block:: c++

   class point2d
   {
   public:
       point2d(double x, double y)
       : _x{x}, _y{y} {}
   
       size_t size() const { return 2; }                  // <--- point2d has .size() too
       double operator[](size_t i) const                  // <--- point2d has [] too
       {
           if (i==0) return _x;
           if (i==1) return _y;
           return 666;
       }
   private:
       double _x, _y;
   };

Error: Requirement Not Fulfilled
--------------------------------

.. code-block:: c++

   class point2d
   {
       // size_t size() const { return 2; }               // <--- requirement *not* fulfilled
   };

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

   writing-concepts/example-4-concept-has-size

.. sidebar::

   **Source**

   * :doc:`writing-concepts/example-4-concept-has-size`

* Implement concept ``has_size``
* Requires that any object of ``V`` has a ``.size()`` method
* |longrightarrow| i.e. the expression ``v.size()`` *compiles*

.. code-block:: c++

   template <typename V>
   concept has_size = requires(V v) {
       v.size();                                          // <--- compiles
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

Concept: ``index_returns_double``
---------------------------------

.. toctree::
   :hidden:

   writing-concepts/example-5-concept-index-ret-double

.. sidebar::

   **Source**

   * :doc:`writing-concepts/example-5-concept-index-ret-double`

* Hmm ... what if elements are not ``double``?
* |longrightarrow| Somebody could use ``hypotenuse()`` on something
  that has ``int`` coordinates
* Could we check this?

*Ruin the whole thing ...*

* Modify object initialization to take real double values,
  e.g. ``{3.5L, 4.5L}``
* |longrightarrow| Result not straight 5 anymore
* Modify ``point2d::operator[]()`` to return ``int``
* |longrightarrow| Result straight 5 again

*Concept* ``index_returns_double``

.. sidebar::

   **Documentation**

   * `std::same_as
     <https://en.cppreference.com/w/cpp/concepts/same_as>`__
   * `std::commone_reference_with
     <https://en.cppreference.com/w/cpp/concepts/common_reference_with>`__
   * <concepts>: `Standard library header
     <https://en.cppreference.com/w/cpp/header/concepts>`__
   * `std::vector
     <https://en.cppreference.com/w/cpp/container/vector>`__

* First use ``std::same_as<double>``
* |longrightarrow| Constraint check fails:
  ``std::vector::operator[]()`` is *not* same as ``double`` (rather, it returns ``double&``)
* Solution: ``std::commone_reference_with<double>``

.. code-block:: c++

   template <typename V>
   concept index_returns_double = requires(V v) {
       { v[0] } -> std::common_reference_with<double>;
   };

* Argh: checking multiple constraints is not possible with abbreviated
  function templates
* |longrightarrow| fall back to ordinary template syntax, and its
  ``requires`` clause
