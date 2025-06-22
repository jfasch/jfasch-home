SPS Shell
=========

.. contents::
   :local:

Meetings/News
-------------

* 2025-06-17: :ref:`2025-06-17-sps-dreamteam`

Goal
----

Out door implementation is (currently) implemented as a state machine
using a big ``switch`` statement inside ``Door::check()``. Also
currently, to figure out what the user wants ("open door") it uses the
devices like ``PushButton`` directly, like

.. code-block:: c++

   case State::CLOSED: {
       // "open" requested (button press). drive motor, and
       // switch state to "opening"
       if (_do_open->get_state() == PushButton::State::PRESSED) {  // <-- here
           _motor->forward();
           _state = State::OPENING;
       }
       break;
   }

This leads to code that is not easily maintained and tested. Look at
``tests/door-tests.cpp`` for example, to get an impression of the
mess.

Lets see how we can externalize *event detection* from the door
itself, into something that resembles the SPS paradigm. Rather than
having a parameter-less ``Door::check()``, pass into that method
something that already contains information about what has
happened. Like ``Door::check(const Events& events)``, with ``events``
carrying information about what has happened ("push button 'do_open'
pressed", "light barrier 'fully opened' reached", "timer expired", and
so on). ``check()`` can then pick up that information to drive its
state machine, and does not need to directly manipulate hardware
devices.

In other words, lets build something like a "Shell" around
``Door::check(...)`` that 

* gathers hardware event information *before* calling the cyclic
  function
* call the cyclic function (handling errors such as "function took too
  long")
* drives the actors that the function might manipulate (this would
  require a second parameter to ``check()``)

How
---

As it is not yet fully clear how this will have to look like, lets try
around a bit. Trying to rewrite the
``door_suite.straightforward_open`` test is a good start. Remove all
parts from the ``Door`` constructor, and pass the information into
``check()`` that ``check()`` currently gather on its own. (You'll
notice that the ``...Mock`` classes will not be needed anymore.)

From there, move forward by further modifying what's needed.

Testing
-------

This is a perfect candidate for test driven development. Every single
evolution step can be safeguarded with one or more tests.
