.. include:: <mmlalias.txt>


Python Advanced (2023-09-25 - 2023-09-27)
=========================================

.. contents::
   :local:

.. toctree::
   :hidden:

   notebook-wrapper

.. sidebar::

   **Predecessor Course**

   This course is a followup to
   :doc:`../2023-05-15--Python-Basics/index`

   **Notebook**

   * Structure: :doc:`notebook-wrapper`
   * Entire notebook: :download:`notebook.ipynb`

   **Github Repository**

   * `https://github.com/jfasch/2023-09-25
     <https://github.com/jfasch/2023-09-25>`__

   **Material**

   * :doc:`/trainings/material/soup/python/group`

Day 1
-----

Recap Of Python Basics Course (Before Summer)
.............................................

Look through code in
`https://github.com/jfasch/2023-05-15/tree/main/livehacking/userdb
<https://github.com/jfasch/2023-05-15/tree/main/livehacking/userdb>`__

Project Management: Requirements, Sandboxing, Testing
.....................................................

* :doc:`/trainings/material/soup/python/swdev/pip/topic`
* :doc:`/trainings/material/soup/python/swdev/venv/topic`
* :doc:`/trainings/material/soup/python/swdev/pytest/intro`

For those who want/need it:

* :doc:`/trainings/material/soup/linux/basics/intro/wsl`

Exercises
,,,,,,,,,

* Clone project: `https://github.com/jfasch/2023-09-25
  <https://github.com/jfasch/2023-09-25>`__
* Create virtual environment based upon ``requirements.txt``
* Become acquainted with Test Driven Development:
  :doc:`/trainings/material/soup/python/exercises/userdb/user_json`

Agenda
------

Object Oriented Programming
...........................

Classes
,,,,,,,

From :doc:`/trainings/material/soup/python/advanced/oo/group`

* :doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/constructor/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/methods/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/str-repr/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/properties/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/namedtuple/topic`

Exercises
,,,,,,,,,

* Create a simple class:
  :doc:`/trainings/material/soup/python/exercises/userdb/user-class-person`

More Details
,,,,,,,,,,,,

* :doc:`/trainings/material/soup/python/advanced/oo/operator-overloading/topic`
* Going Dynamic: ``type()``, ``exec()``

  #. Class dictionary (|longrightarrow| ``fullname()``, and ctor). As
     opposed to object dictionary.
  #. Build ``class Person`` from code (as ``str``), using ``exec()``
  #. Define functions ``fullname()`` and ``ctor()``, and use
     ``type()`` to create the class object.

OO Design: Inheritance, And Abstract Base Classes
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

* :doc:`/trainings/material/soup/python/advanced/oo/inheritance/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/abc/topic`

Into The Wild: Group Project Kickoff
....................................

With a basic understanding of code structuring (classes and modules -
and TDD), let's hack something. An idea:

* Configurable set of sensors
* Polymorphic data sinks (|longrightarrow| *composite* sink)
* Acquisition engine in the middle
* CSV sources and sinks?
* MQTT maybe? How's the internet accessed in the company?
  (:doc:`/trainings/material/soup/python/misc/mqtt/topic`)
* Completely insane: the `pytest monkeypatch fixture
  <https://docs.pytest.org/en/7.1.x/how-to/monkeypatch.html>`__
  (testing MQTT functionality without MQTT/internet)

Exceptions, ``with``
....................

* :doc:`/trainings/material/soup/python/advanced/exceptions/topic`
* :doc:`/trainings/material/soup/python/advanced/context-mgr/topic`

Package Management
..................

* :doc:`/trainings/material/soup/python/swdev/venv/topic`
* :doc:`/trainings/material/soup/python/drafts/setuptools/topic`

Function Arguments, Closures, Decorators
........................................

* :doc:`/trainings/material/soup/python/advanced/starargs/topic`
* :doc:`/trainings/material/soup/python/advanced/closures/topic`
* :doc:`/trainings/material/soup/python/advanced/decorators/topic`
