.. include:: <mmlalias.txt>


Embedded Computing 2020
=======================

.. contents::
   :local:

Preparation
-----------

* Install WSL
* ... or have Linux
* ... or have Mac

2022-03-08 (3 VO)
-----------------

* Intro: Embedded Linux

  * Linux on small devices
  * |longrightarrow| no GUI!
  * Remote login via SSH, mostly
  * C/C++: Cross Compilation - what is that?
  * Development machine: WSL? Mac? Linux!  |longrightarrow| *Focus on
    commandline usage*

* Linux Concepts and Terminology (Theory)

  Transcribe first chapter from
  :download:`/trainings/material/pdf/010-linux-basics.pdf`.

* Shell/Commandline Intro

  From :download:`/trainings/material/pdf/010-linux-basics.pdf`,
  pimped a lot.

* File system (also from
  :download:`/trainings/material/pdf/010-linux-basics.pdf`)

  * Current working directory, ``cd``, ``pwd``, ``ls``
  * Absolute and relative paths
  * Overview of a typical Linux filesystem

2022-03-10 (3 VO)
-----------------








* Permissions (Transcribe relevant chapters from
  :download:`/trainings/material/pdf/010-linux-basics.pdf`)



* Processes

  * ``ps``
  * 

* Scheduling

  * :doc:`/trainings/material/soup/sysprog/scheduling/basics`
  * :doc:`/trainings/material/soup/sysprog/scheduling/processes-and-threads`
  * :doc:`/trainings/material/soup/sysprog/scheduling/wakup-latency`
  * :doc:`/trainings/material/soup/sysprog/scheduling/realtime`
  * :doc:`/trainings/material/soup/sysprog/scheduling/realtime-api`

2022-03-21 (3 VO)
-----------------

2022-03-22 (3 KU G1)
--------------------

2022-03-24 (3 VO)
-----------------

2022-03-24 (3 KU G2)
--------------------

2022-03-25 (3 KU G1)
--------------------

2022-03-28 (3 VO)
-----------------

2022-03-29 (3 KU G2)
--------------------

2022-04-28 (3 KU G1, 3 KU G2)
-----------------------------

2022-05-09 (3 VO)
-----------------

2022-06-02 (3 KU G2, 3 KU G1)
-----------------------------

2022-06-03 (3 VO)
-----------------

2022-06-03 (3 KU G2)
--------------------

2022-06-07 (3 KU G1)
--------------------

2022-06-09 (3 VO)
-----------------

2022-06-09 (3 KU G1)
--------------------

2022-06-10 (3 KU G2)
--------------------

2022-06-21 (3 VO)
-----------------

2022-06-27 (3 KU G1)
--------------------

2022-06-27 (3 KU G2)
--------------------

2022-06-28 (3 KU G2)
--------------------

2022-06-28 (3 KU G1)
--------------------

2022-06-29 (3 VO)
-----------------

2022-06-30 (3 KU G2)
--------------------

2022-06-30 (3 KU G1)
--------------------

2022-07-01 (3 KU G1)
--------------------

2022-07-01 (3 KU G2)
--------------------








Garbage
-------

2022-03-21 (3 VO): Shell, Basic Commands, Permission Intro
..........................................................

* Request working Unix installation. *Give this as homework before we
  start, so everyone has it*.

  * Windows users: `Windows Subsystem for Linux
    <https://docs.microsoft.com/en-us/windows/wsl/install>`__ (`here's
    an article
    <https://devblogs.microsoft.com/commandline/whats-new-for-wsl-in-windows-10-version-1903/>`__
    about further integration)
  * MacOS: `Homebrew <https://brew.sh/>`__
  * Linux: nothing to do

* Shell Usage

  * Current working directory, ``pwd``, ``cd``
  * ``ls``: options |longrightarrow| long listing, sorting by
    timestamp, etc.
  * |longrightarrow| metadata
  * ``cp``, ``mv``
  * Permission intro (whetting appetite): ``cp`` and ``mv`` on
    protected files |longrightarrow| ``/etc/passwd``

2022-03-22 (3 VO): Permissions, Standard I/O Streams, I/O 
.........................................................

* File system permissions

  * ``chmod``
  * ``chown``, ``chgrp``

    * Why can't I simply give away a file to someone else?
    * Why can only root do this?
    * Who's that root, after all? (Administration intro)

  * Set-UID programs (|longrightarrow| ``passwd``, ``sudo``)
  * Details: ``umask``, sticky bit

* Standard I/O streams

  * ``echo``, ``cat`` (``less``)
  * ``grep``
  * Errors (e.g. ``cat /etc/shadow``): enter ``stderr``

* I/O redirection, Pipe

2022-03-24 (3 VO)
.................

* Remote login: SSH

  * Cloud computer on GCP
  * :doc:`/trainings/material/soup/devenv/ssh/basics`
  * :doc:`/trainings/material/soup/devenv/ssh/scp`
  * :doc:`/trainings/material/soup/devenv/ssh/portforwarding`
  * :doc:`/trainings/material/soup/devenv/ssh/sshfs`

* Visual Studio

  * Using the SSH integration - editing files on the target
  * :doc:`/trainings/material/soup/python/misc/vscode`
  * C++: TBD: Cross Compilation to Raspi
  * Shell Scripting: simple examples

2022-03-24 (3 KU G2), 2022-03-25 (3 KU G1)
..........................................

2022-03-28 (3 VO)
.................

2022-03-29 (3 KU G2)
....................

2022-04-28 (3 KU G1)
....................

(G1 s. 2022-06-03)

2022-04-28 (3 KU G2)
....................

2022-05-09 (3 VO)
.................

2022-06-02 (3 KU G2 + 3 KU G1)
..............................

2022-06-03 (3 VO)
.................

2022-06-03 (3 KU G2)
....................

2022-06-07 (3 KU G1)
....................

2022-06-09 (3 VO)
.................

2022-06-09 (3 KU G1)
....................

2022-06-10 (3 KU G2)
....................

2022-06-21 (3 VO)
.................

2022-06-27 (3 KU G1, 3 KU G2)
.............................

2022-06-28 (3 KU G1, 3 KU G2)
.............................

2022-06-29 (3 VO)
.................

2022-06-30 (3 KU G1, 3 KU G2)
.............................

2022-07-01 (3 KU G1, 3 KU G2)
.............................

