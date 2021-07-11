.. include:: <mmlalias.txt>

.. jf-topic:: c.performance.introduction
   :dependencies: c.program_sanity.valgrind

Optimization
============

Optimization - Introduction
---------------------------

**General Rules ...**

* Focus on clean design $\to$ efficiency follows
* Optimization near the end of the project
* Proven hotspots need optimization
* *Proof through profiling*

.. note::

    "Premature optimization is the root of all evil"

    **Donald E. Knuth**

Compute Bound or IO Bound? (1)
------------------------------

**Decide whether, what and how to optimize!**

* Collect representative input data
* Why does the program take long?
* Where does it spend most of its time?

  * Userspace: this is where computation is generally done
  * Kernel: ideally very little computation

Compute Bound or IO Bound? (2)
------------------------------

**Checksumming From An Externel USB Disk**

.. code-block:: console

   $ time sha1sum 8G-dev.img.xz > /dev/null
   real	0m38.879s
   user	0m3.349s
   sys	0m0.375s

* ``real``: total perceived run time ("wall clock time")
* ``user``: total CPU time spent in userspace
* ``sys``: total CPU time spent in kernel

**Here:** ``user`` + ``sys`` is *far less* than ``real``
|longrightarrow| mostly IO

Compute Bound or IO Bound? (3)
------------------------------

**Checksumming From Internal SSD**

.. code-block:: console

   $ time sha1sum 01\ -\ Dazed\ and\ Confused.mp3 1>/dev/null
   
   real	0m0.128s
   user	0m0.107s
   sys	0m0.018s

**Here:** ``user`` + ``sys`` is *roughly equal* to ``real``

* Almost no IO
* |longrightarrow| Compute bound

What to do Next?
----------------

**Now that we know that our application is compute bound ...**

* See where it spends most of its time |longrightarrow| *profiling*
* Decide whether optimization would pay off
* Understand what can be done
* Understand optimizations that compilers generally perform
