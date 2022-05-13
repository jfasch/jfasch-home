.. ot-topic:: linux.basics.io_redir_pipes.pipes
   :dependencies: linux.basics.shell.commandline,
		  linux.basics.io_redir_pipes.io_redir

.. include:: <mmlalias.txt>


Pipes
=====

.. contents::
   :local:

Why Pipes?
----------

**UNIX (and software in general) paradigm** ::

  One tool must do one thing, and it should do that well!

Pipe combines tools; for example ...

* ``find``: recursively walks a directory tree, selects entries
  according to certain criteria, and prints to *standard output* what
  it finds
* ``grep`` is a filter that matches lines (on *standard input* if so
  used) and prints those on *standard output*
* ``less`` is a paging program, letting the user view a stream of data
  that it reads (if so used) from *standard input*

**Example**

Find all header files in the Linux kernel source tree (i.e. files that
end with ``.h``):

.. code-block:: console

   $ find /usr/src/linux/|grep '*.h'|less

.. image:: pipe.dia
   :scale: 50%

Pipe Facts
----------

.. sidebar:: Documentation

   * `man -s 7 pipe (overview) <https://man7.org/linux/man-pages/man7/pipe.7.html>`__
   * `man -s 2 pipe (system call) <https://man7.org/linux/man-pages/man2/pipe.2.html>`__

* *No* temporary files used to hand data from one command to the next
  in the pipeline
* Pipe member work *in parallel*
* Data exchanged *in memory* |longrightarrow| buffer of fixed size
  (~8K, depending on system configuration)
* Writer suspended when buffer is full
* Reader suspended when buffer is empty

Pipe Examples
-------------

.. sidebar:: Documentation

   * `man -s 1 cut <https://man7.org/linux/man-pages/man1/cut.1.html>`__
   * `man -s 1 sort <https://man7.org/linux/man-pages/man1/sort.1.html>`__


All users, sorted alphabetically:

.. code-block:: console

   $ cat /etc/passwd|cut -d : -f 1|sort

Same, but more efficient (using *standard input redirection* from
``/etc/passwd``, while also *not* competing for the `Useless Use Of
Cat Award <https://porkmail.org/era/unix/award>`__):

.. code-block:: console

   $ cut -d : -f 1 < /etc/passwd|sort

Again the same, this time letting ``cut`` open ``/etc/passwd`` (this
is the preferred way I'd say):

.. code-block:: console

   $ cut -d : -f 1 /etc/passwd|sort

Similar, but piping into the shell's ``while`` loop which is also
possible, amazingly:

.. code-block:: console

   $ cut -d : -f 1 < /etc/passwd| \
       sort | \
       while read user; do id $user; done

More Pipe Examples
------------------

Using the ``tee`` program (as plumbers occasionally do) to sniff data
passing by in a pipe. This saves the sorted list of usernames in
``/tmp/users.txt``.

.. code-block:: console

   $ cut -d : -f 1 < /etc/passwd| \
       sort | \
       tee /tmp/users.txt | \
       while read user; do id $user; done

Named Pipes
-----------

.. sidebar:: Documentation

   * `man -s 1 mkfifo <https://man7.org/linux/man-pages/man1/mkfifo.1.html>`__
   * `man -s 7 fifo (overview) <https://man7.org/linux/man-pages/man7/fifo.7.html>`__

* Rendezvous point in the file system
* Writer and reader meet there to exchange data
* Similar to (unnamed) pipe as above, only named

In one terminal ...

.. code-block:: console

   $ mkfifo /tmp/fifo
   $ echo Howdy > /tmp/fifo    # sits and waits until reader is there

In another terminal ...

.. code-block:: console

   $ cat /tmp/fifo
   Howdy
