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

``Sensor``: Plain (Base) Class
------------------------------

* A plain class ``Sensor`` with a ``get_value()`` method
* No surprise

.. plantuml::
   :width: 50%
   :align: center

   @startuml

   class Sensor {
     + double get_value()
   }
   note left of Sensor::get_value
      Implemented somehow
   end note   

   @enduml

.. .. image:: uml-base.jpg


.. literalinclude:: code/base/sensors.h
   :caption: :download:`code/base/sensors.h`
   :language: c++

.. literalinclude:: code/base/main.cpp
   :caption: :download:`code/base/main.cpp`
   :language: c++

.. code-block:: console

   $ ./code/base/cxx-inher-oo-base 
   Sensor::get_value()
   got value 36.5

Inheriting (Deriving) From Base
-------------------------------

**News**

* ``MySensor`` **is-a** ``Sensor`` (though the usage of an is-a
  relationship is not at all clear yet)
* Given an instance of ``Sensor``, ``Sensor::method()`` is called
* Given an instance of ``MySensor``, ``MySensor::method()`` is called

**Question**

* When ``ms`` is of type ``MySensor``, but also of type ``Sensor``
  (``MySensor`` *is-a* ``Sensor``), is it true that I can use ``ms``
  as a ``Sensor``?
* If I use a ``MySensor`` object *as-a* ``Sensor``, what is the effect
  of calling ``get_value()`` on it?


.. plantuml::
   :width: 30%
   :align: center

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


.. literalinclude:: code/derived/sensors.h
   :caption: :download:`code/derived/sensors.h`
   :language: c++

Inheritance: Concrete Instances |longrightarrow| No Surprise
------------------------------------------------------------

* Instantiation of concrete objects
* Method calls directly on objects
* |longrightarrow| no surprise

.. literalinclude:: code/derived/no-surprise.cpp
   :caption: :download:`code/derived/no-surprise.cpp`
   :language: c++

.. code-block:: console

   $ ./code/derived/cxx-inher-oo-derived-no-surprise 
   Sensor::get_value(): 36.4
   Sensor value: 36.4
   Sensor::get_value(): 37.3
   MySensor::get_value(): 37.55
   MySensor value 37.55

Inheritance: Automatic Pointer-To-Base Conversion
-------------------------------------------------

* *Definition of inheritance* 
* Pointer-to-derived is *automatically* (no type cast needed)
  converted to pointer-to-base
* *Not obvious, and maybe unwanted:* base class method called,
  *although object is of derived type*

.. literalinclude:: code/derived/pointer-conversion.cpp
   :caption: :download:`code/derived/pointer-conversion.cpp`
   :language: c++

.. code-block:: console

   $ ./code/derived/cxx-inher-oo-derived-pointer-conversion 
   Sensor::get_value(): 37.3

Inheritance: Slicing (Automatic Instance Conversion)
----------------------------------------------------

* *Instance* conversion: derived to base
* Rarely wanted
* |longrightarrow| **Slicing**

.. literalinclude:: code/derived/slicing.cpp
   :caption: :download:`code/derived/slicing.cpp`
   :language: c++
