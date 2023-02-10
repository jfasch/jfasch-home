Clean Code Development With Python (2023-03-28 - 2023-03-30)
============================================================

.. contents::
   :local:

.. sidebar::

  **Github Repository**

  * https://github.com/jfasch/2023-03-28.git

Work Environment
----------------

* Python Installation

  * `Installing directly from python.org
    <https://www.python.org/downloads/>`__
  * `Anaconda <https://www.anaconda.com/>`__

* IDE

  * :doc:`/trainings/material/soup/python/misc/vscode`
  * `PyCharm <https://www.jetbrains.com/pycharm/>`__

* Package Installation, Virtual Environments

  * :doc:`/trainings/material/soup/python/swdev/pip/topic`
  * :doc:`/trainings/material/soup/python/swdev/venv/topic`
      
*Day 1:* Python Development: Select Topics
------------------------------------------

Up front, something about *Python The Language*. Exercise material not
shown, will pick that from :doc:`here
</trainings/material/soup/python/exercises/group>` as appropriate, or
invent something new.

Basics, And Datatypes
.....................

A quick run-through covering Python basics, and its built-in
datatypes. Neat insights into Python's internals ("everything is an
object"), iterators, and slicing (the basis for `NumPy <numpy.org>`__
array handling).

* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`

Advanced Topics
...............

There always more about Python. Error handling, automatic resource
cleanup, modularization.

* :doc:`/trainings/material/soup/python/advanced/exceptions/topic`
* :doc:`/trainings/material/soup/python/advanced/context-mgr/topic`
* :doc:`/trainings/material/soup/python/advanced/iteration-generation/topic`
* :doc:`/trainings/material/soup/python/advanced/modules`

(To be created) Presentable material and exercises about

* `NumPy <https://numpy.org/>`__
* `pandas <https://pandas.pydata.org/>`__

Optional
........

Even more about Python. Interesting and useful stuff; optional
nonetheless.

* :doc:`/trainings/material/soup/python/advanced/starargs/topic`
* :doc:`/trainings/material/soup/python/advanced/closures/topic`
* :doc:`/trainings/material/soup/python/advanced/decorators/topic`
* :doc:`/trainings/material/soup/python/advanced/multithreading/group`

*Day 2:* Clean Code? (Software Development: A Craft)
----------------------------------------------------

Messages From *The Book*
........................

.. image:: clean-code.jpg
   :align: right
   :height: 300px

The following material (which has been created for a similar show, but
in C++) will be adapted for our seminar. Goal is to start a discussion
on ... well ... software development, and how it is
understood. *Agile*.

* :doc:`/about/site/work-in-progress/2022-04-13/seminar/craft-sw`
* Survey of *The Book* (taken from
  :doc:`/about/site/work-in-progress/2022-04-13/seminar/clean-code-craftsmanship`,
  but polished and Pythonized)

Condensed version of the following talk series by Bob Martin which
takes two days to watch:

* `Clean Code - Uncle Bob / Lesson 1 <https://youtu.be/7EmboKQH8lM>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/7EmboKQH8lM" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>

* `Clean Code - Uncle Bob / Lesson 2 <https://youtu.be/2a_ytyt9sf8>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/2a_ytyt9sf8" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>

* `Clean Code - Uncle Bob / Lesson 3 <https://youtu.be/Qjywrq2gM8o>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/Qjywrq2gM8o" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>

* `Clean Code - Uncle Bob / Lesson 4 <https://youtu.be/58jGpV2Cg50>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/58jGpV2Cg50" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>

* `Clean Code - Uncle Bob / Lesson 5 <https://youtu.be/sn0aFEMVTpA>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/sn0aFEMVTpA" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>

* `Solid Principles by Uncle Bob Martin <https://youtu.be/oar-T2KovwE>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/oar-T2KovwE" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>

Object Oriented Programming
...........................

Python is not a strict OO language: it does not require anybody to
know what a class is. It does bring all features that such languages
usually bring, though, and if one knows more, one can *do* more.

Conversely, Python's *internals* are stongly object oriented. ``int``
and ``float`` are objects, for example, and functions and classes are,
too, as are modules and iterators/generators, to name a few more.

It looks like OO is not entirely bad. OO has made its way into
software development, it is part of our "craft", so lets have a deeper
look at it.

From :doc:`/trainings/material/soup/python/advanced/oo/group`:

* :doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/constructor/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/methods/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/str-repr/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/properties/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/namedtuple/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/inheritance/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/operator-overloading/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/abc/topic`

Exercises: there is some in
:doc:`/trainings/material/soup/python/advanced/oo/group` that we could
pick from. Lets think about something more to the point though.

Design Patterns
...............

*Discussion*: so what? OO is there to solve problems in a readable and
reproducible way.

* :doc:`/trainings/material/soup/cxx-design-patterns/uml/uml`
* :doc:`/trainings/material/soup/cxx-design-patterns/oo-principles`
* Pythonize *some* patterns (the simpler ones) from
  :doc:`/trainings/material/soup/cxx-design-patterns/group`. Maybe ...

  * Adapter
  * Proxy
  * Composite
  * Observer

Unit Testing
............

No craft without testing. Again, automated testing is part of software
development for a long time now. Developers, and their employers
likewise, do not always recognize the goodness of non-immediacy.

Ease the technical hurdle, give terminology, discuss (unit tests as
documentation). The exercises in this training will be formulated as
unit tests, so maybe this chapter is in order right at the beginning
of it.

* :doc:`/trainings/material/soup/python/swdev/pytest-intro`

*Day 3*: Group Exercise
-----------------------

To be designed. Will be the subject of one or two successor meeting.
