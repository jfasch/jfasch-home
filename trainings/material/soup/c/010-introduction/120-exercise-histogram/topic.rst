.. include:: <mmlalias.txt>


Exercise: Character Histogram
=============================

For every possible character on ``stdin``, count the number of
occurrences of that character. At program termination (end of file,
``EOF``), print a histogram as in the example below. 

* Printable characters are output as-is
* Nonprintable characters are output as their ASCII values.

.. note::

   * The decision whether a character is printable is made using the
     ``isprint()`` library function. See `manual page
     <https://man7.org/linux/man-pages/man3/isalpha.3.html>`__.
   * You will need 256 counters (the ASCII alphabet has 256 characters
     defined), so you will it convenient to have an array of those,
     like

     .. code-block:: c

	int counters[256];

     Don't forget to initialize the counters in this array; see
     :doc:`/trainings/material/soup/c/010-introduction/110-arrays/topic`.

.. code-block:: console

   $ ./histogram < /tmp/test-data.txt
   0  ... |
   1  ... |
   .
   'a'... |xxxxxxxxxxxxxxxxxxxxxxxxx
   'b'... |xxxxxxxxxxxxxxxxxx
   .
   .
