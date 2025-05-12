.. include:: <mmlalias.txt>


2025-05-07 (3 VO): Commandline/Shell Recap, C++
===============================================

.. contents::
   :local:

Notes
-----
      
* Notenrelevanz der Exercises? Ncht direkt, aber ich behalt mir vor,
  Negativpunkte zu vergeben, wenns nicht gekonnt wird. (Z.B. wer als
  root arbeitet, weil die Permissions fehlen)
* Explain ``/home`` vs. ``/home/user``. What's ``~``?
* Don't work as root. When ``mkdir /temp`` does not work, ``sudo mkdir
  /temp`` won't make it any better.
* ssh

  * client/server: ``ssh -p 2020
    firstname.lastname@jfasch.bounceme.net``
  * public/private?
  * ``known_hosts``, and answering the question with ``yes``
  * disconnect? explain

* directory permissions? r? w? x? Seiner, jump up and ask! -> sketch
  dir layout vs. file layout
* rm file vom buergermeister

Recap: Exercises From 2025-05-05
--------------------------------

* :doc:`../2025-05-06/index`

C++ Intro
---------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/c`
   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`

* C implementation: https://github.com/jfasch/FH-STECE2023/tree/main/livehacking/point-c
* C++ implementation: https://github.com/jfasch/FH-STECE2023/tree/main/livehacking/point-c++

.. _fh_2023_door_exercise:

Door State Machine
------------------

* State machine discussion. Draw something.
* Ownership? Pointers!
* Polling paradigm: simple and stupid. CPU always at the highest
  possible load; no power saving possible. Battery? No!
* googletest ASSERT_EQ
