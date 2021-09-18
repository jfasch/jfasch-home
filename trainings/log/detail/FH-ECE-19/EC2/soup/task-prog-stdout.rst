.. ot-task:: ec.ec2.task_prog_stdout
   :dependencies: ec.ec2.task_sensor_iface

Simple (``stdout``) Temperature Output
======================================

A program that periodically reads temperatures from a given set of
thermometers. That program has the following characteristics.

* Takes from a configuration file [#winini]__ 

  * The set of thermometers
  * The temperature read interval

* Writes structured data to *standard output* [#pipe]_. The following
  hypothetical output is reasonable,

  .. code-block:: console

     $ ./read-thermometers --config-file /etc/thermometers.conf
     kuehlhaus-lu 1631715429.926543 10.23
     kuehlhaus-ro 1631715458.7846692 11.75
     ...


.. rubric:: Footnotes

.. [#winini] The ``configparser`` module from the Python standard
             library is a straightforward choice; see `here
             <https://docs.python.org/3/library/configparser.html>`__.
.. [#pipe] The program is designed to be part of a larger pipeline.

Dependencies
------------

.. ot-graph::
   :entries: ec.ec2.task_prog_stdout
