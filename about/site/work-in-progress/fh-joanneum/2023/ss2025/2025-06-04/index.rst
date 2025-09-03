.. include:: <mmlalias.txt>


2025-06-04 (3 VO): More C++, Project Kickoff
============================================

.. contents::
   :local:

C++: References, ``auto``
-------------------------

* :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/050-references/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/auto/topic`

Group Project: Potential Tasks
------------------------------

Talk about ...

* Error handling: ``ASSERT_THROW()`` (see `here
  <http://google.github.io/googletest/reference/assertions.html>`__)
* Requirements

  * Burglar detection
  * Close-request while open
  * Close-request while closed
  * Close-request while opening
  * Open-request while closing
  * Safety: pressure sensor
  * ...

* Hardware

  * GPIO (libgpiod)
  * PWM? (motor)
  * PushButton GPIO
  * LightBarrier GPIO
  * Edge events (need previous state), debouncing.

* SPS-like logic

  * Timespec wrapper, wegen libgpiod gpiod_line_event_wait. Oo
    Operator Arithmetik.
  * Externalize event detection into toplevel ``Door::check()``.

    Im Main bzw. Door check. -> wait on ios, and Dispatch Events to
    State machine. Timespec now reinreichen, Time Arithmetik ganz
    einfach mit unit Tests und Overflow condition mit assert. Halt
    schwer zu testen - exceptions ganz kalt hin was ist, mit errno

* Integrationstest, nachdem die Interfaces definiert sind. Mocks als
  erste Implementation, so wie wir's jetzt haben.

  Damit kommt man ziemlich weit, weil der immer rennt. Spätestens
  durch mich, das sowieso, mit den mock Tests die wir haben.

* Door state machine: convert to `State design pattern
  <https://en.wikipedia.org/wiki/State_pattern>`__
