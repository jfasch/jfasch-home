.. ot-topic:: cxx03.functions_and_methods.static
   :dependencies: cxx03.functions_and_methods.references

.. include:: <mmlalias.txt>


``static`` Methods
==================

.. contents::
   :local:

Methods without Object
----------------------

**What we know now:**

* Methods are great
* Name and variable |longrightarrow| Method (like ``p.move(1,2)``)
* |longrightarrow| clear writing
* Methods are invoked on *objects* (mostly)

**But:** *global* functions? Methods without an object?

* Not bound to objects
* Same scheme ("method of the class")?

**Example:** add two point objects (|longrightarrow| vector addition)

* Creates a third point object
* Leaves the two addends *unmodified*

Object method?

* Addition is not normally invoked on an addend
* But it belongs to ``class point`` somehow

Naive Implementation: Global Function
-------------------------------------

* In C, one would define such a thing straightforwardly, as a global
  function
* In C, there are no functions other than global

.. literalinclude:: code/global-function.cpp
   :caption: :download:`code/global-function.cpp`
   :language: c++

C++: ``static`` Method
----------------------

* C++ adds another meaning for the ``static`` keyword
* Global function, but ...

  * Not bound to an object (not called like ``p.add(...)``
  * But inside class scope (called like ``point::add(p1, p2)``)

.. literalinclude:: code/static-method.cpp
   :caption: :download:`code/static-method.cpp`
   :language: c++
