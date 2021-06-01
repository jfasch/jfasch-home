.. include:: <mmlalias.txt>

Python Advanced (2021-05-25 - 2021-05-27)
=========================================

.. sidebar:: *Training Information*

   **Offizielle Beschreibung**

   `tecTrain "Python Vertiefung"
   <https://www.tectrain.at/seminare/seminar-themen/programmierung/python-vertiefung>`__

   **Material**

   * PDF Slides, :download:`Python </trainings/material/pdf/300-python.pdf>`
   * :doc:`OpenTraining </about/site/opentraining/index>` Topics, :doc:`/trainings/material/soup/python/index`

.. contents::
   :local:

Notebook
--------

:download:`Download Notebook <Notebook.ipynb>`

.. toctree::

   Jupyter Notebook <Notebook>

Topics
------

* :doc:`/trainings/material/soup/python/draft/closures/topic`
* :doc:`/trainings/material/soup/python/draft/starargs/topic`
* :doc:`/trainings/material/soup/python/draft/decorators/topic`


jjjj

https://docs.python.org/3/library/exceptions.html  


Predefined streams
..................

.. literalinclude:: wc.py
   :caption: :download:`Download wc.py <wc.py>`

PCAP Exam Syllabus
------------------

(Taken from `here
<https://pythoninstitute.org/certification/pcap-certification-associate/pcap-exam-syllabus/>`__)

**Exam block #1: Modules and Packages (12%)**

Objectives covered by the block (6 items)

* import variants; advanced qualifiying for nested modules

  Comment: ``os.path``

* dir(); sys.path variable
* math: ceil(), floor(), trunc(), factorial(), hypot(), sqrt(); random: random(), seed(), choice(), sample()
* platform: platform(), machine(), processor(), system(), version(), python_implementation(), python_version_tuple()
* idea, __pycache__, __name__, public variables, __init__.py
* searching for modules/packages; nested packages vs directory tree

**Exam block #2: Exceptions (14%)**

Objectives covered by the block (5 items)

* except, except:-except; except:-else:, except (e1,e2)
* the hierarchy of exceptions
* raise, raise ex, assert
* event classes, except E as e, arg property
* self-defined exceptions, defining and using

**Exam block #3: Strings (18%)**

Objectives covered by the block (8 items)

* ASCII, UNICODE, UTF-8, codepoints, escape sequences
* ord(), chr(), literals
* indexing, slicing, immutability
* iterating through,
* concatenating, multiplying, comparing (against strings and numbers)
* in, not in
* .isxxx(), .join(), .split()
* .sort(), sorted(), .index(), .find(), .rfind()

**Exam block #4: Object-Oriented Programming (34%)**

Objectives covered by the block (12 items)

* ideas: class, object, property, method, encapsulation, inheritance, grammar vs class, superclass, subclass
* instance vs class variables: declaring, initializing
* __dict__ property (objects vs classes)
* private components (instance vs classes), name mangling
* methods: declaring, using, self parameter
* instrospection: hasattr() (objects vs classes), __name__, __module__, __bases__ properties
* inheritance: single, multiple, isinstance(), overriding, not is and is operators
* constructors: declaring and invoking
* polymorphism
* __name__, __module__, __bases__ properties, __str__() method
* multiple inheritance, diamonds

**Exam block #5: Miscellaneous (List Comprehensions, Lambdas, Closures, and I/O Operations) (22%)**

Objectives covered by the block (9 items)

* list comprehension: if operator, using list comprehensions
* lambdas: defining and using lambdas, self-defined functions taking lambda as as arguments; map(), filter();
* closures: meaning, defining, and using closures
* I/O Operations: I/O modes, predefined streams, handles; text/binary modes
* open(), errno and its values; close()
* .read(), .write(), .readline(); readlines() (along with bytearray())

Further Information
-------------------

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

* `Python Tutorial: Unit Testing Your Code with the unittest Module
  <https://www.youtube.com/watch?v=6tNS--WetLI>`__, by `Corey Schafer
  <https://www.youtube.com/channel/UCCezIgC97PvUuR4_gbFUs5g>`__

  .. raw:: html

     <iframe width="560" height="315" 
	     src="https://www.youtube.com/embed/6tNS--WetLI" 
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

* `Raymond Hettinger - Super considered super! - PyCon 2015
  <https://www.youtube.com/watch?v=EiOglTERPEo&t=1808s>`__. **Raymond
  Hettinger**, iterating all around ``super()`` and MRO.

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/EiOglTERPEo" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>
