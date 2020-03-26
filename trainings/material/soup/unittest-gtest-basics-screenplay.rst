Screenplay: Unittest: GTest Basics
==================================

.. sidebar:: Contents

   .. contents::
      :local:
      :depth: 1

   **Code**: :doc:`unittest-gtest-basics-code/index`

Before We Start
---------------

Installation
............

**Fedora**:

.. code-block:: console

   # dnf install gtest-devel
   # dnf install gmock-devel

**Debian/Ubuntu**

.. code-block:: console

   # apt-get install libgtest-dev
   # apt-get install libgmock-dev

Documentation
.............

* `Googletest <https://github.com/google/googletest>`__

  * `Primer
    <https://github.com/google/googletest/blob/master/googletest/docs/primer.md>`__
  * `Advanced
    <https://github.com/google/googletest/blob/master/googletest/docs/advanced.md>`__
  * `gMock for Dummies
    <https://github.com/google/googletest/blob/master/googlemock/docs/for_dummies.md>`__
  * `Cookbook
    <https://github.com/google/googletest/blob/master/googlemock/docs/cook_book.md>`__

.. _gtest-basics-simple:

Simplest Test: No Test
----------------------

.. literalinclude:: unittest-gtest-basics-code/simple.cc
   :caption: :download:`unittest-gtest-basics-code/simple.cc`
   :language: c++

Compile and run:

.. code-block:: console

   $ g++ simple.cc -o simple -lgtest
   $ ./simple 
   [==========] Running 0 tests from 0 test cases.
   [==========] 0 tests from 0 test cases ran. (0 ms total)
   [  PASSED  ] 0 tests.

Next Simplest: Single File
--------------------------

Aha, so ``RUN_ALL_TESTS()`` runs all tests. There only have to be
tests there, so add two *suites*.

**Discussion**:

* Test structure, suites

.. literalinclude:: unittest-gtest-basics-code/self-contained.cc
   :caption: :download:`unittest-gtest-basics-code/self-contained.cc`
   :language: c++

Compile and run:

.. code-block:: console

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

Executing Tests Selectively
---------------------------

Most important: RTFM

.. code-block:: console

   $ ./self-contained --help
   ...
     --gtest_filter=POSTIVE_PATTERNS[-NEGATIVE_PATTERNS]
         Run only the tests whose name matches one of the positive patterns but
         none of the negative patterns. '?' matches any single character; '*'
         matches any substring; ':' separates two patterns.
   ...

Running the program executes all tests that are there, which might be
many.

.. code-block:: console

   $ ./self-contained --gtest_list_tests
   OneSuite.
     Test1
     Test2
   AnotherSuite.
     Test1
     Test2

Want to run only ``OneSuite.Test2``,

.. code-block:: console

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

.. code-block:: console

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

``FAIL()``
..........

``FAIL()`` is definitely *fatal*, in that the test stops immediately
in it.

.. literalinclude:: unittest-gtest-basics-code/fail.cc
   :caption: :download:`unittest-gtest-basics-code/fail.cc`
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

**Discussion**

* We do not see the output after ``FAIL()``

``ASSERT_*()``
..............

.. literalinclude:: unittest-gtest-basics-code/assert.cc
   :caption: :download:`unittest-gtest-basics-code/assert.cc`
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
   
**Discussion**. 

* ``assert.cc`` has two assertions to mean the same thing
* We see only one failure reported
* The second isn't executed because the first fails
* This is the essence in the term *fatal*: *stop immediately*

Non-Fatal Failure
-----------------

Instead of using ``ASSERT_*()`` like above, use ``EXPECT_*()`` .

.. literalinclude:: unittest-gtest-basics-code/expect.cc
   :caption: :download:`unittest-gtest-basics-code/expect.cc`
   :language: c++

Compile and run:

