.. include:: <mmlalias.txt>


I/O Redirection
===============

.. sidebar:: See also

   * :doc:`io-redirection-swap-stdout-stderr`

Standard I/O Streams
--------------------

* Three Standard I/O *file descriptors*
* By default bound to the *terminal* |longrightarrow| keyboard and
  screen

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Meaning
     * Name
     * Descriptor
     * C Macro
   * * Standard input
     * ``stdin``
     * 0
     * ``STDIN_FILENO``
   * * Standard output
     * ``stdout``
     * 1
     * ``STDOUT_FILENO``
   * * Standard error
     * ``stderr``
     * 2
     * ``STDERR_FILENO``

.. important:: A tradition which is religiously adhered to in Unix

   * **Debug and error output** goes to *standard error*
     |longrightarrow| can be redirected to logfile, for example (or
     discarded into ``/dev/null``)
   * **Data** goes to *standard output* |longrightarrow| can be fed
     into another programm via the *pipe*

I/O Redirection Operators
-------------------------

.. list-table::
   :align: left
   :widths: auto

   * * ``command < file``
     * ``command`` is fed ``file`` contents as *standard input*
       (i.e. as if typed on keyboard)
   * * ``command > file``
     * ``command`` writes *standard output* into ``file`` (*not* on
       screen)
   * * ``command 2> file``
     * ``command`` writes *standard error* into ``file`` (*not* on
       screen)

Variation: non-destructive redirection
  
* ``>`` *truncates* ``file`` prior to writing, if it exists
* ``>>`` *appends* to ``file`` (or creates if it does not exist)

Example: Standard Output Redirection
------------------------------------

.. sidebar:: Documentation
	     
   * `man -s 1 grep
     <https://man7.org/linux/man-pages/man1/grep.1.html>`__

Say we are using the ``grep`` program to search ``/etc/passwd`` for
lines containing the word ``jfasch``. It writes the lines (only one in
out case) that it finds to *standard output*:

.. code-block:: console

   $ grep jfasch /etc/passwd
   jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash

.. image:: grep-no-redir.dia
   :scale: 50%

Redirect its output into a file that we might keep for later use,

.. code-block:: console

   $ grep jfasch /etc/passwd > found.csv
   $ ls -l found.csv 
   -rw-rw-r--. 1 jfasch jfasch 62 May 12 13:28 found.csv
   $ cat found.csv 
   jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash

.. image:: grep-stdout-redir.dia
   :scale: 50%

Example: Standard Input Redirection
-----------------------------------

Although ``grep`` can open its input file by itself when given as a
second commandline parameter, it reads from *standard input* when not.

.. code-block:: console

   $ grep jfasch < /etc/passwd
   jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash

.. image:: grep-stdin-redir.dia
   :scale: 50%

Example: Standard Error Redirection
-----------------------------------

``grep`` emits error messages on *standard error* in some cases, on of
which is where it cannot find the input file given,

.. code-block:: console

   $ grep jfasch /etc/passwd-does-not-exist
   grep: /etc/passwd-does-not-exist: No such file or directory

If, for example, we want to keep error messages for later debugging (a
larger shell script, say), we can redirect *standard error* to a
file. Remember, *standard error* is on file descriptor 2.

.. code-block:: console

   $ grep jfasch /etc/passwd-does-not-exist 2>errors.lst
   $ ls -l errors.lst 
   -rw-rw-r--. 1 jfasch jfasch 60 May 12 14:21 errors.lst
   $ cat errors.lst 
   grep: /etc/passwd-does-not-exist: No such file or directory

.. image:: grep-stderr-redir.dia
   :scale: 50%

Another way of treating error is to ignore them. In this case, the
character special device ``/dev/null`` is usually used (it behaves
like a filefor the purpose of redirection):

.. code-block:: console

   $ grep jfasch /etc/passwd-does-not-exist 2>/dev/null

Example: Everything Redirection
-------------------------------

If we want (not to say that we have to though!), we can combine
redirections of all three standard streams in a way that ``grep``

* Reads from *standard input*
* Writes *standard output* to a file
* Write *standard error* to ``/dev/null``

.. code-block:: console

   $ grep jfasch < /etc/passwd > found.csv 2>/dev/null

.. image:: grep-all-redir.dia
   :scale: 50%

.. important::

   When multiple redirections are used, the operations are executed
   from left to right!

   This might not sound so important from what we've learned so far -
   but see, for example, :doc:`io-redirection-swap-stdout-stderr`.

