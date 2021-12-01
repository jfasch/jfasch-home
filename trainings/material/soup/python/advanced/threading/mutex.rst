.. ot-topic:: python.advanced.threading.mutex
   :dependencies: python.advanced.threading.basics

.. include:: <mmlalias.txt>


Race Conditions, and Mutexes
============================

.. sidebar::

   **Contents**

   .. contents::
      :local:

   **Threading Documentation**

   :doc:`python:library/threading`

Mother of All Race conditions: Integer Increment
------------------------------------------------

.. literalinclude:: code/race-condition.py
   :caption: :download:`code/race-condition.py`

.. code-block:: console

   $ python code/race-condition.py
   final value: 14784035

|longrightarrow| *Load Modify Store Conflict*

Solution: Mutex (Explicit Acquire/Release)
------------------------------------------

* Mutex (for "MUTual EXclusion"), short: ``Lock``
* Best analogy: toilet door lock

.. literalinclude:: code/mutex.py
   :caption: :download:`code/mutex.py`

.. code-block:: console
   
   $ python code/mutex.py
   final value: 20000000

Solution: Mutex (``with`` Statement)
------------------------------------

* Calling ``lock.acquire()`` and ``lock.release()`` manually
* |longrightarrow| what if exception is raised in the middle? (Well,
  integer increments don't usually raise one; you get the point
  though.)

|longrightarrow| This is what the ``with`` statement is there fore
(``threading.Lock`` can act as a *context manager*)

.. literalinclude:: code/mutex-with.py
   :caption: :download:`code/mutex-with.py`

