.. include:: <mmlalias.txt>

Python: Hello World
===================

.. contents::
   :local:

.. jf-topic:: python_0120_helloworld

*Hello World*: Interactive Mode
-------------------------------

**Interactive Mode**

* Python interpreter, invoked without arguments
* "Shell prompt", only with Python
* Exit |longrightarrow| type :kbd:`Ctrl` + :kbd:`d` (End-of-file)

.. code-block:: console

   $ python
   Python 2.7.9 (default, Aug 15 2015, 22:03:50) 
   [GCC 4.8.4] on linux2
   Type "help", "copyright", "credits" or "license" for ...
   >>> print "Hello World"
   Hello World
   >>> 

*Hello World*: Python 3
-----------------------

**Major annoyance**: Python 3 is not compatible with Python 2

* Breaking compatibility is not an easy decision
* Necessary (so they say) to clean up > 20 years of dirt
* First hurdle: ``print`` is a *statement* in 2, and a *function* in 3
  
.. code-block:: console

   $ python3
   Python 3.4.1 (default, Aug 15 2015, 22:12:12) 
   [GCC 4.8.4] on linux
   Type "help", "copyright", "credits" or "license" for ...
   >>> print("Hello World")
   Hello World
   >>> 

*Hello World*: Python 2 vs. Python 3
------------------------------------

**Compatibility strategy**: the ``__future__`` module

* Enable future features in current versions
* Clearly remains valid in the future version
* One of many strategies
* The remainder of the course will try to be ...

  * version agnostic
  * forward compatible
  * backward compatible

*Tataa*: the feature ``print_function``!

.. code-block:: console

   $ python2
   ...
   >>> from __future__ import print_function
   >>> print("Hello World")
   Hello World
   >>>

*Hello World*: Script Files
---------------------------

**The first and simplest program ...**

.. code-block:: python
   :caption: ``hello-world.py``

   #!/usr/bin/python

   # omitted from now on
   from __future__ import print_function

   print("Hello World")

Make it executable, execute ...

.. code-block:: console

   $ chmod +x hello-world.py
   $ ./hello-world.py
