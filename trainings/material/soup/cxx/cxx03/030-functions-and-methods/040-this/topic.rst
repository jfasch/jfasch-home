.. include:: <mmlalias.txt>


``this``
========

.. contents::
   :local:

Hidden Pointer: ``this`` (1)
----------------------------

.. code-block:: c++

   class point
   {
   public:
       void move(int x, int y)
       {
           _x += x;
           _y += y;
       }
   private:
       int _x;
       int _y;
   };

* Where's the object?
* What's the object?
* Where's the *member* ``_x``?

Hidden Pointer: ``this`` (2)
----------------------------

**How would this be done in C?**

.. list-table::
   :align: left
   :header-rows: 1

   * * C++
     * C
   * * .. code-block:: c++

          point p(5, 6);
	  p.move(2, 3);

       * First parameter of each method: ``this``
       * Method name is: ``move`` in class ``point``

     * .. code-block:: c

          struct point p = {5, 6};
	  point_move(&p /*this*/, 2, 3);

       * C has no "bound" methods
       * Just plain functions

A-ha!! 

* ``p.move(2, 3)`` is equivalent to ``point::move(&p, 2, 3)``
* Just like C

Explicit ``this`` Pointer
-------------------------

For example to resolve ambiguity: say member are ``x`` and ``y``
(*not* prefixed with ``_``)

.. code-block:: c++

   class point
   {
   public:
       void move(int x, int y)
       {
           this->x += x;
	   this->y += y;
       }
   private:
       int x;
       int y;
   };
