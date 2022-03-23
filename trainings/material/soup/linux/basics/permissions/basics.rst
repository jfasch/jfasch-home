.. ot-topic:: linux.basics.permissions.basics
   :dependencies: linux.basics.shell.ls

.. include:: <mmlalias.txt>


Mode, User and Group Ownership
==============================

.. sidebar:: Documentation

   *Tune Permissions*

   * `man -s 1 chmod <https://linux.die.net/man/1/chmod>`__

   *Change Ownership*

   * `man -s 1 chgrp <https://linux.die.net/man/1/chgrp>`__
   * `man -s 1 chown <https://linux.die.net/man/1/chown>`__

   *Create and Modify Users and Groups*

   * `man -s 8 useradd
     <https://man7.org/linux/man-pages/man8/useradd.8.html>`__
   * `man -s 8 groupadd
     <https://man7.org/linux/man-pages/man8/groupadd.8.html>`__
   * `man -s 8 usermod
     <https://man7.org/linux/man-pages/man8/usermod.8.html>`__
   * `man -s 8 groupmod
     <https://man7.org/linux/man-pages/man8/groupmod.8.html>`__

.. contents::
   :local:

Owner and Permissions
---------------------
  
**Types of permissions**
  
* Read (``r``)
* Write (``w``)
* Execute (``x``)
  
**Separate permissions for ...**

* User (``u``): the owning *user* of the entry
* Group (``g``): the owning *group* of the entry
* Others (``o``): all others

A Simple Example
----------------

.. sidebar:: Teacher's note: create that constellation (as root)

   .. code-block:: console

      # groupadd team
      # useradd --groups team --home-dir /home/teammember42 --create-home teammember42
      # usermod --append --groups team jfasch
      $ touch tasks.csv
      $ chmod 664 tasks.csv
      $ chgrp team tasks.csv

* Group ``team``
* User ``jfasch``, member (among possibly others) of group ``team``
* User ``teammember42``, also member of group ``team``
* User ``manfromthestreet``, *not* member of group ``team``

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
     * Read- and writable for (members of) owning *group* (``team``)
   * * ``r--``
     * Readable for all *others*: those who are *neither* user
       ``jfasch`` nor belong to group ``team``

First column (``-``) is irrelevant (it's the type: *regular file*)

Permission Check: User
----------------------

**Can user** ``jfasch`` **write the file?**

* Which triplet to check?

  * ``jfasch`` is the owner of the file
  * |longrightarrow| The first triplet: ``rw-``

* |longrightarrow| yes, ``jfasch`` can write
* (likewise, ``jfasch`` will be able to read)

Permission Check: Group
-----------------------

**Can user** ``teammember42`` **write the file?**

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

**Can user** ``manfromthestreet`` **read the file?**

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

Programs: Execute Permissions
-----------------------------

**What makes a file a program?**

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
   drwxr-xr-x 1 root root 4882 Mar 22 12:20 /etc

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

Shell Commands: Tuning Permissions
----------------------------------

* Permission modification (set to octal value, absolutely, the whole
  bitmask no matter what)

  .. code-block:: console

     $ ls -l /bin/script.sh
     -rw-rw-r-- 1 jfasch jfasch 612 Mar 23 18:39 script.sh
     $ chmod 755 /bin/script.sh
     -rwxr-xr-x 1 jfasch jfasch 0 Mar 23 18:39 script.sh

* Permission modification (differential symbolic)

  .. code-block:: console
     
     $ ls -l /bin/script.sh
     -rw-rw-r-- 1 jfasch jfasch 612 Mar 23 18:39 script.sh
     $ chmod u+x,g-w,g+x,o+x script.sh 
     $ ls -l script.sh 
     -rwxr-xr-x. 1 jfasch jfasch 0 Mar 23 18:42 script.sh

Shell Commands: Changing User/Group Ownership
---------------------------------------------

* Group ownership modification (only root and members of the group can
  do this)

  .. code-block:: console

     $ chgrp team /tmp/file

* Ownership modification (only root)

  .. code-block:: console

     # chown jfasch /tmp/file

* ``chmod``, ``chown``, and ``chgrp`` understand ``-R`` for
  "recursive".
