.. include:: <mmlalias.txt>


2025-11-17 (3 Exc G1,G2): Project Stuff
=======================================

Tasks
-----

Status "Ongoing"
````````````````

* :ref:`fh-ws2025-26-task-integration-tests`
* :ref:`fh-ws2025-26-task-testrack`
* :ref:`fh-ws2025-26-task-struct-refact`

  ``MotorStepper`` is still using ``libgpiod``?

* :ref:`fh-ws2025-26-task-analog-sensor`
* :ref:`fh-ws2025-26-task-ads1115`

**Questions**

* :ref:`fh-ws2025-26-task-integration-tests` and
  :ref:`fh-ws2025-26-task-testrack`
* Does :ref:`fh-ws2025-26-task-analog-sensor` include
  :ref:`fh-ws2025-26-task-ads1115` -> no, todo

Status "Done"
`````````````

* :ref:`fh-ws2025-26-task-rm-light-push`
* :ref:`fh-ws2025-26-task-copy-delete`
* :ref:`fh-ws2025-26-task-graceful-termination`
* :ref:`fh-ws2025-26-task-how-to-include-files`
* :ref:`fh-ws2025-26-task-sysfs-gpio`

**Questions**

* Is there anything missing?
* How hard was it?

Grading
```````

* DingsbumsSPS: state machine

Random Code Review
------------------

* https://github.com/jfasch/FH-STECE2023/blob/main/src/door/small_file_handling.cpp
  file descriptor leak
* https://github.com/jfasch/FH-STECE2023/blob/main/src/door/output-switch-gpio-sysfs.cpp 

  * ``ifstream`` too bloated for existence check. ``open()``?
    ``access()``? ``stat()``?

    (Same with ``InputSwitchGPIOSysfs``)

  * Optimize ``OutputSwitchGPIOSysfs::set_state()``


Today
-----

* Test programs aren't unit tests
* Knepferldrucker: cleanup libgpiod

  * motor led tests todo
  * motor-stepper auskommentiert
  * plan: tests/ motor led tests umnieten auf nicht-unit-test. cmdline
    switch --type={led,stepper} (oder so)

* input-output-switch-gpio-sysfs-tests.cpp -> kein unit test



Tomorrow
--------

* Present ``AnalogSensor`` hierarchy 
* State machine
* ``const`` members, and initializer lists
* Exceptions and file descriptor leaks



