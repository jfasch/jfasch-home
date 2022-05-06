.. ot-exercise:: linux.sysprog.fileio.basics_exercise_copy
   :dependencies: linux.sysprog.fileio.basics


Exercise: Copy A File
---------------------

Write a program that interprets its two arguments as file
names, and copies the first to the second. The first must be an
existing file (error handling!). The second is the target of the
copy. No existing file must be overwritten.

.. code-block:: console

   $ ./my-copy /etc/passwd /tmp/passwd-copy

.. code-block:: console

   $ ./my-copy /etc/passwd /tmp/passwd-copy
   Error: file exists
