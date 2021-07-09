.. include:: <mmlalias.txt>

.. jf-topic:: c.program_flow.goto_and_labels
   :dependencies: c.program_flow.break_and_continue

``goto`` and Labels
===================

Structured Programming vs. ``goto``
-----------------------------------

**Structured programming:**

* Only controlled program flow
* Loops and branches
* At most ``break`` and ``continue``

  * Only one level concerned

``goto`` **is the exact opposite**

* Jump statement out of 10 nested loops
* |longrightarrow| Massacre
* Edsger Dijkstra, 1968: "Goto Considered Harmful"
* |longrightarrow| Plea for structured programming

``goto``: Definition
--------------------

**C offers easy ways to do what you want**

* Dennis Ritchie: "There is no spirit of C!"
* Jörg Faschingbauer: *there is*!

Definition of ``goto``:

* ``goto label;``
* ``label`` is the name of a place inside the function
* |longrightarrow| ``label`` is only *locally* visible
* Naming rules: like a variable
* ``goto`` can jump to arbitrary places inside the function

``goto``: Use Cases
-------------------

.. list-table::
   :align: left

   * * **Manifold**, but ...

       * Easily shot in the foot
       * Suggestion: use judiciously *error handling*
       * Linux Kernel is full of it

     * .. code-block:: c

          int do_complicated_stuff(void)
          {
              while (...) {
                  ...
                  for (...) {
                      if (error)
                          goto out;
                  }
              }
              return 0;
          out:
              cleanup_mess();
              return -1;
          }