.. code-block:: shell

   $ g++ expect.cc -o expect -lgtest
   $ ./expect 
   [==========] Running 1 test from 1 test case.
   [----------] Global test environment set-up.
   [----------] 1 test from ExpectDemo
   [ RUN      ] ExpectDemo.ExpectIsNonFatal
   expect.cc:5: Failure
   Value of: 'X' == 'U'
     Actual: false
   Expected: true
   expect.cc:6: Failure
   Expected equality of these values:
     'X'
       Which is: 'X' (88, 0x58)
     'U'
       Which is: 'U' (85, 0x55)
   [  FAILED  ] ExpectDemo.ExpectIsNonFatal (0 ms)
   [----------] 1 test from ExpectDemo (1 ms total)
   
   [----------] Global test environment tear-down
   [==========] 1 test from 1 test case ran. (1 ms total)
   [  PASSED  ] 0 tests.
   [  FAILED  ] 1 test, listed below:
   [  FAILED  ] ExpectDemo.ExpectIsNonFatal
   
    1 FAILED TEST

**Discussion**

* We see two failures reported
* Both ``EXPECT_()`` are evaluated
* Test continues to run
* Reported as *failed* nonetheless

Custom Message Output
---------------------

All test macros support ``<<`` ``ostream`` operators.

.. literalinclude:: unittest-gtest-basics-code/fail-with-message.cc
   :caption: :download:`unittest-gtest-basics-code/fail-with-message.cc`
   :language: c++

Last Not Least: Structure
-------------------------

**Discussion**

* Hm. This way programs become rather large.
* Running every single one is cumbersome and error prone.

  * "Lost Tests Syndrome"

* Could use preprocessor to include tests :-) but no

**Plan**

* Externalize tests into separate ``.cc`` files.
* Link them together into a single *Test Runner*

Test Cases and Suites
.....................

* Copy what we have down into a ``tests/`` subdirectory (for example,
  to have a structure)
* Small standalone fragments, waiting to be aggregated.
* Do nothing on their own

.. literalinclude:: unittest-gtest-basics-code/tests/self-contained.cc
   :caption: :download:`unittest-gtest-basics-code/tests/self-contained.cc`
   :language: c++

.. literalinclude:: unittest-gtest-basics-code/tests/fail.cc
   :caption: :download:`unittest-gtest-basics-code/tests/fail.cc`
   :language: c++

.. literalinclude:: unittest-gtest-basics-code/tests/assert.cc
   :caption: :download:`unittest-gtest-basics-code/tests/assert.cc`
   :language: c++

.. literalinclude:: unittest-gtest-basics-code/tests/expect.cc
   :caption: :download:`unittest-gtest-basics-code/tests/expect.cc`
   :language: c++


Runner
......

* Aggregate them into a test-runner executable

.. literalinclude:: unittest-gtest-basics-code/run-tests.cc
   :caption: :download:`unittest-gtest-basics-code/run-tests.cc`
   :language: c++

* The main executable does not reference the tests in any way
* It just runs what's there
* This is the same as :ref:`gtest-basics-simple`

.. code-block:: shell
		
   $ g++ run-tests.cc -o run-tests -lgtest
   $ ./run-tests 
   [==========] Running 0 tests from 0 test cases.
   [==========] 0 tests from 0 test cases ran. (0 ms total)
   [  PASSED  ] 0 tests.

**Discussion**

* Magic behind the scenes: remember how ``RUN_ALL_TESTS()`` picked up
  test cases that were there?
* Global list of test cases where test cases enter themselves; *how
  does that work*?
* (Anyway ...)
* **Question**: *So how does this list build up?*
* **Answer**: *link the tests!*

.. code-block:: shell
		
   $ g++ run-tests.cc tests/*.cc -o run-tests -lgtest
   $ ./run-tests 
   [==========] Running 7 tests from 5 test cases.
   ... rödel ...
   [==========] 7 tests from 5 test cases ran. (0 ms total)
   [  PASSED  ] 4 tests.
   [  FAILED  ] 3 tests, listed below:
   [  FAILED  ] AssertDemo.AssertIsFatal
   [  FAILED  ] ExpectDemo.ExpectIsNonFatal
   [  FAILED  ] FailDemo.FailIsFatal
   
    3 FAILED TESTS
