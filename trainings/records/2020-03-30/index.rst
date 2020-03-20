C++ für Embedded C Programmierer (30.3.2020 - 3.4.2020 Baden Württemberg) 
=========================================================================

.. toctree::
   :hidden:

   gtest/basics

.. sidebar:: Material

   * :doc:`C Einführung (Schulungsbeschreibung)
     </trainings/repertoire/c>`
   * :doc:`C Advanced (Schulungsbeschreibung)
     </trainings/repertoire/c-advanced>`
   * :doc:`C++ (Schulungsbeschreibung)
     </trainings/repertoire/cxx>`
   * :download:`C (PDF) </trainings/material/pdf/050-c.pdf>`
   * :download:`C++03 (PDF) </trainings/material/pdf/055-c++03.pdf>`
   * :download:`C++11 (PDF) </trainings/material/pdf/056-c++11.pdf>`
   * :download:`CMake </trainings/material/pdf/045-cmake.pdf>`
   * Livehacking screenplay: :doc:`gtest/basics`

Plan (sich entwickelnd)
-----------------------

Tag 1
.....

`Test Driven Development
<https://www.amazon.de/Test-Driven-Development-Example-Signature/dp/0321146530>`__
funktioniert (weiss ich, weil ich es selbst betreibe). Unittesting
(mit `googletest <https://github.com/google/googletest>`__) soll Teil
des Trainings sein, warum also nicht den Kurs invertieren und uns von
Tests treiben lassen (zumindest was die Übungen anbelangt)? Also:

* :doc:`Einführung in Unittesting <gtest/basics>`
* Klassen, Members ... C++ Basics
* Konstruktoren, Destruktoren, am Beispiel Memoryleak.
* `Auffinden von Leaks mit valgrind <https://valgrind.org/>`__
* `RAII <https://en.cppreference.com/w/cpp/language/raii>`__
* Methoden, ``this``
* CMake im Vorbeigehen, sobald der angehäufte C++ Code zu gross
  wird. Eher früher als später.

Tag 2
.....

* Mehr zu Methoden: `overloading
  <https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm>`__
* Operator overloading
* Parameter passing

  * Per copy/pointer -> Referenzen
  * ``const``
  * Move, RValue-Referenzen (ab C++11)

* Break: zurück zu Unittesting

  * Fixtures
  * Mehr Assertions/Expectations: Exceptions
  * Death tests
  * Output (json, xml)

* Exceptions

Tag 3
.....

* Zur Einstimmung: alles schön und gut die letzten beiden
  Tage. *Aber*: all die Fallen!

  * Copy Konstruktor, Assignment operator
  * Globale Objekte, Abhängigkeiten
  * Exception Design, ``nothrow``, ...
  * (was noch?)

* `Standard Template Library: Containers
  <https://en.cppreference.com/w/cpp/container>`__

  * Überblick, Arten von Containern
  * Pointerarithmetik Wiederholung
  * Iteration mit ``for``
  * ``auto``
  * `Range based
    <https://en.cppreference.com/w/cpp/language/range-for>`__ ``for``

* `Standard Template Library: Algorithmen
  <https://en.cppreference.com/w/cpp/algorithm>`__

  * Überblick, Arten von Algorithmen
  * ``lambda``

* `Smart Pointer
  <https://en.cppreference.com/book/intro/smart_pointers>`__

  * ``unique_ptr``: explicit ownership transfer
  * ``shared_ptr``: shared ownership (a.k.a. loss of control)
  * ``weak_ptr``: subtle but simple

Tag 4
.....

Nun zu etwas einfachem: Threading :-)

* `Threads starten
  <https://en.cppreference.com/w/cpp/thread/thread>`__
* `Mutex <https://en.cppreference.com/w/cpp/thread/mutex>`__, Scoped
  Locking
* `Promise <https://en.cppreference.com/w/cpp/thread/promise>`__,
  `Future <https://de.cppreference.com/w/cpp/thread/future>`__, `Async
  <https://de.cppreference.com/w/cpp/thread/async>`__

Tag 5
.....

Der geplante Stoff der vergangenen vier Tage hat genug Entropie in
sich, um mit dem Ungesagten und Nochzusagenden den fünften Tag zu
füllen.

