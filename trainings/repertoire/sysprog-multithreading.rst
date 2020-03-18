Systemprogrammierung: Multithreading
====================================

.. sidebar:: Kursdaten

   .. csv-table::

      Anfrage, training@faschingbauer.co.at
      Dauer, 2 Tage
      PDF Slides, :download:`sysprog </trainings/material/pdf/020-linux-sysprog--en.pdf>`

Parallele Programmierung war schon immer schwer, und es ist
unverständlich, warum Multithreading von modernen Programmiersprachen
und Frameworks ungeachtet der Gefahren als einzige Möglichkeit,
effiziente Programme zu schreiben, propagiert wird.

.. image:: images/salad-mt-small.jpg
   :alt: Applied Multithreading
   :align: right

Parallele Programmierung ist auch unter Linux schwer - wie sollte es
auch anders sein? Der Kurs gibt einen soliden Überblick über
Multithreading unter Linux (in C/C++) und die Mechanismen, die dort
zur Synchronisation und Kommunikation zur Verfügung stehen. Vor allem
werden die Gefahren beleuchtet, die unbedachtes Handeln in einer
parallelen Welt mit sich bringt.

Kursinhalt
----------

* **Der Lebenszyklus von Threads**. Threads werden gestartet, und
  meistens auch beendet. Hier lauern die ersten Gefahren, denn man
  kommt leicht in die Versuchung, Threads mit Gewalt zu terminieren -
  ohne sich der Konsequenzen bewusst zu sein.

  * *Starten von Threads*
  * *"Joinable" vs. "Detached"*
  * *Terminieren von Threads*
  * *Attribute*: Thread ID, Realtime-Eigenschaften

* **Raceconditions und deren Vermeidung**. Ein grundlegendes
  Verständnis für Race Conditions wird vermittelt. Sie lauern
  überall - auch dort, wo man sie nicht vermutet. Es gibt verschiedene
  Möglichkeiten, Race Conditions zu vermeiden; ein *Mutex* ist nur
  eine davon.

  * *Load-Modify-Store*: die Mutter aller Raceconditions
  * *Mutexes*: Anwendung, die verschiedenen Typen
  * *Atomare Integeroperationen*

* **Kommunikationsmechanismen**. Die *Condition Variable* ist ein
  grundlegender Bestandteil des Linux-Werkzeugkastens, mit dem man
  sich eigene Inter-Thread-Kommunikationskanäle bauen kann (zum
  Beispiel Message Queues, Events, ...).

  * *Condition Variable*: Prinzip
  * *Beispiel: Message Queue*
  * *Beispiel: WIN32 Auto-Reset Event*

* **Verschiedenes**.

  * *One-Time-Initialisierung*
  * *Atomare Integer-Operationen*
  * *Thread Specific Data* (Thread Local Storage)

* **Realtime**. Wenngleich Linux vermutlich niemals in die Reihen der
  traditionellen Hard-Realtime-Systeme aufgenommen werden wird (die
  Codebasis ist einfach zu groß und verzweigt), hat es doch
  ansehnliche Realtimefähigkeiten. Realtime ist ein komplexes Gebiet,
  hier wird ein Überblick vermittelt.

  * Prioritäten
  * Scheduling Policies: FIFO, Round-Robin, ...
  * Gefahren: Priority Inversion etc., und Mechanismen zur Vermeidung
    ("Mutex-Protokolle" wie Priority Inheritance)
  
Empfohlene Vorkenntnisse
------------------------

Solide Kenntnisse in C werden vorausgesetzt, genau wie eine
Grundkenntnis des Systems (:doc:`Einführungskurs <sysprog-basics>`).
