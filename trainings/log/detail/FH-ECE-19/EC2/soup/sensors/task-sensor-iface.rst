.. ot-task:: ec2.sensors.task_sensor_iface
   :responsible: joerg.faschingbauer
   :percent-done: 100

Thermometer Interface Definition
================================

.. contents::
   :local:

Description
-----------

.. list-table::
   :align: left

   * * Define a temperature sensor (thermometer) interface to be used
       throughout the project, roughly as follows.

       .. code-block:: python
  
          class Thermometer:
              def get_temperature(self):
                  celsius = ... # read temperature
                  timestamp = time.time()
                  return (timestamp, celsius)

     * DONE (See `here
       <https://github.com/jfasch/FH-ECE-19/blob/master/src/ece19/sensors/thermometer.py>`__)

Dependencies
------------

.. ot-graph::
   :entries: ec2.sensors.task_sensor_iface
