.. ot-topic:: cxx11.new_language_features.lambda.lambda

.. include:: <mmlalias.txt>


Lambda
======

.. contents::
   :local:

Motivation
----------
  
.. list-table::
   :align: left
   :widths: auto

   * * * E.g. ``<algorithm>``: comparison function, etc.
       * Functions have to be defined *elsewhere* ...
       * ... although used only once
       * |longrightarrow| much typing
       * |longrightarrow| loud
     * Reverse sorting ...

       .. code-block:: c++

	  static bool greater(int lhs, int rhs)
	  { 
	      return lhs > rhs;
	  }

	  // 2 kilometers down below ...
	  std::sort(v.begin(), v.end(), greater);

Lambda To The Rescue
--------------------

* "Lamda" (Python, Perl, ...)
* Definition *is* usage

Reverse sorting: lambda version ...

.. code-block:: c++

   std::sort(v.begin(), v.end(), [](int lhs, int rhs) { return lhs>rhs; });

Excursion: Python *Closures*
----------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/python/advanced/closures/topic`

* Python's closures are all *automatic*
* Created *at function definition time*
* |longrightarrow| *runtime*
* *Closure* = snapshot of names that are ...

  * Undefined in local scope of defined function (``print_message``)
  * Defined in surrounding scope (parameter ``message`` of creating
    function ``create_print_function``)

.. literalinclude:: ../code/closure.py
   :caption: :download:`../code/closure.py`
   :language: python

.. command-output:: python ../code/closure.py
   :cwd: .

Same In C++: *Capturing*
------------------------

.. sidebar:: 

   **See also**

   * :doc:`/trainings/material/soup/cxx11/040-bind-function/020-function/topic`

.. literalinclude:: ../code/c++11-lambda-capture.cpp
   :caption: :download:`../code/c++11-lambda-capture.cpp`
   :language: c++

.. code-block:: console

   $ code/c++11-lambda-capture
   howdy

* Here: *explicit capture*
* Variable ``message`` is *captured* into lambda function object
* Capture is *by copy* if not stated otherwise (see below)

So What Is That? (Answer: A *Functor*)
--------------------------------------

* *Functor*: an instance of a class that happens to be *callable* (has
  ``operator()(...)`` defined)
* *Nothing more*

.. note::

   Go through :doc:`lambda-is-functor`


Capturing By Reference |longrightarrow| *Careful!*
--------------------------------------------------

.. literalinclude:: ../code/c++11-lambda-capture-reference.cpp
   :caption: :download:`../code/c++11-lambda-capture-reference.cpp`
   :language: c++

.. code-block:: console

   $ code/c++11-lambda-capture-reference
   howdy

* Program creates a temporary ``std::string`` object (``"howdy"``)
* Lambda stores a reference to it, and uses it later
* |longrightarrow| *Attentive programmer jumps up and shouts!*

.. note::

   Go through :doc:`lambda-is-functor-pitfall`

.. danger::

   **Be very careful!**

   * Use *capture-by-reference* only when references are use locally
     (for example, passing to algorithms)
   * Don't use *capture-by-reference* in lambdas that you store on the
     heap, for example, or that you pass to other threads

More About Capturing
--------------------

See :doc:`lambda-capture`
