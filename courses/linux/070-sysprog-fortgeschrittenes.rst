================================================================
 Systemprogrammierung: Virtuelles Memory, IPC, Shared Libraries
================================================================

.. sidebar:: Kursdaten

   .. csv-table::

      Anfrage, training@faschingbauer.co.at
      Dauer, 2 Tage
      PDF Slides, :download:`sysprog </training-material/slides/pdf/020-linux-sysprog--en.pdf>`
      S5 Slides, :doc:`Signals </training-material/slides/signals-slides>`
      S5 Slides, :doc:`IPC </training-material/slides/ipc-slides>`
      Live Hacking, :doc:`Signals </training-material/live-hacking/signals-screenplay>`
      Live Hacking, :doc:`IPC </training-material/live-hacking/ipc-screenplay>`


Will man in Tiefen des Systems steigen, die dem Alltagsprogrammierer
normalerweise verborgen bleiben, ist dieser Kurs genau der
Richtige. Linux und Unix bieten an der Basis eine Vielzahl von
Schnittstellen, die es ermöglichen, hochperformante Anwendungen zu
schreiben. Hier wird ein Überblick gegeben.

Kursinhalt
==========

* **Virtuelles Memory**. Speicherverwaltung in modernen
  Bertriebssystemen basiert auf sogenanntem *virtuellen Memory*. Zum
  Beispiel bleibt dem Benutzer verborgen, dass unter Umständen
  Speicherbereiche seiner Programme auf die Festplatte ausgelagert
  werden (Swap), oder dass der Code von zwei Instanzen desselben
  Programmes nur einmal im Hauptspeicher liegt.

  * *Memory Mappings*: Grundlagen
  * *Sichtbarkeit*: "Private" vs. "Shared"
  * *Speicherzugriff*: Schutzmechanismen
  * *Assoziierte System Calls*: mmap, mlock, mlockall, ...
  * *Realtime-Aspekte*

* **POSIX IPC**. Netzwerk-Kommunikation mittels Sockets ist nur *ein*
  Mittel, Prozesse miteinander kommunizieren zu lassen. *IPC* (Inter
  Process Communication) ist eine Sammlung weiterer Mechanismen, auf
  die hier eingegangen wird.

  * *Shared Memory*
  * *Semaphoren*
  * *Message Queues*

* **Neue, Linux-spezifische Systemcalls**. Gewisse Mechanismen in Unix
  sind steinalt und haben bis heute überlebt, obwohl es keineswegs
  einfach ist, sie fehlerfrei zu benutzen - man denke an Signale und
  Timer. Linux führt die Unix-Tradition "Everything is a File"
  konsequent weiter und verpasst genau diesen Mechanismen ein
  alternatives Interface, das genau auf diesem Prinzip beruht.

  * *Signal Handling*: ``signalfd``
  * *Timer*: ``timerfd_create``
  * *Events*: ``eventfd``

* **Shared Libraries**. Dynamisch ladbare Libraries sind ein
  mächtiges, wenngleich kompliziertes, Werkzeug, um Flexibilität,
  Ressourcenschonung, und einen wasserdichten Upgradepfad zu
  erreichen.

  * *ELF*: "Executable and Linkable Format"
  * *Automatisches/implizites Laden*: Linux Loader
  * *Explizites Laden* mit ``dlopen()``: "Loading Scopes" etc.
  
Empfohlene Vorkenntnisse
========================

Solide Kenntnisse in C werden vorausgesetzt, genau wie eine
Grundkenntnis des Systems (vgl. :doc:`Einführungskurs
<020-sysprog-basics>`).
