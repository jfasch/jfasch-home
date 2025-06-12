Event/Edge Detector
===================

.. contents::
   :local:

Goal
----

Detect edges by *polling* GPIO lines (continuously reading their
state). Currently we don't detect edges - rather we naively read the
*level* and interpret a value of "1" as an event. 

**This is not correct:** if a level of "1" persists through two
consecutive cycles, we will falsely detect two events even though
there was only one rising edge.

*Debouncing* the button should also be done by this class.

How
---

Write a class that *knows* a ``PushButton``. That class has an aptly
named method that is called at each cycle start to read the current
state of the button. If that state differs from the state from the
previous cycle, then we have an edge detected.

To properly debounce the button, the class needs to record the
timestamp where the edge was detected and reported, and ignore further
edges for a configurable period.

Something like follows ...

.. code-block:: c++

   class EdgeDetector
   {
   public:
       EdgeDetector(PushButton* button, const TimeSpec& debounce_period);
       bool /*better: rising/falling/none?*/ detect_edge(const TimeSpec& now);
   };

Testing
-------

This is perfectly unit testable. Use ``PushButtonMock`` to manipulate
the switch state from test code between calls to ``detect_edge()`` and
see how the ``EdgeDetector`` performs.
