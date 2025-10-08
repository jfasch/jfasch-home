.. include:: <mmlalias.txt>


UML Short Introduction
======================

.. topic:: See also

   * :doc:`/trainings/material/soup/cxx/cxx03/inheritance-oo-design/index`

Interface
---------

* Does not implement anything
* C++: *abstract base class*
* Purest form (preferred): no implementation of anything

  * Except destructor of course, which has to be defaulted (see
    :doc:`here
    </trainings/material/soup/cxx/cxx03/inheritance-oo-design/destructor>`
    for this sad story)

* Implementation inheritance is possible though, but should not be
  overused
* In this course, lets say the following C++ "interface" is expressed
  in UML like follows ("I" for "interface" in `plantuml
  <https://plantuml.com/>`__)

  * Alternative notation: a stereotype ``<<interface>>``
  * Alternative notation: a small circle in the upper right corner

.. list-table::
   :align: left

   * * .. code-block:: c++

          class Sensor
          {
          public:
              virtual ~Sensor() = default;
              virtual double get_temperature() = 0;
          };

     * .. plantuml::
       
          @startuml
       
          interface Sensor {
            + double get_temperature()
          }
       
          @enduml


Interface Implementation, Inheritance
-------------------------------------

* ``I2CSensor`` *is-a* ``Sensor``
* ``I2CSensor`` *can-be-used-as-a* ``Sensor`` (i.e. ``I2CSensor*`` is
  automatically converted to ``Sensor*``)

.. list-table::
   :align: left

   * * .. code-block:: c++
       
          class I2CSensor : public Sensor
          {
          public:
              I2CSensor(unsigned int bus, uint8_t address);
	      double get_temperature() override;
          };
     * .. plantuml::
       
          @startuml
       
          interface Sensor {
            + double get_temperature()
          }

	  class I2CSensor {
            + double get_temperature()
	  }

	  Sensor <|.. I2CSensor
       
          @enduml

Association
-----------

* Lightest form of a "using" relationship
* Usually implemented in C++ as raw pointer relationship
* Lifetime and resource management unspecified

.. list-table::
   :align: left

   * * .. code-block:: c++

          class PIDController
          {
          // ...
          private:
              Sensor* _sensor;
          };
     * .. plantuml::

          @startuml
       
          class PIDController {}
          interface Sensor {}

	  PIDController -right-> Sensor

          @enduml

Aggregation
-----------

* Semi *has-a*
* Often implemented as ``std::shared_ptr<>``

.. list-table::
   :align: left

   * * .. code-block:: c++

          class PIDController
          {
          // ...
          private:
              std::shared_ptr<Sensor> _sensor;
          };
     * .. plantuml::

          @startuml
       
          class PIDController {}
          interface Sensor {}

	  PIDController o-right-> Sensor

          @enduml

Composition
-----------

* Most-defined form
* Owned object is *lifetime-tied* to owning object
* Commonly implemented as 

  * Automatic membership
  * ``std::unique_ptr<>``

.. list-table::
   :align: left

   * * .. code-block:: c++

          class PIDController
          {
          // ...
          private:
              Sensor _sensor;
          };

       .. code-block:: c++

          class PIDController
          {
          // ...
          private:
              std::unique_ptr<Sensor> _sensor;
          };
     * .. plantuml::

          @startuml
       
          class PIDController {}
          interface Sensor {}

	  PIDController *-right-> Sensor

          @enduml
