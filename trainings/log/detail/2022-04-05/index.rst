.. include:: <mmlalias.txt>


Programmierung Grundlagen, anhand von Python (2022-04-05 - 2022-04-08)
======================================================================

.. sidebar:: *Training Information*

   **Offizielle Beschreibung**

   `tecTrain "Programmierung Grundlagen"
   <https://www.tectrain.at/seminare/seminar-themen/programmierung/programmierung-grundlagen>`__

   **Material**

   * :doc:`/trainings/material/soup/python/basics/index`
   * `Github Repository <https://github.com/jfasch/2022-04-05>`__

   **Notebook**

   * :doc:`Structure <notebook-wrapper>`
   * :doc:`Whole notebook <notebook>`
   * :download:`Download <notebook.ipynb>`

   **Successor Training**

   * :doc:`../2022-04-25/index`

.. contents::
   :local:

Überblick
---------

Die Kurssprache des Kurses "Programmierung Grundlagen" ist Python;
viele der Python-spezifische Elemente werden von :doc:`hier
</trainings/material/soup/python/basics/index>` unterrichtet.

Log
---

Tag 1
.....

Variablen und Datentypen
````````````````````````

* :doc:`/trainings/material/soup/python/basics/python_0110_blahblah/topic`
* :doc:`/trainings/material/soup/python/basics/python_0120_helloworld/topic`
* :doc:`/trainings/material/soup/python/basics/python_0130_syntax_etc/topic`
* :doc:`/trainings/material/soup/python/basics/python_0139_commandline_argv/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/basics/python_0160_boolean/topic`
* :doc:`/trainings/material/soup/python/basics/python_0300_strings/topic`
* :doc:`/trainings/material/soup/python/exercises/herdt/swap`

  * `swap.py <https://github.com/jfasch/2022-04-05/blob/main/exercises/joerg/swap.py>`__
  * `swap-pythonic.py <https://github.com/jfasch/2022-04-05/blob/main/exercises/joerg/swap-pythonic.py>`__

  .. image:: swap.png
     :scale: 40%

Kontrollstrukturen
``````````````````

* :doc:`/trainings/material/soup/python/basics/python_0170_if/topic`
* :doc:`/trainings/material/soup/python/exercises/herdt/max_numbers`

  * `maximum.py <https://github.com/jfasch/2022-04-05/blob/main/exercises/joerg/maximum.py>`__

Discussion: Flow Charts?
````````````````````````

Which one is more clear?

.. list-table::
   :align: left
   :widths: auto

   * * .. image:: flowchart.png
          :scale: 40%
     * .. code-block:: python

          i = 0
          sum = 0
          
          while i < 100:
              sum += i
              i += 1
          
          print(sum)

Tag 2
.....

* :doc:`/trainings/material/soup/python/exercises/herdt/greet`

  * `greet.py
    <https://github.com/jfasch/2022-04-05/blob/main/exercises/joerg/greet.py>`__

* :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`

  * Explaining ``break``: `rolling-dice.py
    <https://github.com/jfasch/2022-04-05/blob/main/exercises/joerg/rolling-dice.py>`__

* :doc:`/trainings/material/soup/python/exercises/herdt/exercise_while_even_numbers`

  * `even.py
    <https://github.com/jfasch/2022-04-05/blob/main/exercises/joerg/even.py>`__

* Back to :doc:`/trainings/material/soup/python/exercises/herdt/greet`

  Additional feature: repeatedly prompt the user after bad input. For
  example, when the input for the sex is 'z', prompt her again. Do
  this until a valid sex is input.

  Same if hour of day is not in 0-23.

Tag 3
.....

* :doc:`/trainings/material/soup/python/exercises/legacy/while_primeness`
* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/cmdline_digit`
* :doc:`/trainings/material/soup/python/basics/python_0270_functions/topic`

  * :doc:`/trainings/material/soup/python/basics/python_0270_functions/slideshow`
  * :doc:`/trainings/material/soup/python/basics/python_0270_functions/screenplay-scoping`

* :doc:`/trainings/material/soup/python/exercises/legacy/max_numbers_function`
* :doc:`/trainings/material/soup/python/exercises/legacy/uniq_function`
* :doc:`/trainings/material/soup/python/exercises/legacy/uniq_generator`
* :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
* :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`
* :doc:`/trainings/material/soup/python/basics/python_0460_sets/topic`
* :doc:`/trainings/material/soup/python/basics/python_0320_strings_methods/topic`
* :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/distill`
* :doc:`/trainings/material/soup/python/exercises/legacy/passwd`

Tag 4
-----

* :doc:`/trainings/material/soup/python/advanced/modules`
* :doc:`/trainings/material/soup/python/advanced/oo/index`
