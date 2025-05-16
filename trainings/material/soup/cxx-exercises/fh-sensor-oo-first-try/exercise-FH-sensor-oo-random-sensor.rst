.. include:: <mmlalias.txt>


Exercise (FH): Write A Sensor Class: ``RandomSensor``
=====================================================

.. contents::
   :local:

New Sensor Class: ``RandomSensor``
----------------------------------

Based on the project you git-cloned in :doc:`exercise-FH-sensor-oo`,
extend the ``sensors`` library (int ``src/sensors/``) with another
sensor, ``RandomSensor``.

Create two new files in that directory,

* ``random-sensor.h``. That file contains the *class definition*
* ``random-sensor.cpp``. That file contains the *implementation*

The proposed usage of such a sensor is as follows:

.. code-block:: c++

   double low = 32.4;
   double high = 38.7;

   RandomSensor sensor{low, high};
   double temperature = sensor.get_temperature();

   // temperature is a random number between low and high


Here is a sample program that generates random numbers in such a
way. It is your responsibility to understand how random numbers are
generated, and to write the ``RandomSensor`` class accordingly.

.. literalinclude:: c++03-exercise-fh-random-demo.cpp
   :caption: :download:`c++03-exercise-fh-random-demo.cpp`
   :language: c++

Implementation Details
......................

Like in the program above which uses two variables,

.. code-block:: c++

   std::uniform_real_distribution<double> distribution(low, high);
   std::default_random_engine engine;

... the ``RandomSensor`` class will have to have two members,

.. code-block:: c++

   class RandomSensor
   {
       // ...
   private:
       std::uniform_real_distribution<double> _distribution;
       std::default_random_engine _engine;
   };

The ``RandomSensor::get_temperature()`` method uses these members to
generate random numbers in the specified range - exactly like the
program, but nicely encapsulated inside the method implementation.

The ``RandomSensor`` constructor - ``RandomSensor(double low, double
high)`` - passes its arguments to the constructor of the
``_distribution`` member in the initializer list.

See this in analogy to the ``class point`` example in
:doc:`/trainings/material/soup/cxx11/introduction/overview-livehacking`,
where we initialize ``int`` members (and not random distributions),

.. code-block:: c++

   class point
   {
   public:
       point(int x, int y) : _x{x}, _y{y} {}
       ...
   };

New Program: ``random-temperature.cpp``
---------------------------------------

In the ``firstname.lastname`` directory you created for
:doc:`exercise-FH-sensor-oo`, create a new program,
``random-temperature.cpp`` that works just like `this one
<https://github.com/jfasch/FH-ECE20/blob/main/joerg.faschingbauer/onewire-temperature-joerg-faschingbauer.cpp>`__,
but differs in the following ways:

* It uses your ``RandomSensor`` implementation (and not the
  ``W1Sensor``)
* It takes from the commandline the necessary ``low`` and ``high``
  parameters to instantiate the ``RandomSensor`` object (instead of
  the ``filename`` parameter that the ``W1Sensor`` program uses). The
  ``interval`` parameter is still necessary.

  .. code-block:: console

     $ ./random-temperature 10.5 30.1 1
     ... spits out random numbers in the range [10.5, 30.1] every second ...

