.. include:: <mmlalias.txt>


Pandas: Selecting Rows (And Columns) With ``loc[]``
====================================================

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

Rows (And Columns) By Label
---------------------------

.. sidebar::

   **See also**

   * :doc:`indexes`
   * :doc:`filters`

* Label?
* |longrightarrow| Default index (:doc:`more on indexes <indexes>`) is
  integer, so ... just the same as ``iloc``

  .. jupyter-execute::
  
     persons.loc[0]
  
  .. jupyter-execute::
  
     persons.loc[[0,1]]

* More power: :doc:`filters`

Hiccup: Slices Are *Inclusive*
------------------------------

* Contrary to ``iloc[]``, the end of a slice specifier is included in
  the slice

  .. jupyter-execute::
  
     persons.loc[0:1]

* Why? Read on

Column Selection By Label
-------------------------

.. jupyter-execute::

   persons.loc[0, ['firstname', 'age']]

.. jupyter-execute::

   persons.loc[[0, 1], ['firstname', 'age']]

Columns By Slicing: *Inclusive*
-------------------------------

.. jupyter-execute::

   persons.loc[1, 'firstname' : 'age']

* Not consistent with Python's definition of ranges
* ... but user friendly (hard to understand why ``'age'`` had to be
  left out)
* Rant: does slicing by column name bear any value?

Summary
-------

* *Attention*: inconsistent with rest of Python (and ``iloc[]``)
* More (absolute) power by using :doc:`filters <filters>` with
  ``loc[]``

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

