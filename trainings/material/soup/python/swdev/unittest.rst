.. ot-topic:: python.swdev.unittest
   :dependencies: python.advanced.oo.inheritance,
		  python.advanced.modules

.. include:: <mmlalias.txt>


The ``unittest`` Module
=======================

.. contents::
   :local:

.. sidebar::

   **Documentation**

   * :doc:`python:library/unittest`

Simplest Example
----------------

.. code-block:: python

   import unittest
   class MyTestCase(unittest.TestCase):
       def runTest(self):
           self.assertEqual(1, 2)
   c = MyTestCase()
   unittest.TextTestRunner().run(c)

.. code-block:: console

   FAIL: runTest (__main__.MyTestCase)
   ---------------------------------------------------------
   Traceback (most recent call last):
     File "/tmp/x.py", line 6, in runTest
       self.assertEqual(1, 2)
   AssertionError: 1 != 2

Using a Fixture
---------------

**Problems ...**

* Cleanup after test failure
* Setup before test begin
* |longrightarrow| formalize (prepare and release) a controlled
  environment for the test body

.. code-block:: python

   class MyTestCase(unittest.TestCase):
       def setUp(self):
           self.__db = create_database()
           fill_test_data(self.__db)
       def tearDown(self):
           remove_database(self.__db)
       def runTest(self):
           ...
   c = MyTestCase()
   unittest.TextTestRunner().run(c)

Multiple Test Cases With Same Fixture
-------------------------------------

* A single ``runTest()`` method is not sufficient in most cases

  * A fixture's purpose is to serve multiple related test cases

* |longrightarrow| test case with multiple test methods
* |longrightarrow| *Test Suite*

.. code-block:: python

   class MyTestCase(unittest.TestCase):
       def setUp(self): ...
       def tearDown(self): ...
       def testFeature1(self): ...
       def testFeature2(self): ...
   suite = unittest.TestSuite()
   suite.addTest(MyTestCase('testFeature1')
   suite.addTest(MyTestCase('testFeature2')
   unittest.TextTestRunner().run(suite)

Auto Recognizing Test Methods
-----------------------------

**Problems:**

* Two steps: *write* test case and *add* test case
* |longrightarrow| /me writes test, but forgets to add to suite
* |longrightarrow| *Lost Test Syndrome*

.. code-block:: python

   class MyTestCase(unittest.TestCase):
       def setUp(self): ...
       def tearDown(self): ...
       def testFeature1(self): ...
       def testFeature2(self): ...
   suite = unittest.TestLoader().\
       loadTestsFromTestCase(MyTestCase)
   unittest.TextTestRunner().run(suite)

The Meat of a Test
------------------

**Enough structure**, now for the real test code ...

.. code-block:: python

   class MyTestCase(unittest.TestCase):
       def testSomething(self):
           self.failIf(1 == 2, "OMG!")

There's more:


* ``failUnless(2 == 2)``
* ``failUnlessEqual(2, 2)``
* ``failIfEqual(2, 3)``
* ``failUnlessAlmostEqual(2.12345, 2.123, 3)``
* ``failUnlessRaises(IOError, file('/'))``

Recommendations
---------------

**A few recommendations**, out of personal experience ...

* **If tests become a burden, then you've messed it up!**
* Tests should live *near* the code

  * ... but not *in* it

* Code must not use test code!
* Structure your tests (test suites) like your package structure
* *Test First Development* - adding tests afterwards is rarely fun
* There is no *Design for Testability* - sound design is always
  testable.
* It's easy to become an addict!
