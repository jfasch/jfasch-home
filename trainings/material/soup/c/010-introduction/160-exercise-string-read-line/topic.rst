.. include:: <mmlalias.txt>

.. jf-exercise:: c.introduction.exercise_string_read_line
   :dependencies: c.introduction.character_arrays


Read Line Into String from ``stdin``
====================================

Write a (nonsensial) program that ...

* Reads standard input line by line. To do so, implement a function
  ``read_line(char line[], int maxlen)`` (which internally uses
  ``getchar()``)
* Outputs the longest line at end of input.
