.. include:: <mmlalias.txt>

.. jf-exercise:: sysprog.posix_threads.exercise_condition_variable
   :dependencies: sysprog.posix_threads.condition_variable


Condition Variable: Message Queue
=================================

**Write a program that ...**
  
* ... starts a consumer thread. The consumer reads data from the
  queue, and writes it to Standard Output. The consumer thread should
  terminate by receiving a special token over the queue.
* ... starts a producer thread. The producer read data from Standard
  Input, line by line. Each line is sent to the consumer over the
  queue.
* When the producer sees *end of file* on Standard Input, he inserts a
  *quit* token into the queue and terminates.
* The main thread joins with both threads, and terminates once both
  are done.
