.. include:: <mmlalias.txt>

.. ot-exercise:: sysprog.posix_threads.exercise_mutex
   :dependencies: sysprog.posix_threads.mutex


Mutex: Solve Load/Modify/Store Conflict
=======================================

* Use a mutex to protect the integer increment in the last
  exercise. *What do you notice?*
* Replace the mutex and the increment with a suitable atomic
  instruction (``__sync_fetch_and_add()``).  *What do you notice?*
