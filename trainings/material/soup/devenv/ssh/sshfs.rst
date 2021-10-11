.. include:: <mmlalias.txt>

.. meta::
   :description: SSHFS: SSH File System
   :keywords: linux, ssh, file system, network file system, training

SSH File System (``sshfs``)
===========================

.. ot-topic:: devenv.ssh.sshfs
   :dependencies: devenv.ssh.basics

.. contents::
   :local:

What Is It?
-----------

* Yet another network file system. Much like SMB and NFS, but simpler.
* Requires a working SSH login on the remote machine
* Implemented as File System in Userspace (`Wikipedia
  <https://en.wikipedia.org/wiki/Filesystem_in_Userspace>`__, `Linux
  kernel
  <https://www.kernel.org/doc/html/latest/filesystems/fuse.html>`__). Regular
  userspace program, sitting on top of

  * The SSH libraries |longrightarrow| authentication, encryption, ...
  * The kernel's filesystem layer |longrightarrow| mounting,
    permissions, ...

Why Is It?
----------

**Question**: why not use ``scp`` (:doc:`here <scp>`) to copy data
back and forth?

**Answers**

* ``scp`` is fine to *copy* data, but it won't let me remove
  anything. ``ssh me@there 'rm ~/a/random/file'`` is not an option.
* Copying is not enough. I want to use ``find`` on a remote tree,
  without being logged in. (Yes I know, remotely crawling a tree is
  slow.)
* I want to use <insert whatever tool> that I have on my machine. The
  tool does not exist for ARM, nor do I want to deploy anything on the
  device.
* I don't want to be bothered with all that, I'm decadent.

Installation
------------

.. code-block:: console
   :caption: Debianish (e.g. Ubuntu, Raspberry OS)

   # apt install fuse-sshfs

.. code-block:: console
   :caption: Fedorish

   # dnf install sshfs

Example Situation: The Raspi
----------------------------

* I have a Raspi with an IP address of ``192.168.1.142``. Substitute
  that with a real embedded device you are working with - the
  principles are the same for that matter.
* The ``sshd`` service is enabled on the Raspi
* ``jfasch`` is my account there. I have :doc:`configured public key
  authentication <basics>`, but *this is not required*.

**What I want:**

Say I have an application running on the Raspi which produces amounts
of log data into ``$HOME`` that I want to inspect/manipulate/whatever
(you'll find a usecase for you I'm really bad at creating artificial
problems).

* I want to *mount* the Raspi log data directory, ``$HOME/logdata``,
  to my local machine.
* I want the directory to appear locally, under
  ``$HOME/raspi-logdata``.

Mounting Remote  ``$HOME/logdata``
----------------------------------

* Create a local mountpoint

  .. code-block:: console
  
     $ mkdir ~/raspi-logdata

* Mount remote directory

  .. code-block:: console
  
     $ sshfs 192.168.1.142:logdata ~/raspi-logdata/

  .. note::

     I did not specify a username for the remote login. ``sshfs`` (and
     `ssh`` in general) assumes in this case that the remote username
     equals the name that I am logged in under locally. It acts as if
     I had said,

     .. code-block:: console

	$ sshfs jfasch@192.168.1.142:logdata ~/raspi-logdata/

* From here on, we'll be using *local tools* only. ``ls -l`` for
  example, or ``rm``.

  .. code-block:: console
  
     $ ls -l ~/raspi-logdata/
     total 16
     -rw-r--r--. 1 1001 1001 4096 Sep 21 16:57 data-0.log
     -rw-r--r--. 1 1001 1001 4096 Sep 21 16:57 data-1.log
     -rw-r--r--. 1 1001 1001 4096 Sep 21 16:57 data-2.log
     -rw-r--r--. 1 1001 1001 4096 Sep 21 16:57 data-3.log

  .. code-block:: console
  
     $ rm ~/raspi-logdata/data-{0,1}.log 

Unmounting: ``fusermount -u``, or Simply ``umount``
---------------------------------------------------

* The "canonical" way to unmount FUSE filesystems is,

  .. code-block:: console

     $ fusermount -u ~/raspi-logdata

  (man page `here
  <https://man7.org/linux/man-pages/man1/fusermount3.1.html>`__)

* On newer systems (well, it's been a while since they built FUSE
  functionality into ``umount``), one can use the regular/historic way
  of unmounting,

  .. code-block:: console

     $ umount ~/raspi-logdata

User ID Mismatch: Problem
-------------------------

**Potential problem: numeric file and group owners**

When I mounted the remote directory, I did not specify a remote
username - SSH chose that the remote username be ``jfasch``, which is
what I am logged in as locally.

Gotcha:

* The local and remote user IDs need not necessarily match
* On the Raspi, user ``pi`` has ID 1000. ``jfasch`` is 1001
* Locally, ``jfasch`` is 1000

.. code-block:: console
   :caption: Local UID

   $ id -u jfasch
   1000

.. code-block:: console
   :caption: Remote UID

   $ id -u jfasch
   1001

.. note::

   Unix, at the system level, does not care about *names*, but only
   about *numbers*. Users and groups have names which are defined in
   ``/etc/passwd`` and ``/etc/group``, but which resolve to numbers
   for all system level operations.

**Effect**: no names, but only IDs 

.. code-block:: console

   $ ls -l ~/raspi-logdata/
   ...
   -rw-r--r--. 1 1001 1001 4096 Sep 21 16:57 data-0.log
   ...

.. attention::

   User ID 1001 might locally resolve to an *existing local user*,
   with the implication that that user would be granted permission on
   *your* files.

User ID Mismatch: Solution (User Mapping)
-----------------------------------------

*Long story short*: present remote files as locally owned by local
user (and group which is also 1000, for that matter),

.. code-block:: console

   $ sshfs -o idmap=user -o uid=1000 -o gid=1000

Or, more generic |:astonished:|

.. code-block:: console

   $ sshfs -o idmap=user -o uid=$(id -u) -o gid=$(id -g)

