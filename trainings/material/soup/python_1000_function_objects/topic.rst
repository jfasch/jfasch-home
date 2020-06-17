.. include:: <mmlalias.txt>

Python: Function Objects
========================

.. contents::
   :local:

.. jf-topic:: python_1000_function_objects
   :dependencies: python_0270_functions

What's a Function?
------------------

.. list-table::
   :align: left

   * - **First: what's a variable?**

       * A name that refers to something (here: an integer object)
       * Created at first assignment

     - .. code-block:: python

          i = 1

   * - **Functions are no different ...**

       * The function's name refers to a *function object*
       * ... it's just that object creation is done differently

     - .. code-block:: python

          def square(number):
              """
              return square 
              of the argument
              """
              return number**2

Function Objects?
-----------------

``square`` is a name that happens to refer to a function object ...

.. code-block:: python
   :caption: Object and its attributes

   >>> square
   <function square at 0x7fca2c785b70>
   >>> square.__doc__
   '\n    return square\n\tof the argument\n\t'

.. code-block:: python
   :caption: The ``()`` Operator

   >>> square(3)
   9

Function Objects! (1)
---------------------

.. code-block:: python
   :caption: Dynamic languages require care

   >>> square = 1
   >>> square(3)
   Traceback (most recent call last):
     File "<stdin>", line 1, in <module>
   TypeError: 'int' object is not callable

.. code-block:: python
   :caption: Assign one variable to another

   op = square
   op(3)

Function Objects! (2)
---------------------

.. code-block:: python
   :caption: Function as function argument

   def forall(op, list):
       result = []
       for elem in list:
           result.append(op(elem))
       return result
   
   print(forall(square, [1, 2, 3]))
   print(forall(len, ["Joerg", "Faschingbauer"]))

.. code-block:: python
   :caption: This will output ...

   [1, 4, 9]
   [5, 13]

**Batteries included:** Python built-in function ``map``
