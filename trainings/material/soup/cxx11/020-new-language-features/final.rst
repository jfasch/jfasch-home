.. include:: <mmlalias.txt>


``final``
=========

.. contents::
   :local:

.. sidebar:: 

   **Documentation**

   * `final <https://en.cppreference.com/w/cpp/language/final>`__

Architectural Decisions
-----------------------

* Interfaces are cool ("pure virtual"): add readability and
  specifiability
* Implementation inheritance (extension) is not so cool

  * One always has to ask: "Does somebody derive from this class?"
  * |longrightarrow| Architectural incontinence!

Enter ``final``: Architectural Cleanliness By Compiler
------------------------------------------------------

**Best thing to do (IMHO): mark entire class final**

.. literalinclude:: code/c++11-final-class.cpp
   :caption: :download:`code/c++11-final-class.cpp`
   :language: c++

.. code-block:: console

   code/c++11-final-class.cpp:2:7: error: cannot derive from ‘final’ base ‘Leaf’ in derived type ‘Impossible’
       2 | class Impossible : public Leaf {};
         |       ^~~~~~~~~~

**Also possible: marking single method final**

.. literalinclude:: code/c++11-final-method.cpp
   :caption: :download:`code/c++11-final-method.cpp`
   :language: c++

.. code-block:: console

   code/c++11-final-method.cpp:11:18: error: virtual function ‘virtual void Derived::method1()’ overriding final function
      11 |     virtual void method1() final {}
         |                  ^~~~~~~
   code/c++11-final-method.cpp:4:18: note: overridden function is ‘virtual void Base::method1()’
       4 |     virtual void method1() final {}
         |                  ^~~~~~~
