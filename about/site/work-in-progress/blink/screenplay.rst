.. include:: <mmlalias.txt>


Screenplay: Pointless Blinking With Python, ``asyncio``, and ``libgpiod`` (and a Raspberry Pi of Course)
========================================================================================================

.. contents::
   :local:

Setup Before Presentation
-------------------------

* Download :download:`code/thread-multi.py` as ``blink.py``, and
  ``chmod +x``
* Download :download:`code/gpio-multi.py` as ``gpio.py``, and ``chmod
  +x``
* Download :download:`code/off.py` as ``off.py``, and ``chmod +x``
* Download :download:`snippets/set_values` into ``snippets``
* Download :download:`snippets/blink-raw` into ``snippets``

Multiple Background Threads
---------------------------

.. sidebar::

   **Editor**

   * ``blink.py``

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
* Fourth (main thread) also involved occasionally, likely due to
  Python's weird thread management (GIL)
* Managed by OS scheduler
* |longrightarrow| scheduling jitter, heavy (?) OS load

**Blink**

.. literalinclude:: code/thread-multi.py
   :caption: :download:`code/thread-multi.py`
   :language: python

Enter ``asyncio``
-----------------

* Replace ``threading`` and ``time`` with ``asyncio``
* ``async`` functions, ``await asyncio.sleep(...)``
* ``async def main()``
* ``asyncio.run(main())``

.. code-block:: console

   $ strace -f code/async-multi.py
   ...
   epoll_wait(3, [], 1, 201)               = 0
   ...

* *Single thread!*
* Timeouts apparently multiplexed on the *event loop's* timeout
  parameter

**Blink**

.. literalinclude:: code/async-multi.py
   :caption: :download:`code/async-multi.py`
   :language: python

Character Device Based GPIO
---------------------------

.. sidebar::

   **Editor**

   * ``gpio.py``

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

Most Basic Feature: Setting GPIO Values
---------------------------------------

* Request GPIO 11, 10, 27
* ... configuring for output

.. literalinclude:: code/gpio-multi.py
   :caption: :download:`code/gpio-multi.py`
   :language: python
  
Entire Matrix On/Off
--------------------

.. sidebar::

   **Editor**

   * ``gpio.py``

   **Snippets**

   * ``matrix``

   **Steps**

   * Dictionary comprehension ``set_values()``
   * Use ``ALL_IOS``

**GPIO**

.. literalinclude:: code/gpio-matrix-on-off.py
   :caption: :download:`code/gpio-matrix-on-off.py`
   :language: python

Bringing All Together
---------------------

.. sidebar::

   **Editor**

   * ``blink.py``

   **Snippets**

   * ``set_values``
   * ``blink-raw``

   **Steps**

   * Transform ``print()`` to ``blink()`` according to table
   * No ``ntimes``
   * List of tasks

* Continue ``blink.py``
* Morph ``hello*()`` in ``blink(ios, interval, ntimes=None)``
  (``None`` -> ``itertools.count()``, else ``range()``)
* ``import gpiod``, next to ``asyncio``
* Pull in snippet ``set_values``
* Pull in snippet ``blink-raw``

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * GPIO
     * Interval
   * * 11
     * 0.5
   * * 10
     * 0.4
   * * 27
     * 0.3
   * * 4
     * 0.2
   * * 2
     * 0.1

**Blink**

.. literalinclude:: code/blink-multi-raw.py
   :caption: :download:`code/blink-multi-raw.py`
   :language: python

Modularize
----------

.. sidebar::

   **Editor**

   * ``blink.py``
   * ``stuff.py``

   **Steps**

   * Externalize stuff into ``stuff.py``

* Note this is not about clean coding |:pig:|
* Cram stuff into ``stuff.py``
* All but ``main()`` goes there


**Stuff**

.. literalinclude:: code/stuff_raw.py
   :caption: :download:`code/stuff_raw.py`
   :language: python

**Blink**

.. literalinclude:: code/blink-multi-raw-mod.py
   :caption: :download:`code/blink-multi-raw-mod.py`
   :language: python

Play A Bit: Blink Entire Rows
-----------------------------

.. sidebar::

   **Steps**

   * ``rows = MATRIX``
   * Blink rows

* Five tasks, one for each row
* Make list of tasks

**Blink**

.. literalinclude:: code/blink-rows-raw.py
   :caption: :download:`code/blink-rows-raw.py`
   :language: python

