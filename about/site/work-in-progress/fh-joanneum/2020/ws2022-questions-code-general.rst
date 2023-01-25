FH Joanneum (Embedded Computing): WS2022/2023 (Questions About Code)
====================================================================

.. contents::
   :local:

Question 1: C++ Inheritance
---------------------------

Given the following class definitions:

.. literalinclude:: code/base-derived-wo-virtual.h
   :language: c++

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

.. literalinclude:: code/base-derived-w-virtual.h
   :language: c++

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

.. literalinclude:: code/memleak-pointer-in-vector.cpp
   :language: c++

Question 4: ``std::vector``
---------------------------

The following code fragment contains a bug. What is the bug? Describe
it.

.. literalinclude:: code/vector-out-of-range.cpp
   :language: c++


