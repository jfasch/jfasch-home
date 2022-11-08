.. ot-topic:: python.advanced.oo.abc
   :dependencies: python.advanced.oo.inheritance

.. include:: <mmlalias.txt>


Abstract Base Classes (``abc``), And Duck Typing
================================================

.. contents::
   :local:

* Python is not picky about types
* Very late binding
* By name
* Method call on object |longrightarrow| lookup in class dict

Duck Typing
-----------

* *If it walks and quacks like a duck, it can be used as a duck*
* Concrete example: Sensor-like classes (mockups)
* Sensor-like: if you can call ``get_temperature()`` on it, it is a
  sensor

.. jupyter-execute::

   class ConstantSensor:
       def __init__(self, value):
           self.value = value
   
       def get_temperature(self):
           return self.value

   import random
   class RandomSensor:
       def __init__(self, lo, hi):
           self.lo = lo
           self.hi = hi
   
       def get_temperature(self):
           return random.uniform(self.lo, self.hi)

* Any of those can be used *as-a* sensor

.. jupyter-execute::

   sensors = {
       'my-const': ConstantSensor(36.5),
       'my-random': RandomSensor(34.3, 41.7),
   }
   
   for i in range(5):
       for name, s in sensors.items():
           temperature = s.get_temperature()         # <--- using a duck
           print(f'#{i} {name}: {temperature}')

Duck Typing: Examples
---------------------

.. sidebar::

   **See also**

   :doc:`/trainings/material/soup/python/misc/csv/topic`

* ``csv.reader`` (`here
  <https://docs.python.org/3/library/csv.html>`__):

     | csvfile can be any object which supports the iterator protocol
     | and returns a string each time its __next__() method is called —
     | file objects and list objects are both suitable.

Duck Typing Problem: Late Errors
--------------------------------

* A broken duck

.. jupyter-execute::

   class BrokenSensor:
       def getTemperature(self):               # <--- broken, should be get_temperature()
           return -273.15

* Program setup instantiates object

.. jupyter-execute::

   sensors = {
       'my-const': ConstantSensor(36.5),
       'my-broken': BrokenSensor(),            # <--- instantiate
   }

* Much later, during regular operation
   
.. jupyter-execute::
   :raises:

   for i in range(5):
       for name, s in sensors.items():
           temperature = s.get_temperature()   # <--- non-duck breaks program
           print(f'#{i} {name}: {temperature}')

Intermediate Step: Common Base Class ("Interface")
--------------------------------------------------

* Other languages have *interfaces*
* Java: ``implements`` expresses ``is-a``
* Python: only inheritance, *and a bunch of metaprogramming
  possibilities*
* |longrightarrow| create base class ``Sensor``

.. jupyter-execute::

   class Sensor:
       def get_temperature(self):
           assert False, "implement this in a derived class!"
	   return -273.5   # implementations should return float

* And derive concrete sensors from it

   class ConstantSensor(Sensor):
       def __init__(self, value):
           self.value = value
   
       def get_temperature(self):
           return self.value

   class BrokenSensor(Sensor):
       def getTemperature(self):               # <--- still broken
           return -273.15
      
* Instantiation still possible

.. jupyter-execute::

   sensors = {
       'my-const': ConstantSensor(36.5),
       'my-broken': BrokenSensor(),            # <--- still passes
   }

* Different runtime error, but still during regular operation

.. jupyter-execute::
   :raises:

   for i in range(5):
       for name, s in sensors.items():
           temperature = s.get_temperature()   # <--- still not a duck
           print(f'#{i} {name}: {temperature}')

   
Enter Abstract Base Classes: Wish List
--------------------------------------

.. sidebar::

   **Documentation**

   * :doc:`python:library/abc`

* True *is-a* relationship |longrightarrow| inheritance, only stronger
* No non-compliant objects should be possible
* |longrightarrow| Error ("not a duck") should happen as early as possible
* |longrightarrow| At instantiation!
* Enter :doc:`abc <python:library/abc>`

Abtract Base Class
------------------

* ``abc.ABC``: *Abstract base class* to inherit from
* ``@abc.abstractmethod``: method decorator

.. jupyter-execute::

   import abc
   
   class Sensor(abc.ABC):
       @abc.abstractmethod
       def get_temperature(self):
   	return -273.5   # implementations should return float
   
* Derived classes unmodified

.. jupyter-execute::

   class ConstantSensor(Sensor):
       def __init__(self, value):
           self.value = value
   
       def get_temperature(self):    # <--- good: overriding abstract method
           return self.value
   
   class BrokenSensor(Sensor):
       def getTemperature(self):     # <--- bad: not overriding abstract method
           return -273.15
   
* **Effect**: ``ABC`` objects cannot be instantiated if they have
  unimplemented ``@abc.abstractmethod`` methods ...

.. jupyter-execute::
   :raises:

   sensors = {
       'my-const': ConstantSensor(36.5),
       'my-broken': BrokenSensor(),  # <--- good: early error
   }
