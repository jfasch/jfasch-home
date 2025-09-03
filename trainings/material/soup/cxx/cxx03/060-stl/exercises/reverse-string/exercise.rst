.. include:: <mmlalias.txt>


Exercise: Reverse a String
==========================

.. contents::
   :local:

Description
-----------

Write a program that 

* reads a string from *standard input* [#read_from_stdin]_
* reverses that string [#iterate_over_string]_
* outputs the reversed string to standard output [#concatenate_char_to_string]_

.. code-block:: console

   $ ./reverse-string
   abc               <--- user input, typed by you
   cba               <--- program output



.. rubric:: Footnotes

.. [#read_from_stdin] Use this code snippet to read a string from standard input:
		      
		      .. code-block:: c++

			 std::string s;
			 std::cin >> s;

.. [#iterate_over_string] Iterating over a string (here in
			  forward iteration) is done just like
			  you would iterate over an array.

			  .. code-block:: c++

			     std::string s("abc");
			     for (int i=0; i<s.size(); i++) {
			         char c = s[i];
				 ...
			     }

.. [#concatenate_char_to_string] Single characters are appended to a
                                 string like so:

				 .. code-block:: c++

				    std::string s("cb");
				    s += 'a';
