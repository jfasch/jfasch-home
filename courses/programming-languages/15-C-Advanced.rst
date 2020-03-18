.. meta::
   :description: Dieses Training versucht, trotz aller Widernisse der
                 Sprache, C näherzubringen und seine Beweggründe
                 verstehen zu lernen
   :keywords: schulung, training, programming, c, linker, toolchain,
              kernighan, ritchie, linux, embedded, pointer, memory

C für Fortgeschrittene
======================

.. sidebar:: Kursdaten

   .. csv-table::

      Anfrage, training@faschingbauer.co.at
      Dauer, 3 Tage
      PDF Slides, :download:`C </courses/material/pdf/050-c.pdf>`

C ist eine kleine und einfache Sprache, was den Sprachumfang angeht. C
ist auch eine schnelle Sprache, da compilierter Maschinencode
ausgeführt wird.

Der Teufel liegt allerdings im Detail --- jeder, der zum Beispiel mit
Pointern hantiert, wird sofort beipflichten. Oder jeder, der einmal
den beinharten Typenkonvertierungen zwischen ``signed`` und
``unsigned`` aufgesessen ist. Oder jeder, der ...

Der Kurs beleuchtet die nicht ganz so oft beschrittenen dunklen Ecken
der Sprache, widmet sich intensiv der Fehlersuche, und versucht
Erklärungen zu geben, wo diese aus der Sprachdefinition nicht so
offensichtlich greifbar sind.

Zielpublikum
------------

Der Kurs richtet sich an erfahrene C-Programmierer, die den Verdacht
haben, dass manches, was sie tun, auf Zufall basiert.

Kursinhalt
----------

* **Typkonversionen und ihre Fallen**: die Lücken im Typensystem von C
  
  * *Techniken zur Typensicherheit*

* **Der C-Präprozessor**

  * *Dunkle Ecken*
  * *C99 Features*, um den C-Präprozessor unnötig zu machen.

* **Programmhygiene**. Verschiedene Wege, sich von Compiler und Linker
  den Weg zu sauberen Programmen weisen zu lassen.

   * *``const``*
   * *``static``*
   * *Explizite Typensicherheit*

* **Performance**

  * Optimierungstechniken, die Compiler anwenden - viele händische
    Optimierung sind unnötig und erschweren die Lesbarkeit
  * Memoryzugriff, Caches, Cache-Thrashing

* **Debugging** mit dem GNU-Debugger ``gdb``
* **Profiling** mit verschiedenen Tools

  * ``gprof``: der Ur-Profiler in Unix
  * ``valgrind`` beziehungsweise ``callgrind``
  * ``oprofile``: Profiling mit Hardwareunterstützung

* **Verschiedenes**

  * Was heisst eigentlich ``volatile``?
  * Was ist *Alignment*?
  * Compiler "Built-Ins", wie zum Beispiel *Atomare Instruktionen*

Empfohlene Vorkenntnisse
------------------------

Solide :doc:`Kenntnisse in C <10-C>` werden vorausgesetzt.
