.. include:: <mmlalias.txt>


GLT 2025: systemd's D-Bus Implementation, And Its Python ``asyncio`` Binding
============================================================================

.. contents::
   :local:

.. toctree::

   submission
   talk/index

Links
-----

* `man sd-bus
  <https://www.freedesktop.org/software/systemd/man/latest/sd-bus.html>`__

Todo
----

* D-Bus signals: errors (toplevel exception handling at server side -
  taskgroup?)

  * "SMS service" |longrightarrow| ``async for``
