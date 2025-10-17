.. ot-topic:: sysprog.syscalls.errorhandling

.. include:: <mmlalias.txt>


``errno``, And Error Handling
=============================

.. topic:: See also

   * :doc:`../overview/index`

.. topic:: Documentation

   * `man -s 3 errno
     <https://man7.org/linux/man-pages/man3/errno.3.html>`__

``errno`` Is A *Global* Variable
--------------------------------

* ``errno`` is *global*, with all consequences
* Should read it immediately after something went wrong

.. literalinclude:: code/errno-is-global.cpp
   :language: c++
   :caption: :download:`code/errno-is-global.cpp`

Simplest Stringification: ``perror()``
--------------------------------------

.. topic:: Documentation

   * `man -s 3 perror
     <https://man7.org/linux/man-pages/man3/perror.3.html>`__

* Advantage: need not mention ``errno``
* Writes human-readable description of ``errno`` to standard error
* Value of ``errno`` not printed though

.. literalinclude:: code/perror.cpp
   :language: c++
   :caption: :download:`code/perror.cpp`

.. code-block:: console

   $ ./sysprog-errors--perror 
   open failed: Permission denied

More Stringification: ``strerror()``
------------------------------------

.. topic:: Documentation

   * `man -s 3 strerror
     <https://man7.org/linux/man-pages/man3/strerror.3.html>`__

* Returns a pointer to a descriptive string
* Does not print anything itself
* *Not thread-safe*: pointer might be invalidated by subsequent calls
  to ``strerror()``
* Historical baggage: return type is ``char*`` - but *please* don't
  write to it

.. literalinclude:: code/strerror.cpp
   :language: c++
   :caption: :download:`code/strerror.cpp`

.. code-block:: console

   $ ./sysprog-errors--strerror 
   open failed: Permission denied (13)

Thread-Safe Stringification: ``strerror_r()``
---------------------------------------------

.. topic:: Documentation

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
