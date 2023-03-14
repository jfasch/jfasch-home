.. include:: <mmlalias.txt>

.. ot-topic:: python.misc.pandas.add_rows
   :dependencies: python.misc.pandas.mod_col


Pandas: Adding Rows
===================

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

Add Rows: Assign To New Row Number
----------------------------------

* Row numbers start at 0
* Row number *behind* existing ones: length of ``DataFrame``
* Assigning to it *extends* ``DataFrame``

.. jupyter-execute::

   persons2 = persons.copy()
   persons2.loc[len(persons2)] = ('Isolde', 'Haubentaucher', '666608091972', 50)
   persons2

Add Rows: ``append()`` (*Deprecated*)
-------------------------------------

.. jupyter-execute::
   :raises:

   persons2 = persons.copy()
   try:
       persons2.append({'firstname': 'Isolde', 'lastname': 'Haubentaucher', 'email': 'isi@email.com', 'age': 50}, ignore_index=True)
   except FutureWarning:
       pass

Add Rows: Concatenating Frames
------------------------------

* This appears to be the most recommended approach

.. jupyter-execute::

   new_persons = pd.DataFrame({'firstname': ['Isolde', 'Saskia'],
                             'lastname': ['Haubentaucher', 'Haubentaucher'],
                             'svnr': ['666608091972', '456710042003'],
			     'age': [50, 19]
			    })
   pd.concat([persons, new_persons])
