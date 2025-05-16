.. include:: <mmlalias.txt>


Python Advanced (2023-11-22 - 2023-22-24)
=========================================

.. toctree::
   :hidden:

   agenda
   notebook-wrapper

.. contents::
   :local:

.. sidebar::

   **Original Agenda** 

   * :doc:`agenda`

   **Github Repository**

   * https://github.com/jfasch/2023-11-22

   **Notebook**

   * Structure: :doc:`notebook-wrapper`
   * Entire notebook: :download:`notebook.ipynb`

   **Material**

   * :doc:`/trainings/material/soup/python/index`

Day 1: Basics
-------------

Before noon, we quickly ran through introductory material:

* :doc:`/trainings/material/soup/python/basics/python_0140_variables/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0225_range/topic`
* :doc:`/trainings/material/soup/python/basics/python_0300_strings/topic`

Also covered ``yield``, and the *Iterator Protocol*:

* :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/iterator-protocol`
* :doc:`/trainings/material/soup/python/advanced/iteration-generation/iteration-generation/topic`

Afternoon exercise:

* :doc:`/trainings/material/soup/python/exercises/legacy/uniq_function`

More Python:

* :doc:`/trainings/material/soup/python/basics/python_0310_strings_formatting/topic`
* :doc:`/trainings/material/soup/python/basics/python_0320_strings_methods/topic`
* :doc:`/trainings/material/soup/python/misc/encoding/topic`
* :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
* :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`
* :doc:`/trainings/material/soup/python/basics/python_0460_sets/topic`
* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`
* :doc:`/trainings/material/soup/python/basics/python_0500_files/topic` (including some ``with`` coverage)

Day 2: Group Project, And Object Oriented Programming
-----------------------------------------------------

Morning wakeup:

* Partial tuple unpacking with ``*``
* :doc:`/trainings/material/soup/python/basics/python_0270_functions/screenplay-scoping`

Project Management

* :doc:`/trainings/material/soup/python/swdev/venv/topic`
* :doc:`/trainings/material/soup/python/swdev/pip/topic`

From :doc:`/trainings/material/soup/python/advanced/oo/index`:
necessary material before we can start hacking

* :doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/constructor/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/methods/topic`

Hackin' da project ...

* Dictionary comprehension in ``SensorConfig``
* ``pytest`` fixtures: ``tmpdir``
* ``AcquisitionLoop`` test, using ``MockSink``
* Derive ``MockSink`` from ``list``

Day 3: OO, Hacking, Python Specials
-----------------------------------

From :doc:`/trainings/material/soup/python/advanced/oo/index`: all the rest

* :doc:`/trainings/material/soup/python/advanced/oo/str-repr/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/properties/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/namedtuple/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/inheritance/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/operator-overloading/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/abc/topic`

Project: lets create interfaces

* :doc:`/trainings/material/soup/python/advanced/exceptions/topic`
* :doc:`/trainings/material/soup/python/advanced/context-mgr/topic`

Closures, Decorators And More

* :doc:`/trainings/material/soup/python/advanced/starargs/topic`
* :doc:`/trainings/material/soup/python/advanced/closures/topic`
* :doc:`/trainings/material/soup/python/advanced/decorators/topic`

Videos
------

* `Grazer Linuxtage 2023: Pointless Blinking With Python, asyncio, and
  libgpiod (and a Raspberry Pi of Course)
  <https://pretalx.linuxtage.at/glt23/speaker/CBESAX/>`__. Jörg
  Faschingbauer, covering

  * GPIO using ``libgpiod`` (Python binding)
  * :doc:`python:library/asyncio`
  * Python decorators

  .. raw:: html
  
     <iframe width="560" height="315"
             src="https://media.ccc.de/v/glt23-322-pointless-blinking-with-python-asyncio-and-libgpiod-and-a-raspberry-pi-of-course-/oembed" 
  	   frameborder="0" 
  	   allowfullscreen>
     </iframe>

  See :doc:`talk notes, screenplay, etc. for more
  </about/site/work-in-progress/blink/index>`

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
