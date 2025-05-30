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
