Building A Sample Project Using Googletest
==========================================

.. contents::
   :local:

Parameters
----------

.. list-table::
   :align: left
   :widths: auto

   * * **Source directory**
     * ``/home/jfasch/tmp/2022-04-13-googletest``
   * * **Build directory**
     * ``/tmp/2022-04-13-googletest``

(Your mileage will vary, obviously)

Get The Sources
---------------

Clone, and massage ``googletest`` submodule, from `here
<https://github.com/jfasch/2022-04-13-googletest>`__

.. code-block:: console

   $ git clone https://github.com/jfasch/2022-04-13-googletest.git
   $ cd 2022-04-13-googletest/
   $ pwd
   /home/jfasch/tmp/2022-04-13-googletest
   $ git submodule init
   $ git submodule update

Create Build Directory And Generate Makefiles
---------------------------------------------

.. note::

   On Windows, create Studio project instead

.. code-block:: console

   $ mkdir /tmp/2022-04-13-googletest
   $ cd /tmp/2022-04-13-googletest
   $ cmake ~/tmp/2022-04-13-googletest/

Build
-----

Linux: call ``make`` in the build directory.

.. code-block:: console

   $ pwd
   /home/jfasch/tmp/2022-04-13-googletest
   $ make
   [  6%] Building CXX object src/my-valuable-stuff/CMakeFiles/my-valuable-stuff.dir/feature1.cpp.o
   [ 13%] Linking CXX static library libmy-valuable-stuff.a
   [ 13%] Built target my-valuable-stuff
   [ 20%] Building CXX object bin/CMakeFiles/super-feature.dir/super-feature.cpp.o
   [ 26%] Linking CXX executable super-feature
   [ 26%] Built target super-feature
   [ 33%] Building CXX object googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
   [ 40%] Linking CXX static library ../../lib/libgtest.a
   [ 40%] Built target gtest
   [ 46%] Building CXX object googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
   [ 53%] Linking CXX static library ../../lib/libgmock.a
   [ 53%] Built target gmock
   [ 60%] Building CXX object googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
   [ 66%] Linking CXX static library ../../lib/libgmock_main.a
   [ 66%] Built target gmock_main
   [ 73%] Building CXX object googletest/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
   [ 80%] Linking CXX static library ../../lib/libgtest_main.a
   [ 80%] Built target gtest_main
   [ 86%] Building CXX object tests/CMakeFiles/run-tests.dir/dummy-suite.cpp.o
   [ 93%] Building CXX object tests/CMakeFiles/run-tests.dir/valuable-stuff-suite.cpp.o
   [100%] Linking CXX executable run-tests
   [100%] Built target run-tests

Run Tests
---------

.. code-block:: console

   $ pwd
   /home/jfasch/tmp/2022-04-13-googletest
   $ ./tests/run-tests 
   Running main() from /home/jfasch/tmp/2022-04-13-googletest/googletest/googletest/src/gtest_main.cc
   [==========] Running 4 tests from 2 test suites.
   [----------] Global test environment set-up.
   [----------] 3 tests from DummySuite
   [ RUN      ] DummySuite.FailingTest
   /home/jfasch/tmp/2022-04-13-googletest/tests/dummy-suite.cpp:6: Failure
   Failed
   [  FAILED  ] DummySuite.FailingTest (0 ms)
   [ RUN      ] DummySuite.AnotherFailingTest
   /home/jfasch/tmp/2022-04-13-googletest/tests/dummy-suite.cpp:11: Failure
   Expected equality of these values:
     'X'
       Which is: 'X' (88, 0x58)
     'U'
       Which is: 'U' (85, 0x55)
   [  FAILED  ] DummySuite.AnotherFailingTest (0 ms)
   [ RUN      ] DummySuite.SucceedingTest
   [       OK ] DummySuite.SucceedingTest (0 ms)
   [----------] 3 tests from DummySuite (0 ms total)
   
   [----------] 1 test from MyValuableStuffSuite
   [ RUN      ] MyValuableStuffSuite.Feature1Test
   [       OK ] MyValuableStuffSuite.Feature1Test (0 ms)
   [----------] 1 test from MyValuableStuffSuite (0 ms total)
   
   [----------] Global test environment tear-down
   [==========] 4 tests from 2 test suites ran. (0 ms total)
   [  PASSED  ] 2 tests.
   [  FAILED  ] 2 tests, listed below:
   [  FAILED  ] DummySuite.FailingTest
   [  FAILED  ] DummySuite.AnotherFailingTest
   
    2 FAILED TESTS
