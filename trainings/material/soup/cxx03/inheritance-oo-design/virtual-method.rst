.. include:: <mmlalias.txt>


Dynamic Dispatch: Virtual Methods
=================================

.. contents:: 
   :local:

.. sidebar:: See also

   From
   :doc:`/trainings/material/soup/cxx11/introduction/overview-livehacking-oo`

   * :ref:`cxx11-overview-inheritance-pointer-virtual`

Simple *Is-A* Relationship Is Not Enough
----------------------------------------

* If ``Sensor* s`` actually points to a ``MySensor`` object, why isn't
  ``MySensor::get_value()`` called?
* If ``MySensor`` *is-a* ``Sensor``, how do I *use it as-a*
  ``Sensor``?
* In other words: how to I use a ``Sensor*`` to call
  ``MySensor::get_value()``

Enter ``virtual``
-----------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/oo/override`

.. sidebar:: Documentation

   * `Type support (basic types, RTTI)
     <https://en.cppreference.com/w/cpp/types.html>`__

* Use ``virtual`` on those methods that need *dynamic dispatch*
* Through the ``Sensor*`` (which points to an object of derived type
  ``MySensor``), the actual *dynamic type* is determined
* |longrightarrow| Run Time Type Information (RTTI)
* **Question**: why isn't that the default?
* **Answer**: performance |longrightarrow| *indirect function call*
  cannot be default

.. literalinclude:: code/virtual-rudimentary/sensors.h
   :caption: :download:`code/virtual-rudimentary/sensors.h`
   :language: c++

Virtual Methods: Effects
------------------------

* Note how ``MySensor::get_value()`` is called *through the base
  pointer*

.. literalinclude:: code/virtual-rudimentary/main.cpp
   :caption: :download:`code/virtual-rudimentary/main.cpp`
   :language: c++

.. code-block:: console

   $ ./code/virtual-rudimentary/cxx-inher-oo-virtual-rudimentary 
   Sensor::get_value(): 37.3
   MySensor::get_value(): 37.55
   37.55


Virtual Methods: Where *Not* To Place ``virtual``
-------------------------------------------------

* C++ lets you complete freedom
* ``virtual`` is just a mechanism to achieve *dynamic dispatch*
* |longrightarrow| no policy!
* *If you want to use* ``Base*`` *polymorphically, this is the place
  where* ``virtual`` *is written*

**Attention**

* ``virtual`` has to come at *dynamic dispatch* entry point!

.. literalinclude:: code/virtual-wrong/sensors.h
   :caption: :download:`code/virtual-wrong/sensors.h`
   :language: c++

.. literalinclude:: code/virtual-wrong/main.cpp
   :caption: :download:`code/virtual-wrong/main.cpp`
   :language: c++

.. code-block:: console

   $ ./code/virtual-wrong/cxx-inher-oo-virtual-wrong 
   Sensor::get_value(): 37.3
   37.3

``override``: Problem
---------------------

* Common mistake in pre C++11: misspelled method signatures
* E.g. ``double get_value() const`` and ``double get_value()`` are
  *different methods*
* |longrightarrow| Base method not *overridden*!

.. literalinclude:: code/virtual-override-problem/sensors.h
   :caption: :download:`code/virtual-override-problem/sensors.h`
   :language: c++

.. literalinclude:: code/virtual-override-problem/main.cpp
   :caption: :download:`code/virtual-override-problem/main.cpp`
   :language: c++

.. code-block:: console

   $ ./code/virtual-override-problem/cxx-inher-oo-virtual-override-problem 
   Sensor::get_value(): 37.3
   37.3

``override``: Solution
----------------------

* ``override``, placed at the overriding method in
  the derived classes
* Compiler then checks if something is overridden
* Rules

  * ``virtual`` at the topmost definition (dynamic dispatch entry
    point)
  * ``override`` at every method that overrides/re-implements the base
    method

* Note that ``override`` implies ``virtual``, so ``virtual`` is not
  specified together with ``override``

.. literalinclude:: code/virtual-override-solution/sensors.h
   :caption: :download:`code/virtual-override-solution/sensors.h`
   :language: c++

.. literalinclude:: code/virtual-override-solution/main.cpp
   :caption: :download:`code/virtual-override-solution/main.cpp`
   :language: c++

.. code-block:: console

   $ ./code/virtual-override-solution/cxx-inher-oo-virtual-override-solution 
   Sensor::get_value(): 37.3
   MySensor::get_value(): 37.55
   37.55
