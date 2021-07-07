.. include:: <mmlalias.txt>

.. jf-exercise:: c.introduction.exercise_histogram
   :dependencies: c.introduction.arrays


Character Histogram
===================

For every possible character on ``stdin``, count the number of
occurrences of that character. At program termination (end of file,
``EOF``), print a histogram as in the example below. 

* Printable characters are output as-is
* Nonprintable characters are output as their ASCII values.

.. note::

   The decision whether a character is printable is made using the
   ``isprint()`` library function. See `manual page
   <https://man7.org/linux/man-pages/man3/isalpha.3.html>`__.

.. code-block:: console

   0  ... |
   1  ... |
   .
   'a'... |xxxxxxxxxxxxxxxxxxxxxxxxx
   'b'... |xxxxxxxxxxxxxxxxxx
   .
   .
