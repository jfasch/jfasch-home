.. include:: <mmlalias.txt>

Decorators (Livehacking Screenplay)
===================================

.. contents::
   :local:

Closures Recap
--------------

.. list-table::
   :align: left

   * * 

       .. literalinclude:: code/10-closures-recap.py
	  :caption: :download:`code/10-closures-recap.py`
	  :language: python

       .. code-block:: console

          $ python code/10-closures-recap.py
          wrapper called, param = 1
          eins 1
          wrapper called, param = 2
          zwei 2
          wrapper called, param = blah
          blah blah

     * * ignore names ``decorator``, ``wrapper``
       
         * think ``outer`` and ``inner``, or ``foo`` and ``bar``

       * decorator semantics will come next

Simple Decorator: Function Without Args
---------------------------------------

.. list-table::
   :align: left

   * * 

       .. literalinclude:: code/20-decorator-no-args.py
	  :caption: :download:`code/20-decorator-no-args.py`
	  :language: python

       .. code-block:: console

          $ python code/20-decorator-no-args.py
          wrapper called, func = f1
          f1 called
          f1 returned 1
          wrapper called, func = f2
          f2 called
          f2 returned 2

     * * Modify ``decorator`` to take a function as parameter
       * print return values, and wrapping information

Decorators are Syntactic Sugar
------------------------------

.. list-table::
   :align: left

   * * 

       .. literalinclude:: code/30-decorator-syntactic-sugar.py
	  :caption: :download:`code/30-decorator-syntactic-sugar.py`
	  :language: python

       .. code-block:: console

          $ python code/30-decorator-syntactic-sugar.py
          wrapper called, func = f1
          f1 called
          f1 returned 1
          wrapper called, func = f2
          f2 called
          f2 returned 2

     * * Replace explicit wrapper call to ``decorator`` with "``@``"
         directly before function definitions
       * Simply call functions (they are automatically wrapped)
       * |longrightarrow| exactly the same
       * *That's basically it*!

``*args``, ``**kwargs``: A Debug-Decorator
------------------------------------------

.. list-table::
   :align: left

   * * 

       .. literalinclude:: code/40-debug-starargs-wrong.py
	  :caption: :download:`code/40-debug-starargs-wrong.py`
	  :language: python

       .. code-block:: console

          $ python code/40-debug-starargs-wrong.py
          Traceback (most recent call last):
            File "code/40-debug-starargs-wrong.py", line 15, in <module>
              print('add(1,2) returned', add(1,2))
          TypeError: wrapper() takes 0 positional arguments but 2 were given

     * * rename ``decorator`` to ``debug`` |longrightarrow| no change,
         basically
       * but: give ``f1`` and ``f2`` parameters ``l`` and ``r``, and
	 rename them to ``add`` and ``sub``
       * call program unmodified |longrightarrow| missing parameters

.. list-table::
   :align: left

   * * 

       .. literalinclude:: code/45-debug-starargs-right.py
	  :caption: :download:`code/45-debug-starargs-right.py`
	  :language: python

       .. code-block:: console

          $ python code/45-debug-starargs-right.py
          debug: func = add (1, 2) {}
          add(1,2) returned 3
          debug: func = sub (1, 2) {}
          sub(1,2) returned -1

     * * Fix it: give ``wrapper`` 2 args
       * think exactly: ``wrapper`` was given 2 arguments (we fix
         this)
       * why?
       * |longrightarrow| it is the function that is actually called
	 (returned by the decorator)

Sideway: ``functools.wraps``
----------------------------

.. list-table::
   :align: left

   * * 

       .. literalinclude:: code/50-wrapper-name-ugly.py
	  :caption: :download:`code/50-wrapper-name-ugly.py`
	  :language: python

       .. code-block:: console

          $ python code/50-wrapper-name-ugly.py
	  add name: wrapper
	  sub name: wrapper

     * * instead of printing the return value of the wrapped
         functions, print the names of the wrappers
       * |longrightarrow| both called "wrapper"

.. list-table::
   :align: left

   * * 

       .. literalinclude:: code/55-wrapper-name-pretty.py
	  :caption: :download:`code/55-wrapper-name-pretty.py`
	  :language: python

       .. code-block:: console

          $ python code/55-wrapper-name-pretty.py
	  add name: add
	  sub name: sub

     * * better |longrightarrow| copies metadata over

Class Decorator: ``debug()`` with prefix
----------------------------------------

.. list-table::
   :align: left

   * * 

       .. literalinclude:: code/55-wrapper-name-pretty.py
	  :caption: :download:`code/55-wrapper-name-pretty.py`
	  :language: python

       .. code-block:: console

          $ python code/60-class-decorator.py
          wtf: func = add, (1, 2), {}
          add(1,2) =  3
          gosh: func = sub, (1, 2), {}
          sub(1,2) =  -1

     * * start with decorator usage: ``@debug('wtf')``
       * see how this can be done ... think ... discuss
       * |longrightarrow| decorator must keep state
       * |longrightarrow| an *object* of a *class*
       * |longrightarrow| *hack it!*. Explain errors as they are
	 encountered, and fix.
