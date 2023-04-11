.. include:: <mmlalias.txt>


Clean Code Development With Python (2023-03-28 - 2023-03-29)
============================================================

.. contents::
   :local:

.. sidebar::

   **Github Repository**

   * https://github.com/jfasch/2023-03-28.git

Work Environment
----------------

* Python Installation

  * `Installing directly from python.org
    <https://www.python.org/downloads/>`__
  * `Anaconda <https://www.anaconda.com/>`__

* IDE

  * :doc:`/trainings/material/soup/python/misc/vscode`
  * `PyCharm <https://www.jetbrains.com/pycharm/>`__

* Package Installation, Virtual Environments

  * :doc:`/trainings/material/soup/python/swdev/pip/topic`
  * :doc:`/trainings/material/soup/python/swdev/venv/topic`
      
*Day 1*
-------

Introduction
............

Clean Code?
```````````

From :doc:`/trainings/material/soup/clean-code/group`:

* :doc:`/trainings/material/soup/clean-code/craft-sw`

Demo Hacking
````````````

* :doc:`/trainings/material/soup/clean-code/intro-python/livehacking`

The demo hacking session was extended through the entire session, with
topics woven in as time seemed right. Read on for those.

Python Development: Select Topics
.................................

Knowing more about Python enables one to write ... well ... more code
in fewer lines. While that is not usually an attitude of programmers
that everybody loves, in Python there's a word for it: *Pythonic*. An
early PEP, `"PEP 20 – The Zen of Python"
<https://peps.python.org/pep-0020/>`__ describes what that could
be. Lets have a closer look at what today's version of the language
offers in that respect.

Built-In Types: Facts
`````````````````````

* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`
* :doc:`/trainings/material/soup/python/advanced/comprehensions/topic`

``for`` Loops, And The Iterator Protocol
````````````````````````````````````````

* From :doc:`/trainings/material/soup/python/advanced/iteration-generation/iteration-generation/topic`

  * :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/iterator-protocol`

*Day 2:* Clean Code? (Software Development: A Craft)
----------------------------------------------------

Closures, And Function Parameters
.................................

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/python/advanced/closures/topic`
   * :doc:`/trainings/material/soup/python/advanced/starargs/topic`

``functools.partial`` was used yesterday to augment ``os.listdir()``
with the dirname: provide my own version, using a :doc:`closure
</trainings/material/soup/python/advanced/closures/topic>`

Generators (Again), ``yield`` Fixtures, And ``yield`` Context Managers
......................................................................

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/fibonacci-generator`
   * :doc:`/trainings/material/soup/python/swdev/pytest/intro`
   * :doc:`/trainings/material/soup/python/advanced/context-mgr/topic`

* Generator recap:
  :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/fibonacci-generator`
* More pytest (yield-fixtures)

  * How come pytest provide fixtures by saying ``test_blah(tmpdir)``?
    |longrightarrow| :doc:`python:library/inspect`
  * :doc:`/trainings/material/soup/python/swdev/pytest/intro`
  * ``pytest.monkeypatch`` (mocking ``os.listdir()``)
    (:doc:`pytest:how-to/monkeypatch`)

* While we are at yield-fixtures: contextlib
  (:doc:`/trainings/material/soup/python/advanced/context-mgr/topic`)

Object Oriented Programming
...........................

(Maybe begin with operator overloading?)

From :doc:`/trainings/material/soup/python/advanced/oo/group`:

* :doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/constructor/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/methods/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/str-repr/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/properties/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/namedtuple/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/inheritance/topic`              
* :doc:`/trainings/material/soup/python/advanced/oo/operator-overloading/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/abc/topic`

Untold
------


Decorators (The Ominous ``@``)
..............................

* :doc:`/trainings/material/soup/python/advanced/starargs/topic`
* :doc:`/trainings/material/soup/python/advanced/closures/topic`
* :doc:`/trainings/material/soup/python/advanced/decorators/topic`

Exceptions
..........

* :doc:`/trainings/material/soup/python/advanced/exceptions/topic`

Modules And Packages
....................

* :doc:`/trainings/material/soup/python/advanced/modules`

Pandas
......

From :doc:`/trainings/material/soup/python/misc/pandas/group`:

* :doc:`/trainings/material/soup/python/misc/pandas/basics`
* :doc:`/trainings/material/soup/python/misc/pandas/iloc`
* :doc:`/trainings/material/soup/python/misc/pandas/loc`
* :doc:`/trainings/material/soup/python/misc/pandas/indexes`
* :doc:`/trainings/material/soup/python/misc/pandas/filters`
* :doc:`/trainings/material/soup/python/misc/pandas/mod_col`
* :doc:`/trainings/material/soup/python/misc/pandas/add_row`

Design Patterns
...............

*Discussion*: so what? OO is there to solve problems in a readable and
reproducible way.

* :doc:`/trainings/material/soup/cxx-design-patterns/uml/uml`
* :doc:`/trainings/material/soup/cxx-design-patterns/oo-principles`
* Pythonize *some* patterns (the simpler ones) from
  :doc:`/trainings/material/soup/cxx-design-patterns/group`. Maybe ...

  * Adapter
  * Proxy
  * Composite
  * Observer

