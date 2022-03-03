.. ot-topic:: linux.basics.permissions.setuid_livedemo
   :dependencies: linux.basics.permissions.setuid

.. include:: <mmlalias.txt>


SetUID: Live Demo
=================

Real and Effective User ID
--------------------------

* Across ``setuid()`` (either via system call or the setuid bit), the
  original user ID (where we came from) is remembered |longrightarrow|
  *effective* user ID
* The user ID that was changed to is the *real* user ID. *It is this
  user ID that defines the process's permissions!*

.. list-table::
   :align: left

   * * .. code-block:: c

          #include <unistd.h>
          #include <sys/types.h>
       
          uid_t getuid(void);
          uid_t geteuid(void);

     * `man getuid <https://man7.org/linux/man-pages/man2/geteuid.2.html>`__

Sample Program
--------------

.. literalinclude:: uid.c
   :language: c

* Build

  .. code-block:: console

     $ gcc -o uid uid.c

* Look

  .. code-block:: console

     $ ls -l uid
     -rwxrwxr-x. 1 jfasch jfasch 24456 Mar  3 14:34 uid
     $ id -u jfasch
     1000

* Run

  .. code-block:: console

     $ ./uid
     1000
     1000

Set-UID ``jfasch``?
-------------------

* Set the Set-UID bit

  .. code-block:: console

     $ chmod 4755 uid

  ... or ...

  .. code-block:: console

     $ chmod u+s uid

* Look

  .. code-block:: console

     $ ls -l uid
     -rwsr-xr-x. 1 jfasch jfasch 24456 Mar  3 14:34 uid

* Run as user ``jfasch`` |longrightarrow| no difference (obviously)

  $ ./uid 
  1000
  1000

* Run as user ``someone-else`` (using ``sudo`` |:thinking:|)

  .. code-block:: console

     $ id -u someone-else 
     1001
     $ sudo -u someone-else ./uid 
     [sudo] password for jfasch: 
     1001
     1000

  .. caution::

     A program that is Set-UID *myself* could for example, if it
     wanted, remove my home directory!

* Run as ``root``

  .. code-block:: console

     $ sudo ./uid 
     0
     1000

Set-UID ``root``? Danger!
-------------------------

* Let ``root`` own program, and run (|longrightarrow| still runs as
  ``jfasch``)

  .. code-block:: console

     $ sudo chown root uid
     $ ls -l uid
     -rwxr-xr-x. 1 root jfasch 24456 Mar  3 14:34 uid
     $ ./uid
     1000
     1000

* Set-UID ``root``

  .. code-block:: console

     $ sudo chmod u+s uid
     $ ls -l uid
     -rwsr-xr-x. 1 root jfasch 24456 Mar  3 14:34 uid

* Run

  .. code-block:: console

     $ ./uid 
     1000
     0
     
.. caution::

   A program that is Set-UID *root* could for example, if it wanted,
   erase the entire disk!
