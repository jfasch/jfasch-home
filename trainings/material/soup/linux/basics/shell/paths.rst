.. ot-topic:: linux.basics.shell.paths
   :dependencies: linux.basics.shell.commandline

.. include:: <mmlalias.txt>


Absolute and Relative Paths
===========================

.. contents::
   :local:

Path Separator
--------------

* **First off**: in UNIX, the *path separator* is the *forward slash*:
  ``/`` (as opposed to Doze which chose the *backslash*, ``\``)

Relative Paths
--------------

* Don't begin with a ``/``
* Interpreted *relative* to the *current working directory* (CWD)

.. code-block:: console
   :caption: Being in my home directory, change into the
             ``Documents`` subdirectory of it

   $ pwd
   /home/jfasch
   $ cd Documents
   $ pwd
   /home/jfasch/Documents

.. code-block:: console
   :caption: From there, change into its neighbor directory, ``Downloads``

   $ cd ../Downloads
   $ pwd
   /home/jfasch/Downloads

Absolute Paths
--------------

* Start with a ``/``
* "Relative" to the *root directory*
* |longrightarrow| Independent of CWD

.. code-block:: console

   $ cd /etc
   $ pwd
   /etc
   
