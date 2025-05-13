Yocto Kernel Bringup on Customer Hardware
=========================================

.. contents:: 
   :local:

Goal
----

* With the outcome of :doc:`kernel-upgrade-dirty`, move to the
  customer hardware.
* Loop until everything works like before.
* Important: don't forget about firmware download

Open Questions: Everything Works Like Before?
---------------------------------------------

* **Current Audio Situation**. I2C communication works with the
  current Debian kernel.

  * Verify that it still works.
  * *How?*

* **Graphics situation**. They plug two monitors (one being 4K
  occasionally?).

  In my experience the dual monitor setup - as easy as it may seem in
  a normal work environment with a, say, `GNOME Desktop
  <https://www.gnome.org/>`__ - is not as easy when an appliance
  places windows automatically. It gets even worse when there is no
  desktop environment.

  * `X11 or Wayland <https://wiki.debian.org/Wayland>`__?
  * Benchmarking (``glxgears`` and related)? See `here
    <https://www.howtoforge.com/tutorial/linux-gpu-benchmark/>`__.

* **Other hardware/driver problems {ex|sus}pected?**
