.. include:: <mmlalias.txt>

.. ot-topic:: c.structures.structures_and_functions
   :dependencies: c.structures.basics


``struct``: Functions
=====================

.. contents::
   :local:

Parameters and Return (1)
-------------------------

**Returning entire structures**

.. code-block:: c
   :caption: Constructor

   struct point makepoint(int x, int y)
   {
       struct point p;
   
       p.x = x;
       p.y = y;
       return p;
   }

Parameters and Return (2)
-------------------------

**Entire structure as parameter**

.. code-block:: c

   struct point addpoints(struct point lhs, struct point rhs)
   {
       lhs.x += rhs.x;
       lhs.y += rhs.y;
       return lhs;
   }

**Question**: does the caller see the modification of ``lhs``?

Parameters and Return (3)
-------------------------

**Pointers to structures ("call by reference")**

.. code-block:: c

   void addtopoint(struct point *lhs, struct point rhs)
   {
       (*lhs).x += rhs.x; /* precedence! */
       (*lhs).y += rhs.y;
   }

**Pointers to structures are very common** |longrightarrow| shortcut
"``->``"

.. code-block:: c

   void addtopoint(struct point *lhs, struct point rhs)
   {
       lhs->x += rhs.x;
       lhs->y += rhs.y;
   }
