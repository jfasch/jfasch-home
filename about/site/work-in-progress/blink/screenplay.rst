.. include:: <mmlalias.txt>


Screenplay: Pointless Blinking With Python, ``asyncio``, and ``libgpiod`` (and a Raspberry Pi of Course)
========================================================================================================

.. contents::
   :local:

.. toctree::
   
   asyncio
   libgpiod

Bringing All Together
---------------------

* Continue ``code/async-multi.py``
* Morph ``hello*()`` in ``blink(ios, interval, ntimes=None)``
  (``None`` -> ``itertools.count()``, else ``range()``)
* ``import gpiod``, next to ``asyncio``
* Pull in snippet ``set_values``
* Pull in snippet ``blink-raw``
* ``left`` -> 11
* ``middle`` -> 10
* ``right`` -> 27

.. literalinclude:: code/blink-multi-raw.py
   :caption: :download:`code/blink-multi-raw.py`
   :language: python

Modularize
----------

* Note this is not about clean coding |:pig:|
* Cram stuff into ``stuff.py``
* All but ``main()`` goes there

.. literalinclude:: code/stuff_raw.py
   :caption: :download:`code/stuff_raw.py`
   :language: python

.. literalinclude:: code/blink-multi-raw-mod.py
   :caption: :download:`code/blink-multi-raw-mod.py`
   :language: python

Play A Bit: Blink Entire Rows
-----------------------------

* Five tasks, one for each row
* Make list of tasks

.. literalinclude:: code/blink-rows-raw.py
   :caption: :download:`code/blink-rows-raw.py`
   :language: python

* Sideway, maybe: blink columns
* |longrightarrow| ``numpy.transpose()``
* I like heavy dependencies |:pig:|

.. literalinclude:: code/blink-cols-raw.py
   :caption: :download:`code/blink-cols-raw.py`
   :language: python

Coroutines?
-----------

* Hm ... too much of ``asyncio.create_task()`` here
* Instantiate coroutines first, not using ``create-task()``
  immediately

  * Coroutines do nothing
  * ``await``, or ``create_task()``

* Pass to ``all()`` (pull in from snippet ``all-initial``)
* ``await`` that instead

.. literalinclude:: code/blink-cols-coro.py
   :caption: :download:`code/blink-cols-coro.py`
   :language: python

Not Enough: ``sequence()``
--------------------------

* Pass a limit to ``blink()``
* |longrightarrow| sequential execution
* |longrightarrow| another one: ``sequence()``

.. literalinclude:: code/blink-sequence.py
   :caption: :download:`code/blink-sequence.py`
   :language: python

* Pull ``all()`` and ``sequence()`` out into ``stuff.py`` when done
* :download:`code/blink-sequence-clean.py`

Looping: ``forever()``
----------------------

.. literalinclude:: code/blink-forever.py
   :caption: :download:`code/blink-forever.py`
   :language: python

.. code-block:: console

   $ code/blink-forever.py
   ...
   RuntimeError: cannot reuse already awaited coroutine
   ...

* Need to *create* new coroutine at each execution
* |longrightarrow| factory?

A Stripped-Down Program (|longrightarrow| Factory)
--------------------------------------------------

* Strip down program to bare minimum
* Overwriting ``blink()``, ``forever()`` in main (still need
  ``stuff.py`` for intialization)

.. literalinclude:: code/blink-factory-start.py
   :caption: :download:`code/blink-factory-start.py`
   :language: python

Turn ``blink()`` Into A Factory
-------------------------------

* ``blink``: stores parameters for ``_blink()`` (the real one)
* ``blink.create_coro()`` creates ``_blink()`` (nested function,
  unchanged from original ``blink()``)
* ``forever()`` gets passed ``factory``, and calls
  ``factory.create_coro()`` in every iteration
* |longrightarrow| done
* |longrightarrow| except: clumsy

.. literalinclude:: code/blink-factory.py
   :caption: :download:`code/blink-factory.py`
   :language: python

Anti-Clumsy Decorator: ``@program``
-----------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/python/advanced/starargs/topic`
   * :doc:`/trainings/material/soup/python/advanced/closures/topic`
   * :doc:`/trainings/material/soup/python/advanced/decorators/topic`

* Factory is much writing
* Closures are objects

  * "Members" are *in the closure*
  * One *method*: the function
  * |longrightarrow| inverted view

* Decorator creates factory
* Factory creates coroutine (the 

