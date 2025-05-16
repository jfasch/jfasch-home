.. include:: <mmlalias.txt>


Lambda: More Capturing
======================

.. contents::
   :local:

More Capture Syntax
-------------------

* Lambdas are constantly improved as C++ evolves
* Find below a number of examples

Capturing Explicitly, By Copy
-----------------------------

.. important::

   A matter of taste, merely: don't cature *all* variables, by just
   saying ``[]``, or ``[&]`` (see below)

   * |longrightarrow| sign of lazyness, *akin to using global variables*
   * |longrightarrow| be explicit

.. literalinclude:: code/c++11-lambda_capture_suite--explicit_by_copy.cpp
   :caption: :download:`code/c++11-lambda_capture_suite--explicit_by_copy.cpp`
   :language: c++

Capturing Explicitly, By Reference
----------------------------------

.. literalinclude:: code/c++11-lambda_capture_suite--explicit_by_reference.cpp
   :caption: :download:`code/c++11-lambda_capture_suite--explicit_by_reference.cpp`
   :language: c++

Mixed Explicit Capture
----------------------

Dubios, for reasons mentioned above
	      
.. literalinclude:: code/c++11-lambda_capture_suite--explicit_mixed.cpp
   :caption: :download:`code/c++11-lambda_capture_suite--explicit_mixed.cpp`
   :language: c++

Define Variables In Capture
---------------------------

.. literalinclude:: code/c++11-lambda_capture_suite--initialized_capture.cpp
   :caption: :download:`code/c++11-lambda_capture_suite--initialized_capture.cpp`
   :language: c++

Capturing All By Reference
--------------------------
	      
.. literalinclude:: code/c++11-lambda_capture_suite--all_by_reference.cpp
   :caption: :download:`code/c++11-lambda_capture_suite--all_by_reference.cpp`
   :language: c++
	      
Capturing All By Copy
---------------------

.. literalinclude:: code/c++11-lambda_capture_suite--all_by_copy.cpp
   :caption: :download:`code/c++11-lambda_capture_suite--all_by_copy.cpp`
   :language: c++

Capturing All By Copy, Except Some By Reference
-----------------------------------------------

.. literalinclude:: code/c++11-lambda_capture_suite--all_by_copy_except.cpp
   :caption: :download:`code/c++11-lambda_capture_suite--all_by_copy_except.cpp`
   :language: c++

Capturing ``this``
------------------

.. literalinclude:: code/c++11-lambda_capture_suite--this_capture.cpp
   :caption: :download:`code/c++11-lambda_capture_suite--this_capture.cpp`
   :language: c++
