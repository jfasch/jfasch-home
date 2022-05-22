.. include:: <mmlalias.txt>


Neuerungen in C++11, C++14, C++17, C++20
========================================

.. contents::
   :local:

.. sidebar::

   **Material**

   * :doc:`/trainings/material/soup/cxx11/group`
   * :doc:`/trainings/material/soup/cxx/group` (unpolished, unsorted)

Agenda: Speisekarte
-------------------

.. list-table::
   :align: left
   :widths: auto

   * * ``+``
     * Wichtiges Thema (ausführliche Behandlung)
   * * ``O``
     * Weniger wichtiges Thema (kurzer Überblick reicht)
   * * ``-``
     * Unwichtiges Thema (Thema kann weggelassen werden)
   * * ``Ü``
     * Thema, zu dem auf jeden Fall eine Teilnehmerübung stattfinden
       soll

Neuerungen in C++ seit 2011
...........................

* Neuerungen in der Kernsprache

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Thema
       * jf
       * pr
     * * Neue Literale
       * ``0``
       *
     * * RValue Referenzen und move-Konstruktoren
       * ``+``
       *
     * * constexpr
       * ``0``
       *
     * * Initializer Listen
       * ``0``
       *
     * * Uniforme Initialisierung
       * ``0``
       *
     * * Type-Inference
       * ``0``
       *
     * * Range-basierte for Schleifen
       * ``0``
       *
     * * Lambdas und function<...>
       * ``Ü`` (-> threads)
       *
     * * Explizites overrides und final
       * ``+``
       *
     * * default und delete für spezielle Member-Funktionen
       * ``+``
       *
     * * Attribute
       * ``0``
       *
     * * Neuerungen bei der Template Programmierung
       * ``0``
       *

* Multithreading

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Thema
       * jf
       * pr
     * * Das C++11-Speichermodell
       * ``Ü``
       *
     * * Atomare Datentypen
       * ``Ü``
       *
     * * Threads und Tasks
       * ``Ü``
       *
     * * Mutex
       * ``Ü``
       *
     * * Thread-lokale Variablen
       * ``Ü``
       *

* Neuerungen in der Standardbibliothek

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Thema
       * jf
       * pr
     * * Smart Pointer
       * ``+``, ``Ü``
       *
     * * Reguäre Ausdrücke
       * ``-``
       *
     * * Type-Traits
       * ``+``
       *
     * * Zufallszahlen
       * ``-``
       *
     * * Zeitbibliothek
       * ``-``
       *
     * * Referenz-Wrapper
       * ``0``
       *
     * * Neue Container
       * ``0``
       *
     * * Neue Algorithmen
       * ``0``
       *

Neuerungen in C++ 14
....................

* Neuerungen in der Sprachsyntax

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Thema
       * jf
       * pr
     * * Neue Literale
       * ``-``
       *
     * * Function-Return Type-Deduction
       * ``0``
       *
     * * Erweiterungen zu constexpr
       * ``-``
       *
     * * Erweiterungen zu Lambdas und Capture-Expressions
       * ``0``
       *
     * * Templated Variables
       * ``0``
       *

* Multithreading

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Thema
       * jf
       * pr
     * * Shared Mutex
       * ``0``
       *

Neuerungen in C++ 17
....................

* Neuerungen in der Sprachsyntax

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Thema
       * jf
       * pr
     * * Geänderte auto Deduction aus { ... }-Listen
       * ``-``
       *
     * * Nested Namespace-Definitionen
       * ``0``
       *
     * * Neue Standard-Attribute
       * ``0``
       *
     * * Neuerungen bei der Template Programmierung
       * ``-``
       *
     * * constexpr if
       * ``0``
       *
     * * Structured Binding
       * ``0``
       *
     * * Inline Variablen
       * ``-``
       *

* Neuerungen in der Standardbibliothek

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Thema
       * jf
       * pr
     * * std::any / std::optional / std::variant
       * ``0``
       *
     * * Filesystem-Bibliothek
       * ``+``, ``Ü``
       *

Neuerungen in C++ 20 (Ausblick)
...............................

* Neuerungen in der Kernsprache

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Thema
       * jf
       * pr
     * * 3-Weg Vergleich mit operator <=>
       * ``0``
       *
     * * Zusatzvariable in range-based for statement
       * ``0``
       *
     * * Erweiterungen zu Lambdas
       * ``-``
       *
     * * Erweiterungen zu constexpr
       * ``-``
       *
     * * constinit
       * ``0``
       *
     * * Concepts für Templates
       * ``0`` (``-``)
       *
     * * Neue Attribute [[likely]] und [[unlikely]]
       * ``0``
       *

* Modularisierung und Versionierung

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Thema
       * jf
       * pr
     * * Version Header
       * ``-``
       *
     * * Module
       * ``-``
       *

* Multithreading

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Thema
       * jf
       * pr
     * * Revised Memory-Model
       * ``0`` (``-``)
       *
     * * Atomic Smart Pointer
       * ``0`` (``-``)
       *
     * * Atomic References
       * ``0`` (``-``)
       *
     * * Co-Routinen
       * ``0`` (``-``)
       *
     * * Synchronisierung-Werkzeuge
       * ``0`` (``-``)
       *

