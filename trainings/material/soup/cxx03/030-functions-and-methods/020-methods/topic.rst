.. ot-topic:: cxx03.functions_and_methods.methods
   :dependencies: cxx03.functions_and_methods.overloading

.. include:: <mmlalias.txt>


Methods
=======

.. contents::
   :local:

Objects - Data and Methods
--------------------------

**C**

* Object |DoubleLeftRightArrow| ``struct``
* Operations on objects: *free functions*
* |longrightarrow| can be defined anywhere

**C++**

* Classes: data and *methods*
* Methods: functions *bound* to objects

A Pointless Class: ``class point``
----------------------------------

* What is a point? |longrightarrow| ``x`` and ``y``
* What is the responsibility of a point?

  * move itself
  * compute its distance to origin
  * ... or from another point ...

.. literalinclude:: code/point.h
   :caption: :download:`code/point.h`
   :language: c++

Using ``class point``
---------------------

.. literalinclude:: code/c++03-methods.cpp
   :caption: :download:`code/c++03-methods.cpp`
   :language: c++

.. code-block:: console

   $ ./code/c++03-methods 
   distance of (3,4) from origin: 5
   distance of (3,4) from (4,4): 1

Methods: What's Coming?
-----------------------

.. sidebar::

   **See also**

   * :doc:`../030-const/topic`
   * :doc:`../050-references/topic`
   * :doc:`../060-static/topic`
   * :doc:`../070-operators/topic`

**Problems**

* ``double distance(point other)``: pass by copy
* ``void move(int x, int y)``: shouldn't that be the ``+=`` operator,
  only in 2D?
* Shouldn't

  .. code-block:: c++

     std::cout << "distance of (" << p.x() << ',' << p.y() << ") from origin: "  << d_orig << std::endl;

  be shorter?

  .. code-block:: c++

     std::cout << "distance of " << p << " from origin: "  << d_orig << std::endl;
