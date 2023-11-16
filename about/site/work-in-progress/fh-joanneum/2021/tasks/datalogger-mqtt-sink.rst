.. include:: <mmlalias.txt>

.. ot-task:: fh2021.datalogger_mqtt_sink
   :dependencies: fh2021.datalogger


Data Logger: MQTT Sink
======================

Requirements
------------

.. sidebar::

   **See also**

   * Predecessor task: :doc:`datalogger`

* An MQTT implementation of the ``SinkLogger`` interface, using
  ``mosquitto`` (see below)
* A wrapper class around the plain C ``struct mosquitto`` that can
  take a ``SensorValues`` instance, like 

  .. code-block:: c++

     SensorValues v = sensor_config.getAllMeasurements();
     // ...
     Mosquitto client("localhost", 1883 /*default MQTT port*/);
     client.publish(v);

* A definition of the MQTT transport format in JSON, like

  .. code-block:: python

     { "sensor1": 37.5, 
       "sensor2": 42.666
     }

  **Write a unit test** to define the format

Implementation
--------------

.. sidebar::

   **See also**

   * `Mosquitto API
     <https://mosquitto.org/api/files/mosquitto-h.html>`__
   * Sample client implementation using Mosquitto API:
     `bin/mosquitto-publish-demo.cpp
     <https://github.com/jfasch/FH-ECE21/blob/main/bin/mosquitto-publish-demo.cpp>`__

MQTT Implementation: ``mosquitto``
..................................

Cross development is a burden, especially when you do C++ with a
handmade Raspberry toolchain. ``mosquitto`` is written in pure C.

Installation
````````````

.. code-block:: console
   :caption: Ubuntu

   $ sudo apt install mosquitto-dev

.. code-block:: console
   :caption: Fedora

   $ sudo dnf install mosquitto-devel

Wrapper
```````

* Constructor: allocate client using ``mosquitto_new()``, and use
  ``mosquitto_connect()`` on it
* Destructor: ``mosquitto_destroy()``
* *Prohibit copy*

Testing
-------

* Unit test for JSON format
* Sample publish program using the wrapper class, in ``bin/``

Future (*Not* Part Of This Development Cycle)
---------------------------------------------

* The wrapper class will become more widely available when the boiling
  pot (:doc:`boiling-pot`) goes IoT. The pot will broadcast
  "switch-on"/"switch-off" events and temperature measurements (it
  only has a single sensor, *the temperature of the pot itself*) -
  will need a more flexible input than just ``SensorValues``

Dependencies
------------

.. ot-graph::
   :entries: fh2021.datalogger_mqtt_sink
