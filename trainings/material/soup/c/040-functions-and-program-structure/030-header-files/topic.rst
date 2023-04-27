.. include:: <mmlalias.txt>

.. ot-topic:: c.functions_and_program_structure.header_files
   :dependencies: c.functions_and_program_structure.external_variables


Header Files
============

.. contents::
   :local:

Declarations: Problems (1)
--------------------------

**Declarations must exactly match corresponding definitions**

.. list-table::
   :align: left

   * * ``main.c``

       .. code-block:: c

          extern int g_lobal;
          void print_g(void);
          void main(void)
          {
              g_lobal = 100;
              print_g();
          }

     * ``g.c``

       .. code-block:: c

          double g_lobal;
          void print_g(const char[] format})
          {
              ...
          }

Declarations: Problems (2)
--------------------------

**Severe bugs**
  
* *Incorrect linkage*: perception of *user* does not match definition
* Hard to detect: no tool support --- only discipline and conventions
* At best: *segmentation fault* |longrightarrow| crash
* At worst: appears to work, but in fact doesn't

**Solution**

* Centralize declarations |longrightarrow| *header files*
* ``#include "g.h"``, rather than giving declarations by hand

Declarations: Solutions
-----------------------

.. list-table:: 
   :align: left

   * * ``g.h``

       .. code-block:: c

          #ifndef G_H
          #define G_H
          
          extern double g_lobal;
          void print_g(
              const char[] format);
          
          #endif

     * ``g.c``

       .. code-block:: c

          // have compiler check
          // declaration/definition
          // consistency
          #include <g.h>
                          
          double g_lobal;
          
          void print_g(
              const char[] format)
          {
              ...
          }

``main.c``

.. code-block:: c

   #include "g.h"
   ...
