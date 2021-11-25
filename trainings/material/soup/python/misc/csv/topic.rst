.. include:: <mmlalias.txt>

.. ot-topic:: python.misc.csv
   :dependencies: python.basics.python_0220_for,
		  python.basics.python_0500_files,
		  python.basics.python_0150_datatypes_overview_compound


CSV Files
=========

.. contents::
   :local:

.. sidebar::

   .. list-table::
      :align: left

      * * **Documentation**
	* :doc:`csv <python:library/csv>`

CSV in its Origins
------------------

* Simple in principle
* Line-based file

  * Each line has a *record*
  * Each record has the same number of fields
  * Each field has a *meaning*

Here is a simple CSV file in its very original form

.. literalinclude:: simple.csv
   :language: none
   :caption: :download:`simple.csv`

* No heading
* Commas (",") as field separators
* ASCII encoded

The ``csv`` Module: ``csv.reader``
----------------------------------

* ``csv.reader`` has sane defaults (`documentation
  <https://docs.python.org/3/library/csv.html#csv.reader>`__)
* Use it in its basic form

.. literalinclude:: read-simple.py
   :caption: :download:`read-simple.py`

.. command-output:: python read-simple.py
   :cwd: .

And Tuple Unpacking?
--------------------

* One row is a list
* Same number of elements (in the *sane CSV* case)
* Tuple unpacking useful

.. literalinclude:: read-simple-tupleunpacked.py
   :caption: :download:`read-simple-tupleunpacked.py`

.. command-output:: python read-simple-tupleunpacked.py
   :cwd: .

Going Insane: CSV? SCSV?
------------------------

* CSV stands for "Comma Separated Values"
* `One popular CSV producer
  <https://en.wikipedia.org/wiki/Microsoft_Excel>`__ produces SCSV
  ("SemiColon Separated Values") files though.

.. literalinclude:: simple-semicolon.csv
   :language: none
   :caption: :download:`simple-semicolon.csv`

One would configure the *delimiter* in such a case ...

.. literalinclude:: read-simple-semicolon.py
   :caption: :download:`read-simple-semicolon.py`

More Tuning Needed: Quoting
---------------------------

But let's use our original CSV (that with the commas)

.. literalinclude:: simple.csv
   :language: none
   :caption: :download:`simple.csv`

* And let's say, Queen Elizabeth would jump up and require us to spell
  her full name, "Queen Elizabeth, II"
* The resulting file would suddenly have four fields in the "Queen"
  row

.. literalinclude:: simple-broken.csv
   :language: none
   :caption: :download:`simple-broken.csv`

A correctly escaped CSV would look like so:

.. literalinclude:: escaped.csv
   :language: none
   :caption: :download:`escaped.csv`

Tuning Options
--------------

Perhaps redundantly (the ``delimiter`` is ',' by default, and the
``quotechar`` is '"' by default), we would read
:download:`escaped.csv` like so,

.. literalinclude:: read-escaped.py
   :caption: :download:`read-escaped.py`

.. command-output:: python read-escaped.py
   :cwd: .

**Many more tuning options** are available; for a complete list `see
the documentation
<https://docs.python.org/3/library/csv.html#csv-fmt-params>`__.

And Headings?
-------------

Another common practice among CSV producers is to export 

* the first line to contain the *field names*
* remaining lines to contain spreadsheet data

If the original spreadsheet would look like so,

.. csv-table::
   :file: headers.csv
   :align: left
   :widths: auto
   :header-rows: 1

, the exported CSV would be,

.. literalinclude:: headers.csv
   :language: none
   :caption: :download:`headers.csv`

Enter ``csv.DictReader``
------------------------

* This - *the column names come with the CSV* - is a case for
  ``csv.DictReader`` (see `documentation
  <https://docs.python.org/3/library/csv.html#csv.DictReader>`__).
* ``csv.DictReader``, when given no explicit ``fieldnames`` parameter,
  does exactly that: take the information from the first line as keys
  into a dictionary, and spit the rest out as dictionaries with this
  shape.

.. literalinclude:: read-headers.py
   :caption: :download:`read-headers.py`

.. command-output:: python read-headers.py
   :cwd: .
