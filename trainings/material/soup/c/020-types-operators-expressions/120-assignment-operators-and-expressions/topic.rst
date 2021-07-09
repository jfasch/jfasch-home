.. include:: <mmlalias.txt>

.. jf-topic:: c.types_operators_expressions.assignment_operators_and_expressions
   :dependencies: c.types_operators_expressions.bit_operators


Assignment with Calculation
===========================

Combined Operators
------------------

**The long way**

.. code-block:: c

   i = i + 2;
   arr[j] = arr[j] + 2;
  
**The short way**

.. code-block:: c

   i += 2;
   arr[j] += 2;

* Less writing (|longrightarrow| confusion)
* Expression evaluated *only once* |longrightarrow| performance
* Applies to ``+``, ``-``, ``*``, ``/``, ``%``, ``<<``, ``>>``, ``&``,
  ``^``, ``|``
