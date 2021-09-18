.. include:: <mmlalias.txt>

.. ot-topic:: c.program_flow.else_if
   :dependencies: c.program_flow.if_else


``else`` - ``if``
=================

Style Matters
-------------

**Very popular**: multiple cases in a row

.. code-block:: c

   if (condition)
       this
   else if (another-condition)
       that
   else if (one-more)
       ...
   else    
       rest

**More appropriate** in such cases: ``switch``
