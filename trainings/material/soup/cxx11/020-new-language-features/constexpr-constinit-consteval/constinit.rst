.. include:: <mmlalias.txt>


``constinit``
=============

.. contents::
   :local:

Definition, And Usage
---------------------

* Used to initialize variables (and only those) that have *program
  lifetime*: ``static`` local, and global
* ``static`` local: initialized when program flow crosses
  initialization *the first time*
* (Except integral which is initialized at compile time)

The Problem
-----------

.. sidebar:: Documentation

   * `std::mutex::mutex()
     <https://en.cppreference.com/w/cpp/thread/mutex/mutex>`__

* ``std::mutex`` is initialized at runtime
* ``unsigned`` is initialized at compiletime (integral)
* |longrightarrow| *this is asymmetric*
* *Want ``std::mutex`` to be initialized at compiletime!*
* This should be possible because it has a ``constexpr`` default
  constructor

.. literalinclude:: code/constinit-problem.cpp
   :caption: :download:`code/constinit-problem.cpp`
   :language: c++

Possible Solutions?
-------------------

* Make ``sequence_lock`` a ``constexpr`` object

  * **No:** ``lock()`` and ``unlock()`` are not ``const``

* Live with runtime initialization

  * **No:** I am programming a tiny embedded microcontroller and
    cannot afford any additional startup time
  * **No:** I have had enough of C++'s `Static Initialization Order
    Fiasco <https://en.cppreference.com/w/cpp/language/siof>`__

* ``constinit``

  * **Yay**

Solution: ``constinit``
-----------------------

.. literalinclude:: code/constinit-solution.cpp
   :caption: :download:`code/constinit-solution.cpp`
   :language: c++


