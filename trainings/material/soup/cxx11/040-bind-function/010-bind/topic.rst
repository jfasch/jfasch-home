.. ot-topic:: cxx11.functions_functions.bind
   :dependencies: cxx11.smart_pointers.closing_words

.. include:: <mmlalias.txt>


``std::bind``
=============

.. contents::
   :local:

.. sidebar:: 
   
   **Documentation**

   * `std::bind <https://en.cppreference.com/w/cpp/utility/functional/bind>`__

``std::bind``: Why? What's The Problem?
---------------------------------------

Clumsy code like below ...

* One-time functions, only used to do one stupid little thing
  (e.g. define ``double distance_origin(Point p)`` in terms of
  ``double distance(Point p, Point q)``)
* Function definition in places which are far off their call sites
  |longrightarrow| *readability suffers!*

.. literalinclude:: code/c++11-bind-distances-origin-manual.cpp
   :caption: :download:`code/c++11-bind-distances-origin-manual.cpp`
   :language: c++

Sideway: ``std::transform``
---------------------------

.. sidebar::

   **Documentation**

   * `std::transform
     <https://en.cppreference.com/w/cpp/algorithm/transform>`__

* Problem: manual loops to transform an arry (or any container) into
  something else
* Loop body contains transformation code
* |longrightarrow| cries for duplicate code elimination (here: using
  `std::transform
  <https://en.cppreference.com/w/cpp/algorithm/transform>`__
* |longrightarrow| similar pattern across ``<algorithm>`` (see `here
  <https://en.cppreference.com/w/cpp/algorithm>`__)

  * Sorting criteria: ``std::sort``, ``std::map``, ...
  * Predicates: ``std::find_if``, ``std::equal``, ...
  * Arbitrary adaptations where helper functions are needed

Here's a version of the above program that uses ``std::transform`` ...

.. literalinclude:: code/c++11-bind-distances-origin-transform.cpp
   :caption: :download:`code/c++11-bind-distances-origin-transform.cpp`
   :language: c++

``std::bind``: Null Adaptation, Pointlessly
-------------------------------------------

.. literalinclude:: code/c++11-bind-null-adaptation.cpp
   :caption: :download:`code/c++11-bind-null-adaptation.cpp`
   :language: c++

``std::bind``: Adapting One Parameter To No Parameter
-----------------------------------------------------


.. literalinclude:: code/c++11-bind-one-to-zero-adaptation.cpp
   :caption: :download:`code/c++11-bind-one-to-zero-adaptation.cpp`
   :language: c++

``std::bind``: Hardcoding Parameters
------------------------------------

.. literalinclude:: code/c++11-bind-minus-hardcoded.cpp
   :caption: :download:`code/c++11-bind-minus-hardcoded.cpp`
   :language: c++

``std::bind``: Swapping Parameters |longrightarrow| ``std::placeholders``
-------------------------------------------------------------------------

.. literalinclude:: code/c++11-bind-minus-swap-params.cpp
   :caption: :download:`code/c++11-bind-minus-swap-params.cpp`
   :language: c++

``std::bind``: Hardcoding Only First Parameter |longrightarrow| ``std::placeholders``
-------------------------------------------------------------------------------------

.. literalinclude:: code/c++11-bind-minus-hardcode-first.cpp
   :caption: :download:`code/c++11-bind-minus-hardcode-first.cpp`
   :language: c++














Applying ``std::bind`` (1)
--------------------------

**So how does this apply to our ``std::transform`` problem?**

* Readability: we want to eliminate those annoying extra helper functions
* Want to wrap existing ``double distance(Point, Point)`` which is
  similar in purpose but does not fit exactly

**What we have ...**

.. code-block:: c++

   struct Point {...};
   double distance(Point, Point);

**What we want ...**

.. code-block:: c++

   std::transform(swarm, swarm+sizeof(swarm)/sizeof(Point), 
                  distances_point, 
                  SOMETHING WHICH TAKES ONE POINT);

Applying ``std::bind`` (2)
--------------------------

.. code-block:: c++
   :caption: Distances from origin

   std::transform(swarm, swarm+sizeof(swarm)/sizeof(Point), 
                  distances_origin, 
                  std::bind(distance, Point{0,0}, std::placeholders::_1));

.. code-block:: c++
   :caption: Distances from any point

   // this is exactly the same as above

**Summary**

* Readability: what remains unreadable is only the language itself
* Have to get used to ``std::bind``

``std::bind`` vs. Lambda
------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/group`

**Lambdas are usually a better alternative** ...

.. code-block:: c++

   std::transform(swarm, swarm+sizeof(swarm)/sizeof(Point), 
                  distances_origin, 
                  [](Point p) { return distance({0,0}, p); });

.. admonition:: A more advanced exercise

   Use ``std::sort`` to sort an array of points by their distance to a
   given point.

A Bigger Picture: Types
-----------------------

**What about types?**

* Goal is to have *no runtime overhead*
* |longrightarrow| *Late binding (polymorphism)* ruled out
* |longrightarrow| No common base class
* Only the call signatures (parameter and return types) are the same

**What does this mean?**

* Perfect for ``<algorithm>`` which is also designed for speed
* Have to be careful when code size is important
* Client code has to be instantiated with the type
* **Tradeoff**: speed, code size, elegance, design, taste ...
