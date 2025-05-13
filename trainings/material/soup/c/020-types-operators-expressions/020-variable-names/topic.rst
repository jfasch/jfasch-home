.. include:: <mmlalias.txt>


Variable Names
==============

Variable- and Function Names
----------------------------

**By law:** ``[A-Za-z\_]+[A-Za-z0-9\_]*``

* Must start with letter or '_'
* Next may come digits
* Reserved names (z.B. ``while``) not allowed

Examples ...

.. code-block: c

   int _;
   char c;
   int c_89;
   float _avg_temp; /* careful! */
   int 1i; /* Error */

**Be defensive:** the standard states that names starting with
underscores are reserved for standard libraries
