.. include:: <mmlalias.txt>

Python Advanced (2022-03-15 - 2022-03-17, 2022-03-31)
=====================================================

.. sidebar:: *Training Information*

   * :doc:`/trainings/material/soup/python/advanced/group`
   * :doc:`/trainings/material/soup/python/group`
   * Jupyter Notebook

     * :doc:`Structure <notebook-wrapper>`
     * :doc:`Entire Notebook <Notebook>`
     * :download:`download <Notebook.ipynb>`

   * `Github Repository <https://github.com/jfasch/2022-02-23>`__
   * :doc:`/trainings/material/soup/python/pcap-exam`
   * Predecessor training: :doc:`../2022-02-23/index`

.. toctree::
   :hidden:

   Jupyter Notebook (Übersicht) <notebook-wrapper>
   Jupyter Notebook <Notebook>

.. contents::
   :local:

2022-03-15
----------

* :doc:`/trainings/material/soup/python/exercises/legacy/primeness_function`
* :doc:`/trainings/material/soup/python/exercises/legacy/distill`
* :doc:`/trainings/material/soup/python/misc/encoding/topic`

2022-03-16
----------

Good morning!

* Live-hack ``eval()``

  * :doc:`notebook (first) <notebook-wrapper>`
  * `dict-from-cmdline.py <https://github.com/jfasch/2022-02-23/blob/main/livehacking/dict-from-cmdline.py>`__

* :doc:`/trainings/material/soup/python/advanced/exec/topic`
  (`exec-context.py
  <https://github.com/jfasch/2022-02-23/blob/main/livehacking/exec-context.py>`__)

* :doc:`/trainings/material/soup/python/advanced/starargs/topic`
  (`args-kwargs.py
  <https://github.com/jfasch/2022-02-23/blob/main/livehacking/args-kwargs.py>`__)
* :doc:`/trainings/material/soup/python/advanced/closures/topic`
  (`closure.py
  <https://github.com/jfasch/2022-02-23/blob/main/livehacking/closure.py>`__)
* :doc:`/trainings/material/soup/python/advanced/decorators/topic`
  (`decorator.py
  <https://github.com/jfasch/2022-02-23/blob/main/livehacking/decorator.py>`__)

Continue with exercises: CSV |longrightarrow| modularization

* :doc:`/trainings/material/soup/python/misc/csv/topic`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvreader`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader`

Test Driven Development
.......................

.. sidebar:: Test Driven Development |longrightarrow| Clean Code

   .. list-table::
      :align: left
      
      * * * `Wikipedia: Test-driven development
            <https://en.wikipedia.org/wiki/Test-driven_development>`__
	  * `Kent Beck: Test Driven Development: By Example
            <https://www.oreilly.com/library/view/test-driven-development/0321146530/>`__
	  * `Clean Code: A Handbook of Agile Software Craftsmanship
            <https://www.oreilly.com/library/view/clean-code-a/9780136083238/>`__
	  * `Scrum <https://en.wikipedia.org/wiki/Scrum_(software_development)>`__
	* .. image:: tdd.jpg
	* .. image:: cleancode.jpg

I had stated my strong opinion about (excess) debugger usage. (In
short words, debuggers are from hell when you use one to *comprehend*
code that is otherwise incomprehensible - the same holds true for
excess IDE usage).

Discussion, naturally (thank you Alex). Decided to switch to test
driven development, provocantly. Based upon
:doc:`/trainings/material/soup/python/swdev/pytest-intro`, hacked the
following topics while introducing TDD:

* :doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader-function`
* :doc:`/trainings/material/soup/python/advanced/modules`
* :doc:`/trainings/material/soup/python/exercises/userdb/userdb_csv`

("Project" `here
<https://github.com/jfasch/2022-02-23/tree/main/userdb>`__)

2022-03-17
----------

Revisit yesterday's mess ...

* Show ``userdb`` "project" on `Github
  <https://github.com/jfasch/2022-02-23/tree/main/userdb>`__

  Plan for exercises: test driven

  * :doc:`Manager </about/myself/index>` writes test (and
    commits/pushes to Github)
  * Team mates `download ZIP file
    <https://github.com/jfasch/2022-02-23/archive/refs/heads/main.zip>`__
    (also done via the `"Code" button on project's main page
    <https://github.com/jfasch/2022-02-23>`__)
  * Team mates hack

