.. ot-exercise:: linux.basics.shell.exercises.cp_mv_mkdir_rm.copy_tree
   :dependencies: linux.basics.shell.exercises.cp_mv_mkdir_rm.verify_hierarchy,
		  linux.basics.shell.cp


Exercise: Copy Directory Tree
=============================

.. sidebar::

   **See also**

   * :doc:`../../cp`

* We just :doc:`had a look at <verify-hierarchy>` the directory tree
  at ``/tmp/parent``

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
  
* :doc:`Copy <../../cp>` that tree into your home directory as
  ``~/parent-copy`` so that you see the following,

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


.. ot-graph::
   :entries: linux.basics.shell.exercises.cp_mv_mkdir_rm.copy_tree
