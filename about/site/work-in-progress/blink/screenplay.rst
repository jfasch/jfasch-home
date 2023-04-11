Screenplay
==========

.. contents::
   :local:

Intro
-----

``libgpiod`` Overview
.....................

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

``asyncio`` Overview
....................

* :doc:`python:library/asyncio`
* ``asyncio.sleep()``

Livehacking
-----------

* Requesting (mention non-auto-reset fun)
* Cram into gpios.py
* Simple example: traverse-linear.py
* Start with asyncio

  * await sleep ...
  * Explain coroutine
  * Explain task

* blink-dumb.py, using stuff/program_dumb.py
* define blink, and cycle
* use in a simple loop
* matrix-like pattern. ndarray transpose
* loop? -> no reuse
* need way to recreate coro
* -> program

* blink-oo.py, using stuff/program_oo.py

  * maybe decrease intervals and/or loop counters
  * blinkfactory.create_coro()
  * manually chain together with cyclefactory
  * evolution: sequencefactory
  * evolution: loopfactory

* blink-wrap, program_wrap
* ... decorated
* all, any

* Taskgroups since 3.11


Afterword
---------

* ``libgpiod`` simu module
