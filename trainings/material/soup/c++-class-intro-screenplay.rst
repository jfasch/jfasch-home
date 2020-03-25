C++: The Very Basics (Screenplay)
=================================

.. sidebar:: Contents

   .. contents::
      :local:
      :depth: 1

Plain Old C: No Encapsulation
-----------------------------

Prepare directory structure,

.. code-block:: console

   .
   ├── CMakeLists.txt
   ├── c-point.c
   ├── c-point.h
   └── tests
       ├── CMakeLists.txt
       ├── c-point-tests.cc
       └── run.cc

Instantiation
.............

**Steps**

* plain C ``struct point``
* test driven (suite ``C_Point_Tests``)
* bulky ops (direct member access)

.. code-block:: c++

   struct point
   {
       int x;
       int y;
   };

and a test,

.. code-block:: c++

   TEST(C_Point_Tests, Instantiation)
   {
       struct point p = {1,2};
   
       ASSERT_EQ(p.x, 1);
       ASSERT_EQ(p.y, 2);
   }

**Discussion**

* Nah
* Direct member access?
* Check for equality? Like ``p == (1,2)``, or something?

Move a Point
............

.. code-block:: c++

   TEST(C_Point_Tests, Move)
   {
       struct point p = {1,2};
       p.x += 3;
       p.y += 3;
   
       ASSERT_EQ(p.x, 4);
       ASSERT_EQ(p.y, 5);
   }

**Discussion**

* Nah
* ``p.move(3,3)``, or something?

Add Points/Vectors?
...................

.. code-block:: c++

   TEST(C_Point_Tests, Add)
   {
       struct point p = {1,2};
       struct point q = {3,4};
   
       struct point added = {p.x+q.x, p.y+q.y}; // this is not C!
   
       ASSERT_EQ(added.x, 4);
       ASSERT_EQ(added.y, 6);
   }

**Discussion**

* Nah

Plain Old C: "Methods"
----------------------

**Steps**: add tests

* ``Instantiation_Func``: ``point_create()``

  * initially, "forget" to add extern "C"; demonstrate on the fly
  * ah yes, C++. cool.

  .. code-block:: c++

     TEST(C_Point_Tests, Instantiation_Func)
     {
         struct point p = point_create(1,2);
     
         ASSERT_EQ(p.x, 1);
         ASSERT_EQ(p.y, 2);
     }

* ``Move_Func``: ``point_move()``

  * discuss prototype: *lhs modified in place* - a point is moved

* ``Add_Func``: ``point_add()``

  * discuss prototype: *use two points (unmodified) to create new one*

* ``Compare_Func``: ``point_compare()``

  * discuss prototype: use ``int`` which is C's *boolean*
  * yes, ``memcmp()`` :-)

C++: ``class Point``
--------------------

**Steps**

* add ``cc-point-tests.cc`` (and, with the first test,
  ``point.{h,cc}``)
* ctor; member visibility
* move

  * variation: ``operator+=()``
  * discuss: ``+=`` usually has a value (``i += 7``)
  * ``Point&`` as retval to ``move()`` and ``+=()``
  * ``operator==()`` (while we are at it)
  * ``operator!=()`` (using ``ASSERT_NE()``)

* add
* last: inline

**Discussion**

* ``public``, ``private`` (``protected``?)
* access methods ("properties"?), ``const``
* ctor: initializer list
* add: ``this``

