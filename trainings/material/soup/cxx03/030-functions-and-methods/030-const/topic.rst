.. ot-topic:: cxx03.functions_and_methods.const
   :dependencies: cxx03.functions_and_methods.methods

.. include:: <mmlalias.txt>


``const``
=========

.. contents::
   :local:

``const``: Immutable Variable
-----------------------------

**Problem:** 

* What if I have a ``const`` point?
* This is just the same as getting a ``const point*`` passed into a
  function

.. literalinclude:: code/c++03-const-bogus.cpp
   :caption: :download:`code/c++03-const-bogus.cpp`
   :language: c++

(``point-nonconst.h`` :download:`here <code/point-nonconst.h>`)

.. code-block:: console

   code/c++03-const-bogus.cpp:9:38: error: passing ‘const point’ as ‘this’ argument discards qualifiers [-fpermissive]
       9 |     double d_orig = p.distance_origin();
         |                     ~~~~~~~~~~~~~~~~~^~
   code/c++03-const-bogus.cpp:10:40: error: passing ‘const point’ as ‘this’ argument discards qualifiers [-fpermissive]
      10 |     std::cout << "distance of (" << p.x() << ',' << p.y() << ") from origin: "  << d_orig << std::endl;
         |                                     ~~~^~
   code/c++03-const-bogus.cpp:10:56: error: passing ‘const point’ as ‘this’ argument discards qualifiers [-fpermissive]
      10 |     std::cout << "distance of (" << p.x() << ',' << p.y() << ") from origin: "  << d_orig << std::endl;
         |                                                     ~~~^~

.. code-block:: c++

   class point
   {
   public:
       int x() { return _x; }     // <---
       int y() { return _y; }     // <---
   
       double distance_origin()   // <---
       {
           return distance(point{0,0});
       }
   };



``const`` Methods
-----------------

* A ``const`` method *promises* to the compiler that it does not
  modify the object
* Non-``const``: compiler must assume that object is modified
  |longrightarrow| error (see above)

.. literalinclude:: code/point.h
   :caption: :download:`code/point.h`
   :language: c++


``const`` Correctness vs. Pollution
-----------------------------------

* ``const`` pollution

  * "being correct is very cumbersome"
  * not using ``const`` is arrogant ("the compiler cannot help me
    because I am better")

* Nice goodie offered by the language
* Compiler helps me verify that my code is correct
* ``const`` correctness
