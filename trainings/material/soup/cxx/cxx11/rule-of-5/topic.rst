.. include:: <mmlalias.txt>


The Rule Of Three/Five/Zero
===========================

.. contents::
   :local:

.. sidebar:: Documentation

   * `The rule of three/five/zero
     <https://en.cppreference.com/w/cpp/language/rule_of_three.html>`__

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx/cxx11/move/index`

.. _cxx11-rule5-rule-of-three:

Rule Of Three
-------------

* If you find yourself writing a destructor, you probably need to
  think about copy
* |longrightarrow| Copy constructor, copy assignment operator

Rule Of Five
------------

* If you implement *one of* (best: :ref:`all three
  <cxx11-rule5-rule-of-three>`)

  * Destructor
  * Copy constructor
  * Copy assignment operator

  your class probably should have a move constructor and move
  assignment operator too. *The compiler won't create one*.

Rule Of Zero
------------

* Best to not think about all this, and try hard to implement *none of
  those five*
* |longrightarrow| Simple life!

Example: Rule Of Zero, Simplest
-------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx/cxx11/move/index`
   * :doc:`/trainings/material/soup/cxx/cxx03/900-standard-library-miscellanea/string/topic`

* Member of ``std::string`` type. Dual copy/move initializers from it.
* ``std::string`` does resource management

  * Implements copy
  * Implements move

* As long as you leave everything go, life is easy
* Compiler implements what's possible |longrightarrow| all five
* |longrightarrow| Rule Of Zero

.. literalinclude:: code/rule-of-zero-string.cpp
   :caption: :download:`code/rule-of-zero-string.cpp`
   :language: c++

Example: Rule Of Zero, Move-Only
--------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/unique-ptr/topic`

* Member of *move-only* type ``std::unique_ptr``
* Compiler implements what's possible |longrightarrow| move only

.. literalinclude:: code/rule-of-zero-unique-ptr.cpp
   :caption: :download:`code/rule-of-zero-unique-ptr.cpp`
   :language: c++

Example: Rule Of Three - Explicit Resource Management, *Done Wrong*
-------------------------------------------------------------------

.. sidebar:: Trainer's note

   *Important:* ``-O0`` *crashes as expected*

   GCC (``gcc (GCC) 15.1.1 20250521 (Red Hat 15.1.1-2)``) with ``-O3``
   (and ``-std=c++26`` for that matter) makes optimizations that
   somehow paper over the double free.

* Pointer member
* Must think of *ownership*
* ``MyString`` allocates
* |longrightarrow| *Must deallocate*
* |longrightarrow| User-defined destructor
* **Compiler generated copy is buggy by default!**
* |longrightarrow| **Rule Of Three**

.. literalinclude:: code/rule-of-three-handwritten-string-wrong.cpp
   :caption: :download:`code/rule-of-three-handwritten-string-wrong.cpp`
   :language: c++

.. list-table::
   :align: left
   :widths: auto

   * * * Pointer to string is simply copied
       * Both point to *same* string

       .. image:: pointer-member-compilerview.dia
	  :scale: 20%
     * * First destructor frees memory
       * Second |longrightarrow| **double-free**

       .. image:: pointer-member-doublefree.dia
	  :scale: 20%

Example: Rule Of Three - Explicit Resource Management, *Done Almost Right*
--------------------------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx/cxx11/delegating-ctor/topic`

* Copy constructor (btw. :doc:`delegating work to an existing
  constructor </trainings/material/soup/cxx/cxx11/delegating-ctor/topic>`)
* Copy assignment operator

  * Slightly wrong |longrightarrow| *self assignment*
  * Perfectly legal in C, realistic in certain corner cases

.. literalinclude:: code/rule-of-three-handwritten-string-almost-right.cpp
   :caption: :download:`code/rule-of-three-handwritten-string-almost-right.cpp`
   :language: c++

.. image:: pointer-member-manual-copy.dia
   :scale: 20%

Example: Rule Of Three - Explicit Resource Management, *Done Right*
-------------------------------------------------------------------

* Final tweak: add *self assignment check*
* |longrightarrow| Pooh

.. literalinclude:: code/rule-of-three-handwritten-string-right.cpp
   :caption: :download:`code/rule-of-three-handwritten-string-right.cpp`
   :language: c++

Example: Rule Of Five - Explicit Resource Management, And Moving?
-----------------------------------------------------------------

* Move not implemented
* |longrightarrow| RValues are copied rather than re-used/moved
* *Not a correctness, but a usability issue*
* "A question of being nice to your users"
* E.g. ``std::string`` (as all types from the standard library, where
  applicable) have dual constructors

.. literalinclude:: code/rule-of-five-handwritten-string-move-missing.cpp
   :caption: :download:`code/rule-of-five-handwritten-string-move-missing.cpp`
   :language: c++

Example: Rule Of Five - Explicit Resource Management, And Moving!
-----------------------------------------------------------------

.. sidebar:: Trainer's note

   ``-Wall`` implies ``-Wself-move``. Disable that CMake-wise, like

   .. code-block:: console

      target_compile_options(<target> PRIVATE -Wno-self-move)

* Same old story: check for self-move cornercase

.. literalinclude:: code/rule-of-five-handwritten-string-move.cpp
   :caption: :download:`code/rule-of-five-handwritten-string-move.cpp`
   :language: c++

Example: Move-Only Datatypes
----------------------------

.. sidebar:: Documentation

   * `man -s 2 timerfd_create
     <https://man7.org/linux/man-pages/man2/timerfd_create.2.html>`__
   * `man -s 2 read
     <https://man7.org/linux/man-pages/man2/read.2.html>`__
   * `man -s 2 dup
     <https://man7.org/linux/man-pages/man2/dup.2.html>`__

* Not everything is copyable
* |longrightarrow| ``std::unique_ptr``, prominently
* File descriptors? Copy *could* be implemented as `dup()
  <https://man7.org/linux/man-pages/man2/dup.2.html>`__

  * ... but that is not exactly the same
  * And not always applicable

.. literalinclude:: code/move-only-timerfd.cpp
   :caption: :download:`code/move-only-timerfd.cpp`
   :language: c++
