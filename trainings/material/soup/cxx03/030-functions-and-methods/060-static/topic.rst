.. include:: <mmlalias.txt>

.. jf-topic:: cxx03.functions_and_methods.static
   :dependencies: cxx03.functions_and_methods.references


``static``
==========

Methods without Object - ``static`` (1)
---------------------------------------

**What we know now:**

* Methods are great
* Name and variable |longrightarrow| Method (like ``p.move(1,2)``)
* |longrightarrow| clear writing

**But:** *global* functions? Methods without an object?

* Not bound to objects
* Same scheme ("method of the class")?

**Example:**

* Adding points in C takes two ``const`` points and makes a third
* Does not operate on any one parameter in particular
* |longrightarrow| global

.. code-block:: c++

   point point_add(const point &l, const point &l);

Methods without Object - ``static`` (2)
---------------------------------------

.. list-table::
   :header-rows: 1

   * * Definition
     * Usage
   * * .. code-block:: c++

          class point
          {
          public:
              static point add(const point &l, const point &r)
              {
                  return point(l.x()+r.x(), l.y()+r.y());
              }
          };

     * .. code-block:: c++

          point a(1,2), b(2, 3);
	  point c = point::add(a, b);
