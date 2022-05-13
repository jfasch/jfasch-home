.. ot-topic:: linux.basics.io_redir_pipes.io_redir_swap_stdout_stderr
   :dependencies: linux.basics.io_redir_pipes.io_redir

.. include:: <mmlalias.txt>


I/O Redirection: Swap ``stdout`` And ``stderr``
===============================================

.. contents::
   :local:

Basic Pipe Usage
----------------

.. sidebar:: See also

   * :doc:`pipes`

Programs which write to *standard output* are good members of a
pipeline:

.. code-block:: console
   :caption: Couting directory entries below ``/etc``

   $ find /etc | wc -l
   find: `/etc/cron.daily': Permission denied
   find: `/etc/sudoers.d': Permission denied
   find: `/etc/cron.weekly': Permission denied
   ... 18 - 3 = 15 errors on stderr omitted ...
   1558

Basic Pipe Usage: What The Shell Does
-------------------------------------

.. sidebar:: Documentation

   * `man -s 7 pipe (overview) <https://man7.org/linux/man-pages/man7/pipe.7.html>`__
   * `man -s 2 pipe (system call) <https://man7.org/linux/man-pages/man2/pipe.2.html>`__
   * `man -s 2 dup <https://man7.org/linux/man-pages/man2/dup.2.html>`__

* Allocates pipe
* Duplicates ``find`` 's ``stdout`` to go into the pipe's write-end
* Duplicates ``wc`` 's ``stdin`` to come from the pipe's read-end

.. image:: io-redir-swap-stderr-and-stdout-orig.dia
   :scale: 50%

And How Do I Count Lines On ``stderr``?
---------------------------------------

*Obviously*: *standard output* and *standard error* need to be
swapped!

.. code-block:: console

   $ find /etc 3>&1 1>&2 2>&3 | wc -l
   ... stderr omitted ...
   18

What?
-----

#. ``A>&B``: make file descriptor ``A`` refer to the object that is
   pointed to by file descriptor ``B``
#. Redirections are applied/evaluated left to right

.. list-table::
   :align: left
   :widths: auto

   * * .. code-block:: console

          3>&1

       Create file descriptor 3 to point to ``stdout`` (which goes
       into the pipe)

       .. image:: io-redir-swap-stderr-and-stdout-step1.dia
	  :scale: 50%

     * .. code-block:: console

          1>&2

       Redirect ``stdout`` to go where ``stderr`` currently points to
       (i.e. the terminal)

       .. image:: io-redir-swap-stderr-and-stdout-step2.dia
	  :scale: 50%

     * .. code-block:: console
       
          2>&3

       Redirect ``stderr`` to where file descriptor 3 currently points
       to (the pipe)

       .. image:: io-redir-swap-stderr-and-stdout-step3.dia
	  :scale: 50%

More Tricks
-----------

The original ``find`` output (the entries that it finds) still go on
the terminal. Silence that by discarding output on 1:

.. code-block:: console

   $ find /etc 3>&1 1>&2 2>&3 1>/dev/null | wc -l
   18

Being overly correct, we can close file descriptor 3 after all
redirections have been applied:

.. code-block:: console

   $ find /etc 3>&1 1>&2 2>&3 1>/dev/null 3>- | wc -l
   18
