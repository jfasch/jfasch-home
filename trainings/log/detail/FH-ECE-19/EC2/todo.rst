Todo List
=========

Switches
--------

Starting with our :doc:`LED blink exercise from summer 2021
</trainings/log/detail/FH-ECE-19/EC1/Exercises/blinklicht>`, we want
to have easily usable classes (just as with the sensors above).

* :doc:`/trainings/log/detail/FH-ECE-19/EC1/Exercises/blinklicht-oo`

OO/Interface Design
-------------------

Moving away from :doc:`duck typing
</trainings/material/soup/python/draft/duck-typing>`, use Python's
`Abstract Base Class (abc) module
<https://docs.python.org/3/library/abc.html>`__.

* Sensors
* Switches:
  :doc:`/trainings/log/detail/FH-ECE-19/EC1/Exercises/blinklicht-abc`

Logging, Testing
----------------

Once the code base has gotten big enough (there's nothing much to test
in :doc:`sensors <soup/sensors/group>` and :doc:`MQTT
<soup/mqtt/group>`, so there's no problem to solve), enter a
refactoring round.

* Build logging into all "service" type programs (much like `here
  <https://github.com/jfasch/openheating/blob/master/openheating/plant/logutil.py>`__).
* Add unit tests.
