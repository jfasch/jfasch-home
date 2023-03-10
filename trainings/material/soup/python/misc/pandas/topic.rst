.. include:: <mmlalias.txt>

.. ot-topic:: python.misc.pandas.topic


Preparational
=============

.. contents::
   :local:

.. sidebar::

   **Documentation**

   * `Pandas <https://pandas.pydata.org/>`__, and the ``DataFrame`` type
   * `10 minutes to pandas
     <https://pandas.pydata.org/docs/user_guide/10min.html>`__

Notebook
--------

* :doc:`Structure <notebook-wrapper>`
* :doc:`Whole notebook <notebook>`
* :download:`Download <notebook.ipynb>`


Videos
------

Basics
......

* Corey Schafer: `Python Pandas Tutorial (Part 8): Grouping and
  Aggregating - Analyzing and Exploring Your Data
  <https://youtu.be/txMdrV1Ut64>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/txMdrV1Ut64" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>

Advanced Usage: Filtering, Editing
..................................

* Corey Schafer: `Python Pandas Tutorial (Part 6): Add/Remove Rows and
  Columns From DataFrames <https://youtu.be/HQ6XO9eT-fc>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/HQ6XO9eT-fc" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>

Datatypes Other Than ``str``, Cleaning and Correcting
.....................................................

* Corey Schafer: `Python Pandas Tutorial (Part 9): Cleaning Data -
  Casting Datatypes and Handling Missing Values
  <https://youtu.be/KdmPHEnPJPs>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/KdmPHEnPJPs" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>

* Corey Schafer: `Python Pandas Tutorial (Part 10): Working with Dates
  and Time Series Data <https://youtu.be/UFuo7EHI8zc>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/UFuo7EHI8zc" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>

From/To Other Locations
.......................

* Corey Schafer: `Python Pandas Tutorial (Part 11): Reading/Writing
  Data to Different Sources - Excel, JSON, SQL, Etc
  <https://youtu.be/N6hyN6BW6ao>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/N6hyN6BW6ao" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>

* ``read_csv('http://...')``
     
Blah
----

.. ipython:: python

   i = 666
   i

``ipython``
...........

.. ipython:: python

   import pandas as pd

   users = {
       'firstname': ['Joerg', 'Johanna', 'Caro', 'Philipp'],
       'lastname': ['Faschingbauer', 'Faschingbauer', 'Faschingbauer', 'Lichtenberger'],
       'svnr': ['1037190666', '1234110695', '2345250497', '345606041986'],
   }   

   df = pd.DataFrame(users)

   df

``jupyter-execute``
...................

.. jupyter-execute::

   import pandas as pd

   users = {
       'firstname': ['Joerg', 'Johanna', 'Caro', 'Philipp'],
       'lastname': ['Faschingbauer', 'Faschingbauer', 'Faschingbauer', 'Lichtenberger'],
       'svnr': ['1037190666', '1234110695', '2345250497', '345606041986'],
   }   

   df = pd.DataFrame(users)

   df

Random Stuff
------------

* Set column widths

  * https://www.statology.org/pandas-column-width/

  .. code-block:: python

     pd.options.display.max_colwidth = None

