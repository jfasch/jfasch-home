.. include:: <mmlalias.txt>


Introduction
============

.. contents::
   :local:

Problems With Pointers
----------------------

**Most prominent pointer (memory management) related bugs**

* Memory leak
* Double free

**Even more so with exceptions**

* Alternate return path
* Requires extra handling for resource cleanup

Problem: Expecting Ownership Tranfer, But Ownership Not Taken |longrightarrow| Memory Leak
------------------------------------------------------------------------------------------

.. literalinclude:: code/expect-ownership-xfer-but-no/f.cpp
   :language: c++

Problem: Not Expecting Ownership Transfer, But Ownership Taken |longrightarrow| Double Free
-------------------------------------------------------------------------------------------

.. literalinclude:: code/no-expect-ownership-xfer-but-yes/f.cpp
   :language: c++

Problem: Early Return |longrightarrow| Memory Leak
--------------------------------------------------

.. literalinclude:: code/leak-early-return/f.cpp
   :language: c++

Problem: Exception |longrightarrow| Memory Leak
-----------------------------------------------

.. literalinclude:: code/leak-exception/f.cpp
   :language: c++

Solution: Pointer Classes
-------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/070-operators/topic`
   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-dtor`

What if pointers could be *objects*?

* Destructor called on ``return`` statements
* Destructor called on exception
* |longrightarrow| no leaks

Two pointer classes available

* :doc:`../unique-ptr/topic`
* :doc:`../sharedptr`
