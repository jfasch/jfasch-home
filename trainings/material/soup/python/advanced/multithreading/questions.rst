.. ot-exercise:: python.advanced.multithreading.exam_questions
   :dependencies: python.advanced.multithreading.basics,
		  python.advanced.multithreading.mutex

Multithreading: Exam Questions
==============================

* Which of the following statements about *threads* is true? (Wrong
  answers are subtracted from correct answers.)

  * A thread shares an *address space* with all other threads in a
    process.
  * Threads are an operating system's way of keeping track of all the
    events that happen while a system is running.
  * A thread's memory is isolated from all other threads in the
    system.
  * When a program starts, the process is made up of one initial
    thread, the *main thread*
  * Threads are a way of achieving *parallel execution* within the
    same address space.

* What can happen when two threads modify the same integer at the same
  time (for example using a plain "+" operator in most programming
  languages)? (One answer.)

  * One of the modifications might be lost.
  * Everything will be ok.

* Which of the following statements about *race conditions* is true?
  (Wrong answers are subtracted from correct answers.)

  * Two or more threads execute a loop, and it is not entirely clear
    which one finishes first.
  * It is a race condition if two or more threads access the same data
    at the same time, without providing any protection for potentially
    overlapping non-atomic operations.

* What device is usually used to prevent race conditions? (One
  answer.)

  * A mutex
  * Character device



.. ot-graph::
   :entries: python.advanced.multithreading.exam_questions
