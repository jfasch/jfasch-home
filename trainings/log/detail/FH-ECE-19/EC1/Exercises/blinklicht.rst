.. include:: <mmlalias.txt>

.. ot-exercise:: ece19.blinklicht
   :dependencies: ece19.file_read

GPIO: Blinklicht
================

.. contents:: 
   :local:

Write a *Python* program that uses one of the Raspberry GPIO pins to
blink an LED at a given frequency. The program will be invoked like
so:

.. code-block:: console

   $ path/to/repo/root/exercises/lastname.firstname/blink 25 0.5

Commandline
-----------

The command takes two *positional* parameters,

#. GPIO number
#. Frequency, in seconds. The number can contain decimal points, and
   so can represent fractions of a second.

Use the ``argparse`` module to do the commandline stuff

* Documentation `here
  <https://docs.python.org/3/library/argparse.html#module-argparse>`__)
* Sample usage in the `checker program
  <https://github.com/jfasch/FH-ECE-19/blob/master/bin/checker-digit>`__
  I keep annoying students with.

``sysfs`` GPIO
--------------

The program uses ``sysfs`` GPIO, and *not* `RPi.GPIO
<https://pypi.org/project/RPi.GPIO/>`__. 

.. note::

   * RPi.GPIO is Raspberry specific. This means it won't work on any
     other Linux than the Raspberry's.
   * RPi.GPIO is Python specific. One cannot easily port prototype
     code to, say, C++.
   * RPi.GPIO is horrible; it accesses hardware registers directly.

* `Kernel documentation
  <https://www.kernel.org/doc/html/latest/admin-guide/gpio/sysfs.html>`__
* `Youtube tutorial (one of many)
  <https://www.youtube.com/watch?v=Si1R2gaqE64>`__. This shows how to
  uses ``sysfs`` GPIO in the shell. *Note* that we are writing a
  Python program, though.

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/Si1R2gaqE64" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* Distilled, what we want to do (in Python) is this ...

  .. code-block:: console
  
     $ cd /sys/class/gpio
     $ echo 25 > export
     $ cat gpio25/direction
     in
     $ echo out > gpio25/direction
     $ cat gpio25/value
     0
     $ echo 1 > gpio25/value    # see if it works
     $  # now for real
     $ i=0
     $ while true; do
     >   echo $((i%2)) > gpio25/value
     >   i=$((i+1))
     >   sleep 0.5
     > done

* The new kid, `libgpiod
  <https://blog.adafruit.com/2018/11/26/sysfs-is-dead-long-live-libgpiod-libgpiod-for-linux-circuitpython/>`__
  solves many of the problems that Sysfs GPIO has. Will switch to that
  when time is right (after we learned what *encapsulation* is).

Electronic Aspect
-----------------

External Circuitry
..................

Well, this is embarassing ...

.. image:: files/gpio25led.png
   :scale: 30%

Raspberry Header Pinout
.......................

.. figure:: GPIO-Pinout-Diagram-2.png

Implementation Notes
--------------------

* After exporting the GPIO (``echo 25 > export``), the directory
  ``gpio25`` and the files it contains are not *immediately*
  visible. Rather, the operation completes *asynchronously*. This
  means that you have to *wait* between the export and the
  access. 1/10 second should be sufficient.

  You do this using ``time.sleep()``. Read the documentation of it.
* A starting point, regarding the "Use ``argparse`` for commandline
  parsing" can be found `here
  <https://github.com/jfasch/FH-ECE-19/blob/master/exercises/faschingbauer.joerg/blink>`__.
* Write the program locally, on your PC, using VS Code (or whatever is
  your favorite editor).

  * *WinSCP*. You can use `WinSCP
    <https://winscp.net/eng/download.php>`__ to transfer the program
    to the Raspberry. Be aware though that the execute permission
    might not be transferred correctly - Windows and Unix are
    different.
  * VS Code, There is also a VS Code extension, `Remote SSH
    <https://code.visualstudio.com/docs/remote/ssh>`__, that you might
    want to try.


Dependencies
------------

.. ot-graph::
   :entries: ece19.blinklicht
