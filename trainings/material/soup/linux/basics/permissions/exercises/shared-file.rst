.. ot-exercise:: linux.basics.permissions.exercises.shared_file
   :dependencies: linux.basics.permissions.basics,
		  linux.basics.permissions.exercises.credentials


Exercise: Create Group-Shared File
==================================

.. sidebar::

   **Documentation**

   * `man -s 1 chmod <https://linux.die.net/man/1/chmod>`__
   * `man -s 1 chgrp <https://linux.die.net/man/1/chgrp>`__

   **Topics**

   * :doc:`../../shell/file_dir_create_rm`

* In your home directory, create an empty file ``shared.txt``
  [#create_file]_.
* Tune that file's permissions so that every member of your team can
  write to it.
* Nobody else must be able to access the file in any way.

.. rubric:: Footnotes

.. [#create_file] Each of the following commands will do this for you:

   .. code-block:: console

      $ echo > shared.txt

   .. code-block:: console

      $ touch shared.txt

.. ot-graph::
   :entries: linux.basics.permissions.exercises.shared_file
