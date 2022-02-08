.. ot-exercise:: cxx03.exercises_misc.american_flag

.. include:: <mmlalias.txt>


Exercise: Paint the American Flag Onto Standard Output
======================================================

.. contents::
   :local:

Description
-----------

Write a program to print the American flag, like so:

.. code-block:: console

   $ ./american-flag
   * * * * * * ==================================                         
    * * * * *  ==================================                         
   * * * * * * ==================================                         
    * * * * *  ==================================                         
   * * * * * * ==================================                         
    * * * * *  ==================================                         
   * * * * * * ==================================                         
    * * * * *  ==================================                         
   * * * * * * ==================================                         
   ==============================================                         
   ==============================================                         
   ==============================================                         
   ==============================================                         
   ==============================================                         
   ==============================================

The program does not simply output those lines as-is, like

.. code-block:: c++
   :caption: NO!

   std::cout << "* * * * * * ==================================" << std::endl;

Rather, it defines a function to compose the output:

.. code-block:: c++

   void print_chars(char c, const std::string& sep, unsigned int n);

To print the line above, for example, the program would use that
function like so:

.. code-block:: c++

   print_chars('*', " ", 6);
   cout << ' ';
   print_chars('=', "", 34);

Dependencies
------------

.. ot-graph::
   :entries: cxx03.exercises_misc.american_flag
