.. ot-topic:: linux.basics.permissions.umasks
   :dependencies: linux.basics.permissions.basics,
		  linux.basics.shell.file_dir_create_rm

.. include:: <mmlalias.txt>


Default Permissions: ``umask``
==============================

.. contents::
   :local:

Default Permissions - ``umask``
-------------------------------

**The U-Mask ...**

* Bit field
* *Subtracted* from default permissions at file/directory creation
*  Process attribute |longrightarrow| inherited

.. code-block:: console
   :caption: ``umask`` in action

   $ umask
   0022
   $ touch /tmp/file
   $ ls -l /tmp/file

``umask``: How Does it Work?
----------------------------

* ``umask`` *subtracted* from default permissions
* ``umask`` is an (inherited) process attribute
* Default permissions at file creation: ``rw-rw-rw-``

.. list-table::
   :align: left

   * * Default permissions
     * ``rw-rw-rw-``
     * ``110 110 110``
     * ``0666``
   * * - U-Mask 
     * ``----w--w-``
     * ``000 010 010``
     * ``0022``
   * * **Outcome**
     * ``rw-r--r--``
     * ``110 100 100``
     * ``0644``
