.. include:: <mmlalias.txt>

.. ot-topic:: cxx11.new_language_features.move
   :dependencies: cxx11.new_language_features.delegating_ctor,
		  cxx11.smart_pointers.unique_ptr


Moving, "RValue References"
===========================

"Return Object" Problem: Lifetime (1)
-------------------------------------

**Whole class of problems**: lifetime of returned objects

.. code-block:: c++

   const std::string& f() {
       std::string s{"blah"};
       return s;
   }

.. code-block:: c++

   const std::string& f() {
       return "blah";
   }

"Return Object" Problem: Lifetime (2)
-------------------------------------

.. code-block:: c++

   const std::string& f() {
       std::string s{"blah"};
       return s;
   }

* Object's home is on the *stack*
* Returning *reference* to it
* |longrightarrow| "undefined behavior"
* Fortunately compilers can detect and warn

.. code-block:: console

   warning: reference to local variable ‘s’ returned
        std::string s{"blah"};
                 ^

"Return Object" Problem: Lifetime (3)
-------------------------------------

.. code-block:: c++

   const std::string& f() {
       return "blah";
   }

* C string converted to ``std::string`` to match return type

  * Return type being *reference* is irrelevant

* |longrightarrow| *temporary* object
* |longrightarrow| "undefined behavior"

.. code-block:: console
  
   warning: returning reference to temporary
        return "blah";
            ^

"Return Object" Problem: Lifetime (4)
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

  * Though ``std::string`` objects are usually reference counted (but
    *not* by standard)
  * |longrightarrow| Cheap copy

"Return Object" Problem: Performance
------------------------------------

.. code-block:: c++

   std::vector<int> f() {
       std::vector<int> v;
       int i=100000;
       while (i--)
           v.push_back(i);
       return v;
   }

* Semantically correct
* Perfectly readable
* It's just that arrays of 100000 elements aren't copied so lightly
* Enter *Rvalue References*

.. literalinclude:: rvalueref-motivation.cc
   :caption: :download:`rvalueref-motivation.cc`

Move Semantics: Wish List
-------------------------

**Wish list:**

* Copy/assignment as before
* Special constructor for *moving*
* Can that be implemented in C++03?

  * Idea: non-const reference

**Exercise**

* Write a ``class X`` that carries an array of ``int`` and implements
  the usual copy semantics and a proper destructor.
* Additionally, for performance, the class provides a constructor that
  *transfers ownership* of the owned buffer.
* Try out the scenarios above, and see what's to be done in order for
  the *move constructor* to (not) be called.

Move Semantics, in C++03
------------------------

**Clumsy**, isn't it?

* Constructor with non-const reference preferred over const
* |longrightarrow| Have to be explicit when moving is not wanted -
  *which is the regular case!*

.. literalinclude:: moving-in-c++03.cc
   :caption: :download:`moving-in-c++03.cc`

* In none of these use cases (except for function return) I want moving!
* Function return is optimized away |longrightarrow| *Return Value
  Optimization (RVO)*

Lvalues and Rvalues (1)
-----------------------

.. code-block:: c++

   int a = 42;
   int b = 43;
   
   a = b; // ok
   b = a; // ok
   a = a * b; // ok
   
   int c = a * b; // ok
   a * b = 42; // error, assignment to rvalue

Lvalues and Rvalues (2)
-----------------------

**Rules** ...

* Everything that has a name is an Lvalue
* Everything that I can assign to is an Lvalue
* Everything that I can take the address of is an Lvalue
* Everything else is an Rvalue

**So** ...

* Temporaries are clearly Rvalues
* As are function calls

Moving (1)
----------

.. list-table:: 
   :align: left

   * * **To make the long story short ...**

       * Compiler will call ``X(X&&)`` when an Rvalue is passed
       * E.g. function return
       * Rules are far more complicated
       * ... as is the language
       * (How about RVO?)

     * .. code-block:: c++

          struct X
          {
              X(X&& x) 
              : data(x.data),
                size(x.size)
              {
                  x.data = 0;
                  x.size = 0;
              }
            
	      int *data;
              size_t size;
          };

Moving (2)
----------

**Compiler will DWIM** ...

* *Return "by copy"*

  .. list-table:: 
     :align: left

     * * * Select ``X(X&&)``
         * Or RVO with copy ctor

       * .. code-block:: c++

            X f()
            {
              return X{"abc"};
            }
            X x = f();

* *Ordinary initialization*

  .. list-table::
     :align: left

     * * * Select ``X(const X&)``
       * .. code-block:: c++

            X x{"abc"};
            X y = x;

Moving (3)
----------

**Explicitly requesting move operation**

.. code-block:: c++

   X y = std::move(x);


* ``std::move`` does not do anything the CPU must know
* Casts to ``&&`` to *force* selection of move-ctor
* Usage: ``std::sort``, for example

  * Rearrange items
  * |longrightarrow| Copy or move, depending on what's there

No C++ Without Pitfalls
-----------------------

**Compiler selects function** based upon parameter type

* Normal overload selection
* Once called, the parameter *is an lvalue*
* Careful with moving

.. list-table::
   :align: left

   * * **Bad**

       .. code-block:: c++

          X(X&& x)
          : s_(x.s_) {}

     * **Good**

       .. code-block:: c++

          X(X&& x)
          : s_(std::move(x.s_)) {}

