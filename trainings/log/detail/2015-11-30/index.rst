Kursnotizen: Linux Embedded 2015-11-30
======================================

Multithreading
--------------

Ausprogrammiert haben wir den Load/Modify/Store Konflikt anhand eines
parallelen Integer Increments - als Demonstration der Mutter aller
Race Conditions. Danach haben wir die Race Condition mit Hilfe eines
Mutex gefixt.

Die Inter-Thread Kommunkation mit Hilfe von Condition Variablen habe
ich nur frontal vorgeführt (mit viel Diskussion, vielen Dank an
Stefan), mit Beispielcode aus meinem `Github-Projekt
<https://github.com/jfasch/jf-linuxexamples>`__) zum Kurs
:doc:`/trainings/repertoire/sysprog/index`.

Das Beispiel war eine "Message Queue", händisch ausprogrammiert mit
Hilfe eines Mutex und zweier Condition Variablen ("not full", "not
empty"), und den Operation ``push`` und ``pop``. `Code zu bewundern
hier
<https://github.com/jfasch/jf-linuxexamples/blob/master/pthread/base/message-queue.h>`__.

GPIOs in Userspace
------------------

Ihr könnt euch erinnern an die LED, die ich von der Commandline aus
blinken liess, irgendwo in ``/sys/class/gpio``. Ein wenig später im
Kurs hatten wir GPIOs, die als Interrupt (an der *Falling Edge*)
konfiguriert waren, und die ich in einem kleinen C-Programm
empfing. Hier ein paar Teile ...

* `Dokumentation im Kernel Source
  <https://www.kernel.org/doc/Documentation/gpio/sysfs.txt>`__. Unbedingt
  lesen.
* Das Beispielprogramm, das auf den GPIOs 23 und 24 horcht,
  `gpio-interrupt.cc
  <https://github.com/jfasch/jf-linuxexamples/blob/master/demo/gpio-interrupt.cc>`__

CAN Bus
-------

CAN wird unter Linux über normale Sockets gesprochen, siehe dazu die
ausführliche Dokumentation im Kernel Source:
`Documentation/networking/can.txt
<https://www.kernel.org/doc/Documentation/networking/can.txt>`__.

Schamlose Eigenwerbung: mein Vortrag bei den `Grazer Linuxtagen 2014
<https://glt14.linuxtage.at/>`__ zu dem Thema,

* `Programm
  <https://glt14-programm.linuxtage.at/events/239.de.html>`__
* `Slides
  <https://glt14-programm.linuxtage.at/attachments/151_GLT2014-CANBus.pdf>`__
* `Video
  <https://www.youtube.com/watch?v=5XuSr4M9uNI&list=PLWHx0EvwLLUHaDLeRf7bHoVjy9wx7IbbB&index=6>`__

Das `can-utils <https://github.com/linux-can/can-utils>`__ Projekt ist
das Überbleibsel des ehemaligen SocketCAN Projektes; dessen
Kernel-Teil ist schon lange vom Kernel absorbiert worden. Es enthält
schnuckelige kleine Utilities wie Aufzeichnen, Replay, etc. (Siehe
dazu die `Folien vom Vortrag
<https://glt14-programm.linuxtage.at/attachments/151_GLT2014-CANBus.pdf>`__.)

.. _records-bodenseo-2015-11-30-kernel:

Driver Beispiele
----------------

Freitag war Kerneldrivertag. Sorry Emanuel für den Reboot. Die
Beispieldriver sind zu finden in `meinem Github-Repository zum
Kernel-Kurs <https://github.com/jfasch/jf-kernel-course>`__.

Beispiele für Real-Life-Driver:

* Wir hatten ``/dev/random``, ``/dev/mem`` (wo der Hans-Jörg seine
  Register findet), ``/dev/null``, ``/dev/zero``. Diese "Devices"
  werden vom *mem* Driver angeboten. Er hat ganz prominent die *Major
  Number* 1 und ist in `drivers/char/mem.c
  <http://lxr.free-electrons.com/source/drivers/char/mem.c>`__.
  implementiert. Gutes Beispiel für den Anfang.
* Der MCP2515 Driver (CAN Controller, über SPI angesprochen). Ein
  etwas fortgeschritteneres Beispiel, da er sich ins Network Subsystem
  einpflegt und als SPI Client agiert. (Kein Character Device in
  Sicht.)  `drivers/net/can/spi/mcp251x.c
  <http://lxr.free-electrons.com/source/drivers/net/can/spi/mcp251x.c>`__
* Der CAN Controller im AT91 SoC - Stefan, ich glaub das ist der Chip,
  der auf deinem Stecker verbaut ist. `drivers/net/can/at91_can.c
  <http://lxr.free-electrons.com/source/drivers/net/can/at91_can.c>`__.

Heizungssteuerung
-----------------

Lacht nur!

* Das OpenHeating Projekt

  * `Github <https://github.com/jfasch/openheating>`__
  * `Homepage <https://www.openheating.org/>`__

* Ein `Vortrag <https://glt15-programm.linuxtage.at/events/15.html>`__
  bei den Grazer Linuxtagen 2015 (`Folien
  <https://glt15-programm.linuxtage.at/system/attachments/26/original/920-glt-2015.pdf>`__)
