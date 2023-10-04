.. ot-topic:: cxx03.inheritance_oo.virtual_method
   :dependencies: cxx03.inheritance_oo.basics

.. include:: <mmlalias.txt>


Virtual Methods
===============

.. contents:: 
   :local:

Simple *Is-A* Relationship Is Not Enough
----------------------------------------

.. literalinclude:: code/inher-oo-derived-novirtual-base-usage.cpp
   :caption: :download:`code/inher-oo-derived-novirtual-base-usage.cpp`
   :language: c++

.. code-block:: console

   $ ./inher-oo-derived-novirtual-base-usage 
   Base::method()

**Questions**

* If ``Base* b`` actually points to a ``Derived`` object, why isn't
  ``Derived::method()`` called?
* If ``Derived`` *is-a* ``Base``, how do I *use it as-a* ``Base``?
* In other words: how to I use a ``Base*`` to call
  ``Derived::method()``

**Usage Scenario**

* Consider a system that uses thermometers to measure temperature
* There are a million of different thermometers out there that can
  answer me that question: *what's the temperature?*
* In software, I don't want to care

  * **I only want to know the temperature**
  * **I don't want to expose the physics of thermometers to my
    system**

Enter ``virtual``
-----------------

**Answer**

* Use ``virtual`` on those methods that need *dynamic dispatch*
* |longrightarrow| through the ``Base*``, the actual *dynamic type* is
  determined

.. literalinclude:: code/inher-oo-derived-virtual-base-usage.cpp
   :caption: :download:`code/inher-oo-derived-virtual-base-usage.cpp`
   :language: c++

.. code-block:: console

   $ ./inher-oo-derived-virtual-base-usage 
   Derived::method()

**Question**

* Why isn't that the default?

**Answer**

* Performance |longrightarrow| *indirect function call* cannot be
  default

Caution: ``virtual``
--------------------

* C++ lets you complete freedom
* ``virtual`` is just a mechanism to achieve *dynamic dispatch*
* |longrightarrow| no policy!
* *If you want to use* ``Base*`` *polymorphically, this is the place
  where* ``virtual`` *is written*

**Wrong**

* ``virtual`` has to come at *dynamic dispatch* entry point!

.. literalinclude:: code/inher-oo-derived-virtual-base-usage-wrong.cpp
   :caption: :download:`code/inher-oo-derived-virtual-base-usage-wrong.cpp`
   :language: c++

.. code-block:: console

   $ ./inher-oo-derived-virtual-base-usage-wrong 
   Base::method()

**Obscure but correct**

* ``virtual`` at *dynamic dispatch* entry point is sufficient
* |longrightarrow| propagates down the line
* Not quite readable though

.. literalinclude:: code/inher-oo-derived-virtual-base-usage-obscure.cpp
   :caption: :download:`code/inher-oo-derived-virtual-base-usage-obscure.cpp`
   :language: c++

.. code-block:: console

   $ ./inher-oo-derived-virtual-base-usage-obscure 
   Derived::method()
