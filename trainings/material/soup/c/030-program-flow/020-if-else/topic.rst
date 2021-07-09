.. include:: <mmlalias.txt>

.. jf-topic:: c.program_flow.if_else
   :dependencies: c.program_flow.statements_and_blocks


``if`` - ``else``
=================

Branches
--------

If *condition* holds true, then we do *this*, else we
do *that* ...

.. code-block:: c

   if (condition)
       this
   else
       that

*this* und *that* are statements ...
  
.. code-block:: c

   if (a < 0)
       a = -a;
   else {
       a = a;
       fprintf(stderr, "alright\n");
   }

True or False? What is Truth?
-----------------------------

.. code-block:: c

   if (condition)
      ...

* *condition* is an *expression*
* An *expression* has a value
* In ``if`` (other similar statements) its value is used as condition
* 0 ... condition does not hold |longrightarrow| *false*
* Everything else ...  |longrightarrow| *true*

``else`` is optional (1)
------------------------

``if`` *may* be followed by an ``else`` branch (but need not)

.. code-block:: c

   if (condition)
       if (another-condition)
           this
       else
           that

**Ambiguity**: where does the ``else`` branch belong?

``else`` is optional (2)
------------------------

**Dangling** ``else``: compiler does not care about
indentation |longrightarrow| *careful*!

.. code-block:: c

   if (condition)
       if (another-condition)
           this
   else
       that

**Braces required!**

.. code-block:: c

   if (condition) {
       if (another-condition)
           this
   }
   else
       that
