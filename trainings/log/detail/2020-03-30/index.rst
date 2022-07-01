C++ für Embedded C Programmierer (30.3.2020 - 3.4.2020 Baden Württemberg) 
=========================================================================

.. toctree::
   :hidden:

   setup
   install-googletest
   vs-code
   code/exercise-string/index

.. sidebar:: *Kursinformation*

   .. contents::
      :local:

   **Beginn**

   Montag 30.3.2020, 8:00

   **Vorbereitung, Übungen**

   * Bitte einen `Github <https://github.com/>`__ Account mitbringen,
     um an Übungen teilzunehmen. Diese werden in einem Private
     Repository stattfinden (Link folgt). Siehe hierzu die
     :doc:`Privatheitsrichtlinien </trainings/codex>`.
   * :doc:`Hier die Bauanleitung <setup>`; bitte wenn geht vorab
     ausprobieren (:doc:`Feedback </about/myself/contact>` sehr
     willkommen).

   **Schulungsbeschreibungen**

   * :doc:`C Einführung </trainings/repertoire/c-like/c>`
   * :doc:`C Advanced </trainings/repertoire/c-like/c-advanced>`
   * :doc:`C++ </trainings/repertoire/c-like/cxx>`
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

   * :doc:`/trainings/material/soup/unittest/unittest_gtest_basics/screenplay`
   * :doc:`/trainings/material/soup/unittest/unittest_gtest_cmake/screenplay`
   * :doc:`/trainings/material/soup/unittest/unittest_gtest_fixture/screenplay`
   * :doc:`/trainings/material/soup/cxx/cxx_dynamic_memory/screenplay`
   * :doc:`/trainings/material/soup/cxx/cxx_ownership_raii/screenplay`
   * :doc:`/trainings/material/soup/cxx/cxx_global_initialization/screenplay`
   * :doc:`/trainings/material/soup/cxx/cxx_stl_container_intro/screenplay`

   **Links**

   * C++ Online Reference: `hier <http://www.cplusplus.com/>`__ oder
     `hier <https://en.cppreference.com>`__
   * `Scott Meyers: Effective Modern C++
     <https://www.oreilly.com/library/view/effective-modern-c/9781491908419/>`__
   * `Git Book <https://git-scm.com/book/en/v2>`__
     <https://git-scm.com/book/en/v2/Distributed-Git-Distributed-Workflows>`__.
   * `Googletest <https://github.com/google/googletest>`__, `Primer
     <https://github.com/google/googletest/blob/master/googletest/docs/primer.md>`__

   **Sonstiges**

   * :doc:`setup`
   * :doc:`install-googletest`
   * :doc:`vs-code`
   * :doc:`/blog/2020/03/ms-teams-on-linux`

Kursaufbau
----------

`Test Driven Development bzw. Unittesting
<https://www.amazon.de/Test-Driven-Development-Example-Signature/dp/0321146530>`__
ist Teil der Kursanforderung, ergänzend zu den C++-Themen.

Lasst uns also den Kursverlauf testgetrieben entwickeln dort, wo es
Sinn macht.

* Die meisten der Livehacking Demos können als Testcases gestaltet
  werden.
* Übungen erst recht; der Trainer formuliert die Aufgabe als
  Unittest - die Teilnehmer hacken - alle diskutieren - nächste
  Iteration ...

Kursverlauf
-----------

Im folgenden eine Niederschrift des Geschehenen. Übungen und
Live-Hacking-Demos des Trainers sind im zur Seite gehörenden
Git-Repository (bzw. eines Clones in einem privaten
Github-Respository) entwickelt worden. 

Die Code-Integration mit HTML verläuft noch nicht ideal, sodass man
den Code hier nicht ansehen kann. Bitte dazu das :doc:`Repo clonen
<setup>`. Wann immer im folgenden Code erwähnt wird, ist dieser im
zugehörigen Clone in dem Subdirectory zu finden, das der URL im
URL-Bar entspricht. Hier also
``<clone-root>/trainings/log/detail/2020-03-30/code/``.

Tag 1
.....

Ein nicht unbeträchtlicher Teil des Tages wurde dafür verwendet, um
das `Google Test Framework <https://github.com/google/googletest>`__
auf Ubuntu 16.04 LTS (mit GCC5 als System-Compiler) zum Laufen zu
bekommen. Daraus entstanden ist :doc:`eine Installationsanleitung
<install-googletest>`.

