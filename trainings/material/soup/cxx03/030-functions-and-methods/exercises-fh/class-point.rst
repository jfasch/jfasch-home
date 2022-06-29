.. ot-exercise:: cxx03.functions_and_methods.exercise_class_point

.. include:: <mmlalias.txt>


Exercise (FH): ``class point``
==============================

.. contents::
   :local:

Skeleton Project
----------------

.. sidebar:: 

   **Github**

   * https://github.com/jfasch/FH-ECE20-shapes

The project contains an initial sparse test suite for - and an initial
(likewise sparse) implementation of - ``class point``. Take the
following steps to get it, and get yourself an overview.

Preparation
...........

.. code-block::

   $ mkdir ~/FH-work
   $ cd ~/FH-work/
   $ git clone https://github.com/jfasch/FH-ECE20-shapes.git
   $ cd FH-ECE20-shapes/
   $ git submodule init
   $ git submodule update

Initial Build
.............

.. code-block:: console

   $ mkdir ~/FH-work/FH-ECE20-shapes-x86_64
   $ cd  ~/FH-work/FH-ECE20-shapes-x86_64
   $ cmake ~/FH-work/FH-ECE20-shapes
   $ make

Initial Test Run
................

.. code-block:: console

   $ pwd
   /home/jfasch/FH-work/FH-ECE20-shapes-x86_64
   $ ./tests/run-tests 
   Running main() from /home/jfasch/FH-work/FH-ECE20-shapes/googletest/googletest/src/gtest_main.cc
   [==========] Running 3 tests from 2 test suites.
   [----------] Global test environment set-up.
   [----------] 2 tests from point_suite
   [ RUN      ] point_suite.starting_point
   [       OK ] point_suite.starting_point (0 ms)
   [ RUN      ] point_suite.implementation_in_cpp_file
   [       OK ] point_suite.implementation_in_cpp_file (0 ms)
   [----------] 2 tests from point_suite (0 ms total)
   
   [----------] 1 test from rectangle_suite
   [ RUN      ] rectangle_suite.starting_point
   [       OK ] rectangle_suite.starting_point (0 ms)
   [----------] 1 test from rectangle_suite (0 ms total)
   
   [----------] Global test environment tear-down
   [==========] 3 tests from 2 test suites ran. (0 ms total)
   [  PASSED  ] 3 tests.

Extending ``class point``: More Unit Tests
------------------------------------------

.. important::
   
   One by one, add the following tests to
   ``tests/point-suite.cpp``. Build, fix/hack, run, repeat, until
   everything is green.

Default Constructor
...................

.. literalinclude:: code/tests/point-default-ctor.cpp
   :caption: :download:`code/tests/point-default-ctor.cpp`
   :language: c++

Access Methods
..............

.. literalinclude:: code/tests/point-xy.cpp
   :caption: :download:`code/tests/point-xy.cpp`
   :language: c++

(In-)Equality
.............

.. literalinclude:: code/tests/point-operator-eq-ne.cpp
   :caption: :download:`code/tests/point-operator-eq-ne.cpp`
   :language: c++

``+=``
......

Implement that one in the ``point.cpp`` file, please.

.. literalinclude:: code/tests/point-operator-pluseq.cpp
   :caption: :download:`code/tests/point-operator-pluseq.cpp`
   :language: c++

``+``
.....

Implement that one in the ``point.cpp`` file, please.

.. literalinclude:: code/tests/point-operator-plus.cpp
   :caption: :download:`code/tests/point-operator-plus.cpp`
   :language: c++

Unary ``-``
...........

.. literalinclude:: code/tests/point-operator-unary-minus.cpp
   :caption: :download:`code/tests/point-operator-unary-minus.cpp`
   :language: c++

``<<`` (``std::ostream``)
.........................

Implement that one in the ``point.cpp`` file, please.

.. literalinclude:: code/tests/point-operator-ostream.cpp
   :caption: :download:`code/tests/point-operator-ostream.cpp`
   :language: c++

