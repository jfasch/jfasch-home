.. include:: <mmlalias.txt>

.. ot-topic:: cxx11.smart_pointers.introduction
   :dependencies: cxx11.new_language_features.miscellaneous


Introduction
============

.. contents::
   :local:

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
       tmp->do_something(); // throws
       delete tmp;     // LEAKED!!
       ...
   }

Recap: Constructors and Destructors
-----------------------------------

**Deterministic cleanup**: at scope exit

* Explicit return
* End of scope
* Exceptions |longrightarrow| *stack unwinding*

.. image:: introduction-dtors.dia

Links
-----

* ` Back to Basics: C++ Smart Pointers - David Olsen - CppCon 2022
  <https://youtu.be/YokY6HzLkXs>`__

  .. raw:: html

     <iframe 
         width="560" height="315" 
	 src="https://www.youtube.com/embed/YokY6HzLkXs" 
	 title="YouTube video player" 
	 frameborder="0" 
	 allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	 allowfullscreen>
     </iframe>
