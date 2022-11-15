.. ot-topic:: python.advanced.iteration_generation
   :dependencies: python.basics.python_0220_for

Iteration, Comprehensions, and Generators
=========================================

.. contents::
   :local:

Coverage Of This Topic
----------------------

* List comprehensions
* The ``range`` function
* Writing generators using ``yield``
* Generator expressions

``for`` Recap: *Sequential Datatypes*
-------------------------------------

.. list-table::
   :align: left

   * * 

       .. literalinclude:: code/10-for-recap.py
	  :caption: :download:`code/10-for-recap.py`
	  :language: python

       .. code-block:: console

          $ python code/10-for-recap.py 
          1
          2
          3
          4

     * * This is the point in sequential datatypes: *iteration* with
         ``for``, mainly

Primitive Transformation ``[1,2,3,4]`` |longrightarrow| ``[1,4,9,16]``
----------------------------------------------------------------------

.. list-table::
   :align: left

   * * 

       .. literalinclude:: code/20-squares-func.py
	  :caption: :download:`code/20-squares-func.py`
	  :language: python

       .. code-block:: console

          $ python code/20-squares-func.py
          1
          4
          9
          16


     * * Define function to create squares list

List Comprehension
------------------

**Problem**: 

* function used in one place
* ... but defined elsewhere

.. list-table::
   :align: left

   * * 

       .. literalinclude:: code/30-squares-comprehension.py
	  :caption: :download:`code/30-squares-comprehension.py`
	  :language: python

       .. code-block:: console

          $ python code/30-squares-comprehension.py
          1
          4
          9
          16

     * * Same behavior as ``squares()``, but more readable
       * Provided that your colleagues know what list comprehensions
         are

*Where does readability end?* |longrightarrow| ``if`` clause

.. list-table::
   :align: left

   * * 

       .. literalinclude:: code/40-odd-squares-comprehension.py
	  :caption: :download:`code/40-odd-squares-comprehension.py`
	  :language: python

       .. code-block:: console

          $ python code/40-odd-squares-comprehension.py
	  1
          9
          25
          49
          81

     * * Somewhere a line has to be drawn
       * |longrightarrow| it's a team decision, as everything

Larger Input List (Still *Allocated*)
-------------------------------------

**Problem**: what about large lists? Say, 10 million elements.

.. list-table::
   :align: left

   * * 

       .. literalinclude:: code/50-larger-list.py
	  :caption: :download:`code/50-larger-list.py`
	  :language: python

       .. code-block:: console

          $ python code/50-larger-list.py
          filling input list
          calculating squares
          ... numbers ...

     * * Start without the ``print()`` statements.
       * Wonder why it takes so long.
	 * Composing two lists
       * Burden on OS

Input List |longrightarrow| ``range``
-------------------------------------

**Problem**: using lists primarily for *iteration*. Can this be done
 better?

.. list-table::
   :align: left

   * * 

       .. literalinclude:: code/60-input-range.py
	  :caption: :download:`code/60-input-range.py`
	  :language: python

       .. code-block:: console

          $ python code/60-input-range.py
          creating input range
          calculating squares
          ... numbers ...

     * * Morph ``inputlist`` into ``inputrange``
       * eliminate loop altogether
	 * ``range`` has been created in no time
       * Discuss ``range``
       * |longrightarrow| *Generator*

Output List |longrightarrow| ``yield``
--------------------------------------

**Problem**: still using temporary list in ``squares()``

.. list-table::
   :align: left

   * * 

       .. literalinclude:: code/70-output-yield.py
	  :caption: :download:`code/70-output-yield.py`
	  :language: python

       .. code-block:: console

          $ python code/70-output-yield.py
          1
          4
          9
          16

     * * Morph back to ``squares()`` function
       * What's so disgusting?

	 * Temporary list in ``squares()``
	 * Gently introduce ``yield``: remove temporary list + its return

       * What's still disgusting?

	 * |longrightarrow| input list
	 * |longrightarrow| ``range``

       * Perfect!
       * Discuss ``yield``

	 * Still ``def``, but contains ``yield`` |longrightarrow|
           *generator*
	 * Morphing temporary lists to ``yield`` is straightforward

Generator Function |longrightarrow| *Generator Expression*
----------------------------------------------------------

**Problem** (re-introduced): ``squares()`` definition and usage are
 too far apart

.. list-table::
   :align: left

   * * 

       .. literalinclude:: code/80-generator-expression.py
	  :caption: :download:`code/80-generator-expression.py`
	  :language: python

       .. code-block:: console

          $ python code/80-generator-expression.py
          1
          4
          9
          16

     * * *Generator expression*
       * |longrightarrow| just like list comprehension, only smarter
