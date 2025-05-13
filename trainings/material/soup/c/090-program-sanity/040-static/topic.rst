.. include:: <mmlalias.txt>


Visibility - ``static``
=======================

Visibility
----------

**Compilation unit:** the entity seen by *one* compiler call

* The C file that is being compiled
* All included header files
* Result is usually one object file

**Symbol resolution:**

* By compiler inside *one* compilation unit
* By linker *across multiple* compilation units

  * Among symbols that the linker *sees*

A Somewhat Contrived Example (1)
--------------------------------

Two compilation units linked into an executable ...

.. list-table:: 
   :align: left

   * * .. code-block:: c
          :caption: ``main.c``

          #include <stdio.h>
          
          extern float avg(
            int *begin, int *end);
          
          int main(void)
          {
            int array[] = 
              { 1, 2, 3, 4, 5 };
            printf("%f\n", 
              avg(array, array+3));
            return 0;
          }

     * .. code-block:: c
          :caption: ``avg.c``

          int sum(int *begin, int *end)
          {
              int sum = 0;
              while (begin < end)
                  sum += *begin++;
              return sum;
          }
          float avg(int *begin, int *end)
          {
              return
                (float)sum(begin, end) /
                (end-begin);
          }

A Somewhat Contrived Example (2)
--------------------------------

**Function** ``sum()`` **in** ``avg.c`` **is globally visible**

* Anybody could *declare* it and use it

  * Linker will resolve it (that's his job)

* Name could clash with another symbol in another compilation unit

  * Linker error ("duplicate symbol") when linking statically
  * Subtle bug when using shared libraries

* Innocent reader has to think twice

  * "Can I modify the function without telling anybody?"

|longrightarrow| **Ambiguity** that needs resolution!

The ``static`` Keyword (Hooray!)
--------------------------------

**Solution:** ``static`` - restrict visibility to the compilation unit

.. list-table::
   :align: left

   * * .. code-block:: c
          :caption: ``avg.c``

          static int sum(
            int *begin, int *end)
          {
              int sum = 0;
              while (begin < end)
                  sum += *begin++;
              return sum;
          }

     * * Nobody has to think twice
       * Nobody can use ``sum`` but the file it is defined in
       * No name clashes
       * **No ambiguity!**
       * **Only readability!**
       * Compiler can automatically inline the function
       * ... with only 6 characters of effort
