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
   
Special Paths
-------------

* ``/``: root directory - **where it all begins**
* ``~``: home directory of the user

  .. code-block:: console

     $ id -u
     1000
     $ id -un
     jfasch
     $ pwd
     /etc
     $ cd ~
     $ pwd
     /home/jfasch

* ``~someone-else``: home directory of someone else
* ``.``: current working directory

  .. code-block:: console

     $ pwd
     /home/jfasch
     $ cd .
     $ pwd
     /home/jfasch

* ``..``: parent directory of CWD

  .. code-block:: console

     $ cd ..
     $ pwd
     /home

  .. code-block:: console

     $ ls -l
     total 0
     drwx------. 1 jfasch       jfasch       554 Mar  8 10:51 jfasch
     drwx------. 1 someone-else someone-else  92 Mar  3 14:12 someone-else

  ``.`` and ``..`` are regular path components ...

  .. code-block:: console

     $ cd ~jfasch/../someone-else
     $ pwd
     /home/someone-else
