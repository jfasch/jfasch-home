.. ot-exercise:: linux.sysprog.fileio.basics_exercise_hole
   :dependencies: linux.sysprog.fileio.basics


Exercise: Create File With Hole
===============================
  
Create a file that claims to be 1 GB in size, but occupies only a
couple of bytes physically.

.. code-block:: console

   $ ./hole /tmp/hole
   $ ls -l /tmp/hole
   -rw-rw-r--. 1 jfasch jfasch 1073741825 May  6 17:08 /tmp/hole
   $ du -sh /tmp/hole
   4.0K    /tmp/hole
