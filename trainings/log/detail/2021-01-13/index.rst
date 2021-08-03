.. include:: <mmlalias.txt>

Programmierung Grundlagen (13. und 14.1.2021)
=============================================

.. sidebar:: *Training Information*

   **Start**

   Mittwoch 13.1.2021, 9:00

   **Offizielle Beschreibung**

   `tecTrain "Programmierung Grundlagen"
   <https://www.tectrain.at/seminare/seminar-themen/programmierung/programmierung-grundlagen>`__

   **Material**

   * PDF Slides, :download:`Python </trainings/material/pdf/300-python.pdf>`
   * :doc:`OpenTraining </about/site/opentraining/index>` Topics, :doc:`/trainings/material/soup/python/index`
   * Jupyter Notebook: :doc:`HTML <notebook-wrapper>`, :download:`download
     <Notebook.ipynb>`

.. toctree::
   :hidden:

   Jupyter Notebook (Übersicht) <notebook-wrapper>
   Jupyter Notebook <Notebook>

.. contents::
   :local:

Überblick
---------

* Dieses Dokument ist unser Leitfaden; Kommentare und ausgehende Links
  werden hier platziert.
* Themenreihenfolge und Übungen werden aus dem Herdt-Skriptum
  "Programmierung Grundlagen mit Beispielen in Python" übernommen.
* Das Herdt Skriptum ist etwas zu allgemein gehalten (geht auf
  Programmiersprachen im Allgemeinen ein, und ist dadurch verwirrend),
  weswegen in einigen Fällen Ausnahmen gemacht werden.
* Die Kurssprache ist Python; viele der Python-spezifische Elemente
  werden von :doc:`hier
  </trainings/material/soup/python/python-basics>` unterrichtet.
* Live-Hackereien des Trainers erfolgen in einem :doc:`gleichermaßen
  strukturierten Dokument <Notebook>`, einem sogenannten `Jupyter
  Notebook <https://jupyter.org/>`__.

Live-Hacking (Jupyter Notebook)
-------------------------------

* :doc:`Jupyter Notebook (Übersicht) <notebook-wrapper>`
* :doc:`Jupyter Notebook <Notebook>`
* :download:`Download <Notebook.ipynb>`

Struktur
--------

Herdt Kapitel 6: Grundlegende Sprachelemente
............................................

.. list-table::
   :widths: 50 50 100
   :align: left
   :header-rows: 1

   * - OpenTraining Topics
     - Herdt Kapitel
     - Kommentar
   * - :doc:`/trainings/material/soup/python/python_0110_blahblah/topic`
     - 
     - 
   * - :doc:`/trainings/material/soup/python/python_0120_helloworld/topic`
     - 
     - 
   * - :doc:`/trainings/material/soup/python/python_0130_syntax_etc/topic`
     - 6.1 Syntax und Semantik
     - Herdt zu allgemein/verwirrend
   * - :doc:`/trainings/material/soup/python/python_0130_syntax_etc/topic`
     - 6.2 Grundlegende Elemente einer Sprache
     - Herdt zu allgemein/verwirrend
   * - - :doc:`/trainings/material/soup/python/python_0150_datatypes_overview/topic`
       - :doc:`/trainings/material/soup/python/python_0160_boolean/topic`
       - :doc:`/trainings/material/soup/python/python_0300_strings/topic`
     - - 6.3 Standarddatentypen (elementare Datentypen)
       - 6.4 Literale für primitive Datentypen
     - - Meins: Python2/3 ignorieren (besser gleich endgültig
         rauslöschen)
   * -
     - 6.5 Variablen und Konstanten
     - *Konstanten* gibts nicht in Python, nur *immutable*
       Typen. Siehe dazu das Kapitel nach "8.1 Warum werden
       Datenstrukturen benötigt?"
   * - 
     - 6.6 Operatoren
     - Bereits bei den Datentypen angeschnitten. Hier als Vertiefung
       nocheinmal.
   * - 
     - 6.7 Ausdrücke und Operatorrangfolgen
     - Bereits bei den Datentypen angeschnitten. Hier als Vertiefung
       nocheinmal.
   * - :doc:`/trainings/material/soup/python/exercises/python_0165_exercises/exercise_variable`
     - 6.8 Übungen
     - - Übung 1: Arbeiten mit grundlegenden Sprachelementen

         - **1** lassen wir aus, da von Funktionen noch nicht die Rede
	   war.
	 - **4** lassen wir aus, da wir Syntaxdiagramme gespritzt
           haben.

       - Übung 2: wird gemacht (siehe :doc:`hier
         </trainings/material/soup/python/exercises/python_0165_exercises/exercise_variable>`)

