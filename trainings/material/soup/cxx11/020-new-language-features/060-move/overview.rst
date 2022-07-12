.. ot-topic:: cxx11.new_language_features.move.overview
   :dependencies: cxx11.smart_pointers.unique_ptr,
		  cxx03.functions_and_methods.references,
		  cxx03.data_encapsulation.object_copy

.. include:: <mmlalias.txt>


Overview
========

.. contents::
   :local:

Return Object Problem: Reference To Stack-Based Object
------------------------------------------------------

**Whole class of problems**: lifetime of returned objects

.. list-table::
   :align: left
   :widths: auto

   * * .. code-block:: c++

          const std::string& f() {
              std::string s{"blah"};
              return s;
          }

     * .. code-block:: console

          warning: reference to local variable ‘s’ returned
               std::string s{"blah"};
                 ^

   * * .. code-block:: c++

          const std::string& f() {
              return "blah";
          }

     * .. code-block:: console
  
          warning: returning reference to temporary
               return "blah";
                   ^

* C string converted to ``std::string`` to match return type
* Object's home is on the *stack*
* Returning *reference* to it
* |longrightarrow| "undefined behavior"
* Fortunately compilers can detect and warn

Return Object Problem: Solution: Copy
-------------------------------------

**Solution**: return by copy

.. code-block:: c++

   std::string f() {
       return "blah";
   }

* Before return, construct temporary from ``"blah"``
* During return, copy-construct receiver object
* After return (during stack frame cleanup), destroy temporary
* |longrightarrow| *Performance*

.. code-block:: c++

   std::vector<int> f() {
       std::vector<int> v;
       int i=100000;
       while (i--)
           v.push_back(i);
       return v;
   }

Move Semantics: Wish List
-------------------------

* Copy is expensive |longrightarrow| want cheap *move* instead

**What if the compiler could help out?**

* Compiler should do that for me (he knows that the local variable is
  not used anymore after return)
* Determine automatically that an object *cannot be used anymore*
* **If so**, call a special kind of constructor (*move constructor*)
  that takes ownership
* **Otherwise**, insert copy constructor as usual

.. _lvalue-definition:

Theory: Lvalues
---------------

Basically ...

* Anything that can be assigned to
* Anything that has an address
* Anything that can be dereferenced

.. code-block:: c++

   int a = 42;
   int b = 43;
   
   a = b;
   b = a;
   a = a * b;

   char* buffer = new char[1];
   *buffer = 'a';              // <--- some expressions are lvalues
   buffer[0] = 'a';            // <--- some expressions are lvalues
   
   a * b = 42;                 // <--- some are not (error)

Theory: Rvalues
---------------

Basically ...

* Anything that is not an lvalue is an rvalue

  * Temporaries

    .. code-block:: c++

       std::string("blah") = "blech";  // <--- error

  * Literal constants

    .. code-block:: c++

       42 = 666;  // <--- error

  * Function return values (that aren't lvalue references)

    .. code-block:: c++

       std::string f();
       f() = "blech";                  // <--- error

    .. code-block:: c++

       std::string& f();
       f() = "blech";                  // <--- ok

  * Results of built-in operators that aren't lvalues

    .. code-block:: c++

       int a = 1, b = 2;
       a + b = 666;                    // <--- error

Lvalue References (The Good Old Ones)
-------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/050-references/topic`

* Non-const lvalue references can only bind to lvalues

  .. code-block:: c++

     int a;
     int& b = a;             // <--- ok
     int& c = a * 2;         // <--- error: cannot bind to rvalue

* Const lvalue references can bind to lvalue or rvalues

  .. code-block:: c++

     const int& r1 = a * 2;         // <--- ok: bind to rvalue
     const std::string& r2 = f();   // <--- ok: bind to rvalue

  |longrightarrow| Non-trivial: compiler has to set aside storage to
  outlive the reference

Rvalue References: So What Is That?
-----------------------------------

* Double ampersand ``&&``
* Rvalue references can only bind to rvalues
* *And can be assigned to!*

  .. code-block:: c++
  
     int&& rvr = 42;   // <--- bound to an rvalue (an int literal)
     rvr = 42;          // <--- assigned to!

* Cannot bind to lvalues

  .. code-block:: c++

     int a = 666;
     int&& rvr = a;   // <--- error: cannot bind rvalue reference to lvalue

* But rvalue references just don't make sense as standalone variables
* |longrightarrow| Preferred use as function parameters for overload
  resolution

Rvalue References As Function Parameters
----------------------------------------

* Semantics just the same as with standalone variables
* |longrightarrow| *Rvalue references can only bind to rvalues*

.. code-block:: c++

   void f(int&& param);

   int a;
   f(a);     // <--- error: cannot bind rvalue reference to lvalue
   f(a*2);   // <--- error: ok - rvalue

.. _use-of-rvalue-inside-function:

Use Of Rvalue References Parameter Inside A Function: *Is An Lvalue*
--------------------------------------------------------------------

.. sidebar::

   **See also**

   * :doc:`livehack-using-string-move`

* Inside a function, and rvalue type parameter *is an lvalue*
* It has a name, after all! And an address!

  .. code-block:: c++
  
     void f(int&& param);
     void g(int&& param)
     {
         f(param);   // <--- error: cannot bind rvalue reference to lvalue
     }

* Enter ``std::move``

  .. code-block:: c++
  
     #include <utility>
     
     void f(int&& param);
     void g(int&& param)
     {
         f(std::move(param));
     }

* *Converts lvalue to rvalue*
* |longrightarrow| Object *copy* vs. object *move*

Enter Move Constructor And Move Assignment
------------------------------------------

* Compiler *knows* that after the return of a local variable that
  variable cannot be used anymore
* |longrightarrow| inserts *move constructor* and/or *move assignment*
  operators

.. code-block:: c++

   class foo
   {
   public:
       foo(foo&&) noexcept;
       foo& operator=(foo&&) noexcept;
   };

**Rules**

* *Move constructor* is implicitly defined by compiler as member- (and
  base-) wise move if there are no user-declared ...

  * Destructor
  * Copy constructor
  * Copy assignment operator
  * Move assignment operator

* *Move assignment operator* is implicitly defined by compiler as
  member- (and base-) wise move if there are no user-declared ...

  * Destructor
  * Copy constructor
  * Copy assignment operator
  * Move constructor
