Screenplay
==========

.. contents::
   :local:

   asyncio
   libgpiod

Multiple Background Threads
---------------------------

* Start with :download:`code/thread-multi.py`

  * 0.5s ``"hello left"``
  * 0.8s ``"hello right"`` (``str.rjust(60)``)
  * 1s ``"hello middle"`` (``str.center(60)``)

.. literalinclude:: code/thread-multi.py
   :caption: :download:`code/thread-multi.py`
   :language: python

.. code-block:: console

   $ strace -f python3 code/thread-multi.py
   ...
   [pid  4677] write(1, "hello left\n", 11hello left
   ) = 11
   [pid  4677] clock_gettime64(CLOCK_MONOTONIC, {tv_sec=164646, tv_nsec=833862215}) = 0
   [pid  4677] _newselect(0, NULL, NULL, NULL, {tv_sec=0, tv_usec=500000} <unfinished ...>
   [pid  4679] <... _newselect resumed>)   = 0 (Timeout)
   [pid  4679] write(1, "                        hello mi"..., 61                        hello middle                        
   ) = 61
   [pid  4679] clock_gettime64(CLOCK_MONOTONIC, {tv_sec=164646, tv_nsec=845864201}) = 0
   [pid  4679] _newselect(0, NULL, NULL, NULL, {tv_sec=1, tv_usec=0} <unfinished ...>
   [pid  4678] <... _newselect resumed>)   = 0 (Timeout)
   [pid  4678] write(1, "                                "..., 61                                                 hello right
   ) = 61

* Three independent PIDs, using ``select()`` to implement
  ``time.sleep()`` (``NULL`` fds)
* Managed by OS scheduler
* |longrightarrow| scheduling jitter, heavy (?) OS load

Enter ``asyncio``
-----------------

* Replace ``threading`` and ``time`` with ``asyncio``
* ``async`` functions, ``await asyncio.sleep(...)``
* ``async def main()``
* ``asyncio.run(main())``

.. literalinclude:: code/async-multi.py
   :caption: :download:`code/async-multi.py`
   :language: python

.. code-block:: console

   $ strace -f code/async-multi.py
   ...
   epoll_wait(3, [], 1, 201)               = 0
   ...

* *Single thread!*
* Timeouts apparently multiplexed on the *event loop's* timeout
  parameter

Character Device Based GPIO
---------------------------

* The way to go for GPIO on Linux
* Alternative: ``sysfs`` GPIO

  * Unmaintained
  * Not immune to hotplug GPIO (e.g. USB GPIO controller)
    |longrightarrow| fixed number range
  * Not reset when application crashes (a feature that is not wanted
    by most people)
  * No pullup/pulldown configuration

* ``RPi.GPIO``

  * Raspberry specific
  * Weird (a background thread fires event/interrupts)
  * Bound to go away (I hope)

`Libgpiod V2: New Major Release with a Ton of New Features - Bartosz
Golaszewski <https://youtu.be/6fxcDDLII6Y>`__
  
.. raw:: html

   <iframe
       width="560" height="315" 
	 src="https://www.youtube.com/embed/6fxcDDLII6Y" 
	 title="YouTube video player" 
	 frameborder="0" 
	 allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	 allowfullscreen>
   </iframe>

GPIO Device
-----------

* ``/dev/gpiochip0``: character device
* Opened by processes
* Communication via ``ioctl()``
* Selectable |longrightarrow| events/interrupts
* User space library: ``libgpiod``

.. code-block:: console

   $ ls -l /dev/gpiochip0
   ls -l crw-rw---- 1 root gpio 254, 0 Apr  9 13:30 /dev/gpiochip0

Most Basic Feature: Setting Single GPIO Value
---------------------------------------------

* Request GPIO 11 (left upper corner)
* ... configuring for output

.. literalinclude:: code/gpio-set-11.py
   :caption: :download:`code/code/gpio-set-11.py`
   :language: python
  
Entire Matrix On/Off
--------------------

* Pull in from snippet: ``matrix``
* Join ``MATRIX`` lines using ``sum(MATRIX, ())``

.. literalinclude:: code/gpio-matrix-on-off.py
   :caption: :download:`code/gpio-matrix-on-off.py`
   :language: python

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
* :download:`blink-sequence-clean.py

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

* ``class blink``, with a ``__init__`` just like original ``blink()``
  function
* Stores ctor parameters as members
* One single method: ``create_coro(self)``

  * Creates nested function ``_blink(ios, interval, ntimes)``
  * Returns instantiated coroutine from it

* ``forever()`` gets passed ``factory``, and calls
  ``factory.create_coro()`` in every iteration
* |longrightarrow| done
* |longrightarrow| except: clumsy

.. literalinclude:: code/blink-factory.py
   :caption: :download:`code/blink-factory.py`
   :language: python

Anti-Clumsy Decorator: ``blink()`` Wrapper
------------------------------------------

* Factory is much writing
* Closures are objects

  * "Members" are *in the closure*
  * One *method*: the function
  * |longrightarrow| inverted view

* Start with ``create_factory_for_blink(blink_func)``

  * |longrightarrow| hardwired parameters: ``ios, interval, ntimes``

  .. code-block:: python
  
     def create_factory_for_blink(blinkfunc):
         def factory(ios, interval, ntimes=None):
             def create_coro():
                 return blinkfunc(ios, interval, ntimes)
             return create_coro
         return factory

  * Wrap manually

  .. code-block:: python

     blink = create_factory_for_blink(blink)

**Stuff**

.. literalinclude:: code/stuff_decorator_stage1.py
   :caption: :download:`code/stuff_decorator_stage1.py`
   :language: python

**Blink**

.. literalinclude:: code/blink-decorator-stage1.py
   :caption: :download:`code/blink-decorator-stage1.py`
   :language: python

``@program``, Finally
---------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/python/advanced/starargs/topic`
   * :doc:`/trainings/material/soup/python/advanced/closures/topic`
   * :doc:`/trainings/material/soup/python/advanced/decorators/topic`

* Use starargs
* Rename ``blinkfunc`` to ``func``
* Rename ``create_factory_for_blink`` to ``program``
* Decorate both ``blink()`` and ``forever()``
* Move both (back) into ``stuff.py``
* Decorate the others (and let them start programs by calling them)
* ``main()`` becomes obsolete: just call ``prog()``

**Stuff**

.. literalinclude:: code/stuff_decorator_stage1.py
   :caption: :download:`code/stuff_decorator_stage1.py`
   :language: python

**Blink**

.. literalinclude:: code/blink-decorator-stage1.py
   :caption: :download:`code/blink-decorator-stage1.py`
   :language: python
