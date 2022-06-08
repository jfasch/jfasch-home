.. ot-topic:: cxx03.data_encapsulation.introduction
   :dependencies: cxx03.introduction

.. include:: <mmlalias.txt>


Introduction: Classes and Objects
=================================

.. contents::
   :local:

Objects in C - ``struct``
-------------------------

* Custom "composite" types
* *Copy* is the only operation supported by the language
* Everything else is explicit

.. literalinclude:: code/c++03-struct.c
   :caption: :download:`code/c++03-struct.c`
   :language: c

``struct point`` - Criticism (Is ``struct`` Good Enough?)
---------------------------------------------------------

* Members are public

  .. code-block:: c

     C.x = 666;   // unwanted at times

  * |longrightarrow| Bugs are only a matter of time
  * Counter argument: "Real programmers don't write bugs"

* Function just hang around

  * ``add_points()`` is the *addition operator* which *belongs to*
    ``struct point``
  * Just nobody knows

* Clean/consistent initialization wanted

  * *Contructor* (and *Destructor*)
  * Error checking

* Self defined operators - e.g. addition of ``struct point`` using the
  addition operator "+"
* *Methods* on *Objects*, like moving a point: ``A.move(1,2);``

Introducing C++: ``class point``
--------------------------------

* Constructor: programmable initialization
* Methods: operations on objects
* Operator overloading

.. literalinclude:: code/c++03-class.cpp
   :caption: :download:`code/c++03-class.cpp`
   :language: c++

Access Specifiers: ``public`` And ``private``
---------------------------------------------

.. code-block:: c++

   class point
   {
   public:
       int x() const { return _x; }
   private:
       int _x;
       int _y;
   };

.. list-table::
   :align: left
   :widths: auto

   * * ``public``
     * Public access on object possible
   * * ``private``
     * Only class methods can access
   * * ``protected``
     * Only class methods, and derived classes (|longrightarrow|
       later)

.. code-block:: c++

   point p{1,2};
   p._x;   // <--- error: ‘int point::_x’ is private within this context

.. code-block:: c++

   point p{1,2};
   p.x();   // ok: using public access method

(Default) Constructors, Initializer Lists
-----------------------------------------

.. code-block:: c++

   class point
   {
   public:
       point() : _x(0), _y(0) {}   // default constructor
       point(int x, int y) : _x(x), _y(y) {}
   
       // ...
   };

* *Constructor(s)*: special methods with the same name as the class
* *Default constructor*: no parameters
* |longrightarrow| *user-defined object initialization*

.. code-block:: c++

   point p1{2,4};  // -> point(int x, int y)
   point p2;       // -> point(); default constructor

**Initializer list?**

.. code-block:: c++

   class point
   {
   public:
       point(int x, int y) : _x(x), _y(y) {}
   };

* Members ``_x`` and ``_y`` initialized with respective parameters
* Just like assignment in constructor body
* |longrightarrow| cannot *assign* to ``const`` members though

Method: Operation *On An Object*
--------------------------------

* Methods are functions that are tied to objects
* ... rather than free functions that take objects as parameters

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * C
     * C++
   * * .. code-block:: c

          double distance_from_origin(const struct point* p);

     * .. code-block:: c++

          class point
          {
          public:
              double distance_from_origin() const;
          };
   * * .. code-block:: c

          distance = distance_from_origin(&A);

     * .. code-block:: c++

          distance = A.distance_from_origin();

``const``
---------

* Promise to not modify an object
* Already there in C
* Equivalents in C++

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * C
     * C++
     * What?
   * * .. code-block:: c

          double distance_from_origin(const struct point* p);

     * .. code-block:: c++

          class point
          {
          public:
              double distance_from_origin() const;
          };

     * When called, object is not modified |longrightarrow| verified
       by compiler

   * * .. code-block:: c

          const point p = {2, 3};   // <--- cannot modify!
	  distance = distance_from_origin(&p);

     * .. code-block:: c++

          const point p{2, 3};   // <--- cannot modify!
	  distance = p.distance_from_origin();
	  
     * * C: ``const`` parameter
       * C++: ``const`` method

Operator Overloading
--------------------

* In C, everything is explicit
* When you *mean* vector addition, you say ``move_point()``

  .. code-block:: c
  
     void move_point(struct point* p, int x, int y)
     {
         p->x += x;
         p->y += y;
     }

* In C++, one can *program* operators in custom classes

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * What
     * Definition
     * Usage
   * * operator ``+=`` to move a ``point`` object by ``(2,3)``
     * .. code-block:: c++

          class point
          {
              // ...
              point& operator+=(const point& p)
              {
                  _x += p._x;
                  _y += p._y;
                  return *this;
              }
          };
          
     * .. code-block:: c++

          C += point{2,3};
          // or even ...
	  D = C += point{2,3};

   * * operator ``+`` to create a new point object (and leave the addends
     * .. code-block:: c++

          class point
          {
              // ...
              point operator+(const point& rhs) const
              {
                  return point(_x+rhs._x, _y+rhs._y);
              }
          };

     * .. code-block:: c++

          D = A + B;

And ``printf()``?!
------------------

* Everybody hates it anyway (``"%ld"`` is *not* ``long double``
  |:face_vomiting:|)
* C++ knows more about types
* C++ supports function (and operator) overloading

  * |longrightarrow| Multiple definitions of the same function name,
    only with different parameters

* ``<iostream>``, with ``operator<<()``

**Shift that thing out, man!**

.. code-block:: c++

   std::cout << "D.x: " << D.x() << ", D.y: " << D.y() << std::endl;

