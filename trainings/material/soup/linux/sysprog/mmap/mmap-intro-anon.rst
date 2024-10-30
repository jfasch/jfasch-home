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

* Building the situation from :doc:`lazy-alloc` ...

  * Mapping (contents of it) not backed from anywhere (a file, say)
    |longrightarrow| *anonymous* mapping (``MAP_ANONYMOUS``)
  * Mapping is not visible in another address space/process
    |longrightarrow| *private* mapping (``MAP_PRIVATE``)
  * We want the allocated memory to be readble and writable
    |longrightarrow| ``PROT_READ|PROT_WRITE``

.. literalinclude:: code/mmap-anon.cpp
   :caption: :download:`mmap-anon.cpp <code/mmap-anon.cpp>`
   :language: c++

Demo: ``/proc/PID/maps``, ``/proc/PID/smaps``
---------------------------------------------

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
   *(((char*)memory)+16) = 'a';
   cin.get();
   ...
