Nonsensical Blinking With Python, ``asyncio``, and ``libgpiod`` (and a Raspberry Pi of Course)
==============================================================================================

Focus of another pointless project of mine is to blink a configurable
set of programmable patterns on a number of LEDs. This might sound
like "hey, you are reinventing the wheel". I admit I do - I am a
notorious reinventer, and it is fun.

Lets reinvent LED blinking in a live-hacking session, and look into a
number of topics as we go:

* Python is a programming language that most of you know. It is simple
  and expressive, thus *fun*.
* Python's ``asyncio`` is a parallel programming technique, similar to
  multithreading in its usage, but fundamentally different in every
  other respect. At its core, it maps multiple parallel control flows
  onto one single event loop. Given that timers are events, this gives
  us the possiblity to run multiple LED blinking programs in one
  single thread - saving all the context switching and scheduling
  overhead that multithreaded program usually have. Smoother blinking
  patterns!
* Ah, blinking programs. Know what Python decorators are? Closures?
  We'll twist our brains to create a ``@program`` decorator,
  implemented as a triple-closure, and use that to write a number of
  amazingly simple blinking programs.
* Last not least, ``libgpiod``. The way to go for GPIO on Linux.
