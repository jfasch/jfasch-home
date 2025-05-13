.. include:: <mmlalias.txt>


Pandas: Indexes
===============

.. contents::
   :local:

.. jupyter-execute::

   import pandas as pd

   persons = pd.DataFrame({
       'firstname': ['Joerg',                  'Johanna',           'Caro',              'Philipp'          ],
       'lastname':  ['Faschingbauer',          'Faschingbauer',     'Faschingbauer',     'Lichtenberger'    ],
       'email':     ['jf@faschingbauer.co.at', 'johanna@email.com', 'caro@email.com',    'philipp@email.com'],
       'age':       [56,                       27,                  25,                  37                 ],
   })

Default Index: Row Number
-------------------------

.. jupyter-execute::

   persons

* See how rows are numbered
* No column name given
* |longrightarrow| default index

.. jupyter-execute::

   persons.index

Setting Custom Index
--------------------

* Notice how ``email`` appears to be unique
* |longrightarrow| could be used as an index

  .. jupyter-execute::

     persons.set_index('email')

* This does not change anything
* Returns modified copy (could be assigned to another variable that
  you continue to work with, for example)
* ``persons`` is still the same as before

  .. jupyter-execute::

     persons

Setting Custom Index, ``inplace=True``
--------------------------------------

* Many (but not all) ``DataFrame`` methods support an ``inplace`` parameter
* Default ``False``

  * |longrightarrow| no change
  * Returns a modified copy of the ``DataFrame`` object

* Nice for trying around on a large dataset that we don't want to
  damage
* Add ``inplace`` if everything works
* |longrightarrow| No return value

  .. jupyter-execute::
  
     persons.set_index('email', inplace=True)

* Modified object in-place

  .. jupyter-execute::
  
     persons

* Index has changed

  .. jupyter-execute::
  
     persons.index

Custom Index, And ``loc[]``
---------------------------

.. sidebar::

   **See also**

   * :doc:`loc`
   * :doc:`iloc`

* ``loc[]`` selects by *row label* (|longrightarrow| index)
* Row labels are not row numbers anymore |longrightarrow| cannot be
  used as row labels

  .. jupyter-execute::
     :raises:

     persons.loc[0]

* New row label: ``email``

  .. jupyter-execute::

     persons.loc['jf@faschingbauer.co.at']

  .. jupyter-execute::

     persons.loc[['jf@faschingbauer.co.at', 'johanna@email.com']]

Custom Index, And ``iloc[]``
----------------------------


* ``iloc[]`` selects by *row number*
* |longrightarrow| still valid as before

.. jupyter-execute::

   persons.iloc[0]

.. jupyter-execute::

   persons.iloc[[0, 1]]

Sorting ``DataFrame`` Object By Index Column
--------------------------------------------

.. sidebar::

   **Documentation**

   * `pandas.DataFrame.sort_index
     <https://pandas.pydata.org/docs/reference/api/pandas.DataFrame.sort_index.html>`__

* ``DataFrame.sort_index()``: non ``inplace`` by default
  |longrightarrow| returns modified copy

  .. jupyter-execute::
  
     persons.sort_index(ascending=True)

* Sorting in place

  .. jupyter-execute::
  
     persons.sort_index(ascending=True, inplace=True)

  .. jupyter-execute::
  
     persons

Links
-----

* Corey Schafer: `Python Pandas Tutorial (Part 3): Indexes - How to
  Set, Reset, and Use Indexes <https://youtu.be/W9XjRYFkkyw>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/W9XjRYFkkyw" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>

* Data School: `How do I use the MultiIndex in pandas?
  <https://youtu.be/tcRGa2soc-c>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/tcRGa2soc-c" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>
