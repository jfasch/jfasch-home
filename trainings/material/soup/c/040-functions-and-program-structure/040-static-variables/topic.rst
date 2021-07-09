.. include:: <mmlalias.txt>

.. jf-topic:: c.functions_and_program_structure.static_variables
   :dependencies: c.functions_and_program_structure.header_files


Static Variables
================

Lifetime and Visibility (1)
---------------------------

**Time span where a variable is** *alive* **(its address is valid)**

* The time of a function call $\to$ *automatic* variable
* The entire program

**Visibility of a variable**
  
* Inside the where it is defined |longrightarrow| *internal* Variable
* Inside the file where is is defined
* Across the entire programx

Automatic Variables
-------------------

.. list-table::
   :align: left

   * * * Visibility: function
       * Lifetime: function

     * .. code-block:: c

          void f(void)
          {
              int i;
          }

Local ``static`` Variable
-------------------------

* Visible only inside the function where it is defined
* Retaines it value across function calls

.. list-table::
   :align: left

   * * * Visible: function
       * Lifetime: program

     * .. code-block:: c

          void f(void)
          {
              static int i;
          }

Global ``static`` Variable
--------------------------

* Visible only inside the file where it has been defined
* Retains its value during program lifetime

.. list-table::
   :align: left

   * * * Visible: file
       * Lifetime: program

     * .. code-block:: c

          static int i;

Global Variable
---------------

* Visible across all files
* Retains its value during program lifetime

.. list-table::
   :align: left

   * * * Visible: program
       * Lifetime: Program

     * .. code-block:: c

          int i;
