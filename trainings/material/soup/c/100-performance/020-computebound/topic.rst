.. ot-topic:: c.performance.computebound
   :dependencies: c.performance.introduction

.. include:: <mmlalias.txt>


Optimizations: Compute Bound Code
=================================

.. contents::
   :local:

Many Ways of Optimization
-------------------------

**There are many ways to try to optimize code** ...

* Unnecessary ones
* Using better algorithms (e.g. sorting and binary search)
* Function call elimination (inlining vs. spaghetti)
* Loop unrolling
* Strength reduction (e.g. using shift instead of mult/div)
* Tail call elimination
* ...

Unnecessary Optimizations
-------------------------

.. code-block:: c

   if (x != 0)
       x = 0;

* The rumour goes that this is not faster than unconditional writing
* Produces more instructions, at least

Inlining (1)
------------

**Facts up front:**

* Function calls are generally fast
* A little slower when definition is in a shared library
* Instruction cache, if used judiciously, makes repeated calls even faster
* But, as always: it depends

**Possible inlining candidate**

.. code-block:: c

   int add(int l, int r)
   {
       return l + r;
   }

Inlining (2)
------------
  
**A couple rules**

* Always write clear code
* Never *not* define a function because of performance reasons

  * *Readability first*
  * Can always inline later, during optimization

* Don't inline large functions |longrightarrow| instruction cache
  pollution when called from different locations
* Use ``static`` for implementation specific functions
  |longrightarrow| compiler has much more freedom

Inlining (3)
------------
  
**GCC ...**

* Does not optimize by default
* Ignores explicit ``inline`` when not optimizing
* ``-finline-small-functions`` (enabled at ``-O2``): inline when
  function call overhead is larger than body (even when not declared
  inline)
* ``-finline-functions`` (enabled at ``-O3``): all functions
  considered for inlining |longrightarrow| heuristics
* ``-finline-functions-called-once`` (enabled at ``-O1, -O2, -O3,
  -Os```): all ``static`` functions that ...
* More |longrightarrow| ``info gcc``

Register Allocation (1)
-----------------------

* Register access is orders of magnitude faster than main memory
  access

  * |longrightarrow| Best to keep variables in registers rather than
    memory

* CPUs have varying numbers of registers

  * ``register`` keyword should not be overused
  * Ignored anyway by most compilers

* Register allocation

  * Compiler performs flow analysis
  * Live vs. dead variables
  * "Spills" registers when allocation changes

**Compiler generally makes better choices than the programmer!**

Register Allocation (2)
-----------------------

**GCC ...**

* ``-fira-*`` (for Integrated Register Allocator)
* `RTFM please
  <https://gcc.gnu.org/onlinedocs/gccint/RTL-passes.html>`__
* A *lot* of tuning opportunities for those who care

Peephole Optimization
---------------------

* **Peephole**: manageable set of instructions; "window"
* Common term for a group of optimizations that operate on a small
  scale

  * Common subexpression elimination
  * Strength reduction
  * Constant folding

* Small scale |longrightarrow| "basic block"

Peephole Optimization: Common Subexpression Elimination
-------------------------------------------------------

Sometimes one writes redundant code, in order to not compromise
readability by introducing yet another variable ...

.. code-block:: c

   a = b + c + d;
   x = b + c + y;

This can be transformed into

.. code-block:: c

   tmp = b + c; /* common subexpression */
   a = tmp + d;
   x = tmp + y;

Peephole Optimization: Strength Reduction
-----------------------------------------

Most programmers prefer to say what they mean (fortunately) ...

.. code-block:: c

   x = y * 2;

The same effect, but cheaper, is brought about by ...

.. code-block:: c

   x = y << 1;

If one knows the "strength" of the operators involved (compilers tend
to know), then even this transformation can be opportune ...

.. code-block:: c

   x = y * 3; /* y*(4-1) == y*4-y */
   x = (y << 2) - y;

Peephole Optimization: Constant Folding
---------------------------------------

Another one that might look stupid but readable ...

.. code-block:: c

   x = 42;
   y = x + 1;

... is likely to be transformed into ...

.. code-block:: c

   x = 42;
   y = 43;

Consider transitive and repeated folding and propagation
|longrightarrow| pretty results

Loop Invariants
---------------

The following bogus code ...

.. code-block:: c

   while (1) {
       x = 42; /* loop invariant */
       y += 2;
   }

... will likely end up as ...

.. code-block:: c

   x = 42;
   while (1)
       y += 2;

At least with a minimal amount of optimization enabled (GCC:
``-fmove-loop-invariants``, enabled with ``-O1`` already)

Loop Unrolling
--------------

If a loop body is run a known number of times, the loop counter can
be omitted.

.. code-block:: c

   for (i=0; i<4; i++)
       dst[i] = src[i];

This can be written as 

.. code-block:: c

   dst[0] = src[0];
   dst[1] = src[1];
   dst[2] = src[2];
   dst[3] = src[3];

* *Complicated heuristics*: does the performance gain outweigh
  instruction cache thrashing?
* |longrightarrow| I'd keep my fingers from it!

Tail Call Optimization
----------------------

.. code-block:: c

   int f(int i)
   {
      do_something(i);
      return g(i+1);
   }

* ``g()`` is called *at the end*
* ``f()``'s stack frame is not used afterwards
* **Optimization:** ``g()`` can use ``f()``'s stack frame

CPU Optimization, Last Words
----------------------------

Once more: **Write clean Code!**

* All optimization techniques explained are performed *automatically*,
  by the compiler
* Theory behind optimization is well understood |longrightarrow|
  engineering discipline
* Compilers generally perform optimizations better than a programmer
  would

  * ... let alone portably, on different CPUs!

* "Optimization" is a misnomer |longrightarrow| "Improvement"

  * Compiler cannot make arbitrary code "optimal"
  * Bigger picture is always up to the programmer
  * |longrightarrow| Once more: **Write clean Code!**

* Work together with compiler |longrightarrow| use ``static``, ``const``

GCC: Optimization "Levels"
--------------------------

* ``-O0``: optimization off; the default
* ``-O1``: most basic optimizations; does as much as possible without
  compromising compilation time too much
* ``-O2``: recommended; does everything which has no size impact, is
    unagressive, and doesn't completely chew compilation time
* ``-O3``: highest level possible; somewhat agressive, can break
  things sometimes, eats up your CPU and memory while compiling
* ``-Os``: optimize for size; all of ``-O2`` that doesn't increase
  size
* ``-Og`` (since GCC 4.8): "developer mode"; turns on options that
  don't interfere with debugging or compilation time

Further Reading
---------------

* `Wikipedia: Optimizing compiler
  <https://en.wikipedia.org/wiki/Optimizing_compiler>`__
* `GCC optimization <https://wiki.gentoo.org/wiki/GCC_optimization>`__
* `Compiler Construction/Optimization
  <http://en.wikibooks.org/wiki/Compiler_Construction/Optimization>`__
* `Steven S. Muchnik: Advanced Compiler Design and Implementation
  <https://www.amazon.de/Advanced-Compiler-Design-Implementation-Muchnick/dp/1558603204>`__
* `John R. Levine: Linkers and Loaders
  <https://www.amazon.de/Linkers-Loaders-John-R-Levine/dp/1558604960>`__
