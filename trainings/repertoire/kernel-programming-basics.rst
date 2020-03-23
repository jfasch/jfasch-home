.. meta::
   :description: Dieses Training vermittelt Grundkenntnisse der Linux
		 Kernel Programmierung, und ermöglicht ihnen einen
		 schnellen Start
   :keywords: schulung, training, programming, c, linux, kernel, linux
              kernel, driver, kernel driver, module, hardware, pci,
              semaphore, mutex, spinlock, wait queue, waitqueue,
              device, character device, block device, interrupt,
              interrupt handler, isr

Kernelprogrammierung: Einführung
================================

.. sidebar:: Kursdaten

   .. csv-table::

      Anfrage, training@faschingbauer.co.at
      Dauer, 2 Tage
      Sourcecode, `jf-kernel-course </https://github.com/jfasch/jf-kernel-course>`__

Der Linux Kernel ist zu verzweigt und komplex, um in eine Schulung
egal welcher Länge zu passen. Diese Schulung richtet sich an erfahrene
Programmierer, die in das Thema "Kernelhacking" einsteigen wollen und
einen Quickstart möchten, der ihnen die grundlegenden Mechanismen mit
auf den Weg gibt. Damit gerüstet, und mit genügend Neugier und
Programmiergeschick, kann man sich in die verschiedenen Subsysteme des
Kernels vorarbeiten. Beispielcode ist `mehr als selbst den
Kernelentwicklern lieb ist <https://github.com/torvalds/linux>`__
vorhanden.

Kursinhalt
----------

(Der Ursprung dieses Kurses ist ein :ref:`eintägiger Ausflug ins
Kernel-Land <records-bodenseo-2015-11-30-kernel>` im Rahmen eines
einwöchigen :ref:`"Systemnahe Programmierung" <trainings-sysprog>`
Trainings am Bodensee.)

* **Module**. In Linux-Speak ist ein *Modul* dynamisch ladbarer
  Code. Module werden geladen (explizit oder implizit), initialisiert,
  deinitialisiert, entladen.
* **Devices**. Hardware wird im Kernel als *Device* präsentiert, dem
  Softwaregegenstück zur physischen Hardware. Ein *Device Special
  File* ist die Schnittstelle zum Userspace.
* **Synchronisationsmechnismen**. Während Prozesse im Userspace eigene
  Adressräume haben, hat der Kernel, der alle Prozesse repräsentiert,
  einen einzigen. Dadurch ist es sehr wichtig, die verfügbaren
  Synchronisationsmechnismen zu kennen und anwenden zu können. (Zum
  Beispiel: "Warum darf man in einer Interruptserviceroutine kein
  Mutex locken?")
* **Kommunikationsmechnismen**. Jeder kennt *Wartebedingungen* - liest
  man zum Beispiel von einem Socket, *blockiert* der Aufruf solange,
  bis Daten einlangen. Solche Wartebedingungen sind allgegenwärtig,
  und an der Basis jedes Betriebssystemes.
* **Interrupthandling**. Interrupts sind im Prinzip Benachrichtigungen
  von Hardware an den Kernel. Es gibt verschiedene Arten, damit
  umzugehen, und noch mehr verschiedene Arten, wie man sein System
  unbrauchbar machen kann.
  
Empfohlene Vorkenntnisse
------------------------

Solide Kenntnisse in C werden vorausgesetzt. Kenntnisse in Embedded
Betriebssystemen sind von Vorteil, genauso wie Hardwarekenntnisse.
