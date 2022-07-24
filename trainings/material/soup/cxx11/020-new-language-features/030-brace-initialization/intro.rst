.. ot-topic:: cxx11.new_language_features.brace_initialization.intro
   :dependencies: cxx11.new_language_features.auto

.. include:: <mmlalias.txt>


Brace Initialization: Introduction
==================================

.. contents::
   :local:

Motivation: Inconsistent Initialization Styles
----------------------------------------------

**Initialization was always inconsistent** |longrightarrow| Extremely
confusing, especially for newbies!

* Integral types
* Aggregates (struct, array)
* Class objects
* Container (e.g. ``std::vector``) initialization with contained
  values |longrightarrow| ``push_back()`` orgies

Motivation: Integral Types Initialization
-----------------------------------------

.. list-table::
   :align: left

   * * **Integral Types**

       * Two different kinds of initialization
       * A matter of history
       * Initialization and assignment are different
       * Constructor style necessary in templates |longrightarrow|
         integers have to behave as if they were objects

     * **Integer Initialization**

       .. code-block:: c++

          int x = 7; // assignment style
          int y(42); // ctor style

Motivation: Aggregate Initialization
------------------------------------

.. list-table::
   :align: left

   * * **Aggregates**

       * Initialization goes like it used to go in good old C
       * No constructor style

     * **Aggregate Initialization**

       .. code-block:: c++

          int arr[] = {1, 2, 3};
          
          struct s { int i,j; }
          s s1 = {1, 2};
          s s2 = {1}; // s2.j==0

Motivation: Object Initialization/Constructor
---------------------------------------------

.. list-table:: 
   :align: left

   * * **Objects**

       * Constructor: looks like function call
       * Copy initialization
      
     * **Object Initialization**

       .. code-block:: c++

          class C {
          public:
            C(int i, int j);
          };
          
          C c1(1,2);
          C c2 = c1;

Motivation: Container Initialization (Missing Pre C++11)
--------------------------------------------------------

.. list-table::
   :align: left

   * * **Containers**

       * Filling containers is extremely cumbersome |longrightarrow| ``.push_back()``
       * *Initialization* requires an existing container
         |longrightarrow| *very very loud*

     * **Container Initialization**

       .. code-block:: c++

          int arr[] = {1,2,3};
          vector<int> v1(arr, arr+3);
          vector<int> v2(v1.cbegin(), v1.cend());
          
          set<int> s;
          s.insert(1);
          s.insert(2);
          vector<int> v(s.cbegin(), s.cend());

Motivation: Member Array Initialization
---------------------------------------

.. list-table:: 
   :align: left

   * * **Member Arrays**

       * *Cannot* be initialized
       * Must be filled in constructor body
       * |longrightarrow| inconsistent
       * |longrightarrow| loud
       * |longrightarrow| workarounds

     * **Member Array Initialization**

       .. code-block:: c++

          class C {
          public:
            C() : data_(/*dammit!*/) {}
          private:
            const int data_[3];
          };

Motivation: Heap Array Initialization
-------------------------------------

.. list-table::
   :align: left

   * * **Arrays on the Heap**

       * *Cannot* be initialized
       * |longrightarrow| inconsistent
       * |longrightarrow| loud
       * |longrightarrow| workarounds

     * **Heap Array Initialization**

       .. code-block:: c++

          const int *arr = new int[42];
	  // and now?

Solution: Brace Initialization In C++11
---------------------------------------

**Solution: brace initialization everywhere** |longrightarrow| the
language becomes ...

* Clear
* Readable
* Memorizable (less exceptions)
* Attractive?

Good: Refuses To *Narrow* Built-In Types
----------------------------------------

.. code-block:: c++

   int i = 1.5;       // <--- silently narrowing to 1
   int j{1.5};        // <--- error: narrowing conversion of ‘1.2e+0’ from ‘double’ to ‘int’

Examples
--------

* **Integer initialization**

  .. code-block:: c++

     int i{42};
     int j{};  // initialized with 0

* **Array initialization**

  .. code-block:: c++

     int arr[]{1,2,3};

* **Struct initialization**

  .. code-block:: c++

     struct s { int i,j; }
     s s1{1,2};

* **Container Initialization**
          
  .. code-block:: c++

     std::vector<int> v{1,2,3};
     std::map<int, std::string{ {1, "one"}, {2, "two"}, };

* **Member array initialization**
      
  .. code-block:: c++

     class C {
     public:
       C() : data_{1,2,3} {}
     private:
       const int data_[3];
     };
          
* **Heap array initialization**

  .. code-block:: c++

     const int *arr = new const int[3]{1,2,3};
