.. include:: <mmlalias.txt>

Python Advanced (2022-05-16 - 2022-05-18)
=========================================

.. toctree:: 
   :hidden:

   notebook

.. sidebar:: *Training Information*

   **Material**

   * :doc:`/trainings/material/soup/python/group`
   * `Github Repository <https://github.com/jfasch/2022-05-16>`__

   **Notebook**

   * :doc:`Structure <notebook-wrapper>`
   * :doc:`Whole notebook <notebook>`
   * :download:`Download <notebook.ipynb>`

   **Predecessor Training**

   * :doc:`../2022-04-25/index`

.. contents::
   :local:

Log
---

Project Management
..................

* :doc:`/trainings/material/soup/python/swdev/venv/topic`
* :doc:`/trainings/material/soup/python/swdev/pip/topic`

Unit Testing, Test Driven Development
.....................................

* :doc:`/trainings/material/soup/python/swdev/pytest-intro`

Object Priented Programming
...........................

* :doc:`/trainings/material/soup/python/advanced/oo/group`

*"class Person" basics*

* `test_person_basics.py
  <https://github.com/jfasch/2022-05-16/blob/main/tests/test_person_basics.py>`__
* `person.py <https://github.com/jfasch/2022-05-16/blob/main/person.py>`__

**Weiteres Vorgehen**

* Download project from `Github
  <https://github.com/jfasch/2022-05-16>`__

  .. image:: download-project.png
     :scale: 50%

* Optional: create a virtual environment, as described in
  :doc:`/trainings/material/soup/python/swdev/venv/screenplay`, and
  activate it.
* Unpack ZIP file into *project directory* (say, ``C:\Users\Student\my-project``)
* Open command prompt (aka terminal)
* Change into that directory (using the ``cd`` command: ``cd
  C:\Users\Student\my-project``)
* If not yet up-to-date: install requirements () as specified in the
  ``requirements.txt`` file (which is part of the project)

  .. code-block:: console

     $ python -m pip install -r requirements.txt

* Run tests to see what the project status is:

  .. code-block:: console

     $ python -m pytest
     ============================================================== test session starts ===============================================================
     platform linux -- Python 3.9.12, pytest-7.1.2, pluggy-1.0.0
     rootdir: /home/jfasch/tmp/2022-05-16
     collected 5 items                                                                                                                                
     
     tests/test_person_basics.py xx                                                                                                             [ 40%]
     tests/test_persondb_basics.py x                                                                                                            [ 60%]
     tests/test_pytest_demo.py ..                                                                                                               [100%]
     
     ========================================================== 2 passed, 3 xfailed in 0.02s ==========================================================

* Fix tests

OO: next exercise (CSV as always |:rolling_eyes:|)
..................................................

* :doc:`/trainings/material/soup/python/misc/csv/topic`

Exercise: Exception Handling
............................

* :doc:`/trainings/material/soup/python/advanced/exceptions`
* :doc:`Notebook->Exceptions <notebook-wrapper>`

Fix tests in `tests/test_persondb.py
<https://github.com/jfasch/2022-05-16/blob/main/tests/test_persondb.py>`__. One
by one, remove the ``@pytest.mark.xfail`` decorator, and fix failures
from:

* ``test_duplicate_svnr()``
* ``test_update_sunnycase()``
* ``test_update_notexist()``
* ``test_update_exact_duplicate()``

Notes:

* See :doc:`Notebook->Exceptions <notebook-wrapper>` for how to define
  and raise exceptions (and for how to handle exceptions - though only
  the former is relevant for the purpose of completing the exercises)
* A number of exception types need to be created. It is up to you
  *where* to define them - the simplest way is to define them right in
  ``persondb.py`` for now.

Standesregister nach SQLite3
............................

.. sidebar:: Topics

   * :doc:`/trainings/material/soup/python/misc/db/group`

.. code-block:: console

   $ sqlite3 data/standesregister.sqlite3 
   SQLite version 3.34.1 2021-01-20 14:10:07
   Enter ".help" for usage hints.
   sqlite> CREATE TABLE persons (svnr text, firstname text, lastname text);
   sqlite> .schema
   CREATE TABLE persons (svnr text, firstname text, lastname text);

Write new program ...

.. code-block:: console

   $ python persondb-csv-to-sqlite3.py data/standesregister.csv data/standesregister.sqlite3

To Do
-----

**Miscellaneous**

* :doc:`/trainings/material/soup/python/basics/python_0139_commandline_argv/topic`
* :doc:`/trainings/material/soup/python/advanced/starargs/topic`
* :doc:`/trainings/material/soup/python/advanced/closures/topic`
* :doc:`/trainings/material/soup/python/advanced/decorators/topic`

Links
-----

Basic Python
............

* `Python Tutorial: Using Try/Except Blocks for Error Handling
  <https://www.youtube.com/watch?v=NIWwJbo-9_8>`__, by `Corey Schafer
  <https://www.youtube.com/channel/UCCezIgC97PvUuR4_gbFUs5g>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/NIWwJbo-9_8" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Python Tutorial: re Module - How to Write and Match Regular
  Expressions (Regex)
  <https://www.youtube.com/watch?v=K8L6KVGG-7o>`__, by `Corey Schafer
  <https://www.youtube.com/channel/UCCezIgC97PvUuR4_gbFUs5g>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/K8L6KVGG-7o" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Python Tutorial: CSV Module - How to Read, Parse, and Write CSV
  Files <https://www.youtube.com/watch?v=q5uM4VKywbA>`__, by `Corey
  Schafer
  <https://www.youtube.com/channel/UCCezIgC97PvUuR4_gbFUs5g>`__

  .. raw:: html
	   
     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/q5uM4VKywbA" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

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

NumPy and Data Science Tutorials
................................

* `Complete Python NumPy Tutorial (Creating Arrays, Indexing, Math,
  Statistics, Reshaping)
  <https://www.youtube.com/watch?v=GB9ByFAIAH4>`__, by `Keith Galli
  <https://www.youtube.com/channel/UCq6XkhO5SZ66N04IcPbqNcw>`__

  .. raw:: html
	   
     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/GB9ByFAIAH4" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Solving real world data science tasks with Python Pandas!
  <https://www.youtube.com/watch?v=eMOA1pPVUc4>`__, by `Keith Galli
  <https://www.youtube.com/channel/UCq6XkhO5SZ66N04IcPbqNcw>`__

  .. raw:: html
	   
     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/eMOA1pPVUc4" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Intro to Data Visualization in Python with Matplotlib! (line graph,
  bar chart, title, labels, size)
  <https://www.youtube.com/watch?v=DAQNHzOcO5A>`__, by `Keith Galli
  <https://www.youtube.com/channel/UCq6XkhO5SZ66N04IcPbqNcw>`__

  .. raw:: html

     <iframe width="560" height="315"
             src="https://www.youtube.com/embed/DAQNHzOcO5A" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

