.. ot-topic:: fh.crazycar.sysfs_pwm

.. include:: <mmlalias.txt>


PMW Abstraction On Top Of ``/sys/class/pwm/``
=============================================

.. contents::
   :local:

* See also :doc:`/trainings/material/soup/linux/hardware/pwm/topic`

Facts
-----

* As an implementation detail (reasding and writing small files in
  ``/sys/class/pwm/``)
* Use `class SysFSFile
  <https://github.com/jfasch/FH-STECE2022/blob/main/toolcase/base/sysfs-file.h>`__
  abstraction
* `How to use class SysFSFile
  <https://github.com/jfasch/FH-STECE2022/blob/main/tests/sysfs-file-tests.cpp>`__

Software Interface
------------------

.. code-block:: c++

   class PWMPin
   {
       // hmm, lets see ...
   };

For functionality, start with test, like ...

.. code-block:: c++

   PWMPin pwm7("/sys/class/pwm/pwmchip0/pwm7");

   uint64_t period = pwm7.period(); // read ./period
   uint64_t a_third = period/3;
   pwm7.set_duty_cycle(a_third);

See tests suite in 
