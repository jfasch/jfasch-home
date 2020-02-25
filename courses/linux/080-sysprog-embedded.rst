Systemprogrammierung: Embedded/Hardware
=======================================

.. todo::

   sidebar: 5

**Gute alte Betriebssystemkonzepte in Verbindung mit hardwarenaher
Programmierung - das ist das Zentrum dieses Kurses.**

Linux ist ein vollwertiges Unix - das heisst, es setzt auf die selben
Betriessystemkonzepte auf, die sich seit mehr als vier Jahrzehnten
bewährt und weiterentwickelt haben.

Linux ist nicht nur ein vollwertiges Unix, sondern auch ein
hervorragendes Embedded-Betriebssystem. Es kann mit jeglicher Hardware
umgehen, die im Embedded- und Automotive-Sektor vertreten ist. Möglich
ist das, indem Linux die altbewährten Konzepte konsequent ausbaut,
Hardwareschnittstellen so gestaltet, dass sie sich nahtlos einfügen,
und verschiedene Features wie Echtzeitfähigkeit implementiert.

Dieser Kurs gibt in fünf Tagen eine Einführung in das Betriebssystem
selbst, erläutert die Konzepte dahinter, die Programmierung inklusive
Werkzeuge, und rundet das Gelernte mit einem "Hardwarebastelworkshop"
ab.

Zielpublikum
------------

* **Embeddedprogrammierer**, die sich schon länger fragen, warum
  Features eines "normalen" Betriebssystems, wie z.B. Multiprocessing,
  TCP/IP, Dateisysteme, ihnen versagt bleiben oder teuer erkauft
  werden müssen.
* **Elektroniker**, die Devices testen wollen, bevor in ihrer Firma
  die Hostsoftware soweit ist.
* **Architekten**, die ihre Plattformzusammensetzung entscheiden und
  rechtfertigen müssen. Die Frage "Wieviel Logik stecke ich in externe
  Hardware, und muss ich das überhaupt?" ist schwer zu beantworten.

Die Teilnehmer sind eingeladen, eigenes Equipment - Lötmaterial,
Breadboard, etc. - mitzubringen. Werkzeug und Material ist reichlich
vorhanden, jedoch macht es mit dem eigenen wahrscheinlich mehr
Spass. Die Bastelei erfolgt mit vorhandenen Raspberry Minicomputern,
mit denen sich hervorragend Prototypen erstellen lassen.

Kursinhalt
----------

* **Linux und die Commandline**. Linux ist ein Desktopbetriebssystem.
  Unter anderem - es ist alles nur eine Frage des vorhandenen
  Speichers. Das Rasperry ist für Embedded-Verhältnisse mit 512MB
  reichlich ausgestattet. Ein Desktop ist trotzdem nur mühsam zu
  betreiben - und ist für ein Embedded-Produktivsystem ohnehin
  unangebracht. Zurück an die Unix-Anfänge also ...

  * Remote Login mit SSH
  * Grundlegendes: die Shell, Werkzeuge wie ``sed``, ``grep``,
    ``find`` ...
  * Diagnose mit Tools wie ``netstat``, ``top``, den Filesystemen
    ``procfs`` und ``sysfs`` ...

* **Programmierung**. Die altbewährten Unix-Konzepte werden benutzt,
  um einfache Übungen durchzuführen. Themen sind unter anderem ...

  * Files. Files bzw. Filedeskriptoren sind ein grundlegendes Konzept
    unter Linux/UNIX.
  * Prozesse. Das zweite Standbein von Linux/UNIX: getrennte
    Adressräume.
  * Multithreading. Mehrere parallele Abläufe im gleichen Adressraum
    zu haben, erfordert vom Programmierer einiges an Sorgfalt und
    Wissen.
  * Netzwerkprogrammierung. Im Grunde sehr einfach (File I/O), bloss
    sehr breit gefächert. TCP/IP ist nur ein Netzwerk unter vielen,
    Bluetooth, CAN-Bus, und viele andere Netzwerke sind auch über
    dieses API zu programmieren.
  * Memory Management. Virtuelles Memory - Shared Memory,
    Memory-Mapped I/O und weitere Techniken.
  * Realtime. Aus gewissen Szenarien (Steuerungen, Audio, ...) nicht
    wegzudenken. Auch gefährlich, wenn falsch bzw. zu umfangreich
    benutzt.
  * Kernel-Konzepte. Wenngleich nicht Hauptthema des Kurses, ist es
    dennoch sehr nützlich, zu wissen, wie diese Konzepte, die die
    Programmierung so einfach machen, unter der Haube implementiert
    sind.

* **Hardware**.

  * Das General Purpose IO (GPIO) Subsystem. Schalten von Ausgängen,
    Abfragen von Eingängen (sowohl über dummes Polling als auch über
    intelligentes ereignisgesteuertes Programmieren bzw. Interrupts)
  * Mit Mikrocontrollern sprechen. Aufgaben wie
    z.B. Temperaturmessung, IO-Port Expandierung, Pulse Width
    Modulation (PWM) etc. werden gerne an externe Hardware
    ausgelagert, die über dedizierte Protokolle angesteuert
    wird. Hier wird ein Überblick über die Protokolle und über
    verschiedene Aspekte der Integration in Linux
    gegeben. Stichworte:

    * Inter Integrated Circuit (I2C)
    * Serial Peripheral Interface (SPI)
    * Verschiedene Driverframeworks im Kernel
    * CAN-Bus. In Linux hat sich eine sehr nette Infrastruktur
      entwickelt, die das Protokoll nahtlos in den Netzwerkstack
      einpasst.

Empfohlene Vorkenntnisse
------------------------

* Etwas Programmiererfahrung. Implementationssprachen sind C und/oder
  Python.
* Etwas Hardwareerfahrung
