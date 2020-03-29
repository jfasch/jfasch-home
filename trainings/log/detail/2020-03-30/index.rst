C++ für Embedded C Programmierer (30.3.2020 - 3.4.2020 Baden Württemberg) 
=========================================================================

.. toctree::
   :hidden:

   setup

Plan (sich entwickelnd)
-----------------------

.. sidebar:: *Kursinformation*

   **Beginn**

   Montag 30.3.2020, 8:00 (Martin lädt ein).

   **Vorbereitung, Übungen**

   * Bitte einen `Github <https://github.com/>`__ Account mitbringen,
     um an Übungen teilzunehmen. Diese werden in einem Private
     Repository stattfinden (Link folgt).
   * :doc:`Hier die Bauanleitung <setup>`; bitte wenn geht vorab
     ausprobieren (:doc:`Feedback </about/myself/contact>` sehr
     willkommen).

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
   * :download:`Unittesting
     </trainings/material/pdf/060-design-patterns-unittests.pdf>`
     (PDF)

   **Screenplays**

   * :doc:`/trainings/material/soup/unittest-gtest-basics-screenplay`
   * :doc:`/trainings/material/soup/unittest-gtest-cmake-screenplay`
   * :doc:`/trainings/material/soup/unittest-gtest-fixture-screenplay`
   * :doc:`/trainings/material/soup/c++-class-intro-screenplay`
   * :doc:`/trainings/material/soup/c++-dynamic-memory-screenplay`
   * :doc:`/trainings/material/soup/c++-ownership-raii-screenplay`
   * :doc:`/trainings/material/soup/c++-global-initialization-screenplay`
   * :doc:`/trainings/material/soup/c++-exercises-screenplay`

   **Sonstiges**

   * :doc:`setup`
   * :doc:`/blog/2020/03/ms-teams-on-linux`
   * `Googletest <https://github.com/google/googletest>`__

     * `Primer
       <https://github.com/google/googletest/blob/master/googletest/docs/primer.md>`__

Tag 1
.....

`Test Driven Development
<https://www.amazon.de/Test-Driven-Development-Example-Signature/dp/0321146530>`__
funktioniert (weiss ich, weil ich es selbst betreibe). Unittesting
(mit `googletest <https://github.com/google/googletest>`__) soll Teil
des Trainings sein, warum also nicht den Kurs invertieren und uns von
Tests treiben lassen (zumindest was die Übungen anbelangt)? Also:

* :doc:`/trainings/material/soup/unittest-gtest-basics-screenplay`
* :doc:`/trainings/material/soup/unittest-gtest-cmake-screenplay`
* :doc:`/trainings/material/soup/c++-class-intro-screenplay`
* :doc:`/trainings/material/soup/c++-dynamic-memory-screenplay`
* :doc:`/trainings/material/soup/c++-ownership-raii-screenplay`
* :doc:`/trainings/material/soup/c++-global-initialization-screenplay`
* :doc:`/trainings/material/soup/c++-exercises-screenplay`

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

* `"Big O" Notation
  <https://realpython.com/must-watch-pycon-talks/#6-big-o-how-code-slows-as-data-grows>`__

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

