.. include:: <mmlalias.txt>


SetUID Programs: ``passwd``, ``sudo``, ...
==========================================

.. contents::
   :local:

Problem: Change My Password
---------------------------

* ``/etc/passwd``: Unix user database

  .. code-block:: console
     :caption: ``/etc/passwd`` structure

     $ grep jfasch /etc/passwd
     jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash

  .. code-block:: console
     :caption: ``/etc/passwd`` permissions

     $ ls -l /etc/passwd
     -rw-r--r--. 1 root root 2691 Nov  2 10:01 /etc/passwd

  |longrightarrow| not writeable
	       
* Column 1 - ``"x"`` - means "Encrypted password is in
  ``/etc/shadow``" |longrightarrow| no need to write ``/etc/passwd``,
  alas

  .. code-block:: console
     :caption: ``/etc/shadow`` permissions

     $ ls -l /etc/shadow
     ----------. 1 root root 1317 Nov  2 10:01 /etc/shadow

  |longrightarrow| *not even readable!*

* **Problem**: I cannot change my password

  Only ``root`` can do that

* **Solution**: ask ``root`` to change my password

  Send the output of this command to ``root``, and ask her to enter it
  into ``/etc/shadow``:

  .. code-block:: console

     $ openssl passwd -6 -salt my-cool-salt
     Password: <... enter cleartext password ...>
     $6$my-cool-salt$MDMCKQvPfaqqUqyPVZjjkIhsBKKcNIOgKNXtiOBvBFw8u7zUF3.0g2RQR9CnyDnQQ5Unt/Wpu8jyZeUXKTApl0

* **Problem**: imagine 100 users doing this per day |longrightarrow|
  ``root`` burnout!

Solution: Set-UID Bit
---------------------

.. note::

   First off: **ugly hack** with severe security implications

* Turns out I (as ``jfasch``) *can* change my password

  .. code-block:: console

     $ passwd
     Changing password for user jfasch.
     Current password:
     New password:
     Retype new password: 

  |longrightarrow| Done!

* How come? |longrightarrow| Set-UID

  .. code-block:: console

     $ which passwd
     /usr/bin/passwd
     [jfasch@fedora ~]
     $ ls -l /usr/bin/passwd 
     -rwsr-xr-x. 1 root root 32712 Jan 30  2021 /usr/bin/passwd

  |longrightarrow| "s", a-ha

Set-UID: How Does It Work?
--------------------------

* Another bit in the "mode" bitmask

  * 32 available
  * 9 reserved for the ``rwxrwxrwx`` game (see :doc:`basics`)

* When that bit (the *set-UID bit*) is set, the process's *effective
  user ID* becomes that of the *owner* of the file program

  * In the case of ``/usr/bin/passwd``, this would be ``root``
    (UID: 0)
  * A program owned by ``jfasch`` would run with that user's
    privileges, no matter who executed it

Command: ``chmod``
------------------

.. code-block:: console

   $ chmod 4755 program

... or ...

.. code-block:: console

   $ chmod u+s program

Set-UID Is Not A Toy!
---------------------

See :doc:`setuid-livedemo`
