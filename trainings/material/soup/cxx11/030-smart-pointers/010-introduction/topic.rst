.. include:: <mmlalias.txt>

.. ot-topic:: cxx11.smart_pointers.introduction
   :dependencies: cxx11.new_language_features.miscellaneous


Introduction
============

Why Smart Pointers?
-------------------

**Most prominent pointer (memory management) related bugs**

* Memory leak
* Double free

**Even more so with exceptions**

* Alternate return path
* Requires extra handling for resource cleanup

.. code-block:: c++

   void do_something() {
       MyClass* tmp = new MyClass(666);
       do_something_with(tmp); // throws
       delete tmp;     // LEAKED!!
       ...
   }

Recap: Constructors and Destructors
-----------------------------------

**Deterministic cleanup**: at scope exit

* Explicit return
* End of scope
* Exceptions |longrightarrow| *stack unwinding*

.. image:: dtors.dia
