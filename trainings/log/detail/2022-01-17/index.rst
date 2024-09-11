.. include:: <mmlalias.txt>


Programmierung Grundlagen, anhand von Python (2022-01-17 - 2022-01-10)
======================================================================

.. sidebar:: *Training Information*

   **Offizielle Beschreibung**

   `tecTrain "Programmierung Grundlagen"
   <https://www.tectrain.at/seminare/seminar-themen/programmierung/programmierung-grundlagen>`__

   **Material**

   * :doc:`/trainings/material/soup/python/basics/group`
   * `Github Repository <https://github.com/jfasch/2022-01-17>`__

.. contents::
   :local:

Überblick
---------

Die Kurssprache des Kurses "Programmierung Grundlagen" ist Python;
viele der Python-spezifische Elemente werden von :doc:`hier
</trainings/material/soup/python/basics/group>` unterrichtet.

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

  * Sequential search in output list (bad): `uniq-sequential.py <https://github.com/jfasch/2022-01-17/blob/main/uniq-sequential.py>`__
  * Constant-time search in ``set`` (good): `uniq-set.py <https://github.com/jfasch/2022-01-17/blob/main/uniq-set.py>`__

* :doc:`/trainings/material/soup/python/exercises/legacy/cmdline_digit`

  * `digit.py <https://github.com/jfasch/2022-01-17/blob/main/digit.py>`__

Tag 3
.....

* :doc:`/trainings/material/soup/python/basics/python_0270_functions/topic`

  * :doc:`/trainings/material/soup/python/basics/python_0270_functions/slideshow`
  * :doc:`/trainings/material/soup/python/basics/python_0270_functions/screenplay-scoping`

* :doc:`/trainings/material/soup/python/exercises/legacy/max_numbers_function`
* :doc:`/trainings/material/soup/python/exercises/legacy/uniq_function`

  * `uniq-function.py
    <https://github.com/jfasch/2022-01-17/blob/main/uniq-function.py>`__
  * Using ``dict.fromkeys()``: `uniq-fromkeys.py
    <https://github.com/jfasch/2022-01-17/blob/main/uniq-fromkeys.py>`__

* :doc:`/trainings/material/soup/python/exercises/legacy/uniq_generator`
* :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
* :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`
* :doc:`/trainings/material/soup/python/basics/python_0460_sets/topic`

  Talking about searchable datastructures, like in ``dict`` and
  ``set`` (those are implemented as hash tables, btw.)

  * Hash Table

    .. image:: hashtable.png
       :scale: 40%

  * Red-Black Tree

    .. image:: rbtree.png
       :scale: 40%

* :doc:`/trainings/material/soup/python/basics/python_0320_strings_methods/topic`
* :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`

  * Using ``f.readline()`` (EOF is clumsy): `passwd-readline.py
    <https://github.com/jfasch/2022-01-17/blob/main/passwd-readline.py>`__
  * Pythonic, using iteration: `passwd-iter.py
    <https://github.com/jfasch/2022-01-17/blob/main/passwd-iter.py>`__

* :doc:`/trainings/material/soup/python/exercises/legacy/distill`

  * `distill.py <https://github.com/jfasch/2022-01-17/blob/main/distill.py>`__

* :doc:`/trainings/material/soup/python/exercises/legacy/passwd`

  * Larger OO/modules/database "project" `see here
    <https://github.com/jfasch/2022-01-17/tree/main/passwd>`__

Tag 4
-----

* :doc:`/trainings/material/soup/python/advanced/modules`
* :doc:`/trainings/material/soup/python/advanced/oo/group`
* SQL

  * :doc:`/trainings/material/soup/python/misc/db/dbapi2`
  * :doc:`/trainings/material/soup/python/misc/db/sqlite3`
  * Exercise: larger OO/modules/database "project" `see here
    <https://github.com/jfasch/2022-01-17/tree/main/passwd>`__

Links
-----

* `PHP: A Fractal of Bad Design <https://eev.ee/blog/2012/04/09/php-a-fractal-of-bad-design/>`__




