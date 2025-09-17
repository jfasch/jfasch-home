.. include:: <mmlalias.txt>


Error Handling
==============

.. contents::
   :local:

The ``errno`` Variable
----------------------

.. sidebar:: Documentation

   * `man -s 3 errno
     <https://man7.org/linux/man-pages/man3/errno.3.html>`__

On error, system calls (and most C library functions) 

* return -1
* set the *global* variable ``errno``

.. literalinclude:: code/return-and-errno.cpp
   :language: c++
   :caption: :download:`code/return-and-errno.cpp`

.. code-block:: console

   $ ./sysprog-errors--return-and-errno 
   open failed, errno==13

``errno`` Is A *Global* Variable
--------------------------------

* ``errno`` is global, with all consequences
* Should read it immediately after failed syscall

.. literalinclude:: code/errno-is-global.cpp
   :language: c++
   :caption: :download:`code/errno-is-global.cpp`

Simplest Stringification: ``perror()``
--------------------------------------

.. sidebar:: Documentation

   * `man -s 3 perror
     <https://man7.org/linux/man-pages/man3/perror.3.html>`__

* Advantage: need not mention ``errno``
* Translates ``errno`` into a descriptive string
* Value of ``errno`` not printed though

.. literalinclude:: code/perror.cpp
   :language: c++
   :caption: :download:`code/perror.cpp`

.. code-block:: console

   $ ./sysprog-errors--perror 
   open failed: Permission denied

More Stringification: ``strerror()``
------------------------------------

.. sidebar:: Documentation

   * `man -s 3 strerror
     <https://man7.org/linux/man-pages/man3/strerror.3.html>`__

* Returns a pointer to a descriptive string
* Does not print anything itself
* *Not thread-safe*: pointer might be invalidated by subsequent calls
  to ``strerror()``

.. literalinclude:: code/strerror.cpp
   :language: c++
   :caption: :download:`code/strerror.cpp`

.. code-block:: console

   $ ./sysprog-errors--strerror 
   open failed: Permission denied (13)

Thread-Safe Stringification: ``strerror_r()``
---------------------------------------------

.. sidebar:: Documentation

   * `man -s 3 strerror_r
     <https://man7.org/linux/man-pages/man3/strerror.3.html>`__

* ``_r`` for "reentrant"
* User has to supply buffer
* Buffer *might* be used by ``strerror_r()``
* Message might be truncated if buffer too small; always 0-terminated

.. literalinclude:: code/strerror_r.cpp
   :language: c++
   :caption: :download:`code/strerror_r.cpp`

.. code-block:: console

   $ ./sysprog-errors--strerror_r 
   open failed: Permission denied (13)
