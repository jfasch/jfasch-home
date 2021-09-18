.. include:: <mmlalias.txt>

.. ot-topic:: c.types_operators_expressions.declarations
   :dependencies: c.types_operators_expressions.constants


Variable Definitions
====================

Definitions und Initialization
------------------------------

**Variables must be known before they can be used**

.. code-block:: c
   :caption: Explicit initialization

   int lower, upper, step;
   char c;
   
   lower = 0;
   upper = 300;
   step = 20;

.. code-block:: c
   :caption: Implicit initialization


   int lower = 0, upper = 300, step = 20;
   char c;

Initialization of *Automatic* Variables
---------------------------------------

**Automatic variables**

* Defined inside a function (at the beginning of a *block*)
* Initialized *at runtime* - everytime the code runs
* |longrightarrow| arbitrary expressions possible

.. code-block:: c

   void some_function(void)
   {
       /* draw random number out of 0..9 */
       int some_variable = random() % 10;
       ...
   }

Initialization of *Global* Variables
------------------------------------

**Global variables**
  
* Defined in *global scope*
* Initialized *before program start*
* |longrightarrow| only constant expressions possible (calculated at
  compilation time, by the compiler)

.. code-block:: c

   const double pi = 3.1415926535897932;
   double some_nonsensical_number = pi / 2;
   const char msg[] = "hallo";
   char msg[] = "hallo";

