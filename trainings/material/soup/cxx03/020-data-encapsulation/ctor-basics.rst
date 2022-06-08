.. include:: <mmlalias.txt>

.. ot-topic:: cxx03.data_encapsulation.ctor_basics
   :dependencies: cxx03.data_encapsulation.introduction


Constructor: Basics
===================

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
       // ...
   };

Constructors: Implementation - *Out-of-Line*
--------------------------------------------

*Long* methods are best defined in the implementation file

.. list-table::
   :header-rows: 1

   * * ``point.h``: declaration
     * ``point.cpp``: definition
   * * .. code-block:: c++

          class point
          {
          public:
              point(int x, int y);
	      // ...
	  };

     * .. code-block:: c++

          point::point(int x, int y)
          {
              _x = x;
              _y = y;
          }

