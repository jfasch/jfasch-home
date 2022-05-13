.. ot-exercise:: linux.basics.io_redir_pipes.exercises
   :dependencies: linux.basics.io_redir_pipes.io_redir,
		  linux.basics.io_redir_pipes.io_redir_swap_stdout_stderr,
		  linux.basics.io_redir_pipes.pipes

.. include:: <mmlalias.txt>


Exercises: IO-Redirection, Pipes
================================

.. contents::
   :local:

* Use the ``cat`` program (without any commandline parameters) to
  copy ``/etc/passwd`` to ``/tmp/passwd``.
* Use the ``echo`` command (call it multiple times in a row) to create
  a file that contains your name and your address.
* Output a sorted list of all users in your system. *Hint:*
  ``/etc/passwd`` contains all users in the first column - fields are
  separated with the ``:`` character.
* Redirect *standard output* and *standard error* of the command
  ``find /etc`` to ``/tmp/output.txt``
* Why is the (non-empty) file ``/tmp/output`` suddenly empty after
  running the command ``cat < /tmp/output > /tmp/output``?
* Run the commands

  .. code-block:: console

     $ echo Howdy > /tmp/output
     $ cat < /tmp/output >> /tmp/output

  #. What do you notice? 
  #. Explain!

* How many subdirectories does your home directory contain? *Hint:*
  combine ``find`` und ``wc`` in a pipeline.
* Modify the command ``find /etc | wc``, applying redirections, so
  that it counts the number of lines on *standard error*, and
  *standard output* is sent to ``/dev/null``.
* Using ``echo``, ``cat``, and ``mkfifo``, send the word "Howdy" in
  circles such that ``cat`` consumes as much CPU time as it can get.
