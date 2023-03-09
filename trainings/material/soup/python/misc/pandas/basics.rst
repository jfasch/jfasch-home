.. include:: <mmlalias.txt>

.. ot-topic:: python.misc.pandas.basics


Pandas: Basics (``DataFrame`` And ``Series``)
=============================================

.. contents::
   :local:

.. sidebar::

   **Documentation**

   * `Pandas <https://pandas.pydata.org/>`__

Naive: Objects, And Collections Of Objects
------------------------------------------

.. sidebar::

   **See also**

   * Better Python native way to represent objects:
     :doc:`/trainings/material/soup/python/advanced/oo/namedtuple/topic`

* ``Person`` object, represented as naive dictionary in Python

.. jupyter-execute::

   joerg = {
       'firstname': 'Joerg',
       'lastname': 'Faschingbauer',
       'email': 'jf@faschingbauer.co.at',
       'age': 56,
   }

* Again, naive collection of persons: native Python ``list``

.. jupyter-execute::

   caro = {
       'firstname': 'Caro',
       'lastname': 'Faschingbauer',
       'email': 'caro@email.com',
       'age': 25,
   }
   persons = [joerg, caro]
   persons

Inverted: Objects, And Collections Of Objects (|longrightarrow| ``DataFrame``)
------------------------------------------------------------------------------

* Pandas DataFrame ist different
* ... analogous to a dictionary that contains database columns

.. jupyter-execute::

   persons = {
       'firstname': ['Joerg',                  'Johanna',        'Caro',              'Philipp'          ],
       'lastname':  ['Faschingbauer',          'Faschingbauer',  'Faschingbauer',     'Lichtenberger'    ],
       'email':     ['jf@faschingbauer.co.at', 'caro@email.com', 'johanna@email.com', 'philipp@email.com'],
       'age':       [56,                       27,               25,                  37],
   }

* Operation: *column selection*

.. jupyter-execute::

   persons['firstname']

.. jupyter-execute::

   persons['age']

* Operation: *aggregation*

.. jupyter-execute::

   sum(persons['age'])

Enter ``pandas``, ``DataFrame``, ``Series``
-------------------------------------------

.. jupyter-execute::

   import pandas as pd

* Native Python dictionaries are not efficient enough
* Native Python dictionaries are feature-rich enough
* Mixing of data types inside a list/column
* Pandas uses `NumPy <https://numpy.org/>`__ internally
  |longrightarrow| values inside one column (``Series``) have same
  type

.. jupyter-execute::

   persons = pd.DataFrame(persons)

.. jupyter-execute::

   persons

.. sidebar:: 

   **See also**

   * :doc:`indexes`

* Note the *index* column

.. jupyter-execute::

   persons.shape

Selecting A Column |longrightarrow| ``Series``
----------------------------------------------

* Just like a Python dictionary: index operator ``[]``

.. jupyter-execute::

   persons.columns

.. jupyter-execute::

   persons['firstname']

.. jupyter-execute::

   type(persons['firstname'])

.. jupyter-execute::

   persons['firstname'].iloc[0]

Selecting Multiple Columns
--------------------------

* Unlike Python dictionary: using index operator with a list of column
  names

.. jupyter-execute::

   persons[['firstname', 'age']]

.. jupyter-execute::

   type(persons[['firstname', 'age']])

.. note::

   One would wish that slicing works, just as with ``loc`` and
   ``iloc`` (see :doc:`iloc` and :doc:`loc`):

   .. code-block:: python

      persons['firstname':'age']

   Unfortunately this does not work.

Links
-----

* Corey Schafer: `Python Pandas Tutorial (Part 1): Getting Started
  with Data Analysis - Installation and Loading Data
  <https://youtu.be/ZyhVh-qRZPA>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/ZyhVh-qRZPA" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share"
	     allowfullscreen>
     </iframe>

* Corey Schafer: `Python Pandas Tutorial (Part 2): DataFrame and
  Series Basics - Selecting Rows and Columns
  <https://youtu.be/zmdjNSmRXF4>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/zmdjNSmRXF4" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>
