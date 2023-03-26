.. include:: <mmlalias.txt>


A Typical Project (Livehacking Screenplay: My Own Bookkeeping Effort)
=====================================================================

.. contents::
   :local:

Spaghetti Version
-----------------

* Contains functions only because necessary (applied with
  ``DataFrame.apply()``)
* Can imaging that ``make_category()`` will become worse

.. literalinclude:: code/spaghetti/categorize.py
   :caption: :download:`code/spaghetti/categorize.py`
   :language: python

A Little Better: Functions (And Commandline Parameters)
-------------------------------------------------------

* Dedicated Functions (not only for the purpose of
  ``DataFrame.apply()``)
* Gives Structure
* |longrightarrow| Readability
* |longrightarrow| Steps are obvious
* Step 1: *reading in* |longrightarrow| ``DataFrame``
* Step 2: *data cleaning*
* Step 3: *categorization*
* Step 4: *writing out*

.. literalinclude:: code/functions/categorize.py
   :caption: :download:`code/functions/categorize.py`
   :language: python

Feature Request: Concatenate Input Data From Multiple CSV Files
---------------------------------------------------------------

* One directory, containing possibly many alphabetic-as-date
  (e.g. ``2022-12.csv``) named files
* Commandline arguments: input ``[1:-1]``, and output ``[-1]``
* "Polymorphic" parameter to ``read_from_csv()``: ``str`` or
  *iterable*

  * Cool |:muscle:|: works with both single filename and list of
    filenames

* |longrightarrow| works magically
* |longrightarrow| problem solved

.. literalinclude:: code/feature-multiple-csv//categorize.py
   :caption: :download:`code/feature-multiple-csv//categorize.py`
   :language: python

**Problem created**

* What if there are files inside the directory that don't obey the
  ``YYYY-MM.csv`` convention?
* Workaround: put burden on user (not use ``data/*.csv`` anymore)

Feature Request: Concatenate Input Data From ``YYYY-MM.csv`` Files
------------------------------------------------------------------

* ``YYYY-MM.csv`` files in specified directory
* Use regular expressions (``import re``)
* |longrightarrow| only two commandline parameters

.. literalinclude:: code/feature-YYYY-MM.csv/categorize.py
   :caption: :download:`code/feature-YYYY-MM.csv/categorize.py`
   :language: python

**Problem created**

* We aggregate possibly *very* many files *automatically*
* How do I test?

.. code-block:: console

   $ wc -l data/202*csv
      67 data/2022-12.csv
      58 data/2023-01.csv
      55 data/2023-02.csv
     180 total

.. code-block:: console

   $ wc -l bank-cat.csv 
   181 bank-cat.csv

(Fortunately that's only the CSV column header that
``DataFrame.to_csv()`` writes out by default. ``header=False`` fixes
that.)

A Step Back: What Do We Have?
-----------------------------

* A number of different ways - *policies* - to read input data
* Data cleaning
* Categorization
* (Currently) one way to output data

**Questions**

* How do I test input-reading (and data cleaning)?
* Can categorization be done without cleaning? |longrightarrow|
  currently yes, but possibly not in the general case
* How do I proceed with categorization? 

  * It's going to become more complex
  * Want to specify expected category by-example

Testability At A Low Level: Currency And Date Conversion
--------------------------------------------------------

**Currency conversion**

* Does the ``make_float()`` routine work?
* |longrightarrow| factor out from script
* |longrightarrow| *module*; lets name it ``stuff``
* |longrightarrow| ``scripts``
* |longrightarrow| project structure

**Date conversion**

* Next: factor out ``clean_data()``
* Test that
* |longrightarrow| note that the second test is easier to write than
  the first

.. literalinclude:: code/test-data-cleaning/tests/test_data_cleaning.py
   :caption: :download:`code/test-data-cleaning/tests/test_data_cleaning.py`
   :language: python
