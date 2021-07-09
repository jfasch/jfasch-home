.. include:: <mmlalias.txt>

.. jf-topic:: c.types_operators_expressions.increment_decrement_operators
   :dependencies: c.types_operators_expressions.type_conversions


Increment, Decrement
====================

Confusion: ``++``, ``--``
-------------------------

**Increment- and decrement-Operators** with a subtle difference

.. code-block:: c

   i = 5;

.. list-table:: 
   :align: left
   :header-rows: 1

   * * Operator
     * Name
     * Value of ``i`` afterwards
     * Value of expression
   * * ``++i``
     * Pre-Increment
     * 6
     * 6
   * * ``i++``
     * Post-Increment
     * 6
     * 5
   * * ``--i``
     * Pre-Decrement
     * 4
     * 4
   * * ``i--``
     * Post-Decrement
     * 4
     * 5

Confused to perfection (1)
--------------------------

**No confusion:** copying string while ignoring all occurences
of character ``c`` ...

.. code-block:: c

   void copy_and_omit(char dst[], const char src[], char c)
   {
       int i = 0, j = 0;
   
       while (src[i] != '\0') {
           if (src[i] != c) {
               dst[j] = src[i];
               j = j + 1;
           }
           i = i + 1;
       }
       dst[j] = '\0';
   }

Confused to perfection (2)
--------------------------

**Real men complain**:
  
* *So many lines for a trivial thing?*
* *Multiple indexing does not perform!*

.. code-block:: c

   void copy_and_omit(char dst[], const char src[], char c)
   {
       int i = 0, j = 0;
       char cur;
   
       while ((cur = src[i++]) != '\0')
           if (cur != c)
               dst[j++] = cur;
       dst[j] = '\0';
   }
