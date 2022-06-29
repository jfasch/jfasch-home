.. ot-topic:: cxx03.functions_and_methods.overloading
   :dependencies: cxx03.data_encapsulation.classes_objects

.. include:: <mmlalias.txt>


Overloading
===========

.. contents::
   :local:

Functions in C
--------------

**In C, everything is simple**

* A function has a name
* The name is the only thing by which functions are distinguished
* *Not* the return type, nor the paraameters

.. literalinclude:: code/c++03-overloading-c.c
   :caption: :download:`code/c++03-overloading-c.c`
   :language: c++

Compiler complains:

.. code-block:: console

   code/c++03-overloading-c.c:7:6: error: conflicting types for ‘f’; have ‘void(char *)’
       7 | void f(char* s)
         |      ^
   code/c++03-overloading-c.c:3:6: note: previous definition of ‘f’ with type ‘void(int)’
       3 | void f(int i)
         |      ^


Functions in C++ --- Overloading
--------------------------------

.. literalinclude:: code/c++03-overloading.cpp
   :caption: :download:`code/c++03-overloading.cpp`
   :language: c++

.. code-block:: console

   $ code/c++03-overloading 
   void f(int)
   void f(char*)

Underlying Mechanism: *Name Mangling*
-------------------------------------

* Originally, C++ compilers were *frontends* to C
* Generated C code which was then compiled
* Times have changed, but not so much
* |longrightarrow| still compatible with C
* |longrightarrow| C++ and C can be mixed

*How is overloading implemented?*

* Function names are mangled 
* |longrightarrow| contain their parameter types

.. code-block:: console

   $ nm code/c++03-overloading 
   ...
   0000000000401176 T _Z1fi
   00000000004011a0 T _Z1fPc
   ...

.. code-block:: console

   $ nm --demangle code/c++03-overloading 
   ...
   0000000000401176 T f(int)
   00000000004011a0 T f(char*)
   ...

Overloading Class Methods: Just The Same
----------------------------------------

The pointless ``class point`` from
:doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`
has a method ``move(int, int)`` which takes two parameters which
represent the respective ``x`` and ``y`` coordinates by which to move
the point in question:

.. code-block:: c++

   class point
   {
   public:
       // ...

       void move(int x, int y)
       {
           _x += x;
           _y += y;
       }

   };
   

Overloading permits the class to have an alternative method which
takes a single parameter, the *vector* by which to move the point:

.. code-block:: c++

   class point
   {
   public:
       // ...

       void move(point vec)
       {
           _x += vec._x;
           _y += vec._y;
       }

   };
