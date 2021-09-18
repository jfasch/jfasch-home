.. include:: <mmlalias.txt>

.. ot-topic:: cxx11.multithreading.thread
   :dependencies: cxx11.multithreading.introduction,
		  sysprog.posix_threads.lifecycle


Threads in C++
==============

Creating Threads is Far Too Easy
--------------------------------

.. code-block:: c++
   :caption: No parameterization

   void f() { ... }
   std::thread t(f);

.. code-block:: c++
   :caption: ``std::bind``?

   void f(int i) { ... }
   std::thread t(f, 666);

.. code-block:: c++
   :caption: Lambdas

   std::thread t([](){ ... });

*Looks all pretty familiar, no?*

Joinable vs. Detached
---------------------

**Why wait for termination?**

* Wait for a calculation to finish

  * Distribute parallelizable algorithm over multiple CPUs

* Graceful program termination

.. code-block:: c++
   :caption: Synchronize caller with termination of ``t``

   t.join();


**Why detach a thread?**

* Background service thread |longrightarrow| program lifetime

.. code-block:: c++
   :caption: Detach a thread

   t.detach();

Cornercases in Thread Lifetime
------------------------------

**What if the program terminates before a thread?**

.. code-block:: c++

   int main() { std::thread t([](){for(;;);}); }

On Linux, at least ...

* When a process terminates, all its threads terminate *immediately*

**Can I terminate a thread without its cooperation?**

* In Linux, yes, theoretically
* What happens with locked mutexes?
* |longrightarrow| Cancellation hooks (hell!)

*Portably, no!*
