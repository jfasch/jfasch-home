.. include:: <mmlalias.txt>


Function Templates
==================

Origin: Duplicated Code
-----------------------

**Overloading**: function ``max`` with different implementations ...

.. code-block:: c++

   int max(int a, int b)
   {
       return (a<b)?b:a;
   }
   float max(float a, float b)
   {
       return (a<b)?b:a;
   }

**Problem**: duplicated code

A simple Function-Template
--------------------------

**Solution**: "code generator" |longrightarrow| Templates

.. code-block:: c++

   template <typename T> T max(T a, T b)
   {
       return (a<b)?b:a;
   }

* Generation recipe
* ``T`` ... *Template parameter*
* Requirement: ``operator<()`` must be valid

More Templates from the STL
---------------------------

**Better:** look into the STL. For example ...

.. code-block:: c++

   #include <algorithm>
   
   float f = std::max(1.2, 1.3);
   int i = std::max(1, 2);
   std::string s = std::max("abc", "abd");
