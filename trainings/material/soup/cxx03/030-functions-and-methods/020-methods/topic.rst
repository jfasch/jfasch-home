.. ot-topic:: cxx03.functions_and_methods.methods
   :dependencies: cxx03.functions_and_methods.overloading

.. include:: <mmlalias.txt>


Methods
=======

.. contents::
   :local:

Objects - Data and Methods
--------------------------

**C**

* Object |DoubleLeftRightArrow| ``struct``
* Operations on objects: *free functions*
* |longrightarrow| can be defined anywhere

  .. code-block:: c

     struct point p = {1,2};
     point_move(&p, 3, 4); // <--- not syntactically *bound* to p

**C++**

* Classes: data and *methods*
* Methods: functions *bound* to objects

  .. code-block:: c++

     point p{1,2};
     p.move(3,4);

``class point`` Again
---------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`

Reiterating ``class point`` from
:doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`:

* What is a point? |longrightarrow| ``x`` and ``y``
* What is the responsibility of a point?

  * contain ``x`` and ``y``
  * move itself
  * compute its distance to origin
  * ... or from another point ...

Access Methods ("Getters") **WRONG**
------------------------------------

* Members are private |longrightarrow| outside access prohibited
* Read-only access desired, though
* |longrightarrow| Public access methods

  .. literalinclude:: code/accessors-nonconst/point.h
     :caption: :download:`point.h <code/accessors-nonconst/point.h>`
     :language: c++

* Getting ``x`` and ``y`` values: call getters

  .. literalinclude:: code/accessors-nonconst/main-ok.cpp
     :caption: :download:`main-ok.cpp
               <code/accessors-nonconst/main-ok.cpp>`
     :language: c++

Access Methods ("Getters"): ``const`` Objects
---------------------------------------------

* ``const`` objects: must not be changed
* |longrightarrow| guarantee, enforced by the compiler

.. literalinclude:: code/accessors-nonconst/main-error.cpp
   :caption: :download:`main-error.cpp
             <code/accessors-nonconst/main-error.cpp>`
   :language: c++

.. code-block:: console

   .../main-error.cpp:8:28: error: passing ‘const point’ as ‘this’ argument discards qualifiers [-fpermissive]
       8 |     std::cout << '(' << p.x() << ',' << p.y() << ")\n";
         |                         ~~~^~
   
Access Methods ("Getters"): ``const`` Methods
---------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/040-this/topic`

* ``const`` objects can only be accessed with ``const`` method
* |longrightarrow| leave the object itself (``this``) unchanged

.. literalinclude:: code/accessors-const/point.h
   :caption: :download:`point.h <code/accessors-const/point.h>`
   :language: c++

Modifying Method (``p.move(...)``)
----------------------------------

* "Point, move yourself by ``x`` and ``y``"
* Usage ...

.. literalinclude:: code/move-x-y/main.cpp
   :caption: :download:`main.cpp <code/move-x-y/main.cpp>`
   :language: c++

* Implementation (inline)

.. literalinclude:: code/move-x-y/point.h
   :caption: :download:`point.h <code/move-x-y/point.h>`
   :language: c++

Non-Inline Implementation
-------------------------

* Implementation in header file is *inline*
* |longrightarrow| code inserted at call site
* |longrightarrow| large binary size (not for ``move(x,y)``, but sure
  for larger methods)

.. literalinclude:: code/move-x-y-non-inline/point.h
   :caption: :download:`point.h <code/move-x-y-non-inline/point.h>`
   :language: c++

.. literalinclude:: code/move-x-y-non-inline/point.cpp
   :caption: :download:`point.h <code/move-x-y-non-inline/point.cpp>`
   :language: c++

Overloading ``move()`` |longrightarrow| Vector Addition
-------------------------------------------------------

* Why not use a ``point`` instance as a vector?
* |longrightarrow| ``move(point vec)``

.. literalinclude:: code/move-vector/point.h
   :caption: :download:`point.h <code/move-vector/point.h>`
   :language: c++

Moving ``const point`` Objects?
-------------------------------

.. literalinclude:: code/move-const-object/main-error.cpp
   :caption: :download:`main.cpp <code/move-const-object/main-error.cpp>`
   :language: c++

.. code-block:: console

   .../main-error.cpp:8:11: error: passing ‘const point’ as ‘this’ argument discards qualifiers [-fpermissive]
       8 |     p.move(vec);
         |     ~~~~~~^~~~~

* As above (accessors): cannot call non-``const`` method on ``const``
  object

.. literalinclude:: code/move-const-object/main-ok.cpp
   :caption: :download:`main.cpp <code/move-const-object/main-ok.cpp>`
   :language: c++

Finally: ``point::distance()``
------------------------------

What we want ...

* distance from another point
* distance from origin
* |longrightarrow| overload
* |longrightarrow| ``const`` method (though Heisenberg says we always
  modify through measurement)

.. literalinclude:: code/distance/main.cpp
   :caption: :download:`main.cpp <code/distance/main.cpp>`
   :language: c++

.. literalinclude:: code/distance/point.h
   :caption: :download:`main.cpp <code/distance/point.h>`
   :language: c++


``const`` Correctness vs. Pollution
-----------------------------------

* ``const`` *pollution*

  * "being correct is very cumbersome"
  * not using ``const`` is arrogant ("the compiler cannot help me
    because I am better")

* Nice goodie offered by the language
* Compiler helps me verify that my code is correct
* ``const`` *correctness*
