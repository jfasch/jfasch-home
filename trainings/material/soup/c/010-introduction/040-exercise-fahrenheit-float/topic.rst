.. include:: <mmlalias.txt>

.. ot-exercise::  c.introduction.exercise_fahrenheit_float
   :dependencies: c.introduction.variables_and_arithmetic_expressions


Exercise: A Better Fahrenheit Table
===================================

Review the "Fahrenheit/Celsius Table" program in
:doc:`../030-variables-and-arithmetic-expressions/topic`.

**Following ugliness comes to mind:**

* The output is not justified. (Hint: the format string "``%6d``" (for
  example) creates a 6 character wide right-justified field.)
* Integer arithmetic is inappropriate. Temperature conversion are
  better done in floating point.
