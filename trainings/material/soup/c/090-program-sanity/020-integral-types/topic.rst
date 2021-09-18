.. include:: <mmlalias.txt>

.. ot-topic:: c.program_sanity.integral_types
   :dependencies: c.program_sanity.introduction


Know Your Integers
==================

Standard Data Types: ``size_t`` (1)
-----------------------------------

**Sizes are everywhere**

* Number of bytes in an allocated chunk of memory
* Number of elements in an array
* Number of microseconds until timer runs off
* Result of the ``strlen()`` function
* Result of the ``sizeof`` operator

*This is what* ``size_t`` *is there for:*

* Nobody has to worry about signedness (sizes simply don't become
  negative)
* |longrightarrow| adds clarity

.. code-block:: c

   #include <unistd.h>

Standard Data Types: ``size_t`` (2)
-----------------------------------

**Consequences**

* None (except for readability)
* (GCC) ``-Wsign-compare``, ``-Wtype-limits``, ...

  * *lots* of warnings when mixing
  * consider ``-Wextra``

* |longrightarrow| *Correctness* (up to a certain extent)

**Find at least two Bugs!**

.. code-block:: c

   size_t sum(int set[], size_t size)
   {
       size_t sum = 0;
       while (size-- >= 0)
           sum += set[size];
       return sum;
   }
