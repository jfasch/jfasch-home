.. include:: <mmlalias.txt>


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
