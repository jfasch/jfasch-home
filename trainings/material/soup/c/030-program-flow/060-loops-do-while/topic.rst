.. include:: <mmlalias.txt>

.. ot-topic:: c.program_flow.loops_do_while
   :dependencies: c.program_flow.loops_while_and_for


Loops: ``do - while``
=====================

``do - while``: Condition After Body
------------------------------------

.. code-block:: c

   do
       do-something
   while (condition);

* Condition is checked *after* body
* |longrightarrow| body is executed *at least once*
