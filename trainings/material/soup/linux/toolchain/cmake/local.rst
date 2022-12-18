.. ot-topic:: linux.toolchain.cmake_local
   :dependencies: linux.toolchain.cmake_stub_course,
		  linux.toolchain.static_library

.. include:: <mmlalias.txt>


CMake: Local Build
==================

.. sidebar:: 

   **Source Code**

   The example code in this section is maintained on `Github
   <https://github.com/jfasch/jfasch-home-linux-toolchain>`__

.. contents::
   :local:

``make``: Problems
------------------

* Writing a ``Makefile`` is tedious
* "Assembly language of build systems"
* Way too much boilerplate
* |longrightarrow| Targets ``all``, ``clean``, ``install``
* Error prone
* **Unmaintainable!!**

**Missing features ...**

* Out-of-source build
* Toolchain-independent build descriptions
* Packaging
* Dependency management

CMake To The Rescue
-------------------

.. sidebar:: Rant

   Well, CMake language does not deserve that name. It is more of a
   brute force macro expander.

* CMake: higher level build system
* Generates ``Makefile`` (and files for other low level build tools,
  like `Ninja <https://ninja-build.org/>`__)
* ``CMakeLists.txt`` instead of ``Makefile``
* Written in a dedicated "language"

**Listing of the project directory**

.. program-output:: ls -l
   :caption: ``../jfasch-home-linux-toolchain/cmake/``
   :cwd: ../jfasch-home-linux-toolchain/cmake

.. literalinclude:: ../jfasch-home-linux-toolchain/cmake/CMakeLists.txt
   :caption: :download:`../jfasch-home-linux-toolchain/cmake/CMakeLists.txt`
   :language: cmake

Out-Of-Source Build
-------------------

* Build artifacts (object files, libraries, executables) *pollute
  source directory*
* Hiccups with version control systems |longrightarrow|
  e.g. ``.gitignore``
* |longrightarrow| CMake can build into a separate directory, the
  *build directory*

For the remainder, lets define these directories ...

.. list-table::
   :align: left
   :widths: auto

   * * Source directory
     * ``/home/jfasch/source``
   * * Build directory
     * ``/home/jfasch/build``

Step 1: Generate ``Makefile`` In Build Directory
------------------------------------------------

.. code-block:: console
   
   $ cd /home/jfasch/build              # <--- CWD is the *build* directory
   $ cmake /home/jfasch/source          # <--- parameter is the *source* directory
   -- The C compiler identification is GNU 11.2.1
   -- The CXX compiler identification is GNU 11.2.1
   -- Detecting C compiler ABI info
   -- Detecting C compiler ABI info - done
   -- Check for working C compiler: /usr/bin/cc - skipped
   -- Detecting C compile features
   -- Detecting C compile features - done
   -- Detecting CXX compiler ABI info
   -- Detecting CXX compiler ABI info - done
   -- Check for working CXX compiler: /usr/bin/c++ - skipped
   -- Detecting CXX compile features
   -- Detecting CXX compile features - done
   -- Configuring done
   -- Generating done
   -- Build files have been written to: /home/jfasch/build

.. note::

   Please be careful to pass the source **directory** to ``cmake``,
   not the ``CMakeLists.txt`` file in that directory! (CMake builds in
   the source if you pass the *file*)

This creates a ``Makefile`` in the *build directory*

* Used as usual |longrightarrow| ``make``
* The file is generated |longrightarrow| basically unreadable

Step 2: Build Using ``make``
----------------------------

.. code-block:: console

   $ pwd                               # <--- CWD is the *build* directory when you call make
   /home/jfasch/build
   $ make
   [ 14%] Building C object CMakeFiles/greet.dir/hello.c.o
   [ 28%] Building C object CMakeFiles/greet.dir/hello-flexible.c.o
   [ 42%] Linking C static library libgreet.a
   [ 42%] Built target greet
   [ 57%] Building C object CMakeFiles/hello-second.dir/hello-second.c.o
   [ 71%] Linking C executable hello-second
   [ 71%] Built target hello-second
   [ 85%] Building C object CMakeFiles/hello-first.dir/hello-first.c.o
   [100%] Linking C executable hello-first
   [100%] Built target hello-first

Et voila:

.. code-block:: console

   $ ls -l 
   total 96
   -rw-rw-r--. 1 jfasch jfasch 13921 Apr 22 10:58 CMakeCache.txt
   drwxrwxr-x. 7 jfasch jfasch   280 Apr 22 11:02 CMakeFiles
   -rw-rw-r--. 1 jfasch jfasch  1688 Apr 22 10:58 cmake_install.cmake
   -rwxrwxr-x. 1 jfasch jfasch 26192 Apr 22 11:02 hello-first
   -rwxrwxr-x. 1 jfasch jfasch 27920 Apr 22 11:02 hello-second
   -rw-rw-r--. 1 jfasch jfasch  8102 Apr 22 11:02 libgreet.a
   -rw-rw-r--. 1 jfasch jfasch  8503 Apr 22 10:58 Makefile

Goodie: Dependency Management
-----------------------------

* Executables *depend on* libraries

  .. code-block:: cmake

     ADD_LIBRARY(greet hello.h hello.c hello-flexible.c)
     
     ADD_EXECUTABLE(hello-first hello-first.c)
     TARGET_LINK_LIBRARIES(hello-first greet)
     
     ADD_EXECUTABLE(hello-second hello-second.c)
     TARGET_LINK_LIBRARIES(hello-second greet)

* These relationships are not always so simple
* *Directed acyclic graph*
* |longrightarrow| want to be visualized
* |longrightarrow| `Graphviz <https://graphviz.org/>`__ package

  .. code-block:: console
     :caption: Debian/Ubuntu

     # apt install graphviz

  .. code-block:: console
     :caption: Fedora

     # dnf install graphviz

* During ``Makefile`` generation, pass the ``--graphviz`` option
  |longrightarrow| ``.dot`` file

  .. code-block:: console
  
     $ pwd
     /home/jfasch/build
     $ cmake --graphviz=dependencies.dot /home/jfasch/source
     ... roedel ...

* Massage the ``.dot`` file, e.g. turning it into a ``.png`` (or a
  ``.pdf``, ...)

  .. code-block:: console

     $ dot -Tpng dependencies.dot > dependencies.png

  .. graphviz:: dependencies.dot
