.. include:: <mmlalias.txt>

.. jf-topic:: cxx03.data_encapsulation.ctor_dtor
   :dependencies: cxx03.data_encapsulation.introduction


Constructors and Destructors
============================

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

Constructors: Initializer List (1)
----------------------------------

**What about ``const`` members?**

.. list-table::

   * * .. code-block:: c++

          class point
          {
          public:
              point(int x, int y)
              {
                  _x = x;
                  _y = y;
              }
          private:
              const int _x;
              const int _y;
          };

     * * Compiler error

         * "``const`` members ``x`` und ``y`` not initialized"
	 * "Assignment to ``const`` member"

       * Constructor body is *normal* Code
       * ``const`` pollution?
       * |longrightarrow| **No!**

Constructors: *Initializer List* (2)
------------------------------------

**Initializer List**: different form of assignment - *Initialization*

.. code-block:: c++

   class point
   {
   public:
       point(int x, int y) : _x(x), _y(y) {}
   private:
       const int _x;
       const int _y;
   };

Default Constructor (1)
-----------------------

**Constructor without parameter** - *Default Constructor*

.. code-block:: c++

   class point
   {
   public:
       point() : _x(0), _y(0) {}
       point(int x, int y) : _x(x), _y(y) {}
   };
   
   ...
   
   point p; // -> (0, 0), implicitly

Default Constructor (2)
-----------------------

.. list-table::

   * * .. code-block:: c++
          
          class rectangle
          {
              point nw;
              point se;
          };

     * * Compiler *generates* default constructor
       * ... but only when none is defined explicitly

Does this "design" make sense?

* Always ask whether a default constructor makes sense
* Here: rectangle ``((0,0),(0,0))`` |longrightarrow| nonsense
* If one wants a real ctor *and* a default ctor |longrightarrow|
  define one explicitly

Object Lifecycle - Destructor
-----------------------------

**Like in C.** Well almost. The end of an object is ...
  
* Scope: end of block
* ``return`` from function |longrightarrow| end for *local* objects
* Explicit lifetime (dynamic memory): ``delete`` operator
* Static (global) lifetime: program termination

**In any case**: as soon as life is over, the *destructor* is called

* Implicitly defined (compiler generated)

  * |longrightarrow| memberwise destruction

* Explicitly defined

Destructors (1)
---------------

**What happens when life is over?**

.. code-block:: c++

   class String
   {
   public:
       String(const char *from)
         : _c_str(new char[strlen(from)+1])
       {
           strcpy(_c_str, from);
       }
   private:
       char *_c_str;
   };

Destructors (2)
---------------

**Implementation detail** of ``String``:

* *Heap-allocated* memory
* ``String`` is only as big as all of its members
* |longrightarrow| ``sizeof(char *)`` (4 or 8 bytes)
* *Data are on the heap* |longrightarrow| compiler cannot help
* |longrightarrow| variable length

Destructors (3)
---------------

.. list-table::

   * * .. code-block:: c++

          void f()
          {
              String s("hello");
              ...
              // LEAKED 6 bytes!
          }

     * 

       .. image:: 02-01-00-dtor-dyn-memory.dia

Destructors (4)
---------------

**Solution**: program a destructor

.. code-block:: c++

   class String
   {
   public:
       ~String()
       {
           delete[] _c_str;
       }
   };

* Not only with dynamically allocated memory
* ... but with all kinds of explicit resource allocation (e.g. file
  descriptors)
* More details for ``new`` and ``delete`` |longrightarrow| later
