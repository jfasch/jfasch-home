.. ot-group:: sysprog.syscalls

System Calls
============

Knowing what the responsibilities of an OS kernel are, it is clear
that a request for one of its services (like opening a file for
reading) cannot be an ordinary function call.

Here we discuss what a system call is, how system call errors are
generally handled (spoiler: :ref:`a global variable
<sysprog-syscalls-errno>` |:pig:|) and what debugging tools exist at
that level (spoiler: :ref:`strace <sysprog-syscalls-strace>`).

.. toctree::
   :maxdepth: 1

   overview/index
   errorhandling/index
