.. ot-topic:: linux.sysprog.fileio.example_O_CREAT
   :dependencies: linux.sysprog.fileio.basics,
		  linux.sysprog.fileio.example_O_WRONLY,
		  linux.basics.permissions.basics

.. include:: <mmlalias.txt>


``O_CREAT``: Creating A File
============================

.. contents::
   :local:

Creating A File If It Does Not Exist (Bogus Version)
----------------------------------------------------

We saw in :doc:`example-O_WRONLY` that a file is not implicitly
created only because we open one, which is a good thing. Lets see how
to use the ``O_CREAT`` to make this happen.

.. sidebar:: Documentation

   * `man -s 2 open
     <https://man7.org/linux/man-pages/man2/open.2.html>`__

The following program 

* opens the file for writing [#read-just-as-well]_, declaring that is
  must be created if it does not exist

  * We pass the ``O_WRONLY`` flag since this is our intention
  * We also pass the ``O_CREAT`` flag in a bitwise-or combination

.. literalinclude:: example-O_CREAT-bogus.c
   :caption: :download:`example-O_CREAT-bogus.c`
   :language: c

.. code-block:: console
   :caption: Build it

   $ gcc -o example-O_CREAT-bogus example-O_CREAT-bogus.c

Bogus ``O_CREAT`` Usage: Mode Parameter Missing
-----------------------------------------------

Lets see if a file that does not exist is created, and how that looks
like:

.. code-block:: console

   $ ./example-O_CREAT-bogus /tmp/file-that-does-not-exist
   $ ls -l /tmp/file-that-does-not-exist 
   --wxr-S---. 1 jfasch jfasch 0 May 13 18:09 /tmp/file-that-does-not-exist

**What?** Permissions ``-wxr-S---``? This looks like if there's
 something wrong.

This is a consequence of reading manual pages too sloppily ::

       O_CREAT

              ...

              The mode argument specifies the file mode  bits  to  be  applied
              when a new file is created.  If neither O_CREAT nor O_TMPFILE is
              specified in flags, then mode is ignored (and can thus be speci‐
              fied  as  0, or simply omitted).  The mode argument must be sup‐
              plied if O_CREAT or O_TMPFILE is specified in flags;  if  it  is
              not  supplied,  some  arbitrary bytes from the stack will be ap‐
              plied as the file mode.

	      ...




.. rubric:: Footnotes
.. [#read-just-as-well] One could legally combine ``O_CREAT`` with
                        ``O_RDONLY`` just as well if that made sense.