Herdt Kapitel 7: Kontrollstrukturen
...................................

Verzweigung
```````````

Das gesamte Kapitel im Herdt Skriptum ist etwas sperrig
gehalten. Meins ist nicht etwa besser, sondern nützt einfach den
Effekt aus, dass menschliche Sprache leicht in Python abzubilden ist
:-)

Also: aus meinem Skriptum
:doc:`/trainings/material/soup/python/python_0170_if/topic`, und die
Übungen von Herdt. Siehe dazu die folgende Tabelle.

.. list-table::
   :align: left
   :widths: 50 50 100
   :header-rows: 1

   * - OpenTraining Topics
     - Herdt Kapitel
     - Kommentar
   * - 
     - 7.1 Anweisungen und Folgen
     - - Im Großen und Ganzen für die Fisch (zu allgemein und
         verwirrend)
       - Das VAT Beispiel am Ende ist recht instruktiv
   * - 
     - 7.2 Bedingungen und Kontrollstrukturen
     - - Beispiele (sehr instruktiv)
       - Kontrollstrukturen Überblick
   * - 
     - 7.3 Grundlagen zu Verzweigungen
     - Bullshit
   * - :doc:`/trainings/material/soup/python/python_0170_if/topic`
     - 7.4 Bedingte Anweisung
     - Sperrige Formulierungen bei Herdt
   * - :doc:`/trainings/material/soup/python/python_0170_if/topic`
     - 7.5 Verzweigung
     - Sperrige Formulierungen bei Herdt
   * - :doc:`/trainings/material/soup/python/python_0170_if/topic`
     - 7.6 Geschachtelte Verzweigung
     - Sperrige Formulierungen bei Herdt
   * - :doc:`/trainings/material/soup/python/python_0170_if/topic`
     - 7.7 Mehrfache Verzweigung (Fallauswahl)
     - Sperrige Formulierungen bei Herdt
   * - * :doc:`/trainings/material/soup/python/exercises/python_0190_exercises/exercise_max_numbers`
       * :doc:`/trainings/material/soup/python/exercises/python_0190_exercises/exercise_greet`
       * :doc:`/trainings/material/soup/python/exercises/python_0190_exercises/exercise_username_password`
     - 7.15 Übungen
     - - Übung 1: Verzweigung
       - Übung 2: Geschachtelte Verzweigung
       - Übung 3: Benutzereingaben überprüfen

Schleifen
`````````

Da die Schleifenkonstrukte über verschiedenene Sprachen hinweg sehr
unterschiedlich sind, lassen wir hier das Herdt-Skriptum weitgehend
ausser Acht. Es ist zu allgemein gehalten, um bei unserem Vehikel
*Python* hilfreich zu sein.

