.. include:: <mmlalias.txt>


Talk Script: Python, asyncio, libgpiod, and Pointless Blinking
==============================================================

.. contents::
   :local:

``gpiod`` Intro
---------------

.. sidebar::

   ``blueprints/gpiod-demo.py``

* ``gpiod`` basics, ``Box``

   * Show center on/off
   * Quickly explain ``request_lines()`` (``request.set_value()``
     vs. ``request.set_values()``)
   * Show ``blink.glt2024.box``
   * Use ``Box.matrix``
   * insert ``snippets/blink``, and use it

``asyncio`` Intro
-----------------

* ``threading``

  * insert ``snippets/threads``
  * ``strace -f ...`` |longrightarrow| PIDs
  * Complain about threads

* Change to ``asyncio``
* ``strace -f ...`` again |longrightarrow| no PIDs

And ``blink``?
--------------

.. sidebar::

   ``blueprints/blink-demo.py``

* Explain ``on()``, ``sleep()``, ``any()``, ``forever()``
* Pull in snippet ``blueprints/snippet-nice-pattern``
* Ah, ``wait_button()``
* Revert to original blinking
* Enclose in ``any()``, limiting it to 3 secons

``gpiod``, And Interrupts
-------------------------

.. sidebar::

   ``blueprints/gpiod-interrupts.py``

* ``blink.base.sleep``: timer event
* Other events? |longrightarrow| interrupt on GPIO line
* Show ``blueprints/gpiod-interrupts.py``
* Discuss edges, timestamps, *bouncing*
* ``FALLING``, ``debounce_period``
* Transform into generator, ``events()``

Nice, Pythonic!

``gpiod``, Interrupts, and ``asyncio``
--------------------------------------

.. sidebar::

   ``blueprints/gpiod-interrupts.py``

* ``async def main()``; simply iterate over ``events()``
* |longrightarrow| works
* Second button, 19? Hm, tasks. 
* Wrap ``events()`` iteration in ``print_events()``
* Make ``print_events()`` ``async``
* In ``main()``, create two tasks around ``print_events()``
* |longrightarrow| one works, the other not

We block! Aha, ``async`` all over

* Question: how make ``events()`` async? *asynchronous generator*?
* Future, loops, blah

And ``blink``?
--------------

* Show ``wait_button``
* back in ``blink-demo.py``, replace ``sleep(3)`` with
  ``wait_button()``

``textual``
-----------

* My own stuff

  .. code-block:: console
  
     $ ./run-menu.py 

* Show https://pypi.org/project/textual-imageview/

  .. code-block:: console

     $ vimg ~/IMG<TAB>

``python-sdbus``
----------------

Start the server:

.. code-block:: console

   $ ./dbus-blink-server.py 

On another terminal, use ``busctl``

.. code-block:: console

   $ busctl --user list
   $ busctl --user introspect <TAB>
   $ busctl --user call ...
