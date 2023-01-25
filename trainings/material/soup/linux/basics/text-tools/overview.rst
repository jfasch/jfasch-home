.. ot-topic:: linux.basics.text_tools.overview
   :dependencies: linux.basics.shell.commandline

.. include:: <mmlalias.txt>


Overview
========

.. contents::
   :local:

``stdin``, ``stdout``, And The Pipe
-----------------------------------

.. sidebar::

   **More information**

   * :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/group`

* Good Ol' Unix philosopy
  
  .. line-block::

     A program does just one thing, and it does that well!

* Combining programs via the *pipe*

  * Connect one program's *standard output* with another program's
    *standard input*
  * |longrightarrow| multiple tools connected toether in a pipeline

* Most text/line based
    
  * Configuration files
  * Logfile
  * Programm source
  * ...

``stdin``, ``stdout``: Examples
-------------------------------

* Counting lines from ``stdin``

  .. code-block:: console

     $ wc -l
     line 1
     line 2
     line 3
     ^D
     3

  ``^D``: *end of file* when ``stdin`` is *terminal/console*

* Counting lines from ``/etc/passwd``

  .. code-block:: console

     $ wc -l < /etc/passwd
     47

  ``wc`` reads ``/etc/passwd`` from ``stdin``, :doc:`arranged by the
  shell <../io-redirection-pipes/group>`

* Finally: redirecting ``stdout``

  .. code-block:: console

     $ wc -l > num-lines
     line 1
     line 2
     line 3
     ^D
     $ cat num-lines 
     3

Pipe: Examples
--------------

* How many group am I member of?

  .. code-block:: console

     $ cat /etc/group | grep jfasch | wc -l
     2

  Equivalent (though more efficient):

  .. code-block:: console

     $ grep jfasch < /etc/group | wc -l
     2

  Equivalent:

  .. code-block:: console

     $ grep jfasch /etc/group | wc -l
     2

* Number of ``#include`` directives in Linux kernel source

  .. code-block:: console

     $ find ~/work/linux -name '*.[hc]' -exec cat {} \; | grep '^#include' | wc -l
     325324

  Equivalent (though more efficient):

  .. code-block:: console

     $ find ~/work/linux -name '*.[hc]' | xargs cat | grep '^#include' | wc -l
     325324

Basics Text Tools
-----------------

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Command
     * Description
   * * ``cat``
     * Write file content to ``stdout``
   * * ``head``
     * Write first couple of line to ``stdout``
   * * ``tail``
     * Write last couple of line to ``stdout``
   * * ``cut``
     * Cut out fields from lines (according to configurable *field
       separator*)
   * * ``less``
     * *Page* file content to ``stdout``
   * * ``sort``
     * Sort lines and write to ``stdout`` 
   * * ``uniq``
     * Eliminate consecutive equal lines (ideally, in a pipe after
       ``sort``)
   * * ``grep``
     * Filter lines by *regular expression*
