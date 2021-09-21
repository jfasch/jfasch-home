.. include:: <mmlalias.txt>

.. meta::
   :description: Slide material: SSH basics
   :keywords: linux, ssh, ssh-keygen, password authentication,
              authentication, training, key based authentication,
              remote login


SSH: Basics
===========

.. ot-topic:: devenv.ssh.basics

.. contents::
   :local:

SSH: Overview (1)
-----------------

**Secure Shell**: *secure* login to remote computers

* *Unencrypted* protocols, like ``rsh``, ``rlogin``, ``telnet``, ...
* |longrightarrow| passwords readable on the wire
* |longrightarrow| NSA must have it a bit harder!
* |longrightarrow| SSH

SSH:Overview (2)
----------------

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

SSH: Login (1)
--------------

**Logging in as user \texttt{jfasch}**

.. code-block:: console

   $ ssh jfasch@home.com

**Logging in under the same username as local**

.. code-block:: console

   $ ssh home.com

**Logging in and executing a remote command** (using one's login
  shell)**

.. code-block:: console

   $ ssh jfasch@home.com ls -l}
   $ ssh jfasch@home.com 'ps -efl | grep sshd'    # quoting necessary: '|' is a shell metacharacter

SSH: Exit Status, ``stdin``, ``stdout``
---------------------------------------

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

SSH: Public Key Authentication (1)
----------------------------------

Password authentication is insecure:

* Man-in-the-Middle (MITM) attacks
* Brute force attacks to guess passwords

... and uncomfortable: have to type password over and over

* *Public key* deployed to server
* *Private key* remains local, in one's personal locked safe ideally

SSH: Public Key Authentication (2)
----------------------------------

.. code-block:: console

   $ ssh-keygen -t rsa
   Generating public/private rsa key pair.
   ...

* *Public key* ``~/.ssh/id_rsa.pub`` is deployed to the server: append
  it to ``~/.ssh/authorized_keys``.
* *Private key* ``~/.ssh/id_rsa`` remains local.

SSH: Public Key Authentication (3)
----------------------------------

* *Passphrase* provides additional safeguard, should the private key
  get lost
* |longrightarrow| *Drawback*: login becomes interactive again
  (although on a different level)
* Omitting passphrase: answer prompt empty, twice
* ``ssh-agent``: managing passphrases

  * Remembers passphrase in memory, *safely*
  * ``ssh`` talks to agent when passphrase needed

* *Permissions* of ``~/.ssh`` - and contained files - are
  important. If permissions are too open (others could read
  credentials, other could write/modify), ``ssh`` will complain loudly
  and refuse to work.
