C++ für Embedded C Programmierer (30.3.2020 - 3.4.2020 Baden Württemberg) 
=========================================================================

.. toctree::
   :hidden:

   cmake/index
   gtest/basics-screenplay
   gtest/cmake-screenplay

Plan (sich entwickelnd)
-----------------------

.. sidebar:: *Material*

   **Schulungsbeschreibungen**

   * :doc:`C Einführung </trainings/repertoire/c>`
   * :doc:`C Advanced </trainings/repertoire/c-advanced>`
   * :doc:`C++ </trainings/repertoire/cxx>`
   * :doc:`CMake </trainings/repertoire/cmake>`

   **Folien**

   * :download:`C </trainings/material/pdf/050-c.pdf>` (PDF)
   * :download:`C++03 </trainings/material/pdf/055-c++03.pdf>` (PDF)
   * :download:`C++11 </trainings/material/pdf/056-c++11.pdf>` (PDF)
   * :download:`CMake </trainings/material/pdf/045-cmake.pdf>` (PDF)

   **Screenplays**

   * :doc:`gtest/basics-screenplay`
   * :doc:`gtest/cmake-screenplay`

   **Sonstiges**

   * :doc:`Bauen der Seite mit CMake <cmake/index>`
   * :doc:`/blog/2020/03/ms-teams-on-linux`

Tag 1
.....

`Test Driven Development
<https://www.amazon.de/Test-Driven-Development-Example-Signature/dp/0321146530>`__
funktioniert (weiss ich, weil ich es selbst betreibe). Unittesting
(mit `googletest <https://github.com/google/googletest>`__) soll Teil
des Trainings sein, warum also nicht den Kurs invertieren und uns von
Tests treiben lassen (zumindest was die Übungen anbelangt)? Also:

* :doc:`Livehacking: Einführung in Unittesting
  <gtest/basics-screenplay>`, mittels `googletest
  <https://github.com/google/googletest>`__
* Klassen, Members ... C++ Basics
* Konstruktoren, Destruktoren, am Beispiel Memoryleak.
* `Auffinden von Leaks mit valgrind <https://valgrind.org/>`__
* `RAII <https://en.cppreference.com/w/cpp/language/raii>`__
* Methoden, ``this``
* ``<iostream>``, zumindest rudimentär
* :doc:`CMake <cmake/index>` im Vorbeigehen, sobald der angehäufte C++
  Code zu gross wird. Eher früher als später.

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
  * Globale Objekte, Abhängigkeiten: *Vorsicht!*
  * Globale Objekte, cool: *Der Init Trick*
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
* `Atomics <https://en.cppreference.com/w/cpp/atomic/atomic>`__
* `Promise <https://en.cppreference.com/w/cpp/thread/promise>`__,
  `Future <https://de.cppreference.com/w/cpp/thread/future>`__, `Async
  <https://de.cppreference.com/w/cpp/thread/async>`__

Tag 5
.....

Der geplante Stoff der vergangenen vier Tage hat genug Entropie in
sich, um mit dem Ungesagten und Nochzusagenden den fünften Tag zu
füllen.

