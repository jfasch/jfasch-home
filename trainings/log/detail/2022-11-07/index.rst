Python (2022-11-07 - 2022-11-10, 2022-12-01)
============================================

.. contents::
   :local:

.. sidebar:: *Training Information*

   **Material**

   * :doc:`/trainings/material/soup/python/group`

   **Source Code**

   * `Github <https://github.com/jfasch/2022-11-07>`__. This is a
     *private project*; to view it you must be a collaborator.

   **Notebook**

   * :doc:`Structure <notebook-wrapper>`
   * :doc:`Whole notebook <notebook>`
   * :download:`Download <notebook.ipynb>`

Up Front: Project Management
----------------------------

* :doc:`/trainings/material/soup/linux/basics/intro/wsl`
* :doc:`/trainings/material/soup/python/swdev/pip/topic`
* :doc:`/trainings/material/soup/python/swdev/venv/topic`
* :doc:`/trainings/material/soup/python/swdev/pytest/intro`

Object Oriented Programming: Classes
------------------------------------

* From :doc:`/trainings/material/soup/python/advanced/oo/group`

  * :doc:`/trainings/material/soup/python/advanced/oo/constructor/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/methods/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/str-repr/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/properties/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/namedtuple/topic`

Exercise Series: CSV
--------------------

* :doc:`/trainings/material/soup/python/misc/csv/topic`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvreader`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvreader-function`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader-function`

Missing Pieces: Encoding, Unit Testing
--------------------------------------

* :doc:`/trainings/material/soup/python/misc/encoding/topic`
* Unit Testing (``pytest`` vs. ``unittest``)

  * :doc:`/trainings/material/soup/python/swdev/unittest`

    * `unittest sample suite
      <https://github.com/jfasch/2022-11-07/blob/main/livehacking/unittest/unittest-demo.py>`__
      (*Private Github project*)
    * `pytest sample suite
      <https://github.com/jfasch/2022-11-07/blob/main/livehacking/unittest/test_read_csv.py>`__
      (*Private Github project*)

  * :doc:`/trainings/material/soup/python/swdev/pytest/intro`

Exercise Series: CSV, JSON
--------------------------

* :doc:`/trainings/material/soup/python/exercises/userdb/userdb_csv`
* :doc:`/trainings/material/soup/python/exercises/userdb/user_json`
* :doc:`/trainings/material/soup/python/exercises/userdb/user-class-person`

Iteration, Generators
---------------------

* Iteration (Recap) (:doc:`see notebook <notebook-wrapper>`)
* :doc:`/trainings/material/soup/python/advanced/comprehensions/topic`
* Generators, The ``yield`` Keyword

  * :doc:`/trainings/material/soup/python/advanced/iteration-generation/iteration-generation/topic`
  * Generator Expressions

Operator Overloading
--------------------

* :doc:`/trainings/material/soup/python/advanced/oo/operator-overloading/topic`

Going Dynamic: ``type()``, ``exec()``
-------------------------------------

* ``type()``, ``exec()``. Revisit class dictionary, and build ``class
  Person`` dynamically. See demo `here
  <https://github.com/jfasch/2022-11-07/blob/main/livehacking/oo-fully-dynamic.py>`__
  (*Private Github project*)

More OO: Inheritance, Abstract Base Classes
-------------------------------------------

* From :doc:`/trainings/material/soup/python/advanced/oo/group`

  * :doc:`/trainings/material/soup/python/advanced/oo/inheritance/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/abc/topic`

Group Project Kickoff
---------------------

.. image:: project.jpg

Data Structures Recap
---------------------

* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
* :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`

Miscellaneous Livehacking
-------------------------

* Subprocess

  * `Livehacking
    <https://github.com/jfasch/2022-11-07/tree/main/livehacking/subprocess-demo.py>`__
  * Documentation: :doc:`python:library/subprocess`

* Network programming

  * `Livehacked client
    <https://github.com/jfasch/2022-11-07/tree/main/livehacking/client.py>`__
  * `Livehacked server
    <https://github.com/jfasch/2022-11-07/tree/main/livehacking/server.py>`__
  * Documentation: :doc:`python:library/socket`

Function Arguments, Closures, Decorators
----------------------------------------

* :doc:`/trainings/material/soup/python/advanced/starargs/topic`
  (`Livehacking <livehacking/args-kwargs.py>`__)
* :doc:`/trainings/material/soup/python/advanced/closures/topic`
  (`Livehacking <livehacking/closures.py>`__)
* :doc:`/trainings/material/soup/python/advanced/decorators/topic`
  (`Livehacking <livehacking/decorator.py>`__)

Exceptions, ``with``
--------------------

* :doc:`/trainings/material/soup/python/advanced/exceptions/topic`
  (`Livehacking
  <https://github.com/jfasch/2022-11-07/blob/main/livehacking/exceptions.py>`__)
* :doc:`/trainings/material/soup/python/advanced/context-mgr/topic`
  (`Livehacking
  <https://github.com/jfasch/2022-11-07/blob/main/livehacking/context-mgr.py>`__)

Package Management
------------------

* :doc:`/trainings/material/soup/python/swdev/venv/topic`
* :doc:`/trainings/material/soup/python/drafts/setuptools/topic`

Videos
------

Beginner
........

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

* `Publishing (Perfect) Python Packages on PyPi
  <https://youtu.be/GIF3LaRqgXo>`__

  .. raw:: html

     <iframe
         width="560" height="315" 
	 src="https://www.youtube.com/embed/GIF3LaRqgXo" 
	 title="YouTube video player" 
	 frameborder="0" 
	 allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	 allowfullscreen>
     </iframe>

Fun
...

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

* `Iterations of Evolution: The Unauthorized Biography of the For-Loop
  <https://www.youtube.com/watch?v=2AXuhgid7E4>`__. `David Beazley
  <https://www.dabeaz.com/>`__ giving lessons in history. How ``for``
  evolved from the beginning until where we are today.

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/2AXuhgid7E4" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

* `The Fun of Reinvention - David Beazley - Pycon Israel 2017
  <https://www.youtube.com/watch?v=5nXmq1PsoJ0&t=1263s>`__. `David
  Beazley <https://www.dabeaz.com/>`__ with an entertaining keynote
  about typing, type annotations, metaprogramming, contracts.

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/5nXmq1PsoJ0" 
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

