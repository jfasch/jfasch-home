.. include:: <mmlalias.txt>


Classes and Objects
===================

.. contents::
   :local:

.. sidebar::

   **Trainer's Note**

   * Download :download:`code/c-point.c`
   * Morph it into C++

Introducing C++: ``class point``
--------------------------------

Following a complete C++ re-implementation of the ``struct point``
story that we :doc:`saw earlier <c>`.

It has:

* *Constructors*: programmable initialization
* *Methods*: operations on objects
* *Operators*

.. literalinclude:: code/point.h
   :caption: :download:`code/point.h`
   :language: c++

Access Specifiers: ``public`` And ``private``
---------------------------------------------

.. code-block:: c++

   class point
   {
   public:
       int x() const { return _x; }  // permit read-only access to _x
       int y() const { return _y; }  // permit read-only access to _y
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

Default Constructor
-------------------

* C does not help with initialization
* |longrightarrow| leaves things uninitialized *if not explicitly
  initialized*

  .. code-block:: c++
  
     struct point p;  // <--- uninitialized!!

* C++: *default constructor*

  .. code-block:: c++
  
     point p;         // <--- default constructor invoked

**Default constructor implementation: pre C++11**

* Initializer list used to set members to their defaults

.. code-block:: c++

   class point
   {
   public:
       point() : _x{0}, _y{0} {}    // <--- initializer list
   private:
       int _x;
       int _y;
   };

**Default constructor implementation: since C++11**

* Member default initialization right in class
* ``= default``

.. code-block:: c++

   class point
   {
   public:
       point() = default;   // <--- use default values from member definitions
   private:
       int _x{};            // <--- _x defaults to 0
       int _y{};            // <--- _y defaults to 0
   };

.. code-block:: c++

   point p1{2,4};  // -> point(int x, int y)
   point p2;       // -> point(); default constructor

Custom Constructor: Usage
-------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx/cxx11/brace-initialization/index`

* User defined initialization
* Programmer responsible for parameter signature

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * C++ usage
     * C "usage"
   * * .. literalinclude:: code/cpp-constructor-coordinates.cpp
          :caption: :download:`code/cpp-constructor-coordinates.cpp`
	  :language: c++
     * .. literalinclude:: code/c-constructor.cpp
          :caption: :download:`code/c-constructor.cpp`
	  :language: c++

Custom Constructor: Implementation
----------------------------------

**Initializer list?**

.. code-block:: c++

   class point
   {
   public:
       point(int x, int y)
        : _x{x}, _y{y}           // <--- initializer list
	{}                       // <--- constructor body (here: empty)
   };

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/020-methods/topic`

* Members ``_x`` and ``_y`` initialized with respective parameters
* Just like assignment in constructor body
* |longrightarrow| cannot *assign* to ``const`` members though

Access Methods For Otherwise Private Members
--------------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/020-methods/topic`

* Members in ``private:`` section inaccessibile from outside class
  definition
* Read access desired though
* |longrightarrow| *access methods*
* |longrightarrow| note the ``const``: *promise* that a call won't
  alter the object

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

Methods: Operations *On An Object*
----------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/020-methods/topic`

* Methods are functions that are tied to objects
* ... rather than free functions that take objects as parameters
* Note the ``const`` again

  * C++: ``const`` method
  * C: ``const`` object pointer

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * C++
     * C
   * * .. code-block:: c++
          :caption: Implementation

          class point
          {
          public:
              double abs() const
              {
                  int hyp = _x*_x + _y*_y;
                  return sqrt(hyp);
              }
          private:
              int _x{};
              int _y{};
          };

       .. literalinclude:: code/cpp-abs.cpp
          :caption: Usage
	  :language: c++

     * .. literalinclude:: code/c-abs.cpp
          :caption: Usage
	  :language: c++

Operator Overloading
--------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/070-operators/topic`

* In C, everything is explicit
* When you *mean* vector addition, you say ``point_move()``
* In C++, you say ``+=``

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * C++
     * C
   * * .. code-block:: c++
          :caption: Implementation

          class point
          {
          public:
              point& operator+=(point vec)
              {
                  _x += vec._x;
                  _y += vec._y; 
                  return *this;
              }
          };

       .. literalinclude:: code/cpp-move-op-pluseq.cpp
          :caption: Usage
	  :language: c++

     * .. literalinclude:: code/c-move.cpp
          :caption: Usage
	  :language: c

And ``printf()``?!
------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/070-operators/topic`

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

