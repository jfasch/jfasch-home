Screenplay: Unittest: GTest Fixtures
====================================

.. sidebar:: Contents

   .. contents::
      :local:

   **Code**: :doc:`unittest-gtest-fixture-code/index`

Predefined Environment for a Number of Tests
--------------------------------------------

.. literalinclude:: unittest-gtest-fixture-code/predef-environ.cc
   :caption: :download:`unittest-gtest-fixture-code/predef-environ.cc`
   :language: c++

**Discussion**

* A fixture is a class (in ``gtest``). Technically,

  * "environment": protected members
  * ``TEST_F()``: C macro; derives from fixture class

* ``initial_state`` is not a very complex test environment, but you
  get the point

  * database
  * running co-process
  * a server that's being talked to
  * ...

* Otherwise (untechnically), it's just a function that operates on an
  environment

Environment is *Isolated* Per Test
----------------------------------

.. literalinclude:: unittest-gtest-fixture-code/isolated-environment.cc
   :caption: :download:`unittest-gtest-fixture-code/isolated-environment.cc`
   :language: c++

**Discussion**

* See how environment modification is not seen by the other test

More Complex Environment: ``SetUp()``, ``TearDown()``
-----------------------------------------------------

.. literalinclude:: unittest-gtest-fixture-code/setup-teardown.cc
   :caption: :download:`unittest-gtest-fixture-code/setup-teardown.cc`
   :language: c++

**Discussion**

* *Fixture* is `historically defined
  <https://www.amazon.de/Test-Driven-Development-Example-Signature/dp/0321146530>`__
  as being *set up* and *torn down*
* Naive alternative: use constructor and destructor

  * Destructor *must not throw*!
  * ``TearDown()`` exception is a normal failure
