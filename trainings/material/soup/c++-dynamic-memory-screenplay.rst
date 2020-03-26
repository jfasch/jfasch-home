Screenplay: C++: Dynamic Memory
===============================

.. sidebar:: Contents

   .. contents::
      :local:

   **Code**: :doc:`c++-dynamic-memory-code/index`

C: ``malloc()``/``free()``
--------------------------

.. code-block:: c++

   TEST(MallocFree, ArrayOfInteger)
   {
       int* ip = (int*)malloc(28*sizeof(int));
       ip[0] = 42;
       ip[27] = 7;
       free(ip);
   }

**Discussion**

* ``man malloc``

  .. code-block:: c

     void *malloc(size_t size);

* ``void*``
* C++ does not permit implicit conversion (which is good). Fix with
  cast.

``valgrind``: Memory Leak
.........................

.. note::

   Make sure :ref:`debug build <cmake-debug-build>` is enabled.

.. code-block:: c++

   TEST(Bug, MemoryLeak)
   {
       int* ip = (int*)malloc(sizeof(int));
   }

.. code-block:: console

   $ valgrind ./c++-dynamic-memory 

.. code-block:: console

   $ valgrind --leak-check=full ./c++-dynamic-memory 

``valgrind``: Array Bounds Write
................................

.. code-block:: c++

   TEST(Bug, ArrayBoundsWrite)
   {
       int* ip = (int*)malloc(28*sizeof(int));
       ip[0] = 42;
       ip[27] = 7;
       ip[28] = 666;
       free(ip);
   }

.. code-block:: console

   $ valgrind ./c++-dynamic-memory Bug.ArrayBoundsWrite

C++: ``new``, ``delete``
------------------------

.. code-block:: c++

   TEST(NewDelete, SingleInteger)
   {
       int* ip = new int;
       *ip = 666;
       delete ip;
   }

**Discussion**

* ``new`` is typed
* ``valgrind``: leaks and bounds write/read detected just as well

C++: ``new``, ``delete`` on Arrays
----------------------------------

.. code-block:: c++

   TEST(NewDelete, ArrayOfInteger)
   {
       int* ip = new int[28];
       ip[0] = 42;
       ip[27] = 7;
       delete[] ip;
   }

**Discussion**

* *Array delete!*

``valgrind``: ``delete`` Mismatch
.................................

.. code-block:: c++

   TEST(Bug, DeleteMismatch)
   {
       int* ip = new int[28];
       delete ip;
   }

.. code-block:: console

   $ valgrind ./c++-dynamic-memory Bug.DeleteMismatch
