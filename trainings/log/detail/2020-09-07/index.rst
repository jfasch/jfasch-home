.. include:: <mmlalias.txt>

Python Advanced (7.9.2020 - 10.9.2020)
======================================

.. contents::
   :local:

.. sidebar:: *Training Information*

   **Start**

   Montag 7.9.2020, 8:00

   **Official Description**

   :doc:`/trainings/repertoire/python-advanced`

   **Material**

   .. csv-table::

      :doc:`OpenTraining </about/site/opentraining/index>` Topics, :doc:`/trainings/material/soup/python/group`
      PDF Slides (Python obsolete), :download:`Python </trainings/material/pdf/300-python.pdf>`
      PDF Slides (Design Patterns), :download:`Design Patterns </trainings/material/pdf/060-design-patterns-unittests.pdf>`

   **Github Private Repository**

   https://github.com/jfasch/2020-09-07

This is a training for a team which is already experienced in Python
programming. There were some special requirements for the training,
such as to loose a couple of words about AI/machinelearning and other
topics, as well as a fuzzy "bring us advanced stuff".

Preparation
-----------

Workspace Setup
...............

* :doc:`/trainings/material/soup/python/basics/installation`
* :doc:`/trainings/material/soup/python/draft/vscode`

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
* :doc:`/trainings/material/soup/python/draft/context_manager/topic`
* :doc:`/trainings/material/soup/python/draft/encoding/topic`
* :doc:`/trainings/material/soup/python/draft/exceptions`
* :doc:`/trainings/material/soup/python/python_1200_modules/topic`
* :doc:`/trainings/material/soup/python/draft/duck-typing`
* :doc:`/trainings/material/soup/python/draft/special_methods`
* :doc:`/trainings/material/soup/python/draft/starargs/topic`
* :doc:`/trainings/material/soup/python/draft/closures/topic`
* :doc:`/trainings/material/soup/python/draft/decorators/topic`

Special Topics
..............

* :doc:`/trainings/material/soup/python/draft/ai`

  * :doc:`/trainings/material/soup/python/draft/machine-learning-intro`
  * :doc:`/trainings/material/soup/python/draft/linear-regression/topic`
  * :doc:`/trainings/material/soup/python/draft/k-means`

* Unit Testing, Test Driven Development, Design Patterns

  * Excerpt from :doc:`/trainings/repertoire/unittests`
    (:download:`/trainings/material/pdf/060-design-patterns-unittests.pdf`)
  * :doc:`/trainings/material/soup/python/python_5600_unittest/topic`

* Web programming with Jango and/or Flask

Finishing
---------

Following is a recap of what has happened. File names are relative to
the root of the `Github repository
<https://github.com/jfasch/2020-09-07>`__ we were working from.

Day 1
.....

Rushed through basics,

* :doc:`/trainings/material/soup/python/basics/python_0140_variables/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/basics/python_0170_if/topic`

Put a strong focus on Python features,

* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`
* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`. The
  ``else`` clause, mainly - everyone was supposed to know what a
  ``while`` loop is.
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`.

  * ``else`` clause
  * :doc:`/trainings/material/soup/python/basics/python_0225_range/topic`. Whetting
    appetite for the *Iteration* livehacking session on day 2.

Day 2
.....

* Livehacking:
  :doc:`/trainings/material/soup/python/iteration-generation/topic`,
  covering

  * List comprehensions
  * The ``range`` function
  * Writing generators using ``yield``
  * Generator expressions

* Livehacking OO

  * ``joerg-livehacking/oo.py``

    * initially: ``Thermometer``, ctor, ``get_temperature()``
    * ``__init__``, ``self``, etc. (``self`` can also read ``this``)
    * ``th.__dict__``
    * *private*, pros and cons
    * properties (r/w)
 
  * inheritance

    * ``joerg-livehacking/abstract-base-class.py``, ``joerg-livehacking/abstract-base-class.cpp``
    * insert one step *without* ``abc`` before it, and then show what
      ``abc`` can do
    * explain "check errors as early as can" |longrightarrow| at ctor
      time, rather than at method call time.

* Livehacking design patterns

  * ``joerg-livehacking/composite.py``. Using the thermometer
    hierarchy, a "composite" thermometer was created. That thermometer
    uses (*has*) a set of concrete thermometers to calculate the
    average room temperature.
  * ``joerg-livehacking/adapter.py``. Fictional scenario ...

    * The ``Unser`` thermometer framework contains a number of
      thermometer implementations which all support the
      ``get_temperature_celsius()`` method.
    * A collaboration with a competitor is launched. That competitor
      has a similar set of thermometer implementations. The difference
      between ``Eana`` and ``Unser`` is that ``Eana`` thermometers do
      not support ``get_temperature_celsius()``, but rather only
      ``get_temperature_fahrenheit()``.
    * We employ the *adapter pattern* and create one special
      thermometer in the ``Unser`` hierarchy

      .. code-block:: python

         class EanaAdapter(UnserThermometer):
	     ...

Day 3
.....

* Revisit abstract base classes

  * Discuss duck typing.
  * Morph ``joerg-livehacking/abstract-base-class.py`` into
    ``joerg-livehacking/duck-typing.py``.
  * Explaining how ``abc`` shifts duck errors from *call* to
    *initialization*

* Visitor pattern. Not every pattern in the `"Gang of Four" book
  <https://www.amazon.de/Patterns-Elements-Reusable-Object-Oriented-Software/dp/0201633612>`__
  should be considered a real pattern. For example, the `Visitor
  pattern <https://en.wikipedia.org/wiki/Visitor_pattern>`__ turn into
  an idiom for languages that don't support generators.

  * ``joerg-livehacking/visitor.py``. Classic OO implementation of the
    visitor pattern as a `DFS traversal
    <https://en.wikipedia.org/wiki/Depth-first_search>`__. Together
    with callbacks and all convolutions. Took sideways like,

    * show how ``__call__`` makes a class callable.
    * show how ``__str__`` and ``__repr__`` work together in
      ``print()``

  * ``joerg-livehacking/visitor-generator.py``. "I don't want to
    implement a visitor!", poor user says. "I only want to iterate
    over the tree in DFS order!"

    Implement DFS iteration using ``yield from`` which delegates
    iteration into recursion.

