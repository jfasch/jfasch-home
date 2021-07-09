.. include:: <mmlalias.txt>

.. jf-topic:: c.advanced_language_features.atomic
   :dependencies: c.advanced_language_features.volatile


Compiler Intrinsics
===================

Atomic Memory Access
--------------------

**Why is this code broken for multithreaded programs?**

.. code-block:: c

   volatile int use_count;
   
   void use_resource(void)
   {
     do_something_with_shared_resource();
     use_count++;
   }

Atomic Memory Access: Load/Modify/Store
---------------------------------------

**Load-Modify-Store conflict**

* Classic form of a *race condition*
* BTW: ``volatile`` is completely irrelevant!

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

Load/Modify/Store: Mutex
------------------------

.. code-block:: c

   static pthread_mutex_t use_count_mutex = 
     PTHREAD_MUTEX_INITIALIZER;
   int use_count;
   
   void use_resource(void)
   {
     do_something_with_shared_resource();
   
     pthread_mutex_lock(&use_count_mutex);
     use_count++;
     pthread_mutex_unlock(&use_count_mutex);
   }

**Drawback:** mutexes are expensive (|longrightarrow| context
switches)

Atomic Instructions
-------------------

**For simple integers there is a simpler way to atomicity (GCC only)**

.. code-block:: c
   :caption: ``fetch_and_add()``

   int use_count;
   
   void use_resource(void)
   {
     do_something_with_shared_resource();
     __sync_fetch_and_add(&use_count, 1);
   }

More GCC "Builtins"
-------------------

**GCC has a sheer number of builtins ...**

* Atomic operations
* Arithmetic with overflow checking (built-in "functions" with a
  "success" return type)
* Pointer bounds checking

**Further Information**

* `GCC Documentation: 6.55 Built-in Functions for Memory Model Aware
  Atomic Operations
  <https://gcc.gnu.org/onlinedocs/gcc/_005f_005fatomic-Builtins.html>`__
* `Microsoft: Compiler intrinsics
  <http://msdn.microsoft.com/en-us/library/26td21ds.aspx>`__

