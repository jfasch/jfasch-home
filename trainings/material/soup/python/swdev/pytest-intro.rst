.. ot-topic:: python.swdev.pytest
   :dependencies: python.advanced.modules

.. include:: <mmlalias.txt>


``pytest`` Introduction, By Example
===================================

.. sidebar::

   **Contents**

   .. contents::
      :local:

   **pytest Documentation**

   :doc:`pytest:index`

Sample Project Structure
------------------------

Common project layout:

* Package in ``src/``
  
  * The project's name is ``opentraining``
  * So is the name of the root package: ``src/opentraining``
  * This is where most of the code is (programs are supposed to
    ``import`` from there).

* Tests are in ``tests``
* Package root is ``/home/jfasch/work/opentraining/`` (your mileage
  might vary)

.. code-block:: console

   $ tree ~/work/opentraining/
   /home/jfasch/work/opentraining/
   ├── src
   │    └── opentraining
   │        ├── __init__.py
   │        └── core
   │            ├── element.py
   │            ├── errors.py
   │            ├── exercise.py
   │            ├── group.py
   │            ├── node.py
   │            ├── person.py
   │            ├── project.py
   │            ├── soup.py
   │            ├── task.py
   │            └── topic.py
   └── tests
       ├── __init__.py
       ├── test_project.py
       ├── test_soup.py
       └── test_task.py

``pytest``: Installation, Documentation
---------------------------------------

* ``pytest`` is a PyPi package (`here
  <https://pypi.org/project/pytest/>`__)
* Suggest to create a project-specific :doc:`virtual environment
  <venv/topic>`, and install it into that.

  .. code-block:: console
  
     $ . ~/venv/opentraining/bin/activate
     (opentraining) $ python -m pip install pytest

* :doc:`Homepage and documentation <pytest:index>`

Running Tests
-------------

* ``pytest`` has no stringent requirements - only sane defaults
* Awesome *test discovery* |longrightarrow| working against *Lost
  Tests Syndrome*

.. code-block:: console
   :caption: Run all tests
   
   (opentraining) $ pwd
   /home/jfasch/work/opentraining
   (opentraining) $ python -m pytest
   ============================= test session starts =============================
   platform linux -- Python 3.9.7, pytest-6.2.5, py-1.11.0, pluggy-1.0.0
   rootdir: /home/jfasch/work/opentraining
   collected 10 items                                                            
   
   tests/test_project.py .....                                             [ 50%]
   tests/test_soup.py ...                                                  [ 80%]
   tests/test_task.py ..                                                   [100%]

   ============================== 5 passed in 0.19s ==============================

   
.. code-block:: console
   :caption: Run all tests in a file

   (opentraining) $ python -m pytest tests/test_project.py 
   ============================= test session starts =============================
   platform linux -- Python 3.9.7, pytest-6.2.5, py-1.11.0, pluggy-1.0.0
   rootdir: /home/jfasch/work/opentraining
   collected 5 items                                                             
   
   tests/test_project.py .....                                             [100%]
   
   ============================== 5 passed in 0.19s ==============================

.. code-block:: console
   :caption: Run single test from file

   $ python -m pytest tests/test_project.py -k test_person_points
   ============================= test session starts =============================
   platform linux -- Python 3.9.7, pytest-6.2.5, py-1.11.0, pluggy-1.0.0
   rootdir: /home/jfasch/work/opentraining
   collected 5 items / 4 deselected / 1 selected                                 
   
   tests/test_project.py .                                                 [100%]
   
   ======================= 1 passed, 4 deselected in 0.19s =======================

And ``PYTHONPATH``?
-------------------

* How do tests (in ``tests/``) import modules from
  ``src/opentraining``?
* ``pytest`` does not help us in this regard. Arguments:

  * Tests are not always run against code in the same package (in
    ``../src/`` for example) - the *uninstalled* case.
  * Tests might also be run against installed packages
    |longrightarrow| path already points there, nothing to do.

* When running tests against *uninstalled* code in the same package,
  an easy workaround is to tweak ``sys.path`` in the topmost test
  ``__init__.py`` file, ``tests/__init__.py``

  .. code-block:: python
     :caption: ``tests/__init__.py``
     
     import sys
     import os.path
     
     sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', 'src'))

.. note::

   Normally, when hacking about on your project, you have the
   ``PYTHONPATH`` point into ``src/`` anyway - so *for you as a
   developer*, tweaking the module search path in such a way is not
   necessary.

   It should be easy to run tests for *everybody* though, not only
   developers who generally know the package, but also

   * Testers and integrators
   * Aspiring developers
   * Build and CI bots

A Simple Test
-------------

* What is in a test? What's it that a ``test_*.py`` file contains?
* |longrightarrow| in the simplest case, a number of functions whose
  names start with ``test_``
* (Such test discovery strategies are only the default, and can be
  overridden if necessary)

.. code-block:: python
   :caption: Simple test (passes), in file ``tests/test_simple.py``

   def test_trivial():
       assert 1+1 == 2

.. code-block:: console
   :caption: Run simple test (just like explained above)

   (opentraining) $ python -m pytest tests/test_simple.py 
   ============================= test session starts =============================
   platform linux -- Python 3.9.7, pytest-6.2.5, py-1.11.0, pluggy-1.0.0
   rootdir: /home/jfasch/work/opentraining
   collected 1 item                                                              
   
   tests/test_simple.py .                                                  [100%]
   
   ============================== 1 passed in 0.00s ==============================

