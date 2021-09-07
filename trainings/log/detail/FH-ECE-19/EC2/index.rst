Embedded Computing 2 (ECE 19)
=============================

.. contents::
   :local:

Overall Big Picture
-------------------

This is a learning project - we do *not* expect any meaningful
output. An initial bullshit bingo session led to this picture; let's
cover what we can.

.. image:: ../EC1/Bullshit-Bingo-G2.jpg
   :scale: 30%

.. toctree:: 

   random-thoughts

Hardware Interaction
--------------------

Sensors
.......

* Write Python class for each sensor:
  :doc:`/about/site/work-in-progress/fh-joanneum/py_exercise_sensors`
* Simple test program, letting us configure the sensor to use, and the
  measurement interval from the commandline.

  * See
    :doc:`/trainings/material/soup/python/basics/python_0130_syntax_etc/topic`;
    maybe extract ``sys.argv`` from there into a separate topic
  * `argparse documentation
    <https://docs.python.org/3/library/argparse.html>`__
  * `Youtube Tutorial <https://www.youtube.com/watch?v=cdblJqEUDNo>`__

  Program writes sensor values to ``sys.stdout``, making it a good
  member of a pipeline.

  *Special goodie:* one special sensor that does *not* require
  hardware, but rather returns sine values based upon the measurement
  time. Cute for testing.

* Evolution step: ``sys.stdout`` is too unflexible. Enter :doc:`MQTT
  </trainings/material/soup/python/draft/mqtt/topic>`.

  More configuration options on commandline: MQTT parameters.

  (Maybe switch over to D-Bus is there's time or need. For example,
  querying the state of a switch is not something that's easily done
  with MQTT.)

Switches
........

Starting with our :doc:`LED blink exercise from summer 2021
</trainings/log/detail/FH-ECE-19/EC1/Exercises/blinklicht>`, we want
to have easily usable classes (just as with the sensors above).

* :doc:`/trainings/log/detail/FH-ECE-19/EC1/Exercises/blinklicht-oo`

OO/Interface Design
...................

Moving away from :doc:`duck typing
</trainings/material/soup/python/draft/duck-typing>`, use Python's
`Abstract Base Class (abc) module
<https://docs.python.org/3/library/abc.html>`__.

* Sensors
* Switches:
  :doc:`/trainings/log/detail/FH-ECE-19/EC1/Exercises/blinklicht-abc`

Project State (Hardware Perspective)
------------------------------------

Having implemented that, we can now draw this picture.

* A bunch of sensors pushing sensor values into the cloud (err, MQTT)
* Something (a PID controller operating a switch maybe?) listening for
  those.

.. image:: picture-hw-perspective.png

Service Management
------------------

What's a "service"? Clear that up, and introduce systemd.

* `systemd service unit files
  <https://www.freedesktop.org/software/systemd/man/systemd.service.html>`__

