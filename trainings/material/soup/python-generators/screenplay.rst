.. jf-screenplay:: python-generators

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

   **Code**: :doc:`code/index`

Fibonacci Numbers: Naive List
-----------------------------

.. literalinclude:: code/10-fibo-list-nolimit.py
   :caption: :download:`code/10-fibo-list-nolimit.py`
   :language: python

* watch OS become overly jerky, until process is OOM-killed
* well, there's need for a limit

Fibonacci Numbers: Naive List, Limited
--------------------------------------

.. literalinclude:: code/20-fibo-list-limit.py
   :caption: :download:`code/20-fibo-list-limit.py`
   :language: python

Sideway: Infinity by Not Using Functions
----------------------------------------

* Still not satisfactory
* Want infinity
* Can be done, by embedding the using code (``print()``) into the
  Fibonacci generation.
* not so modular though

.. literalinclude:: code/30-fibo-embedded-print.py
   :caption: :download:`code/30-fibo-embedded-print.py`
   :language: python

Fibonacci Numbers: Function Producing Infinite Sequence
-------------------------------------------------------

.. literalinclude:: code/40-fibo-generator.py
   :caption: :download:`code/40-fibo-generator.py`
   :language: python

Common Pattern: Turn List into Generated Items
----------------------------------------------

* correct infinity can save a few lines

.. literalinclude:: code/40-fibo-generator.py
   :language: python
   :diff: code/10-fibo-list-nolimit.py

