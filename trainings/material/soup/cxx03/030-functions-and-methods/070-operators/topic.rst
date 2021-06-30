.. include:: <mmlalias.txt>

.. jf-topic:: cxx03.functions_and_methods.operators
   :dependencies: cxx03.functions_and_methods.static


Operator Overloading
====================

Motivation
----------

**Operators (+, +=, ->) etc. in C**

* Only available for simple data types (``int``, ``float``, pointer arithmetic, ...)
* |longrightarrow| *defined by the language*

**Problem**: we want more ...

* Arithmetic operators for ``class point``?
* Intelligent pointers which have a different definition of ``->``?
* ... unbounded fantasy here ...

Operators, Functions, and Methods
---------------------------------

**Why shouldn't this be possible?** Operators, after all, are
functions that are implemented by the compiler.

* ``i += 42``. Method "``+=``" on object of type ``int``, with parameter ``int``
* ``i = j + 42`. *Static* method "``+``". Two parameters (type ``int``), return type ``int``
* ``p += point(1,2)``. Define as you like!
* ``str += "hallo!"``. Someone else did this already ...

  * ``std::string``
  * *C++ Standard Library*

Example: Operator ``+=`` *on the Object* (1)
--------------------------------------------

.. list-table::
   :header-rows: 1

   * * Definition
     * Usage
   * * .. code-block:: c++

          class point
          {
          public:
              point& operator+=(const point &addend)
              {
                  _x += addend._x;
                  _y += addend._y;
                  return *this;
              }
          private:
              int _x;
              int _y;
          };

     * .. code-block:: c++

          point a(1,2), b(2,3);
	  a += b;

Example: Operator ``+=`` *on the Object* (2)
--------------------------------------------

.. list-table::

   * * .. code-block:: c++

          operator+=(const point &addend)

     * * ``this``: left hand side of ``p1 += p2``
       * ``addend``: right hand side of ``p1 += p2``

   * * .. code-block:: c++

          point& operator+=(...)

     * ``p3 = p2 += p1;``

   * * .. code-block:: c++

          return *this;

     * * Value of the expression ``p1 += p2`` is ``p1``
       * |longrightarrow| use ``p1`` onwards

Example: Operator ``+`` *not* on the Object (1)
-----------------------------------------------

.. code-block:: c++

   class point
   {
   public:
       int x() const { return _x; }
       int y() const { return _y; }
   };
   
   point operator+(const point &l, const point &r)
   {
       return point(l.x()+r.x(), l.y()+r.y());
   }

Example: Operator ``+`` *not* on the Object (2)
-----------------------------------------------

.. list-table::

   * * .. code-block:: c++

          operator+(const point &l, const point &r)

     * * No object |longrightarrow| no ``this``
       * Two real parameters

   * * .. code-block:: c++

          point operator+(...)

     * * "+" creates *new* object
       * |longrightarrow| return by *copy*

   * * .. code-block:: c++

          l.x()+r.x() ...

     * * Global function |longrightarrow| ``private`` not visible
       * ``friend`` - not a solution

Example: Function Objects - *Functors* (1)
------------------------------------------

**Function Call Operator** "``()``": for example ...

* Class *without* comparison operator


.. code-block:: c++

   class Item
   {
   public:
       Item(int dies, int das)
       : _dies(dies), _das(das) {}
   
       int dies() const { return _dies; }
       int das() const { return _das; }
   
   private:
       int _dies, _das;
   };

Example: Function Objects - *Functors* (2)
------------------------------------------

**Problem**: one wants to sort |longrightarrow| comparison operator
 needed

.. code-block:: c++

   bool operator<(const Item &lhs, const Item &rhs)
   {
       if (lhs.dies() < rhs.dies())
           return true;
       if (lhs.dies() > rhs.das())
           return false;
       return lhs.das() < rhs.das();
   }

**Problem**: he's *global*

* |longrightarrow| Ambiguity!
* Not everybody agrees

Example: Function Objects - *Functors* (3)
------------------------------------------

**Solution**:
  
* Functors that everybody can tailor to their use
* *Function Call Operator*

.. list-table::
   :header-rows: 1

   * * Definition
     * Usage
   * * .. code-block:: c++

          class LessOp
          {
          public:
              bool operator()(const Item &lhs, const Item &rhs) const
              {
                  // same as operator<(lhs, rhs)
              }
          };

     * .. code-block:: c++

          LessOp less;
          if (less(item1, item2))
              ...

* Container classes
* Algorithms