* TDD and Unit Testing theory; using excerpts from the
  :download:`Design Patterns
  </trainings/material/pdf/060-design-patterns-unittests.pdf>` deck of
  slides. Explain terminology; *fixtures* and such.

* Start hacking on project. Agreed upon myself doing live
  hacking. Doing TDD.
  
  * ``Project/sensor/sensordata.py``, and
    ``Project/tests/sensordata_tests.py``. Prepare TDD; explain
    suites, cases, fixture, assertions.
  * While writing data classes (holding only attributes and no
    functionality), explain ``namedtuple``. Use that to implement
    ``sensor.sensordata.HistoryData``.
  * Slowly fix things, in a test driven way. Discuss, team giving
    input, all really fine.

Day 4
.....

  * Decorators theory, and livehacking. Mainly to see how flask routes
    work.

    * :doc:`/trainings/material/soup/python/draft/starargs/topic`
    * :doc:`/trainings/material/soup/python/draft/closures/topic`
    * :doc:`/trainings/material/soup/python/draft/decorators/topic`

  * Continue project; add CSV
    import. 

    ``Project/programs/csvreport.py``
  * `sqlite3 <https://docs.python.org/3/library/sqlite3.html>`__
    export, trying out the `DBAPI 2.0 interface
    <https://www.python.org/dev/peps/pep-0249/>`__. 

    ``Project/programs/csv2sqlite3.py``
  * Flask frontend, reading ``sqlite3`` db.

    ``Project/programs/flaskerl.py``

Recommended Tutorials
---------------------

We couldn't cover everything we would have liked to. Here is a random
list of tutorial to watch in quiet moments.

