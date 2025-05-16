.. include:: <mmlalias.txt>


More Constructors, Destructors
==============================

.. contents::
   :local:

Default Constructor (1)
-----------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/new-language-features/oo/default`

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
