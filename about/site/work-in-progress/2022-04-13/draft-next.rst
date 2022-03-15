.. include:: <mmlalias.txt>


Agenda (Draft, Unpublished)
===========================

.. contents::
   :local:

.. note:: **Changes from** :doc:`draft-2022-02-16`

   * Add section on "Code Structure"
   * Proposed changes 2022-03-09

     * Block 1: Clean code

       * Thoughts from Uncle Bob |longrightarrow| discussion
       * Keeping Code Clean in the Small

     * Block 2: Unit Testing, TDD

       * C/C++: googletest
       * Python: pytest (sketch only)
       * Livehacking and simple project

     * Block 3: TDD hands-on

       * 7 people |longrightarrow| groups
       * Artificial project; it's not easy to find code that can be
         made testable/tested at customer's site.
       * cmake, cdash (?), ctest, visual studio (2019, doze)
       * In-house tools for unittests?

	 * cdk (core development kit) testsystem (home-made, unwanted
           internally)
	 * https://robotframework.org/ -> jenkins

       * Create two dummy projects googletest and boost, try to build
         those

Introduction: Clean Code? What is that?
---------------------------------------

.. sidebar:: 

   .. image:: clean-code.jpg

`Clean Code: A Handbook of Agile Software Craftsmanship, by
Robert C. Martin ("Uncle Bob")
<https://www.oreilly.com/library/view/clean-code-a/9780136083238/>`__

Cornerstones ...

* Software development cycle (*not (!!)*: waterfall)
* Requirements
* *Intuitive* implementation (|longrightarrow| respect from co-workers
  and oneself)
* Refactoring: removing unclean code and *not* breaking requirements
* Craftsmanship? 
* **Maintainability?**

Object Oriented Programming
---------------------------

* Not necessarily a science
* Start with *encapsulation*

  * |longrightarrow| Non-over-engineering (but discipline, maybe)

* People tend to talk about objects (data) and their behavior

  * |longrightarrow| Terminology
  * |longrightarrow| Requirements
  * |longrightarrow| Why not reflect terminology in code?

.. todo::

   Find an easy to implement use case from your domain that I can give
   a live-codeing sketch about.

   * First, in C |longrightarrow| no language support for OO, but
     manageable with a little discipline (not so intuitive though for
     the inexperienced).
   * Same in C++

Interfaces, Implementations, and Design Patterns
------------------------------------------------

* Example: codecs in `libav <https://libav.org/>`__

  * *Interface* in ``libavcodec/avcodec.h``
  * One of many *implementations*: ``libavcodec/libmp3lame.c``
  * *Instantiation* and usage in ``avtools/avplay.c``

* Inheritance

  * ... is not at all intuitive in C
  * Understanding that *function pointers are used for interface
    implementations* helps a lot
  * Enter C++: ``virtual`` and all that (gosh)
  * Short live-coding: draw a simplified sketch of the same matter in
    C++.
  * Enter *Design Patterns*: libav codec instantiation is an
    application of the *Factory* pattern

* Quick run through `GoF Patterns
  <https://www.oreilly.com/library/view/design-patterns-elements/0201633612/>`__

  * Maybe a little sample coding on select patterns (*Adapter*,
    *Proxy*, *Composite* are the most understandable).
  * Mix coding with UML whiteboard drawings, this gives a gentle
    introduction.

Code Structure
--------------

* What's a "module"?
* *Dependency management*

  * Modules depend on others
  * Often the *why* is unknown |longrightarrow| "just happened"
  * *Dependency Inversion*: depending on *interfaces* rather than
    *implementations*
  * ``cmake --graphviz=...``

* Road to hell: *cyclic dependencies* and *global variables*

Requirements Engineering: *Boring* |longrightarrow| Unit Testing
----------------------------------------------------------------

* Nobody can plan 100% ahead

  * Road/building construction does a good job
  * Never seen that in software engineering
  * Fortunately, software can be easily changed in its lifecycle
    (hence the name)

* |longrightarrow| best to not even try
* Enter *Agile* |longrightarrow| automatic testing at the basis of all
  agile processes

Unit Testing Terminology
........................

* Short run through slide material on the matter
* Use Python for simplicity
* Python's ``unittest`` module has most of the terminology explicit
* Show what *test driven development* is, prototypically

  * Write initial test |longrightarrow| fails (no implementation
    there)
  * Implement, test, implement, ... done
  * Refactor

.. todo::

   Find a simple problem-to-solve from your domain that can be done in
   Python. Would be cool if it is related to the one above.

More Unit Testing Frameworks
............................

* Rewrite tests in `pytest <https://docs.pytest.org/>`__ (simply
  because it is outright *amazing!*)
* `Boost.Test
  <https://www.boost.org/doc/libs/1_66_0/libs/test/doc/html/index.html>`__
* `googletest <https://github.com/google/googletest>`__
* `CMake's CTest <https://docs.pytest.org/en/7.0.x/>`__

Conclusion/Message
..................

* Unit Testing makes code clean from beginning
* Refactoring is done as needed (no fear of breakage)
* Part of software craftsmanship

Keeping Code Clean in the Small
-------------------------------

C Language Support for Code Sanity
..................................

See :doc:`/trainings/material/soup/c/090-program-sanity/group` for
available slide material. Maybe do some live coding if there is time
and interest.

* ``const`` correctness
* ``static``: constraining global visibility
* Integer sizes and signedness
* Advanced techniques

Compiler Warning and Error Options
..................................

Talk about GCC/LLVM's options to enable warnings on suspicious code.

Optimization
............

* Show what compilers usually can do for you, performance-wise
  (message: they are better at writing ugly code than any human).

  :doc:`/trainings/material/soup/c/100-performance/020-computebound/topic`

* Memory optimization: Caches, array traversal

  :doc:`/trainings/material/soup/c/100-performance/030-memory/topic`
