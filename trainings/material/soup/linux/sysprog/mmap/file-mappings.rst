.. include:: <mmlalias.txt>


``mmap``: File Mappings, Basics
===============================

.. contents::
   :local:

Reading A File, Not Using File I/O
----------------------------------

.. sidebar:: See also

   * :doc:`../file-io/group`

.. sidebar:: Documentation

   * `man -s 2 mmap
     <https://man7.org/linux/man-pages/man2/mmap.2.html>`__
   * `man -s 3 sysconf
     <https://man7.org/linux/man-pages/man3/sysconf.3.html>`__

.. literalinclude:: code/file-mapping-ro.cpp
   :caption: :download:`code/file-mapping-ro.cpp`
   :language: c++

* Open file ``O_RDONLY``
* Create mapping
* ``PROT_READ``: memory protection *read only*
* ``MAP_PRIVATE``: private mapping

  * pointless as we don't *write* to it, but we have to say something
  * *Copy on write* otherwise |longrightarrow| private to each address
    space (later)

* ``offset`` and ``length`` span entire file

  * ``offset`` must start at a page boundary. 4096 on many systems;
    determined exactly by ``sysconf(_SC_PAGE_SIZE)``

.. code-block:: console

   $ echo 0123456789 > /tmp/a-file
   $ ./file-mapping-ro /tmp/a-file
   0123456789

Read-Only, Basic
----------------

* file ro
* map ro, private
* error MAP_FAILED

Wait, /proc/PID/maps
--------------------

Error Cases
-----------

* file ro, map rw
* file ro, map ro, write byte -> segfault
* file rw, map ro, write byte -> segfault
* read beyond eof
* offset not multiple of pagae size
