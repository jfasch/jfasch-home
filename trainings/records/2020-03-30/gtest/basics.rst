Basic GTest Usage
=================

.. sidebar:: Contents

   .. contents::
      :local:

Siehe `Github <https://github.com/google/googletest>`__.

Installation
------------

**Fedora**:

.. code-block:: shell

   # dnf install gtest-devel

**Debian/Ubuntu**

.. code-block:: shell

   # apt-get install libgtest-dev

Simplest Test: No Test
----------------------

.. literalinclude:: simple.cc
   :caption: :download:`simple.cc`
   :language: c++

Compile and run:

.. code-block:: shell

   $ g++ simple.cc -o simple -lgtest
   $ ./simple 
   [==========] Running 0 tests from 0 test cases.
   [==========] 0 tests from 0 test cases ran. (0 ms total)
   [  PASSED  ] 0 tests.

Next Simplest: Test in Same File as ``main()``
----------------------------------------------

Aha, so ``RUN_ALL_TESTS()`` runs all tests. There only have to be
tests there, so add two *suites*.

**Discuss**: test structure, suites

.. literalinclude:: self-contained.cc
   :caption: :download:`self-contained.cc`
   :language: c++

Compile and run:

.. code-block:: shell

   $ g++ self-contained.cc -o self-contained -lgtest
   $ ./self-contained 
   [==========] Running 2 tests from 1 test case.
   [----------] Global test environment set-up.
   [----------] 2 tests from Suite
   [ RUN      ] Suite.Test1
   [       OK ] Suite.Test1 (0 ms)
   [ RUN      ] Suite.Test2
   [       OK ] Suite.Test2 (0 ms)
   [----------] 2 tests from Suite (0 ms total)
   
   [----------] Global test environment tear-down
   [==========] 2 tests from 1 test case ran. (1 ms total)
   [  PASSED  ] 2 tests.

Execute Tests Selectively
-------------------------

Most importantly: RTFM

.. code-block:: shell

   $ ./self-contained --help
   ...
     --gtest_filter=POSTIVE_PATTERNS[-NEGATIVE_PATTERNS]
         Run only the tests whose name matches one of the positive patterns but
         none of the negative patterns. '?' matches any single character; '*'
         matches any substring; ':' separates two patterns.
   ...

Running the program executes all tests that are there, which might be
many.

.. code-block:: shell

   $ ./self-contained --gtest_list_tests
   OneSuite.
     Test1
     Test2
   AnotherSuite.
     Test1
     Test2

Want to run only ``OneSuite.Test2``,

.. code-block:: shell

   $ ./self-contained --gtest_filter='OneSuite.Test1'
   Note: Google Test filter = OneSuite.Test1
   [==========] Running 1 test from 1 test case.
   [----------] Global test environment set-up.
   [----------] 1 test from OneSuite
   [ RUN      ] OneSuite.Test1
   [       OK ] OneSuite.Test1 (0 ms)
   [----------] 1 test from OneSuite (0 ms total)
   
   [----------] Global test environment tear-down
   [==========] 1 test from 1 test case ran. (0 ms total)
   [  PASSED  ] 1 test.

Filter is actually a *shell glob*,

.. code-block:: shell

   $ ./self-contained --gtest_filter='OneSuite*'
   Note: Google Test filter = OneSuite*
   [==========] Running 2 tests from 1 test case.
   [----------] Global test environment set-up.
   [----------] 2 tests from OneSuite
   [ RUN      ] OneSuite.Test1
   [       OK ] OneSuite.Test1 (0 ms)
   [ RUN      ] OneSuite.Test2
   [       OK ] OneSuite.Test2 (0 ms)
   [----------] 2 tests from OneSuite (0 ms total)
   
   [----------] Global test environment tear-down
   [==========] 2 tests from 1 test case ran. (0 ms total)
   [  PASSED  ] 2 tests.
   
.. code-block:: shell

   $ ./self-contained --gtest_filter='*.Test1'
   ...

Fatal Failure
-------------

.. literalinclude:: fail.cc
   :caption: :download:`fail.cc`
   :language: c++

Compile and run:

.. code-block:: shell

   $ g++ fail.cc -o fail -lgtest
   $ ./fail 
   [==========] Running 1 test from 1 test case.
   [----------] Global test environment set-up.
   [----------] 1 test from FailDemo
   [ RUN      ] FailDemo.FailIsFatal
   fail.cc:6: Failure
   Failed
   [  FAILED  ] FailDemo.FailIsFatal (1 ms)
   [----------] 1 test from FailDemo (1 ms total)
   
   [----------] Global test environment tear-down
   [==========] 1 test from 1 test case ran. (1 ms total)
   [  PASSED  ] 0 tests.
   [  FAILED  ] 1 test, listed below:
   [  FAILED  ] FailDemo.FailIsFatal
   
.. literalinclude:: assert.cc
   :caption: :download:`assert.cc`
   :language: c++

Compile and run:

.. code-block:: shell

   $ g++ assert.cc -o assert -lgtest
   $ ./assert 
   [==========] Running 1 test from 1 test case.
   [----------] Global test environment set-up.
   [----------] 1 test from AssertDemo
   [ RUN      ] AssertDemo.AssertIsFatal
   assert.cc:6: Failure
   Value of: 'X' == 'U'
     Actual: false
   Expected: true
   [  FAILED  ] AssertDemo.AssertIsFatal (1 ms)
   [----------] 1 test from AssertDemo (1 ms total)
   
   [----------] Global test environment tear-down
   [==========] 1 test from 1 test case ran. (1 ms total)
   [  PASSED  ] 0 tests.
   [  FAILED  ] 1 test, listed below:
   [  FAILED  ] AssertDemo.AssertIsFatal
   
    1 FAILED TEST
   
