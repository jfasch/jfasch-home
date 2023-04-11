Agenda: Python Advanced (2023-04-24 - 2023-04-26)
=================================================

.. contents::
   :local:

.. sidebar::

   **Material**

   * :doc:`/trainings/material/soup/python/group`

Up Front: Project Management
----------------------------

* :doc:`/trainings/material/soup/linux/basics/intro/wsl`
* :doc:`/trainings/material/soup/python/swdev/pip/topic`
* :doc:`/trainings/material/soup/python/swdev/venv/topic`
* :doc:`/trainings/material/soup/python/swdev/pytest/intro`

Day 1: Python Inside Out
------------------------

* Exercise prerequisites

  * :doc:`/trainings/material/soup/python/basics/python_0139_commandline_argv/topic`
  * :doc:`/trainings/material/soup/python/drafts/argparse/topic`

* References and other pitfalls

  * :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`
  * :doc:`/trainings/material/soup/python/basics/python_0270_functions/slideshow`
  * :doc:`/trainings/material/soup/python/basics/python_0270_functions/screenplay-scoping`

* Looping constructs (with an emphasis on the ``else`` clause)

  * :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`
  * :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`

* Generators (from
  :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/topic`)

  * :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/iterator-protocol`
  * :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/fibonacci-generator`

* Closures, decorators and more

  * :doc:`/trainings/material/soup/python/advanced/starargs/topic`
  * :doc:`/trainings/material/soup/python/advanced/closures/topic`
  * :doc:`/trainings/material/soup/python/advanced/decorators/topic`

* Dynamic features

  * :doc:`/trainings/material/soup/python/advanced/exec/topic`
  * :doc:`The eval() function <python:library/functions>`

* :doc:`/trainings/material/soup/python/advanced/oo/group`

  * :doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/constructor/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/methods/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/str-repr/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/properties/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/namedtuple/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/inheritance/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/operator-overloading/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/abc/topic`

* Error handling and recovery

  * :doc:`/trainings/material/soup/python/advanced/exceptions/topic`
  * :doc:`/trainings/material/soup/python/advanced/context-mgr/topic`

Day 2: Clean Code (In A Broader Sense), Group Project Kickoff
-------------------------------------------------------------

* Group project: discussion

  * Data acquisition: gathering sensor data
  * Varying kinds of sensors: physical hardware, internet proxy, MQTT, ...
  * Varying kinds of information sinks: CSV, database, MQTT, ...
  * Acquisition machinery: timestamping, frequency, buffering, ...

* From :doc:`/trainings/material/soup/clean-code/group` ...

    * :doc:`/trainings/material/soup/clean-code/craft-sw`
    * :doc:`/about/site/work-in-progress/2022-04-13/seminar/clean-code-craftsmanship`

* Design patterns overview

  * :doc:`/trainings/material/soup/cxx-design-patterns/uml/uml`
  * :doc:`/trainings/material/soup/cxx-design-patterns/oo-principles`
  * :doc:`Design patterns
    </trainings/material/soup/cxx-design-patterns/group>`: problems,
    possible solutions

* Test Driven Development

  * (Try to) establish mindset
  * :doc:`/trainings/material/soup/python/swdev/pytest/intro`
  * ``pytest`` fixtures

    * :doc:`pytest:how-to/tmp_path`
    * :doc:`pytest:how-to/monkeypatch`

Day 3: Group Project
--------------------

* Create two or three teams
* Use Test Driven Develpment (TDD) to formulate requirements
* *Loop: hack, fix, refactor*
