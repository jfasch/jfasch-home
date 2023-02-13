.. ot-exercise:: linux.basics.shell.exercises.cp_mv_mkdir_rm.echo_create_files
   :dependencies: linux.basics.shell.exercises.cp_mv_mkdir_rm.mkdir_p_rm_r,
		  linux.basics.shell.file_dir_create_rm,
		  linux.basics.shell.paths,
		  linux.basics.shell.cwd


Exercise: Create Files (I/O Redirection)
========================================

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/basics/shell/cwd`
   * :doc:`/trainings/material/soup/linux/basics/shell/file_dir_create_rm`

* Make your home directory your *current working diretory* ("Change
  into your home directory")
* *From there*, fill the directory hierarchy from :doc:`mkdir-p-rm-r`
  with files

  * Create a file ``hello`` in the ``parent`` directory, containing a
    single line, ``hello sweetheart``

  * Create a file ``business-card`` in the ``child`` directory,
    containing four lines

    * Your first name
    * Your last name
    * Your street (including number)
    * Your ZIP code and city

.. hint::

   You use the ``>>`` operator to *append* a line to an existing file
   (or to create that file if it doesn't exist:

   .. code-block:: console

      $ echo 8020 Graz >> somefile.txt

.. ot-graph::
   :entries: linux.basics.shell.exercises.cp_mv_mkdir_rm.echo_create_files
