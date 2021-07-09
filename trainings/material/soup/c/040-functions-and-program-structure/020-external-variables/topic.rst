.. include:: <mmlalias.txt>

.. jf-topic:: c.functions_and_program_structure.external_variables
   :dependencies: c.functions_and_program_structure.basics


Extern/Global Variables
=======================

Variables: Declaration and Definition
-------------------------------------

**Functions**

* Functions are complex
* |longrightarrow| usually not written on one line
* **Readability** |longrightarrow| separate declaration and definition
* ... even when defined and called inside the same source file

**Variables**

* Usually written on one line |longrightarrow| declaration *and* definition
* |longrightarrow| no need for a *declaration*
* **But**: how does one *declare* a variable (make it known to the
  compiler without allocating memory), and *define* it in a different
  file?

Variables: Separating Declaration from Definition (1)
-----------------------------------------------------

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

          #include <stdio.h>
          
          int g_lobal;
          
          void print_g(void)
          {
              printf("%d\n", 
                     g_lobal);
          }

Variables: Separating Declaration from Definition (2)
-----------------------------------------------------

**Compiler and linker work together**

* ``extern`` variable declaration |longrightarrow| explicitly marked
  as *declaration*
* *Compiler* does *not* set aside memory
* There is no address yet |longrightarrow| *Compiler* cannot insert
  address where variable is used
* |longrightarrow| Inserts a *reference*, to be *resolved* by the
  linker

