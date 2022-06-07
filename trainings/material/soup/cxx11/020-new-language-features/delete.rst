.. include:: <mmlalias.txt>

.. ot-topic:: cxx11.new_language_features.delete


``= delete``
============

.. contents::
   :local:

.. sidebar:: 

   **Documentation**

   * `= delete
     <https://en.cppreference.com/w/cpp/language/function#Deleted_functions>`__

Problem: Copy Is Not Always Wanted
----------------------------------

A class that owns memory, for example ...

* Compiler generated default copy is buggy (only assigns pointer
  member)
* All sorts of memory errors

  * Double free
  * Segmentation violation
  * ...

.. literalinclude:: code/c++11-delete-bogus-copy.cpp
   :caption: :download:`code/c++11-delete-bogus-copy.cpp`
   :language: c++

.. code-block:: console

   $ ./code/c++11-delete-bogus-copy 
   free(): double free detected in tcache 2
   Aborted (core dumped)

C++ < 11 Solution: Make Copy ``private``
----------------------------------------

Make those private (no implementation necessary)

* Copy constructor
* Assignment operator

|longrightarrow| Problem

* Weird way of *inhibiting* bugs
* Everyone has to know that idiom to understand what the compiler says

.. literalinclude:: code/c++11-delete-private-copy.cpp
   :caption: :download:`code/c++11-delete-private-copy.cpp`
   :language: c++

.. code-block:: console

   code/c++11-delete-private-copy.cpp:17:26: error: ‘OwnsMemory::OwnsMemory(const OwnsMemory&)’ is private within this context
      17 |     OwnsMemory om_copy = om;
         |                          ^~
   code/c++11-delete-private-copy.cpp:10:5: note: declared private here
      10 |     OwnsMemory(const OwnsMemory&);
         |     ^~~~~~~~~~

C++ >= 11 Solution: ``= delete`` Copy
-------------------------------------

.. literalinclude:: code/c++11-delete-delete-copy.cpp
   :caption: :download:`code/c++11-delete-delete-copy.cpp`
   :language: c++

.. code-block:: console

   code/c++11-delete-delete-copy.cpp:17:26: error: use of deleted function ‘OwnsMemory::OwnsMemory(const OwnsMemory&)’
      17 |     OwnsMemory om_copy = om;
         |                          ^~
   code/c++11-delete-delete-copy.cpp:7:5: note: declared here
       7 |     OwnsMemory(const OwnsMemory&) = delete;
         |     ^~~~~~~~~~
