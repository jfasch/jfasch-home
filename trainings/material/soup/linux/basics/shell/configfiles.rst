.. ot-topic:: linux.basics.shell.configfiles
   :dependencies: linux.basics.intro.environment

.. include:: <mmlalias.txt>


Shell Configuration File: ``~/.bashrc``
=======================================

.. sidebar:: Documentation

   * `man -s 1 bash
     <https://www.man7.org/linux/man-pages/man1/bash.1.html>`__

.. contents:: 
   :local:

What's Volatile?
================

* Setting from the commandline aren't usually persistent
* Tuning the ``PATH`` environment variable is in effect only for the
  current shell/process and for all of its descendants
* Nobody outside can see the modification (environment variables are
  *inherited* after all)
* After a reboot, they are definitely gone

  .. code-block:: console
  
     $ PATH=/home/jfasch/bin:$PATH
     $ export PATH

* Same with shell aliases

  .. code-block:: console

     $ alias d='ls -al'

**Solution**: ``~/.bashrc``

* Write everything that needs to persist (and is re-initialized at
  every login) in ``~/.bashrc``
* Read be every shell that starts up

**"Sourcing" a file**

* If you do not want to quit your running shell, you can always
  re-read the file into the current shell, by "sourcing" it

  .. code-block:: console

     $ . ~/.bashrc

  or, equivalently,
     
  .. code-block:: console

     $ source ~/.bashrc

