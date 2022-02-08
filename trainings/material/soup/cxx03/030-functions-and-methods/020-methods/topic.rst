.. include:: <mmlalias.txt>

.. ot-topic:: cxx03.functions_and_methods.methods
   :dependencies: cxx03.functions_and_methods.overloading


Methods
=======

Objects - Data and Methods
--------------------------

**C**

* Object |DoubleLeftRightArrow| ``struct``
* Operations on objects: *free functions*
* |longrightarrow| can be defined anywhere

**C++**

* Classes: data and *methods*
* Methods: functions *bound* to objects

Method - Example ``point`` (1)
------------------------------

* What is a point? |longrightarrow| ``x`` and ``y``
* What is the responsibility of a point?

  * move itself
  * compute its distance to origin
  * ... or from another point ...

.. code-block:: c++

   class point
   {
   public:
       void move(int x, int y)
       {
	   this->x += x;
	   this->y += y;
       }
       float distance_origin() const;
       float distance(const point&) const;
   };

Method - Example ``point`` (2)
------------------------------

* ``point`` offers functionality
* ``point`` should be used *as simply and clearly as possible!*

.. code-block:: c++

   point p(2, 0);
   p.move(1, 0);
   if (fabs(p.distance_origin() - 3.0) > 0.0001)
       std::cerr << "FPU bogus?" << std::endl;

Methods and Design
------------------

**Question: what should a point be able to?** 

Difficult to answer ...

* Should it offer its coordinates?

  * I think so |longrightarrow| small ``inline`` access methods

* Should it offer two dimensional arithmetic methods?

  * Why not? This is what a point is there for.

* Should it be able to print a plot of itself?

  * Why not? As long as users of a point are willing to link 28 more
    libraries.
  * |longrightarrow| *Coupling*

Methods: Wrap-Up
----------------

**Many but simple (?) Nuances ...**

* ``const``: type system
* References: performance
* ``static``, with yet another meaning of the keyword
