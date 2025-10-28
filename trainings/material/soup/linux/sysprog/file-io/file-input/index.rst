.. ot-topic:: sysprog.fileio.input

.. include:: <mmlalias.txt>


Reading Files
=============

.. topic:: Documentation

   * `man -s 2 open
     <https://man7.org/linux/man-pages/man2/open.2.html>`__
   * `man -s 2 read
     <https://man7.org/linux/man-pages/man2/read.2.html>`__

.. code-block:: c

   #include <fcntl.h>
   int open(const char *pathname, int flags);

.. code-block:: c

   #include <unistd.h>
   ssize_t read(int fd, void buf[.count], size_t count);

``open()`` File For Reading
---------------------------

.. topic:: Documentation

   * `man -s 2 open
     <https://man7.org/linux/man-pages/man2/open.2.html>`__

   .. code-block:: c
   
      #include <fcntl.h>
      int open(const char *pathname, int flags);

* Simplest case
* Only ``flags`` needed: ``O_RDONLY`` (or ``O_RDWR`` if writing is
  also intended)
* Third parameter (``mode``) ignored (see :doc:`../create/index`)

.. literalinclude:: code/open-readonly.cpp
   :caption: :download:`code/open-readonly.cpp`
   :language: c++

Demo: Read One Block Of Bytes
-----------------------------

.. topic:: Documentation

   * `man -s 2 read
     <https://man7.org/linux/man-pages/man2/read.2.html>`__

   .. code-block:: c
   
      #include <unistd.h>
      ssize_t read(int fd, void buf[.count], size_t count);

* Read first 16 bytes of file
* Write them to standard output, just to do something meaningful with
  what we just read

.. literalinclude:: code/read-one-block.cpp
   :caption: :download:`code/read-one-block.cpp`
   :language: c++

.. code-block:: console

   $ strace ./sysprog-fileio-read-one-block 
   ...
   openat(AT_FDCWD, "/etc/passwd", O_RDONLY) = 3
   read(3, "root:x:0:0:Super", 16)         = 16
   write(1, "root:x:0:0:Super", 16root:x:0:0:Super)        = 16
   close(3)                                = 0
   ...

.. _sysprog-fileio-eof:

Demo: Read Until *End-Of-File*
------------------------------

* *End-of-file*: there won't be any input anymore (file is exhausted)
* Reached when ``read()`` returns *0 bytes*
* |longrightarrow| usually used to end some loop

.. literalinclude:: code/read-until-eof.cpp
   :caption: :download:`code/read-until-eof.cpp`
   :language: c++

Questions
---------

* How does ``read()`` know where a previous ``read()`` left off?

  See :doc:`../file-descriptors/index`

  .. image:: ../file-descriptors/file-descriptor.svg
     :scale: 40%
  
* Error conditions. Modify program to open ``argv[1]`` and ...

  * Show "permission denied" (``EACCESS``)
  * Show "does not exist" (``EEXIST``)
