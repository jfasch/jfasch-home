.. ot-topic:: linux.toolchain.separate_compilation
   :dependencies: linux.toolchain.basics

.. include:: <mmlalias.txt>


Zooming In: Separate Compilation, and Linking *Statically*
==========================================================

.. sidebar:: 

   **Source Code**

   Clone the `Github repository
   <https://github.com/jfasch/jfasch-home-linux-toolchain>`__, and
   change into the ``separate-compilation/`` subdirectory to follow
   along.

.. contents::
   :local:

Remember: All-In-One Build ...
------------------------------

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * User
     * Valuable and rock-stable code
   * * .. literalinclude:: ../jfasch-home-linux-toolchain/separate-compilation/hello-first.c
          :caption: :download:`../jfasch-home-linux-toolchain/separate-compilation/hello-first.c`
          :language: c
     * .. literalinclude:: ../jfasch-home-linux-toolchain/separate-compilation/hello.h
          :caption: :download:`../jfasch-home-linux-toolchain/separate-compilation/hello.h`
	  :language: c

       .. literalinclude:: ../jfasch-home-linux-toolchain/separate-compilation/hello.c
          :caption: :download:`../jfasch-home-linux-toolchain/separate-compilation/hello.c`
          :language: c

Would be built like so,

.. code-block:: console
  
   $ gcc -o hello-first hello-first.c hello.c

Adding Another ``main()``: What About Shared Code?
--------------------------------------------------

* Lets say ``hello()`` is a popular thing
* |longrightarrow| more code will want to use it

**So here's another user ...**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Users
     * Valuable and rock-stable code
   * * .. literalinclude:: ../jfasch-home-linux-toolchain/separate-compilation/hello-first.c
          :caption: :download:`../jfasch-home-linux-toolchain/separate-compilation/hello-first.c`
          :language: c

       .. literalinclude:: ../jfasch-home-linux-toolchain/separate-compilation/hello-second.c
          :caption: :download:`../jfasch-home-linux-toolchain/separate-compilation/hello-second.c`
          :language: c

     * .. literalinclude:: ../jfasch-home-linux-toolchain/separate-compilation/hello.h
          :caption: :download:`../jfasch-home-linux-toolchain/separate-compilation/hello.h`
	  :language: c

       .. literalinclude:: ../jfasch-home-linux-toolchain/separate-compilation/hello.c
	  :caption: :download:`../jfasch-home-linux-toolchain/separate-compilation/hello.c`
          :language: c

**Building all this**

.. code-block:: console
  
   $ gcc -o hello-first hello-first.c hello.c
   $ gcc -o hello-second hello-second.c hello.c

**This is bad!**

* Code is reused, *but* ...
* Compiled twice
* |longrightarrow| Build time increases as more code uses ``hello()``
* |longrightarrow| This does not scale!

Solution: Separate Compilation And Linking Steps
------------------------------------------------

* **Goal**: only a single compilation step of ``hello.c``
* This cannot produce an executable, obviously
* Compilation only: turn ``hello.c`` into ``hello.o``

.. code-block:: console
   :caption: *Compiling only*: ``hello.c``

   $ gcc -c -o hello.o hello.c

* Same for both users of ``hello()``

  * ``hello-first.c`` |longrightarrow| ``hello-first.o``

    .. code-block:: console

       $ gcc -c -o hello-first.o hello-first.c 

  * ``hello-second.c`` |longrightarrow| ``hello-second.o``

    .. code-block:: console

       $ gcc -c -o hello-second.o hello-second.c 

* Linking existing object files into executables

  * ``hello-first`` needs ``hello-first.o`` and ``hello.o``

    .. code-block:: console

       $ gcc -o hello-first hello-first.o hello.o

  * ``hello-second`` needs ``hello-second.o`` and ``hello.o``

    .. code-block:: console

       $ gcc -o hello-second hello-second.o hello.o

  .. note::

     This is referred to as *static linking*. Each of the resulting
     executables ``hello-first`` and ``hello-second`` has its own copy
     of ``hello.o`` in it!

Complication: Modification Tracking
-----------------------------------

**Question:** what if I modify ``hello.c``?

*Answer*: re-do the following steps

#. Re-compile ``hello.o`` from it

   .. code-block:: console
   
      $ gcc -c -o hello.o hello.c

#. Re-link both using executable to update their *copy* of ``hello.o``

   .. code-block:: console

      $ gcc -o hello-first hello-first.o hello.o

   .. code-block:: console

      $ gcc -o hello-second hello-second.o hello.o

.. note::

   A similar dance has to be performed if you modify one of the using
   files ``hello-first.c`` or ``hello-second.c``.

The following *directed acyclic graph* reflects exactly those
relationships (an arrow ``A`` "|longrightarrow|" ``B`` says that "If
``B`` is newer than ``A``, then ``A`` has to be recreated from ``B``):

.. graphviz::

   digraph foo {
      "hello.o" -> "hello.c";
      "hello-first.o" -> "hello-first.c";
      "hello-second.o" -> "hello-second.c";
      "hello-first" -> "hello-first.o";
      "hello-first" -> "hello.o";
      "hello-second" -> "hello-second.o";
      "hello-second" -> "hello.o";
      "all" -> "hello-first";
      "all" -> "hello-second";
   }

.. note::

   The ``all`` node is artificial in that it does not correspond to a
   file, but rather means the "see if anything needs to be done" case.

Enter Makefiles
---------------

.. sidebar::

   **Documentation**

   * `GNU Make <https://www.gnu.org/software/make/>`__
   * `man -s 1 make
     <https://man7.org/linux/man-pages/man1/make.1.html>`__

**Problem**: how would I manually track all those dependencies in a
rapidly growing project?

**Answer**: automate it!

The following ``Makefile`` describes exactly the situation above,

.. literalinclude:: ../jfasch-home-linux-toolchain/separate-compilation/Makefile
   :caption: :download:`../jfasch-home-linux-toolchain/separate-compilation/Makefile`
   :language: Makefile

To run the commands in that file, standing in the directory where the
``Makefile`` is, simply say [#rm-files]_ ,

.. code-block:: console

   $ make
   gcc -c -o hello-first.o hello-first.c
   gcc -c -o hello.o hello.c
   gcc -o hello-first hello-first.o hello.o
   gcc -c -o hello-second.o hello-second.c 
   gcc -o hello-second hello-second.o hello.o

As a test, modify ``hello-second.c``, and see how only a subset of the
commands run,

.. code-block:: console

   $ make
   gcc -c -o hello-second.o hello-second.c 
   gcc -o hello-second hello-second.o hello.o
   
.. rubric:: Footnotes

.. [#rm-files] Prior to doing this, you may want to remove the
               binaries we created during this lesson.
