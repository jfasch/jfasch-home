.. ot-topic:: linux.sysprog.process.commandline
   :dependencies: linux.sysprog.fileio.basics

.. include:: <mmlalias.txt>


Process: Arguments, Exit Status
===============================

.. contents::
   :local:

.. sidebar:: See also

   * :doc:`Standard File Descriptors
     </trainings/material/soup/linux/sysprog/file-io/basics>`
   * :doc:`/trainings/material/soup/c/050-pointers-and-arrays/050-command-line-arguments/topic`

Shell, Running A Program
------------------------

* The shell is a program just like any other program
  (e.g. ``/bin/bash``)
* Main purpose: start other programs, and report on their exit status

**Commandline, the sunny case**

* In the sunny case (which is "got two parameters" in the case of
  ``my-command``), an exit status of *zero* is returned.
* The truth value of *zero* is ``true``, paradoxically. This makes
  sense though because *there is only one* sunny case.

.. code-block:: console

   $ ./my-command hallo suesser
   Command: ./my-command
   Parameter 1: hallo
   Parameter 2: suesser
   $ echo $?
   0

**Commandline, error case**

* In any error case (which is "no two parameters" for us), an exit
  status of *non-zero* is returned.
* The truth value of *non-zero* is ``false``. Again, this makes sense
  because there are possibly many things why a program might fail.

.. code-block:: console

   $ ./my-command
   ./my-command: requires 2 parameters
   [jfasch@wohnzimmer ~/work/jfasch-home/trainings/material/soup/linux/sysprog/process]
   $ echo $?
   1

The Sample Program
------------------

.. literalinclude:: my-command.c
   :language: c

Argument Vector
---------------

.. image:: argv.dia

Exit Status
-----------

* An integer in the range 0-255
* In the simplest case, a ``return`` from the main function is the
  program's exit status
* Otherwise, see `man -s 3 exit
  <https://man7.org/linux/man-pages/man3/exit.3.html>`__
