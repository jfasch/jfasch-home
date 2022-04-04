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

09:00-11:00: Establishing The Project (Live Hacking, Slides)
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


Enter Unit Test Frameworks
--------------------------

Restructure Test Code
---------------------

* ``mkstemp()`` used a lot
* ``UserDB`` filling


Modifications
-------------

It's about keeping code clean, not features.

Error Handling
..............

* Not overwrite existing files
* Refuse to read from file when inmem already has data
* Properly defined exceptions (can start with flat unrelated exception
  types, and then be unified under a common exception type)

  Search for ``assert``

Refactoring
...........

* Something simple as a common output routine for a user?
* That entire file format mess

  * Flag ``bool binary=true``. From that we know that there is a
    binary file format somehow. We can assume that there is at most
    one additional format, but not which one that could be.

    * |longrightarrow| use an ``enum`` and a ``switch`` statement
    * |longrightarrow| show how ``-Wswitch`` (and ``-Werror``) can
      help (UB partly hates ``switch`` because he does not know about
      that feature)

    Discuss *dependency magnetism* though: *every future file format
    would have to be implemented inside the class*.

  * Everything is implemented inside ``UserDB``: reader and writer
    classes. 

    * |longrightarrow| could also come up with a reader that reads
      user records from stdin, and build that into
      ``bin/userdb-write-binaryfile.cpp`` where it prompts.

      The test for this one would be a little more involved; show that
      maybe.

* A fixture for temporary files as we would like it. Testname in the
  file stem, but *not* in CWD. Rather in ``/tmp``.

Features
........

* Search by other indexes. ``lastname`` |longrightarrow| multiple
  search results. Something like ``std::lower_bound`` maybe.
