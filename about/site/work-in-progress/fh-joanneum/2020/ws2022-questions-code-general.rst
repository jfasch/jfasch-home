FH Joanneum (Embedded Computing): WS2022/2023 (Questions About Code)
====================================================================

.. contents::
   :local:

Question 1: C++ Inheritance
---------------------------

Given the following class definitions:

.. .. literalinclude:: code/base-derived-wo-virtual.h
..    :language: c++

.. code-block:: c++

   class Base
   {
   public:
       const char* method() const
       {
           return "I am an instance of class Base";
       }
   };
   
   class Derived : public Base
   {
   public:
       const char* method() const
       {
           return "I am an instance of class Derived";
       }
   };

What would the following code output?

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Code
     * Output
   * * .. code-block:: c++

          Base b;
          std::cout << b.method() << std::endl;
     * 
   * * .. code-block:: c++

          Derived d;
          std::cout << d.method() << std::endl;
     * 
   * * .. code-block:: c++

          Derived d;
          Base* b = &d;
          std::cout << b->method() << std::endl;
     * 
          
Question 2: C++ Inheritance
---------------------------

Given the following class definitions:

.. .. literalinclude:: code/base-derived-w-virtual.h
..    :language: c++

.. code-block:: c++

   class Base
   {
   public:
       virtual const char* method() const
       {
           return "I am an instance of class Base";
       }
   };
   
   class Derived : public Base
   {
   public:
       virtual const char* method() const
       {
           return "I am an instance of class Derived";
       }
   };

What would the following code output?

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Code
     * Output
   * * .. code-block:: c++

          Base b;
	  std::cout << b.method() << std::endl;
     * 
   * * .. code-block:: c++

          Derived d;
          std::cout << d.method() << std::endl;
     * 
   * * .. code-block:: c++

          Derived d;
          Base* b = &d;
          std::cout << b->method() << std::endl;
     * 

Question 3: Memory Leak
-----------------------

The following code contains a memory leak.

* What constitutes that leak?
* What would be a fix to the problem?

.. .. literalinclude:: code/memleak-pointer-in-vector.cpp
..    :language: c++

.. code-block:: c++

   #include <vector>
   
   class Object
   {
   public:
       Object(int id) : _id(id) {}
       int id() const { return _id; }
   private:
       int _id;
   };
   
   class ObjectContainer
   {
   public:
       void add_object(Object* o) { _container.push_back(o); }
       
   private:
       using _Container = std::vector<Object*>;
       _Container _container;
   };
   
   int main()
   {
       ObjectContainer container;
       Object* o = new Object(666);
       container.add_object(o);
   
       return 0;
   }

Question 4: ``std::vector``
---------------------------

The following code fragment contains a bug. What is the bug? Describe
it.

.. .. literalinclude:: code/vector-out-of-range.cpp
..    :language: c++

.. code-block:: c++

   #include <vector>
   #include <iostream>
   
   int main()
   {
       std::vector<int> my_vector = { 1,2,3 };
       std::cout << my_vector[3] << std::endl;
   
       return 0;
   }
