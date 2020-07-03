.. include:: <mmlalias.txt>

Object Oriented Programming
===========================

.. contents::
   :local:

.. jf-topic:: python.python_1050_oo
   :dependencies: python.python_0450_dictionaries,
		  python.python_0270_functions

Object Oriented Programming
---------------------------

**OO Principles**


* *Procedural*: there's data, and there's code
* |longrightarrow| relationship is not aways clear
* *OO*: data and code aggregated together, into classes*
* |longrightarrow| *Methods* operate on *objects* that have members*
* *Encapsulation*: implementation is hidden from the public

*End effect:* you talk about your code in the same way that you
program it

OO Everywhere
-------------

.. code-block:: python
   :caption: Strings

   s = 'Jörg'
   enc_s = s.encode(encoding='utf-8')

.. code-block:: python
   :caption: Lists

   list = ['Hello', 'World']
   list.extend(['!'])

.. code-block:: python
   :caption: Batteries

   from http.client import HTTPConnection
   connection = HTTPConnection('www.google.com')
   connection.connect()

The ``class`` Statement
-----------------------

**Defining a class:** the ``class`` statement

.. code-block:: python

   class MakesNoSense:
       ...

* ``class`` creates a "class" object (|longrightarrow|
  *Metaprogramming*)
* ``MakesNoSense`` is the name of a variable (that refers to the class
  object)
* |longrightarrow| like with functions, the class object can be
  assigned, passed as parameter, ...

The Constructor
---------------

.. code-block:: python

   class MakesNoSense:
       def __init__(self, parameter1, parameter2):
           ...
   
   mns = MakesNoSense('Hello', 666)


* ``__init__``: special method name |longrightarrow| *constructor*
* ``self``: the object being initialized/constructed
* Python does not require the name ``self``, but it is "good
  style". IDE's may rely upon it, but no requirement otherwise.

Attributes/Members
------------------

.. code-block:: python

   class MakesNoSense:
       def __init__(self, parameter1, parameter2):
           self.member1 = parameter1
           self.member2 = parameter2
   
   ...
   print(mns.member1)
   mns.member2 = 42

* There is no *information hiding* in Python
* Members are visible to outside users
* ... by default at least

Attributes/Members: Hiding
--------------------------

.. code-block:: python

   class MakesNoSense:
       def __init__(self, parameter1, parameter2):
           self.__member1 = parameter1
           self.__member2 = parameter2
   
   # error!
   mns.__member2 = 42

* Python recognizes ``__`` as something special
* *Mangles* the name |longrightarrow| visible as-is only within
  class's methods

Methods
-------

A **Method** is a function that *is called on an object* ...

.. code-block:: python

   class MakesNoSense:
       def __init__(self, parameter1, parameter2):
           self.__member1 = parameter1
           self.__member2 = parameter2
   
       def do_make_sense(self, value):
           print('I try to but fail: {} {} {}'.format(
               self.__member1, self.__member2, value))
   
   mns = MakesNoSense(1, 'one')
   mns.do_make_sense('bummer')
