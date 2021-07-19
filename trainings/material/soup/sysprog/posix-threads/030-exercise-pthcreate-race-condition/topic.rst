.. include:: <mmlalias.txt>

.. jf-exercise:: sysprog.posix_threads.exercise_pthcreate_racecondition
   :dependencies: sysprog.posix_threads.lifecycle


Thread Creation, Race Condition
===============================

Write a program that creates two threads. Each one of the threads
increments *the same* integer, say, 10000000 times.

* The integer is shared between both threads (allocated in the
  ``main()`` function). A pointer to it gets passed to the thread
  start function.
* The threads don't increment a copy of the integer, but rather access
  *the same* memory location.

After the starting process (the *main thread*) has synchronized with
the incrementer's termination, he outputs the current value of the
said integer.

*What do you notice?*
