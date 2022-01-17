.. include:: <mmlalias.txt>

Programmierung Grundlagen, anhand von Python (2022-01-17 - 2022-01-10)
======================================================================

.. sidebar:: *Training Information*

   **Offizielle Beschreibung**

   `tecTrain "Programmierung Grundlagen"
   <https://www.tectrain.at/seminare/seminar-themen/programmierung/programmierung-grundlagen>`__

   **Material**

   * :doc:`/trainings/material/soup/python/basics/group`
   * Herdt vs. Python: :doc:`hier </trainings/repertoire/python/herdt>`.
   * `Github Repository <https://github.com/jfasch/2022-01-17>`__

.. contents::
   :local:

Überblick
---------

Die Kurssprache des Kurses "Programmierung Grundlagen" ist Python;
viele der Python-spezifische Elemente werden von :doc:`hier
</trainings/material/soup/python/basics/group>` unterrichtet.

Themenreihenfolge und Übungen werden aus dem Herdt-Skriptum
"Programmierung Grundlagen mit Beispielen in Python" übernommen.

Das Herdt Skriptum ist etwas zu allgemein gehalten (geht auf
Programmiersprachen im Allgemeinen ein, und ist dadurch verwirrend),
weswegen in vielen Fällen Ausnahmen gemacht werden. Siehe :doc:`hier
</trainings/repertoire/python/herdt>` für eine Zuordnung zu meinen
Python Unterlagen.

Jupyter Notebook
----------------

* :doc:`Structure <notebook-wrapper>`
* :doc:`Whole notebook <notebook>`

Agenda
------

Variablen und Datentypen
........................

**Stoff**

* :doc:`/trainings/material/soup/python/basics/python_0110_blahblah/topic`
* :doc:`/trainings/material/soup/python/basics/python_0120_helloworld/topic`
* :doc:`/trainings/material/soup/python/basics/python_0130_syntax_etc/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/basics/python_0160_boolean/topic`
* :doc:`/trainings/material/soup/python/basics/python_0300_strings/topic`

**Übungen**

* :doc:`/trainings/material/soup/python/exercises/herdt/swap`

  .. .. jjjj rename exercise to something like "swap"

  .. .. jjjj extract herdt exercises into separate group

  .. image:: wacom-sketches/swap.png
     :scale: 50%


Kontrollstrukturen
``````````````````

**Stoff**

* :doc:`/trainings/material/soup/python/basics/python_0170_if/topic`

**Übungen**

* :doc:`/trainings/material/soup/python/exercises/herdt/max_numbers`
* :doc:`/trainings/material/soup/python/exercises/herdt/greet`

**Stoff**

* :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`

**Übungen**

* :doc:`/trainings/material/soup/python/exercises/herdt/exercise_while_even_numbers`
* :doc:`/trainings/material/soup/python/exercises/legacy/while_primeness`

  .. image:: wacom-sketches/prime.png
     :scale: 50%


.. .. .. jjj Log
.. .. .. jjj ---
.. .. .. jjj 
.. .. .. jjj Tag 1
.. .. .. jjj .....
.. .. .. jjj 
.. .. .. jjj **Vorab**: bissl Livehacking
.. .. .. jjj 
.. .. .. jjj * `Hello World <https://github.com/jfasch/2021-08-02/blob/master/live-hacking/hello.py>`__
.. .. .. jjj * `Commandlineargumente <https://github.com/jfasch/2021-08-02/blob/master/live-hacking/args.py>`__
.. .. .. jjj * `Input/Prompt <https://github.com/jfasch/2021-08-02/blob/master/live-hacking/input.py>`__
.. .. .. jjj 
.. .. .. jjj 
.. .. .. jjj Kontrollstrukturen
.. .. .. jjj ``````````````````
.. .. .. jjj 
.. .. .. jjj **Stoff**
.. .. .. jjj 
.. .. .. jjj * :doc:`/trainings/material/soup/python/basics/python_0170_if/topic`
.. .. .. jjj 
.. .. .. jjj **Übungen**
.. .. .. jjj 
.. .. .. jjj * :doc:`/trainings/material/soup/python/exercises/herdt/max_numbers` (`livehacked <https://github.com/jfasch/2021-08-02/blob/master/live-hacking/maximum.py>`__)
.. .. .. jjj * :doc:`/trainings/material/soup/python/exercises/herdt/greet` (`livehacked <https://github.com/jfasch/2021-08-02/blob/master/live-hacking/greeting.py>`__)
.. .. .. jjj 
.. .. .. jjj **Stoff**
.. .. .. jjj 
.. .. .. jjj * :doc:`/trainings/material/soup/python/basics/python_0193_while/topic` (das
.. .. .. jjj   Summenbeispiel `live-gehackt
.. .. .. jjj   <https://github.com/jfasch/2021-08-02/blob/master/live-hacking/sum.py>`__)
.. .. .. jjj 
.. .. .. jjj **Übungen**
.. .. .. jjj 
.. .. .. jjj * :doc:`/trainings/material/soup/python/exercises/herdt/exercise_while_even_numbers`
.. .. .. jjj * :doc:`/trainings/material/soup/python/exercises/legacy/while_primeness`
.. .. .. jjj 
.. .. .. jjj   .. image:: wacom-sketches/prime.png
.. .. .. jjj      :scale: 50%
.. .. .. jjj 
.. .. .. jjj Tag 2
.. .. .. jjj .....
.. .. .. jjj 
.. .. .. jjj **Stoff**
.. .. .. jjj 
.. .. .. jjj * :doc:`/trainings/material/soup/python/basics/python_0270_functions/topic`
.. .. .. jjj 
.. .. .. jjj **Übungen**
.. .. .. jjj 
.. .. .. jjj * :doc:`/trainings/material/soup/python/exercises/legacy/max_numbers_function`
.. .. .. jjj 
.. .. .. jjj **Stoff**
.. .. .. jjj 
.. .. .. jjj * :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
.. .. .. jjj * :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
.. .. .. jjj * :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`
.. .. .. jjj * :doc:`/trainings/material/soup/python/basics/python_0460_sets/topic`
.. .. .. jjj 
.. .. .. jjj **Showcasing "Full Stack Development"**
.. .. .. jjj 
.. .. .. jjj .. image:: wacom-sketches/fullstack.png
.. .. .. jjj    :scale: 70%
.. .. .. jjj 
.. .. .. jjj .. toctree::
.. .. .. jjj 
.. .. .. jjj    notebook
.. .. .. jjj 
.. .. .. jjj Links
.. .. .. jjj -----
.. .. .. jjj 
.. .. .. jjj * `PHP: A Fractal of Bad Design <https://eev.ee/blog/2012/04/09/php-a-fractal-of-bad-design/>`__
.. .. .. jjj * :doc:`Meine Web-Tutorials </about/site/work-in-progress/web>`
.. .. .. jjj 
