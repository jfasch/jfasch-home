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

Log
---

Tag 1
.....

Variablen und Datentypen
````````````````````````

* :doc:`/trainings/material/soup/python/basics/python_0110_blahblah/topic`
* :doc:`/trainings/material/soup/python/basics/python_0120_helloworld/topic`

  * Hello World: `hello.py
    <https://github.com/jfasch/2022-01-17/blob/main/hello.py>`__
  * Commandline arguments: `argv.py
    <https://github.com/jfasch/2022-01-17/blob/main/argv.py>`__

* :doc:`/trainings/material/soup/python/basics/python_0130_syntax_etc/topic`

  * Indentation: `indentation.py
    <https://github.com/jfasch/2022-01-17/blob/main/indentation.py>`__

* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`

  * Overflow in C: `overflow.c
    <https://github.com/jfasch/2022-01-17/blob/main/overflow.c>`__

* :doc:`/trainings/material/soup/python/basics/python_0160_boolean/topic`
* :doc:`/trainings/material/soup/python/basics/python_0300_strings/topic`

  * Encoding: ``Liebe Grüße, Jörg`` in UTF-8 `umlaut-utf8.txt
    <https://github.com/jfasch/2022-01-17/blob/main/umlaut-utf8.txt>`__
  * Encoding: ``Liebe Grüße, Jörg`` in ISO-8859-1
    `umlaut-iso-latin-1.txt
    <https://github.com/jfasch/2022-01-17/blob/main/umlaut-iso-latin-1.txt>`__

* :doc:`/trainings/material/soup/python/exercises/herdt/swap`

  * Swap: `swap.py
    <https://github.com/jfasch/2022-01-17/blob/main/swap.py>`__
  * Swap, Pythonic version: `swap-pythonic.py
    <https://github.com/jfasch/2022-01-17/blob/main/swap-pythonic.py>`__

  .. image:: wacom-sketches/swap.png
     :scale: 50%

Kontrollstrukturen
``````````````````

* :doc:`/trainings/material/soup/python/basics/python_0170_if/topic`
* :doc:`/trainings/material/soup/python/exercises/herdt/max_numbers`

  * Maximum: `maximum.py
    <https://github.com/jfasch/2022-01-17/blob/main/maximum.py>`__
  * Maximum, Pythonic version `maximum-pythonic.py
    <https://github.com/jfasch/2022-01-17/blob/main/maximum-pythonic.py>`__

* :doc:`/trainings/material/soup/python/exercises/herdt/greet`

  * `greet.py <https://github.com/jfasch/2022-01-17/blob/main/greet.py>`__

Tag 2
.....

* :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`
* :doc:`/trainings/material/soup/python/exercises/herdt/exercise_while_even_numbers`

  * Straightforward (``while``): `even.py <https://github.com/jfasch/2022-01-17/blob/main/even.py>`__
  * Straightforward (using ``for``; slightly better): `even-for.py
    <https://github.com/jfasch/2022-01-17/blob/main/even-for.py>`__
  * Even-number *generator*: `even-yield.py
    <https://github.com/jfasch/2022-01-17/blob/main/even-yield.py>`__
  * Not programming anything, but rather using ``range()``'s
    *step-width* parameter: `even-ultimate-pythonicity.py
    <https://github.com/jfasch/2022-01-17/blob/main/even-ultimate-pythonicity.py>`__

* :doc:`/trainings/material/soup/python/exercises/legacy/while_primeness`

  .. image:: wacom-sketches/prime.png
     :scale: 50%

  * `prime.py <https://github.com/jfasch/2022-01-17/blob/main/prime.py>`__

* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/uniq_plain`

  * Sequential search in output list (bad): `uniq-sequential.py <https://github.com/jfasch/2022-01-17/blob/main/uniq-sequential.py>`__
  * Constant-time search in ``set`` (good): `uniq-set.py <https://github.com/jfasch/2022-01-17/blob/main/uniq-set.py>`__

* :doc:`/trainings/material/soup/python/exercises/legacy/cmdline_digit`

  * `digit.py <https://github.com/jfasch/2022-01-17/blob/main/digit.py>`__


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
.. .. .. jjj * :doc:`Meine Web-Tutorials </about/site/work-in-progress/web>`
.. .. .. jjj 


TODO
----

* :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`:
  explain "break and continue" in terms of "while-else" (right below)
* Link: `PHP: A Fractal of Bad Design <https://eev.ee/blog/2012/04/09/php-a-fractal-of-bad-design/>`__




