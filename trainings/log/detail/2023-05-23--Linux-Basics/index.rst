.. include:: <mmlalias.txt>


Linux Basics (2023-05-23 - 2023-05-25)
======================================

.. toctree::
   :hidden:

   agenda

.. contents::
   :local:

.. sidebar::

   * Start: Tuesday, 8:30
   * :doc:`/trainings/material/soup/linux/basics/index`
   * Original agenda: :doc:`agenda`

Day 1
-----

Setup
.....

Please create SSH key as described `here
<https://www.ssh.com/academy/ssh/putty/windows/puttygen>`__, and send
me the *public key*.

:doc:`/trainings/material/soup/linux/ssh/basics`

Introduction: Concepts and Terminology
......................................

From :doc:`/trainings/material/soup/linux/basics/intro/index`

* :doc:`/trainings/material/soup/linux/basics/intro/overview`
* :doc:`/trainings/material/soup/linux/basics/intro/demo-everything-is-a-file`
* :doc:`/trainings/material/soup/linux/basics/intro/process`
* :doc:`/trainings/material/soup/linux/basics/intro/process-tree`
* :doc:`/trainings/material/soup/linux/basics/intro/environment`

The Shell (Bash - “Bourne Again Shell”)
.......................................

From :doc:`/trainings/material/soup/linux/basics/shell/index`

* :doc:`/trainings/material/soup/linux/basics/shell/paths`
* :doc:`/trainings/material/soup/linux/basics/shell/special-paths`
* :doc:`/trainings/material/soup/linux/basics/shell/ls`
* :doc:`/trainings/material/soup/linux/basics/shell/cwd`
* :doc:`/trainings/material/soup/linux/basics/shell/file_dir_create_rm`

Day 2
-----

The Shell (Bash - “Bourne Again Shell”)
.......................................

From :doc:`/trainings/material/soup/linux/basics/shell/index`

* :doc:`/trainings/material/soup/linux/basics/shell/cp`
* :doc:`/trainings/material/soup/linux/basics/shell/mv`
* :doc:`/trainings/material/soup/linux/basics/shell/links`
* :doc:`/trainings/material/soup/linux/basics/shell/configfiles`

Exercise time (from
:doc:`/trainings/material/soup/linux/basics/shell/exercises/index`)

* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/index`

Tools: Inspecting Text Files
............................

From :doc:`/trainings/material/soup/linux/basics/text-tools/index`

* :doc:`/trainings/material/soup/linux/basics/text-tools/overview`
* :doc:`/trainings/material/soup/linux/basics/text-tools/cat`
* :doc:`/trainings/material/soup/linux/basics/text-tools/head-tail`
* :doc:`/trainings/material/soup/linux/basics/text-tools/cut`
* :doc:`/trainings/material/soup/linux/basics/text-tools/less`
* :doc:`/trainings/material/soup/linux/basics/text-tools/grep`
* :doc:`/trainings/material/soup/linux/basics/text-tools/find`
* :doc:`/trainings/material/soup/linux/basics/text-tools/exercises`

File System Permissions
.......................

From :doc:`/trainings/material/soup/linux/basics/permissions/index`

* :doc:`/trainings/material/soup/linux/basics/permissions/basics`
* :doc:`/trainings/material/soup/linux/basics/permissions/exercises/index`

Day 3
-----

Morning Wakeup
..............

* Package installation

  * ``bash`` from source

    * `Clone from Github <https://github.com/bminor/bash>`__
    * Build (read `INSTALL
      <https://github.com/bminor/bash/blob/master/INSTALL>`__)
    * Install (``make && make install``)

  * ``coreutils`` from source

    * `Clone from Github <https://github.com/coreutils/coreutils>`__
    * Build |longrightarrow| build-time dependencies fail (wtf is
      ``autopoint``?)

  * The problems that are solved by package management systems such as
    Debian (``.deb``) and Redhat (``.rpm``)
  * Dependency management
  * And Flatpak?

* File locking? (`man -s 2 fcntl
  <https://man7.org/linux/man-pages/man2/fcntl.2.html>`__)

File System Permissions
.......................

More from
:doc:`/trainings/material/soup/linux/basics/permissions/index`

* :doc:`/trainings/material/soup/linux/basics/permissions/setuid`
* :doc:`/trainings/material/soup/linux/basics/permissions/setuid-livedemo`
* :doc:`/trainings/material/soup/linux/basics/permissions/umask`
* :doc:`/trainings/material/soup/linux/basics/permissions/sticky`

I/O Redirection And Pipes
.........................

From :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/index`

* :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/io-redirection`
* :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/io-redirection-swap-stdout-stderr`
* :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/pipes`
* :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/exercises`

Archiving and Compression
.........................

From :doc:`/trainings/material/soup/linux/basics/archiving-compression/index`

* :doc:`/trainings/material/soup/linux/basics/archiving-compression/overview`
* :doc:`/trainings/material/soup/linux/basics/archiving-compression/gzip`
* :doc:`/trainings/material/soup/linux/basics/archiving-compression/tar`
* :doc:`/trainings/material/soup/linux/basics/archiving-compression/exercises`

Networking
..........

From :download:`Linux Basics PDF
</trainings/material/pdf/010-linux-basics.pdf>`

* ``netstat``
* Netcat (``nc``)

Processes And Scheduling
........................

From :download:`Linux Basics PDF
</trainings/material/pdf/010-linux-basics.pdf>`

SSH: Secure Shell
.................

From :doc:`/trainings/material/soup/linux/ssh/index`

* :doc:`/trainings/material/soup/linux/ssh/basics`
* :doc:`/trainings/material/soup/linux/ssh/key-pair`
* :doc:`/trainings/material/soup/linux/ssh/scp`
* :doc:`/trainings/material/soup/linux/ssh/portforwarding`
* :doc:`/trainings/material/soup/linux/ssh/sshfs`
* :doc:`/trainings/material/soup/linux/ssh/links`
* :doc:`/trainings/material/soup/linux/ssh/exercises/index`

Shell Scripting (at least some of it)
.....................................

From :download:`Shell Scripting PDF
</trainings/material/pdf/100-shell-scripting.pdf>`
