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
* Close file (mapping already knows)
* ``PROT_READ``: memory protection *read only*
* ``MAP_PRIVATE``: private mapping

  * Pointless as we don't *write* to it, but we have to say something
  * *Copy on write* otherwise |longrightarrow| private to each address
    space (later)

* ``offset`` and ``length`` span entire file

  * ``offset`` must start at a page boundary. 4096 on many systems;
    determined exactly by ``sysconf(_SC_PAGE_SIZE)``

.. code-block:: console

   $ echo 0123456789 > /tmp/a-file
   $ ./file-mapping-ro /tmp/a-file
   0123456789

Writing: ``MAP_PRIVATE``, And Copy-On-Write (COW)
-------------------------------------------------

* Change ``PROT_READ`` to ``PROT_WRITE`` 
* *Note* how ``open()`` is left as-is - ``O_RDONLY``
* Touch one byte in mapping
* Look with ``cat`` |longrightarrow| no change
* Copy-On-Write (COW)
* |longrightarrow| this is why this works on a ``O_RDONLY`` file

.. literalinclude:: code/file-mapping-wr-private.cpp
   :caption: :download:`code/file-mapping-wr-private.cpp`
   :language: c++

Writing: ``MAP_SHARED`` - Make Changes Visible
----------------------------------------------

* Change ``MAP_PRIVATE`` to ``MAP_SHARED``
* Fails with ``EACCESS``
* |longrightarrow| change ``O_RDONLY`` to ``O_WRONLY``
* Still fails
* |longrightarrow| ``O_RDWR`` - mapping needs to be populated

.. literalinclude:: code/file-mapping-wr-shared.cpp
   :caption: :download:`code/file-mapping-wr-shared.cpp`
   :language: c++
