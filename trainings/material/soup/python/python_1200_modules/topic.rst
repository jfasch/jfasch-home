.. include:: <mmlalias.txt>

Modules and Packages
====================

.. contents::
   :local:

.. ot-topic:: python.swdev.python_1200_modules
   :dependencies: python.basics.python_0270_functions,
		  python.basics.python_0140_variables,
		  python.swdev.python_1050_oo


Modules
-------

* Collection of ... well ... *objects* - e.g. classes, functions,
  variables
* Collected in a dedicated ``.py`` file
* Pulled in with the ``import`` statement

.. code-block:: python

   import sys

So where is ``sys`` looked for?


* In the directory where the *importer* lives
* Along the ``PYTHONPATH`` environment variable
* In the Python installation's module directories

Modules are Objects
-------------------

* ``import`` makes a *module object* available under a name
* |longrightarrow| a variable
* Contained names accessible through that variable
* |longrightarrow| "Namespace"

.. code-block:: python

   import sys
   ...
   sys.exit(42)

Other Forms (1)
---------------

.. code-block:: python
   :caption: Pulling in a single symbol

   from sys import exit
   exit(42)

.. code-block:: python
   :caption: Massacre ...

   from sys import *
   exit(42)


* Pulls in *everything* into the importer's namespace

  * Well, except those names that start with an underscore

* Conflicts easily possible
* Importer's names are overwritten with conflicting names

Other Forms (2)
---------------

.. code-block:: python
   :caption: Changing a module's name

   import sys
   my_sys = sys
   del sys

.. code-block:: python
   :caption: Shorter ...

   import sys as my_sys

.. code-block:: python
   :caption: Same with specific imports

   from sys import exit as my_exit
   my_exit(42)

Packages
--------

* *Package*: collection of modules (and further packages)
* "Subnamespace"

.. code-block:: python

   import os.path
   path = os.path.normpath('a/../b')

.. code-block:: python

   from os.path import normpath

Executing Modules as Scripts
----------------------------


* A module's name is its filename, with the ``.py`` extension stripped
* Available to the module in the variable ``__name__``
* Can be used to decide if the module is being imported or executed as
  a script

.. code-block:: python
   :caption: Inside ``mysupermodule.py``

   def mysuperfunction(a, b):
       ...
   
   if __name__ == '__main__':
       mysuperfunction(sys.argv[1], sys.argv[2]))

Package Structure
-----------------

.. code-block:: console

   package/
   +-- __init__.py
   +-- subpackage1
   |   +-- __init__.py
   |   +-- module1.py
   |   \- module2.py
   \- subpackage2
       +-- __init__.py
       +-- module1.py
       \-- module2.py

* Top level directory ``package/`` found in module search path
* Each directory has file ``__init__.py``

  * Disambiguation
  * Usually empty

Relative Imports (1)
--------------------

.. code-block:: console

   package/
   +-- subpackage1
       +-- module1.py
       \- module2.py

**Problem**: inside ``module1.py``, I want to ...

* ``import module2``
* *Not* search along the entire module search path
* I know that ``module2`` is next to me

.. code-block:: python

   from . import module2

Relative Imports (2)
--------------------

.. code-block:: console

   package/
   +-- subpackage1
       \-- module1.py
   \- subpackage2
       \-- module1.py

**Problem:**

* ``subpackage1/module1.py`` wants to import
  ``subpackage2/module1.py``
* ... and nothing else

.. code-block:: python

   from ..subpackage2 import module1
