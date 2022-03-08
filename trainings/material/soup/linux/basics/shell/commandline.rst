.. ot-topic:: linux.basics.shell.commandline
   :dependencies: linux.basics.intro.overview

.. include:: <mmlalias.txt>


Commandline
===========

.. contents:: 
   :local:

Shape (1)
---------
  
Consists of three parts ... well mostly, this is just convention.

* Command: executable program, or script, shell alias (see below),
  or shell builtin (like ``cd``)
* Options: e.g. ``-i`` (*short option*), oder ``--interactive`` (*long
  option*)
* Arguments: file names, mostly

Shape (2)
---------
  
.. code-block:: console
   :caption: Example: ``cp`` - "Copy"

   $ cp -i -r /etc ~/tmp
   $ cp -ir /etc ~/tmp

* Command: ``cp``
* Options: ``-i`` and ``-r``
* Arguments: ``/etc`` and ``/tmp``

Options
-------
  
* Alternative: *long options*; e.g. ``cp``

  * ``--interactive`` instead of ``-i``
  * ``--recursive`` instead of ``-r``
  * |longrightarrow| shell scripts
  * |longrightarrow| readability

* "Standard" options

  * ``-h`` or ``--help``: brief overview
  * ``-v`` or ``--verbose``: log/debug outout as the command runs
  * ``--version``: command version

* There is no standard, only evolution

  .. code-block:: console
     :caption: ``dd``, used to copy 20K (20*1024) of NULL bytes into
               trash bin

     $ dd if=/dev/zero of=/dev/null count=20 bs=1024

  .. code-block:: console
     :caption: ``ls -h`` is not helpful either, but *human readable*

     $ ls -h
     Documents  Downloads  Pictures

Help and Manual
---------------
  
* Command explains itself when given the option ``--help`` (well,
  mostly)

  .. code-block:: console
  
     $ find --help
     Usage: find [-H] [-L] [-P] [-Olevel] [-D debugopts] [path...] [expression]
     
     default path is the current directory; default expression is -print
     expression may consist of: operators, options, tests, and actions:
     operators (decreasing precedence; -and is implicit where no others are given):
           ( EXPR )   ! EXPR   -not EXPR   EXPR1 -a EXPR2   EXPR1 -and EXPR2
           EXPR1 -o EXPR2   EXPR1 -or EXPR2   EXPR1 , EXPR2
     positional options (always true): -daystart -follow -regextype
     ...


* Complete Description is in the *manual page* (or *man page*, for
  short)

  .. code-block:: console

     FIND(1)                                                                                                  General Commands Manual                                                                                                 FIND(1)
     
     NAME
            find - search for files in a directory hierarchy
     
     SYNOPSIS
            find [-H] [-L] [-P] [-D debugopts] [-Olevel] [starting-point...] [expression]
     
     DESCRIPTION
            This  manual  page  documents the GNU version of find.  GNU find searches the directory tree rooted at each given starting-point by evaluating the given expression from left to right, according to the rules of precedence (see
            section OPERATORS), until the outcome is known (the left hand side is false for and operations, true for or), at which point find moves on to the next file name.  If no starting-point is specified, `.' is assumed.
     
            If you are using find in an environment where security is important (for example if you are using it to search directories that are writable by other users), you should read the `Security Considerations' chapter of the findu‐
            tils documentation, which is called Finding Files and comes with findutils.  That document also includes a lot more detail and discussion than this manual page, so you may find it a more useful source of information.
     
     OPTIONS
            The  -H,  -L  and -P options control the treatment of symbolic links.  Command-line arguments following these are taken to be names of files or directories to be examined, up to the first argument that begins with `-', or the
            argument `(' or `!'.  That argument and any following arguments are taken to be the expression describing what is to be searched for.  If no paths are given, the current directory is used.  If no expression is given, the  ex‐
            pression -print is used (but you should probably consider using -print0 instead, anyway).
     ... 20 kilometers more ...

Man Pages: Navigation
---------------------

.. sidebar:: Documentation

   * `man -s 1 man <https://man7.org/linux/man-pages/man1/man.1.html>`__
   * `man -s 7 man (man page format itself)
     <https://man7.org/linux/man-pages/man7/man.7.html>`__
     |:exploding_head:|

* When used interactively, the ``man`` command uses the ``less``
  command to *page* its output.

  .. list-table::
     :align: left
     :header-rows: 1
     :widths: auto

     * * Keystroke
       * Description
     * * :kbd:`q`
       * Quit ``man``
     * * :kbd:`h`
       * Integrated help (same keystrokes apply there) - :kbd:`q` for
         "quit help"
     * * :kbd:`g`
       * Go to beginning of page
     * * :kbd:`G`
       * Go to bottom of page
     * * :kbd:`/`
       * Prompts for pattern, search forward
     * * :kbd:`?`
       * Prompts for pattern, search backwards
     * * :kbd:`n`
       * Repeat last search, go to next occurence
     * * :kbd:`N`
       * Repeat last search, go to previous occurence

Commandline Editing: Moving, Deleting
-------------------------------------

.. sidebar:: Documentation

   * `Useful Linux Command Line Bash Shortcuts You Should Know <https://www.tecmint.com/linux-command-line-bash-shortcut-keys/>`__
   * `Bash Shortcuts for the Command Line (emacs) <https://www.smartfile.com/blog/bash-shortcuts-for-the-command-line-emacs/>`__
   * :download:`bash-help-sheet.pdf`
   * :download:`readline-emacs-editing-mode-cheat-sheet.pdf`
   * `Repetitive strain injury (RSI, Mouse Disease)
     <https://en.wikipedia.org/wiki/Repetitive_strain_injury>`__

* Noob: **run away screaming!!**
* Expert: *come on, don't panic!*

.. list-table::
   :align: left
   :header-rows: 1
   :widths: auto

   * * Keystroke
     * Description
   * * |LeftArrow|
     * One character left
   * * |RightArrow|
     * One character right
   * * ``<BACKSPACE>``
     * Delete character left of cursor
   * * ``<DELETE>``, :kbd:`C-d`
     * Delete character below cursor
   * * ``<HOME>`` (``<POS1>``), :kbd:`C-a`
     * Move cursor to beginning of line
   * * ``<END>``, :kbd:`C-e`
     * Move cursor to end of line
   * * :kbd:`C-k`
     * Delete character below cursor, until end of line 
   * * :kbd:`C-u`
     * Delete character left of cursor, until beginning of line 
   * * :kbd:`C-l` ("ell")
     * Clear screen

Commandline Editing: Entire Words
---------------------------------

.. list-table::
   :align: left
   :header-rows: 1
   :widths: auto

   * * Keystroke
     * Description
   * * :kbd:`C-<left>`, `M-b`
     * Move cursor one word left
   * * :kbd:`C-<right>`, `M-f`
     * Move cursor one word right
   * * :kbd:`M-d`
     * Delete word right
   * * :kbd:`M-<backspace>`
     * Delete word left

.. note::

   * Arrow keys don't always work (embedded systems are often
     misconfigured in this regard) |longrightarrow| best to get used
     to *real* keys
   * Should the ``M`` (*Meta*, ``Alt``) not work, one can use ``ESC``,
     followed by the combined character. 

     For example ``Alt+d`` (pressed at the same time) is the same as
     ``ESC``, *followed by* ``d``