Failing Tests
-------------

That was simple. Lets add another test to the same file,

.. code-block:: python

   def test_trivial_but_fails():
       assert 1+1 == 3

Run both tests,

.. code-block:: console

   $ python -m pytest tests/test_simple.py 
   ============================= test session starts =============================
   platform linux -- Python 3.9.7, pytest-6.2.5, py-1.11.0, pluggy-1.0.0
   rootdir: /home/jfasch/work/opentraining
   collected 2 items                                                             
   
   tests/test_simple.py .F                                                 [100%]
   
   ================================== FAILURES ===================================
   ___________________________ test_trivial_but_fails ____________________________
   
       def test_trivial_but_fails():
   >       assert 1+1 == 3
   E       assert (1 + 1) == 3
   
   tests/test_simple.py:5: AssertionError
   =========================== short test summary info ===========================
   FAILED tests/test_simple.py::test_trivial_but_fails - assert (1 + 1) == 3
   ========================= 1 failed, 1 passed in 0.04s =========================

A More Realistic Example
------------------------

The ``opentraining`` :doc:`framework <opentraining:index>` of `Sphinx
<https://www.sphinx-doc.org/>`__ extensions has a "project management"
subsystem that allows a trainer to conduct a light form of
grading. Among others, there is a class ``Task``, one of whose
responsiblities is to calculate *statistics*.

.. code-block:: python
   :caption: ``tests/test_task.py``

   def test_stats():
       task = Task(
	   # ... stuff omitted ...
           
           implementation_points=70, 
           implementors=[(['implementor1'], 30), (['implementor2'], 20)],
           documentation_points=30, 
	   documenters=[(['documenter'], 30)],
           integration_points=90, 
           integrators=[(['integrator'], 10)],
       )
   
       implementation_percent, documentation_percent, integration_percent, total_percent = task.stats()
       assert implementation_percent == 30+20
       assert documentation_percent == 30
       assert integration_percent == 10
   
       total_points = 70+30+90
       gathered_points = 70*(30+20)/100 + 30*30/100 + 90*10/100
   
       assert total_percent == pytest.approx(gathered_points/total_points*100)

* Subject Under Test: ``Task.stats()``
* Four ``assert`` statements |longrightarrow| check that ``Task`` has
  done its job

Fixtures
--------

.. sidebar::

   See :doc:`here <pytest:how-to/fixtures>` much more about fixtures.

**Problem**

* What if I want to write another test upon the same task?
* Do I duplicate the entire task constructor in the new test?

|longrightarrow| **No, create a fixture!**

* ``@pytest.fixture`` decorator
* *Request* the fixture: give its name as the argument name to the
  test function (magic happens!)

.. code-block:: python

   import pytest
   
   @pytest.fixture
   def task():
       return Task(
	   # ... stuff omitted ...
           
           implementation_points=70, 
           implementors=[(['implementor1'], 30), (['implementor2'], 20)],
           documentation_points=30, 
           documenters=[(['documenter'], 30)],
           integration_points=90, 
           integrators=[(['integrator'], 10)],
       )
       
   def test_stats(task):
       implementation_percent, documentation_percent, integration_percent, total_percent = task.stats()
       assert implementation_percent == 30+20
       assert documentation_percent == 30
       assert integration_percent == 10
   
       total_points = 70+30+90
       gathered_points = 70*(30+20)/100 + 30*30/100 + 90*10/100
   
       assert total_percent == pytest.approx(gathered_points/total_points*100)

   def test_another_task_aspect(task):
       # ... test another task aspect ...

Temporary Test Directory
------------------------

.. sidebar::

   More built-in fixture see :doc:`pytest:reference/fixtures`

* Sometimes it is necessary to create temporary data in the filesystem
* ``pytest`` has a number of fixtures to cover this (and related) use
  cases
* *Request* the fixture |longrightarrow| ``tmpdir``
* Type is a path-like object (see :doc:`python:library/pathlib` what
  can be done with those)

Use it like so ...

.. code-block:: python

   def test_ini_file_parser(tmpdir):
       # create a file in tmpdir
       my_test_file = tmpdir / 'my-test-file.ini'
       with open(my_test_file, 'w') as ini:
           ini.write('\n'.join(
               [
                   '[section DS18S20]',
                   'type = DS18S20',
                   'name = name',
                   'address = addr',
               ]))
           
       # use that file in the test case
       with open(my_test_file) as ini:
           pass    # perform some testing with that file

Marking Tests as Expected to Fail
---------------------------------

* A feature is not yet ready
* Tests do exist though (*Test Driven Development*)
* Plan during TDD is that they will fail
* *Cannot commit/push without annoying others*
* |longrightarrow| ``@pytest.mark.xfail``

.. code-block:: python

   @pytest.mark.xfail
   def test_trivial_but_fails():
       assert 1+1 == 3

.. code-block:: console

   $ python -m pytest tests/test_simple.py 
   ============================= test session starts =============================
   platform linux -- Python 3.9.7, pytest-6.2.5, py-1.11.0, pluggy-1.0.0
   rootdir: /home/jfasch/work/opentraining
   collected 3 items                                                             
   
   tests/test_simple.py .x.                                                [100%]
   
   ======================== 2 passed, 1 xfailed in 0.01s =========================
