Scheduling: Exam Questions
==========================

* Which term reflects a *guaranteed response time*? (One correct
  answer.)

  * Multithreading
  * Realtime
  * Scheduling

* What is the difference between a thread and a process? (One correct
  answer.)

  * A process has its own address space, where a thread has not.
  * A thread has its own address space, where a process has not.

* Which of the following statements about a *process's address space*
  is true? (Wrong answers are subtracted from correct answers.)

  * A range of memory set aside for a process's exclusive use.
  * Provides memory isolation between processes.
  * A pool of IP addresses that are made available to it.
  * A process cannot access memory outside of that space.

* What is the effect of running the command ``sha1sum /dev/zero``?
  (Wrong answers are subtracted from correct answers.)

  * It consumes as much CPU time as it can.
  * It will exhaust all physical memory that is available.
  * It tries to calculate a SHA1 fingerprint of an infinite sequence
    of null bytes.
  * It calculates the sum of the major numbers of all character
    devices on the machine.
  * The process is compute-bound.

* Which of the following statements about *fair scheduling* are true?
  (Wrong answers are subtracted from correct answers.)

  * It is the default scheduling policy for a task (that task is said
    to *be in the fair scheduling domain*).
  * A task that is in the fair scheduling domain can provide
    guaranteed response times.
  * The scheduler favors *IO bound processes* over *CPU bound
    processes*.
  * Fair scheduling can be considered the opposite of realtime
    scheduling.

* Which of the following statements about the *OS scheduler* are true?
  (Wrong answers are subtracted from correct answers.)

  * The scheduler provides the illusion of task parallelism, even on
    single-CPU machines.
  * The scheduler is a core component of the GNOME desktop environment
    which manages the user's to-do list, using machine learning.
  * Its main responsiblity is to assign CPU time slices to waiting
    tasks (effectively moving them into the "running" state).
  * Its main responsiblity is to assign CPU time slices to runnable
    tasks (effectively moving them into the "running" state).

* When a task becomes *runnable*, under which circumstances is it made
  *running* (i.e., is assigned a CPU to run on) **immediately**?
  (Wrong answers are subtracted from correct answers.)

  * When no task with higher priority is runnable.
  * When a CPU is free.
  * When all other tasks explicitly agree.
  * When the administrator permits it to.

* How does a CPU become available/free for another task to run on?
  (Wrong answers are subtracted from correct answers.)

  * By *preemption*: the scheduler interrupts a running task in favor
    of another (runnable) task.
  * *Voluntarily*: the task puts itself to sleep by declaring to the
    kernel that it has to wait for something.
  * The CPU is signaled (by an inter-processor interrupt) by another
    CPU's cache that it should free resources. Reason: one task
    constantly thrashes the signaler's cache.

* Which of the following statements about *priority inversion* is
  true? (Wrong answers are subtracted from correct answers.)

  * Priority inversion can occur only when fair scheduling is in
    place.
  * It is a deadlock scenario (a bug).
  * Realtime systems are particularly susceptible to priority inversion.

* Which of the following statements about *wakeup latency* is true?
  (Wrong answers are subtracted from correct answers.)

  * Wakeup latency is the time between the occurence of an event
    (usually an interrupt), and the point where a task that waits for
    that event enters the *running* state.
  * Realtime scheduling provides a guaranteed upper bound to wakeup
    latency.
  * Fair scheduling provides a guaranteed upper bound to wakeup
    latency.
