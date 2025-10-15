.. include:: <mmlalias.txt>


Inheritance
===========

Extending Existing Classes
--------------------------

* ``Person`` is not enough
* Want ``Employee``
* *is-a* ``Person``, but with additional features
* |longrightarrow| *Implementation inheritance*

  .. jupyter-execute::
  
     class Person:
         def __init__(self, firstname, lastname):
             self.firstname = firstname
             self.lastname = lastname
     
         def fullname(self):
             return f'{self.firstname} {self.lastname}'
     
     class Employee(Person):  # <--- is-a Person
         pass

Creating an instance of ``Employee`` ...

* ``Employee``: no ``__init__()``
* ``Person``: found
* |longrightarrow| ``Person.__init__()`` called

  .. jupyter-execute::
  
     emp = Employee('Joerg', 'Faschingbauer')
     emp.fullname()

Additional Feature: Salary
--------------------------

* ``Employee`` needs its own constructor (added ``salary``)
* Calls base classe constructor |longrightarrow| ``super()``

  .. jupyter-execute::
  
     class Employee(Person):
         def __init__(self, firstname, lastname, salary):
             super().__init__(firstname, lastname)   # <--- Person.__init__()
             self.salary = salary
     
         def title(self):
             return f'{self.fullname()} ({self.salary})'

* Now calling ``Employee.__init__()`` ...
* ... which in turn calls ``Person.__init__()``

  .. jupyter-execute::
  
     emp = Employee('Joerg', 'Faschingbauer', 6000)
     emp.title()

Want Manager
------------

Another class, ``Manager``, in the tree ...

.. jupyter-execute::

   class Manager(Employee):
       def __init__(self, firstname, lastname, salary, employees):
           super().__init__(firstname, lastname, salary) # <--- Employee.__init__()
           self.employees = employees
   
       def add_employee(self, employee):
           self.employees.append(employee)
   
       def title(self):
           title = super().title()
           return title + f' (manages {len(self.employees)} employees)'

Composing a number of objects into a ``Manager`` instance ...

.. jupyter-execute::

   joerg = Employee('Joerg', 'Faschingbauer', 6000)
   mgr = Manager('Isolde', 'Haubentaucher', 10000, [joerg])
   caro = Employee('Caro', 'Faschingbauer', 5000)
   mgr.add_employee(caro)

   mgr.title()

Introspecting Inheritance: ``isinstance()``, ``issubclass()``
-------------------------------------------------------------

* ``isinstance(object, cls)``: is ``object`` an instance of ``cls``
  (or of a base class thereof)?
* ``issubclass(cls, parentcls)``: is ``cls`` a subclass of
  ``parentcls``?

  * Funnily a class is considered a subclass of itself

``isinstance()``
----------------

Obviously an ``Employee`` instance is an ``Employee`` instance:

.. jupyter-execute::

   joerg = Employee('Joerg', 'Faschingbauer', 6000)
   isinstance(joerg, Employee)

He is also a ``Person``:

.. jupyter-execute::

   isinstance(joerg, Person)

But not a ``Manager``:

.. jupyter-execute::

   isinstance(joerg, Manager)

``issubclass()``
----------------

``Manager`` *is-a* ``Person``

.. jupyter-execute::

   issubclass(Manager, Person)

... but not the other way around:

.. jupyter-execute::

   issubclass(Person, Manager)

Funnily, ``Person`` *is-a* ``Person``:

.. jupyter-execute::

   issubclass(Person, Person)

Add ``__str__()``, Creatively, After The Fact
---------------------------------------------

.. sidebar::

   **See also**

   * :doc:`../str-repr/topic`

Unrelated, but fun: add class methods dynamically ...

.. jupyter-execute::

   Person.__str__ = Person.fullname
   Employee.__str__ = Employee.title
   Manager.__str__ = Manager.title

   joerg = Employee('Joerg', 'Faschingbauer', 6000)
   mgr = Manager('Isolde', 'Haubentaucher', 10000, [joerg])
   caro = Employee('Caro', 'Faschingbauer', 5000)
   mgr.add_employee(caro)

   print('joerg:', joerg)
   print('mgr:', mgr)
