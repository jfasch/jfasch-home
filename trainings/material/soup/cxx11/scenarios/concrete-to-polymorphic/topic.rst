.. include:: <mmlalias.txt>


From Concrete To Polymorphic (``class Sensor``)
===============================================

.. contents::
   :local:

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/index`

Very Concrete, And Old School
-----------------------------

.. sidebar:: Documentation

   * `man -s2 time
     <https://man7.org/linux/man-pages/man2/time.2.html>`__
   * `man -s3 sleep
     <https://man7.org/linux/man-pages/man3/sleep.3.html>`__

* Main program calls ``logger.log_one()`` at a one-second interval
  (`man -s3 sleep
  <https://man7.org/linux/man-pages/man3/sleep.3.html>`__)

.. literalinclude:: code/concrete-no-chrono/main.cpp
   :language: c++
   :caption: :download:`code/concrete-no-chrono/main.cpp`

* ``Logger::log_one()`` takes the current time, and outputs the sensor
  value along with it (`man -s2 time
  <https://man7.org/linux/man-pages/man2/time.2.html>`__).

.. literalinclude:: code/concrete-no-chrono/logger.h
   :language: c++
   :caption: :download:`code/concrete-no-chrono/logger.h`

* Mock sensor straightforward, with a method ``set_value()`` for test
  usage. (Note that ``Logger`` only uses ``get_value()``.)

.. literalinclude:: code/concrete-no-chrono/sensor-mock.h
   :language: c++
   :caption: :download:`code/concrete-no-chrono/sensor-mock.h`

Use ``std::chrono`` For Time
----------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/chrono/topic`

* Main program

.. literalinclude:: code/concrete-chrono/main.cpp
   :language: c++
   :caption: :download:`code/concrete-chrono/main.cpp`

* Logger. Talk about :ref:`cxx11-chrono-clock-domains`

.. literalinclude:: code/concrete-chrono/logger.h
   :language: c++
   :caption: :download:`code/concrete-chrono/logger.h`

New Sensor Type: ``FileSensor``
-------------------------------

* Invent new sensor type: ``FileSensor``
* Show usage in ``main.cpp``, *not* passing it to logger

.. literalinclude:: code/file-sensor/sensor-file.h
   :language: c++
   :caption: :download:`code/file-sensor/sensor-file.h`

.. literalinclude:: code/file-sensor/sensor-file.cpp
   :language: c++
   :caption: :download:`code/file-sensor/sensor-file.cpp`

Type Mismatch: ``Logger(...)``
------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/index`

* Pass to ``Logger`` |longrightarrow| wants ``MockSensor*``, not
  ``FileSensor*``
* What to do?
* Interfaces, ``virtual``
* See
  :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/index`
  for the full story

Create Interface: ``Sensor``
----------------------------

* **Every** interface has a ``virtual`` destructor *that does nothing*
* *Dynamic dispatch*: object carries its type, and that type's
  ``get_value()`` is called.

.. literalinclude:: code/polymorphic/sensor.h
   :language: c++
   :caption: :download:`code/polymorphic/sensor.h`

Derive Concrete Implementations From ``Sensor``
-----------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/oo/override`

* *Is-a* relationship
* ``override`` the ``virtual = 0`` in interface (:doc:`don't ask
  </trainings/material/soup/cxx11/oo/override>`)

.. literalinclude:: code/polymorphic/sensor-file.h
   :language: c++
   :caption: :download:`code/polymorphic/sensor-file.h`

.. literalinclude:: code/polymorphic/sensor-mock.h
   :language: c++
   :caption: :download:`code/polymorphic/sensor-mock.h`

