.. ot-exercise:: linux.toolchain.exercises.native_build
   :dependencies: linux.toolchain.static_library

.. include:: <mmlalias.txt>


Exercise: Build Software Package (Native)
=========================================

* Download the tar file (:download:`Software.tar.xz`)
* Unpack it with the following command:

  .. code-block:: console

     $ tar -J -x -f Software.tar.xz

* You'll see a directory, ``Software/``, a follows

  .. code-block:: console

     $ tree Software/
     Software/
     ├── greet.c
     ├── greet.h
     ├── greet-parameterized.c
     └── greet-simple.c

* Write a ``Makefile`` that builds the software in a way that

  * All ``*.c`` files are compiled into corresponding ``*.o`` files
    |longrightarrow| *no linking step!*
  * ``greet.o`` goes into a library, ``libgreet.a`` (it does not
    contain a ``main()`` function)
  * A program ``greet-parameterized`` is built by linking
    ``greet-parameterized.o`` (containing ``main()``) against
    ``libgreet.a``.
  * Likewise, ``greet-simple`` is build by linking ``greet-simple.o``
    against the Library.

* Test the outcome by running the two program.

.. ot-graph::
   :entries: linux.toolchain.exercises.native_build
