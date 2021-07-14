.. include:: <mmlalias.txt>

.. jf-topic:: cxx03.functions_and_methods.references
   :dependencies: cxx03.functions_and_methods.this


References
==========

Pointers, Seen Differently: References (1)
------------------------------------------

**Problem**

* Passing parameters *by copy* is expensive
* Especially when objects are large (well, a ``point`` is not so
  large, but you get the point)

.. list-table::
   :align: left

   * * .. code-block:: c++

          class point
          {
          public:
              float distance(point p) const
              {
                  int dx = abs(_x-p._x);
                  int dy = abs(_y-p._y);
                  return sqrt(dx*dx+dy*dy);
              }
          };

     * * **Problem**

         * Parameter is a ``copy``

       * **Solution**

         * Pass by pointer
	 * Even better: ``const`` pointer

Pointers, Seen Differently: References (2)
------------------------------------------

.. list-table::
   :align: left

   * * Definition
     * Usage
   * * .. code-block:: c++

          class point
          {
          public:
              float distance(const point *p) const
              {
                  int dx = abs(_x-p->_x);
                  int dy = abs(_y-p->_y);
                  return sqrt(dx*dx+dy*dy);
              }
          };

     * .. code-block:: c++

          point a(1,2);
	  point b(2, 3);
	  float dist = a.distance(&b);

       **Problem**
       
       * User has to take the address
       * Pointers can easily be ``NULL``
       
       **Solution**
       
       * References

Pointers, Seen Differently: References (3)
------------------------------------------

.. list-table::
   :align: left

   * * Definition
     * Usage
   * * .. code-block:: c++

          class point
          {
          public:
              float distance(const point &p) const
              {
                  int dx = abs(_x-p._x);
                  int dy = abs(_y-p._y);
                  return sqrt(dx*dx+dy*dy);
              }
          };

     * .. code-block:: c++

          point a(1,2);
	  point b(2, 3);
	  float dist = a.distance(b);

       **Pretty, because ...**

       * Looks like ordinary parameter passing
       * *Compiler* takes the address |longrightarrow| physically, a
         pointer is passed
       * ``NULL`` pointer passing (nearly) impossible
