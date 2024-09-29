.. include:: <mmlalias.txt>

.. ot-topic:: cxx03.data_encapsulation.object_copy
   :dependencies: cxx03.data_encapsulation.ctor_dtor


Object Copy (And Resource Management): There Be Dragons
=======================================================

.. contents::
   :local:

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/delete`

Copy in C
---------

**Copy of objects in C**: ``struct``

.. list-table::
   :align: left
   :widths: auto

   * * .. code-block:: c++

          struct point
          {
              int x;
              int y;
          };

     * .. code-block:: c++

          struct point p1 = {2,7};
	  struct point p2;

	  p2 = p1;

* ``struct point``: *memberwise* copy
* Simple: transfer of memory image

Copy Constructor
----------------

**Copying objects in C**: similar to C++

.. list-table::
   :align: left
   :widths: auto

   * * .. code-block:: c++

          class point
          {
              // ...
	  private:
	      int x;
	      int y;
          };
          ...
          point p1;
          point p2(p1);

     * * Compiler *generates copy constructor*
       * |longrightarrow| member by member
       * |longrightarrow| simple data types just as in C

That was simple. **But ...**

Pointer Members, And Compiler Generated Copy
--------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/c/090-program-sanity/080-valgrind/topic`
   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/delete`

* Compiler-generated copy constructor (and assignment operator) does
  member-wise copy
* Pointers are members just like any other member

That ``String`` class is missing something ...

.. literalinclude:: code/string-10.h
   :caption: :download:`code/string-10.h`
   :language: c++

.. literalinclude:: code/c++03-copy-string-10.cpp
   :caption: :download:`code/c++03-copy-string-10.cpp`
   :language: c++

Crashes on execution ...

.. code-block:: console

   $ ./code/c++03-copy-string-10 
   free(): double free detected in tcache 2
   Aborted (core dumped)

:doc:`Valgrind </trainings/material/soup/c/090-program-sanity/080-valgrind/topic>`
complains loudly ...

.. code-block:: console

   $ valgrind ./code/c++03-copy-string-10 
   ==221601== Memcheck, a memory error detector
   ==221601== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
   ==221601== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
   ==221601== Command: ./code/c++03-copy-string-10
   ==221601== 
   ==221601== Invalid free() / delete / delete[] / realloc()
   ==221601==    at 0x484465B: operator delete[](void*) (vg_replace_malloc.c:1103)
   ==221601==    by 0x401210: String::~String() (string-10.h:17)
   ==221601==    by 0x401194: main (c++03-copy-string-10.cpp:8)
   ==221601==  Address 0x4dc8c80 is 0 bytes inside a block of size 6 free'd
   ==221601==    at 0x484465B: operator delete[](void*) (vg_replace_malloc.c:1103)
   ==221601==    by 0x401210: String::~String() (string-10.h:17)
   ==221601==    by 0x401188: main (c++03-copy-string-10.cpp:8)
   ==221601==  Block was alloc'd at
   ==221601==    at 0x484222F: operator new[](unsigned long) (vg_replace_malloc.c:640)
   ==221601==    by 0x4011C5: String::String(char const*) (string-10.h:10)
   ==221601==    by 0x40116F: main (c++03-copy-string-10.cpp:5)
   ==221601== 
   ==221601== 
   ==221601== HEAP SUMMARY:
   ==221601==     in use at exit: 0 bytes in 0 blocks
   ==221601==   total heap usage: 2 allocs, 3 frees, 72,710 bytes allocated
   ==221601== 
   ==221601== All heap blocks were freed -- no leaks are possible
   ==221601== 
   ==221601== For lists of detected and suppressed errors, rerun with: -s
   ==221601== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)


Why? Dragons Everywhere!
------------------------

* Pointer member is to compiler simply *a pointer*
* Pointers are copied
* But not what they point to
* The first of both objects that is destroyed frees memory
* *How should the compiler know!*

.. list-table::
   :align: left
   :widths: auto

   * * * Pointer to string is simply copied
       * Both point to *same* string

       .. image:: 02-02-00-pointer-member.dia
	  :scale: 20%
     * * First destructor frees memory
       * Second |longrightarrow| **double-free**

       .. image:: 02-02-00-pointer-member-segfault.dia
	  :scale: 20%

Solution: Write Copy Constructor Manually
-----------------------------------------

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * C++ pre 11
     * C++ 11 onwards
   * * * Copy ctor is a duplicate of ``String(const char*)``
       * Solution: write clumsy helper function
     * * Simply call the other ctor
       * |longrightarrow|
         :doc:`/trainings/material/soup/cxx11/020-new-language-features/050-delegating-ctor/topic`
   * * .. literalinclude:: code/string-20-03.h
          :caption: :download:`code/string-20-03.h`
	  :language: c++
     * .. literalinclude:: code/string-20-11.h
          :caption: :download:`code/string-20-11.h`
	  :language: c++

.. image:: 02-02-00-pointer-member-2.dia
   :scale: 20%

Valgrind is happy ...

.. code-block:: console

   $ valgrind ./code/c++03-copy-string-20-11 
   ...
   ==221807== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

Copy Constructor: Recursive/Memberwise
--------------------------------------

.. list-table::
   :align: left
   :widths: auto

   * * .. code-block:: c++

          struct TwoStrings
          {
              String s1;
              String s2;
          };
          struct TwoTwoStrings
          {
              TwoStrings s21;
              TwoStrings s22;
          };

     * * ``String`` has copy constructor (correct because handwritten)
       * |implies| ``TwoStrings`` is correct
       * |implies| ``TwoTwoStrings`` is correct
       * |implies| ...

Assignment Operator
-------------------

**Second way of copying objects:** overwrite an existing object

.. list-table::

   * * .. code-block:: c++

          class point
          {
              // ...
	  private:
	      int x;
	      int y;
          };

	  point p1, p2;
	  // ...
	  p2 = p1;         // <--- assignment!

     * * Generated by compiler, just like copy constructor 
       * |longrightarrow| Member by member
       * |longrightarrow| simple data types just as in C

**But ...** 

* As with the copy constructor |longrightarrow| pointer members!
* Assignment operator is best self defined when pointer members are
  involved

Assignment Operator and Pointer Members: Memory Leak
----------------------------------------------------

**Caution, naively buggy!**

.. list-table::

   * * .. code-block:: c++

          String& String::operator=(
              const String& s)
          {
              _c_str = new char[
                  strlen(s._c_str)+1];
              strcpy(_c_str, s._c_str);
              return *this;
          }

	  String s1("hello");
	  String s2("hallo");
	  s2 = s1;              // <--- LEAK!

     * 

       .. image:: 02-02-00-pointer-member-assignment-operator.dia
	  :scale: 20%

Assignment Operator and Pointer Members: Memory Leak, Straighforward Fix
------------------------------------------------------------------------

**Caution, still naively buggy!**

.. code-block:: c++

   String& String::operator=(
       const String& s)
   {
       delete[] _c_str;        // <--- BUG!!
       _c_str = new char[
           strlen(s._c_str)+1];
       strcpy(_c_str, s._c_str);
       return *this;
   }

**WTF, why could this be a bug??**

Assignment Operator and Pointer Members: *Self-Assignment*
----------------------------------------------------------

Correct nonsense ...

* Why would somebody want to write this?
* But anyway, it is legal!

.. list-table::

   * * .. code-block:: c++

          int i = 42;
          i = i;

     * .. code-block:: c++

          String s("hello");
	  s = s;             // <--- SEGFAULT!! (if you're lucky)

* *Self Assignment*
* Rare but true!
* User expects that this is not an error

Assignment Operator: *Self Assignment*, Correctly Implemented
-------------------------------------------------------------

**Ultimate Fix**: *Self Assignment Check*

.. code-block:: c++

   String& String::operator=(
       const String& s)
   {
       if (this != &s)} {        // <--- self assignment check
           delete[] _c_str;
           _c_str = new char[
               strlen(s._c_str)+1];
           strcpy(_c_str, s._c_str);
       }
       return *this;
   }
