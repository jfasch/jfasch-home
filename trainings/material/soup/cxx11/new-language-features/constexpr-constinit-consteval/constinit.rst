.. include:: <mmlalias.txt>


``constinit``
=============

.. contents::
   :local:

Definition: Initialization Of Globals
-------------------------------------

* ``static`` locals

  * Initialized when program flow crosses initialization *the first
    time*

* Globals

  * Initialization in definition order per compilation unit
  * **Initialization order of compilation units is undefined**

* Since 1970-01-01: integrals are initialized at compile time

Problem: The *Static Initialization Order Fiasco*
-------------------------------------------------

.. sidebar:: Documentation

   * `Static Initialization Order Fiasco
     <https://en.cppreference.com/w/cpp/language/siof>`__

.. literalinclude:: code/siof/point.h
   :caption: :download:`code/siof/point.h`
   :language: c++

.. list-table:: 
   :align: left
   :widths: auto

   * * .. literalinclude:: code/siof/global-point-standalone.h
          :caption: :download:`code/siof/global-point-standalone.h`
	  :language: c++
     * .. literalinclude:: code/siof/global-point-standalone.cpp
          :caption: :download:`code/siof/global-point-standalone.cpp`
          :language: c++

.. list-table:: 
   :align: left
   :widths: auto

   * * .. literalinclude:: code/siof/global-point-depends.h
          :caption: :download:`code/siof/global-point-depends.h`
          :language: c++
     * .. literalinclude:: code/siof/global-point-depends.cpp 
          :caption: :download:`code/siof/global-point-depends.cpp`
          :language: c++

.. literalinclude:: code/siof/main.cpp
   :caption: :download:`code/siof/main.cpp`
   :language: c++

* Compile

.. code-block:: console

   $ g++ -c -o global-point-depends.o global-point-depends.cpp
   $ g++ -c -o global-point-standalone.o global-point-standalone.cpp
   $ g++ -c -o main.o main.cpp

* Link order wrong: "standalone" *after* "depends"

.. code-block:: console

   $ g++ main.o global-point-depends.o global-point-standalone.o
   $ ./a.out 
   global_point_standalone: (42,666)
   global_point_depends: (0,0)

* Link order wrong: "standalone" *before* "depends"

.. code-block:: console

   $ g++ main.o global-point-standalone.o global-point-depends.o
   $ ./a.out 
   global_point_standalone: (42,666)
   global_point_depends: (42,666)

Solution: ``constinit``
-----------------------



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


