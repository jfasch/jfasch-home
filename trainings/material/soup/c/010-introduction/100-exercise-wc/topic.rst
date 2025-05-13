.. include:: <mmlalias.txt>


Exercise: ``wc`` For The Poor
=============================

Write a program that reads from standard input and counts
characters, words, and lines. It prints the results on standard
output. (Words are separated by one or more spaces, tabulators, or
linefeeds.)

.. code-block:: console

   $ ./wc-poor
   word1 word2 word3
   word4 word5
   ^D        <--- EOF (on Unixen; Windows needs ^Z)
   lines=2 words=5 chars=30

*Optional*: take into account error scenarios and corner cases. For
 example:

* What if input starts with a space?
* What if there are multiple separators between two words?
