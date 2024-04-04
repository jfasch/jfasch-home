.. include:: <mmlalias.txt>


Talk Sketch: Pointless Blinking: Evolution
==========================================

``asyncio`` Intro
-----------------

.. sidebar::

   ``blueprints/async-demo.py``

* ``strace -f ...`` |longrightarrow| PIDs
* Complain about threads
* Change to ``asyncio``
* ``strace -f ...`` again

``gpiod`` Intro
---------------

.. sidebar::

   ``blueprints/gpiod-demo.py``

* Show center on/off
* Quickly explain ``request_lines()`` (``request.set_value()``
  vs. ``request.set_values()``)
* Show ``blink.glt2024.box``
* Use ``Box.matrix``

* Copy one of the ``hello...()`` coroutines fom ``async-demo.py``
* Morph it into something like below
* Call it three times

  .. code-block:: python

     async def blink(output, interval):
       try:
           for _ in range(10):
               output.set(True)
               await asyncio.sleep(interval)
               output.set(False)
               await asyncio.sleep(interval)
       finally:
           output.set(False)

And ``blink``?
--------------

.. sidebar::

   ``blueprints/blink-demo.py``

* Explain ``on`` |longrightarrow| ``asyncio.create_future()``
* ``sleep``
* Combine through ``any`` |longrightarrow| ``launch_isolated``
* ``forever`` and ``sequence`` |longrightarrow| ``blink``

.. code-block:: python

   forever(
       sequence(
           any(
	       on(box.matrix.get(2,2)),
               sleep(0.5),
           ),
           sleep(0.5),
       )
   )

* Pull in snippet ``blueprints/snippet-nice-pattern``

``gpiod``, And Interrupts
-------------------------

.. sidebar::

   ``blueprints/gpiod-interrupts.py``

* ``blink.base.sleep``: timer event
* Other events? |longrightarrow| interrupt on GPIO line
* Show ``blueprints/gpiod-interrupts.py``
* Discuss edges, timestamps, *bouncing*
* ``FALLING``, ``debounce_period``
* Transform into generator

Nice, Pythonic!

``gpiod``, Interrupts, and ``asyncio``
--------------------------------------





* blocking -> ``bin/watch-input-blocking.py``
* transform to ``bin/watch-input-async.py``
* build one-shot device

  * ``io.Input.wait()``

* bring that into an ``@program``. standalone program, ``any(on(),
  wait_button())``

``textual``
-----------

* Show https://pypi.org/project/textual-imageview/

Python 3.12 Installation (for ``TaskGroup``)
--------------------------------------------

.. code-block:: console

   $ sudo apt install libssl-dev libreadline-dev libffi-dev libsystemd-dev python3-dev
   $ wget https://www.python.org/ftp/python/3.12.2/Python-3.12.2.tar.xz
   $ tar xf Python-3.12.2.tar.xz 
   $ cd Python-3.12.2/
   $ ./configure --prefix=$HOME/Python-3.12.2-Install --with-readline
   $ make
   $ make install


