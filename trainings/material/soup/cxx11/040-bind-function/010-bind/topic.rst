.. include:: <mmlalias.txt>

.. jf-topic:: cxx11.functions_functions.bind
   :dependencies: cxx11.smart_pointers.closing_words


``std::bind``
=============

``std::bind``: Why?
-------------------

**Why?** What's the problem?

**Answer:**

* Hard to explain
* Best to see the problem first
* Let's start small, by simple example

**Problem: we have ...**

* Two dimensional points ``(x,y)``
* A function to compute the distance between two points

**We want:**

* A function to compute the distance from *origin* ``(0,0)``

What We Have
------------

.. code-block:: c++
   :caption: ``Point``

   struct Point
   {
       Point(double x, double y)
         : x(x), y(y) {}
       double x, y;
   };

.. code-block:: c++
   :caption: Distance

   double distance(Point p, Point q)
   {
       return std::sqrt(
           std::pow(std::abs(p.x-q.x), 2) + 
           std::pow(std::abs(p.y-q.y), 2)
       );
   }

Retro C/C++
-----------

* We have all that is needed
* Could easily define a small function
* |longrightarrow| Problem solved
* *But this would be soo retro!*

.. code-block:: c++
   :caption: Distance from Origin

   double distance_origin(Point p)
   {
       return distance(p, {0,0});
   }

The Real Problem
----------------

**Nothing is wrong with small functions**

* Compiler will inline them

  * ... and optimize away entirely

* Defined centrally (public header file?) for further reuse


**But...**

* What if they serve *only one* purpose?

.. admonition:: Sample Problem

   Compute the origin-distances of an array of points, and store
   those in an equally sized array of ``double``!

Straightforward Implementation
------------------------------

Near the top of the implementation file ...

.. code-block:: c++
   :caption: One-Time Function Definition

   static double distance_origin(Point p) {
       return distance(p, {0,0});
   }

And *far down below*, in the implementation section ...
  
.. code-block:: c++
   :caption: Location of use

   double distances_origin[sizeof(swarm)/sizeof(Point)];
   std::transform(swarm, swarm+sizeof(swarm)/sizeof(Point), 
                  distances_origin, 
		  distance_origin);

More Sample Problems
--------------------

.. admonition:: Another Sample Problem

   Compute the distances of an array of points from a given point, and
   store those in an equally sized array of ``double``!

*Possible solutions*: as many as there are different tastes around ...
  
* Lets write another stupid function, basically a copy of
  ``distance_origin`` - only with ``(1,1)`` instead of
  ``(0,0)``
* Even better: lets generalize! *Functors!* *Function call operator!*

More Straightforward Implementations
------------------------------------

.. code-block:: c++
   :caption: One-Time Functor Definition

   struct distance_point {
       distance_point(Point origin) : origin(origin) {}
       double operator()(Point p) const {
           return distance(p, origin);
       }
       Point origin;
   };

.. code-block:: c++
   :caption: Location of use

   double distances_origin[sizeof(swarm)/sizeof(Point)];
   std::transform(swarm, swarm+sizeof(swarm)/sizeof(Point), 
                  distances_point, 
                  distance_point({1,1}));

Readability
-----------

*Provided that the helper code is only used once ...*

* *Readability* is inversely proportional to amount of code
* *Number of bugs* is directly proportional to amount of code
* Helper implementation is nowhere near location of use
* ``static`` is the only keyword that enhances readability

*Similar problem with many data structures and algorithms ...*

* Sorting criteria: ``std::sort``, ``std::map``, ...
* Predicates: ``std::find_if``, ``std::equal``, ...
* Arbitrary adaptations where helper functions are needed

  * Most prominent (although relatively useless nowadays):
    ``std::for_each``

Introducing ``std::bind`` (1)
-----------------------------

*Best done by example ...*

.. code-block:: c++

   void f(int a, int b)
   {
       std::cout << a << ',' << b << std::endl;
   }

.. list-table::
   :align: left

   * * .. code-block:: c++
          :caption: Direct function call

	  f(1, 2);

     * .. code-block:: console
          :caption: prints ...

	  1,2

**What if** we need the functionality of ``f(a, b)``, but are required
to pass a *callable* that takes no parameters?

Introducing ``std::bind`` (2)
-----------------------------

**In other words**, we need to create a function-like object that
wraps ``f(a,b)`` that always calls ``f`` with, say, ``a=1`` and
``b=2``.

.. list-table:: 
   :align: left

   * * **Hardcoded parameters**

       .. code-block:: c++

          auto bound = std::bind(f, 1, 2);
          bound();

     * .. code-block:: console
          :caption: prints ...

	  1,2

* Alternative: manually write function adaptor (functor) that
  remembers parameters until called
* Origin: `Boost (www.boost.org) <https://www.boost.org>`__

Introducing ``std::bind`` (3)
-----------------------------

**Routing parameters into arbitrary positions:** ``std::placeholders``

.. list-table::
   :align: left

   * * **Hardcoding only second parameter**

       .. code-block:: c++

	  auto bound = std::bind(f, 42, std::placeholders::_1);
	  bound(7);

     * .. code-block:: console
          :caption: prints ...

	  42,7

.. list-table::
   :align: left

   * * **Exchanging parameters**

       .. code-block:: c++

          auto bound = std::bind(f, 
                 std::placeholders::_2, 
                 std::placeholders::_1);
          bound(1,2);

     * .. code-block:: console
          :caption: prints ...

	  2,1

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
