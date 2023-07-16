.. ot-topic:: cmake.testing
   :dependencies: cmake.external_dependencies
.. include:: <mmlalias.txt>


Running Tests
=============

.. contents::
   :local:

Setup And Usage
---------------

.. sidebar::

   **Documentation**

   * `ENABLE_TESTING()
     <https://cmake.org/cmake/help/latest/command/enable_testing.html>`__

* Enable testing (ideally in toplavel ``CMakeLists.txt``)

  .. code-block:: console

     ENABLE_TESTING()

* This creates a ``test`` target

  .. code-block:: console

     $ cmake /home/jfasch/work/jfasch-home/trainings/material/soup/cmake/14-testing/
     $ make test
     Running tests...
     Test project /home/jfasch/tmp/cmake-demo
     No tests were found!!!

Add Simple Test
---------------

.. sidebar::

   **Documentation**

   * `ADD_TEST()
     <https://cmake.org/cmake/help/latest/command/add_test.html>`__

* ``ADD_TEST()`` adds a program to run when ``test`` target is run
* Exit status 0 |longrightarrow| Ok
* Exit status not 0 |longrightarrow| Failure

.. code-block:: console
   :caption: ``bin/CMakeLists.txt``

   ADD_TEST(
     NAME hello-first-runs 
     COMMAND hello-first)

.. code-block:: console

   $ make test
   Running tests...
   Test project /home/jfasch/tmp/cmake-demo
       Start 1: hello-first-runs
   1/1 Test #1: hello-first-runs .................   Passed    0.00 sec
   
   100% tests passed, 0 tests failed out of 1
   
   Total Test time (real) =   0.01 sec

Checking Test Output
--------------------

.. sidebar::

   **Documentation**

   * `Properties on Tests
     <https://cmake.org/cmake/help/latest/manual/cmake-properties.7.html#properties-on-tests>`__

.. code-block:: console

   ADD_TEST(
     NAME hello-first-has-version
     COMMAND hello-first)
   SET_TESTS_PROPERTIES(
     hello-first-has-version
     PROPERTIES PASS_REGULAR_EXPRESSION "Hello World")

.. code-block:: console

   $ make test
   Running tests...
   Test project /home/jfasch/tmp/cmake-demo
       Start 1: hello-first-runs
   1/2 Test #1: hello-first-runs .................   Passed    0.00 sec
       Start 2: hello-first-has-version
   2/2 Test #2: hello-first-has-version ..........   Passed    0.00 sec
   
   100% tests passed, 0 tests failed out of 2
   
   Total Test time (real) =   0.01 sec

Questionability
---------------

* Is this a testing framework?
* |longrightarrow| *Probably not*
* CTest (the CMake module that implements testing) integrates nicely
  with CDash and other products of KitWare
* |longrightarrow| A clumsy try of vendor lock-in, I'd say

*Better options ...*

* Get code right from beginning |:face_with_raised_eyebrow:|
* Use a unit testing framework; for example

  * :doc:`/trainings/material/soup/unittest/group`
  * `Boost.Test <https://www.boost.org/doc/libs/1_82_0/libs/test/doc/html/index.html>`__
  * ... many others ...
