.. meta::
   :description: Slide material: SSH basics
   :keywords: linux, ssh, ssh-keygen, password authentication,
              authentication, training, key based authentication,
              remote login

.. include:: <mmlalias.txt>


SSH: Basics
===========

.. contents::
   :local:

Overview
--------

**Secure Shell**: *secure* login to remote computers

* *Unencrypted* protocols, like ``rsh``, ``rlogin``, ``telnet``, ...
* |longrightarrow| passwords readable on the wire
* |longrightarrow| NSA must have it a bit harder!
* |longrightarrow| SSH

**Focus**

* SSH is a protocol (primarily, at least))
* Main task: authentication and encryption
* Main usage: *remote login*
* Further usages

  * Copy data over the wire (``scp``)
  * File transfer (``sftp``). Also usable as a *network file system*
    (|longrightarrow| ``sshfs``/FUSE)
  * Port forwarding
  * Tunneling (a.k.a VPN)
  * ...

Login
-----

.. sidebar::

   If the SSH daemon runs on a non-default (22) port, you use the ``-p
   <portno>`` (lowercase "p") option. For example:

   .. code-block:: console

      $ ssh -p 2020 jfasch@home.com

**Logging in as user** ``jfasch``

.. code-block:: console

   $ ssh jfasch@home.com

**Logging in under the same username as local**

.. code-block:: console

   $ ssh home.com

**Logging in and executing a remote command** (using one's login
shell)

.. code-block:: console

   $ ssh jfasch@home.com ls -l
   $ ssh jfasch@home.com 'ps -efl | grep sshd'    # quoting necessary: '|' is a shell metacharacter

Exit Status, ``stdin``, ``stdout``: Scripting
---------------------------------------------

**Exit status of the remote command is propagated**

.. code-block:: console

   $ ssh jfasch@home.com rm -f /etc/passwd
   rm: unable to remove `/etc/passwd': Permission denied
   $ echo $?
   1

**Standard Input, Output (und Error) are propageted, too**

.. code-block:: console

   $ { echo hallo; echo hello; } | \
     ssh jfasch@home.com cat | \
     wc -l

.. note::

   * Only the middle part of the pipeline (``ssh cat``) runs on the
     remote computer
   * ``wc -l`` runs locally

