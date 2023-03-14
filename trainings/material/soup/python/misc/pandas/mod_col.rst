.. ot-topic:: python.misc.pandas.mod_col
   :dependencies: python.misc.pandas.basics

.. include:: <mmlalias.txt>


Pandas: Adding/Modifying Columns
================================

.. contents::
   :local:

Example 1: Lowercasing A Column Of Strings
------------------------------------------

* Email addresses are case-insensitive, by law
* The dataset has them mixed

.. jupyter-execute::

   import pandas as pd

   persons = pd.DataFrame({
       'firstname': ['Joerg',                  'Johanna',        'Caro',              'Philipp'          ],
       'lastname':  ['Faschingbauer',          'Faschingbauer',  'Faschingbauer',     'Lichtenberger'    ],

       'email':     ['JF@faschingbauer.co.at', 'Caro@email.com', 'Johanna@email.com', 'PHILIPP@email.com'],

       'age':       [56,                       27,               25,                  37                 ],
   })

.. jupyter-execute::

   persons['email']

Example 1: Modifying The ``email`` Column
-----------------------------------------

.. sidebar::

   **Documentation**

   * `pandas.Series.str
     <https://pandas.pydata.org/docs/reference/api/pandas.Series.str.html>`__

* Pull out ``email``

  .. jupyter-execute::

     email = persons['email']

* Lowercase that, using vectorized string methods of ``Series``

  .. jupyter-execute::

     email.str.lower()

  .. jupyter-execute::

     lower_email = email.str.lower()

* Assign back into ``persons`` ``DataFrame``

  .. jupyter-execute::

     persons['email'] = lower_email

  .. jupyter-execute::

     persons

* In short

  .. jupyter-execute::

     persons['email'] = persons['email'].str.lower()

Example 2: Adding A ``normalized_email`` Column
-----------------------------------------------

.. jupyter-execute::

   import pandas as pd

   persons = pd.DataFrame({
       'firstname': ['Guido',      'Joerg',                  'Johanna',        'Caro',              'Philipp'],
       'lastname':  ['Rentner',    'Faschingbauer',          'Faschingbauer',  'Faschingbauer',     'Lichtenberger'],
       'email':     ['jf@old.com', 'JF@faschingbauer.co.at', 'Caro@email.com', 'Johanna@email.com', 'PHILIPP@email.com'],
       'age':       [69,           56,                       27,               25,                  37],
   })

* It's as simple as assigning a column that does not yet exist

  .. jupyter-execute::

     persons['normalized_email'] = persons['email'].str.lower()

What If No Prebuilt Functionality Exists? ``apply()`` To The Rescue!
--------------------------------------------------------------------

* Simple example: Python's built-in ``len()`` function: one parameter,
  and return value

  .. jupyter-execute::

     s = 'Hello'
     len(s)

* Apply that on a ``Series``; e.g. ``firstname``

  .. jupyter-execute::

     fn = persons['firstname']
     fn

* Length of each ``firstname``

  .. jupyter-execute::

     fn.apply(len)

``apply()`` -ing Custom Functions
---------------------------------

* Write single-parameter function (just like ``len()``)

  .. jupyter-execute::
  
     def is_palindrome(s):
         s = s.lower()
	 return s == s[::-1]

  .. jupyter-execute::

     persons

* Apply it

  .. jupyter-execute::
  
     persons['lastname'].apply(is_palindrome)
     
Links
-----

* `Working with text data
  <https://pandas.pydata.org/docs/user_guide/text.html>`__
* `pandas.Series.str
  <https://pandas.pydata.org/docs/reference/api/pandas.Series.str.html>`__
* Corey Schafer: `Python Pandas Tutorial (Part 5): Updating Rows and
  Columns - Modifying Data Within DataFrames
  <https://youtu.be/DCDe29sIKcE>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/DCDe29sIKcE" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>

