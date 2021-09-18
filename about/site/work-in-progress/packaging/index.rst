Packaging this Site on PyPI
===========================

* ``README.md``. Move to ``.rst`` somehow, add proper description
* ``MANIFEST.in``
* ``setup.cfg``

  * ``author_email``
  * ``classifiers``
  * ``keywords``

* ``setup.py``
* ``tox.ini``?
* ``.travis.yml``?

Log
---

.. code-block:: console
   :caption: ``build`` package

   $ python3 -m pip install --upgrade build

.. code-block:: console

   $ python -m build

.. code-block:: console
   :caption: Wheels are ZIP files

   $ python -m zipfile --list dist/opentraining-0.99.999-py3-none-any.whl 

.. code-block:: console
   :caption: Installation

   $ pip install dist/opentraining-0.99.999-py3-none-any.whl 
   $ pip uninstall opentraining

Links
-----

* https://github.com/pypa/sampleproject
* `Python Packaging User Guide <https://packaging.python.org/>`__
