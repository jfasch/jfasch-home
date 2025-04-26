GLT 2025 Submission: systemd's D-Bus Implementation, And Its Python ``asyncio`` Binding
=======================================================================================

.. sidebar:: Grazer Linuxtage

   * `Grazer Linuxtage <https://www.linuxtage.at/de/>`__
   * `Programm GLT 2025 <https://pretalx.linuxtage.at/glt25/>`__
   * `This talk on GLT 2025
     <https://pretalx.linuxtage.at/glt25/talk/38MNWT/>`__

.. sidebar:: Talk notes

   * :doc:`talk/index`

Abstract
````````

An overview of D-Bus, systemd, and systemd's own D-Bus implementation,
`sd-bus
<https://0pointer.net/blog/the-new-sd-bus-api-of-systemd.html>`__. Less
slide show, more live coding in Python and `asyncio
<https://docs.python.org/3/library/asyncio.html>`__.

Description
```````````

D-Bus is a broker-based interprocess communication mechanism which has
been used for ages in Linux's desktop environments like `GNOME
<https://www.gnome.org/>`__ or `KDE <https://kde.org/>`__.

`systemd <https://systemd.io/>`__, the Linux init system and service
manager, likewise consists of many loosely coupled components. Since
systemd's inception, likewise, its components are using D-Bus to
communicate.

Over time, the systemd developers have become uncomfortable with the
existing D-Bus implementation they were using. They created another
implementation, `sd-bus
<https://0pointer.net/blog/the-new-sd-bus-api-of-systemd.html>`__,
tailored towards systemd's needs - minimal and fast.

This talk gives an overview of D-Bus and its concepts, and then shows
how sd-bus is used to implement one's own interfaces and
components. Out of its many language bindings, we will use Python to
implement a use case, just to show how simple this is.

You will probably like the use of `asyncio
<https://docs.python.org/3/library/asyncio.html>`__ in the talk. For
those of you who don't know what this is and what problems it solves,
I'll try to explain, however hard that may be. If you are interested:
my last year's talk `Python, asyncio, libgpiod, and Pointless Blinking
<https://media.ccc.de/v/glt24-435-python-asyncio-libgpiod-and-pointless-blinking>`__
contains a deeper asyncio introduction.

