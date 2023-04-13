Submission: Pointless Blinking With Python, ``asyncio``, and ``libgpiod`` (and a Raspberry Pi of Course)
========================================================================================================

Biography
---------

* Born in Graz, and bound to die in Graz
* Been around as an employee in and around Graz for many years
* Self employed as trainer and consultant for even more years
* https://www.faschingbauer.me

Abstract
--------

One of my more pointless projects is to blink a configurable set of
programmable patterns on a number of LEDs. This might sound like "hey,
you are reinventing the wheel". I admit I do - I am a notorious
reinventer, and it is fun.

Description
-----------

Lets reinvent LED blinking in a live-hacking session, and look into a
number of topics as we go:

* Python is a programming language that most of you know. It is simple
  and expressive, thus *fun*.
* Python's ``asyncio`` is a parallel programming technique, similar to
  multithreading in its usage, but fundamentally different in every
  other respect. At its core, it maps multiple parallel control flows
  onto one *single-threaded* event loop. Given that timers are events,
  this gives us the possiblity to run multiple LED blinking programs
  in one single thread - saving all the context switching and
  scheduling overhead that multithreaded programs usually
  exhibit. Blinking with less glitches caused by context switch
  hiccups!
* Ah, blinking patterns. Know what Python decorators are? Closures?
  We'll twist our brains and create a ``@program`` decorator,
  implemented as a triple-closure, and use that to write a number of
  amazingly simple blinking programs. Almost like functional
  programming.
* Last not least, ``libgpiod``. The way to go for GPIO on Linux.
