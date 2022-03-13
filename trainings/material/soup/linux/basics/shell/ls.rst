.. ot-topic:: linux.basics.shell.ls
   :dependencies: linux.basics.shell.cwd,
		  linux.basics.shell.paths,
		  linux.basics.intro.overview

.. include:: <mmlalias.txt>


Directory Listings: The ``ls`` Command
======================================

.. sidebar:: Documentation

   * `man -s 1 ls <https://man7.org/linux/man-pages/man1/ls.1.html>`__

.. contents:: 
   :local:

Basic Usage
-----------

* Displays directory content
* Without any options |longrightarrow| names only
* No metadata, no nothing

  * When terminal supports color output, different file types are
    colored differently |longrightarrow| minimal *file type* hintingx

* No further arguments |longrightarrow| current working directory
  (CWD)

  .. code-block:: console
  
     $ pwd
     /home/jfasch
     $ ls
     Documents  Downloads  Homebrain  Pictures  tmp  venv  work
   
* Displaying non CWD directory:

  .. code-block:: console

     $ ls Documents/
     Buchhaltung.csv  python-3.10.0-docs-html  python-doc.zip  Umsatzsteuerbescheid1.pdf

Many Options
------------

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Option
     * Description
   * * ``-l``
     * *Long* listing |longrightarrow| show :ref:`metadata <metadata>`
   * * ``-a``
     * Show :ref:`hidden <hidden>` files
   * * ``-d``
     * Show directory, not its content (``ls /etc`` would show
       ``/etc``'s content)
   * * ``-h``
     * File sizes (and possibly others) in human readable form (e.g.,
       ``1.0M`` instead of ``1048576``)
   * * ``-t``
     * Sort by timestamp
   * * ``-R``
     * Recurse into directories
   * * ...
     * `man -s 1 ls
       <https://man7.org/linux/man-pages/man1/ls.1.html>`__

.. _metadata:

Metadata
--------

* Showing names only is rarely sufficient
* |longrightarrow| file type, timestamp, owner, group owner,
  *permissions*, ...

.. code-block::

   $ ls -l /etc/passwd
   -rw-r--r-- 1 root root 2746 Mar  3 14:12 /etc/passwd

.. list-table::
   :align: left
   :widths: auto

   * * ``-``
     * :ref:`File type <filetype>` (``-``: *regular file*)
   * * ``rw-r--r--``
     * :doc:`Permissions <../permissions/group>`
   * * ``1``
     * Reference count (|longrightarrow| :doc:`links`)
   * * ``root``
     * :doc:`Owner <../permissions/basics>`
   * * ``root``
     * :doc:`Group owner <../permissions/basics>`
   * * ``2746``
     * File size
   * * ``Mar 3 14:12``
     * *Last modification* timestamp
   * * ``/etc/passwd``
     * Entry name
   
.. _hidden:

Hidden Files
------------

* *Per convention*: all names starting with a dot (".") are not shown
* |longrightarrow| "hidden" files
* ... unless ``-a`` is given

.. code-block:: console

   $ ls -a
   .   .bash_history  .bash_profile  .bashrc~  .config  .dia       Downloads  .emacs.d    .gnupg     .ipython  .lesshst  .mozilla  .pki             .ssh         .thunderbird  .var  .vscode  .zoom
   ..  .bash_logout   .bashrc        .cache    Desktop  Documents  .emacs     .gitconfig  Homebrain  .jupyter  .local    Pictures  .python_history  .subversion  tmp           venv  work

* Best combined with ``-al``

.. code-block:: console

   $ ls -al
   total 68
   drwx------. 1 jfasch jfasch   490 Mar  9 17:51 .
   drwxr-xr-x. 1 root   root      36 Mar  3 14:12 ..
   -rw-------. 1 jfasch jfasch 36817 Mar  9 17:31 .bash_history
   -rw-r--r--. 1 jfasch jfasch    18 Jan 26  2021 .bash_logout
   -rw-r--r--. 1 jfasch jfasch   141 Jan 26  2021 .bash_profile
   -rw-r--r--. 1 jfasch jfasch   610 Oct 28 12:43 .bashrc
   drwx------. 1 jfasch jfasch   910 Mar  7 16:20 .cache
   drwxr-xr-x. 1 jfasch jfasch   682 Mar  3 16:21 .config
   drwxr-xr-x. 1 jfasch jfasch     0 Mar  9 16:11 Desktop
   drwxr-xr-x. 1 jfasch jfasch   112 Feb 12 16:26 .dia
   drwxr-xr-x. 1 jfasch jfasch   154 Mar  9 17:22 Documents
   drwxr-xr-x. 1 jfasch jfasch  2332 Mar  9 12:31 Downloads
   lrwxrwxrwx. 1 jfasch jfasch    42 Sep 27 12:16 .emacs -> /home/jfasch/Homebrain/local-config/.emacs
   drwx------. 1 jfasch jfasch  5080 Mar  7 12:09 .emacs.d
   lrwxrwxrwx. 1 jfasch jfasch    46 Sep 27 19:21 .gitconfig -> /home/jfasch/Homebrain/local-config/.gitconfig
   lrwxrwxrwx. 1 jfasch jfasch    43 Sep 27 18:41 .gnupg -> /home/jfasch/Homebrain/local-config/.gnupg/
   drwxrwxr-x. 1 jfasch jfasch   536 Feb 25 18:32 Homebrain
   drwxr-xr-x. 1 jfasch jfasch    74 Nov 16 21:53 .ipython
   drwxrwxr-x. 1 jfasch jfasch    16 Nov 16 21:54 .jupyter
   -rw-------. 1 jfasch jfasch    20 Mar  8 14:00 .lesshst
   drwx------. 1 jfasch jfasch    32 Oct 18 13:10 .local
   drwx------. 1 jfasch jfasch   100 Mar 23  2019 .mozilla
   drwxr-xr-x. 1 jfasch jfasch    34 Mar  9 13:57 Pictures
   drwx------. 1 jfasch jfasch    10 Oct  8 09:31 .pki
   -rw-------. 1 jfasch jfasch     0 Mar  9 17:30 .python_history
   drwx------. 1 jfasch jfasch   174 Feb 18 13:09 .ssh
   drwxrwxr-x. 1 jfasch jfasch    54 Nov  5 10:50 .subversion
   drwx------. 1 jfasch jfasch   118 Sep 23  2019 .thunderbird
   drwxrwxr-x. 1 jfasch jfasch   698 Mar  9 17:31 tmp
   drwxr-xr-x. 1 jfasch jfasch     6 Sep 27 12:40 .var
   drwxrwxr-x. 1 jfasch jfasch   106 Feb 24 20:19 venv
   drwxr-xr-x. 1 jfasch jfasch    38 Oct  8 09:31 .vscode
   drwxr-xr-x. 1 jfasch jfasch   902 Feb 16 11:12 work
   drwx------. 1 jfasch jfasch    80 Mar  2 17:23 .zoom

.. _filetype:

File Types
----------

* Everything is a file |:sunglasses:|
* But there are different types of files |:rolling_eyes:|

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1
  
     * * ``ls -l``, first character
       * Type
     * * ``-``
       * Regular file
     * * ``d``
       * Directory
     * * ``c``
       * Character device
     * * ``b``
       * Block device
     * * ``l``
       * :doc:`Symbolic link <links>`
     * * ``p``
       * Named pipe
  
* Examples ...

  .. code-block:: console
  
     $ ls -l /etc/passwd
     -rw-r--r--. 1 root root 2746 Mar  3 14:12 /etc/passwd

  .. code-block:: console
  
     $ ls -ld Documents
     drwxr-xr-x. 1 jfasch jfasch 154 Mar  9 17:22 Documents
  
  .. code-block:: console
  
     $ ls -l /dev/{zero,null}
     crw-rw-rw-. 1 root root 1, 3 Mar  7 12:10 /dev/null
     crw-rw-rw-. 1 root root 1, 5 Mar  7 12:10 /dev/zero
  
  .. code-block:: console
  
     $ ls -al .emacs
     lrwxrwxrwx. 1 jfasch jfasch 42 Sep 27 12:16 .emacs -> /home/jfasch/Homebrain/local-config/.emacs

