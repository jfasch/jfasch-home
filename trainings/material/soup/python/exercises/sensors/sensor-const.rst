.. include:: <mmlalias.txt>


Exercise: Basic "Sensor"
========================

.. contents::
   :local:

.. sidebar::

   * :doc:`project-setup`

Specification, And Setup
------------------------

Implement a class ``ConstantSensor``, such that the following works.

* A *program*, ``read-sensor-const.py``. Download that into the
  ``programs/`` directory of your project structure.

  .. literalinclude:: code/programs/read-sensor-const.py
     :caption: :download:`read-sensor-const.py
               <code/programs/read-sensor-const.py>`
     :language: python

* A *unit test*; you download that into the ``tests/`` subdirectory of
  you project.

  .. literalinclude:: code/tests/test_sensor_const.py
     :caption: :download:`test_sensor_const.py
               <code/tests/test_sensor_const.py>`
     :language: python

* To set paths, follow the instructions in :doc:`project-setup`

Verification
------------

Program
.......

Run the program,

.. code-block:: console

   $ python programs/read-sensor-const.py
   36.7

Unit Test
.........

In you project's root directory, unit tests like follows ...

.. code-block:: console

   $ python -m pytest
   ============================= test session starts ==============================
   platform linux -- Python 3.10.7, pytest-7.2.0, pluggy-1.0.0
   rootdir: <your project root>
   collected 1 item                                                               
   
   tests/test_sensor_const.py .                                             [100%]
   
   ============================== 1 passed in 0.01s ===============================
