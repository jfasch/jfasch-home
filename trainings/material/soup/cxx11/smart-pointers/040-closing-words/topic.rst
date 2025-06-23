.. include:: <mmlalias.txt>


Smart Pointers: Closing Words
=============================

.. contents::
   :local:

Shared Pointers: Closing Words
------------------------------

**Now when to use which pointer?**

|longrightarrow| no definitive answer, but ...

**Answer 1: performance, and designwise correctness**

* Always use ``std::unique_ptr<>`` |longrightarrow| clearly defined
  ownership
* Pass object around as pointer (``uptr->get()``)
* Use ``std::shared_ptr<>`` only if we have real shared ownership

**Answer 2: programming efficiency**

* Don't waste a thought on ownership, simply write it
* Always use ``std::shared_ptr<>``

jjj move to closing words: ``std::shared_ptr`` vs. ``std::unique_ptr``
----------------------------------------------------------------------

How do ``std::shared_ptr`` and ``std::unique_ptr`` compare?

* ``std::unique_ptr``

  * Small - size of a pointer
  * Operations compile away entirely
  * No excuse *not* to use it
  * Have to think more though

* ``std::shared_ptr``

  * Size of two pointers
  * Copying manipulates the resource count. *Expensive: atomic
    instructions - memory barriers*
  * Copying manipulates non-adjacent memory locations
  * Usage is very easy (no ``std::move`` and such)

  .. attention::

     * Cyclic references possible! 
     * No *garbage collection* as in Java
     * |longrightarrow| Leak!!

     See below ...

