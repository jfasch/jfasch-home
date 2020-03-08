Generators (Live Hacking Screenplay)
====================================

.. contents::
   :local:

Fibonacci Numbers: Naive List
-----------------------------

.. literalinclude:: generators-code/10-fibo-list-nolimit.py
   :caption: :download:`generators-code/10-fibo-list-nolimit.py`
   :language: python

* watch OS become overly jerky, until process is OOM-killed
* well, there's need for a limit

Fibonacci Numbers: Naive List, Limited
--------------------------------------

.. literalinclude:: generators-code/20-fibo-list-limit.py
   :caption: :download:`generators-code/20-fibo-list-limit.py`
   :language: python

Sideway: Infinity by Not Using Functions
----------------------------------------

* Still not satisfactory
* Want infinity
* Can be done, by embedding the using code (``print()``) into the
  Fibonacci generation.
* not so modular though

.. literalinclude:: generators-code/30-fibo-embedded-print.py
   :caption: :download:`generators-code/30-fibo-embedded-print.py`
   :language: python

Fibonacci Numbers: Function Producing Infinite Sequence
-------------------------------------------------------

.. literalinclude:: generators-code/40-fibo-generator.py
   :caption: :download:`generators-code/40-fibo-generator.py`
   :language: python

Common Pattern: Turn List into Generated Items
----------------------------------------------

* correct infinity can save a few lines

.. literalinclude:: generators-code/40-fibo-generator.py
   :language: python
   :diff: generators-code/10-fibo-list-nolimit.py

