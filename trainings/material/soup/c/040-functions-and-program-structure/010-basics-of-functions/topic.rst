.. include:: <mmlalias.txt>

.. jf-topic:: c.functions_and_program_structure.basics
   :dependencies: c.program_flow.goto_and_labels

Basics
======

Nesting
-------

.. list-table::
   :align: left

   * * **Global** objects

       * Variables
       * Functions

       **Local** objects

       * Variables

       Functions cannot be defined *locally*

     * .. code-block:: c

          int global;
          
          void f(void)
          {
              int local;
          
              /* visibility: */
              local = global;
          }

Modularization
--------------

No non-trivial program consists of only one source file
|longrightarrow| *modularization*

* Code in multiple files
* Separate compilation
* Organization in (shared) libraries
* Combining (*linking*) of separately compiled entities into an
  executable program
* **Re-use**: building different programs from the same *modules*

Declaration vs. Definition
--------------------------

**Declaration**: compiler needs to know things ("*objects*") in order
to treat them right. It doesn't need to know where in memory they are
though - only the type.

**Definition**: setting aside memory for objects.

A definition ist eine declaration, but not vice versa.


* *Variables*

  * Until now we only *declared* und at the same time *defined*
    variables
  * Pure declaration possible |longrightarrow| ("``extern``")

* *Functions*: usually only *declared* before use, and *defined* separately.

A Monolithic Program
--------------------

.. code-block:: c

   void g(void); /* Declaration */
   void main(void)
   {
       g(); /* Use */
   }
   void f(void); /* Declaration */
   void g(void) /* Definition */
   {
       printf("g()\n");
       f(); /* Use */
   }
   void f(void) /* Definition */
   {
       printf("f()\n");
   }

Separate Compilation
--------------------

.. list-table::
   :align: left

   * * ``f.c``

       .. code-block:: c

          void f(void)
          {
              printf("f()\n");
          }

     * ``g.c``

       .. code-block:: c

          void f(void);
          void g(void)
          {
              printf("g()\n");
              f();
          }

   * * ``main.c``

       .. code-block:: c

          void g(void);
          void main(void)
          {
              g();
          }

     * **Built like so:**

       .. code-block:: c

	  $ gcc main.c f.c g.c
