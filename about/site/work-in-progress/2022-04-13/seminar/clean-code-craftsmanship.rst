.. include:: <mmlalias.txt>


Clean Code: Messages From The Book
==================================

.. contents::
   :local:

Clean Code Book Chapters
------------------------

Keep the structure, give an overview of what he says (|longrightarrow|
*respect*), and discuss a few topics. Don't forget "The Code is
Documentation Enough* T - shirt.

* Clean Code: what is that?

Names
.....

* Clear and concise. Nobody should have to think longer than necessary
  what the named thing is. No encoding, no nothing. Gosh, *hungarian
  notation*.

  * Is ``UserDB`` a good name? It keeps data in-memory, and has
    methods ``read()`` and ``write()`` bolted onto it
    
    * |longrightarrow| unclear semantics
    * See :doc:`tasks/refactoring/pass-store-in-ctor`

* Class member names: no mangling, like prefixing with ``m_``. Classes
  must be short enough to not need this.
  
Functions
.........

* Not everything must take dogmatically though
* |longrightarrow| Make a case for ``switch``
* :doc:`tasks/refactoring/store-enum-switch`
  
Comments
........

* Wear T-shirt

Formatting
..........

* Newspaper Metaphor

Objects and Data Structures
...........................

Error Handling
..............

Boundaries
..........

Unit Tests
..........

Three laws of TDD ...

1. You may not write production code until you have written a
   failing unit test
2. You may not write more of a unit test than is sufficient to fail
   (and not compiling is a failure)
3. You may not write more production code than is necessary to pass
   current tests

Refactoring ...

* Initial code is a mess (nobody writes clean code from the
  beginning)
* Takes roughly the same time than it took to write code initially
* |longrightarrow| nobody likes it
* Anyway, it is the only way to keep code clean
* |longrightarrow| integral part of our craftsmanship

Another look ...

* If you are not able to test in isolation, then something is wrong
* If you must fire up an Oracle database to conduct testing, then
  something's seriously wrong

It's only tests?

* Seriously, no!
* Tests are the safety net of your architecture |longrightarrow|
  keep production code together
* |longrightarrow| treat them carefully!
* Production code follows the tests, actually!

F.I.R.S.T.

* Fast
* Independent
* Repeatable
* Self-validating (either pass or fail)
* Timely (test first)

.. note:: 

   * Couple words about debugging!!!!
   * Writing tests after the fact -> come across code that is hard to
     test

Classes
.......

Gosh, OO. Couple principles maybe.

* Not loose overview |longrightarrow| classes should be small
* One responsibility
* ... (it's always the same)

