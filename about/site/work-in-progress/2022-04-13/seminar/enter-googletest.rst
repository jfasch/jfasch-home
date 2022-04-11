.. include:: <mmlalias.txt>


Live Hacking: Switch To ``googletest``
======================================

.. contents::
   :local:

Git Submodule
-------------

In the toplevel directory,

.. code-block:: console

   $ git submodule add https://github.com/google/googletest.git

.. note::

   Cloners must then, at the toplevel,

   .. code-block:: console

      $ git submodule init
      $ git submodule update

Add ``googletest`` to toplevel ``CMakeLists.txt``

Establish Tests: Demo
---------------------

.. sidebar:: Snippets

   * ``cmake-tests``

* Pull ``cmake-tests`` into ``tests/CMakeLists.txt`` (and comment out
  most of what's there)
* Add single ``test-demo.cpp``

  * ``TEST()``

    * pass
    * ``FAIL()``
    * ``ASSERT_EQ() << "..."``

  * ``TEST_F()``

    .. code-block:: c++

       #include <gtest/gtest.h>
       class SimpleFixture : public ::testing::Test { ... };
       TEST_F(SimpleFixture, MyFirstSuite) { ... }

Straightforward ``main()`` Conversion
-------------------------------------

* Add ``test_find.cpp`` to new runner executable, and build

  * |longrightarrow| works (WTF?)
  * |longrightarrow| tallk a little about linking ``main()``

* Morph ``test-find.cpp``
* Morph ``test-funny-overflow-file.cpp``

  * Note: fixture!

* Morph ``test-csv.cpp``

  * Note: two tests!

Fix Shortcomings
----------------

.. sidebar:: Snippets

   * ``temp-file-fixture``

* Make two tests out of one in ``test-csv.cpp`` |longrightarrow|
  trivial
* Create a fixture class for this tempfile crap

  * Pull in ``temp-file-fixture`` into new file ``tests/tempfile.h``

* ``tests/test-funny-overflow-file.cpp``: add null suite class that
  void-derives from fixture
* ``tests/test-csv.cpp``: same
