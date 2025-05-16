Python Basics (2023-06-20 - 2023-06-22)
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

   * `https://github.com/jfasch/2023-06-20
     <https://github.com/jfasch/2023-06-20>`__

   **Material**

   * :doc:`/trainings/material/soup/python/index`

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
* :doc:`/trainings/material/soup/python/basics/python_0139_commandline_argv/topic` (livehacked: `argv.py <https://github.com/jfasch/2023-06-20/blob/main/livehacking/argv.py>`__)
* :doc:`/trainings/material/soup/python/basics/python_0140_variables/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/basics/python_0160_boolean/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_interactive`
* :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_executable`
* :doc:`/trainings/material/soup/python/exercises/legacy/cmdline_digit` (solution: `digit.py <https://github.com/jfasch/2023-06-20/blob/main/livehacking/digit.py>`__

Control Flow, Sequences, *Iteration*
````````````````````````````````````

* :doc:`/trainings/material/soup/python/basics/python_0170_if/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/max_numbers` (solution, in one line, using a generator expression |:wink:|: `maximum.py <https://github.com/jfasch/2023-06-20/blob/main/livehacking/maximum.py>`__)

Miscellaneous
`````````````

* *Generating* Fibonacci numbers: `fibonacci.py
  <https://github.com/jfasch/2023-06-20/blob/main/livehacking/fibonacci.py>`__

Day2
----

Morning Wakeup
..............

* Index-based vs. element-based iteration
* ``yield``, again: sequence of yielded element (three in a row), with
  debug statement in between
* :doc:`/trainings/material/soup/python/advanced/iteration-generation/iteration-generation/topic`

Basics
......

Control Flow, Sequences, *Iteration*
````````````````````````````````````

* :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/while_primeness`
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`
* :doc:`/trainings/material/soup/python/basics/python_0225_range/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/for_primeness` (solution: `prime.py <https://github.com/jfasch/2023-06-20/blob/main/livehacking/prime.py>`__)

More Datatypes
```````````````

* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`
* From :doc:`/trainings/material/soup/python/basics/python_0270_functions/topic` ...

  * :doc:`/trainings/material/soup/python/basics/python_0270_functions/slideshow`
  * :doc:`/trainings/material/soup/python/basics/python_0270_functions/screenplay-scoping`

* :doc:`/trainings/material/soup/python/exercises/legacy/primeness_function` (solution: `prime-function.py <https://github.com/jfasch/2023-06-20/blob/main/livehacking/prime-function.py>`__)
* :doc:`/trainings/material/soup/python/basics/python_0300_strings/topic`
* :doc:`/trainings/material/soup/python/basics/python_0320_strings_methods/topic`
* :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
* :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`
* :doc:`/trainings/material/soup/python/basics/python_0460_sets/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/uniq_function` (solution: `uniq-function.py <https://github.com/jfasch/2023-06-20/blob/main/livehacking/uniq-function.py>`__)
* :doc:`/trainings/material/soup/python/exercises/legacy/uniq_generator` (solution: `uniq-generator.py <https://github.com/jfasch/2023-06-20/blob/main/livehacking/uniq-generator.py>`__)
* :doc:`/trainings/material/soup/python/advanced/comprehensions/topic`

Day 3
-----

File I/O, And Encoding
......................

* :doc:`/trainings/material/soup/python/misc/encoding/topic`
* :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/distill`

  * Solution: `distill.py <https://github.com/jfasch/2023-06-20/blob/main/livehacking/distill.py>`__
  * Alternative solution, using a generator expression:
    `distill-yield.py
    <https://github.com/jfasch/2023-06-20/blob/main/livehacking/distill-yield.py>`__

Exercise Series: CSV Files
..........................

* :doc:`/trainings/material/soup/python/misc/csv/topic`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvreader`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvreader-function`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader-function`
* :doc:`/trainings/material/soup/python/exercises/userdb/userdb_csv`
* Solution: `csv-exercises/
  <https://github.com/jfasch/2023-06-20/tree/main/csv-exercises>`__

Links
-----

Books
.....

* `Automate the Boring Stuff with Python (Al Sweigart)
  <https://automatetheboringstuff.com/>`__
* `Fluent Python (Luciano Ramalho)
  <https://www.oreilly.com/library/view/fluent-python-2nd/9781492056348/>`__

Python Videos
.............

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

* `Python Tutorial for Beginners 7: Loops and Iterations - For/While
  Loops <https://www.youtube.com/watch?v=6iF8Xb7Z3wQ>`__, by `Corey
  Schafer
  <https://www.youtube.com/channel/UCCezIgC97PvUuR4_gbFUs5g>`__

  .. raw:: html
	   
     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/6iF8Xb7Z3wQ" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Python Tutorial for Beginners 8: Functions
  <https://www.youtube.com/watch?v=9Os0o3wzS_I>`__, by `Corey Schafer
  <https://www.youtube.com/channel/UCCezIgC97PvUuR4_gbFUs5g>`__

  .. raw:: html
	   
     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/9Os0o3wzS_I" 
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

* `Python Quick Tip: F-Strings - How to Use Them and Advanced String
  Formatting <https://www.youtube.com/watch?v=nghuHvKLhJA>`__, by
  `Corey Schafer
  <https://www.youtube.com/channel/UCCezIgC97PvUuR4_gbFUs5g>`__

  .. raw:: html
	   
     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/nghuHvKLhJA" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

NumPy, Pandas, Matplotlib
.........................

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
