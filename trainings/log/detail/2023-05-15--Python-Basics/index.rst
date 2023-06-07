Python Basics (2023-05-15 - 2023-05-17)
=======================================

.. contents::
   :local:

.. toctree::
   :hidden:

   agenda
   notebook-wrapper

.. sidebar::

   **Original Agenda** 

   * :doc:`agenda`

   **Notebook**

   * Structure: :doc:`notebook-wrapper`
   * Entire notebook: :download:`notebook.ipynb`

   **Github Repository**

   * `https://github.com/jfasch/2023-05-15
     <https://github.com/jfasch/2023-05-15>`__

   **Material**

   * :doc:`/trainings/material/soup/python/group`

Day 1
-----

Setup
.....

* :doc:`/trainings/material/soup/python/basics/installation`
* :doc:`/trainings/material/soup/python/misc/vscode`

Basics
......

Datatypes
`````````

* :doc:`/trainings/material/soup/python/basics/python_0110_blahblah/topic`
* :doc:`/trainings/material/soup/python/basics/python_0120_helloworld/topic`
* :doc:`/trainings/material/soup/python/basics/python_0125_running/topic`
* :doc:`/trainings/material/soup/python/basics/python_0130_syntax_etc/topic`
* :doc:`/trainings/material/soup/python/basics/python_0139_commandline_argv/topic`
* :doc:`/trainings/material/soup/python/basics/python_0140_variables/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/basics/python_0160_boolean/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_interactive`
* :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_executable`
* :doc:`/trainings/material/soup/python/exercises/legacy/cmdline_digit` (solution: `digit.py <https://github.com/jfasch/2023-05-15/blob/main/livehacking/digit.py>`__)

Control Flow, Sequences, *Iteration*
````````````````````````````````````

* :doc:`/trainings/material/soup/python/basics/python_0170_if/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/max_numbers` (solution: `maximum.py <https://github.com/jfasch/2023-05-15/blob/main/livehacking/maximum.py>`__)
* :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/while_primeness` (solution: `prime-while.py <https://github.com/jfasch/2023-05-15/blob/main/livehacking/prime-while.py>`__)
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`
* :doc:`/trainings/material/soup/python/basics/python_0225_range/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/for_primeness` (solution: `prime-for.py <https://github.com/jfasch/2023-05-15/blob/main/livehacking/prime-for.py>`__)

More Datatypes
``````````````

* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`
* :doc:`/trainings/material/soup/python/basics/python_0270_functions/topic`

Day 2
-----

Morning Awakening
.................

Generators
``````````

* :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/topic`
* Generating infinitely many Fibonacci numbers: `fibonacci.py
  <https://github.com/jfasch/2023-05-15/blob/main/livehacking/fibonacci.py>`__
* Generating a sine wave: `sine.py
  <https://github.com/jfasch/2023-05-15/blob/main/livehacking/sine.py>`__
* Watching a directory for new files (by *iterating*): `watch-dir.py
  <https://github.com/jfasch/2023-05-15/blob/main/livehacking/watch-dir.py>`__

A Bit Of ``venv``, A Bit Of ``pip``
```````````````````````````````````

From :doc:`/trainings/material/soup/python/swdev/group`

* :doc:`/trainings/material/soup/python/swdev/venv/topic`
* :doc:`/trainings/material/soup/python/swdev/pip/topic`

Basics
......

More Datatypes
``````````````

* :doc:`/trainings/material/soup/python/exercises/legacy/primeness_function` (solution: `prime-function.py <https://github.com/jfasch/2023-05-15/blob/main/livehacking/prime-function.py>`__)
* :doc:`/trainings/material/soup/python/basics/python_0300_strings/topic`
* :doc:`/trainings/material/soup/python/basics/python_0320_strings_methods/topic`
* :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
* :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`
* :doc:`/trainings/material/soup/python/basics/python_0460_sets/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/uniq_function`
* :doc:`/trainings/material/soup/python/exercises/legacy/uniq_generator`
* :doc:`/trainings/material/soup/python/advanced/comprehensions/topic`
* :doc:`/trainings/material/soup/python/misc/encoding/topic`
* :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`

Exercise Series: CSV Files
..........................

* :doc:`/trainings/material/soup/python/misc/csv/topic`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvreader` (solution: `read-userdb-noheader.py <https://github.com/jfasch/2023-05-15/blob/main/livehacking/userdb/read-userdb-noheader.py>`__)
* :doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader` (solution: `read-userdb-header.py <https://github.com/jfasch/2023-05-15/blob/main/livehacking/userdb/read-userdb-header.py>`__)
* :doc:`/trainings/material/soup/python/exercises/userdb/csvreader-function` (solution: `read-userdb-noheader-func.py <https://github.com/jfasch/2023-05-15/blob/main/livehacking/userdb/read-userdb-noheader-func.py>`__)
* :doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader-function` (solution: `read-userdb-header-func.py <https://github.com/jfasch/2023-05-15/blob/main/livehacking/userdb/read-userdb-header-func.py>`__)
* :doc:`/trainings/material/soup/python/exercises/userdb/userdb_csv` (solution: `userdb_csv.py <https://github.com/jfasch/2023-05-15/blob/main/livehacking/userdb/userdb_csv.py>`__ (module), `read-userdb-noheader-mod.py <https://github.com/jfasch/2023-05-15/blob/main/livehacking/userdb/read-userdb-noheader-mod.py>`__, `read-userdb-header-mod.py <https://github.com/jfasch/2023-05-15/blob/main/livehacking/userdb/read-userdb-header-mod.py>`__)

