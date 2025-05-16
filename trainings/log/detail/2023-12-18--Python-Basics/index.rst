Python Basics (2023-12-18 - 2023-12-20)
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
   * Entire notebook: :doc:`notebook`
   * Download: :download:`notebook.ipynb`

   **Github Repository**

   * `https://github.com/jfasch/2023-12-18
     <https://github.com/jfasch/2023-12-18>`__

   **Material**

   * :doc:`/trainings/material/soup/python/index`

Setup
-----

* :doc:`/trainings/material/soup/python/basics/installation`
* :doc:`/trainings/material/soup/python/misc/vscode`

Datatypes
---------

* :doc:`/trainings/material/soup/python/basics/python_0110_blahblah/topic`
* :doc:`/trainings/material/soup/python/basics/python_0120_helloworld/topic`
* :doc:`/trainings/material/soup/python/basics/python_0125_running/topic`
* :doc:`/trainings/material/soup/python/basics/python_0130_syntax_etc/topic`
* :doc:`/trainings/material/soup/python/basics/python_0140_variables/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`

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

* :doc:`/trainings/material/soup/python/basics/python_0160_boolean/topic`

Exercise time:

* :doc:`/trainings/material/soup/python/basics/python_0139_commandline_argv/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_interactive`
* :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_executable`
* :doc:`/trainings/material/soup/python/exercises/legacy/cmdline_digit`

  * ``set``? ctor? -> iterable
  * Exchange key/value of a dict (``{str:int}`` -> ``{int:str}``)

Control Flow, Sequences, *Iteration*
------------------------------------

* :doc:`/trainings/material/soup/python/basics/python_0170_if/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/max_numbers`

  Here's the condensed version of it

  .. code-block:: python

     import sys
     print(max(map(int, sys.argv[1:])))

* :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/while_primeness`
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`
* :doc:`/trainings/material/soup/python/basics/python_0225_range/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/for_primeness`

Functions
---------

* :doc:`/trainings/material/soup/python/basics/python_0270_functions/slideshow`
* :doc:`/trainings/material/soup/python/basics/python_0270_functions/screenplay-scoping`
* :doc:`/trainings/material/soup/python/exercises/legacy/primeness_function`

More About Datatypes
--------------------

* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`
* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0300_strings/topic`
* :doc:`/trainings/material/soup/python/basics/python_0320_strings_methods/topic`
* :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
* :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`
* :doc:`/trainings/material/soup/python/basics/python_0460_sets/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/uniq_function`
* :doc:`/trainings/material/soup/python/exercises/legacy/uniq_generator`
* :doc:`/trainings/material/soup/python/advanced/comprehensions/topic`
* :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/distill`

Exercise Series: CSV Files
--------------------------

* :doc:`/trainings/material/soup/python/misc/csv/topic`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvreader`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvreader-function`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader-function`
* :doc:`/trainings/material/soup/python/exercises/userdb/userdb_csv`

A Bit Of OO
-----------

From :doc:`/trainings/material/soup/python/advanced/oo/index`

* :doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/constructor/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/methods/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/properties/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/namedtuple/topic`

Exercise:

* :doc:`/trainings/material/soup/python/exercises/userdb/user-class-person`
