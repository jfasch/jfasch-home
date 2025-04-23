.. include:: <mmlalias.txt>


Slides: systemd's D-Bus Implementation, And Its Python ``asyncio`` Binding
==========================================================================

.. contents::
   :local:

Show
----

.. sidebar::

   * jjjj https://dbus.freedesktop.org/doc/dbus-specification.html
   * `MPRIS D-Bus Interface Specification <https://specifications.freedesktop.org/mpris-spec/latest/>`__.

* How does Spotify react on ``Next/Prev`` buttons? |longrightarrow|
  D-Bus
* d-feet: Search for "spotify"; play/pause
* ``busctl`` (`man -s 7 busctl <https://man7.org/linux/man-pages/man1/busctl.1.html>`__)

  .. code-block:: console

     $ busctl --user tree
     $ busctl --user call org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player Pause

  .. code-block:: console

     $ busctl --system call org.freedesktop.login1 /org/freedesktop/login1 org.freedesktop.login1.Manager Suspend "b" 1

A Big Picture
-------------

* Picture jjj (one) bus, jjj picture two buses -> ``system and (user
  or session)``

Implementations
---------------

* Original/reference implementation (``libdbus``)
* Used in GNOME to interconnect apps (jjj link gi.gdbus)
* Used in systemd to interconnect components (jjj link sd-bus)



Can Add To It
-------------

jjj spotify binding

.. literalinclude:: notification-blocking.py
   :caption: :download:`notification-blocking.py`
   :language: python

Bindings
--------

Can add to it using language bindings. Here: jjj link sd-bus

* jjj notification synchronous, incl. a few words about ``sync``
  vs. ``async``

  https://python-sdbus-notifications.readthedocs.io/

* jjj sidebar

  * enter asyncio jjj 

* Short history, implementations, my usage reports (link to nody.py
  decorator something jjj). enter sd-bus.

* sd-bus

  * D-Bus implementation to interlink `systemd <https://systemd.io/>`__ components

    * incl. ``dbus-broker`` jjjjj

  * Python binding: `python-sdbus
    <https://python-sdbus.readthedocs.io/en/latest/>`__

    * Show links in sidebar  In realty, all is more complex

      * `dbus-broker <https://github.com/bus1/dbus-broker/wiki>`__
      * `python-sdbus
        <https://python-sdbus.readthedocs.io/en/latest/>`__
      * https://github.com/bus1/dbus-broker/wiki/Integration
      * https://lwn.net/Articles/967192/ ("``xz`` backdoor")

* python asyncio, blah single threaded blah jjj
 
  * jjj show async notification from above -> blah complicated
  * jjj show second task, printing out "hello" over and over
  * jjj show one that receives dbus signals (jjjj project jjj switch
    change notification -> ``async for``) and dbus notify on each (and
    prints "hello")

  * jjj sidebar

    * aiomqtt
    * aiohttp
    * python-sdbus/

Concrete Use Case: ``jf-irrigation``
------------------------------------

* Purely local irrigation system
* |longrightarrow| *adaptation* into D-Bus




Keep In Mind
------------

* D-Bus calls (method calls, signals, and property access) are
  *expensive*

  * |longrightarrow| jjj picture from earlier
  * ``low``, ``high``, sensor value, and switch state should better be
    exposed as D-Bus *struct* with those members
  * jjj hack that

  See ``DBusIrrigator`` jjj link vs. ``Irrigator`` (which even exposes
  Python objects) jjj link

* Local system knows nothing about ``async``. Events
  - like "switch state changed" - are usually modeled as *callbacks*.

  * No direct translation to D-Bus signals, at least not in async
    sd-bus: cannot asynchronously emit something onto D-Bus when
    caller is not async.
  * Solution: stay away from callbacks (better for software sanity
    anyway), but rather return data to be carried by signal. jjj show
    implementation of ``SwitchStateChanged`` signal.


 D-Bus *signals* are
  *events*, which are locally 

* All in all

  * D-Bus objects/interfaces should mimic local ones as much as
    possible
  * But no closer


* what else?

  * write own proxy jjj -> spotify proxy
  * show ``dbus-monitor``
