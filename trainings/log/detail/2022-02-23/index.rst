.. include:: <mmlalias.txt>

Python Basics (2022-02-23 - 2022-02-25)
=======================================

.. sidebar:: *Training Information*

   * :doc:`/trainings/material/soup/python/basics/index`
   * :doc:`/trainings/material/soup/python/index`
   * Jupyter Notebook

     * :doc:`Structure <notebook-wrapper>`
     * :doc:`Entire Notebook <Notebook>`
     * :download:`download <Notebook.ipynb>`

   * `Github Repository <https://github.com/jfasch/2022-02-23>`__
   * Followup training to this one: :doc:`../2022-03-15/index`

.. toctree::
   :hidden:

   notebook-wrapper

.. contents::
   :local:

Day 1
-----

* :doc:`/trainings/material/soup/python/basics/installation`
* :doc:`/trainings/material/soup/python/misc/vscode`
* :doc:`/trainings/material/soup/python/basics/python_0110_blahblah/topic`
* :doc:`/trainings/material/soup/python/basics/python_0120_helloworld/topic`
* :doc:`/trainings/material/soup/python/basics/python_0130_syntax_etc/topic`
* :doc:`/trainings/material/soup/python/basics/python_0140_variables/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/basics/python_0160_boolean/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* Exercise: :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_interactive`
* Exercise:
  :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_executable`
  (Solution: `mixed-list.py
  <https://github.com/jfasch/2022-02-23/blob/main/exercises/joerg/mixed-list.py>`__)

Day 2
-----

* Quick walkthrough of data structures and algorithms

  .. list-table::
     :align: left

     * * .. image:: oh-notation.png
            :scale: 40%
       * Big-O Notation
     * * .. image:: binarytree.png
            :scale: 40%
       * (Unbalanced) binary tree
     * * .. image:: binarysearch.png
            :scale: 40%
       * Binary search in a *sorted* array
     * * .. image:: hashtable.png
            :scale: 40%
       * Hash table (very basic)
     * * .. raw:: html

            <iframe width="560" height="315" 
                    src="https://www.youtube.com/embed/p33CVV29OG8" 
       		    title="YouTube video player" 
       		    frameborder="0" 
       		    allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
       		    allowfullscreen>
            </iframe>
       * `Raymond Hettinger - Modern Dictionaries
	 <https://youtu.be/p33CVV29OG8>`__. **Raymond Hettinger**,
	 explaining how dictionaries are implemented.

* :doc:`/trainings/material/soup/python/basics/python_0139_commandline_argv/topic`
* Exercise:
  :doc:`/trainings/material/soup/python/exercises/legacy/cmdline_digit`
  (Solution: `digit.py
  <https://github.com/jfasch/2022-02-23/blob/main/exercises/joerg/digit.py>`__)
* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`

* Control Flow and Iteration

  * :doc:`/trainings/material/soup/python/basics/python_0170_if/topic`
  * Exercise:
    :doc:`/trainings/material/soup/python/exercises/legacy/max_numbers`
    (Solution: `maximum.py
    <https://github.com/jfasch/2022-02-23/blob/main/exercises/joerg/maximum.py>`__)
  * :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`
  * Exercise:
    :doc:`/trainings/material/soup/python/exercises/legacy/while_primeness`
    (Solution: `prime-while.py
    <https://github.com/jfasch/2022-02-23/blob/main/exercises/joerg/prime-while.py>`__)
  * :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`
  * :doc:`/trainings/material/soup/python/basics/python_0225_range/topic`
  * Exercise:
    :doc:`/trainings/material/soup/python/exercises/legacy/for_primeness`
    (Solution `prime-for.py
    <https://github.com/jfasch/2022-02-23/blob/main/exercises/joerg/prime-for.py>`__)

Day 3
-----

* Functions

  * :doc:`/trainings/material/soup/python/basics/python_0270_functions/topic`
  * Exercise: :doc:`/trainings/material/soup/python/exercises/legacy/uniq_function`
  * Short generators demo?

* Miscellaneous

  * :doc:`/trainings/material/soup/python/basics/python_0320_strings_methods/topic`
  * :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
  * :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`
  * :doc:`/trainings/material/soup/python/basics/python_0460_sets/topic`

* File I/O

  * :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`
  * :doc:`/trainings/material/soup/python/exercises/legacy/passwd`

* Into the wild: do something with GIS data

  * Sample data `here
    <https://github.com/jfasch/2022-02-23/tree/main/the-wild/data>`__
  * :doc:`/trainings/material/soup/python/misc/csv/topic`
  * `Open Source Geospatial Foundation
    <https://de.wikipedia.org/wiki/Open_Source_Geospatial_Foundation>`__
  * `GDAL Project <https://pypi.org/project/GDAL/>`__ on `PyPI <https://pypi.org/>`__
  * `PyPI <https://pypi.org/>`__

    * :doc:`/trainings/material/soup/python/swdev/pip/topic`
    * :doc:`/trainings/material/soup/python/swdev/venv/topic`

Further Information
-------------------

* `Book: Automate the Boring Stuff with Python (Al Sweigart)
  <https://automatetheboringstuff.com/>`__
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

Data Structures
...............

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

OS Things
.........

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

Data Science
............

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
