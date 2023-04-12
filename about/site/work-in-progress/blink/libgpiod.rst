.. include:: <mmlalias.txt>


``libgpiod`` Overview
=====================

.. contents::
   :local:

Character Device Based GPIO
---------------------------

* The way to go for GPIO on Linux
* Alternative: ``sysfs`` GPIO

  * Unmaintained
  * Not immune to hotplug GPIO (e.g. USB GPIO controller)
    |longrightarrow| fixed number range
  * Not reset when application crashes (a feature that is not wanted
    by most people)
  * No pullup/pulldown configuration

* ``RPi.GPIO``

  * Raspberry specific
  * Weird (a background thread fires event/interrupts)
  * Bound to go away (I hope)

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

GPIO Device
-----------

* ``/dev/gpiochip0``: character device
* Opened by processes
* Communication via ``ioctl()``
* Selectable |longrightarrow| events/interrupts
* User space library: ``libgpiod``

.. code-block:: console

   $ ls -l /dev/gpiochip0
   ls -l crw-rw---- 1 root gpio 254, 0 Apr  9 13:30 /dev/gpiochip0

Most Basic Feature: Setting Single GPIO Value
---------------------------------------------

* Request GPIO 11 (left upper corner)
* ... configuring for output

.. literalinclude:: code/gpio-set-11.py
   :caption: :download:`code/gpio-set-11.py`
   :language: python
  
Entire Matrix On/Off
--------------------

* Pull in from snippet: ``matrix``
* Join ``MATRIX`` lines using ``sum(MATRIX, ())``

.. literalinclude:: code/gpio-matrix-on-off.py
   :caption: :download:`code/gpio-matrix-on-off.py`
   :language: python

