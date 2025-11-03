.. include:: <mmlalias.txt>


2025-11-03 (3 Lec): Processes, Signals
======================================

Things From Previous Lecture
----------------------------

See
:doc:`/about/site/work-in-progress/fh-joanneum/2023/ws2025-26/2025-10-20-G2/index`
and
:doc:`/about/site/work-in-progress/fh-joanneum/2023/ws2025-26/2025-10-21-G1/index`

* What's ``sizeof``?

Signal Handling, Graceful Termination
-------------------------------------

From :doc:`/trainings/material/soup/linux/sysprog/process/index`

* :doc:`/trainings/material/soup/linux/sysprog/signals/intro/index`
* :doc:`/trainings/material/soup/linux/sysprog/signals/async/index` (stopping at :ref:`sysprog-signals-async-restart`)
* :doc:`/trainings/material/soup/linux/sysprog/signals/async-graceful/index`

Files, And File I/O: Duplication
--------------------------------

* :doc:`/trainings/material/soup/linux/sysprog/file-io/dup/index`
* :doc:`/trainings/material/soup/linux/sysprog/file-io/lseek/index`

Processes
---------

From :doc:`/trainings/material/soup/linux/sysprog/process/index`

* :doc:`/trainings/material/soup/linux/sysprog/process/tree/index`
* :doc:`/trainings/material/soup/linux/sysprog/process/fork-basics/index`
* :doc:`/trainings/material/soup/linux/sysprog/process/unnamed-pipe-ipc/index`

.. _fh-2025-11-03-homework:

Homework Until 2025-11-04: Git/CMake
------------------------------------

Restart the teamwork, as if only
https://github.com/jfasch/FH-STECE2023 existed. All from scratch.

.. attention::

   In the current semester, **everyone** - at least once - will be in
   the team leader role! Teamleaders are responsible for:

   * Forking from upstream
   * Manage collaborators on that fork
   * Sending pull requests upstream and updating the fork

* Teamleader: remove team fork
* All: remove local source and build directories (or back them up
  somewhere)
* Teamleader: create new fork on Github
* Teamleader: add team members as collaborators
* All: create new source and build directories

  *Let's disregard libgpiod for a moment*

  * Clone source directory from the new clone according to
    https://github.com/jfasch/FH-STECE2023 (no ``libgpiod``)
  * Create build directory - **please not as a subdirectory of the
    source directory**
