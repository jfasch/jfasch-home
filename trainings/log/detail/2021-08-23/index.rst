.. include:: <mmlalias.txt>

Python Grundlagen (2021-08-23 - 2021-08-25)
===========================================

.. sidebar:: *Training Information*

   **Start**

   Monday 2021-08-23, 9:00

   **Course Description**

   `tecTrain "Programmierung Grundlagen"
   <https://www.tectrain.at/seminare/seminar-themen/programmierung/programmierung-grundlagen>`__

   **Material**

   * :doc:`Python Topics </trainings/material/soup/python/group>`
   * PDF Slides (Altlast), :download:`Python
     </trainings/material/pdf/300-python.pdf>`
   * Jupyter Notebook: :doc:`HTML <notebook-wrapper>`,
     :download:`download <Notebook.ipynb>`
   * `Github Repository <https://github.com/jfasch/2021-08-23>`__

.. toctree::
   :hidden:

   Jupyter Notebook (Übersicht) <notebook-wrapper>
   Jupyter Notebook <Notebook>
   exercises/sap-cleaned

.. contents::
   :local:

Log
---

Day 1
.....

The basics, with a moderate amount of exercises.

* :doc:`/trainings/material/soup/python/basics/installation`
* :doc:`/trainings/material/soup/python/draft/vscode`

* Datatypes

  * :doc:`/trainings/material/soup/python/basics/python_0110_blahblah/topic`
  * :doc:`/trainings/material/soup/python/basics/python_0120_helloworld/topic`

    * `Hello world
      <https://github.com/jfasch/2021-08-23/blob/master/live-hacking/hello.py>`__
    * `Commandline arguments demo
      <https://github.com/jfasch/2021-08-23/blob/master/live-hacking/argv.py>`__

  * :doc:`/trainings/material/soup/python/basics/python_0130_syntax_etc/topic`
  * :doc:`/trainings/material/soup/python/basics/python_0140_variables/topic`
  * :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
  * :doc:`/trainings/material/soup/python/basics/python_0160_boolean/topic`
  * :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
  * Exercise: :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_interactive`
  * Exercise: :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_executable`
  * :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
  * Exercise: :doc:`/trainings/material/soup/python/exercises/legacy/dict_keyerror`
  * Exercise:
    :doc:`/trainings/material/soup/python/exercises/legacy/cmdline_digit`
    (`Solution
    <https://github.com/jfasch/2021-08-23/blob/master/live-hacking/digit.py>`__)
  * :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`

* Control Flow and Iteration

  * :doc:`/trainings/material/soup/python/basics/python_0170_if/topic`
  * Exercise: :doc:`/trainings/material/soup/python/exercises/legacy/max_numbers`
  * :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`
  * Exercise:
    :doc:`/trainings/material/soup/python/exercises/legacy/while_primeness`
    (`Solution
    <https://github.com/jfasch/2021-08-23/blob/master/live-hacking/prime-while.py>`__)
  * :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`
  * :doc:`/trainings/material/soup/python/basics/python_0225_range/topic`
  * Exercise: :doc:`/trainings/material/soup/python/exercises/legacy/for_primeness`

* Functions and Generators

  * :doc:`/trainings/material/soup/python/basics/python_0270_functions/topic`
  * Exercise: :doc:`/trainings/material/soup/python/exercises/legacy/max_numbers_function`
  * Exercise: :doc:`/trainings/material/soup/python/exercises/legacy/primeness_function`
  * Exercise: :doc:`/trainings/material/soup/python/exercises/legacy/uniq_function`

Day 2
.....

* Functions and Generators

  * Exercise: :doc:`/trainings/material/soup/python/exercises/legacy/uniq_function`
  * Exercise: :doc:`/trainings/material/soup/python/exercises/legacy/join_function`
  * :doc:`/trainings/material/soup/python/python_1010_generators_yield/topic`
  * Exercise: :doc:`/trainings/material/soup/python/exercises/legacy/uniq_generator`

* File I/O and Strings

  * :doc:`/trainings/material/soup/python/basics/python_0300_strings/topic`
  * :doc:`/trainings/material/soup/python/basics/python_0320_strings_methods/topic`
  * Exercise: :doc:`/trainings/material/soup/python/exercises/legacy/string-rightjustify`
  * :doc:`/trainings/material/soup/python/basics/python_0310_strings_formatting/topic`
  * :doc:`/trainings/material/soup/python/basics/python_0330_strings_encoding/topic`
  * :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`
  * ``collections.namedtuple``: see `here
    <https://docs.python.org/3/library/collections.html#collections.namedtuple>`__
  * ``datetime``

    * ``datetime``: `here <https://docs.python.org/3/library/datetime.html?highlight=strptime#datetime.datetime>`__
    * ``timedelta``: `here <https://docs.python.org/3/library/datetime.html?highlight=strptime#timedelta-objects>`__
    * ``datetime.strptime()``: `parsing strings
      <https://docs.python.org/3/library/datetime.html?highlight=strptime#datetime.datetime.strptime>`__

    .. image:: datetime.png
       :scale: 50%

  * Exercise: :doc:`exercises/sap-cleaned`

Day 3
.....

* Databases

  * :doc:`/trainings/material/soup/python/python_5500_dbapi2/topic`
  * :doc:`/trainings/material/soup/python/python_5510_dbapi2_sqlite3/topic`
  * `DB-API2 for MS-SQL <https://docs.microsoft.com/de-de/sql/connect/python/python-driver-for-sql-server>`__

* Advanced Topics

  * :doc:`/trainings/material/soup/python/python_1050_oo/topic`
  * :doc:`/trainings/material/soup/python/python_1100_exceptions/topic`
  * :doc:`/trainings/material/soup/python/python_1200_modules/topic`
  * :doc:`/trainings/material/soup/python/python_5600_unittest/topic`

* What else?
    
  * Multithreadihg
  * Multiprocessing
  * OPC-UA (-> :doc:`/trainings/material/soup/python/draft/venv/topic`)

Live-Hacking (Jupyter Notebook)
-------------------------------

* :doc:`Jupyter Notebook (Übersicht) <notebook-wrapper>`
* :doc:`Jupyter Notebook <Notebook>`
* :download:`Download <Notebook.ipynb>`

Links
-----

Todo
----

*
  :doc:`/trainings/material/soup/python/exercises/legacy/cmdline_digit`
  depends on
  :doc:`/trainings/material/soup/python/exercises/legacy/dict_keyerror`
  which depends on
  :doc:`/trainings/material/soup/python/exercises/legacy/max_numbers`
  which depends on
  :doc:`/trainings/material/soup/python/basics/python_0170_if/topic` !!

