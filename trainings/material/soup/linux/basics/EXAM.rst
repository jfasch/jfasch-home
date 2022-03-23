.. ot-exercise:: linux.basics.EXAM
   :dependencies: linux.basics.shell.exercises.cp_mv_mkdir_rm.mkdir_p_rm_r,
		  linux.basics.shell.exercises.cp_mv_mkdir_rm.echo_create_files,
		  linux.basics.shell.cp,
		  linux.basics.shell.ls


Exam: Do A Lot With Files And Directories
=========================================

.. contents:: 
   :local:

Precondition: Logged-In To Remote/Exam Computer
-----------------------------------------------

* Public key deployed to remote computer (see
  :doc:`/trainings/material/soup/linux/ssh/key-pair`)
* Logged in to remote computer

  .. code-block:: console

     $ ssh -p 2020 firstname.lastname@jfasch.bounceme.net

.. danger::

   **The exam must be done on the remote computer**

   Take care to not accidentally execute the following steps on your
   local machine!

Create Exam Skeleton (5 Points)
--------------------------------

.. sidebar::

   * :doc:`/trainings/material/soup/linux/basics/shell/file_dir_create_rm`

* In your home directory, create a subdirectory ``exam-01``. 
* In the ``~/exam-01`` directory, create an empty ("skeleton") tree as
  follows,

.. code-block:: console

   $ tree ~/exam-01/
   ~/exam-01/
   ├── business-cards
   ├── private-place
   └── public-place

Create Business Cards (10 Points)
---------------------------------

.. sidebar::

   * :doc:`/trainings/material/soup/linux/basics/shell/file_dir_create_rm`
   * :doc:`/trainings/material/soup/linux/basics/intro/login`

In the directory ``~/exam-01/business-cards``, create a file
``my-credentials.card`` that contains, line by line,

* Your user name
* Your user ID (``uid``)
* The name and ID of your primary group (``gid``)
* The names and IDs of your supplementary groups (``groups``)

In the case of user ``joerg.faschingbauer``, that file would look like
this:

.. code-block:: console

   $ cat ~/exam-01/business-cards/my-credentials.card
   joerg.faschingbauer
   1020
   joerg.faschingbauer 1020
   ece20 1021

.. hint::

   See :doc:`/trainings/material/soup/linux/basics/intro/login` for
   how to find out who you are.

.. hint::

   You use the ``>>`` operator to *append* a line to an existing file
   (or to create that file if it doesn't exist):

   .. code-block:: console

      $ echo 8020 Graz >> somefile.txt

Public Place (10 Points)
------------------------

.. sidebar::

   * :doc:`/trainings/material/soup/linux/basics/permissions/basics`

Tune the permissions of the ``~/exam-01/public-place`` directory in a
way that

* You can

  * look and ``cd`` into it
  * create files in it
  * remove files from it

* Your fellow members of the ``ece20`` group can

  * look and ``cd`` into it
  * create files in it
  * remove files from it

* Nobody else can do any of the above

Private Place (10 Points)
-------------------------

Tune the permissions of the ``~/exam-01/private-place`` directory in a
way that

* You can 

  * look and ``cd`` into it
  * create files in it
  * remove files from it

* Nobody else can do any of the above

Shared File in Public Place (10 Points)
---------------------------------------

Create a file ``completely-open.txt`` in ``~/exam-01/public-place`` in
a way that

* It contains the phrase "Hello teacher"

  .. code-block:: console

     $ cat ~/exam-01/public-place/completely-open.txt
     Hello teacher

* You can modify/write that file
* Your fellow members of ``ece20`` can only read it

Make A Backup Of ``~/exam-01`` (15 Points)
------------------------------------------

* Goal

  * Transfer what you created (i.e. the entire contents of the remote
    ``~/exam-01`` directory) to your local machine.
  * Use the ``scp`` command for this task

* Think

  * What would be the command to do this?
  * Note that we were extremely picky to restrict permissions in most
    parts of the tree. How would you preserve those valuable
    permissions across the remote copy?

    (Hint: read the ``scp`` manual page, and find out about the ``-p``
    option.)

* Create a file ``backup-command.sh`` in ``~/exam-01/public-place``
  containing that command.
* Make this file executable for *all users* (but otherwise preserve
  its default permissions that it had initially)
* Finally, execute the ``scp`` command on your local machine

Dependencies
------------

.. ot-graph::
   :entries: linux.basics.EXAM

