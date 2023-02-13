.. ot-exercise:: linux.basics.shell.exercises.cp_mv_mkdir_rm.echo_move_files
   :dependencies: linux.basics.shell.exercises.cp_mv_mkdir_rm.mkdir_p_rm_r,
		  linux.basics.shell.exercises.cp_mv_mkdir_rm.echo_create_files,
		  linux.basics.shell.cp,
		  linux.basics.shell.ls


Exercise: Move Files
====================

.. sidebar::

   * :doc:`/trainings/material/soup/linux/basics/shell/ls`
   * :doc:`/trainings/material/soup/linux/basics/shell/file_dir_create_rm`
   * :doc:`/trainings/material/soup/linux/basics/shell/mv`

* Create two files ``garbage1.txt`` and ``garbage2.txt`` in your home
  directory (containing whatever you like)

  * Prior to doing this, use the ``ls`` :doc:`command <../../ls>` to
    verify that you don't accidentally overwrite existing files (you
    created - and should have removed - them in
    :doc:`echo-copy-files`)

* :doc:`Move <../../cp>` these files into
  ``/tmp/firstname.lastname/parent``

  * Do this using a *single* command

.. ot-graph::
   :entries: linux.basics.shell.exercises.cp_mv_mkdir_rm.echo_move_files
