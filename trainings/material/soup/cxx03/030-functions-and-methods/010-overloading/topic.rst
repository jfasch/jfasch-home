.. include:: <mmlalias.txt>

.. jf-topic:: cxx03.functions_and_methods.overloading
   :dependencies: cxx03.data_encapsulation.object_copy


Overloading
===========

Functions in C
--------------

**In C, everything is simple**

* A function has a name
* The name is the only thing by which functions are distinguished
* *Not* the return type, nor the paraameters

.. code-block:: c++
   :caption: Declaration of ``x``

   int x(int i);

.. code-block:: c++
   :caption: Ok

   int ret = x(42);

.. code-block:: c++
   :caption: 2x Error

   char *ret = x("huh?");

.. code-block:: c++
   :caption: Error: ``x`` declared twice

   char *x(char* str);

Functions in C++ --- Overloading
--------------------------------

**C++: better**

.. code-block:: c++
   :caption: *Two* declarations of ``x``

   int x(int i);
   char *x(const char *str);
  
.. code-block:: c++
   :caption: Ok

   int ret = x(42);

.. code-block:: c++
   :caption: Ok

   char *ret = x("huh?");

.. code-block:: c++
   :caption: Error: no appropriate ``x`` found

   char *ret = x(42);
