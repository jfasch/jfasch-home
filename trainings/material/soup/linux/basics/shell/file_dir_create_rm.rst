.. ot-topic:: linux.basics.shell.file_dir_create_rm
   :dependencies: linux.basics.shell.cwd,
		  linux.basics.shell.paths

.. include:: <mmlalias.txt>


Creating And Removing Files and Directories
===========================================

.. contents::
   :local:

Creating a Directory: ``mkdir``
-------------------------------

.. sidebar:: Documentation

   * `man -s 1 mkdir
     <https://man7.org/linux/man-pages/man1/mkdir.1.html>`__

* Create a new directory in an *existing* directory

  .. code-block:: console

     $ mkdir /tmp/a-directory

* Cannot create a directory inside a directory that doesn't exist

  .. code-block:: console

     $ mkdir /tmp/an/entire/hierarchy
     mkdir: cannot create directory ‘/tmp/an/entire/hierarchy’: No such file or directory

* |longrightarrow| ``mkdir -p``

  .. code-block:: console

     $ mkdir -p /tmp/an/entire/hierarchy

Creating a File: I/O redirection
--------------------------------

**Create a file (or overwrite if it exists)**

.. code-block:: console

   $ echo hello > /tmp/a-file-containing-hello
   $ cat /tmp/a-file-containing-hello
   hello

And permissions? I didn't say how I want these!
|:face_with_raised_eyebrow:|

.. code-block:: console

   $ ls -l /tmp/a-file-containing-hello
   -rw-rw-r--. 1 jfasch jfasch 6 Mar  9 18:56 /tmp/a-file-containing-hello

|longrightarrow| :doc:`../permissions/umask`

**Append to an existing file (or creating, if it doesn't exist)**

.. code-block:: console

   $ echo sweetheart >> /tmp/a-file-containing-hello
   $ cat /tmp/a-file-containing-hello
   hello
   sweetheart

Creating an Empty File: ``touch``
---------------------------------

.. code-block:: console

   $ touch file.txt

Removing A File: ``rm``
-----------------------

.. sidebar:: Documentation

   * `man -s 1 rm <https://man7.org/linux/man-pages/man1/rm.1.html>`__

* Remove a file

  .. code-block:: console

     $ rm /tmp/a-file-containing-hallo

* Remove a file, but no :doc:`../permissions/basics`

  .. code-block:: console

     $ rm /etc/passwd
     rm: remove write-protected regular file '/etc/passwd'? y
     rm: cannot remove '/etc/passwd': Permission denied

* Remove a file, suppressing the stupid question

  * |longrightarrow| still fails with ``/etc/passwd`` because owned by
    ``root``)
  * Succeeds though if owned by myself but not writeable

  .. code-block:: console

     $ rm -f /etc/passwd
     rm: cannot remove '/etc/passwd': Permission denied

Removing A Directory: ``rmdir``, ``rm -r``
------------------------------------------

.. sidebar:: Documentation

   * `man -s 1 rmdir
     <https://man7.org/linux/man-pages/man1/rmdir.1.html>`__

* ``rmdir``: remove directory - provided that it is *empty*

  .. code-block:: console

     $ rmdir /tmp/a-directory

* ``rmdir`` fails if directory not empty

  (remember, we recently created ``/tmp/an/entire/hierarchy``)

  .. code-block:: console

     $ rmdir /tmp/an/entire
     rmdir: failed to remove '/tmp/an/entire': Directory not empty

  * Solution 1 (no!): bottom up
  
    * Use ``rm`` to remove files from leaf directories
      |longrightarrow| make them empty
    * Use ``rmdir`` to remove empty leaf directories
    * Repeat one leavel up until all is done

  * Solution 2 (better): shorthand for Solution 1 - ``rm -r``

    .. code-block:: console

       $ rm -r /tmp/an/entire

