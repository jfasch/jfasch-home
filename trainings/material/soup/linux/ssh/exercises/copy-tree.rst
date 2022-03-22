.. ot-exercise:: linux.ssh.exercises.copy_tree
   :dependencies: linux.ssh.exercises.copy_file,
		  linux.ssh.exercises.pubkey,
		  linux.ssh.key_pair,
		  linux.ssh.scp,
		  linux.ssh.basics


Exercise: Copy a Tree To Remote Machine (And Adjust Permissions)
================================================================

In
:doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/verify-hierarchy`
(and the exercise series that preceded it), you created an entire file
hierarchy *on the local machine* (your work machine), rooted at
``/tmp/parent``.

Continuing from there ...

* Copy that tree to the remote machine, under the name
  ``~/my-parent-copy``. Use the ``scp`` :doc:`command <../scp>` to do
  this.
* Use one single local ``ssh`` command to tune the permissions of the
  remote tree ``~/my-parent-copy`` (and its contents, *recursively*)
  so that *others* don't have any permissions to do anything.

  (Hint: you can use the ``-R`` option to the ``chmod`` command to
  modify permissions recursively)

.. ot-graph::
   :entries: linux.ssh.exercises.copy_tree
