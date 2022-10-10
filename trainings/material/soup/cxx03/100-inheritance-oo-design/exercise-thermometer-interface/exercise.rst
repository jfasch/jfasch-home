.. ot-exercise:: cxx03.inheritance_oo.exercise_thermometer_iface
   :dependencies: cxx03.inheritance_oo.interface,
		  linux.toolchain.cmake_local

Exercise: Thermometer Interface
===============================

.. contents::
   :local:

Prerequisites
-------------

* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/interface`
* :doc:`/trainings/material/soup/linux/toolchain/cmake/local`

Goal
----

Create a single-directory CMake project, step by step. The initial
``CMakeLists.txt`` file contains the following boilerplate,

.. code-block:: CMake

   CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
   PROJECT(FH-ECE20)
   
   set(CMAKE_CXX_STANDARD 17)
   
   # compiler options. (we only check for gcc)
   if (${CMAKE_COMPILER_IS_GNUCC})
     set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g3 -Wall -Werror")
     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g3 -Wall -Werror")
   endif()

Unrelated Thermometers: Library
-------------------------------

The following *unrelated* thermometers will go in a library,
``thermometers``. Hint: use the CMake function ``ADD_LIBRARY()``.

* ``ThermometerConst``

  .. literalinclude:: code/thermometer-const.h
     :caption: :download:`code/thermometer-const.h`
     :language: c++

  .. literalinclude:: code/thermometer-const.cpp
     :caption: :download:`code/thermometer-const.cpp`
     :language: c++

* ``ThermometerRandom``

  .. literalinclude:: code/thermometer-random.h
     :caption: :download:`code/thermometer-random.h`
     :language: c++

  .. literalinclude:: code/thermometer-random.cpp
     :caption: :download:`code/thermometer-random.cpp`
     :language: c++

Executables
-----------

Add the following executables to the project. Hint: use
``ADD_EXECUTABLE()`` to build the main code itself, together with
``TARGET_LINK_LIBRARIES()`` to link the ``thermometers`` library to
each.

* ``ThermometerConst`` test program

  .. literalinclude:: code/thermometer-const-test.cpp
     :caption: :download:`code/thermometer-const-test.cpp`
     :language: c++

* ``ThermometerRandom`` test program

  .. literalinclude:: code/thermometer-random-test.cpp
     :caption: :download:`code/thermometer-random-test.cpp`
     :language: c++

Getting To The Point: Polymorphic Thermometer Usage
---------------------------------------------------

``ThermometerConst`` and ``ThermometerRandom`` are completely
unrelated - *they don't share a common base class*.

The following program uses an instance of each *in an array of a
hypothetical interface/base class* to measure two temperature
points. It calculates the average of both points, and outputs that.

Add the missing ``Thermometer`` interface (create a file
``thermometer.h`` to contain it), and make the program compile and
run.

.. literalinclude:: code/thermometer-avg.cpp
   :caption: :download:`code/thermometer-avg.cpp`
   :language: c++

Topics Covered
--------------

.. ot-graph::
   :entries: cxx03.inheritance_oo.exercise_thermometer_iface
