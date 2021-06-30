.. include:: <mmlalias.txt>

.. jf-topic:: cxx03.functions_and_methods.const
   :dependencies: cxx03.functions_and_methods.methods


``const``
=========

``const``: Immutable Variable
-----------------------------

**Already possible in C:** immutable variables

.. list-table::

   * * .. code-block::

          const point *p;
	  p->x = 7;       // ERROR!!

     * Variables |longrightarrow| modification impossible

   * * .. code-block:: c++

          void f(const struct point *p)
	  {
	      p->x = 7;   // ERROR!!
	  }

     * Parameter |longrightarrow| modification impossible

``const``: Methods (1)
----------------------

* ``const`` methods *promise to the compiler* not to modify the object
* No promise |longrightarrow| compiler *has to assume* that the method
  modifies the object

.. list-table:: 

   * * .. code-block:: c++

          class point
          {
          public:
              int x() { return _x; }
              int y() { return _y; }
          private:
              int _x;
              int _y;
          };

     * .. code-block:: c++

          void f(const point *p)
          {
              cout << p->x();      // ERROR!!
          }

``const``: Methods (2)
----------------------

.. code-block:: c++

   class point
   {
   public:
       int x() const { return _x; }
       int y() const { return _y; }
   private:
       int _x;
       int _y;
   };

* "``const`` pollution" |DoubleLeftRightArrow| "being correct is very cumbersome"
* "``const`` correctness": best possible state
* Nice goodie offered by the language
