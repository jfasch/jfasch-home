.. include:: <mmlalias.txt>


Pure Virtual Methods, And *Interfaces*
======================================

.. contents:: 
   :local:

.. sidebar:: See also

   From :doc:`/trainings/material/soup/cxx11/introduction/overview-livehacking-oo`

   * :ref:`cxx11-overview-inheritance-pointer-virtual`

Polymorphic Usage Of Objects
----------------------------

* Derived classes behave as-a sensor |longrightarrow| ``virtual``
* Possibly many derived classes |longrightarrow| there are many sensor
  types out there, one class for each
* In the current form, the base class ``Sensor`` has an implementation
  of ``get_value()``

.. plantuml::
   :align: center

   @startuml

   class Sensor {
     + double get_value()
   }

   class MySensor {
     + double get_value()
   }

   class YourSensor {
     + double get_value()
   }

   class HerSensor {
     + double get_value()
   }

   Sensor <|-- MySensor
   Sensor <|-- YourSensor
   Sensor <|-- HerSensor

   @enduml

Sensor Base Class: One Among Many?
----------------------------------

* **Questions** 

  * What sensor kind does ``Sensor`` (the base class) implement?
  * Why does it implement anything at all?
  * (Alas, implementations are the business of derived classes)

* **Answer**

  * ``Sensor`` is an *interface*, not a *class*
  * C++ does not differentiate, but others (e.g. Java and C#) do
  * Derived classes *realize* that interface
  * *Interfaces don't implement anything*

.. plantuml::
   :align: center

   @startuml

   interface Sensor {
     + double get_value()
   }

   class MySensor {
     + double get_value()
   }

   class YourSensor {
     + double get_value()
   }

   class HerSensor {
     + double get_value()
   }

   Sensor <|.. MySensor
   Sensor <|.. YourSensor
   Sensor <|.. HerSensor

   @enduml

Towards Interfaces: Pure Virtual Methods
----------------------------------------

* Pure virtual method: ``= 0;`` (like "no implementation", or NULL pointer)
* Class ``Sensor`` becomes *abstract*
* |longrightarrow| cannot be instantiated

.. literalinclude:: code/pure-virtual-methods/sensors.h
   :caption: :download:`code/pure-virtual-methods/sensors.h`
   :language: c++

.. literalinclude:: code/pure-virtual-methods/main.cpp
   :caption: :download:`code/pure-virtual-methods/main.cpp`
   :language: c++

.. code-block:: console

   $ ./code/pure-virtual-methods/cxx-inher-oo-pure-virtual-methods 
   MySensor::get_value(): 37.55
   37.55
