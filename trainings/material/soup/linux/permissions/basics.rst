.. include:: <mmlalias.txt>


Basics: Mode, User and Group Ownership
======================================

.. contents::
   :local:

.. sidebar:: Topic

   .. jf-topic:: linux.permissions.basics

Owner and Permissions
---------------------
  
**Types of permissions**
  
* Read (``r``)
* Write (``w``)
* Execute (``x``)
  
**Separate permissions for ...**

* User (``u``): the owning user of the entry
* Group (``g``): the owning group of the entry
* Others (``o``): all others

A Simple Example
----------------

The typical ``ls -l`` output:

.. code-block:: console

   $ ls -l tasks.csv
   -rw-rw-r-- 1 jfasch team 396 Jun  8 14:49 tasks.csv

Three groups of "bits": ``rw-``, ``rw-``, ``r--``

.. list-table::
   :align: left
   :header-rows: 1

   * * Bits
     * Meaning
   * * ``rw-``
     * Read- and writable for owning *user* (``jfasch``)
   * * ``rw-``
     * Read- and writable for owning *group* (``team``)
   * * ``r--``
     * Readable for all *others*: those who are *neither* user
       ``jfasch`` nor belong to group ``team``

First column (``-``) is irrelevant (type: *regular file*)

Permission Check: User
----------------------

**Can user ``jfasch`` write the file?**

* Which triplet to check?

  * ``jfasch`` is the owner of the file
  * |longrightarrow| The first triplet: ``rw-``

* |longrightarrow| yes, ``jfasch`` can write
* (likewise, ``jfasch`` will be able to read)

Permission Check: Group
-----------------------

**Can user ``teammember42`` write the file?**

* Which triplet to check?

  * ``teammember42`` *is not* ``jfasch`` |longrightarrow| *not* the
    first triplet
  * Is ``teammember42`` a member of group ``team``?

    .. code-block:: console

       $ id teammember42 
       uid=1001(teammember42) gid=1002(teammember42) groups=1002(teammember42),1001(team)

    * Answer: *yes*
    * |longrightarrow| second triplet, ``rw-``

* |longrightarrow| yes, ``teammember42`` can write
* (likewise, ``teammember42`` will be able to read)
    
Permission Check: Others
------------------------

**Can user ``manfromthestreet`` read the file?**

* Which triplet to check?

  * ``manfromthestreet`` *is not* ``jfasch`` |longrightarrow| *not*
    the first triplet
  * Is ``manfromthestreet`` a member of group ``team``?

    .. code-block:: console

       $ id manfromthestreet
       uid=1002(manfromthestreet) gid=1003(manfromthestreet) groups=1003(manfromthestreet)

    * Answer: *no*
    * |longrightarrow| not the second triplet

  * |longrightarrow| ``manfromthestreet`` is among the *others*

    * Third triplet, ``r--``
    * |longrightarrow| no, ``manfromthestreet`` cannot write
    * (``manfromthestreet`` can read though)



.. .. futoaschbeidl:: jjjj






Execute Permissions
-------------------

.. code-block:: console

   $ ls -l /bin/ls
   -rwxr-xr-x ... /bin/ls

**Facts ...**

* An executable file does not have to end with ``.exe`` to be
  executable
* ... it simply *is* executable

Directory Permissions
---------------------

.. code-block:: console

   $ ls -ld /etc
   drwxr-xr-x ... 07:54 /etc

* Read permissions: *content* (list of names) is readable
* Execute permissions: to access a file (e.g. for reading), one has to
  have *execute permissions* on the parent directory and all
  directories along the path
* *The right to* ``cd`` *into the directory*

Permission Bits, octal
----------------------
  
.. list-table::
   :align: left
   :header-rows: 1

   * * ``ls -l`` Output
     * Binary
     * Shell command
   * * ``-rw-r--r--``
     * ``110100100``
     * ``chmod 0644 <path>``
   * * ``-rw-------``
     * ``110000000``
     * ``chmod 0600 <path>``
   * * ``-rwxr-xr-x``
     * ``111101101``
     * ``chmod 0755 <path>``

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

Shell Commands
--------------

* Permission modification (set to octal value)

  .. code-block:: console
     
     $ chmod 755 /bin/script.sh

* Permission modification (differential symbolic)

  .. code-block:: console
     
     $ chmod u+x,g-wx,o-rwx /bin/script.sh

* Group ownership modification (only root and members of the
  group can do this)

  .. code-block:: console

     $ chgrp team /tmp/file

* Ownership modification (only root)

  .. code-block:: console

     # chown jfasch /tmp/file

* ``chmod``, ``chown``, and ``chgrp`` understand
    ``-R`` for "recursive".

Set-UID Bit
-----------

**Set-UID Bit: motivation**

* *Ugly hack!*
* Encrypted passwords in ``/etc/passwd`` (or ``/etc/shadow``,
  nowadays)
* Only ``root`` can modify
* I (``jfasch``) want to change my password
* Have to ask ``root`` to edit ``/etc/passwd`` or ``/etc/shadow`` for
  me
* ``root`` is annoyed by me

.. code-block:: console

   $ ls -l /bin/passwd 
   -rws--x--x 1 root root ... /bin/passwd

Sticky Bit
----------

**Sticky bit: motivation**

* *Ugly hack!*
* Everyone has write permissions in ``/tmp``

  * |longrightarrow| everyone can create files
  * |longrightarrow| everyone can remove files

* Chaos: everyone can remove each other's files

.. code-block:: console

   $ ls -ld /tmp
   drwxrwxrwt ... /tmp

