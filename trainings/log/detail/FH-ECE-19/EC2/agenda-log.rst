Agenda/Log
==========

.. contents::
   :local:

.. _2021-10-07:

2021-10-07 (13:00 - 15:30)
--------------------------

Whose Fault It Is
.................

.. image:: ../EC1/Bullshit-Bingo-G2.jpg
   :scale: 10%

Topics
......

* Org stuff

  * `Moodle
    <https://virtueller-campus-2021-22.fh-joanneum.at/course/view.php?id=3249>`__
  * :doc:`Project plan <soup/group-ec2>`
  * Grading system: show `manager's sheet
    <https://virtueller-campus-2021-22.fh-joanneum.at/mod/resource/view.php?id=21246>`__
  * `VirtualBox image
    <https://fhjoanneum-my.sharepoint.com/:u:/g/personal/joerg_faschingbauer_fh-joanneum_at/EWHSVLu-U5tPladezSnhRxIBNTSPmq4XvNiaMGnlFsJ0tA?e=JgfzSt>`__
    (:doc:`Task <soup/devenv/task-virtualbox>`)

* Project structure

  * `Github <https://github.com/jfasch/FH-ECE-19>`__ (same as in
    :doc:`last semester <../EC1/index>`)
  * Briefly discuss the Why

* OO introduction. Live-hack a thermometer that reads from a file

  * Sketch of task ":doc:`soup/sensors/task-prog-stdout`" (`here
    <https://github.com/jfasch/FH-ECE-19/blob/master/bin/read-thermometers>`__)

    * Omit commandline parsing and config file. Hardcode interval and
      thermometer list.
    * Try to instantiate ``Thermometer``.

  * *Abstract base class*. ``Thermometer`` discussion.
  * ``FileThermometer`` (`here
    <https://github.com/jfasch/FH-ECE-19/blob/master/src/ece19/sensors/thermometer.py>`__

    * *Constructor*
    * *Member* (= attribute, property)
    * *Method*

2021-10-28
----------

  * Complain how I hate that manual ``read-thermometers`` invocation.
  * Introduce prerequisites

    * :doc:`/trainings/material/soup/python/draft/pip/topic`
    * :doc:`/trainings/material/soup/python/draft/venv/topic`

  * Unit testing. Present ``pytest``.

* Hardware interfaces for sensors (:doc:`Task
  <soup/devenv/task-hwdoc>`)

  * :doc:`/trainings/material/soup/linux/hardware/w1/topic`
  * :doc:`/trainings/material/soup/linux/hardware/i2c/topic`

Exercise
........

* Setup Pi (again?)
* Install VirtualBox
* Run the image
* Use ``ssh`` to connect to the Pi (:doc:`here
  </trainings/material/soup/devenv/ssh/basics>`)
* Mount your Pi homedirectory (:doc:`here
  </trainings/material/soup/devenv/ssh/sshfs>`)

TODOs
.....

* Add VSCode to Vbox image
* Topic: Raspi static IP, point to point connection to Linux PC (on
  subnet ``192.168.7.*``)
