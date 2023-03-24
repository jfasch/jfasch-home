.. include:: <mmlalias.txt>

The Iterator Protocol
=====================

.. contents::
   :local:

Iteration in Python
-------------------

.. sidebar::

   **Documentation**

   * Iterable, Iterator: :doc:`Python Glossary <python:glossary>`
   * :doc:`python:library/itertools`
   * :doc:`python:library/operator`

* ``for`` loops are very common in Python
* They operate on *iterators*
* Just about any composite data type is *iterable*

  * Lists
  * Dictionaries
  * Strings
  * Files
  * ...

What's an Iterator?
-------------------

An iterator is an object that yields a *data stream* ...

* The ``next()`` method yields the next element in the stream
* If there is no next element, it raises the ``StopIteration``
  exception

**Question:** where do iterators come from?

**Answer:** they are made by *iterables*

What's an Iterable?
-------------------

* *Iterables* are objects that support *iteration* (Gosh!)
* Iterables that are built into Python are for example ...

  * Sequence, tuple
  * Dictionary (iteration yields key/value pairs)
  * Set
  * String
  * File
  * ... and many more ...

The Iterator Protocol
---------------------

Technically speaking ...

* An *iterable* can make an *iterator* through the ``__iter__()``
  method (called when ``iter()`` is used on an object)
* Not usually done by hand
* Done for me by ``for`` loop

.. code-block:: python

   for elem in iterable:
       ... do something with elem ...

The Iterator Protocol: Manual Iteration
---------------------------------------

* Use ``iter()`` to create an *iterator* (types that support creating
  an iterator are said to be *iterable*)

  .. jupyter-execute::
  
     elements = [1,2,3]
     iterator = iter(elements)

* Use ``next()`` on it to pull out three items

  .. jupyter-execute::
  
     next(iterator)

  .. jupyter-execute::
  
     next(iterator)

  .. jupyter-execute::
  
     next(iterator)

* ``StopIteration`` is raised when exhausted

  .. jupyter-execute::
     :raises:

     next(iterator)  

The Iterator Protocol, And The ``for`` Loop
-------------------------------------------

* *What does that mean*?
* Lets dissect the following simple ``for`` loop

  .. jupyter-execute::
  
     elements = [1,2,3]
     for element in elements:
         print(element)

* Internally, that is implemented as follows ...
* *Setup* phase (before ``for`` begins): retrieve *iterator* from
  *iterable*

  .. jupyter-execute:: 
  
     iterator = iter(elements)

* *Generate* next element until ``StopIteration`` exception

  .. jupyter-execute:: 
  
     while True:
         try:
             element = next(iterator)
             print(element)
         except StopIteration:
             break

Generators: Motivation
----------------------

* Often the calculation of the next element is complicated
* |longrightarrow| object state has to be kept manually
* Coding iterables is no fun
* ... at least not without language support

**Examples of complicated iteration ...**

* Traverse a binary tree in depth-first or breadth-first order
* Infinite sets like Fibonacci numbers

**Stupid solution:**

.. sidebar::

   **See also**

   * :doc:`fibonacci-generator`

* Store result in a list
* Return the list
* |longrightarrow| Problem with large iterables (Fibonacci?)
* |longrightarrow| Best to *generate* on-demand

Generators: How?
----------------

The following code fragment *generates* an infinite sequence of odd
numbers:

.. code-block:: python

   def odd_numbers():
       i = 0
       while True:
           if i%2 != 0:
               yield i
           i += 1
   
   for j in odd_numbers():
       print(j)

Observations
------------

* ``odd_numbers`` is *iterable*
* ``yield`` is magic
* Every function that calls yield is a *generator*
* Each call to ``next(iterator)`` (speak: execution of the ``for``
  body) continues the function where ``yield`` left it.
* *This is outright genius!*