.. list-table::
   :align: left
   :widths: 50 50 100
   :header-rows: 1

   * - OpenTraining Topics
     - Herdt Kapitel
     - Kommentar
   * - 
     - 7.8 Schleifen
     - - Einstieg über Herdt, dann weiter bei mir
       - Klarstellung (am Ende des Kapitels): fußgesteuerte Schleifen
         gibts in Python nicht
   * - 
     - 7.9 Zählergesteuerte Schleifen (Iteration)
     - Auslassen
   * - :doc:`/trainings/material/soup/python/python_0193_while/topic`
     - 7.10 Kopfgesteuerte bedingte Schleife
     - Meins gewinnt
   * - * :doc:`/trainings/material/soup/python/exercises/python_0195_exercises/exercise_while_primeness`
       * :doc:`/trainings/material/soup/python/exercises/python_0195_exercises/exercise_while_even_numbers`
     -
     - 7.15 Übungen
       - Übung 4: Gerade Zahlen in der Konsole anzeigen
       - :doc:`/trainings/material/soup/python/exercises/python_0195_exercises/exercise_while_primeness`
   * - 
     - 7.11 Fußgesteuerte bedingte Schleife
     - Auslassen (gibts nicht in Python)
   * - :doc:`/trainings/material/soup/python/python_0200_sequential_types/topic`
     - (jf) Sequential Datatypes
     - Als Voraussetzung für ``for``
   * - :doc:`/trainings/material/soup/python/python_0220_for/topic`
     - 
     - ``for`` Loop ist bei Herdt nicht so gut. Livehacking, Iteration
       über

       * Liste
       * String
       * Dictionary (als Ausblick)
       
   * - :doc:`/trainings/material/soup/python/python_0225_range/topic`
     - 
     -
   * - :doc:`/trainings/material/soup/python/exercises/python_0230_exercises/exercise_for_primeness`
     - 
     - 
   * - 
     - 7.12 Schnellübersicht
     - Auslassen
   * - 
     - 7.13 Sprunganweisungen
     - Auslassen
   * - 
     - 7.14 Endlosschleifen
     - Auslassen

Herdt Kapitel 8: Elementare Datenstrukturen
...........................................

.. list-table::
   :align: left
   :widths: 50 50 100
   :header-rows: 1

   * - OpenTraining Topics
     - Herdt Kapitel
     - Kommentar
   * - 
     - 8.1 Warum werden Datenstrukturen benötigt?
     - Naja mal reinschauen, eher mager
   * - :doc:`/trainings/material/soup/python/python_0150_datatypes_overview_compound/topic`
     - 
     - Compound Datatypes: Überblick
   * - :doc:`/trainings/material/soup/python/python_0250_refs_flat_deep_copy/topic`
     -
     - Als Ersatz für das ausgelassene Kapitel "6.5 Variablen und
       Konstanten"
   * - 
     - 8.2 Arrays
     - Auslassen (Java)
   * - 
     - 8.3 Eindimensionale Arrays
     - Auslassen (Java)
   * - 
     - 8.4 Records
     - Auslassen: siehe 8.7 Dictionaries, gefolgt von ``class`` und
       ``namedtuple``
   * - - :doc:`/trainings/material/soup/python/python_0300_strings/topic` (Wiederholung)
       - :doc:`/trainings/material/soup/python/python_0320_strings_methods/topic`
       - :doc:`/trainings/material/soup/python/python_0310_strings_formatting/topic`
     - 8.5 Zeichenketten
     - Vielleicht eine kurze Livehacking Session *f-Strings*
   * - :doc:`/trainings/material/soup/python/python_0400_lists/topic`
     - 8.6 Tupel und Listen
     - Meins
   * - :doc:`/trainings/material/soup/python/python_0450_dictionaries/topic`
     - 8.7 Dictionaries
     - Meins
   * -
     - (jf) Records in Python
     - Jupyter notebook: Records von oben mit Dictionaries

       - Livehacking Demo von ``class``
       - ``from collections import namedtuple``

   * - :doc:`/trainings/material/soup/python/python_0460_sets/topic`
     - 8.8 Mengen
     - Meins
   * - 
     - 8.9 Besondere Datenstrukturen anhand von Stapel (Stack) und
       Schlangen (Queue)
     - Wenns passt vom Tempo, schauma da rein. Vielleicht fallt eine
       gscheite Übung ab.
   * - 
     - 8.10 Übungen
     - Gemeinsam drüber schauen

       * Übung 1. Siehe
	 :doc:`Jupyter Notebook, Kapitel 8.10 </trainings/log/detail/2021-01-13/notebook-wrapper>`; dort
	 wird auf eine Vielzahl von Lösungsmöglichkeiten
         eingegangen. *Bitte spezielle die Variante mit ``enumerate()``
         beachten, diese ist die Pythonischste*.

Herdt Kapitel 9: Methoden, Prozeduren und Funktionen
....................................................

