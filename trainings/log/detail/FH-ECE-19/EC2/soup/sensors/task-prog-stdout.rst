.. ot-task:: ec2.sensors.task_prog_stdout
   :dependencies: ec2.sensors.task_simu


Program: Read Sensors, Write to ``stdout``
==========================================

.. contents::
   :local:

Description
-----------

Write a program that periodically reads temperatures from a given set
of thermometers. That program has the following characteristics.

* Takes from a configuration file 

  * A set of thermometers
  * The temperature read interval

  Possible choices for configuration file formats are

  * The ``configparser`` module from the Python standard library; see
    `here <https://docs.python.org/3/library/configparser.html>`__
  * Simpler (albeit more involved): something that can be passed to
    the ``exec()`` function (see `here
    <https://docs.python.org/3/library/functions.html#exec>`__).

  .. note::

     The configuration file parsing code should be externalized as a
     module. :doc:`../mqtt/task-prog-mqtt` is going to use the same
     code.

* Writes structured data to *standard output* [#pipe]_. The following
  hypothetical output is reasonable,

  .. code-block:: console

     $ ./read-thermometers --config-file /etc/thermometers.conf
     kuehlhaus-lu 1631715429.926543 10.23
     kuehlhaus-ro 1631715458.7846692 11.75
     ...

.. rubric:: Footnotes

.. [#pipe] The program is designed to be part of a larger pipeline.

Dependencies
------------

.. ot-graph::
   :entries: ec2.sensors.task_prog_stdout
