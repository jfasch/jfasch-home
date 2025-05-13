.. include:: <mmlalias.txt>


Constructors: Member Initialization
===================================

.. contents::
   :local:

Member Initialization? Assignment?
----------------------------------

* *Initialization* is different from *assignment*
* Sometimes objects may not be left uninitialized
* Sometimes objects/classes might not have a default constructor

.. code-block:: c++

   class point
   {
   public:
       point(int x, int y)
       {
                                       // <--- space allocated for _x and _y, but value undefined
           _x = x;                     // <--- assignment
           _y = y;                     // <--- assignment
       }
   private:
       int _x;
       int _y;
   };

Real Initialization: Initializer List
-------------------------------------

* Not necessary with ``class point``
* |longrightarrow| Members have defined value after constructor has
  run (which is sufficient)
* Good style though: use *initializer list*

.. code-block:: c++

   class point
   {
   public:
       point(int x, int y)
       : _x(x), _y(y)                  // <--- real initialization
       {}                              // <--- body can be left empty
   private:
       int _x;
       int _y;
   };

Why Is That Important?
----------------------

* Hypothetical design decision ...

  * ``point`` objects can only be initialized
  * Cannot be modified afterwards

.. code-block:: c++

   class point
   {
   public:
       point(int x, int y)
       {
           _x = x;                        // <--- error: assignment of read-only member ‘point::_x’
           _y = y;                        // <--- error: assignment of read-only member ‘point::_y’
       }
   private:
       const int _x;                      // <--- const!
       const int _y;                      // <--- const!
   };

Why Else Is That Important?
---------------------------

* Members might not have a default constructor
* |longrightarrow| *Cannot* be left uninitialized - not even for a
  short time period
