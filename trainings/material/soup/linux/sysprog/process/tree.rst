.. include:: <mmlalias.txt>


The Process Tree (And Environment, And ``procfs``)
==================================================

.. contents::
   :local:

Process ID (PID) And Parent Process ID (PPID)
---------------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/basics/intro/process-tree`

* Every process has an ID (PID ... Process ID)
* Every process but the first (PID 1) has a parent process)
* |longrightarrow| process tree

.. image:: /trainings/material/soup/linux/basics/intro/process-tree/process-tree.svg
   :scale: 40%

System Calls: ``getpid()``, ``getppid()``
-----------------------------------------

.. sidebar::

   **Documentation**

   * `man -s 2 getpid
     <https://man7.org/linux/man-pages/man2/getpid.2.html>`__
   * `man -s 2 getppid
     <https://man7.org/linux/man-pages/man2/getpid.2.html>`__

.. literalinclude:: tree.cpp
   :language: c++
   :caption: :download:`tree.cpp`

Environment Variables
---------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/basics/intro/environment`

   **Documentation**

   * `man -s 7 environ
     <https://man7.org/linux/man-pages/man7/environ.7.html>`__
   * `man -s 3 getenv
     <https://man7.org/linux/man-pages/man3/getenv.3.html>`__
   * `man -s 3 setenv
     <https://man7.org/linux/man-pages/man3/setenv.3.html>`__
   * `man -s 3 putenv
     <https://man7.org/linux/man-pages/man3/putenv.3.html>`__
   * `man -s 3 unsetenv
     <https://man7.org/linux/man-pages/man3/unsetenv.3.html>`__
   * `man -s 3 clearenv
     <https://man7.org/linux/man-pages/man3/clearenv.3.html>`__

.. literalinclude:: environ.cpp
   :language: c++
   :caption: :download:`environ.cpp`
