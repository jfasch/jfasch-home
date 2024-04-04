GLT 2024 Submission: Python, asyncio, libgpiod, and Pointless Blinking
======================================================================

Biography
---------

* Born in Graz, and bound to die in Graz
* Been around as an employee in and around Graz for many years
* Self employed as trainer and consultant for even more years
* https://www.faschingbauer.me

Abstract
--------

Python's lovely :doc:`asyncio <python:library/asyncio>` library allows
me to write event-driven programs in a style that looks much like
multithreaded code but isn't. Combining :doc:`asyncio
<python:library/asyncio>` with the equally lovely `Linux GPIO
subsystem
<https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git>`__ is just
another logical step. In this talk I show what :doc:`asyncio
<python:library/asyncio>` is, how `libgpiod
<https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git>`__ works,
and how both are used to do pointless projects.

Description
-----------

Continuing the :doc:`story of pointlessly blinking lights
<../glt2023/index>` from my last year's talk, I show

* How GPIO interrupts are configured to get notified of hardware
  button presses, and how this can look like in Python (hint:
  *generators*, and *iteration*).
* How button-events can be used in an ``async`` programming style.
* How this fits into the pointless project of blinking lights.

Additionally, I give an overview of async libraries that are more to
the point, like

* `Textual <https://textual.textualize.io>`__, a terminal UI framework
* `python-sdbus <https://github.com/python-sdbus/python-sdbus>`__, the
  Python binding for the systemd D-Bus client implementation
