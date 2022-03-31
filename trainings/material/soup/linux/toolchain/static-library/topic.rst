.. ot-topic:: linux.toolchain.static_library
   :dependencies: linux.toolchain.separate_compilation

.. include:: <mmlalias.txt>


Object Code Archives/Static Libraries
=====================================

.. sidebar:: 

   **Source Code**

   The example code in this section is maintained on `Github
   <https://github.com/jfasch/jfasch-home-linux-toolchain>`__

.. contents::
   :local:

Code Bases Get Larger (1)
-------------------------

New feature in our code base |:clown:| ...

* more flexible greeting, in a separate file pair,
  ``hello-flexible.{h,c}``. Takes the name to be greeted from the
  commandline. (See
  :doc:`/trainings/material/soup/linux/toolchain/static-library/topic`
  for details on commandline argument processing.)
* used by ``hello-second.c``

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Users
     * Valuable and rock-stable code
   * * .. literalinclude:: ../jfasch-home-linux-toolchain/static-libraries/hello-first.c
          :caption: :download:`../jfasch-home-linux-toolchain/static-libraries/hello-first.c`
          :language: c

       .. literalinclude:: ../jfasch-home-linux-toolchain/static-libraries/hello-second.c
          :caption: :download:`../jfasch-home-linux-toolchain/static-libraries/hello-second.c`
          :language: c

     * 

       .. literalinclude:: ../jfasch-home-linux-toolchain/static-libraries/hello.h
          :caption: :download:`../jfasch-home-linux-toolchain/static-libraries/hello.h`
	  :language: c

       .. literalinclude:: ../jfasch-home-linux-toolchain/static-libraries/hello.c
	  :caption: :download:`../jfasch-home-linux-toolchain/static-libraries/hello.c`
          :language: c

       .. literalinclude:: ../jfasch-home-linux-toolchain/static-libraries/hello-flexible.h
          :caption: :download:`../jfasch-home-linux-toolchain/static-libraries/hello-flexible.h`
	  :language: c

       .. literalinclude:: ../jfasch-home-linux-toolchain/static-libraries/hello-flexible.c
	  :caption: :download:`../jfasch-home-linux-toolchain/static-libraries/hello-flexible.c`
          :language: c

Code Bases Get Larger
---------------------

Build instructions need to be updated

* Build ``hello-flexible.o`` from ``hello-flexible.c``

* Link ``hello-second`` against ``hello-flexible.o`` (and not
  ``hello.o``)

.. list-table::
   :align: left
   :header-rows: 1

   * * Smaller
     * Larger
   * *
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

     * 

       .. graphviz::
       
          digraph foo {
             "hello.o" -> "hello.c";
             "hello-flexible.o" -> "hello-flexible.c";
             "hello-first.o" -> "hello-first.c";
             "hello-second.o" -> "hello-second.c";
             "hello-first" -> "hello-first.o";
             "hello-first" -> "hello.o";
             "hello-second" -> "hello-second.o";
             "hello-second" -> "hello-flexible.o";
             "all" -> "hello-first";
             "all" -> "hello-second";
          }

.. literalinclude:: ../jfasch-home-linux-toolchain/static-libraries/Makefile-explicit
   :caption: :download:`../jfasch-home-linux-toolchain/static-libraries/Makefile-explicit`
   :language: c

Problem: Structure
------------------

* Two similar routines with similar purpose in different
  implementation files
* |longrightarrow| Frontend programs ``hello-first`` and
  ``hello-second`` must know which one they have to link against
* |longrightarrow| cannot easily rename a single file, or move
  implementations around, from one file into another

Solution: Libraries
-------------------

* Archives of object code
* Executables are linked against those instead
* |longrightarrow| single point of dependency

**Building a library** from two object files, ``hello.o`` and
``hello-flexible.o`` ...

.. code-block:: console

   $ ar cq libgreet.a hello.o hello-flexible.o

What's in it?

.. code-block:: console

   $ nm libgreet.a 
   
   hello.o:
   0000000000000000 T hello
                    U puts
   
   hello-flexible.o:
   0000000000000000 T hello_flexible
                    U printf
   
**Linking a executable against the library** ...

.. code-block:: console

   $ gcc -o hello-second hello-second.o libgreet.a 

Build Instructions: Building A Library
--------------------------------------

.. graphviz::

   digraph foo {
      "hello.o" -> "hello.c";
      "hello-flexible.o" -> "hello-flexible.c";
      "libgreet.a" -> "hello.o";
      "libgreet.a" -> "hello-flexible.o";
      "hello-first.o" -> "hello-first.c";
      "hello-second.o" -> "hello-second.c";
      "hello-first" -> "hello-first.o";
      "hello-first" -> "libgreet.a";
      "hello-second" -> "hello-second.o";
      "hello-second" -> "libgreet.a";
      "all" -> "hello-first";
      "all" -> "hello-second";
   }

.. literalinclude:: ../jfasch-home-linux-toolchain/static-libraries/Makefile
   :caption: :download:`../jfasch-home-linux-toolchain/static-libraries/Makefile`
   :language: c