* `Transforming Code into Beautiful, Idiomatic Python
  <https://www.youtube.com/watch?v=OSGv2VnC0go>`__. **Raymond
  Hettinger**, reiterating his favorite phrase: "There must be a
  better way". (Hettinger is a "Python Core Developer".)

  .. raw:: html

     <iframe width="560" 
             height="315" 
	     src="https://www.youtube.com/embed/OSGv2VnC0go" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Python Tutorial: Duck Typing and Asking Forgiveness, Not Permission
  (EAFP) <https://www.youtube.com/watch?v=x3v9zMX1s4s>`__. **Corey
  Schafer** about *Duck Typing*, and the word *Pythonic*. Corey
  Schafer has a number of very good Tutorials; he manages to keep
  those short and to the point, and rarely exceeds 15 minutes.

  .. raw:: html

     <iframe width="560" 
             height="315" 
	     src="https://www.youtube.com/embed/x3v9zMX1s4s" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Python Tutorial: Unit Testing Your Code with the unittest Module
  <https://www.youtube.com/watch?v=6tNS--WetLI>`__. Our project was
  guided by unit tests; here's **Corey Schafer** about the
  ``unittest`` module.

  .. raw:: html

     <iframe width="560" 
             height="315" 
	     src="https://www.youtube.com/embed/6tNS--WetLI" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Python Tutorial: Decorators - Dynamically Alter The Functionality
  Of Your Functions <https://www.youtube.com/watch?v=FsAPt_9Bf3U>`__.
  **Corey Schafer** about decorators. Mine was better :-)

  .. raw:: html

     <iframe width="560" 
             height="315" 
	     src="https://www.youtube.com/embed/FsAPt_9Bf3U" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Built in Super Heroes
  <https://www.youtube.com/watch?v=lyDLAutA88s>`__. **David Beazley**
  in an entertaining keynote to the "PyData Chicago 2016"
  conference. He has a number of very good and entertaining (and very
  advanced) videos. You have to spend an entire evening with him
  though.

  .. raw:: html

     <iframe width="560" 
             height="315" 
	     src="https://www.youtube.com/embed/lyDLAutA88s" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Concurrency <https://www.youtube.com/watch?v=9zinZmE3Ogk>`__:
  **Raymond Hettinger** covering most if not all aspects and
  possiblities of concurrency. Very informative, very concise,
  covering

  * Multithreading
  * Multiprocessing
  * Async; I didn't even mention that. `asyncio
    <https://docs.python.org/3/library/asyncio.html>`__. Me big fan.

  .. raw:: html

     <iframe width="560" 
             height="315" 
	     src="https://www.youtube.com/embed/9zinZmE3Ogk" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Understanding the Python GIL
  <https://www.youtube.com/watch?v=Obt-vMVdM8s>`__: **David Beazley**
  dissecting the Global Interpreter Lock, explaining why
  multiprocessing is better. At around minute 45, in the
  questions/answers, there a mention that using NumPy operations in
  multiple threads is *truly parallel*.

  .. raw:: html

     <iframe width="560" 
             height="315" 
	     src="https://www.youtube.com/embed/Obt-vMVdM8s" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Modules and Packages
  <https://www.youtube.com/watch?v=0oTh1CXRaQ0>`__. **David Beazley**
  has a three hour (!) *really cool and in-depth* look into the
  seemingly simple ``import`` mechanism.

  .. raw:: html

     <iframe width="560" 
             height="315" 
	     src="https://www.youtube.com/embed/0oTh1CXRaQ0" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Virtual Environments Tutorial
  <https://www.youtube.com/watch?v=APOPm01BVrk>`__: **Corey Schafer**
  again. Virtual environments are kind of an isolated development
  sandbox, solving a similar problem as containers do, but much more
  lightweight and Python only.

  .. raw:: html

     <iframe width="560" 
             height="315" 
	     src="https://www.youtube.com/embed/APOPm01BVrk" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Packaging, Deployment, PyPI, and pip
  <https://www.youtube.com/watch?v=P3dY3uDmnkU>`__: **Chris Wilcox**
  (of Google) talking about packaging and deployment, and related
  topics

  .. raw:: html

     <iframe width="560" 
             height="315" 
	     src="https://www.youtube.com/embed/P3dY3uDmnkU" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Generators: The Final Frontier
  <https://www.youtube.com/watch?v=D1twn9kLmYg>`__: **David Beazley**,
  again a bit (a whopping four hours) more precise on that topic.

  .. raw:: html

     <iframe width="560" 
             height="315" 
	     src="https://www.youtube.com/embed/D1twn9kLmYg" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `NumPy Tutorial <https://www.youtube.com/watch?v=GB9ByFAIAH4>`__:
  **Keith Galli** has a number of good **data science** tutorials.

  .. raw:: html

     <iframe width="560" 
             height="315" 
	     src="https://www.youtube.com/embed/GB9ByFAIAH4" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

After Work Party
----------------

From my point of view, the training went really fine. Not everyone is
equally satisfied with the outcome (we didn't get to the AI topics,
for example), but I have the impression that I brought it over.

As a gift to myself, I had reserved Thursday night at `Gmundner Hütte
<http://members.aon.at/traunstein/>`__. After the training I went back
to `Hoisn Wirt <https://www.hoisnwirt.at/>`__ (which is where I stayed
during the training - really fine), changed clothes, and started to
climb the `Traunstein
<https://de.wikipedia.org/wiki/Traunstein_(Berg)>`__ via `Zierlersteig
<https://www.alpenvereinaktiv.com/de/tour/am-zierlersteig-auf-den-traunstein-1691-m/10620837/>`__.

:doc:`See here for the description and pictures from this
extraordinary hike.  </blog/2020/09/traunstein>`

Graph
-----

.. ot-graph::
   :entries: python.drafts.ai.linear_regression,
	     python.drafts.ai.k_means,
	     python.drafts.duck_typing,
	     python.drafts.context_manager,
	     python.drafts.special_methods,
	     python.drafts.closures,
	     python.drafts.decorators,
	     python.drafts.starargs,
	     python.swdev.python_1200_modules,
	     python.python_1010_generators_yield,
	     python.drafts.encoding,
	     python.basics.installation,
	     python.drafts.exceptions