.. .. % --------------------------------------------------------------------
.. .. \begin{frame}[fragile]
.. ..   \frametitle{Jonglieren (1)}
.. .. 
.. ..   Programme, die auf \texttt{stdout} schreiben, sind gute Mitglieder
.. ..   einer Pipe ...
.. .. 
.. ..   \begin{block}{Zählen der Einträge in \texttt{/etc}}
.. .. \begin{verbatim}
.. .. $ find /etc | wc -l
.. .. find: `/etc/cron.daily': Permission denied
.. .. find: `/etc/sudoers.d': Permission denied
.. .. find: `/etc/cron.weekly': Permission denied
.. .. ...
.. .. 1558
.. .. \end{verbatim}
.. ..   \end{block}
.. .. 
.. .. \end{frame}
.. .. 
.. .. % --------------------------------------------------------------------
.. .. \begin{frame}
.. ..   \frametitle{Jonglieren (2)}
.. .. 
.. ..   Aktionen der Shell:
.. ..   \begin{itemize}
.. ..   \item Alloziert Pipe ($\to$ \texttt{man 2 pipe})
.. ..   \item Dupliziert \texttt{stdout} von \texttt{find} auf den Input der
.. ..     Pipe
.. ..   \item Dupliziert \texttt{stdin} von \texttt{wc} auf den Output der
.. ..     Pipe ($\to$ \texttt{man 2 dup})
.. ..   \end{itemize}
.. .. 
.. ..   \begin{block}{}
.. ..     \includegraphics[width=5cm]{io-redir-swap-stderr-and-stdout-orig.png}
.. ..   \end{block}
.. .. 
.. .. \end{frame}
.. .. 
.. .. % --------------------------------------------------------------------
.. .. \begin{frame}[fragile]
.. ..   \frametitle{Jonglieren (3)}
.. .. 
.. ..   \textit{Problem:} wie zählt man Fehlermeldungen?
.. ..   \linebreak
.. ..   $\to$ Vertauschen von \texttt{stdout} und \texttt{stderr}
.. .. 
.. ..   \begin{block}{Zählen der Fehlermeldungen}
.. .. \begin{verbatim}
.. .. $ find /etc 3>&1 1>&2 2>&3 | wc -l
.. .. \end{verbatim}
.. ..   \end{block}
.. .. 
.. ..   Häh?!
.. ..   \begin{itemize}
.. ..   \item Evaluierung von links nach rechts (\texttt{3>\&1} vor
.. ..     \texttt{1>\&2} ...)
.. ..   \item \texttt{A>\&B} heisst: ``Mach, dass Filedeskriptor A auf das
.. ..     gleiche zeigt wie Filedeskriptor B!''
.. ..   \end{itemize}
.. .. 
.. .. \end{frame}
.. .. 
.. .. % --------------------------------------------------------------------
.. .. \begin{frame}
.. ..   \frametitle{Jonglieren (4)}
.. .. 
.. ..   \begin{columns}[c]
.. .. 
.. ..     \begin{column}{.3\textwidth}
.. ..       \begin{block}{}
.. ..         \texttt{3>\&1}
.. ..       \end{block}
.. ..       Wegspeichern von \texttt{stdout} nach 3
.. ..       \begin{block}{}
.. ..         \includegraphics[height=2.5cm]{io-redir-swap-stderr-and-stdout-step1.png}
.. ..       \end{block}
.. ..     \end{column}
.. .. 
.. ..     \begin{column}{.3\textwidth}
.. ..       \begin{block}{}
.. ..         \texttt{1>\&2}
.. ..       \end{block}
.. ..       \texttt{stderr} nach \texttt{stdout} zeigen lassen
.. ..       \begin{block}{}
.. ..         \includegraphics[height=2.5cm]{io-redir-swap-stderr-and-stdout-step2.png}
.. ..       \end{block}
.. ..     \end{column}
.. .. 
.. ..     \begin{column}{.3\textwidth}
.. ..       \begin{block}{}
.. ..         \texttt{2>\&3}
.. ..       \end{block}
.. ..       \texttt{stderr} mit Ex-\texttt{stdout} überschreiben
.. ..       \begin{block}{}
.. ..         \includegraphics[height=2.5cm]{io-redir-swap-stderr-and-stdout-step3.png}
.. ..       \end{block}
.. ..     \end{column}
.. .. 
.. ..   \end{columns}
.. .. 
.. ..   \begin{itemize}
.. ..   \item Optional: Schliessen von 3: \texttt{3>\&-}
.. ..   \end{itemize}
.. .. \end{frame}
.. .. 
.. .. 