* Sideway, maybe: blink columns
* |longrightarrow| ``numpy.transpose()``
* I like heavy dependencies |:pig:|

**Blink**

.. literalinclude:: code/blink-cols-raw.py
   :caption: :download:`code/blink-cols-raw.py`
   :language: python

Coroutines?
-----------

.. sidebar::

   **Steps**

   * Omit ``create_task()`` |longrightarrow| coroutines
   * Show ``blink()`` in interactive interpreter (``await`` outside
     function? |longrightarrow| ``run()``)

* Hm ... too much of ``asyncio.create_task()`` here
* Instantiate coroutines first, not using ``create-task()``
  immediately

  * Coroutines do nothing
  * ``await``, or ``create_task()``

* Pass to ``all()`` (pull in from snippet ``all-initial``)
* ``await`` that instead

**Blink**

.. literalinclude:: code/blink-cols-coro.py
   :caption: :download:`code/blink-cols-coro.py`
   :language: python

Not Enough: ``sequence()``
--------------------------

* Not using ``create_task()``: sequential execution
* Pass a limit to ``blink()``
* |longrightarrow| another one: ``sequence()``

.. literalinclude:: code/blink-sequence.py
   :caption: :download:`code/blink-sequence.py`
   :language: python

* Pull ``all()`` and ``sequence()`` out into ``stuff.py`` when done
* :download:`code/blink-sequence-clean.py`

Looping: ``forever()``
----------------------

.. sidebar::

   **Steps**

   * Cannot re-use coroutine
   * |longrightarrow| **re-instantiate!**

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

.. sidebar::

   **Steps**

   * Strip down program to bare minimum

.. literalinclude:: code/blink-factory-start.py
   :caption: :download:`code/blink-factory-start.py`
   :language: python

Turn ``blink()`` Into A Factory
-------------------------------

.. sidebar::

   **Steps**

   * ``class blink``
   * Method ``create_coro()``
   * Call in ``forever()``

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

.. code-block:: python

   def create_factory_for_blink(blinkfunc):
       def factory(ios, interval, ntimes=None):
           def create_coro():
               return blinkfunc(ios, interval, ntimes)
           return create_coro
       return factory

.. sidebar::

   **Steps**

   * ``create_factory_for_blink()``
   * Replace: ``blink = create_factory_for_blink(blink)``

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

   **Steps**

   * Use starargs
   * Rename ``blinkfunc`` to ``func``
   * Rename ``create_factory_for_blink`` to ``program``
   * Decorate both ``blink()`` and ``forever()``
   * Move both (back) into ``stuff.py``
   * Decorate the others (and let them start programs by calling them)
   * ``main()`` becomes obsolete: just call ``prog()``

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/python/advanced/starargs/topic`
   * :doc:`/trainings/material/soup/python/advanced/closures/topic`
   * :doc:`/trainings/material/soup/python/advanced/decorators/topic`


**Stuff**

.. literalinclude:: code/stuff_decorator_stage1.py
   :caption: :download:`code/stuff_decorator_stage1.py`
   :language: python

**Blink**

.. literalinclude:: code/blink-decorator-stage1.py
   :caption: :download:`code/blink-decorator-stage1.py`
   :language: python

Playground: ``cycle()``
-----------------------

.. sidebar::

   **Snippets**

   * ``cycle`` into ``stuff.py``
   * ``squares`` into ``stuff.py``

   **Steps**

   * cycle one row
   * cycle all rows
   * cycle squares
   * ...

.. literalinclude:: snippets/cycle
   :caption: :download:`snippets/cycle`
   :language: python

* Cycle ``row[0]``
* |longrightarrow| **A-HA!!**

Playground: ``any()``
---------------------

.. sidebar::

   **Snippets**

   * ``stuff-complete``, replacing ``stuff.py`` content
   * ``prog-any-demo``

* Show ``stuff.any()``
* ``blink.py``: insert ``prog-any-demo``

Playground: ``on()``
--------------------

.. sidebar::

   **Snippets**

   * ``prog-any-on-demo``
   * ``prog-my-blink``

* Show ``stuff.on()``
* Explain ``Future``
* ``blink.py``: insert ``prog-any-on-demo``
* ``blink.py``: insert ``prog-my-blink``

Goodbye
-------

.. sidebar::

   **Snippets**

   * ``prog-smiley``

* ``blink.py``: insert ``prog-smiley``