* :doc:`/trainings/material/soup/python/swdev/pip/topic`
* :doc:`/trainings/material/soup/python/swdev/venv/topic`
* :doc:`/trainings/material/soup/python/swdev/pytest-intro`

Continue with mess ...

* Elaborate on ``class User`` |longrightarrow| require that
  constructor raise a dedicated exception if, for example, ``id`` is
  not an integer (requirement `here
  <https://github.com/jfasch/2022-02-23/blob/main/userdb/tests/test_user.py>`__)
* More requirements ... (`here
  <https://github.com/jfasch/2022-02-23/blob/main/userdb/tests/>`__)
* More ...

  * ``User`` "invalid ID" exception
  * "Duplicate ID in DB" exception
  * Common exception base class
  * ``collections.defaultdict``
  * :doc:`/trainings/material/soup/python/misc/db/group`

    * `sqlite3 user database test
      <https://github.com/jfasch/2022-02-23/blob/main/userdb/tests/test_sqlite_db.py>`__
    * `CSV to database program
      <https://github.com/jfasch/2022-02-23/blob/main/userdb/hcsv-to-sqlite3.py>`__

2022-03-31
----------

* :doc:`/trainings/material/soup/python/swdev/pip/topic`
* :doc:`/trainings/material/soup/python/swdev/venv/topic`

:doc:`PCAP exam </trainings/material/soup/python/pcap-exam>` preparation
........................................................................

* Look through
  https://www.udemy.com/course/python-certification-exam-pcap-31-03-practice-tests/
  (suggest subscription at Udemy)

  * :doc:`Notebook <notebook-wrapper>` section on OO

    * Duck typing
    * Interfaces
    * Implementation Inheritance
    * Method Resolution Order (MRO), and super()
    * Object Layout (``self``)

    .. image:: mro.png
       :scale: 50%

* Repeat these:

  * :doc:`/trainings/material/soup/python/advanced/starargs/topic`
  * :doc:`/trainings/material/soup/python/advanced/closures/topic`
  * :doc:`/trainings/material/soup/python/advanced/decorators/topic`
 
Links
-----

* `Raymond Hettinger - Super considered super! - PyCon 2015
  <https://www.youtube.com/watch?v=EiOglTERPEo&t=1808s>`__. **Raymond
  Hettinger**, revolving around ``super()`` and MRO.

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/EiOglTERPEo" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Transforming Code into Beautiful, Idiomatic Python
  <https://www.youtube.com/watch?v=OSGv2VnC0go>`__. **Raymond
  Hettinger**, reiterating his favorite phrase: "There must be a
  better way". (Hettinger is a "Python Core Developer".)

  (He uses Python 2 though.)

  .. raw:: html

     <iframe width="560" height="315" 
	     src="https://www.youtube.com/embed/OSGv2VnC0go" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Raymond Hettinger, Keynote on Concurrency, PyBay 2017 <https://www.youtube.com/watch?v=9zinZmE3Ogk>`__:
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

* `Python Tutorial: pip - An in-depth look at the package management
  system <https://www.youtube.com/watch?v=U2ZN104hIcc>`__, by `Corey
  Schafer
  <https://www.youtube.com/channel/UCCezIgC97PvUuR4_gbFUs5g>`__

  .. raw:: html

     <iframe width="560" height="315" src="https://www.youtube.com/embed/U2ZN104hIcc" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

* `Python Tutorial: VENV (Windows) - How to Use Virtual Environments
  with the Built-In venv Module
  <https://www.youtube.com/watch?v=APOPm01BVrk>`__: `Corey Schafer
  <https://www.youtube.com/channel/UCCezIgC97PvUuR4_gbFUs5g>`__
  again. :doc:`Virtual environments
  </trainings/material/soup/python/swdev/venv/topic>` are kind of an
  isolated development sandbox, solving a similar problem as
  containers do, but much more lightweight and Python only.

  .. raw:: html

     <iframe width="560" 
             height="315" 
	     src="https://www.youtube.com/embed/APOPm01BVrk" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Python Tutorial: Decorators - Dynamically Alter The Functionality
  Of Your Functions <https://www.youtube.com/watch?v=FsAPt_9Bf3U>`__,
  by `Corey Schafer
  <https://www.youtube.com/channel/UCCezIgC97PvUuR4_gbFUs5g>`__

  .. raw:: html

     <iframe width="560" height="315" 
	     src="https://www.youtube.com/embed/FsAPt_9Bf3U" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>
