.. include:: <mmlalias.txt>


Login? What Is That?
====================

.. contents::
   :local:

Authentication: Prompting The User For Login Data
-------------------------------------------------

* Different login programs

  * *GNOME Display Manager* (graphical login)
  * *SSH Daemon* ("secure shell", network login)
  * *getty* (console/serial terminal login)
  * ...

* Login process verifies that user the is who she claims to be

  * Username and password
  * Username and public/private key (see
    :doc:`/trainings/material/soup/linux/ssh/key-pair`)
  * Username and token (Kerberos/Active directory)
  * ...

.. list-table::
   :align: left
   :header-rows: 1

   * * GNOME3 login (gdm)
     * Console login (``agetty``)
     * SSH login
   * * .. image:: gdm-wayland.png
          :scale: 40%
     * .. image:: console_login_ubuntu.png
          :scale: 60%
     * .. code-block:: console

          $ ssh jfasch@192.168.1.147
	  jfasch@192.168.1.147's password: 

Authentication: Verification Of Login Data
------------------------------------------

* Authentication information has been prompted |longrightarrow|
  username, password (lets stick with the simplest case).
* Does the user exist?

  .. code-block:: console

     $ grep jfasch /etc/passwd
     jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash

  |longrightarrow| |:thumbsup:| 

  (See below for meaning of single fields)

* Does the user-supplied cleartext password match the encrypted
  password?

  .. note::

     If field #2 (password) is equal to ``x``, then the user's
     encrypted password can found in ``/etc/shadow``. (Only readable
     by ``root``, as a security measure against brute force password
     cracking attacks.)

And After Successful Authentication?
------------------------------------

Following successful authentication, the user is being *logged
in*. *What does that mean?*

* User metadata (taken from ``/etc/passwd``)

  .. code-block:: console

     $ grep jfasch /etc/passwd
     jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash

  * Username: ``jfasch``
  * Password: ``x``
  * UID: ``1000``
  * GID (primary group): ``1000`` (nowadays every user has her own
    group)
  * Description: ``Joerg Faschingbauer``
  * Home directory: ``/home/jfasch``
  * Login shell: ``/bin/bash``

* I was successfully authenticated |longrightarrow| I want

  * My configured login shell (``/bin/bash``) 
  * In my home directory (``/home/jfasch``)
  * Running as myself (UID ``1000``, GID ``1000``, supplementary
    groups from ``/etc/group`` btw.)

Impersonation
-------------

.. sidebar:: Documentation

   * `man -s 2 setuid
     <https://man7.org/linux/man-pages/man2/setuid.2.html>`__

* Login process runs as ``root`` - necessary to *impersonate as the
  user*

  * |longrightarrow| System call ``setuid()`` (or executing a
    :doc:`"setuid program" <../permissions/setuid>`)
  * Only possible for ``root``
  * "Hey kernel, I don't want to be ``0`` anymore, let me be ``1000``
    from now on

  As ``1000``,

  * Change current working directory to ``/home/jfasch``
  * Execute ``/bin/bash``

* Done

Logged In, Finally
------------------

.. sidebar:: Documentation

   * `man -s 1 id <https://man7.org/linux/man-pages/man1/id.1.html>`__

* Finally, when a user is logged in, they get presented a shell (their
  *login shell*).
* All commands that they run *inherit* (:doc:`process-tree`) their
  credentials from their login shell
* |longrightarrow| UID, GID, (supplementary) groups

To find out who you are, you can use the ``id`` command:

.. code-block:: console

   $ id
   uid=1020(joerg.faschingbauer) gid=1020(joerg.faschingbauer) groups=1020(joerg.faschingbauer),1021(ece20)
