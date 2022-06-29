.. ot-topic:: cxx03.data_encapsulation.ctor_custom
   :dependencies: cxx03.data_encapsulation.classes_objects

.. include:: <mmlalias.txt>


Custom Constructor
==================

.. contents::
   :local:

Constructors: why? (1)
----------------------

**Initialization in C**


* left to the programmer
* |longrightarrow| *sheer number of bugs!*

.. list-table::

   * * .. code-block:: c++

          struct point A;

     * A remains *uninitialized* |longrightarrow| *random* values

   * * .. code-block:: c++

          struct point A = {1,2};

     * ``A`` is initialized with ``x = 1`` and ``y = 2``

   * * .. code-block:: c++

          struct point A;
          ...
          A.x = 1;
          A.y = 2;

     * * *Definition* |longrightarrow| uninitialized
       * Only *set* at some later point |longrightarrow| error prone

Constructors: why? (2)
----------------------

**Initialization in C++**

* Programmer has no choice
* Whenever programmer thinks about a ``point`` object, they *have to*
  think about its value
* |longrightarrow| initialization error excluded from the beginning

.. list-table::

   * * .. code-block:: c++

          point A;

     * Compiler error: "void constructor for point not defined"

   * * .. code-block:: c++

          point A(1,2);

     * Only possibility to create a ``point``

Constructors: Implementation - *Inline*
---------------------------------------

*Short* methods are best defined in the class definition itself
|longrightarrow| *inline*

.. code-block:: c++
   :caption: ``point.h``: *inline* definition

   class point
   {
   public:
       point(int x, int y)
       {
           _x = x;
           _y = y;
       }
   private:
       int _x;
       int _y;
   };

* Better: using an *initializer list* for member initialization
* No difference for non ``const`` members
* Assignment in constructor body not possible for ``const`` members
  |longrightarrow| initializer list necessary

.. code-block:: c++
   :caption: ``point.h``: initializer list

   class point
   {
   public:
       point(int x, int y)
       : _x{x}, _y{y}        // <--- initializer list
       {}                    // <--- empty constructor body
   private:
       const int _x;         // <--- note the "const"
       const int _y;         // <--- note the "const"
   };

Constructors: Implementation - *Out-of-Line*
--------------------------------------------

* *Long* methods are best defined in the implementation file
* (``class point`` constructor is not a long method though ...)

.. list-table::
   :header-rows: 1

   * * ``point.h``: declaration
     * ``point.cpp``: definition
   * * .. code-block:: c++

          class point
          {
          public:
	      point(int x, int y);
	  };

     * .. code-block:: c++

          point::point(int x, int y)    // <--- note the SCOPE:  "point::"
	  : _x{x}, _y{y}
	  {}

