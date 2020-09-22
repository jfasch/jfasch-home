.. include:: <mmlalias.txt>

Python Advanced (7.9.2020 - 10.9.2020)
======================================

.. contents::
   :local:

.. toctree::
   :hidden:

   traunstein/index

.. sidebar:: *Training Information*

   **Start**

   Montag 7.9.2020, 8:00

   **Official Description**

   :doc:`/trainings/repertoire/python-advanced`

   **Material**

   .. csv-table::

      :doc:`OpenTraining </about/site/opentraining/index>` Topics, :doc:`/trainings/material/soup/python/python`
      PDF Slides (Python obsolete), :download:`Python </trainings/material/pdf/300-python.pdf>`
      PDF Slides (Design Patterns), :download:`Design Patterns </trainings/material/pdf/060-design-patterns-unittests.pdf>`

This is a training for a team which is already experienced in Python
programming. There were some special requirements for the training,
such as to loose a couple of words about AI/machinelearning and other
topics, as well as a fuzzy "bring us advanced stuff".

Preparation
-----------

Workspace Setup
...............

* :doc:`/trainings/material/soup/draft/installation`
* :doc:`/trainings/material/soup/draft/vscode`

Github for Exercises
....................

Please create `Github <https://github.com/>`__ accounts and send them
to training@faschingbauer.co.at. We will do exercises via a private
repository on Github. (See the :doc:`privacy statement
</trainings/codex>`.)

Agenda
------

Advanced Core Python Topics
...........................

Python is easy; one can solve nontrivial problems in only a few lines
of code, in no time. This does not mean that you have to fully
understand the language - which is good because this is what makes the
language easy.

On the other hand, there's always a line to cross where you wish you
knew more. Here the more advanced core Python topics that shall be
covered.

* :doc:`/trainings/material/soup/python/python_1010_generators_yield/topic`
* :doc:`/trainings/material/soup/draft/context_manager/topic`
* :doc:`/trainings/material/soup/draft/encoding`
* :doc:`/trainings/material/soup/draft/exceptions`
* :doc:`/trainings/material/soup/python/python_1200_modules/topic`
* :doc:`/trainings/material/soup/draft/duck-typing`
* :doc:`/trainings/material/soup/draft/special_methods`
* :doc:`/trainings/material/soup/draft/starargs/topic`
* :doc:`/trainings/material/soup/draft/closures/topic`
* :doc:`/trainings/material/soup/draft/decorators/topic`

Special Topics
..............

* :doc:`/trainings/material/soup/draft/ai`

  * :doc:`/trainings/material/soup/draft/machine-learning-intro`
  * :doc:`/trainings/material/soup/draft/linear-regression/topic`
  * :doc:`/trainings/material/soup/draft/k-means`

* :doc:`/trainings/material/soup/draft/mysql`
* Unit Testing, Test Driven Development, Design Patterns

  * Excerpt from :doc:`/trainings/repertoire/unittests`
    (:download:`/trainings/material/pdf/060-design-patterns-unittests.pdf`)
  * :doc:`/trainings/material/soup/python/python_5600_unittest/topic`

* Web programming with Jango and/or Flask

Finishing
---------

Day 1
.....

Rushed through basics,

* :doc:`/trainings/material/soup/python/python_0140_variables/topic`
* :doc:`/trainings/material/soup/python/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/python_0170_if/topic`

Put a strong focus on Python features,

* :doc:`/trainings/material/soup/python/python_0250_refs_flat_deep_copy/topic`
* :doc:`/trainings/material/soup/python/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/python_0193_while/topic`. The
  ``else`` clause, mainly - everyone was supposed to know what a
  ``while`` loop is.
* :doc:`/trainings/material/soup/python/python_0220_for/topic`.

  * ``else`` clause
  * :doc:`/trainings/material/soup/python/python_0225_range/topic`. Whetting
    appetite for the *Iteration* livehacking session on day 2.

TODO
----

Log
...

* Day 2

  * livehacking *iteration*

    * start with ``squares()`` function, over ``[1,2,3]``
    * list comprehension
    * larger input list: 10000000, first filled with manual ``while``
      loop. then filled with for/in/range(10000000).
    * not at all fill list with anything, but rather pass range to
      ``squares()`` directly.
    * squares still has temporary list
    * enter ``yield``

  * livehacking OO

    * ``oo.py``

      * initially: ``Thermometer``, ctor, ``get_temperature()``
      * ``__init__``, ``self``, etc. (``self`` can also read ``this``)
      * ``th.__dict__``
      * *private*, pros and cons
      * properties (r/w)
   
    * inheritance

      * ``abstract-base-class.py``, ``abstract-base-class.cpp``
      * insert one step *without* ``abc`` before it, and then show
        what ``abc`` can do
      * explain "check errors as early as can" |longrightarrow| at
        ctor time, rather than at method call time.

    * patterns

      * ``composite.py``
      * ``adapter.py``

* Day 3

  * revisit ``abstract-base-class.py``. morph into ``duck-typing.py``,
    explaining how ``abc`` shifts duck errors from *call* to
    *initialization*
  * visitor pattern

    * ``visitor.py``, complicated with class with callback. sideways:

      * show how ``__call__`` makes a class callable.
      * show how ``__str__`` and ``__repr__`` work together in
        ``print()``

    * ``visitor-generator.py``, making ``dfs()`` iterable. ``yield
      from``
    * TODO: Turn that into a screenplay

  * TDD and Unit Testing theory

  * Start hacking on project. Agreed upon myself doing live
    hacking. Doing TDD.
    
    * ``sensordata.py``, and ``sensordata_tests.py``. Prepare TDD;
      explain suites, cases, fixture, assertions.
    * While writing data classes (holding only attributes and no
      functionality), explain ``namedtuple``.
    * Slowly fix things, in a test driven way. Discuss, team giving
      input, all really fine.

* Day 4

  * Decorators (starargs and closures); mainly to see how flask routes
    work.
  * CSV import
  * sqlite3 export, trying out dbapi2
  * flask frontend, reading sqlite3 db

Videos
......

* Beazley metaprogramming 3h
* Hettinger "Own the Dot"
* Schaefer Properties maybe

After Work Party
................

From my point of view, the training went really fine. Not everyone is
equally satisfied with the outcome (we didn't get to the AI topics,
for example), but I have the impression that I brought it over.

As a gift to myself, I had reserved Thursday night at `Gmundner Hütter
<http://members.aon.at/traunstein/>`__. After the training I went back
to `Hoisn Wirt <https://www.hoisnwirt.at/>`__ (which is where I stayed
during the training - really fine), changed clothes, and started to
climb the `Traunstein
<https://de.wikipedia.org/wiki/Traunstein_(Berg)>`__ via `Zierlersteig
<https://www.alpenvereinaktiv.com/de/tour/am-zierlersteig-auf-den-traunstein-1691-m/10620837/>`__.

See :doc:`here <traunstein/index>` for the description and pictures from
this extraordinary hike.

Graph
-----

.. jf-topicgraph::
   :entries: drafts.ai.linear_regression,
	     drafts.ai.k_means,
	     drafts.duck_typing,
	     drafts.context_manager,
	     drafts.special_methods,
	     drafts.closures,
	     drafts.decorators,
	     drafts.starargs,
	     python.swdev.python_1200_modules,
	     python.python_1010_generators_yield,
	     drafts.encoding,
	     drafts.mysql,
	     drafts.installation,
	     drafts.exceptions

