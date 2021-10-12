.. ot-task:: ec2.switches.task_switch_iface

Switch Interface Definition
===========================

.. contents::
   :local:

Description
-----------

.. list-table::
   :align: left

   * * Define a *switch* interface throughout the project, roughly as
       follows.

       .. code-block:: python
  
          class Switch:
              def get_state(self):
	          return False    # bool, depending on switch state
              def set_state(self, onoff):    # onoff: bool
	          # ...

     * 

Dependencies
------------

.. ot-graph::
   :entries: ec2.sensors.task_sensor_iface