Commandline Editing: Entire Lines
---------------------------------

.. note:: 

   Keys for freaks, nerds, and `Emacs
   <https://www.gnu.org/software/emacs/>`__ addicts.

.. list-table::
   :align: left
   :header-rows: 1
   :widths: auto

   * * Keystroke
     * Description
   * * :kbd:`C-y`, :kbd:`M-y`
     * Insert from *kill ring* (`here
       <https://unix.stackexchange.com/questions/284871/what-does-rotate-the-kill-ring-mean>`__)
   * * :kbd:`C-_`
     * Undo
   * * :kbd:`C-t`
     * Transpose characters
   * * :kbd:`M-t`
     * Transpose words
   * * :kbd:`M-u`
     * Uppercase word
   * * :kbd:`M-l`
     * Lowercase word
   * * :kbd:`M-c`
     * Capitalize word

The Tabulator Key: Command Completion
-------------------------------------

* Usage **absolutely recommended**
* Nobody remembers, for example, all commands the start with ``git``

  .. code-block:: console
     
     $ git       # <-- HIT <TAB> HERE AFTER 'git'
     git                 git-p4              git-resurrect       git-upload-archive  gitk
     git-cvsserver       git-receive-pack    git-shell           git-upload-pack     gitview

The Tabulator Key: Filename Completion
--------------------------------------

* Usage **absolutely recommended**
* Nobody wants to type long paths
* Single ``TAB`` completes until ambiguity
* Double ``TAB`` shows alternatives

.. code-block:: console

   $ less ~/Doc             # <-- HIT <TAB> HERE       -> COMPLETES
   $ less ~/Documents/      # <-- HIT <TAB> HERE TWICE -> ALTERNATIVES
   2021-12-26-Oesterreich-Pre-Travel-Clearance.pdf                          e7d76d19-dd3d-4d52-9394-2c16dc73f9d1_VStV_921302213705_2021___VStVF.pdf  python-3.10.0-docs-html/
   boardingpass_1d9xf3dvd1uzt00tsswu68duh.gif                               Einkommensteuerbescheid1.pdf                                             python-doc.zip
   boardingpass_b6uy9xqgeojspx1hxshogcbbq.gif                               Einkommensteuervorauszahlungsbescheid1.pdf                               RF-Immobilienbewertung-ETW-2022.pdf
   Booking.com Confirmation.pdf                                             Fedora 34 ECE 19.ova                                                     Umsatzsteuerbescheid1.pdf
   Buchhaltung.csv                                                          H0020211105124337.pdf                                                    VK9VST311192021_0022021.pdf
   $ less ~/Documents/Bu    # <-- HIT <TAB>            -> COMPLETES
   less ~/Documents/Buchhaltung.csv
   ... shows boring stuff ...

Links
-----

* `Bash Tutorial: How to Use the Command Line in Linux, Windows, and
  Mac Terminal <https://youtu.be/BFMyUgF6I8Y>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/BFMyUgF6I8Y" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>
