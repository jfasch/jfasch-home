.. include:: <mmlalias.txt>

.. jf-topic:: c.profiling.introduction
   :dependencies: c.performance.memory


Introduction
============

Profiling - Famous Words
------------------------

.. admonition:: Donald E. Knuth

   Premature optimization is the root of all evil

.. admonition:: Tony Hoare

   Premature optimization is the root of all evil

.. admonition:: Larry Wall

   Optimizations always bust things, because all optimizations are, in
   the long haul, a form of cheating, and cheaters eventually get
   caught.

.. admonition:: The Practice of Programming, Brian W. Kernighan and
                Rob Pike

   Measurement is a crucial component of performance improvement since
   reasoning and intuition are fallible guides and must be
   supplemented with tools like timing commands and profilers.

Profiling - Introduction
------------------------

**General Rules ...**

* Focus on clean design |longrightarrow| efficiency follows
* Optimization near the end of the project
* Proven hotspots need optimization
* *Proof through profiling*

**How?** On Linux ...

* ``gprof``: compile time code instrumentation, single program
* ``valgrind --tool=callgrind``: emulation
* ``oprofile``: no instrumentation, global system view
