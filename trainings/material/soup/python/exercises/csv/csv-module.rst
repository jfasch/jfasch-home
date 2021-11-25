.. ot-exercise:: python.exercises.csv.csv_module
   :dependencies: python.misc.csv,
		  python.advanced.python_1010_generators_yield,
		  python.advanced.modules
		  
.. include:: <mmlalias.txt>


Exercise: Read CSV File
=======================

.. contents::
   :local:

Sample CSV File
---------------

The following table (:download:`download CSV <stock.csv>`) is an
excerpt from a stock exchange procedure [#me-no-money-man]_. In its
visual form, it would be nicely made up, headed by a row that contains
the column names.

.. csv-table::
   :file: stock.csv
   :align: left
   :widths: auto
   :header-rows: 1
   :quote: "
   :delim: ;

Requirement
-----------

#. Write a function ``read_stock()`` that ...

   * takes a ``filename`` parameter
   * reads the CSV (using a ``csv.DictReader`` to automatically absorb
     the header line of the CSV file into dictionary keys), and
     thereby converts the fields as follows,

     * ``FUND_NAME``: ``str``
     * ``FUND_ISIN``: ``str``
     * ``FUND_TICKER``: ``str``
     * ``AS_OF_DATE``: ``datetime``
     * ``FUND_IN_UNIVERSE``: ``bool`` (interpreting ``T`` and ``F``
       straightforwardly)
     * ``FUND_HOLDINGS_COUNT``: ``float``
     * ``FUND_HOLDING_FUNDS_COUNT``: ``float``

   * returns a list of dictionaries (better yet: an :doc:`iterable
     </trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/topic>`).

#. Put that function in a module, say ``stock.py``
#. Write an executable program, say ``read-stock.py``, that is called
   like follows,

   .. code-block:: console

      $ python read-stock.py stock.csv
      ...

   It then writes the returned dictionaries/record to ``stdout`` in
   the most beautiful way you can come up with.

.. rubric:: Footnotes

.. [#me-no-money-man] Although I make a living from what I do, I
                      hardly know what money is. Lets take the CSV as
                      a representative example, and not try to
                      understand what's in it.


Dependencies
------------

.. ot-graph::
   :entries: python.exercises.csv.csv_module
