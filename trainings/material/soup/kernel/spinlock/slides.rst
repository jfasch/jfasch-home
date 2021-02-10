.. include:: <mmlalias.txt>

Spinlock (vs. Mutex) (Slideshow)
================================

.. contents::
   :local:

.. sidebar:: Source

   `See Github
   <https://github.com/jfasch/jf-kernel-course/tree/my_driver_spinlock_atomic/_morph>`__

Mutual Exclusion: Spinlock
--------------------------

**Atomic context must not sleep** |longrightarrow| *busy waiting*

* The only locking possibility in atomic context
* Can also be used in process context

  * Cheap - no context switch if lock is held
  * Interrupts off on local CPU |longrightarrow| *anti-realtime*

**How does it work?**

* On a *Uniprocessor*

  * Disable interrupts
  * |longrightarrow| preemption disabled
  * |longrightarrow| lock in its simplest form

* On a *Multiprocessor*

  * Set "locked" flag (atomically)
  * Disable interrupts on local processor
  * |longrightarrow| no preemption on local processor
  * Remote processors busy wait around the "locked" flag (atomically
    trying to *test-and-set* it)

Spinlock Initialization
-----------------------

.. code-block:: c

   #include <linux/spinlock.h>

   spinlock_t lock;
   void spin_lock_init(spinlock_t* lock);

* No destructor available

Simple Lock/Unlock
------------------

.. code-block:: c

   #include <linux/spinlock.h>

   void spin_lock(spinlock_t *lock);
   int spin_trylock(spinlock_t *lock);
   void spin_unlock(spinlock_t *lock);

**Careful**

* No nesting (no recursive locks) |longrightarrow| deadlock

* If you find yourself using ``spin_trylock()`` ...

  * your code is likely broken
  * you rather want to *wait* for something

Simple is not Bulletproof: Interrupt State
------------------------------------------

* Multiple spinlocks can be acquired in non-trivial call chains
* Most variations don't keep track of interrupt state

  * Too easy to re-enable interrupts *too early*
  * One cannot always control the call chain

.. code-block:: c

   unsigned long irqflags;

   spin_lock_irqsave(&lock, irqflags);
   ...
   spin_unlock_irqrestore(&lock, irqflags);

Mutual Exclusion: Conclusion
----------------------------

**There is always a tradeoff** ...

* Spinlocks are good

  * No expensive *context switch* during lock contention
  * Can be used in (between) interrupt context and process context

* Spinlocks are bad

  * No sleep! (|longrightarrow| no easy memory allocation, no easy
    this, no easy that)
  * Must be held *very short* |longrightarrow| no
    scheduling/preemption on local processor

* Mutexes are good

  * Sleeping allowed
  * Everything's easy

* Mutexes are bad

  * Expensive *context switch* during lock contention
  * Cannot be used in interrupt context
  * |longrightarrow| no easy data sharing between process and
    interrupt context
