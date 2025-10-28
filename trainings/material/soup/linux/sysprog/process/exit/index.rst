.. ot-topic:: sysprog.process.exit

.. include:: <mmlalias.txt>


Exit Status
===========

.. topic:: See also

   * :doc:`/trainings/material/soup/linux/basics/intro/process`
   * :doc:`/trainings/repertoire/linux-prog/bash`

The Shell: A Program Like Any Other Program
-------------------------------------------

* The shell is a program just like any other program (``/bin/bash``)
* Main purpose: start other programs, and report on their exit status

.. code-block:: console

   $ grep jfasch /etc/passwd
   jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash

* Search program ``grep`` along ``$PATH`` (see :doc:`../environ/index`)
* Start it, passing it two arguments: ``jfasch``, ``/etc/passwd``
  (:doc:`../argv/index`))
* Wait for it to terminate
* Examine its exit status

.. code-block:: console

   $ echo $?            # <-- $? ... exit status of last foreground process (huh?)
   0

The Shell: A Programming Language
---------------------------------

.. topic:: See also

   * :doc:`/trainings/repertoire/linux-prog/bash`

.. code-block:: console

   $ if grep jfasch /etc/passwd; then echo YAY; else echo NOPE; fi
   jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash
   YAY

* Exit status used as conditional for ``if`` (and ``while``)
* Functions, recursion, and whatnot
* |longrightarrow| Full programming language
* ... albeit a little weird

Exit Status
-----------

* An integer in the range 0-255
* In the simplest case, a ``return`` from the program's main function
  is its exit status
* Otherwise (exiting deeper in a process's call chain), see `man -s 3
  exit <https://man7.org/linux/man-pages/man3/exit.3.html>`__

Exit Status: ``0`` is "OK"
--------------------------

.. literalinclude:: code/exit-ok.cpp
   :language: c++
   :caption: :download:`code/exit-ok.cpp`

* In the sunny case, an exit status of *zero* is returned.
* The truth value of *zero* is ``true``, paradoxically. This makes
  sense though: *there is only one* sunny case, but many opportunities
  to get into trouble.

.. code-block:: console

   $ ./exit-ok 
   $ echo $?
   0

* Or, programmatically ...

.. code-block:: console

   $ if ./exit-ok; then echo YAY; else echo NOPE; fi
   YAY

Exit Status: ``!= 0`` is "Not OK"
---------------------------------

.. literalinclude:: code/exit-nok.cpp
   :language: c++
   :caption: :download:`code/exit-nok.cpp`

* In any error case, an exit status of *non-zero* is returned.
* The truth value of *non-zero* is ``false``. Again, this makes sense
  because there are possibly many things why a program might fail.

.. code-block:: console

   $ ./exit-nok 
   $ echo $?
   42

* Or, programmatically ...

.. code-block:: console

   $ if ./exit-nok; then echo YAY; else echo NOPE; fi
   NOPE
