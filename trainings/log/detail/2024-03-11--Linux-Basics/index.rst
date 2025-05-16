.. include:: <mmlalias.txt>


Linux Basics (2024-03-11 - 2024-03-13)
======================================

.. toctree::
   :hidden:

   agenda

.. contents::
   :local:

.. sidebar::

   * Start: Monday 2024-03-11, 8:00AM
   * Original agenda: :doc:`agenda`
   * Material taken from
     :doc:`/trainings/material/soup/linux/basics/index`

Day 1
-----

SSH/Putty Setup
...............

From :doc:`/trainings/material/soup/linux/ssh/index`

* :doc:`/trainings/material/soup/linux/ssh/basics`
* :doc:`/trainings/material/soup/linux/ssh/key-pair`

Exercise
........

Please create SSH key as described `here
<https://www.ssh.com/academy/ssh/putty/windows/puttygen>`__, and send
me the *public key*.

Introduction: Concepts and Terminology
......................................

From :doc:`/trainings/material/soup/linux/basics/intro/index`

* :doc:`/trainings/material/soup/linux/basics/intro/overview`
* :doc:`/trainings/material/soup/linux/basics/intro/process`
* :doc:`/trainings/material/soup/linux/basics/intro/process-tree`
* :doc:`/trainings/material/soup/linux/basics/intro/demo-everything-is-a-file`
* :doc:`/trainings/material/soup/linux/basics/intro/environment`

The Shell (Bash - “Bourne Again Shell”)
.......................................

From :doc:`/trainings/material/soup/linux/basics/shell/index`

* :doc:`/trainings/material/soup/linux/basics/shell/paths`
* :doc:`/trainings/material/soup/linux/basics/shell/special-paths`
* :doc:`/trainings/material/soup/linux/basics/shell/ls`
* :doc:`/trainings/material/soup/linux/basics/shell/cwd`
* :doc:`/trainings/material/soup/linux/basics/shell/file_dir_create_rm`
* :doc:`/trainings/material/soup/linux/basics/shell/cp`
* :doc:`/trainings/material/soup/linux/basics/shell/mv`

Exercises
.........

From
:doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/index`

* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/mkdir-p-rm-r`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/echo-create-files`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/echo-copy-files`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/echo-move-files`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/verify-hierarchy`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/copy-tree`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/rm-tree`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/rm-rf`

Day 2
-----

Morning Wakeup
..............

Quiz |:ninja:|
``````````````

.. list-table::
   :align: left
   :widths: auto

   * * Relative paths start with a '/'
     * 
   * * Relative paths don't start with a '/'
     * 
   * * Absolute paths start with a '/'
     * 
   * * Absolute paths don't start with a '/'
     * 
   * * Absolute paths are relative to the root directory
     * 
   * * '.' refers to the currect working directory
     * 
   * * '..' refers to the currect working directory of the parent
       process
     * 

Exercises
`````````

From
:doc:`/trainings/material/soup/linux/basics/shell/exercises/ls/index`

* :doc:`/trainings/material/soup/linux/basics/shell/exercises/ls/etc-passwd-size`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/ls/dev-types`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/ls/home-permissions`

File System Permissions
.......................

From :doc:`/trainings/material/soup/linux/basics/permissions/index`

* :doc:`/trainings/material/soup/linux/basics/permissions/basics`
* :doc:`/trainings/material/soup/linux/basics/permissions/exercises/index`

  * :doc:`/trainings/material/soup/linux/basics/permissions/exercises/credentials`
  * :doc:`/trainings/material/soup/linux/basics/permissions/exercises/shared-file`
  * :doc:`/trainings/material/soup/linux/basics/permissions/exercises/private-directory`
  * :doc:`/trainings/material/soup/linux/basics/permissions/exercises/private-directory-question`
  * :doc:`/trainings/material/soup/linux/basics/permissions/exercises/public-directory`
  * :doc:`/trainings/material/soup/linux/basics/permissions/exercises/public-directory-question`
  * :doc:`/trainings/material/soup/linux/basics/permissions/exercises/fh-questions-nocheat`

* :doc:`/trainings/material/soup/linux/basics/permissions/setuid`
* :doc:`/trainings/material/soup/linux/basics/permissions/setuid-livedemo`
* :doc:`/trainings/material/soup/linux/basics/permissions/umask`
* :doc:`/trainings/material/soup/linux/basics/permissions/sticky`

The Shell (Bash - “Bourne Again Shell”) (Continued)
...................................................

* :doc:`/trainings/material/soup/linux/basics/shell/configfiles`
* :doc:`/trainings/material/soup/linux/basics/shell/links`

Day 3
-----

Morning Wakeup
..............

* What does ``/`` contain? |longrightarrow| `File system hierarchy
  overview (systemd)
  <https://www.freedesktop.org/software/systemd/man/latest/file-hierarchy.html>`__
* Emacs/Bash keyboard shortcuts (Google knows). E.g.

  * :download:`/trainings/material/soup/linux/basics/shell/bash-help-sheet.pdf`
  * :download:`/trainings/material/soup/linux/basics/shell/readline-emacs-editing-mode-cheat-sheet.pdf`

* WSL walk-through |longrightarrow|
  :doc:`/trainings/material/soup/linux/basics/intro/wsl`
* Services? 

  * ``systemd``: `System and Service Manager <https://systemd.io/>`__
  * ... as opposed to `SysVinit
    <https://de.wikipedia.org/wiki/SysVinit>`__

Missing Pieces
..............

From :doc:`/trainings/material/soup/linux/basics/intro/index`

* :doc:`/trainings/material/soup/linux/basics/intro/environment`

From :doc:`/trainings/material/soup/linux/ssh/index`

* :doc:`/trainings/material/soup/linux/ssh/sshfs`

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

I/O Redirection And Pipes
.........................

From
:doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/index`

* :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/io-redirection`
* :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/pipes`
* :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/exercises`

Archiving and Compression
.........................

From
:doc:`/trainings/material/soup/linux/basics/archiving-compression/index`

* :doc:`/trainings/material/soup/linux/basics/archiving-compression/overview`
* :doc:`/trainings/material/soup/linux/basics/archiving-compression/gzip`
* :doc:`/trainings/material/soup/linux/basics/archiving-compression/tar`
* :doc:`/trainings/material/soup/linux/basics/archiving-compression/exercises`
