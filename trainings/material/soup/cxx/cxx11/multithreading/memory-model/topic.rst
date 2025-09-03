.. include:: <mmlalias.txt>


The C++ Memory Model
====================

.. contents::
   :local:

Data Race: Load Modify Store
----------------------------

.. sidebar:: Trainer's note

   * Start with this program, as ``load-modify-store.cpp``
   * Compile manually with ``-O0``, because ``-O3`` optimizes data
     races away at this limited level

     $ g++ -O0 load-modify-store.cpp

     (Or tune build system accordingly)

   * More:
     https://gcc.gnu.org/onlinedocs/gcc-13.3.0/gcc/Optimize-Options.html

* A data race is what the memory model is there to help understand and
  prevent
* Here: *Load-Modify-Store-Conflict*
* |longrightarrow| Integer access is not atomic

.. literalinclude:: code/load-modify-store.cpp
   :caption: :download:`code/load-modify-store.cpp`
   :language: c++

.. code-block:: console

   $ g++ -O0 load-modify-store.cpp
   $ ./a.out 
   expected 2000000000, real 1066359623

.. _cxx11-memory-model-load-modify-store:

Data Race: Load Modify Store (Explained)
----------------------------------------

* Innocent ``counter++`` is

  * Load from memory
  * Increment in CPU register
  * Write back to memory

====== ====     ====== ====  ===========
**CPU A**         **CPU B**  **Memory**
-----------     -----------  -----------
Instr   Loc     Instr   Loc  Glob
load     42     -       -     42 
-        42     load    42    42 
inc      43     -       -     42 
-        43     inc     43    42 
-        43     store   43    43 
store    43     -       43    43 
====== ====     ====== ====  ===========

Optimizations
-------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/c/100-performance/020-computebound/topic`

* Your program does not run how you wrote it
* Compiler optimizations (see :doc:`here
  </trainings/material/soup/c/100-performance/020-computebound/topic>`
  for an overview)
* CPU optimizations: e.g. read and write reordering
* |longrightarrow| the order in which writes becomes visible to other
  threads/CPUs is *not* what you think
* (Similar for reads)
* |longrightarrow| no *sequential order* guaranteed

.. _cxx11-memory-model-write-reordering:

CPU Optimization: Write Reordering
----------------------------------

* The following code has "undefined behavior"
* A threads that accesses the object through ``global_widget`` **might
  see the pointer in memory before the memory itself**
* This is done **by the CPU**
* |longrightarrow| 

.. code-block:: c++

   Widget* w = new Widget(...);                           // <-- write: memory allocation, Widget initialization
   global_widget = w;                                     // <-- write: global_widget

Another Race: ``std::list`` Is Not Threadsafe
---------------------------------------------

.. sidebar:: Documentation

   * `std::list <https://en.cppreference.com/w/cpp/container/list>`__

.. sidebar:: Trainer's note

   * Start with this program, as ``list.cpp``

.. literalinclude:: code/list-mt-unsafe.cpp
   :caption: :download:`code/list-mt-unsafe.cpp`
   :language: c++

.. code-block:: console

   $ g++ -O0 list.cpp
   $ ./a.out 
   #elements: 1476027

* Somehow pointers have been updated concurrently and
  incorrectly
* |longrightarrow| A typical case for a mutex

Protecting ``std::list`` With A Mutex
-------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx/cxx11/multithreading/040-locking-atomics/mutex`
   * :doc:`/trainings/material/soup/cxx/cxx11/multithreading/040-locking-atomics/scoped-locking`

.. sidebar:: Trainer's note

   * Program ``list.cpp``

.. literalinclude:: code/list-mt-mutex.cpp
   :caption: :download:`code/list-mt-mutex.cpp`
   :language: c++

.. code-block:: console

   $ g++ -O0 list.cpp
   $ ./a.out 
   #elements: 2000000

What's A Mutex?
---------------

* A boolean flag, with states "open" and "closed"
* Operations "acquire" and "release"
* *Acquire*

  * Flag is "open"

    * Set it "closed"

  * Flag is "closed"

    * Enqueue yourself onto list of waiters
    * Enter wait state *at the same time* (|longrightarrow| Lost
      Wakeup Problem)
    * Retry on wakeup

* *Release*

  * Reset flag to "open"
  * Wake any waiters

**What if there is something wrong with the flag?**

For example:

* :ref:`cxx11-memory-model-load-modify-store`
* :ref:`cxx11-memory-model-write-reordering`

Memory Order
------------

.. sidebar:: Documentation

   * `std::memory_order
     <https://en.cppreference.com/w/cpp/atomic/memory_order>`__

