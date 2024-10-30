.. include:: <mmlalias.txt>


Virtual Memory: Big Picture
===========================

.. contents::
   :local:

Big Picture
-----------

.. libreoffice:: drawings/libreoffice/virtual-memory-basics.odg

Terms
-----

* **MMU**: Memory Management Unit; sits between CPU and cache/physical
  memory
* **TLB**: Translation Lookaside Buffer, used by the OS to communicate
  address translations to the MMU
* **Kernel Page Tables** (not shown): used by the kernel to keep track
  of a process's allocations - TLB is set up from page tables
* **Virtual Memory**: idealized view of memory as seen by a process
* **Physical Memory**: real RAM, as allocated to processes (and kernel
  itself, of course).

Facts
-----

.. sidebar:: Documentation

   * `sysconf(_SC_PAGESIZE)
     <https://man7.org/linux/man-pages/man3/sysconf.3.html>`__

* Memory is managed in units of pages (4K on most architectures, but
  see `sysconf(_SC_PAGESIZE)
  <https://man7.org/linux/man-pages/man3/sysconf.3.html>`__)
* Physical memory becomes fragmented over time |longrightarrow|
  contiguous allocations beyond page size generally impossible

  * This is only relevant for the kernel, as userspace *cannot*
    allocate physical memory - this is what virtual memory has been
    made for

