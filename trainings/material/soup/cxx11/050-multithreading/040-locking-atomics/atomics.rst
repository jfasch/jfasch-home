.. ot-topic:: cxx11.multithreading.atomics
   :dependencies: cxx11.multithreading.race_conditions

.. include:: <mmlalias.txt>


Atomics: ``std::atomic``
========================

Atomic Instructions (1)
-----------------------

Simple integers don't need a mutex |longrightarrow| *atomic
instructions*

.. code-block:: c++
   :caption: GCC: atomic built-ins

   static int global;
   void inc() {
     __sync_fetch_and_add(&global, 1);
   }

.. code-block:: c++
   :caption: Windows

   static LONG global;
   void inc() {
     InterlockedIncrement(&global);   
   }

Atomic Instructions (2)
-----------------------

.. code-block:: c++

   #include <atomic>
   std::atomic<int> global(0);
   void inc() {
     global++;
   }
  
* Specializations for all types that are capable

