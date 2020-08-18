.. include:: <mmlalias.txt>

Virtual Environments: Livehacking Screenplay
============================================

.. contents::
   :local:

Setup
-----

.. code-block:: console

   $ python -m venv my_env
   $ tree my_venv/
   my_venv/
   ├── bin
   │   ├── activate
   │   ├── activate.csh
   │   ├── activate.fish
   │   ├── Activate.ps1
   │   ├── easy_install
   │   ├── easy_install-3.8
   │   ├── pip
   │   ├── pip3
   │   ├── pip3.8
   │   ├── python -> /usr/bin/python
   │   └── python3 -> python
   ├── include
   ├── lib
   │   └── python3.8
   ... much ...
   
* Hm. Looks like the Python environment has been duplicated.
* ``bin/python``, ``bin/pip``, ``lib/python3.8``
* Point paths to it?
* |longrightarrow| *activating*

.. code-block:: console

   $ . my_venv/bin/activate
   (my_venv) $ 

* A-ha! Prompt.
* What are the effects?

.. code-block:: console
   :caption: Python version sandboxed

   (my_venv) $ type python
   python is /home/jfasch/tmp/my_venv/bin/python

.. code-block:: console
   :caption: ``$PATH``

   (my_venv) $ echo $PATH
   /home/jfasch/tmp/my_venv/bin:...(original PATH)...

.. code-block:: console
   :caption: *No* ``pip`` installed packages

   (my_venv) $ pip list
   Package    Version
   ---------- -------
   pip        20.2.2
   setuptools 41.6.0

*Local* Package Installation
----------------------------

.. code-block:: console

   (my_venv) $ pip install sklearn
   Collecting sklearn
     Using cached sklearn-0.0.tar.gz (1.1 kB)
   Collecting scikit-learn
   ... roedel ...

   (my_venv) $ pip list
   Package       Version
   ------------- -------
   joblib        0.16.0
   numpy         1.19.1
   pip           20.2.2
   scikit-learn  0.23.2
   scipy         1.5.2
   setuptools    41.6.0
   sklearn       0.0
   threadpoolctl 2.1.0

Freezing an Environment
-----------------------

Same information as in ``pip list`` (except ``pip`` and ``setuptools``
which are built-in) ...

.. code-block:: console

   (my_venv) $ pip freeze
   joblib==0.16.0
   numpy==1.19.1
   scikit-learn==0.23.2
   scipy==1.5.2
   sklearn==0.0
   threadpoolctl==2.1.0

Save to a file. Usually called ``requirements.txt``, but not
necessarily so.

.. code-block:: console

   (my_venv) $ pip freeze > ~/tmp/requirements.txt

Destroying an Environment
-------------------------

.. code-block:: console

   (my_venv) $ deactivate 
   $ rm -rf my_venv/

Recreating an Environment
-------------------------

.. code-block:: console

   $ python -m venv my_recreated_venv
   $ . ./my_recreated_venv/bin/activate
   (my_recreated_venv) $
   (my_recreated_venv) $ pip install -r ~/tmp/requirements.txt 
   ... roedel ...
   (my_recreated_venv) $ pip list
   Package       Version
   ------------- -------
   joblib        0.16.0 
   numpy         1.19.1 
   pip           19.3.1 
   scikit-learn  0.23.2 
   scipy         1.5.2  
   setuptools    41.6.0 
   sklearn       0.0    
   threadpoolctl 2.1.0  


