.. include:: <mmlalias.txt>


2025-06-24 (3+3 UE): Hacking The Project
========================================

.. contents::
   :local:

Progress
--------

* :doc:`/about/site/work-in-progress/fh-joanneum/2023/ss2025/tasks/motor-gpio`

  Done, integrated

* :doc:`/about/site/work-in-progress/fh-joanneum/2023/ss2025/tasks/lightbarrier-gpio`

  Done, integrated

* :doc:`/about/site/work-in-progress/fh-joanneum/2023/ss2025/tasks/pushbutton-gpio`

  Still in the works. Using the C++ binding of ``libgpiod`` - maybe
  interesting for the future.

* :doc:`/about/site/work-in-progress/fh-joanneum/2023/ss2025/tasks/sps-shell`

  Defining helpers:

  * One to create ``input_t`` and ``events_t`` from the sensors that
    we have
  * One to receive the ``output_t`` and control the actors (only motor
    for now)

* :doc:`/about/site/work-in-progress/fh-joanneum/2023/ss2025/tasks/event-detector`
  
  * Plain edge detection integrated
  * Debouncing on the way

* :doc:`/about/site/work-in-progress/fh-joanneum/2023/ss2025/tasks/pressure-sensor`

  Done, integrated

* :doc:`/about/site/work-in-progress/fh-joanneum/2023/ss2025/tasks/motor-stepper`

  * PWM roughly implemented
  * 3D printed :-)
  * Still hacking

Followup Tasks
--------------

* :doc:`/about/site/work-in-progress/fh-joanneum/2023/ss2025/tasks/input-output-switch`
  
