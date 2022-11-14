Python (2022-11-07 - 2022-11-10)
================================

.. contents::
   :local:

.. sidebar:: *Training Information*

   **Material**

   * :doc:`/trainings/material/soup/python/group`

   **Source Code**

   * `Github <https://github.com/jfasch/2022-11-07>`__. This is a
     *private project*; to view it you must be a collaborator.

   **Notebook**

   * :doc:`Structure <notebook-wrapper>`
   * :doc:`Whole notebook <notebook>`
   * :download:`Download <notebook.ipynb>`

Up Front: Project Management
----------------------------

* :doc:`/trainings/material/soup/linux/basics/intro/wsl`
* :doc:`/trainings/material/soup/python/swdev/pip/topic`
* :doc:`/trainings/material/soup/python/swdev/venv/topic`
* :doc:`/trainings/material/soup/python/swdev/pytest-intro`

Object Oriented Programming: Classes
------------------------------------

* From :doc:`/trainings/material/soup/python/advanced/oo/group`

  * :doc:`/trainings/material/soup/python/advanced/oo/constructor/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/methods/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/str-repr/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/properties/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/namedtuple/topic`

Exercise Series: CSV
--------------------

* :doc:`/trainings/material/soup/python/misc/csv/topic`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvreader`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvreader-function`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader-function`

Missing Pieces: Encoding, Unit Testing
--------------------------------------

* :doc:`/trainings/material/soup/python/misc/encoding/topic`
* Unit Testing (``pytest`` vs. ``unittest``)

  * :doc:`/trainings/material/soup/python/swdev/unittest`

    * `unittest sample suite
      <https://github.com/jfasch/2022-11-07/blob/main/livehacking/unittest/unittest-demo.py>`__
      (*Private Github project*)
    * `pytest sample suite
      <https://github.com/jfasch/2022-11-07/blob/main/livehacking/unittest/test_read_csv.py>`__
      (*Private Github project*)

  * :doc:`/trainings/material/soup/python/swdev/pytest-intro`

Exercise Series: CSV, JSON
--------------------------

* :doc:`/trainings/material/soup/python/exercises/userdb/userdb_csv`
* :doc:`/trainings/material/soup/python/exercises/userdb/user_json`
* :doc:`/trainings/material/soup/python/exercises/userdb/user-class-person`

Iteration, Generators
---------------------

* Iteration (Recap) (:doc:`see notebook <notebook-wrapper>`)
* :doc:`/trainings/material/soup/python/advanced/comprehensions/topic`
* Generators, The ``yield`` Keyword

  * :doc:`/trainings/material/soup/python/advanced/iteration-generation/iteration-generation/topic`
  * Generator Expressions

Operator Overloading
--------------------

* :doc:`/trainings/material/soup/python/advanced/oo/operator-overloading/topic`

Going Dynamic: ``type()``, ``exec()``
-------------------------------------

* ``type()``, ``exec()``. Revisit class dictionary, and build ``class
  Person`` dynamically. See demo `here
  <https://github.com/jfasch/2022-11-07/blob/main/livehacking/oo-fully-dynamic.py>`__
  (*Private Github project*)

More OO: Inheritance, Abstract Base Classes
-------------------------------------------

* From :doc:`/trainings/material/soup/python/advanced/oo/group`

  * :doc:`/trainings/material/soup/python/advanced/oo/inheritance/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/abc/topic`

Group Project Kickoff
---------------------

.. image:: project.jpg

Data Structures Recap
---------------------

* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
* :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`

Miscellaneous Livehacking
-------------------------

https://github.com/jfasch/2022-11-07/tree/main/

* Subprocess

  * `Livehacking
    <https://github.com/jfasch/2022-11-07/tree/main/livehacking/subprocess-demo.py>`__
  * Documentation: :doc:`python:library/subprocess`

* Network programming

  * `Livehacked client
    <https://github.com/jfasch/2022-11-07/tree/main/livehacking/livehacking/client.py>`__
  * `Livehacked server
    <https://github.com/jfasch/2022-11-07/tree/main/livehacking/livehacking/server.py>`__
  * Documentation: :doc:`python:library/socket`

Function Arguments, Closures, Decorators
----------------------------------------

* :doc:`/trainings/material/soup/python/advanced/starargs/topic`
  (`Livehacking <livehacking/args-kwargs.py>`__)
* :doc:`/trainings/material/soup/python/advanced/closures/topic`
  (`Livehacking <livehacking/closures.py>`__)
* :doc:`/trainings/material/soup/python/advanced/decorators/topic`
  (`Livehacking <livehacking/decorator.py>`__)

TODO
----

* SOLID

* The ``with`` Statement (Context Managers)
* setuptools
* :doc:`/trainings/material/soup/python/advanced/exceptions`
* :doc:`/trainings/material/soup/python/misc/python_5550_xml_etree/topic`

Databases
.........
  
* :doc:`/trainings/material/soup/python/misc/db/dbapi2`
* :doc:`/trainings/material/soup/python/exercises/csv/csv-db`


Context Managers/``with``
.........................

Project Ideas
-------------

* ``NoneType`` object is not **iterable** -> iteration
* ``subprocess`` optimization

  * Network programming (client/server)
  * stdin, stdout to a coprocess

* Sensors, configurable

  * configfile: INI
  * configfile: XML
  * configfile: ``exec()``
