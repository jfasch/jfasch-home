.. include:: <mmlalias.txt>


Writing Your Own Concepts
=========================

.. contents::
   :local:

Starting Point: Good Old Function
---------------------------------

* N-dimensional hypotenuse, over ``std::vector<double>``
* Uses

  * ``v.size()``
  * ``v.operator[]()``

.. literalinclude:: code/hypotenuse-good-old-function.cpp
   :caption: :download:`code/hypotenuse-good-old-function.cpp`
   :language: c++

Problem: ``std::vector<double>`` Is Not Enough |longrightarrow| Template
------------------------------------------------------------------------

* ``point2d``: members ``x, y`` (and potentially some operations on a
  point, but that is not the point here)
* |longrightarrow| Turn ``hypotenuse()`` into a template
* *Straightforward*
* |longrightarrow| Errors deep down in the implementation

.. literalinclude:: code/hypotenuse-template-no-concept-error.cpp
   :caption: :download:`code/hypotenuse-template-no-concept-error.cpp`
   :language: c++

.. code-block:: console

   error: ‘const class point2d’ has no member named ‘size’
       9 |     for (size_t i=0; i<v.size(); ++i)
         |                        ~~^~~~
   error: no match for ‘operator[]’ (operand types are ‘const point2d’ and ‘size_t’ {aka ‘long unsigned int’})
      10 |         sumsq += v[i]*v[i];
         |                  ~^
   error: no match for ‘operator[]’ (operand types are ‘const point2d’ and ‘size_t’ {aka ‘long unsigned int’})
      10 |         sumsq += v[i]*v[i];
         |                       ~^

Concept: ``has_size``
---------------------

* Implement concept ``has_size``
* Requires that any object of ``V`` has a ``.size()`` method
* |longrightarrow| i.e. the expression ``v.size()`` *compiles*

.. literalinclude:: code/hypotenuse-template-concept-has_size-error.cpp
   :caption: :download:`code/hypotenuse-template-concept-has_size-error.cpp`
   :language: c++

.. code-block:: console

   error: no matching function for call to ‘hypotenuse(point2d&)’
      31 |     std::cout << hypotenuse(p) << std::endl;
         |                  ~~~~~~~~~~^~~
   ... blah ...
   note: constraints not satisfied
   ... blah ...
   required for the satisfaction of ‘has_size<V>’ [with V = point2d]

Fix ``has_size`` Failure In ``point2d``
---------------------------------------

* Fix: add ``point2d::size()`` as required
* Still old-school-complains about ``operator[]``

.. literalinclude:: code/hypotenuse-template-concept-has_size-fixed.cpp
   :caption: :download:`code/hypotenuse-template-concept-has_size-fixed.cpp`
   :language: c++

Problem: What If I Pass Elements That Do Not Support ``*``?
-----------------------------------------------------------

* E.g.: ``std::vector<std::string>``
* Which is nonsense because vector (in its math sense) coordinates
  must be *multipliable*
* |longrightarrow| does not support ``operator*()``

.. literalinclude:: code/hypotenuse-coordinate-not-multipliable-error.cpp
   :caption: :download:`code/hypotenuse-coordinate-not-multipliable-error.cpp`
   :language: c++

.. code-block:: console

   error: no match for ‘operator*’ (operand types are ‘const __gnu_cxx::__alloc_traits<std::allocator<std::pair<int, int> >, std::pair<int, int> >::value_type’ {aka ‘const std::pair<int, int>’} and ‘const __gnu_cxx::__alloc_traits<std::allocator<std::pair<int, int> >, std::pair<int, int> >::value_type’ {aka ‘const std::pair<int, int>’})
      17 |         sumsq += v[i]*v[i];
         |                  ~~~~^~~

Concept: ``coordinate_is_multipliable``
---------------------------------------

* Again, require this explicitly
* |longrightarrow| result of ``operator[]`` must support
  multiplication
* |longrightarrow| this is exactly how the concept looks

.. literalinclude:: code/hypotenuse-coordinate-not-multipliable-concept-error.cpp
   :caption: :download:`code/hypotenuse-coordinate-not-multipliable-concept-error.cpp`
   :language: c++

.. code-block:: console

   note: constraints not satisfied
    In substitution of ‘template<class V> double hypotenuse(const V&) requires (has_size<V>) && (coordinate_is_multipliable<V>) [with V = std::vector<std::pair<int, int> >]’:
      required from here
      required for the satisfaction of ‘coordinate_is_multipliable<V>’ [with V = std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >]
      in requirements with ‘V v’ [with V = std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >]
   note: the required expression ‘(v[0] * v[0])’ is invalid
      13 |     v[0]*v[0];                                         // <-- as a requirement, this must compile
         |     ~~~~^~~

Concept: Require Coordinate Type To Be Double
---------------------------------------------

.. sidebar:: Documentation

   * `std::same_as
     <https://en.cppreference.com/w/cpp/concepts/same_as>`__
   * `Concepts library (since C++20)
     <https://en.cppreference.com/w/cpp/concepts>`__

* Rationale: because I can |:muscle:|
* There is no real reason but to show another syntactical highlight
* ... and some usage of ``<concept>``

.. literalinclude:: code/hypotenuse-coordinate-concept-must-be-double.cpp
   :caption: :download:`code/hypotenuse-coordinate-concept-must-be-double.cpp`
   :language: c++

.. code-block:: console

   note: constraints not satisfied
    In substitution of ‘template<class V> double hypotenuse(const V&) requires  contains_double_likes<V> [with V = std::vector<const char*, std::allocator<const char*> >]’:
      required from here
      required for the satisfaction of ‘contains_double_likes<V>’ [with V = std::vector<const char*, std::allocator<const char*> >]
      in requirements with ‘V v’ [with V = std::vector<const char*, std::allocator<const char*> >]
   note: ‘v[0]’ does not satisfy return-type-requirement
       9 |     { v[0] } -> std::same_as<double>;
         |     ~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
