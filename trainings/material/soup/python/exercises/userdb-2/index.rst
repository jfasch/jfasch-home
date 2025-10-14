Another User Database (Exercise Series)
=======================================

Setup
-----

* :doc:`/trainings/material/soup/python/swdev/venv/topic`

  Create virtual environment ("sandbox")

  .. code-block:: console
  
     $ python -m venv ~/My-Environments/2025-10-13

  Activate that environment

  .. code-block:: console
     :caption: Linux
  
     $ source ~/My-Environments/2025-10-13/bin/activate
     (2025-10-13) $                          # <-- prompt changes!

  .. code-block:: console
     :caption: Windos ``cmd``
  
     $ C:\Users\Myself\My-Projects\2025-10-13\Scripts\activate.bat

* :doc:`/trainings/material/soup/python/swdev/pip/topic`

  In the environment (note the prompt)

  .. code-block:: console
  
     (2025-10-13) $ python -m pip install pytest

Contents
--------

.. toctree::
   :maxdepth: 1

   read-csv-dicts
   write-json-dicts
   csv2json
   read-csv-objs
   write-json-objs
   csv2json-modern
