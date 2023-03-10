.. include:: <mmlalias.txt>

.. ot-topic:: python.misc.pandas.filters
   :dependencies: python.misc.pandas.indexes,
		  python.misc.pandas.basics


Pandas: Filters
===============

.. contents::
   :local:

.. jupyter-execute::

   import pandas as pd

   persons = pd.DataFrame({
       'firstname': ['Joerg',                  'Johanna',        'Caro',              'Philipp'          ],
       'lastname':  ['Faschingbauer',          'Faschingbauer',  'Faschingbauer',     'Lichtenberger'    ],
       'email':     ['jf@faschingbauer.co.at', 'caro@email.com', 'johanna@email.com', 'philipp@email.com'],
       'age':       [56,                       27,               25,                  37],
   })

Basic Filter Example
--------------------

.. jupyter-execute::

   persons.loc[persons['lastname'] == 'Faschingbauer']

* Comprehensive
* More operators |longrightarrow| later
* How does that work?

Filter? Bitmap!
---------------

* A filter is a boolean expression
* Returns a ``Series`` of ``True`` and ``False`` values
  |longrightarrow| a *bitmap*
* Given to ``loc[]`` to select rows of interest

  .. jupyter-execute::
  
     flt = (persons['lastname'] == 'Faschingbauer')
     flt

  .. jupyter-execute::
  
     type(flt)

* Content of ``persons``

  .. jupyter-execute::
  
     persons

* Filter applied to ``persons`` with ``loc[]``

  .. jupyter-execute::
  
     persons.loc[flt]

Confusion: Filter/Column Addressing
-----------------------------------

* User friendliness: filter can be directly applied to ``DataFrame``

  .. jupyter-execute::
  
     persons[flt]

* Looks like columns were selected
* |longrightarrow| **confusion**

Column Selection And Filters
----------------------------

* Filters select rows, just like ``persons.loc[0]`` selects row by
  label
* Consequently, can be combined with column selection

.. jupyter-execute::
  
   persons.loc[flt, 'firstname']

Boolean Expressions: Bitwise Operators! Braces!
-----------------------------------------------

.. jupyter-execute::
  
   flt = (persons['firstname'] == 'Joerg') & (persons['lastname'] == 'Faschingbauer') | (persons['firstname'] == 'Philipp')

* **Confusion**: braces around ``==`` are important!
* *Bitwise* ``&`` binds stronger than ``==``
* |longrightarrow| wish they had used the normal boolean operators
  instead

Anyway,

.. jupyter-execute::
  
   persons.loc[flt]

Negation: ``~``
---------------

* Consequently |:rolling_eyes:|, bitwise negation was chosen to mean
  logical ``NOT``

.. jupyter-execute::
  
   persons.loc[~flt]

Neat Helpers
------------

.. sidebar::

   **Documentation**

   * `pandas.DataFrame.isin
     <https://pandas.pydata.org/docs/reference/api/pandas.DataFrame.isin.html>`__
   * `String methods
     <https://pandas.pydata.org/docs/user_guide/text.html#string-methods>`__
   * `Working with text data <https://pandas.pydata.org/docs/user_guide/text.html>`__

.. jupyter-execute::
  
   flt = persons['firstname'].isin(['Caro', 'Philipp'])
   persons[flt]

.. jupyter-execute::
  
   flt = persons['firstname'].str.startswith('J')
   persons[flt]

Links
-----

* Corey Schafer: `Python Pandas Tutorial (Part 4): Filtering - Using
  Conditionals to Filter Rows and Columns
  <https://youtu.be/Lw2rlcxScZY>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/Lw2rlcxScZY" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>
