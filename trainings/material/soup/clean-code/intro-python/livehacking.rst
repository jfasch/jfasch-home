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

Where Are We? Questions!
------------------------

* A number of different ways - *policies* - to read input data
* Data cleaning
* Categorization
* (Currently) one way to output data

**Questions**

* I'm annoyed by the cycles. Modify, manual test. Libreoffice in the
  toolchain or what??!
* What do I test?

  * Input?
  * Cleaning? 
  * Categories?
  * All in one? *Monolithically?*

Testability: Input Cleaning
---------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/python/swdev/pytest/group`

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

Testability: Reading Input (One Or Multiple Files, Explicitly)
--------------------------------------------------------------

* ``test_input.py``
* ``stuff/input.py``, containing

  * ``read_from_csv_single()``
  * ``read_from_csv_multiple()``

* Write tests first (don't touch ``scripts/categorize.py``
* Deliberately omit ``encoding`` parameter to ``open()``
  |longrightarrow| failure
* Raw strings!
* Only finally factor out ``read_from_csv()`` from
  ``scripts/categorize.py``

.. literalinclude:: code/test-input/tests/test_input.py
   :caption: :download:`code/test-input/tests/test_input.py`
   :language: python

.. literalinclude:: code/test-input/stuff/input.py
   :caption: :download:`code/test-input/stuff/input.py`
   :language: python

Test Sanity: Common Code
------------------------

* Tests contain repeated code
* |longrightarrow| Factor out (write simple function to create one CSV
  file in one go)

.. literalinclude:: code/test-input-common-code/tests/test_input.py
   :caption: :download:`code/test-input-common-code/tests/test_input.py`
   :language: python

Testability: Reading Input From Directory
-----------------------------------------

* Finally, factor out ``read_from_dir()``
* Don't forget to modify ``scripts/categorize.py``

.. literalinclude:: code/test-input-dir/tests/test_input.py
   :caption: :download:`code/test-input-dir/tests/test_input.py`
   :language: python

* Tests become larger
* Programs become smaller

Testability: Categorization
---------------------------

* First: all-in-one approach
* Write entire CSV file, and see how categorization is
* |longrightarrow| rip ``_write_csv()`` out from ``test_input.py``
* Lets see: ``__init__.py`` necessary

.. literalinclude:: code/test-category/tests/test_category.py
   :caption: :download:`code/test-category/tests/test_category.py`
   :language: python

* Finally, rip out ``write_to_csv()``
* |longrightarrow| **null length script**
