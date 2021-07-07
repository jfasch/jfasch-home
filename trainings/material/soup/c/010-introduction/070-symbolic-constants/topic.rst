.. include:: <mmlalias.txt>

.. jf-topic:: c.introduction.cpp_symbolic_constants
   :dependencies: c.introduction.exercise_fahrenheit_for


Symbolic Constants
==================

C Preprocessor: Symbolic Constants
----------------------------------

**One does not write number literals in a program!**

* Inflexible
* Unreadable (a matter of taste though)
* Leads to duplicated code

*C Preprocessor* replaces symbols with arbitrary strings
|longrightarrow| *Macros*

.. code-block:: c

   #define LOWER 0
   #define UPPER 300
   #define STEP 20
   
   // and later down in the code, all occurences of the token are
   // replaces with their values
   
   int start = LOWER;

