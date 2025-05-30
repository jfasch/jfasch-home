.. include:: <mmlalias.txt>


Lazy Allocation, Demand Paging, And Overcommit
==============================================

.. contents::
   :local:

Lazy Allocation, And Overcommit
-------------------------------

.. list-table::
   :align: left
   :widths: 40, 60

   * * * Mappings are *unpopulated*, initially
       * Not backed by physical memory
       * |longrightarrow| MMU knows nothing
       * |longrightarrow| Error condition
       * Memory will be allocated at first access
       * |longrightarrow| *overcommit*: if all processes allocated
         memory for all of their mappings, the system would run out of
         memory
       * (generally, they don't)
     * :download:`drawings/libreoffice/lazy-alloc-unpopulated.odg`

..      * .. libreoffice:: drawings/libreoffice/lazy-alloc-unpopulated.odg
..           :align: center
..           :autocrop:

jjj libreoffice extension dead

Memory Access, And Allocation
-----------------------------

.. list-table::
   :align: left
   :widths: 40, 60

   * * * On first access, MMU knows nothing (no TLB entry)
       * |longrightarrow| "TLB miss"
       * Page table has nothing too
       * |longrightarrow| Process is *suspended*
       * Memory allocation starts
       * Might require disk IO |longrightarrow| could take a while
       * |longrightarrow| No-go if one has :doc:`realtime requirements
         <realtime>`

     * :download:`drawings/libreoffice/lazy-alloc-mmu-trap.odg`

jjj libreoffice extension dead

..      * .. libreoffice:: drawings/libreoffice/lazy-alloc-mmu-trap.odg
..           :align: center
..           :autocrop:

Finish: Setup Mapping, Kick Process Loose
-----------------------------------------

.. list-table::
   :align: left
   :widths: 40, 60

   * * * Finally, when allocation has taken place, page tables and TLB
         are updated
       * |longrightarrow| Process is runnable again
       * |longrightarrow| Subject to scheduling
     * :download:`drawings/libreoffice/lazy-alloc-allocated.odg`

jjj libreoffice extension dead

..      * .. libreoffice:: drawings/libreoffice/lazy-alloc-allocated.odg
..           :align: center
..           :autocrop:

Further Notes: TLB Misses, Memory Performance
---------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/c/100-performance/030-memory/topic`

TLB misses not only occur when a mapping is unpopulated

* TLB thrashing

  * TLB is of limited size |longrightarrow| cannot contain all
    possible address mappings of a process
  * |longrightarrow| Needs occasional updates from OS's page tables
  * Programmer's responsibility (see
    :doc:`/trainings/material/soup/c/100-performance/030-memory/topic`)

* Paging/swapping

  * The OS might have *paged out* memory to swap (running low on total
    memory?)
  * Technically, mapping is not unpopulated
  * Effect is even worse: guaranteed disk IO

Further Notes: Realtime
-----------------------

.. sidebar:: See also

   * :doc:`realtime`

* **Allocation may suspend a process in critical situations**
* |longrightarrow| Lazy allocation is not generally wanted in realtime
  situations
* Allocations must be done up-front
* *Not all allocations are explicit*

  * Program itself is loaded *on-demand* |longrightarrow| bad luck if
    a new code branch is taken at the wrong time
  * Stack memory is dynamically allocated, *on-demand*
  * Global variables are lazy-loaded too
  * ...
