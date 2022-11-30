.. include:: <mmlalias.txt>


Package Installation (``setuptools``)
=====================================

.. contents::
   :local:

Prerequisites
-------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/python/swdev/pypi`
   * :doc:`/trainings/material/soup/python/swdev/venv/topic`
   * :doc:`/trainings/material/soup/python/swdev/pip/topic`

* Virtual environment recommended (but not necessary)

.. code-block:: console

   $ python -m pip install setuptools wheel twine

Files
-----

.. literalinclude:: setup.py
   :caption: :download:`setup.py`
   :language: python

.. literalinclude:: pyproject.toml
   :caption: :download:`pyproject.toml`
   :language: toml

Test "Installation"
-------------------

.. code-block:: console

   $ python -m pip install --editable ~/work/2022-11-07/
   ... yadda ...

* Actually, not an *installation*
* Creates links to source package
* Can use the package *as if it were installed*
* *Source code is still editable*
* |longrightarrow| *very helpful*
* |longrightarrow| don't need to set ``$PYTHONPATH`` into ``src/``

Source Distribution
-------------------

.. code-block:: console

   $ cd ~/work/2022-11-07/
   $ python setup.py sdist
   ... yadda ...

Manifest
--------

* A file ``MANIFEST.in`` that contains all that need packaging
* Written manually by default
* Tool support: ``check-manifest``

  .. code-block:: console

     $ python -m pip install check-manifest

* Create (and add) ``MANIFEST.in``

  .. code-block:: console

     $ check-manifest --create
     $ git add MANIFEST.in

Packaging
---------

.. code-block:: console

   $ python setup.py bdist_wheel sdist
   ... yadda ...
   $ ls -l dist/
   total 20
   -rw-r--r--. 1 jfasch jfasch  1954 Nov 30 18:32 python_course_2022_11_07-0.0.1-py3-none-any.whl
   -rw-r--r--. 1 jfasch jfasch 12549 Nov 30 18:32 python-course-2022-11-07-0.0.1.tar.gz

Installing From Wheel File
--------------------------

.. code-block:: console

   $ python -m pip install ~/work/2022-11-07/dist/python_course_2022_11_07-0.0.1-py3-none-any.whl 

Publishing On PyPI
------------------

* TO BE DONE

  * twine
  * API Token

Links
-----

* ` Publishing (Perfect) Python Packages on PyPi
  <https://youtu.be/GIF3LaRqgXo>`__

  .. raw:: html

     <iframe
         width="560" height="315" 
	 src="https://www.youtube.com/embed/GIF3LaRqgXo" 
	 title="YouTube video player" 
	 frameborder="0" 
	 allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	 allowfullscreen>
     </iframe>
