.. include:: <mmlalias.txt>

.. jf-topic:: c.pointers_and_arrays.pointers_and_function_arguments
   :dependencies: c.pointers_and_arrays.pointers_and_addresses


Pointers as Function Parameters
===============================

.. contents::
   :local:

Call by Reference (1)
---------------------

.. list-table::
   :align: left

   * * * **Problem**: in C, parameters are passed by-copy* - callee
         *see *copies* of the caller's values.
       * **Question**: how can I use a function to *modify* the
         caller's value?

     * .. code-block:: c

          void f(int a)
          {
              a = 42;
          }
          
          void main(void)
          {
              int i = 1;
              
              f(i);
              /* i is still 1 */
          }

Call by Reference (2)
---------------------

**Solution**: pointer

.. code-block:: c

   void f(int *a)
   {
       *a = 42;
   }
   
   void main(void)
   {
       int i = 1;
       
       f(&i);
   }

