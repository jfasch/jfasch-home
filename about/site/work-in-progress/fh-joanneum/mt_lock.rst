.. jf-topic:: ecproposal.ec1.mt.lock
   :dependencies: ecproposal.ec1.mt.exercise_mt_race

Avoiding Race Conditions: Semaphore/Mutex
=========================================

Goals
-----

* Learn how to use *atomic integer access* to avoid the mother of all
  race conditions: *Load/Modify/Store*
* Learn how to use a binary semaphore to avoid race conditions (to
  protect *critical sections*)
* Learn how to use different kinds of mutexes (*normal*
  vs. *recursive* vs. *error-check*)
