.. include:: <mmlalias.txt>

Iteration and Generators
========================

.. contents::
   :local:

.. jf-topic:: python.python_1010_generators_yield
   :dependencies: python.basics.python_0220_for,
		  python.basics.python_0200_sequential_types,
		  python.basics.python_0225_range,
		  python.basics.python_0270_functions

Iteration in Python
-------------------

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

*Iterables* are objects that support *iteration* (Gosh!)

Iterables that are built into Python are for example ...

* Sequence, tuple
* Dictionary (iteration yields key/value pairs)
* Set
* String
* File
* ... and many more ...

The Iterator Protocol (1)
-------------------------

Technically speaking ...

* An *iterable* can make an *iterator* through the ``__iter__()``
    method
* Not usually done by hand
* Done for me by ``for`` loop

.. code-block:: python

   for elem in iterable:
       ... do something with elem ...

The interpreter ...

* Creates an *iterator* before entering the loop (|longrightarrow|
  ``__iter__()``)
* Calls ``next()`` on that iterator before every iteration
* Terminates the loop when ``StopIteration`` is caught

The Iterator Protocol (2)
-------------------------

.. code-block:: python
   :caption: Manually

   iterator = iter(iterable)
   try:
       i = next(iterator)
   except StopIteration:
       ...

* Often the calculation of the next element is complicated
* |longrightarrow| object state has to be kept manually
* Coding iterables is no fun
* ... at least not without language support

Generators: Motivation
----------------------

**Examples of complicated iteration ...**

* Traverse a binary tree in depth-first or breadth-first order
* Infinite sets like Fibonacci numbers

**Stupid solution:**

* Store result in a list
* Return the list
* |longrightarrow| Problem with large iterables (Fibonacci?)
* |longrightarrow| Best to *generate* on-demand

Generators: How?
----------------

.. code-block:: python
   :caption: A sample generator

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

More on Generators
------------------

**Python 2 to 3 transition**

* ``range()`` is a generator in 3
* Python 2: returns a (temporary) list
* ... had to use ``xrange()`` to generate
* Many more places converted to generators

**Standard library helpers**

* ``itertools``
* ``operator``
