.. meta::
   :description: This live-hacking screenplay is a guide for myself to
                 repeatably, didactically, demonstrate what Python
                 generators are
   :keywords: python, schulung, training, programming

Screenplay: Python: Generators
==============================

.. sidebar:: Contents

   .. contents::
      :local:

   **Code**: :doc:`python-generators-code/index`

Fibonacci Numbers: Naive List
-----------------------------

.. literalinclude:: python-generators-code/10-fibo-list-nolimit.py
   :caption: :download:`python-generators-code/10-fibo-list-nolimit.py`
   :language: python

* watch OS become overly jerky, until process is OOM-killed
* well, there's need for a limit

Fibonacci Numbers: Naive List, Limited
--------------------------------------

.. literalinclude:: python-generators-code/20-fibo-list-limit.py
   :caption: :download:`python-generators-code/20-fibo-list-limit.py`
   :language: python

Sideway: Infinity by Not Using Functions
----------------------------------------

* Still not satisfactory
* Want infinity
* Can be done, by embedding the using code (``print()``) into the
  Fibonacci generation.
* not so modular though

.. literalinclude:: python-generators-code/30-fibo-embedded-print.py
   :caption: :download:`python-generators-code/30-fibo-embedded-print.py`
   :language: python

Fibonacci Numbers: Function Producing Infinite Sequence
-------------------------------------------------------

.. literalinclude:: python-generators-code/40-fibo-generator.py
   :caption: :download:`python-generators-code/40-fibo-generator.py`
   :language: python

Common Pattern: Turn List into Generated Items
----------------------------------------------

* correct infinity can save a few lines

.. literalinclude:: python-generators-code/40-fibo-generator.py
   :language: python
   :diff: python-generators-code/10-fibo-list-nolimit.py

