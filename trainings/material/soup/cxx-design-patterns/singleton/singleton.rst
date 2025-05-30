.. include:: <mmlalias.txt>


Singleton
=========

.. contents::
   :local:

Description
-----------

* Provide single entry point to global variable
* It *is* a global variable
* Only more engineered

**Drawbacks**

* Hidden dependencies
* Instantiation should be automatic
* ... and this is where the problems arise

Exercises
---------

* :doc:`/trainings/material/soup/cxx-exercises/design-patterns/singleton-flexible`
* :doc:`/trainings/material/soup/cxx-exercises/design-patterns/singleton-flexible-strict`
* :doc:`/trainings/material/soup/cxx-exercises/design-patterns/singleton-inflexible`

And ``class Person``?
.....................

Imagine a system with huge numbers of instances of

.. code-block:: c++

   class Person
   {
   public:
       // ...
       void be_sick();   // <--- charges social insurance. which one?
       // ...
   };

* Do all ``Person`` instance share the same insurance institution?
  Which one?
* How to test such a system? Provide a test case *fixture* to setup
  and teardown the singleton instance?
