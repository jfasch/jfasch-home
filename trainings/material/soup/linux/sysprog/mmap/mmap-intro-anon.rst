.. include:: <mmlalias.txt>


Introduction To ``mmap()``: Anonymous Memory
============================================

.. contents::
   :local:

``mmap()``: An Anonymous (Private) Mapping
------------------------------------------

.. sidebar:: See also

   * :doc:`lazy-alloc`

.. sidebar:: Documentation

   * `man -s 2 mmap
     <https://man7.org/linux/man-pages/man2/mmap.2.html>`__

Building the situation from :doc:`lazy-alloc` ...

* Mapping (contents of it) not backed from anywhere (a file, say)
  |longrightarrow| *anonymous* mapping (``MAP_ANONYMOUS``)
* We want the allocated memory to be readable and writable
  |longrightarrow| ``PROT_READ|PROT_WRITE``
* Mapping is not shared with another address space/process
  |longrightarrow| *private* mapping (``MAP_PRIVATE``)

  If already backed by physical memory, that memory is shared. A copy
  is made if one party *writes* to it |longrightarrow| Copy-On-Write
  (COW). See :doc:`fork`

.. literalinclude:: code/mmap-anon.cpp
   :caption: :download:`mmap-anon.cpp <code/mmap-anon.cpp>`
   :language: c++

Step By Step: From Unpopulated To Populated
-------------------------------------------

.. sidebar:: Documentation

   * `man -s 5 proc
     <https://man7.org/linux/man-pages/man5/proc.5.html>`__
   * `man -s 2 getpid
     <https://man7.org/linux/man-pages/man2/getpid.2.html>`__

* Modify above program to ...

  * output its PID
  * wait before and after memory access

.. code-block:: c++
   :caption: :download:`mmap-anon-interactive.cpp <code/mmap-anon-interactive.cpp>`
   
   cout << getpid() << '\n';
   ...
   cin.get();
   *(((char*)memory)+16) = 'a';                       // <-- memory access in first page of mapping
                                                      //     will cause page to be allocated
   cin.get();
   ...

.. code-block:: console

   $ ./code/mmap-anon-interactive 
   216234
 
Unpopulated Mapping: ``/proc/PID/maps``, ``/proc/PID/smaps``
------------------------------------------------------------

.. sidebar:: Documentation

   * `man -s 5 proc
     <https://man7.org/linux/man-pages/man5/proc.5.html>`__

* Peek into ``/proc/PID/maps``
* Talk about program loading (mappings with a program file, or a
  shared library) |longrightarrow| later
* Find our mapping (16 MiB)

.. code-block:: console

   $ cat /proc/216234/maps 
   ...
   7f1571c00000-7f1572c00000 rw-p 00000000 00:00 0 
   ...

* Is that mapping populated?
* |longrightarrow| Peek into ``/proc/PID/smaps`` (contains much more
  information)
* Search for ``7f1571c00000-7f1572c00000`` (or whatever ``maps``
  shows)
* ``Rss`` (from `man -s 5 proc
  <https://man7.org/linux/man-pages/man5/proc.5.html>`__): 0 bytes
  *allocated* from that mapping

.. code-block:: console

   $ less /proc/216234/smaps
   ...
   7f1571c00000-7f1572c00000 rw-p 00000000 00:00 0 
   Size:              16384 kB
   KernelPageSize:        4 kB
   MMUPageSize:           4 kB
   Rss:                   0 kB                            # <-- not allocated
   Pss:                   0 kB
   Pss_Dirty:             0 kB
   Shared_Clean:          0 kB
   Shared_Dirty:          0 kB
   Private_Clean:         0 kB
   Private_Dirty:         0 kB
   Referenced:            0 kB
   Anonymous:             0 kB
   KSM:                   0 kB
   LazyFree:              0 kB
   AnonHugePages:         0 kB
   ShmemPmdMapped:        0 kB
   FilePmdMapped:         0 kB
   Shared_Hugetlb:        0 kB
   Private_Hugetlb:       0 kB
   Swap:                  0 kB
   SwapPss:               0 kB
   Locked:                0 kB
   THPeligible:           0
   ProtectionKey:         0
   VmFlags: rd wr mr mw me ac sd 
   ...

Lazy Allocation, And ``Rss``
----------------------------

* Hit return to write one byte
* |longrightarrow| Et voila: one page allocated (the one containing
  the byte)

.. code-block:: console

   $ less /proc/216234/smaps
   ...
   7f1571c00000-7f1572c00000 rw-p 00000000 00:00 0 
   Size:              16384 kB
   KernelPageSize:        4 kB
   MMUPageSize:           4 kB
   Rss:                   4 kB                            # <-- one page allocated
   ...