Day 3
-----

Object Oriented Programming
...........................

From :doc:`/trainings/material/soup/python/advanced/oo/group`

* :doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/constructor/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/namedtuple/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/methods/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/str-repr/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/properties/topic`

(livehacked in `oo.py
<https://github.com/jfasch/2023-05-15/blob/main/livehacking/oo.py>`__)

Interleaved by a ``pytest`` installation into a virtual environment:

* :doc:`/trainings/material/soup/python/swdev/venv/topic`
* :doc:`/trainings/material/soup/python/swdev/pip/topic`
* :doc:`/trainings/material/soup/python/swdev/pytest/intro`

Followed by an exercise ...

* :doc:`/trainings/material/soup/python/exercises/userdb/user-class-person`

OO, cont'd ...

* :doc:`/trainings/material/soup/python/advanced/oo/inheritance/topic`
* :doc:`/trainings/material/soup/python/advanced/exceptions/topic`

(see also `oo.py
<https://github.com/jfasch/2023-05-15/blob/main/livehacking/oo.py>`__)

Advanced Language Features
..........................

* :doc:`/trainings/material/soup/python/advanced/context-mgr/topic`
  (livehacked - though the topic is a better read - in
  `context-manager.py
  <https://github.com/jfasch/2023-05-15/blob/main/livehacking/context-manager.py>`__)

Links
-----

Beginner
........

* `Python Tutorial for Beginners 4: Lists, Tuples, and Sets
  <https://www.youtube.com/watch?v=W8KRzm-HUcc>`__, by `Corey Schafer
  <https://www.youtube.com/channel/UCCezIgC97PvUuR4_gbFUs5g>`__

  .. raw:: html
	   
     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/W8KRzm-HUcc" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Python Tutorial for Beginners 5: Dictionaries - Working with
  Key-Value Pairs <https://www.youtube.com/watch?v=daefaLgNkw0>`__, by
  `Corey Schafer
  <https://www.youtube.com/channel/UCCezIgC97PvUuR4_gbFUs5g>`__

  .. raw:: html
	   
     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/daefaLgNkw0" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `10 Python Tips and Tricks For Writing Better Code
  <https://www.youtube.com/watch?v=C-gEQdGVXbk>`__, by `Corey Schafer
  <https://www.youtube.com/channel/UCCezIgC97PvUuR4_gbFUs5g>`__

  .. raw:: html
	   
     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/C-gEQdGVXbk" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

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

Modules from Standard Library
.............................

* `Python Tutorial: OS Module - Use Underlying Operating System
  Functionality <https://www.youtube.com/watch?v=tJxcKyFMTGo>`__, by
  `Corey Schafer
  <https://www.youtube.com/channel/UCCezIgC97PvUuR4_gbFUs5g>`__

  .. raw:: html

     <iframe width="560" height="315" 
	     src="https://www.youtube.com/embed/tJxcKyFMTGo" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Python Tutorial: Calling External Commands Using the Subprocess
  Module <https://www.youtube.com/watch?v=2Fp1N6dof0Y>`__, by `Corey
  Schafer
  <https://www.youtube.com/channel/UCCezIgC97PvUuR4_gbFUs5g>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/2Fp1N6dof0Y" 
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

Advanced
........

* `Transforming Code into Beautiful, Idiomatic Python
  <https://www.youtube.com/watch?v=OSGv2VnC0go>`__, by **Raymond
  Hettinger**

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/OSGv2VnC0go" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Python Tutorial: Duck Typing and Asking Forgiveness, Not Permission
  (EAFP) <https://www.youtube.com/watch?v=x3v9zMX1s4s>`__, by `Corey
  Schafer
  <https://www.youtube.com/channel/UCCezIgC97PvUuR4_gbFUs5g>`__

  .. raw:: html

     <iframe width="560" height="315" 
	     src="https://www.youtube.com/embed/x3v9zMX1s4s" 
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

Conference Talks
................

* `Built in Super Heroes
  <https://www.youtube.com/watch?v=lyDLAutA88s>`__. `David Beazley
  <https://www.dabeaz.com/>`__ in an entertaining keynote to the
  "PyData Chicago 2016" conference. He has a number of very good and
  entertaining (and very advanced) videos. You have to spend an entire
  evening with him though.

  .. raw:: html

     <iframe width="560" height="315" 
	     src="https://www.youtube.com/embed/lyDLAutA88s" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Keynote - David Beazley
  <https://www.youtube.com/watch?v=VUT386_GKI8>`__. `David Beazley
  <https://www.dabeaz.com/>`__ live
  coding a Web Assembly interpreter. PyCon India 2019.

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/VUT386_GKI8" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `David Beazley: Generators: The Final Frontier - PyCon 2014
  <https://www.youtube.com/watch?v=D1twn9kLmYg>`__: `David Beazley
  <https://www.dabeaz.com/>`__ again a bit (a whopping four hours)
  more precise on that topic.

  .. raw:: html

     <iframe width="560" 
             height="315" 
	     src="https://www.youtube.com/embed/D1twn9kLmYg" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>


