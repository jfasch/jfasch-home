.. ot-topic:: cxx_design_patterns.adapter
   :dependencies: cxx03.inheritance_oo.interface,
		  cxx_design_patterns.uml,
		  cxx_design_patterns.sensor_hierarchy

.. include:: <mmlalias.txt>


Adapter
=======

.. contents::
   :local:

Problem
-------

The sensor hierarchy of our company covers many different
sensor. However, management has decided that it is not broad enough,
and some sensors of company A need to be added. Company A has software
implementations for those sensors that we could technically use. It
does not fit into our hierarchy, naturally [#impedance_mismatch]_.

What they have, though, is a similar hierarchy (one interface for all
their sensors), with the only apparent difference being that they
measure in degrees Fahrenheit.

.. image:: sensor-hierarchy-company-A.png
   :scale: 40%

.. literalinclude:: ../code/libtrainer/sensor-A.h
   :caption: :download:`../code/libtrainer/sensor-A.h`
   :language: c++

Solution: Adaptation
--------------------

Seems like we could be able to integrate all of their sensors in one
swoop, *easily*.

.. image:: sensor-a-adapter.png
   :scale: 40%

.. note::

   Convert Fahrenheit to Celsius using the following formula:

   .. math::

      C = (F - 32) * 5 / 9

Exercise
--------

Implement such an adapter class into our sensor hierarchy, such that
the following tests are satisfied. Implement one by one, and take your
time.

Basic Adaptation
................

.. literalinclude:: ../code/tests-trainee/adapter-suite-basic.cpp
   :caption: :download:`../code/tests-trainee/adapter-suite-basic.cpp`
   :language: c++

Adapter Must *Be-A* ``Sensor``
..............................

.. literalinclude:: ../code/tests-trainee/adapter-suite-adapter--is-a--sensor.cpp
   :caption: :download:`../code/tests-trainee/adapter-suite-adapter--is-a--sensor.cpp`
   :language: c++

Adaptee Can *Be-Any* ``ASensor``
................................

.. literalinclude:: ../code/tests-trainee/adapter-suite-adapter--knows--an-a-sensor.cpp
   :caption: :download:`../code/tests-trainee/adapter-suite-adapter--knows--an-a-sensor.cpp`
   :language: c++

Adapter Is Doing Real Measurements
..................................

Make sure that the adapter is really doing *measurement* (i.e. *use*
the adaptee) when being asked for its temperature.

.. literalinclude:: ../code/tests-trainee/adapter-suite-adapter-definitely-knows--a-sensor--HELL.cpp
   :caption: :download:`../code/tests-trainee/adapter-suite-adapter-definitely-knows--a-sensor--HELL.cpp`
   :language: c++


.. rubric:: Footnotes
.. [#impedance_mismatch] They sure don't share our ``Sensor``
                         interface. That interface is only internal to
                         our company.
