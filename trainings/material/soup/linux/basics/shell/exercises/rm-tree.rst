.. ot-exercise:: linux.basics.shell.exercises.rm_tree
   :dependencies: linux.basics.shell.exercises.copy_tree,
		  linux.basics.shell.file_dir_create_rm


Exercise: Remove Directory Tree
===============================

* In :doc:`copy-tree`, you created a directory ``~/parent-copy``,

  .. code-block:: console

     $ tree ~/parent-copy/
     /home/<you>/parent-copy/
     ├── child
     │   ├── business-card
     │   ├── garbage1.txt
     │   └── garbage2.txt
     ├── garbage1.txt
     ├── garbage2.txt
     └── hello

* Remove that directory entirely, so that,

  .. code-block:: console

     $ ls ~/parent-copy
     ls: cannot access '/home/jfasch/parent-copy': No such file or directory

.. ot-graph::
   :entries: linux.basics.shell.exercises.rm_tree