Diese Abteilung wurde hauptsächlich im :doc:`Jupyter Notebook
</trainings/log/detail/2021-01-13/notebook-wrapper>` bestritten.

.. list-table::
   :align: left
   :widths: 50 50 100
   :header-rows: 1

   * - OpenTraining Topics
     - Herdt Kapitel
     - Kommentar
   * - :doc:`/trainings/material/soup/python/python_0270_functions/topic`
     -
     - Funktionen und Scope
   * -
     -
     - Übungen
       
       * ``maximum()`` (nein, das steht im Skriptum :-) )
       * Primzahl

   * - 
     - 9.1 Unterprogramme
     - Auslassen
   * - 
     - 9.2 Parameterübergabe
     - Auslassen
   * - 
     - 9.3 Parameterübergabe als Wert
     - Auslassen
   * - 
     - 9.4 Parameterübergabe über Referenzen
     - Auslassen
   * - 
     - 9.5 Rückgabewerte von Funktionen oder Methoden
     - Auslassen
   * - 
     - 9.6 Innere Funktionen - Closures
     - Auslassen
   * - 
     - 9.7 Standardbibliotheken und Built-in-Funktionalitäten
     - Auslassen
   * - * :doc:`/trainings/material/soup/python/exercises/python_0275_exercises/exercise_max_numbers_function`
       * :doc:`/trainings/material/soup/python/exercises/python_0275_exercises/exercise_primeness_function`
     - 9.8 Übungen
     - U.U. nimmt man die Übungen aus ``if``/Verzweigung her
       (Beispiel: Übung 1 dort will, dass man das Maximum zweier
       Zahlen berechnet |longrightarrow| Funktion ``maximum()``)

Links
-----

* `PEP 20 - The Zen of Python
  <https://www.python.org/dev/peps/pep-0020/>`__
* `Corey Schaefer's Youtube Channel
  <https://www.youtube.com/channel/UCCezIgC97PvUuR4_gbFUs5g>`__

  Corey Schaefer ist ein Python Trainer/Hacker, der eine schier
  unendliche Anzahl von sehr guten Tutorials (im Live-Hacking Stil) im
  Repertoire hat, eines besser als das andere. Hier eine Auswahl.

  * .. raw:: html

       <iframe
           width="560" 
	   height="315" 
	   src="https://www.youtube.com/embed/QVdf0LgmICw" 
	   frameborder="0" 
	   allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	   allowfullscreen>
       </iframe>

  * .. raw:: html

       <iframe
           width="560" 
	   height="315" 
	   src="https://www.youtube.com/embed/CqvZ3vGoGs0" 
	   frameborder="0" 
	   allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	   allowfullscreen>
       </iframe>

  * .. raw:: html

       <iframe
           width="560"
	   height="315" 
	   src="https://www.youtube.com/embed/jTYiNjvnHZY" 
	   frameborder="0" 
	   allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	   allowfullscreen>
       </iframe>

  * .. raw:: html

       <iframe
           width="560" 
	   height="315" 
	   src="https://www.youtube.com/embed/bD05uGo_sVI" 
	   frameborder="0" 
	   allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	   allowfullscreen>
       </iframe>

* Raymond Hettinger hat den Satz geprägt, "There must be a better
  way!"

  Hettinger ist ein Python Core Developer, und gibt von Zeit zu Zeit
  Talks auf Konferenzen. Hier der Talk mit dem Satz; definitiv
  sehenswert, wenn man weiter in Python rein will.

  .. raw:: html

     <iframe
         width="560" 
	 height="315" 
	 src="https://www.youtube.com/embed/anrOzOapJ2E" 
	 frameborder="0" 
	 allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	 allowfullscreen>
     </iframe>

* `David Beazley
  <https://www.youtube.com/channel/UCbNpPBMvCHr-TeJkkezog7Q>`__,
  definitiv nichts für Anfänger, aber dafür hochinteressant und
  lustig.

  Hier ein typisches Video von ihm:

  .. raw:: html

     <iframe
         width="560" 
	 height="315" 
	 src="https://www.youtube.com/embed/sPiWg5jSoZI" 
	 frameborder="0" 
	 allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	 allowfullscreen>
     </iframe>
