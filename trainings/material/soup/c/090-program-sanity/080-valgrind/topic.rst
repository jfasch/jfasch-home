.. include:: <mmlalias.txt>

.. jf-topic:: c.program_sanity.valgrind
   :dependencies: c.program_sanity.explicit_type_safety

``valgrind``
============

Valgrind
--------

**Valgrind: debugging at its best** (because it is so simple)

* Main target: memory errors
* Writing and reading beyond array bounds
* Usage of uninitialized memory
* Double ``free``/``delete``
* Memory leaks
  
**Drawback:** considerable execution slowdown |longrightarrow|

* Race conditions not easily debugged
* Multithreading is hard generally
* Larger programs are not easily emulated |longrightarrow| smaller
  test suites that are regularly checked with ``valgrind``

Valgrind in Action (1)
----------------------

.. Material/C-Advanced/Code/valgrind/off-by-one.c
.. Material/C-Advanced/Code/valgrind/segfault.c

**There are bugs that cannot be found because they ...**

* *almost* never occur
* *almost* never are visible
* Cannot be reproduced in tests programs
* ...

**Find the Bug!**

.. code-block:: c

   #include <stdlib.h>
   void main(void)
   {
       char *bug = malloc(64);
       bug[64] = '\0';
   }

Valgrind in Action (2)
----------------------

``valgrind`` **at Bug Search**

.. code-block:: console

   $ valgrind ./a.out 
   ...
   Invalid write of size 1
      at 0x400552: main (array-bounds-write.c:5)
    Address 0x51bb072 is 0 bytes after a block of size 50
      at 0x4C28C6D: malloc (vg_replace_malloc.c:236)
      by 0x400545: main (array-bounds-write.c:4)
   ...

Valgrind in Action (3)
----------------------

**Memory leak**

.. code-block:: console

   $ valgrind --leak-check=full ./a.out 
   ...
   50 bytes in 1 blocks are definitely lost in loss rec..
      at 0x4C28C6D: malloc (vg_replace_malloc.c:236)
      by 0x400545: main (array-bounds-write.c:4)
   ...

|longrightarrow| *very* helpful!

Valgrind: more ...
------------------

**Uncovers many more types of errors:**

* Usage of uninitialized variables
* \textit{De}allocation errors (\texttt{free}/\texttt{delete}/\texttt{delete[]})
* Erroneous system call usage
* ...

**More information:**

* `Valgrind homepage <https://valgrind.org>`__