.. code-block:: c++

   enum class memory_order
   {
       relaxed, 
       consume, 
       acquire,                                        // <-- cf lock
       release,                                        // <-- cf unlock
       acq_rel, 
       seq_cst                                         // <-- atomic ++
   };

Release And Acquire Ordering
----------------------------

.. sidebar:: Trainer's note

   * Draw sketch

**Mutex**: memory/flag requirements

* *Release order*: when flag is released (set to "open"), the
  reader/locker must see all writes that happened before "open"

  |longrightarrow| CPU must not reorder writes across flag write

* *Acquire order*: the opposite side must cooperate and tag their flag
  read operations accordingly

  |longrightarrow| CPU must not reorder reads across flag read

Release And Acquire Ordering: A Naive Spinlock
----------------------------------------------

.. sidebar:: Documentation

   * `std::atomic_flag
     <https://en.cppreference.com/w/cpp/atomic/atomic_flag>`__
   * `std::atomic <https://en.cppreference.com/w/cpp/atomic/atomic>`__

.. sidebar:: Trainer's note

   * Program ``list.cpp``

* Spinlock: does not block the locker if locked, but rather spins
  actively until free

  * |longrightarrow| less context switches
  * Good for short critical sections
  * **Not good if both contenders are scheduled on the same CPU**
    |longrightarrow| do not use this, it is way too naive.

* ``std::atomic_flag`` is guaranteed to be lock-free
* ``std::atomic<>`` specializations are not

.. literalinclude:: code/list-mt-spinlock.cpp
   :caption: :download:`code/list-mt-spinlock.cpp`
   :language: c++

Sequential Consistency: Resolving Load-Modify-Store-Conflict
------------------------------------------------------------

.. sidebar:: Trainer's note

   * Program ``load-modify-store.cpp``

.. literalinclude:: code/load-modify-store-seq-cst.cpp
   :caption: :download:`code/load-modify-store-seq-cst.cpp`
   :language: c++

And Other Memory Orders?
------------------------

* Read-Copy-Update (`What is RCU, Fundamentally?
  <https://lwn.net/Articles/262464/>`__)
* `A Relaxed Guide to memory_order_relaxed - Paul E. McKenney & Hans
  Boehm - CppCon 2020
  <https://youtu.be/cWkUqK71DZ0?si=H0Qovi9DpFdf7uqh>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/cWkUqK71DZ0?si=_c07ry8dzPWeLlFF" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     referrerpolicy="strict-origin-when-cross-origin" 
	     allowfullscreen>
     </iframe>

Links
-----

* `C++ Memory Model: from C++11 to C++23 - Alex Dathskovsky
  <https://youtu.be/tjcU2xDmuFQ?si=uKahmiSRZdS87Xzh>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/tjcU2xDmuFQ?si=uKahmiSRZdS87Xzh" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     referrerpolicy="strict-origin-when-cross-origin" 
	     allowfullscreen>
     </iframe>

* `The memory model in C++ - Rainer Grimm - Meeting C++ 2016
  <https://youtu.be/e0DsVqZLMzU?si=mj9ETF1-CyarbGcN>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/e0DsVqZLMzU?si=xG0GcV-pACRlJ7EQ" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     referrerpolicy="strict-origin-when-cross-origin" 
	     allowfullscreen>
     </iframe>

* `Arvid Norberg: The C++ memory model: an intuition
  <https://youtu.be/OyNG4qiWnmU?si=1xLDFrgdHW9Ak0vZ>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/OyNG4qiWnmU?si=mmZdH5XCN3lc1WJZ" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     referrerpolicy="strict-origin-when-cross-origin" 
	     allowfullscreen>
     </iframe>
