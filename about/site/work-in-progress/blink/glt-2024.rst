GLT 2024 Submission: Pointless Blinking: Evolution
==================================================

Biography
---------

* Born in Graz, and bound to die in Graz
* Been around as an employee in and around Graz for many years
* Self employed as trainer and consultant for even more years
* https://www.faschingbauer.me

Abstract
--------

Continuing the :doc:`story of pointlessly blinking lights <glt-2023>`,
I add a number of features to the project. Add hardware buttons that
actually do something, add a `user interface (textual)
<https://textual.textualize.io/>`__ to "add value", and so on ...

Description
-----------

The :doc:`2023 talk <glt-2023>` focused much on Python's beauty (the
lovely :doc:`asyncio <python:library/asyncio>`, and decorators that
can be used creatively). In this year's edition I'll extend the
pointless project ...

* GPIO input, and debouncing hardware buttons with `libgpiod
  <https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git>`__
* A *very cool* user interface toolkit which is *terminal-only*:
  `textual <https://textual.textualize.io/>`__. It is completely
  *async*, and integrates perfectly with blinking. I'll use it to
  simulate lights that I cannot use when I'm on a train, to add cute
  UI controls, ...
