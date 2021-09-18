.. ot-topic:: ecproposal.ec1.mt.wait
   :dependencies: ecproposal.ec1.mt.lock

Communication: Waiting for Something
====================================

Communication between threads is often solved with *polling*:

* Every second, look into that data structure over there and see if
  something's ready. (Only in rare occasions a mutex is used to do
  this, btw.)
* If response time is a requirement, continue to increase the polling
  interval to the point where it becomes a tight loop.
* Buy bigger batteries to power the device

Goals
-----

* Learn which mechanisms are available to *wait* for something to
  become ready

  * Counting semaphore (as used on many bare metal OSen)
  * Condition variable
