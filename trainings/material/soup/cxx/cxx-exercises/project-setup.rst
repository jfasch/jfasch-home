.. include:: <mmlalias.txt>


Working On Exercise Projects
============================

.. contents::
   :local:

Most of the exercises consist of a small textual description which
tries to transport the big picture of what needs to be
implemented. Human language, though, is inefficient in specifying
exactly what's needed. Detailed specifications are given as unit
tests, using :doc:`Google's unit testing framework
</trainings/material/soup/unittest/index>`.

Typically, exercise packs are cloned from a Git repository, need to be
massaged a bit, compiled, and finally a *test suite* is run. Here's
how.

Clone Github Repository
-----------------------

A *repository URL* is given by your trainer; clone that project into a
directory of your choice.

If the repository URL is, say,
``https://github.com/jfasch/2022-10-11.git`` (we will use that name
during this setup document), then you use the following command to
clone the repository into s subdirectory ``2022-10-11`` of the current
working directory.

.. code-block:: console

   $ pwd
   /home/jfasch/src
   $ git clone https://github.com/jfasch/2022-10-11.git

We will use ``/home/jfasch/src/2022-10-11`` as *source directory* from
now on (your is likely different of course).

Massage ``googletest`` Sub-Module
---------------------------------

Inside the source directory,

.. code-block::

   $ cd 2022-10-11/
   $ pwd
   /home/jfasch/src/2022-10-11

Massage the source tree to clone the ``googletest`` submodule:

.. code-block::

   $ git submodule init
   $ git submodule update

Create Build Directory
----------------------

We *build* into a directory that is *different* from the source
directory. Lets create one; I'll use ``/home/jfasch/build/2022-10-11``
as build directory from now on (your situation will again be
different).

Create one, and change CWD into it:

.. code-block:: console

   $ mkdir -p /home/jfasch/build/2022-10-11
   $ cd /home/jfasch/build/2022-10-11

Build Directory: Create Makefiles With ``cmake``
------------------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/toolchain/cmake/local`

Inside the build directory, a call to ``cmake`` is used to create a
``Makefile`` structure *from the source directory*:

.. code-block:: console

   $ pwd             # <--- inside the build directory
   /home/jfasch/build/2022-10-11
   $ cmake /home/jfasch/src/2022-10-11
   ... roedel ...

.. attention::

   Be sure to specify the source directory, and not th epath to the
   ``CMakeLists.txt`` file inside it! If you do, CMake will behave
   obscurely and build into the source directory.

Usually this step needs to be done only once, right after project
setup. In rare cases (subtle modifications of ``CMakeLists.txt``
files, generally), one needs to re-generate Makefiles.

Build Directory: Build With ``make``
------------------------------------

Inside the build directory, use ``make`` to build the project:

.. code-block:: console

   $ pwd             # <--- inside the build directory
   /home/jfasch/build/2022-10-11
   $ make
   ... roedel ...

This step is usually done after project setup, and after each
modification of the source tree.

Build Directory: Run Tests
--------------------------

The build directory contains a ``tests/`` subdirectory where the test
executable is. It is usually called something like
``tests/test-suite``, or ``tests/run-tests``, or something similar.

.. code-block:: console

   $ pwd             # <--- inside the build directory
   /home/jfasch/build/2022-10-11
   $ tests/test-suite 
   [==========] Running 11 tests from 3 test suites.
   [----------] Global test environment set-up.
   [----------] 3 tests from bag_copy_suite
   [ RUN      ] bag_copy_suite.find_by_int_ok
   [       OK ] bag_copy_suite.find_by_int_ok (0 ms)
   [ RUN      ] bag_copy_suite.find_by_int_nok
   [       OK ] bag_copy_suite.find_by_int_nok (0 ms)
   [ RUN      ] bag_copy_suite.remove_by_int_ok
   [       OK ] bag_copy_suite.remove_by_int_ok (0 ms)
   [----------] 3 tests from bag_copy_suite (0 ms total)
   
   [----------] 3 tests from bag_unique_suite
   [ RUN      ] bag_unique_suite.find_by_int_ok
   [       OK ] bag_unique_suite.find_by_int_ok (0 ms)
   [ RUN      ] bag_unique_suite.find_by_int_nok
   [       OK ] bag_unique_suite.find_by_int_nok (0 ms)
   [ RUN      ] bag_unique_suite.remove_by_int_ok
   [       OK ] bag_unique_suite.remove_by_int_ok (0 ms)
   [----------] 3 tests from bag_unique_suite (0 ms total)
   
   [----------] 5 tests from bag_shared_suite
   [ RUN      ] bag_shared_suite.find_by_int_ok
   [       OK ] bag_shared_suite.find_by_int_ok (0 ms)
   [ RUN      ] bag_shared_suite.find_by_int_nok
   [       OK ] bag_shared_suite.find_by_int_nok (0 ms)
   [ RUN      ] bag_shared_suite.remove_by_int_ok
   [       OK ] bag_shared_suite.remove_by_int_ok (0 ms)
   [ RUN      ] bag_shared_suite.insert_const_ref
   [       OK ] bag_shared_suite.insert_const_ref (0 ms)
   [ RUN      ] bag_shared_suite.insert_move
   [       OK ] bag_shared_suite.insert_move (0 ms)
   [----------] 5 tests from bag_shared_suite (0 ms total)
   
   [----------] Global test environment tear-down
   [==========] 11 tests from 3 test suites ran. (0 ms total)
   [  PASSED  ] 11 tests.
