.. ot-group:: sysprog.fileio

Files And File Descriptors
==========================

Here we cover one of the most important concepts - file descriptors
[#processes]_, and I/O. While a file on disk is by far not the only
thing that one can do I/O on, we see how the ``open(2)`` :doc:`system
call </trainings/material/soup/linux/sysprog/syscalls/index>` is used
to open and create files in many ways.

Contents
--------

.. toctree::
   :maxdepth: 1

   file-descriptors/index
   open/index
   file-input/index
   file-output/index
   create/index
   dup/index
   lseek/index

   misc

Exercises
---------

.. toctree::
   :maxdepth: 1

   basics-exercise-copy/exercise
   basics-exercise-hole
   exercise-sensor-read

.. rubric:: Footnotes
.. [#processes] :doc:`Processes
		</trainings/material/soup/linux/sysprog/process/index>`
		are just as important
