.. include:: <mmlalias.txt>


systemd's D-Bus Implementation, And Its Python ``asyncio`` Binding
==================================================================

.. .. Presentation
.. .. ------------
.. .. 
.. .. jjjjjjj
.. .. 
.. .. * Short D-Bus show (spotify button vs. cmd aus history) jjj
.. .. * Picture jjj (one) bus, jjj picture two buses -> ``system and (user
.. ..   or session)``
.. .. * 
.. .. 
.. ..   * show ``d-feet``
.. ..   * show ``dbus-monitor``
.. .. 
.. ..   Can add to it, eg.
.. .. 
.. ..   * jjj notification synchronous, incl. few words about ``sync``
.. ..     vs. ``async``
.. ..   * jjj sidebar
.. .. 
.. ..     * enter asyncio jjj 
.. .. 
.. ..   * jjj glt2025 structural refact
.. .. 

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

* Switch to jf-irrigation

* what else?

  * write own proxy jjj -> spotify proxy



D-Bus Show
..........

* Use case: spotify

  * Function keys play/pause (and next, prev)
  * |longrightarrow| how?
  * |longrightarrow| D-Bus

* d-feet

  * Search for "spotify"
  * Pause

* ``busctl`` (`man -s 7 busctl <https://man7.org/linux/man-pages/man1/busctl.1.html>`__)

  .. code-block:: console

     $ busctl --user tree
     $ busctl --user call org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player Pause

  .. code-block:: console

     $ busctl --system call org.freedesktop.login1 /org/freedesktop/login1 org.freedesktop.login1.Manager Suspend "b" 1

  See `MPRIS D-Bus Interface Specification <https://specifications.freedesktop.org/mpris-spec/latest/>`__.

* Monitoring/Debugging

  .. code-block:: console

     $ dbus-monitor --session

D-Bus Spec, Implementations
...........................

* What is D-Bus: Blah protocol and type system
  https://dbus.freedesktop.org/doc/dbus-specification.html

  jjj draw sketch jf-irrigation

* *Very* good D-Bus intro: `Poettering: The new sd-bus API of systemd
  <https://0pointer.net/blog/the-new-sd-bus-api-of-systemd.html>`__

* D-Bus reference implementation
  https://www.freedesktop.org/wiki/Software/dbus/

  * Python binding https://dbus.freedesktop.org/doc/dbus-python/
  * Really old and quirky, cannot remember

* Glib's D-Bus implementation

  * Source: https://gitlab.gnome.org/GNOME/glib
  * ``gdbus`` commandline tool,
    https://gnome.pages.gitlab.gnome.org/libsoup/gio/gdbus.html
  * Python binding https://github.com/LEW21/pydbus
  * Interfaces defined in XML, pretty weird. Show
    https://github.com/jfasch/openheating/blob/master/openheating/dbus/node.py

* SD-Bus jjj

  * https://www.freedesktop.org/software/systemd/man/latest/sd-bus.html
  * Python binding https://python-sdbus.readthedocs.io/en/latest/

* What else? bring this at the end

  * Errors:
    https://python-sdbus.readthedocs.io/en/latest/exceptions.html#list-of-error-exception
  * https://dbus.freedesktop.org/doc/dbus-specification.html

Client Implementation
.....................

* Bus name (service name): ``me.faschingbauer.IrrigationService``
* Object path: ``/me/faschingbauer/IrrigationSystem``
* Interface name: ``me.faschingbauer.IrrigationSystem``, as parameter
  of ``DBusIrrigationSystem`` (see
  https://github.com/jfasch/jf-irrigation/blob/main/src/irrigation/dbus/interfaces.py)

* Irrigation system

  * Simple: blocking operations

    * Structure/objects |longrightarrow| sketch

  * Challenge: expose objects via D-Bus. Continue irrigation in the
    "background" while serving D-Bus operations. *No-go*: create a
    thread.

* Read doc:
  https://python-sdbus.readthedocs.io/en/latest/examples.html

Gotchas, Weirdnesses
....................

* D-Bus methods (and properties) are always BiCapitalized; if you name
  a method ``some_method``, SDBus will translate it to ``SomeMethod``
* DBus socket is watched somehow magically. in ``main()``, I'd expect
  I have to create a task for DBus traffic - but no. Must be done
  magically inside some of the routines that we use to export object
  and register names.
* complain about confusion: busname, path, and iface name



What Else?
----------

Irrigation Outlook
..................

* Hardware, finally
* User interface with `textual <https://github.com/Textualize/textual>`__
* Add logging, error reporting, watchdog

More Information
................

* jjj collect links here, annotated and grouped

