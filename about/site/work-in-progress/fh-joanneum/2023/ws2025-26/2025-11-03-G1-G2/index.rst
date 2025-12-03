.. include:: <mmlalias.txt>


2025-11-03 (3 Exc G1,G2): Project Stuff
=======================================

* Gather project status updates
* Fill them into task list
* Gather new ideas (also into task list)

  * Python (`textualize.io <https://www.textualize.io/>`__, `MQTT
    <https://pypi.org/project/paho-mqtt/>`__
  * RFID/NFC to move door

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

