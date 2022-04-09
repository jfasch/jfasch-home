.. include:: <mmlalias.txt>


Screenplay
==========

.. contents::
   :local:

Words
-----

* Uncle Bob only marginally talks about testing, later on. He is
  convinced that testing is necessary though, although he brings it as
  a solution for a problem that he builds up. I'll start earlier.
* Craftsmanship; my own past of becoming a craftsman

  * A project that falls apart because of ... overengineering
  * Nights of debugging (fun but doesn't scale)

* Scenario

  * Someone makes a dumb mistake and software kills 10000 people
  * Politics will jump in want answers
  * If we do not have one, they will regulate
  * Do we want this?
  * Ethics maybe? Do we have ethics?

* Survey: who has had a project in thier life that got out of control?
  Why?

09:00-10:30: Establishing The Project (Live Hacking, Slides)
------------------------------------------------------------

.. sidebar::

   **Goal**

   * Establish an initial code base
   * That is the problem |longrightarrow| *it has a bug*
   * Initial *informal* test suite

In a live-hacking session, establish the initial project state.

.. toctree::
   :maxdepth: 1

   block-before-googletest

10:30-10:45: Coffee Break
-------------------------

10:45-12:00: Cornerstones From The "Clean Code" Book
----------------------------------------------------

Craftsmanship? What's That?
...........................

.. image:: electrical-nonsolution.jpg
   :scale: 40%

.. image:: gsellmanns-weltmaschine.jpg
   :scale: 40%



Blah 

* Respect: author cares about me

blah



* A word about OO |longrightarrow| overengineering is the greatest bug
* Architecture

  * Good architecture allows major decisions to be deferred
  * Maximizes the number of decisions *not made*
  * Makes choice of tools irrelevant
  * Cite Luke :-)

* Software development cycle (*not (!!)*: waterfall)
* Requirements

  * At a small scale, tests are easy. Mocking a database away maybe?
    New reader/writer.
  * Lost tests? Do ``CMake`` and ``googletest`` help in this regard?

* *Intuitive* implementation (|longrightarrow| respect from co-workers
  and oneself)
* Refactoring: removing unclean code and *not* breaking requirements

  E.g., factor out readers and writers in an interface, and separate.

* Craftsmanship? 
* **Maintainability?**
* Bonus topics about code structure [#code-structure]_, maybe

Clean Code Book Chapters
........................

Keep the structure, give an overview of what he says (|longrightarrow|
*respect*), and discuss a few topics. Don't forget "The Code is
Documentation Enough* T - shirt.

* Clean Code: what is that?
* Names

  * Clear and concise. Nobody should have to think longer than
    necessary what the named thing is. No encoding, no nothing. Gosh,
    *hungarian notation*.

    * Is ``UserDB`` a good name? It keeps data in-memory, and has
      methods ``read()`` and ``write()`` bolted onto it
      
      * |longrightarrow| unclear semantics
      * See :ref:`requirement <userdb-naming-and-implementation>`

  * Class member names: no mangling, like prefixing with
    ``m_``. Classes must be short enough to not need this.
  
* Functions

  * Not everything must take dogmatically though
  * |longrightarrow| Make a case for ``switch``, by doing
    :ref:`userdb-backingstore-interface`
  
* Comments

  * Wear T-shirt

* Formatting

  * Newspaper Metaphor

* Objects and Data Structures
* Error Handling
* Boundaries
* Unit Tests

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

* Classes. Gosh, OO. Couple principles maybe.

  * Not loose overview |longrightarrow| classes should be small
  * One responsibility
  * ... (it's always the same)


10:30-11:00 Enter Unit Test Frameworks
--------------------------------------

.. sidebar::

   **Goal**

   * Establish terminology
   * Show ``googletest`` basics

* jjj slideshow about unit testing, extract from :download:`PDF
  </trainings/material/pdf/060-design-patterns-unittests.pdf>`
* jjj polish :doc:`/trainings/material/soup/unittest/unittest_gtest_basics/screenplay`
* jjj polish :doc:`/trainings/material/soup/unittest/unittest_gtest_cmake/screenplay`

.. toctree::
   :maxdepth: 1

   enter-googletest

12:00-13:00: Lunch Break
------------------------

UNPOLISHED FROM HERE ON
-----------------------

Requirements
------------

Error Handling
..............

* Not overwrite existing files
* Refuse to read from file when inmem already has data (but see
  :ref:`pass-store-in-ctor`)
* Properly defined exceptions (can start with flat unrelated exception
  types, and then be unified under a common exception type)

  Search for ``assert``

Refactoring
...........

* A fixture for temporary files as we would like it. Testname in the
  file stem, but *not* in CWD. Rather in ``/tmp``.

.. _pass-store-in-ctor:

Load From BackingStore in Constructor
`````````````````````````````````````

**Problem**

Why live with the restriction that ``UserDB`` cannot load fom a
``BackingStore`` when we already have data?

**Solution**

* Load from a ``BackingStore`` when ``UserDB`` is initialized.
* Remove the error type

.. _userdb-naming-and-implementation:

``UserDB`` Naming and Implementation
````````````````````````````````````

* ``UserDB`` is an in-memory structure - a cache basically
* It has ``read()`` and ``write()`` methods bolted onto it, with
  unclear signature (``bool binary``?)
* Create a ``BackingStore`` class that ``UserDB`` gets passed in the
  constructor (where it then loads from). It does the
  ``read()/write()`` when the user calls ``sync()`` on ``UserDB``.

.. _userdb-backingstore-interface:

``UserDB``: ``BackingStore`` Must Be An Interface
`````````````````````````````````````````````````

That entire file format mess. Now
(:ref:`userdb-naming-and-implementation`) we have a dedicaded
``BackingStore`` class, but that does two jobs/formats.

* |longrightarrow| *Strategy* pattern
* Flag ``bool binary=true``. From that we know that there is a binary
  file format somehow. We can assume that there is at most one
  additional format, but not which one that could be.

  * |longrightarrow| use an ``enum`` and a ``switch`` statement
  * |longrightarrow| show how ``-Wswitch`` (and ``-Werror``) can help
    (UB partly hates ``switch`` because he does not know about that
    feature)

  Discuss *dependency magnetism* though: *every future file format
  would have to be implemented inside the class*.

* Everything is still implemented inside ``BackingStore``
* Make ``BackingStore`` an interface, derive ``Binary`` and ``CSV``
  from it
* Change it in frondend programs
* |longrightarrow| pull out an ``argv``-to-``BackingStore`` function
  to centralize code.

Features
........

* Search by other indexes. ``lastname`` |longrightarrow| multiple
  search results. Something like ``std::lower_bound`` maybe.

.. rubric:: Footnotes

.. [#rvalue-ref] If somebody asks, talk about :doc:`C++ 11 move
                 semantics
                 </trainings/material/soup/cxx11/020-new-language-features/060-move/topic>`
                 |:wink:|

.. [#code-structure] 

   * What's a "module"?
   * *Dependency management*
   
     * Modules depend on others
     * Often the *why* is unknown |longrightarrow| "just happened"
     * *Dependency Inversion*: depending on *interfaces* rather than
       *implementations*
     * ``cmake --graphviz=...``
   
   * Road to hell: *cyclic dependencies* and *global variables*
