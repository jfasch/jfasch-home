.. ot-topic:: cxx03.functions_and_methods.methods
   :dependencies: cxx03.functions_and_methods.overloading

.. include:: <mmlalias.txt>


Methods
=======

.. contents::
   :local:

Objects - Data and Methods
--------------------------

**C**

* Object |DoubleLeftRightArrow| ``struct``
* Operations on objects: *free functions*
* |longrightarrow| can be defined anywhere

  .. code-block:: c

     struct point p = {1,2};
     point_move(&p, 3, 4); // <--- not syntactically *bound* to p

**C++**

* Classes: data and *methods*
* Methods: functions *bound* to objects

  .. code-block:: c++

     point p{1,2};
     p.move(3,4);

``class point`` Again
---------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`

Reiterating ``class point`` from
:doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`:

* What is a point? |longrightarrow| ``x`` and ``y``
* What is the responsibility of a point?

  * move itself
  * compute its distance to origin
  * ... or from another point ...

.. literalinclude:: code/point.h
   :caption: :download:`code/point.h`
   :language: c++

Simple Methods: Access Methods ("Getters")
------------------------------------------

* Members are private |longrightarrow| outside access prohibited
* Read-only access desired, though
* |longrightarrow| Public access methods

.. code-block:: c++

   class point
   {
   public:
       int x() const { return _x; }
       int y() const { return _y; }
   private:
       int _x;
       int _y;
   };

* ``const``: read-only access does not alter the object

  .. code-block:: c++

     const point p{1,2};
     int x = p.x();       // <--- x() is *const* => ok

How Are Members Accessed Inside Methods?
----------------------------------------

.. sidebar::

   **See also**

   * :doc:`../040-this/topic`

* Method is a *function* that is defined inside the class definition
* |longrightarrow| C++ *knows* that an object is involved
* ``_x`` in method body means: "the ``_x`` of the object"
* Accessed via the hidded ``this`` pointer (see
  :doc:`../040-this/topic`)

``const`` Methods
-----------------

.. sidebar::

   **See also**

   * :doc:`../030-const/topic`

* Getters above are ``const`` but trivial
* Even non-trivial methods can be ``const``
* |longrightarrow| whenever a method does not modify a member, it
  should be written as ``const``

.. code-block:: c++

   class point
   {
   public:
       double abs() const
       {
           int hyp = _x*_x + _y*_y;  // <--- read-only member access -> const
           return sqrt(hyp);
       }
   };

Non ``const`` Methods
---------------------

* Moving a point obviously must modify its coordinates
* |longrightarrow| cannot be ``const``

.. code-block:: c++

   class point
   {
   public:
       void move(int x, int y)
       {
           _x += x;
           _y += y;
       }
   };

* Non ``const`` methods cannot be called on objects that are ``const``
* |longrightarrow| that is the deal, after all

.. code-block:: c++

   const point p{1,2};
   p.move(3,4);         // <--- ERROR: passing ‘const point’ as ‘this’ argument discards qualifiers

* Error message is a little "C++ standardese"
