.. ot-topic:: python.basics.python_0120_helloworld
   :dependencies: python.basics.python_0110_blahblah

.. include:: <mmlalias.txt>


Hello World
===========

.. contents::
   :local:

*Hello World*: Interactive Mode
-------------------------------

**Interactive Mode**

* Python interpreter, invoked without arguments
* Like Shell prompt, only with Python
* Exit |longrightarrow| type ``exit()``, or *End-of-file (EOF)*:

  * Unix (Linux, Mac): :kbd:`Ctrl` + :kbd:`d`
  * Windows: :kbd:`Ctrl` + :kbd:`z`

.. code-block:: console

   $ python
   Python 3.9.9 (main, Nov 19 2021, 00:00:00) 
   [GCC 11.2.1 20210728 (Red Hat 11.2.1-1)] on linux
   Type "help", "copyright", "credits" or "license" for more information.
   >>> print("Hello World")
   Hello World
   >>> 

*Hello World*: Script Files
---------------------------

**The first and simplest program ...**

.. literalinclude:: hello-world.py
   :caption: :download:`hello-world.py`
   :language: python

Run it like so:

.. code-block:: console

   $ python hello-world.py
   Hello World

.. note::

   This way of running Python programs works on both Unix and Windows,
   because the Python interpreter is invoked by hand.

   See :doc:`../python_0125_running/topic` for other, OS dependent,
   ways to run Python programs.
