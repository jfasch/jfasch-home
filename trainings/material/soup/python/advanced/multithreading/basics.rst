.. include:: <mmlalias.txt>


Multithreading (Python)
=======================

.. topic:: Documentation

   * :doc:`python:library/threading`

What's a Thread?
----------------

* Mechanism for parallel code execution
* |longrightarrow| more than one flow of control in the same address
  space
* Issues

  * Startup/shutdown
  * Sharing data: concurrent access, and protecting against
  * Communication between threads

Threads: The Pythonic Way
-------------------------

.. literalinclude:: code/thread-pythonic.py
   :caption: :download:`code/thread-pythonic.py`

.. code-block:: console

   $ python code/thread-pythonic.py
   background: value is 0
   foreground: value is 0
   background: value is 1
   foreground: value is -1
   background: value is 2
   foreground: value is -2
   background: value is 3
   foreground: value is -3
   background: value is 4
   ...

**Two threads exist, runnning in parallel**

* Main thread (not explicitly created)
* Background integer incrementer (explicitly created)

Threads: The OO Way - Inheritance
---------------------------------

* Inherit from ``threading.Thread``
* Inheritance is a mechanism for *late binding*, brought to the world
  by languages that have no other mechanism
* In Python there is *duck typing*
* This method of starting a thread is equivalent to the pythonic
  method, but should not be used (trainer's opinion only, though)

Anyway:

.. literalinclude:: code/thread-inheritance.py
   :caption: :download:`code/thread-inheritance.py`

* Uncool: inheritance is not strictly Pythonic (at least not for such
  kinds of relationship)
* Uncool: people might not even know what inheritance is

And Program Termination?
------------------------

**Problem**: threads continue running when main thread terminates
(*spoiler*: daemon threads don't)

.. literalinclude:: code/program-termination-fails.py
   :caption: :download:`code/program-termination-fails.py`

.. code-block:: console

   $ python code/thread-program-termination.py
   background: value is 0
   foreground: value is 0
   background: value is 1
   foreground: value is -1
   background: value is 2
   foreground: value is -2  # <--- last notice of main thread
   background: value is 3
   background: value is 4
   background: value is 5
   background: value is 6
   background: value is 7
   background: value is 8
   ...   # only background thread running

Daemon Threads
--------------

**Definition**

* A program exits when only daemon threads are left
* The main thread is not a daemon thread

.. attention::

   This definition is Python specific!

*Corollary*: if I only create daemon threads, then program exit is
 fine.

.. literalinclude:: code/program-termination-ok.py
   :caption: :download:`code/program-termination-ok.py`
