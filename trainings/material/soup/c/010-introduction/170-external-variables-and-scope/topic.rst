.. include:: <mmlalias.txt>

.. jf-topic:: c.introduction.external_variables_and_scope
   :dependencies: c.introduction.exercise_string_read_line


Lifetime of Variables
=====================

Lifetime
--------

**Two classes of variables ...**

* Local ("automatic"). Lifetime (and visibility) is confined to the function call.

  * All variables that we had so far are *automatic* (function
    parameters are local variables)

* Global ("extern"). Lifetime is the entire program.

  Another point of view: *visibility* |longrightarrow| later

Global Variables
----------------

**Global variables are evil**

* They obscure program logic
* Side effects through unnecessary persistence
* Global *constants* are ok

**There are use cases though ...**

* Not a use case: **laziness**

Global Variables: How?
----------------------

* Functions (code) can only be defined in global scope
* Have access to *local variables* and *other global objects*

.. code-block:: c

   int i;
   
   void f(void)
   {
       printf("%d\n", i);
   }

