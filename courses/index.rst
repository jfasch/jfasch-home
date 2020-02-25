Schulungen
==========

.. toctree::
   :hidden:
   :titlesonly:

   linux-basics.rst
   programming-languages/10-C.rst
   programming-languages/12-C-Refresher.rst
   programming-languages/15-C-Advanced.rst
   programming-languages/20-CXX.rst
   programming-languages/30-Python-Basics.rst
   programming-languages/35-Python-Advanced.rst
   programming-languages/40-bash.rst
   programming-languages/50-make.rst
   sysprog/System-Basics.rst
   sysprog/Network.rst
   sysprog/Multithreading.rst
   sysprog/Fortgeschrittenes.rst
   sysprog/Embedded.rst
   misc/raspi-hands-on.rst
   misc/kettner-lfs-descr.rst
   misc/Subversion.rst

.. image:: sysprog-bodenseo.jpg
   :alt: Kurs im Hoeri-Hotel
   :align: right

Jahre des Programmierens haben ihre Spuren hinterlassen - es hat
sich einiges an Wissen angesammelt. Vieles davon ist nicht mehr
relevant (was gut ist); einiges vom Rest habe ich strukturiert und zu
Schulungsunterlagen verarbeitet.

Mir ist es sehr wichtig, Schulungen ausschliesslich über solche Themen
anzubieten, in denen ich selbst lange genug tätig bin und in denen ich
genügend Erfahrung besitze. Zum Beispiel möchte ich gerne eines Tages
eine Schulung über `Git <http://git-scm.com/>`__ anbieten - bis
dahin ist es allerdings noch ein langer Weg. Ich lerne noch.

Kursmaterial wird gestellt in Form von gedruckten Handouts der Folien,
sowie einem PDF derselben.

Basics
------

* :doc:`linux-basics`: "Wie tickt Linux?" für Technik-Affine.

Programmiersprachen
-------------------

Unix und speziell Linux haben eine Vielzahl von Programmiersprachen
hervorgebracht. Im Laufe der Zeit habe ich viele von ihnen
erlernt. Einige habe ich erfolgreich verlernt (zum Beispiel Perl),
andere sind mir erhalten geblieben.

* :doc:`C Grundlagen <programming-languages/10-C>`: C anhand des
  didaktisch perfekten (weil minimalen) Buches `The C Programming
  Language
  <http://en.wikipedia.org/wiki/The_C_Programming_Language>`__
* :doc:`C Auffrischung <programming-languages/12-C-Refresher>`:
  Schnellstart für Programmierer, die C kennen, deren Wissen aber
  entstaubt gehört
* :doc:`C für Fortgeschrittene <programming-languages/15-C-Advanced>`:
  Verschiedenes aus C, das die wenigsten wissen
* :doc:`C++ Grundlagen <programming-languages/20-CXX>` für
  C-Programmierer
* :doc:`Python Grundlagen <programming-languages/30-Python-Basics>`:
  die wahrscheinlich schönste und einfachste Sprache der Welt
* :doc:`Python für Fortgeschrittene
  <programming-languages/35-Python-Advanced>`: Python ist nicht nur
  einfach, sondern auch mächtig
* :doc:`Bourne (Again) Shell <programming-languages/40-bash>`: Shell
  Scripting
* :doc:`GNU Make <programming-languages/50-make>`: die Mutter aller
  Build Tools - ist auch eine kleine Programmiersprache

Systemnahe Programmierung
-------------------------

Mit Linux kann man Probleme auf elegante und einfache Art lösen -
vorausgesetzt, man versteht die Funktionsweise des Betriebssystems.

Die Kursreihe *Systemnahe Programmierung unter Linux* vermittelt den
Teilnehmern ein grosses Bild, indem die zentralen Punkte des Systems
herausgearbeitet werden, und auf dieser Basis in speziellere Gebiete
vorgestossen wird. Die Unterlagen sind modular aufgebaut, sodass sie
je nach Bedarf angepasst werden können - die nachfolgenden
Schulungsbeschreibungen sind dementsprechend als Vorschlag zu
verstehen.

* :doc:`Linux Grundlagen <sysprog/System-Basics>`: eine Einführung in
  das System anhand von Beispielen.
* :doc:`Netzwerk-Programmierung <sysprog/Network>`: Client/Server
  Programmierung mit TCP/IP und UNIX-Domain Sockets
* :doc:`Multithreading <sysprog/Multithreading>`: richtiger Umgang mit
  POSIX Threads und Realtime.
* :doc:`Fortgeschrittene Themen <sysprog/Fortgeschrittenes>` wie
  virtuelles Memory, POSIX IPC, und konsequente Unix-ismen, die es
  paradoxerweise nur unter Linux gibt.

  .. todo::

     avl live hacking: mmap, ipc

* :doc:`Embedded Linux <sysprog/Embedded>`: Systemnahe
  Unixprogrammierung, gepaart mit ausgewählten Themen aus der
  Embedded-Welt

Verschiedenes
-------------

* :doc:`Raspberry Pi Hands-On <misc/raspi-hands-on>`
* :doc:`Linux from Scratch <misc/kettner-lfs-descr>`
* :doc:`Einführung in Subversion <misc/Subversion>`
