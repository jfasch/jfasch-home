.. ot-exercise:: linux.basics.shell.exercises.verify_hierarchy
   :dependencies: linux.basics.shell.exercises.mkdir_p_rm_r,
		  linux.basics.shell.exercises.echo_create_files,
		  linux.basics.shell.exercises.echo_copy_files,
		  linux.basics.shell.exercises.echo_move_files


Exercise: Verify, Repeat
========================

In the exercises 

* :doc:`mkdir-p-rm-r`
* :doc:`echo-create-files`
* :doc:`echo-copy-files`
* :doc:`echo-move-files`

, you created a tree rooted at ``/tmp/parent``.

1. Verify that all is correct

   * The hierarchy should look as follows,
   
     .. code-block:: console
     
        $ tree /tmp/parent
        /tmp/parent
        ├── child
        │   ├── business-card
        │   ├── garbage1.txt
        │   └── garbage2.txt
        ├── garbage1.txt
        ├── garbage2.txt
        └── hello
      
   * The file ``/tmp/parent/hello`` should look as follows,
   
     .. code-block:: console
   
        $ cat /tmp/parent/hello
        hello sweetheart
   
   * The file ``/tmp/parent/child/business-card`` should contain
     something like,
   
     .. code-block:: console
   
        $ cat /tmp/parent/child/business-card 
        Joerg
        Faschingbauer
        Prankergasse 33
        8020 Graz

2. If any of the above is not the case, :doc:`remove
   <../file_dir_create_rm>` ``/tmp/parent`` again recursively, and
   recreate the hierarchy.
3. **Repeat until successful!**



.. ot-graph::
   :entries: linux.basics.shell.exercises.verify_hierarchy
