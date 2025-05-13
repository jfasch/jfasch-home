.. include:: <mmlalias.txt>


Dynamic Memory
==============

Stack and Global Memory
-----------------------

**Stack**

* One *stack frame* per function call
* Local variables live there
* |longrightarrow| *Lifetime* is the duration of the function call

**Global memory**

* Global Variables
* "Allocated" at program start
* Lifetime: entire program

**What's in between?** |longrightarrow| *explicit* lifetime

Dynamic Memory
--------------

.. list-table::
   :align: left

   * * **Heap memory**

       * *Not* part of the core language
       * |longrightarrow| implemented in the *C library*
       * Lifetime is managed by the programmer

         * *Allocation*
         * *Deallocation*

       * See `manual page
         <https://man7.org/linux/man-pages/man3/malloc.3.html>`__

     * .. code-block:: c

          #include <stdlib.h>
          
          void *malloc(size_t size);
          void free(void *ptr);

Dynamic Memory - Usage
----------------------

.. code-block:: c

   struct point *p = malloc(sizeof(struct point));
   do_something_with(p);
   ...
   free(p);

**New traps:** as always, there is no checking done (as always, this
is for performance reasons)

* *Memory leak*: forget to ``free()`` allocated memory
* ``free()`` a pointer that does not point to dynamically allocated
  memory
* ``free()`` a pointer that has already been deallocated
