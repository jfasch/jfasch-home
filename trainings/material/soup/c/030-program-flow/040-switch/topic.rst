.. include:: <mmlalias.txt>

.. jf-topic:: c.program_flow.switch
   :dependencies: c.program_flow.else_if


``switch``
==========

Case Distinctions
-----------------

**Problem**: ``if`` - ``else if`` ... - ``else``

* Much typing
* ... especially when checking for equality of integers
* Direct jump table (compiler generated) would be more efficient

``if - else if`` vs. ``switch``
-------------------------------

.. list-table::
   :align: left

   * * .. code-block:: c

          if (c == ' ')
              ...
          else if (c == '\n' || 
                   c == '\t')
              ...
          else
              ...

     * .. code-block:: c

          switch (c) {
              case ' ':
                  ...
                  break;
              case '\n':
              case '\t':
                  ...
                  break;
              default:
                  ...
          }

``switch``
----------

* Labels must only be *constants* (and constant expressions), no *variables*

  * known at compile time

* Equality |longrightarrow| code starting at label is executed, until
  the end of ``switch`` statement
* ``break``: *fall through* otherwise
* *fall through* sometimes desired, but mostly not |longrightarrow|
  careful!
* ``default`` label is optional

**When do I use it?**

* Finite number of values (e.g. states of a *state machines*)
* ``switch`` over ``enum`` without ``default``: compiler can warn
  about missing label |longrightarrow| very useful!
