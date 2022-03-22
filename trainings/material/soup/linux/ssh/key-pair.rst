.. ot-topic:: linux.ssh.key_pair
   :dependencies: linux.ssh.basics, 
		  linux.basics.intro.login

.. meta::
   :description: Slide material: SSH key pairs
   :keywords: linux, ssh, ssh-keygen, password authentication,
              authentication, training, key based authentication,
              remote login

.. include:: <mmlalias.txt>


SSH: Public Key Authentication
==============================

.. contents::
   :local:

Why?
----

Password authentication is insecure:

* Man-in-the-Middle (MITM) attacks
* Brute force attacks to guess passwords

... and uncomfortable: have to type password over and over

* *Public key* deployed to server
* *Private key* remains local, in one's personal locked safe ideally

Local Setup, Key Generation
---------------------------

**On the client** (your work machine, the machine you log in from),
 ...

* Create SSH config directory - ``.ssh`` - in ``$HOME`` (if not
  already in place), and *set permissions so nobody else can look
  into* (we will store key material here):

  .. code-block:: console

     $ mkdir ~/.ssh
     $ chmod 700 ~/.ssh

* Create key pair (by default ``id-rsa*``) in ``~/.ssh``:

  .. code-block:: console

     $ cd ~/.ssh
     $ ssh-keygen -t rsa
     Generating public/private rsa key pair.
     ...

Key Pair?
---------

* ``~/.ssh/id_rsa.pub``

  *Public key*: deployed to remote machine

  * Send email (or otherwise transfer) to remote machine's
    administrator
  * Ask them to set it up for you

* * ``~/.ssh/id_rsa``

  *Private key*; remains local - **in your safe**

  .. danger::

     The *private key* is **your secret**, and must not be disclosed
  
     * Careful with your ``~/.ssh``

       * ``~/.ssh`` **is your private safe**
       * The ``ssh`` program refuses to work if permissions are too
         wide
       * **But**: can you trust ``root``?
  
     * *Careful where you store backups!*

       * Can you trust the cloud?

Remote Setup (Wearing The Remote Admin's Hat) 
---------------------------------------------

* Receive the user's public key
* In the user's home directory, create a ``.ssh`` directory

  As opposed the situation on the user's *local* machine, the
  permissions can be left open (there is no private key material
  there)

* Append the user's key to ``~/.ssh/authorized_keys`` (a create the
  file if not yet inplace)

What Else?
----------

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
