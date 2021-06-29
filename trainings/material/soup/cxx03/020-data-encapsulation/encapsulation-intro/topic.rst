.. include:: <mmlalias.txt>

.. jf-topic:: cxx03.data_encapsulation.introduction
   :dependencies: cxx03.introduction


Introduction: Classes and Objects
=================================

Objects in C - ``struct``
-------------------------

.. list-table::
   
   * * **Objects in C** - ``struct``

       * Self defined "composite" types
       * *Copy* is supported by the compiler - but nothing else

         * Explicit assignment
         * Parameter passing
         * Function return value

     * .. code-block:: c

          struct point
          {
              int x;
              int y;
          };
          struct point add_points(
              struct point p1,
              struct point p2)
          {
               struct point ret;
               ret.x = p1.x + p2.x;
               ret.y = p1.y + p2.y;
               return ret;
          }

Example: ``struct point``
-------------------------

.. list-table::
   :header-rows: 1

   * * Definition
     * Usage
   * * .. code-block:: c

          struct point
          {
              int x;
              int y;
          };
          struct point add_points(
              struct point rhs,
              struct point lhs);
          void add_to_point(
              struct point *rhs,
              struct point lhs);

     * .. code-block:: c

          struct point A = {1,2}, 
                       B = {2,4};
          struct point C;
          
          C = add_points(A, B);
          add_to_point(&A, B);

``struct point`` - Criticism
----------------------------

**Is ``struct`` good enough?**


* Members are public

  * |longrightarrow| Bugs are only a matter of time
  * Counter argument: "Real programmers don't write bugs"

* Function just hang around
* Clean/consistent initialization wanted

  * *Contructor* (and *Destructor*)
  * Error checking

* Self defined operators - e.g. addition of ``struct point`` using the addition operator "+"
* *Methods* on *Objects*, like moving a point: ``A.move(1,2);``

Example: ``class point``
------------------------

.. list-table::
   :header-rows: 1

   * * Definition
     * Usage

   * * .. code-block:: c++

          class point
          {
          public:
              point(int x, int y);
              int x() const;
              int y() const;
              point& operator+=(
                  point addend);
          private:
              int _x;
              int _y;
          };
          point operator+(
              point lhs, 
              point rhs);

     * .. code-block:: c++

          point A(1,2), B(2,4);
	  // C++11 init syntax: A{1,2}
          
          point C = A + B;
          A += B;

``class point``, analyzed (1)
-----------------------------

**Access Specifier**

.. list-table::
   :header-rows: 1

   * * Definition
     * Usage
   * * .. code-block:: c++

          class point
          {
          private:
              int _x; // the underscore is only 
	              // a stylistic matter
          };

     * *This code won't compile:*

       .. code-block:: c++

	  int x = A._x;
 
* **Compiler error**: "Access to private member ..."
* **Access Specifier**: specifies who can call a method or access a
  member

  * ``public``: access allowed from everywhere
  * ``private``: access only from withni methods of the same class
  * ``protected``: access only from within methods of same or derived
    class (|longrightarrow| *inheritance*)

``class point``, analyzed (2)
-----------------------------

**Access Specifier** and **Access Methods**

.. list-table::
   :header-rows: 1

   * * Definition
     * Usage
   * * .. code-block:: c++

          class point
          {
          public:
              int x() const { return _x; }
          private:
              // ...
          };

     * .. code-block:: c++

          int x = A.x();


* Public Access |longrightarrow| compiler does not complain
* Access Specifier: matter of taste ("Design")

  * Public Member Access: everybody could modify everything
    |longrightarrow| C
  * Access Methods: read-only member access |longrightarrow| *inline*

* ``const``: ``x()`` does not modify the object |longrightarrow|
  *excellent type system*

``class point``, analyzed (3)
-----------------------------

**Constuctors**

.. list-table::
   :header-rows: 1

   * * Definition
     * Usage
   * * .. code-block:: c++

          class point
          {
          public:
              point(int x, int y);
          };

     * .. code-block:: c++

          point A(1,2);

* **Constuctor**: initializes the object
* Here: initialization of the members ``x`` and ``y``
* Multiple constuctors possible

``class point``, analyzed (4)
-----------------------------

**Operators**

.. list-table::
   :header-rows: 1

   * * Definition
     * Usage
   * * .. code-block:: c++

          class point
          {
          public:
              point& operator+=(point addend);
          };

     * .. code-block:: c++

          A += B;
          C = A += B;


* *Operator Overloading*
* ``A += B`` has the value of ``A`` *after assignment*

``class point``, analyzed (5)
-----------------------------

**Operators**

.. list-table::
   :header-rows: 1

   * * Definition
     * Usage
   * * .. code-block:: c++

          class point
          {
              // ...
          };
          point operator+(point lhs, point rhs);

     * .. code-block:: c++

          C = A + B;

* Operator "+=" modifies an object (left hand side) |longrightarrow|
  *member* (defined in class scope)
* Operator "+" creates a new object |longrightarrow| *global* (defined
  in global scope)

Terminology
-----------

**One says:**

.. list-table::

   * * .. code-block:: c++

          class point
          {
              // ...
          };

     * * ``point`` is a type ...
       * ... a *class* of objects

   * * .. code-block:: c++

          point A(1,2), B(3,4);

     * * ``A`` and ``B`` are *instances* of *class* ``point``
       * *Instance* is a synonym for *object*

