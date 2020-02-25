:orphan:

Linux from Scratch, 16.9.2013, München
======================================

Von Montag bis Freitag zügig durch, dann am Freitag gegen 4 Uhr die
Punktlandung: ``fdisk``, GRUB 0.97 (siehe unten) ins MBR,
``menu.lst``, und bootet von Disk! Danke an alle für die lustige
Woche!

Nachfolgend ein paar Nachsätze und Links, in etwas wahlloser
Reihenfolge.

GRUB 0.97
---------

GRUB 0.97 ("GRUB Legacy") baut nicht mit einer reinen 64 Bit
Toolchain. Im Kurs haben wir das erste Mal (Zeit is worden) ein 64 Bit
System gebastelt und ``glibc`` und ``gcc`` leichtfertigerweise
(eigentlich richtigerweise) mit ``--disable-multilib``
ausgestattet. GRUB läuft nicht mit sowas (seltsamerweise baut er
damit). Darüber haben wir uns aus Zeitersparnisgründen (der Weg war
klar: Multilib-Toolchain bauen) hinweggeholfen, und zwar mit einer
vorcompilierten statisch gelinkten Version von GRUB aus dem
Gentoo-Paket ``sys-boot/grub-static``.

Cross Systeme Bauen
-------------------

Christof's Ziel war, alle Sourcen crosszucompilieren und schliesslich
auf einem meiner Raspberries zum laufen zu bringen. Leider
gescheitert, weil durch einen unglücklichen Umstand (Danke an die
Infrastruktur bei Mathias, die es erlaubt, den Schulungsrechner extrem
leicht neu aufzusetzen :-) ) alle Kompilate und sein Build-Script
verschwunden waren. Das Buildscript konnte durch kreativen Einsatz von
``dd`` wiederhergestellt werden, aber die Zeit war dahin.

Wie eingangs im Kurs gesagt, ist der Output des Kurses völlig sinnfrei
- es gibt Distributionen, die einem diese Arbeit erledigen. Will man
unbedingt selbst compilieren, verwendet man z.B. `Gentoo Linux
<http://www.gentoo.org>`__.

Für nicht-PC-Architekturen ist die Situation ein wenig komplizierter,
und man ist unter Umständen wirklich versucht, das, was wir in dem
Kurs machen, im richtigen Leben anzuwenden. Andere Leute haben das
gleiche Problem - und wie es so ist in der Open-Source-Welt, gibt es
mittlerweile auch dafür flexible Lösungen. Ich empfehle, sich `Yocto
<https://www.yoctoproject.org/>`__ anzusehen.

Realtime
--------

Das Wort Xenomai ist im Kurs mal gefallen. Für harte
Realtime-Garantien durchaus gerechtfertigt; unter Umständen muss man
aber nicht so arge Geschütze auffahren, sondern reicht es auch, die im
Linux-Kernel enthaltenen Realtime-Features zu nützen (Stichwort
``SCHED_FIFO`` und ``SCHED_RR`` Scheduling). Reicht das nicht, kann
ein guter Mittelweg auch der `PREEMPT_RT Patch
<http://rt.wiki.kernel.org>`__ sein, dessen Ziel ist, immer mehr in
Mainline zu diffundieren.

Init, oder der Prozess mit der ID 1
-----------------------------------

Unser ``init`` ist ein kleines Shell-Script, das Pfade setzt,
``ldconfig`` etc. aufruft, und dann eine Login-Shell startet. Nicht
sehr flexibel und ausgeklügelt, aber durchaus geeignet, die
Funktionsweise eines Unix-Systems zu verdeutlichen. Will man flexibler
werden, muss dieser Init mehr machen.

`System-V Init <http://de.wikipedia.org/wiki/SysVinit>`__ ist das, was
man von Linux-Distributionen und anderen Unixen seit jeher kennt. Es
ist gewaltig geschichtsbelastet, basiert auf Shell-Scripts, und trägt
zur Boot-Zeit eines Systems den meisten Teil bei.

Eine sehr intelligente Linux-spezifische Alternative, die von immer
mehr Distributionen eingesetzt wird, ist `systemd
<http://www.freedesktop.org/wiki/Software/systemd/>`__. Sehr
interessant, und trotz aller Behauptungen gar nicht overengineered.

Verschiedenes
-------------

* `Linux Device Drivers, Jonathan Corbet
  <http://lwn.net/Kernel/LDD3/>`__
* `LWN <http://lwn.net/>`__, meine Lieblingsseite für
  Linuxthemen. Kernel-zentrisch.
* `Bash Programmierung
  <http://tldp.org/HOWTO/Bash-Prog-Intro-HOWTO.html>`__
