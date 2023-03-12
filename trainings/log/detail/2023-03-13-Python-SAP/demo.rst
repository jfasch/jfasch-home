.. include:: <mmlalias.txt>


Whetting Your Appetite (Livehacking Demo)
=========================================

.. contents::
   :local:

Pipeline Driver
---------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/python/misc/pandas/basics`
   * :doc:`/trainings/material/soup/python/advanced/exec/topic`

* Read CSV
* Read pipe members; drive empty pipeline
* Print frame
* |longrightarrow| ``DataFrame``

.. literalinclude:: Demo/drive-pipeline.py
   :language: python
   :caption: :download:`Demo/drive-pipeline.py`

Won't work though ...

.. code-block:: console

   $ ./drive-pipeline.py
   Traceback (most recent call last):
     File "/home/jfasch/Homebrain/Firma/Kunden/039-IT-Visions/2023-03-13--Python-SAP--Consolut/Demo/./drive-pipeline.py", line 4, in <module>
       import pandas as pd
   ModuleNotFoundError: No module named 'pandas'

Virtual Environment Setup
-------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/python/swdev/venv/slides`
   * :doc:`/trainings/material/soup/python/swdev/venv/screenplay`
   * :doc:`/trainings/material/soup/python/swdev/pip/slides`
   * :doc:`/trainings/material/soup/python/swdev/pip/screenplay`

   **Documentation**

   * `Python, and its standard library <https://docs.python.org/3/>`__

* Modules from Python standard library
* Modules that are not in Python standard library (like ``pandas``,
  for example)
* Sandboxing

  * Python interpreter (and standard library) version
  * External module version

* Jupyter notebook? Sure!

Filter: Add Category: ``card-payment``
--------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/python/misc/pandas/mod_col`

* ``info.startswith('Bezahlung Karte')``
* Add column ``category``, containing value ``card-payment`` only

.. literalinclude:: Demo/filters/cat-card-payment-v1.py
   :language: python
   :caption: :download:`Demo/filters/cat-card-payment-v1.py`

* Pandas *vectorized* string methods
* |longrightarrow| ``Series``
* Modeled after Python's built-in ``str`` methods (only on a
  ``Series`` instead``)
* Insufficient: adds only ``bool`` column

.. literalinclude:: Demo/filters/cat-card-payment-v2.py
   :language: python
   :caption: :download:`Demo/filters/cat-card-payment-v2.py`

* ``apply()``
* |longrightarrow| generic way to hook-in custom fuctionality
* |longrightarrow| enter real Python programming

Filter: Select Uncategorized
----------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/python/misc/pandas/loc`
   * :doc:`/trainings/material/soup/python/misc/pandas/filters`

.. literalinclude:: Demo/filters/uncategorized.py
   :language: python
   :caption: :download:`Demo/filters/uncategorized.py`

* *Hiccup*: duplicating the string ``unknown`` across (at least) two
  different filters/files

More Categories
---------------

* ``card-payment`` is far too unspecific
* *Useless*: want "Food", "Car", "Luxury", ...

.. literalinclude:: Demo/filters/categorize-v1.py
   :language: python
   :caption: :download:`Demo/filters/categorize-v1.py`

* Heavily modified though
* Python programming

.. sidebar::

   * :doc:`/trainings/material/soup/python/basics/python_0320_strings_methods/topic`

* Split the ``info`` field

  * Manually unpacking fields, first
  * |longrightarrow| tuple unpacking

* Interpret fields
* *Guess* category
* Into the wild

  * Working with crap data
  * Date formats
  * Floating point/currency formats and units (``EUR``?!)
  * Field tunneling (``info`` has three fields, but not always)

* Uncertainty!
* Fear!!
* |longrightarrow| Testing!!!

Testing
-------

.. sidebar::

   **See also**

   * :download:`Test Driven Development
     </trainings/material/pdf/060-design-patterns-unittests.pdf>`
   * :doc:`/trainings/material/soup/python/swdev/unittest` (comes with Python)
   * :doc:`/trainings/material/soup/python/swdev/pytest-intro`
     (outright genius)
   * :doc:`/trainings/material/soup/python/advanced/modules`

* Modularize

  * Externalize stuff from ``filters/categorize_v1.py``
  * |longrightarrow| ``filters/categorize_v2.py``

    .. literalinclude:: Demo/filters/categorize-v2.py
       :language: python
       :caption: :download:`Demo/filters/categorize-v2.py`

  * Import from ``stuff/category.py``

    .. literalinclude:: Demo/stuff/category.py
       :language: python
       :caption: :download:`Demo/stuff/category.py`

  * See if still works |longrightarrow| ok

* Add second importer: *test*

  * Problems

    * Primary problem: finding a *category* based upon the ``info``
      field (a `str``)
    * Secondary (if at all): reading CSV

  * Unit test: ``tests/test_category.py``

    * Test only the ``info`` column (|longrightarrow| :doc:`raw
      strings
      </trainings/material/soup/python/basics/python_0300_strings/topic>`)
    * Minor hiccup: have to set ``PYTHONPATH`` (see :doc:`here
      </trainings/material/soup/python/advanced/modules>`)

    .. literalinclude:: Demo/tests/test_category.py
       :language: python
       :caption: :download:`Demo/tests/test_category.py`

  .. code-block:: console

     $ pytest 
     ======================================= test session starts =======================================
     platform linux -- Python 3.10.7, pytest-7.2.0, pluggy-1.0.0
     rootdir: /home/jfasch/work/jfasch-home/trainings/log/detail/2023-03-13-Python-SAP/Demo
     collected 1 item                                                                                  
     
     tests/test_category.py .                                                                    [100%]
     ======================================== 1 passed in 0.01s ========================================
