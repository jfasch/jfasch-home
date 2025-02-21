GLT 2025
========

.. contents::
   :local:

Submission
----------

systemd's D-Bus Implementation, And Its Python ``asyncio`` Binding
..................................................................

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
I'll try to explain, however hard that may be.

Talk Concept
------------

* incoming AF_UNIX dgrams

  imagine other data sources ...

  * CAN socket jjj link
  * GPIO interrupt
  * any kind of events

* event loop programming

  asyncio intro: add second incoming-socket -> second task ->
  strace -f

* dbus server

  * method: get incoming (list, because multiple) -> setup graph
  * setup chart plot
  * animation?

* hmm

  * Example from python-sdbus
  * Project
  
    * gpiod interrupt, and asyncio
    * dbus server emits sdbus signal
    * dbus client iterates over it in a task

Links
-----

* `Poettering: The new sd-bus API of systemd
  <https://0pointer.net/blog/the-new-sd-bus-api-of-systemd.html>`__
* `man sd-bus
  <https://www.freedesktop.org/software/systemd/man/latest/sd-bus.html>`__
