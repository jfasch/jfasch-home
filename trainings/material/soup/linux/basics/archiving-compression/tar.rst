.. include:: <mmlalias.txt>


``tar``
=======

.. contents::
   :local:

Basics
------

.. sidebar::

   **Documentation**

   * `man -s 1 tar
     <https://man7.org/linux/man-pages/man1/tar.1.html>`__

* Archives files and directories
* ... togehter with all other UNIX entry types (|longrightarrow| UNIX
  specific)
* Does not compress by itself |longrightarrow| pipe

**Modes**

* Pack (``-c`` ... "create")

  .. code-block:: console

     $ tar -c -f file.tar directory}

* Unpack (``-x`` ... "extract")

  .. code-block:: console

     $ tar -x -f file.tar

* View (``-t`` ... "tell")

  .. code-block:: console

     $ tar -t -f file.tar

Creating And Viewing Archives
-----------------------------

Takes a list of input directories, and adds them to the archive.

.. code-block:: console

   $ cd /usr/src/linux
   $ tar -c -f /tmp/filesystems.tar Documentation/filesystems
   $ tar -t -f /tmp/filesystems.tar
   Documentation/filesystems/
   Documentation/filesystems/ceph.txt
   Documentation/filesystems/gfs2.txt
   Documentation/filesystems/quota.txt
   ...

(De)Compression
---------------

As a convenience measure, ``tar`` is also capable of compressing what
it creates. The following calls are equivalent:

.. code-block:: console

   $ tar -c -f file.tar.gz -z directory
   $ tar -zcf file.tar.gz directory
   $ tar -c -f - directory | gzip > file.tar.gz

Decompression likewise:

.. code-block:: console

   $ tar zxf file.tar.gz
   $ tar ztf file.tar.gz
   $ gzip -cd file.tar.gz | tar tf -

Etiquette
---------

* **Caution**: ``tar`` unpacks into the current working directory
  (unless you give ``-C`` to change CWD)

  * |longrightarrow| use ``tar -t -f ...`` prior to unpacking
  * If there are many toplevel entries, you'll be pouring a can of
    dirt into your livingroom

    .. code-block:: console

       $ tar ztf file.tar.gz

  * |longrightarrow| grumble, create subdirectory, and unpack there

* *Be nice to others*: always take care to archive *only one* toplevel
  directory
* Refuses to add *absolute paths* to the archive

  .. code-block:: console

     $ tar cf /tmp/jfasch.tar /home/jfasch
     tar: Removing leading `/' from member names
     ...

Option Summary
--------------

.. sidebar::

   **Documentation**

   * `man -s 1 tar
     <https://man7.org/linux/man-pages/man1/tar.1.html>`__

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Option
     * Description
   * * ``-c``
     * (c)reate archive
   * * ``-x``
     * e(x)tract archive
   * * ``-t``
     * (t)ell archive content
   * * ``-f file``
     * From/to file (special filename "-" for ``stdin``/``stdout``)
   * * ``-v``
     * Verbose
   * * ``-vv``
     * More verbose
   * * ``-z``
     * Use ``gzip`` for (de)compression
   * * ``-j``
     * Use ``bzip2`` for (de)compression
   * * ``-C``
     * (C)hange directory before you begin
   * * ``-T file``
     * Read list of entries from ``file`` ("-" to read from ``stdin``)

Being Creative With The Pipe
----------------------------

* Using ``tar`` to copy one directory to another

  .. code-block:: console

     $ tar -cf - -C one-directory . | \
            tar -xf - -C another-directory

* Using ``ssh`` remote command execution (see :doc:`here
  <../../ssh/basics>`) to transfer an archive on the fly

  .. code-block:: console

     $ tar -jcf - -C ein-directory . | \
            ssh server 'tar -jxf - -C anderes-directory'

* Dynamically creating a file list which ``tar`` reads from ``stdin``

  .. code-block:: console

     $ ( cd /usr/src/linux; \
            find -name \*.h -o -name \*.c | \
            tar -cf - -T - ) | \
          tar -xf - -C anderes-directory
