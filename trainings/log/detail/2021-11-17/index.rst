.. include:: <mmlalias.txt>

Python Basics (2021-11-17 - 2021-11-19)
=======================================

.. sidebar::

   **Material**

   * :doc:`Python Basics </trainings/material/soup/python/basics/group>`
   * :doc:`Python </trainings/material/soup/python/group>`
   * Jupyter Notebook: :doc:`HTML <notebook-wrapper>`,
     :download:`download <Notebook.ipynb>`
   * `Github Repository <https://github.com/jfasch/2021-11-17>`__

.. toctree::
   :hidden:

   Jupyter Notebook (Übersicht) <notebook-wrapper>
   Jupyter Notebook <Notebook>

.. contents::
   :local:

Day 1
-----

* :doc:`/trainings/material/soup/python/basics/installation`
* :doc:`/trainings/material/soup/python/basics/python_0110_blahblah/topic`
* :doc:`/trainings/material/soup/python/basics/python_0120_helloworld/topic`
* :doc:`/trainings/material/soup/python/basics/python_0130_syntax_etc/topic`
  
  .. literalinclude:: code/argv.py
     :caption: :download:`code/argv.py`

* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`

  Explaining how Python integers work (they don't overflow), we came
  up with an overflow demo in C.

  .. literalinclude:: code/overflow.c
     :caption: :download:`code/overflow.c`

* :doc:`/trainings/material/soup/python/basics/python_0140_variables/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/basics/python_0160_boolean/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_interactive`
* :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_executable`
* :doc:`/trainings/material/soup/python/basics/python_0170_if/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/max_numbers`

  .. literalinclude:: code/maximum.py
     :caption: :download:`code/maximum.py`

Day 2
-----

* :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`

  * ``while`` and ``for`` in C (similar in Jave and C#): ``for`` is
    just a shorthand for ``while`` - as opposed to Python.

    .. literalinclude:: code/loops.c
       :caption: :download:`code/loops.c`

* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/uniq_function`

  .. image:: uniq-algo.png
     :scale: 50%

  .. literalinclude:: code/uniq.py
     :caption: :download:`code/uniq.py`

* :doc:`/trainings/material/soup/python/exercises/legacy/passwd`

  * Solution 1: relatively explicit and long

    .. literalinclude:: code/getuser.py
       :caption: :download:`code/getuser.py`

  * Solution 2: dense, short, requires a bit of programming pratice
    (not much though)

    .. literalinclude:: code/getuser-dense.py
       :caption: :download:`code/getuser-dense.py`

Day 3
-----

* Back to
  :doc:`/trainings/material/soup/python/exercises/legacy/uniq_function`:
  ``set`` usage for speed!
* :doc:`/trainings/material/soup/python/basics/python_0225_range/topic`
* :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
* :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`
* :doc:`/trainings/material/soup/python/basics/python_0460_sets/topic`
* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`
* :doc:`/trainings/material/soup/python/basics/python_0270_functions/topic`
* :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`


Jupyter Notebook
----------------

* :doc:`Jupyter Notebook (Übersicht) <notebook-wrapper>`
* :doc:`Jupyter Notebook <Notebook>`
* :download:`Download <Notebook.ipynb>`

Links
-----

jjj

* Python doc
* PyPI
* Studio Code
* corey schafer re
* corey schafer was noch?

Visual Studio Code
..................

* `Visual Studio Code (Windows) - Setting up a Python Development
  Environment and Complete Overview
  <https://www.youtube.com/watch?v=-nh9rCzPJ20>`__, by `Corey Schafer
  <https://www.youtube.com/channel/UCCezIgC97PvUuR4_gbFUs5g>`__

  .. raw:: html
  
     <iframe width="560" 
             height="315" 
	     src="https://www.youtube.com/embed/-nh9rCzPJ20" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `Visual Studio Code (Mac) - Setting up a Python Development
  Environment and Complete Overview
  <https://www.youtube.com/watch?v=06I63_p-2A4>`__, by `Corey Schafer
  <https://www.youtube.com/channel/UCCezIgC97PvUuR4_gbFUs5g>`__

  .. raw:: html
  
     <iframe width="560" height="315" 
	     src="https://www.youtube.com/embed/06I63_p-2A4" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

Python (Core Topics)
....................

* `5 Common Python Mistakes and How to Fix Them
  <https://www.youtube.com/watch?v=zdJEYhA2AZQ>`__, by `Corey Schafer
  <https://www.youtube.com/channel/UCCezIgC97PvUuR4_gbFUs5g>`__

  .. raw:: html
	   
     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/zdJEYhA2AZQ" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

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

Python Standard Library
.......................

jjj
