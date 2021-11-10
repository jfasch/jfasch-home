.. include:: <mmlalias.txt>

Virtual Environments (Livehacking Screenplay)
=============================================

.. contents::
   :local:

First: Help
-----------

.. code-block:: console

   $ python -m venv --help
   usage: venv [-h] [--system-site-packages] [--symlinks | --copies] [--clear] [--upgrade] [--without-pip] [--prompt PROMPT] ENV_DIR [ENV_DIR ...]
   
   Creates virtual Python environments in one or more target directories.
   
   positional arguments:
     ENV_DIR               A directory to create the environment in.
   
   optional arguments:
     -h, --help            show this help message and exit
     --system-site-packages
                           Give the virtual environment access to the system site-packages dir.
     --symlinks            Try to use symlinks rather than copies, when symlinks are not the default for the platform.
     --copies              Try to use copies rather than symlinks, even when symlinks are the default for the platform.
     --clear               Delete the contents of the environment directory if it already exists, before environment creation.
     --upgrade             Upgrade the environment directory to use this version of Python, assuming Python has been upgraded in-place.
     --without-pip         Skips installing or upgrading pip in the virtual environment (pip is bootstrapped by default)
     --prompt PROMPT       Provides an alternative prompt prefix for this environment.
   
   Once an environment has been created, you may wish to activate it, e.g. by sourcing an activate script in its bin directory.


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
   :caption: Unixen

   $ . my_venv/bin/activate
   (my_venv) $ 

.. code-block:: console
   :caption: Doze, ``cmd.exe``

   C:\ my_venv\Scripts\activate.bat

.. code-block:: console
   :caption: Doze, ``Powershell``

   PS C:\> my_venv\Scripts\Activate.ps1

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

Using Virtual Environments With :doc:`Visual Studio Code <../../misc/vscode>`
-----------------------------------------------------------------------------

`Here <https://code.visualstudio.com/docs/python/environments>`__ is
an explanation of the matter. In short: persuade VS Code to use the
Python interpreter from your virtual environment - that one has all
the paths VS Code needs to display help.
