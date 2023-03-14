.. include:: <mmlalias.txt>

.. ot-topic:: python.misc.pandas.iloc
   :dependencies: python.misc.pandas.indexes,
		  python.misc.pandas.basics,
		  python.basics.python_0210_indexing_slicing


Pandas: Selecting Rows (And Columns) With ``iloc[]``
====================================================

.. contents::
   :local:

.. jupyter-execute::

   import pandas as pd

   persons = pd.DataFrame({
       'firstname': ['Joerg',                  'Johanna',        'Caro',              'Philipp'          ],
       'lastname':  ['Faschingbauer',          'Faschingbauer',  'Faschingbauer',     'Lichtenberger'    ],
       'email':     ['jf@faschingbauer.co.at', 'caro@email.com', 'johanna@email.com', 'philipp@email.com'],
       'age':       [56,                       27,               25,                  37                 ],
   })

Row By Number: ``iloc[]``
-------------------------

.. sidebar::

   **See also**

   * :doc:`indexes`

* Note the index column
* ... has no explicit column name
* Default index (unless configured explicitly): *row numbers*
* |longrightarrow| *integers*
* |longrightarrow| ``iloc``, for *integer location*

  .. jupyter-execute::
  
     persons.iloc[1]

  .. jupyter-execute::
  
     type(persons.iloc[1])

* Out-of-range access not possible (see :doc:`add_row`)

.. sidebar::

   **See also**

   * :doc:`indexes`

.. jupyter-execute::
   :raises:

   persons.iloc[4]

So What Is A Row, Then?
-----------------------

.. jupyter-execute::

   row = persons.iloc[1]

.. jupyter-execute::

   type(row)

.. jupyter-execute::

   row

* ``Series``
* Non-default index |longrightarrow| *column name*
* Best accessed using ``loc[]``, using the column name
* Or the *column index/number* (clumsy though)

.. sidebar::

   **See also**

   * :doc:`loc`

.. jupyter-execute::

   row.loc['firstname']

.. jupyter-execute::

   row.iloc[0]

Selecting Multiple Rows
-----------------------

* Using *list of column numbers* as ``iloc[]`` subscript parameter

  .. jupyter-execute::
  
     persons.iloc[[0,1]]      # <--- single list [0,1] inside []

* Note how the index is an integer again
* |longrightarrow| two rows selected
* |longrightarrow| ``DataFrame``, not ``Series``

Slicing
-------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`

* ``[0,1]`` (contiguous range) is alternatively expressed as a *slice*
  ``[0:2]``
* 0 ... inclusive
* 2 ... exclusive

  .. jupyter-execute::
  
     persons.iloc[0:2]        # <--- note: no double squares! 0:2 *is* [0,1]

Selecting Rows And Columns
--------------------------

* ``iloc[]`` selects rows, primarily
* Can select columns from those *in the same step*

* Example: row 1, column 2 (which is ``email``)

  .. jupyter-execute::
  
     persons.iloc[1, 2]

* Example: rows 0 and 1 (i.e. two rows), column 2 (``email``)

  .. jupyter-execute::
  
     persons.iloc[[0,1], 2]

* Example ...

  .. jupyter-execute::
  
     persons.iloc[[0,1], [0, 2]]

* Example: slices ... note that the end is *exclusive* with ``iloc[]``
  (as opposed to ``loc[]``; see :doc:`loc`)

  .. jupyter-execute::
  
     persons.iloc[0:2, 0:3]

Summary
-------

* Works with integers only
* Cannot even specify columns by their names
* Efficient though

Links
-----

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

