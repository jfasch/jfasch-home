.. ot-topic:: sysprog.fileio.output

.. include:: <mmlalias.txt>


Writing Files
=============

.. topic:: Documentation

   * `man -s 2 open
     <https://man7.org/linux/man-pages/man2/open.2.html>`__
   * `man -s 2 write
     <https://man7.org/linux/man-pages/man2/write.2.html>`__

.. code-block:: c
   
   #include <fcntl.h>
   int open(const char *pathname, int flags);

.. code-block:: c
   
   #include <unistd.h>
   ssize_t write(int fd, const void buf[.count], size_t count);

``open()`` File For Writing
---------------------------

.. topic:: Documentation

   * `man -s 2 open
     <https://man7.org/linux/man-pages/man2/open.2.html>`__

* ``flags`` contains ``O_WRONLY`` (or ``O_RDWR`` for that matter)
* *The file will be overwritten starting a position 0* - unless
  ``flags`` also contains ``O_APPEND`` (see
  :ref:`sysprog-fileio-file-output-append`,
* File must exist
* ``mode`` is necessary when ``O_CREAT`` (and possibly ``O_EXCL``) is
  used (but see :doc:`../create/index` for more)

.. literalinclude:: code/open-writeonly.cpp
   :caption: :download:`code/open-writeonly.cpp`
   :language: c++

Write One Block Of Bytes
------------------------

.. topic:: Documentation

   * `man -s 2 write
     <https://man7.org/linux/man-pages/man2/write.2.html>`__

   .. code-block:: c
   
      #include <unistd.h>
      ssize_t write(int fd, const void buf[.count], size_t count);

* Write 16 bytes (here we add a linefeed character for demonstration
  purposes)
* Show how existing content is overwritten

.. literalinclude:: code/write-one-block.cpp
   :caption: :download:`code/write-one-block.cpp`
   :language: c++

Write Multiple Blocks Of Bytes
------------------------------

* Demonstrate how file position advances by number of bytes written

.. literalinclude:: code/write-two-blocks.cpp
   :caption: :download:`code/write-two-blocks.cpp`
   :language: c++

.. _sysprog-fileio-file-output-append:

Appending To An Existing File
-----------------------------

* ``flags`` contains ``O_APPEND``

.. literalinclude:: code/append.cpp
   :caption: :download:`code/append.cpp`
   :language: c++

Error Conditions
----------------

Use ``argv[1]`` like in :doc:`../file-input/index`, and ...

* Show "permission denied" (``EACCESS``)
* Show "does not exist" (``EEXIST``)
