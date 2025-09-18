.. include:: <mmlalias.txt>


``O_WRONLY``: Writing A File (Which Must Exist)
===============================================

Writing (And Not Creating) A File
---------------------------------

Continuing from :doc:`example-O_RDONLY`, lets see how a file is
written. This is where the ``O_WRONLY`` (or ``O_RDWR`` if combined
reading *and* writing is desired) is passed to ``open()``.

.. sidebar:: Documentation

   * `man -s 2 open
     <https://man7.org/linux/man-pages/man2/open.2.html>`__
   * `man -s 2 write
     <https://man7.org/linux/man-pages/man2/write.2.html>`__
   * `man -s 3 perror
     <https://man7.org/linux/man-pages/man3/perror.3.html>`__

The following program 

* opens the file for writing

  * This time we pass the ``O_WRONLY`` flag since this is our
    intention

* writes a number of bytes to it

.. literalinclude:: code/example-O_WRONLY.c
   :caption: :download:`code/example-O_WRONLY.c`
   :language: c

Error: File Not Writeable
-------------------------

Lets start with an error: ``/etc/passwd`` is clearly not writeable for
others, and this is what we see:

.. code-block:: console

   $ ./example-O_WRONLY /etc/passwd
   open: Permission denied

Error: File Not Even There |longrightarrow| *Not Implicitly Created*
--------------------------------------------------------------------

.. code-block:: console

   $ ./example-O_WRONLY something-thats-not-there
   open: No such file or directory

This obviously means that, just because I declare my intention to
write to a file, that file is not automatically created.

*This is intended*: if such files were create, we would litter our
filesystems with garbage just because we misspelled filenames.

Sunny Case: File Exists, And Is Writeable
-----------------------------------------

Now that we know that a file must exist for ``O_WRONLY`` to work, we
create one, and then write to it:

.. code-block:: console

   $ touch /tmp/something-thats-not-there
   $ ./example-O_WRONLY /tmp/something-thats-not-there
   $ cat /tmp/something-thats-not-there 
   Howdy

That was easy.