* Neuerungen in der Standardbibliothek

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Thema
       * jf
       * pr
     * * Text-Formatierung
       * ``-``
       *
     * * Kalender- und Zeitzonen-Zusätze zu chrono
       * ``-``
       *
     * * Range-Bibliothek
       * ``-``
       *
     * * std::span
       * ``-``
       *

Agenda: Entwurf
---------------

jjj flatten all out, into something that's an ordering of features
that I consider important. in order of descending importance.

Pythonicity to C++
..................

Emphasis on readability and writeability

Range Based for Loops
`````````````````````

 file:///tmp/jfasch-home/html/trainings/material/soup/cxx11/020-new-language-features/040-range-based-for/topic.html

* Depend on ``auto``
* Discuss ``auto&``, ``const auto&``, ...
* Live hacking example: iteration over ``map<k,v>``
* See also -> "Structured binding", depending on RBF

* While we are at it: loop-scope variable definition
* While we are at it: if-scope variable definition

auto Type Declarations
``````````````````````

 file:///tmp/jfasch-home/html/trainings/material/soup/cxx11/020-new-language-features/020-auto-type-declaration/topic.html

* Discussion: caveats, compiler errors, ...
* Bring live hacking examples accordingly

* Function return-type deduction (auto zum quadrat)

Things That Simply Deserved Fixing Since Ages
.............................................

file:///tmp/jfasch-home/html/trainings/material/soup/cxx11/020-new-language-features/group.html

Brace Initialization
````````````````````

file:///tmp/jfasch-home/html/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/topic.html

New OO keywords: override, final, default, delete
`````````````````````````````````````````````````

  * Live hacking: show motivation (C++03 lacking those), solution

Strongly Typed enum
```````````````````

file:///tmp/jfasch-home/html/trainings/material/soup/cxx11/020-new-language-features/010-strongly-typed-enums/topic.html

Delegating Constructor
``````````````````````

file:///tmp/jfasch-home/html/trainings/material/soup/cxx11/020-new-language-features/050-delegating-ctor/topic.html

Miscellaneous
`````````````

* ``nullptr`` file:///tmp/jfasch-home/html/trainings/material/soup/cxx11/020-new-language-features/070-miscellaneous/topic.html
* ``constexpr``: bring example

    * ``constexpr if`` (C++17)

  * User defined literals

* Raw Strings?

  * regex library excursion
  * python example
  * c++ example

Smart Pointers
..............

file:///tmp/jfasch-home/html/trainings/material/soup/cxx11/030-smart-pointers/group.html

* ``unique_ptr<>`` file:///tmp/jfasch-home/html/trainings/material/soup/cxx11/030-smart-pointers/020-unique-ptr/topic.html

  * Live hacking

    * show how the compiler helps you in ownership transfer
    * -> ``std::move<>``
    * -> see Moving, “RValue References”

* ``shared_ptr<>`` file:///tmp/jfasch-home/html/trainings/material/soup/cxx11/030-smart-pointers/030-shared-ptr/topic.html

  * Live hacking: caveat cyclic references

* ``weak_ptr<>`` NEU

Moving, “RValue References”
...........................

Probably the biggest and most important change

file:///tmp/jfasch-home/html/trainings/material/soup/cxx11/020-new-language-features/060-move/topic.html

* jjj Depend that on "Smart Pointers" (``unique_ptr<>`` and compiler
  errors "blah move blah")
* Live hacking

  * Use auto_ptr -> show weaknesses
  * Use && to implement "unique_ptr for the poor"

Functions (``std::bind<>``, ``std::function<>``, Lambdas)
.........................................................

jjj highlight difference between bind and function (polymorphic
vs. single-purpose-but-efficient), and show how lambda fits in (->
is-a function, basically)

* ``bind<>``
* ``function<>``
* Lambda NEU 

  * file:///tmp/jfasch-home/html/trainings/log/detail/2020-03-30/index.html?highlight=lambda
  * Bring in extensions from >11
  * Live hacking: caveat: dead references in capture
  * Exercise, preparing for threads group exercise

Multithreading
..............

file:///tmp/jfasch-home/html/trainings/material/soup/cxx11/050-multithreading/group.html

* file:///tmp/jfasch-home/html/trainings/material/soup/cxx11/050-multithreading/010-introduction/topic.html
* Locking and Atomics  file:///tmp/jfasch-home/html/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/topic.html

  * C++14 shared mutex

* Communication

  * Condition Variables
    file:///tmp/jfasch-home/html/trainings/material/soup/cxx11/050-multithreading/050-condition-variable/topic.html
  * ``promise<>`` and ``future<>`` NEU

Miscellaneous Libraries
.......................

* Solutions to the ``union`` problem

  * any, optional, variant (c++17)

* FS library excursions (next to threading maybe)

  * ``/`` operator

* ``chrono<>``

Miscellaneous
.............

* new containers and algorithms (next to beginning somewhere)
* attributes
* Templated variables?
* Nested namespace definitions (C++17)
* Template programming

  * Live hacking (hmmm)

    * two classes with compatible template methods
    * template function using those
    * maybe with type traits?


