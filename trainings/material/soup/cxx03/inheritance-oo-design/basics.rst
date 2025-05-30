.. include:: <mmlalias.txt>


Inheritance Basics
==================

.. contents::
   :local:

.. sidebar:: See also

   From
   :doc:`/trainings/material/soup/cxx11/introduction/overview-livehacking-oo`

   * :ref:`cxx11-overview-inheritance`
   * :ref:`cxx11-overview-inheritance-slicing`
   * :ref:`cxx11-overview-inheritance-pointer-conversion`

Plain (Base) Class
------------------

* A plain class ``Sensor`` with a ``get_value()`` method
* No surprise

.. plantuml::
   :width: 100%
   :align: left

   @startuml

   class Sensor {
     + double get_value()
   }
   note left of Sensor::get_value
      Implemented somehow
   end note   

   @enduml

.. .. image:: uml-base.jpg


.. literalinclude:: code/base.cpp
   :caption: :download:`code/base.cpp`
   :language: c++

.. code-block:: console

   $ ./cxx-inher-oo-base 
   Sensor::get_value()
   got value 36.5

Inheriting (Deriving) From Base
-------------------------------

.. note::

   Here we use only ``public`` inheritance. See
   :doc:`private-protected` for more.

.. plantuml::
   :width: 100%
   :align: left

   @startuml

   class Sensor {
     + double get_value()
   }

   class MySensor {
     + double get_value()
   }

   Sensor <|-- MySensor

   @enduml

.. .. image:: uml-derived.jpg

.. literalinclude:: code/derived.cpp
   :caption: :download:`code/derived.cpp`
   :language: c++

.. code-block:: console

   $ ./cxx-inher-oo-derived 
   Sensor::get_value()
   Sensor value: 36.5
   MySensor::get_value()
   MySensor value 42.6

**News**

* ``MySensor`` **is-a** ``Sensor`` (though the usage of an is-a
  relationship is not at all clear yet)
* Given an instance of ``Sensor``, ``Sensor::method()`` is called
* Given an instance of ``MySensor``, ``MySensor::method()`` is called

**Question**

* When ``ms`` is of type ``MySensor``, but also (*is-a*) of type
  ``Sensor``, is it true that I can use ``ms`` as a ``Sensor``?

jjj

* If I use a ``Derived`` object as-a ``Base``, what is the effect of
  calling ``method()`` on it?

``Derived`` *is-a* ``Base``?
----------------------------

.. literalinclude:: code/inher-oo-derived-novirtual-base-conversion.cpp
   :caption: :download:`code/inher-oo-derived-novirtual-base-conversion.cpp`
   :language: c++

.. code-block:: console

   $ ./inher-oo-derived-novirtual-base-conversion 
   Base::method()

**Answer**

* I can convert a ``Derived`` into a ``Base`` by assigning a
  ``Derived*`` to a ``Base*``.
* C++ does that automatically; **I don't need to use a type cast**.
* But still, I cannot *use* the actual object (remember, ``Derived
  d``) through that ``Base* b``

