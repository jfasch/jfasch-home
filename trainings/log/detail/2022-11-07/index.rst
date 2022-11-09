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

TODO
----

Function Arguments, Closures, Decorators
........................................

* :doc:`/trainings/material/soup/python/advanced/starargs/topic`
* :doc:`/trainings/material/soup/python/advanced/closures/topic`
* :doc:`/trainings/material/soup/python/advanced/decorators/topic`

* :doc:`/trainings/material/soup/python/advanced/exec/topic`

* The ``with`` Statement (Context Managers)

File System Interaction
.......................

:doc:`python:library/filesys`

* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/group` (Linux Filesystem)
* The ``shutil`` Module
* Exercise: Like
  :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/group`,
  only in Python
* ``os.path``: :doc:`python:library/os.path`
* ``pathlib``: :doc:`python:library/pathlib`
* ``os.walk()``

(More About) Exception Handling, Modules
........................................

* :doc:`/trainings/material/soup/python/advanced/exceptions`
* :doc:`/trainings/material/soup/python/advanced/modules`

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
