.. include:: <mmlalias.txt>

.. ot-topic:: cxx03.templates.class_templates
   :dependencies: cxx03.templates.function_templates


Class Templates
===============

Does This Work With Classes?
----------------------------

.. code-block:: c++

   class point
   {
   public:
       point(int x, int y);
       int x() const;
       int y() const;
   private:
       int _x;
       int _y;
   };

**What about other data types?**

* ``point`` with ``int``
* ``point`` with ``float``
* ...

Example: ``point`` as a Class Template (1)
------------------------------------------

.. code-block:: c++

   template <typename T>
   class point
   {
   public:
       point(T x, T y) : _x(x), _y(y) {}
       T x() const;
       T y() const;
   private:
       T _x;
       T _y;
   };

Example: ``point`` as a Class Template (2)
------------------------------------------

.. code-block:: c++

   template <typename T>  // method template parameter
   T                      // method return type
   point<T>::x() const    // class template parameter
   {
       return _x;
   }

Pooh ...

Last Words
----------

* Template classes *must* be defined in the header file
* *Compiler* instantiates code
* *Linker* recognizes duplicates |longrightarrow| unifies
* Rules are very complicated
* |longrightarrow| *Language in the language*
* Compiler error message often very confusing
