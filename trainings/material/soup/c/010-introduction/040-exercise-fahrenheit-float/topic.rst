.. include:: <mmlalias.txt>

.. jf-exercise::  c.introduction.exercise_fahrenheit_float
   :dependencies: c.introduction.variables_and_arithmetic_expressions


A Better Fahrenheit Table
=========================

**Following ugliness comes to mind:**

* The output is not justified. (Hint: the format string "``%6d``" (for
  example) creates a 6 character wide right-justified field.)
* Integer arithmetic is inappropriate. Temperature conversion are
  better done in floating point.
