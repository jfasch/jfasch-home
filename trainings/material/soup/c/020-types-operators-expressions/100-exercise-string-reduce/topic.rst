.. include:: <mmlalias.txt>

.. jf-exercise:: c.types_operators_expressions.exercise_string_reduce
   :dependencies: c.types_operators_expressions.increment_decrement_operators


Copy and Reduce String
======================

* Write a function (and the program with the ``main()`` function
  calling that function) similar to :doc:`what we just saw
  <../090-increment-and-decrement-operators/topic>`.

  Instead of just omitting the given character, it reduces consecutive
  occurences of that character to just one.

* *The function does not check for overflow:* fix that!

  Add overflow protection, by adding one parameter ``size`` which
  contains the maximum size of the destination string.
