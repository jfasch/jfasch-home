.. include:: <mmlalias.txt>

.. jf-topic:: cxx11.new_language_features.brace_initialization
   :dependencies: cxx11.new_language_features.auto


Brace Initialization
====================

Brace Initialization: Motivation (1)
------------------------------------

**Initialization was always inconsistent** |longrightarrow| Extremely
confusing, especially for newbies!

* Integral types
* Aggregates (struct, array)
* Class objects
* Container (e.g. ``std::vector``) initialization with contained
  values |longrightarrow| ``push_back()`` orgies

Brace Initialization: Motivation (2)
------------------------------------

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

Brace Initialization: Motivation (3)
------------------------------------

.. list-table::
   :align: left

   * * **Aggregates**

       * Initialization as it used to be in good old C
       * No constructor style

     * **Aggregate Initialization**

       .. code-block:: c++

          int arr[] = {1, 2, 3};
          
          struct s { int i,j; }
          s s1 = {1, 2};
          s s2 = {1}; // s2.j==0

Brace Initialization: Motivation (4)
------------------------------------

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

Brace Initialization: Motivation (5)
------------------------------------

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

Brace Initialization: Motivation (6)
------------------------------------

.. list-table:: 
   :align: left

   * * **Member Arrays**

       * \textit{Cannot} be initialized
       * Must be filled in constructor body
       * $\to$ inconsistent
       * $\to$ loud
       * $\to$ workarounds

     * **Member Array Initialization**

       .. code-block:: c++

          class C {
          public:
            C() : data_(/*dammit!*/) {}
          private:
            const int data_[3];
          };

Brace Initialization: Motivation (7)
------------------------------------

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

Brace Initialization: Solution (1)
----------------------------------

**Solution: brace initialization everywhere** |longrightarrow| the
language becomes ...

* Clear
* Readable
* Memorizable (less exceptions)
* Attractive?

Brace Initialization: Solution (2)
----------------------------------

.. list-table::
   :align: left

   * * **Braces ...**

       .. code-block:: c++

          int i{42};
          
          int arr[]{1,2,3};
          
          struct s { int i,j; }
          s s1{1,2};
          
          vector<int> v{1,2,3};
      
     * **... many more braces**

       .. code-block:: c++

          class C {
          public:
            C() : data_{1,2,3} {}
          private:
            const int data_[3];
          };
          
          const int *arr = new const int[3]{1,2,3};
