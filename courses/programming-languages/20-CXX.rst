.. meta::
   :description: Dieses einwöchige Training versucht, trotz aller
                 Widernisse der Sprache, C++ näherzubringen
   :keywords: schulung, training, programming, c, c++, linker,
              toolchain

C++: Einführung und Überblick
=============================

.. sidebar:: Kursdaten

   .. csv-table::

      Anfrage, training@faschingbauer.co.at
      Dauer, 5 Tage
      PDF Slides, :download:`C++03 </courses/material/pdf/055-c++03.pdf>`
      PDF Slides, :download:`C++11 </courses/material/pdf/056-c++11.pdf>`

C++ wurde ursprünglich erfunden, um als Superset des guten alten C
dessen Schwächen leichter handhabbar zu machen. Die Eckpfeiler der
damals neuen Sprache waren zum Beispiel,

 * Konstruktoren und Destruktoren, die es ermöglichen,
   Ressourcenverwaltung kontrollierter zu implementieren
 * Objektorientierte Programmierung mit Vererbung und Interfaces. OOP
   war zwar schon aus anderen Programmiersprachen bekannt, diese haben
   aber nie in den Mainstream Einzug gehalten.

C++ hieß damals "C mit Klassen", was ein treffender Name war. Seitdem
hat sich die Sprache allerdings weiterentwickelt. Man kann heute noch
vereinzelt Artefakte von C erkennen (Pointer wird es immer geben), und
man kann C++ noch so programmieren, als ob es C wäre - aber mit C hat
das ganze soviel zu tun wie ein ICE mit einer Dampflokomotive.

C++ stellt dem Programmierer eine Vielfalt an Datenstrukturen und
Algorithmen zur Verfügung, die einfach da sind und funktionieren. Dem
Programmierer werden Sprachkonstrukte - und ein geniales Typensystem
- zur Verfügung gestellt, um eigene Libraries zu erstellen. Dass C++
eine einfache Programmiersprache ist, hat allerdings noch keiner
gewagt zu behaupten.

Der Kurs gibt, basierend auf einem :doc:`Vorwissen, was C anbelangt
<10-C>`, eine Einführung in die Sprache und ihre Sprachmittel und
Libraries. Und, was vielleicht das wichtigste ist, in ihre Fallen -
deren gibt es nämlich reichlich.

Zielpublikum
------------

 * C-Programmierer, die einen Umstieg erwägen - unter Umständen, weil
   sich die Zielplattform von einem Embeddedbetriebssystem auf Linux
   weiterentwickelt hat.
 * Programmierer, die bereits C++ einsetzen, aber mehr machen
   wollen. Vielerorts wird zum Beispiel C++ wie C programmiert - was
   möglich aber nicht optimal ist.

Kursinhalt
----------

* **Datenkapselung**

  * Klassen
  * Konstruktoren und Destruktoren
  * Kopieren von Objekten (inklusive Fallstricke)

* **Funktionen und Methoden**

  * Overloading
  * ``const``: der Weg zur Korrektheit
  * Referenzen: Pointer mal anders
  * ``static``: die 100ste Bedeutung dieses Keywords
  * Operator-Overloading

* **Exception Handling**: Strukturierte Fehlerbehandlung, abseits von
  ``if-else``
* **Templates**: eine Einführung in generische Programmierung
* **Standard Template Library (STL)**

   * Sortieren
   * Suchen
   * Sequentielle Container
   * Assoziative Container

* **Dynamische Speicherverwaltung**: die Operatoren ``new`` und
  ``delete``
* **Vererbung**

  * Grundlegende Mechanismen
  * Interfaces --- das ``virtual`` Keyword
  * Mehrfachvererbung (inklusive Fallstricke)

* **Objektorientiertes Design**: Grundlagen --- alles andere wäre zuviel
* **Die Neuerungen aus C++11 und C++14**: teilweise werden bereits in
  den bisherigen Kapiteln die Unterschiede zwischen "herkömmlichen"
  C++ (C++03) und dem "neuen" C++ erläutert. Es gibt mehr:

  * Range Based ``for`` Loops
  * Lambda Expressions
  * ``rvalue`` Referenzen und Moving
  * Threading

Empfohlene Vorkenntnisse
------------------------

Solide :doc:`Kenntnisse in C <10-C>` werden vorausgesetzt.
