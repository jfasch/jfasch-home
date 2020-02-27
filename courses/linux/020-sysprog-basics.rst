Systemprogrammierung: Einführung
================================

.. sidebar:: Kursdaten

   .. csv-table::

      Dauer, 2 Tage

Dieser Einführungskurs richtet sich an Programmierer, die Linux nicht
so sehr kennen, es aber kennen lernen wollen. Die Zusammenhänge und
die Grundpfeiler des Systems werden erklärt, sodass man am Ende ein
großes Bild hat und sich selbst orientieren und zurechtfinden kann.

Kursinhalt
----------

* **Die Shell**. Für Ein- bzw. Umsteiger ist dieses Commandline-Zeug
  meist ein einziges Ärgernis. Wenn man allerdings die Möglichkeiten,
  die einem die Shell bietet, einmal zu nutzen weiss, schlägt man
  damit das ausgeklügeltste GUI. Im Kurs werden Commandline-Editing,
  History, die Pipe, und weitere Shell-Grundlagen erklärt.
* **Systemkonzepte und Systemcalls**. Die Shell und Unix haben sich
  gemeinsam entwickelt, und viele Konzepte des Betriebssystems sind
  direkt in der Shell erkennbar.

  * Kurze Beispiele in der Shell: Prozesse, Filesystem,
    IO-Redirection, ...
  * ``strace``: ein Programm, mit dem sich die Systemschnittstellen
    (sogenannte Systemcalls) inspizieren lässt.
  * *Everything is a File* ist ein Grundprinzip in Unix, und ganz
    speziell in Linux.
  * Das ``/proc`` Filesystem

* **Die Toolchain**. Die Programmiersprache für systemnahes
  Programmieren ist C - die *Toolchain* ist eine Sammlung von
  Programmen, die C-Code in ausführbare Programme verwandeln.

  * Compiler, Linker
  * Debugger
  * Shared und statische Libraries
  * Executables

* **Make** ist ein Programm, das die Toolchain bedient und Programme,
  die aus mehr als einem C-File bestehen, baut. Seine Handhabung ist
  für Anfänger etwas gewöhnungsbedürftig - hier wird eine kurze
  Einführung gegeben.
* **Programmierung**. In Übungen werden grundlegende Systemcalls
  verwendet.

  * Prozesse: ``fork/exec/wait``, Signale
  * Filesystem: ``open/read/write/close``
  * Filedescriptoren und assoziierte Systemcalls
  
Empfohlene Vorkenntnisse
------------------------

Solide Kenntnisse in C werden vorausgesetzt. Kenntnisse in
Betriebssystemen im Allgemeinen sind von Vorteil, aber nicht zwingend
notwendig. (Spaß an Lowlevel-Programmierung hingegen schon.)