* Code: ``code/gtest-basics/``. Live-Hacking, GTest und Test Driven
  Development. Anfangs ohne CMake mit direkter Toolchain-Benutzung,
  dann Migration auf CMake.

  * Zuerst drei separate Test-Executables:
    ``code/gtest-basics/fail.cc``, ``code/gtest-basics/non-fatal.cc``,
    ``code/gtest-basics/simple.cc``.
  * Dann eine Aggregation *durch den Linker* (bitte
    ``code/gtest-basics/CMakeLists.txt`` ansehen) aller Testcases in
    *ein einzelnes* Executable.

Tag 2
.....

* Klassen (Einführung): Konstruktoren, Methoden, Referenzen, ``const``

  * Code: ``code/class-basics/``. "Point" Klasse (Live-Hacking)
  
    * Zuerst in C als ``struct``
    * C++ Äquivalent als ``class``
    * ``const`` bei Parameter-Übergabe
    * ``const`` Methoden
    * Langsames Ausbauen: Operator Overloading
    
* Dynamisches Memory, ``code/dynmem-ownership/``

  * ``code/dynmem-ownership/dynmem-tests.cc``. Eine Reihe von Tests,
    um zu demonstrieren, wie in C und in C++ dynamisch alloziert
    wird. ``malloc()``/``free()`` vs. ``new``/``delete``
    vs. ``new[]``/``delete[]``
  * *Ownership*, bzw. RAII (*Resource Acquisition is Initialization*).
  * Verwenden von Konstruktor und Destruktor, um Memory-Fehler zu
    vermeiden. Siehe dazu
    ``code/dynmem-ownership/ownership-ctor-dtor.cc``
  * Benutzung von ``valgrind``
  * Ausflug: ``std::string``, ``size()`` und ``capacity()``. Siehe
    ``code/dynmem-ownership/string-demo.cc``


Tag 3
.....

* Diskussion: "Temporary Objects"
  (``code/class-basics/temporaries-demo.cc``)
* Copy Konstruktor, Assignment operator
* :doc:`code/exercise-string/index`
  
  * *Copy Constructor* und *Assignment Operator*
  * Zum Teufel: **Self Assignment**
  * Code: ``code/exercise-string/``
  
* Viel Diskussion

Tag 4
.....

* Diskussion (Code: ``code/static-vs-inline/``): ``static``
  (File-Scope), und was hat das zu tun mit ``inline``?
* Pointer-Datentypen (Unittest: ``code/smart-pointers/ownership.cc``).
  ``std::shared_ptr<>`` (Shared Ownership) und ``std::unique_ptr<>``
  (Exclusive Ownership), demonstriert anhand einer
  Manager/Employee/Testcase Beziehung.
* Vorgriff auf STL (Code: ``code/smart-pointers/lt-sort.cc``):
  sortieren von ``EmployeeRecord``s in einem ``std::vector`` nach
  verschiedenen Kriterien.
* Templates Intro (Code: ``class-template/``): ``class Point`` mit
  parametrisierbarem Koordinatentyp

Tag 5
.....

* STL Containers (Code: ``code/stl-container/``, Slides:
  :download:`C++03 (PDF) </trainings/material/pdf/055-c++03.pdf>`, 102ff)

  * Überblick, Arten von Containern
  * Pointerarithmetik Wiederholung
  * Iteratoren, Iteration mit ``for``
  * Demos

    * ``std::vector`` (``code/vector.cc``).
    * ``std::list`` (``code/list.cc``)
    * ``std::map`` (``code/map.cc``)

  * Diskussion: Laufzeitverhalten, `O-Notation
    <https://realpython.com/must-watch-pycon-talks/#6-big-o-how-code-slows-as-data-grows>`__

  * C++11 Verbesserungen gegenüber C++03 (Slides: :download:`C++11
    (PDF) </trainings/material/pdf/056-c++11.pdf>`, 6ff)

    * ``auto``
    * `Range based
      <https://en.cppreference.com/w/cpp/language/range-for>`__
      ``for``

* ``lambda``. Siehe

  * ``code/stl-container/sort-is-n-log-n.cc``. Gegenüberstellung
    explizite Funktion vs. Lambda.
  * ``code/stl-container/vector.cc``: ``TEST(Vector,
    Sort_Algorithm_Reverse_Lambda)``
  * ``code/stl-container/threads.cc``

* Vererbung vs. Templates. Fallstudie, livegehackt. Wir haben einen
  Sensor ``Thermometer``, der über SPI angebunden ist, und auf den
  komplexe Stücke Software aufbauen. Nun will ein Kunde, dass wir
  einen vergleichbaren über I2C anbinden. Zwei Möglichkeiten, und
  Diskussion,

  * Vererbung (Code: ``code/inheritance-interfaces-virtual/``)
  * Templates (Code: ``code/inheritance-morph-to-templates/``)

* Exceptions wurden nicht explizit als eigenes Kapitel behandelt und
  quasi im Vorbeigehen erklärt.






