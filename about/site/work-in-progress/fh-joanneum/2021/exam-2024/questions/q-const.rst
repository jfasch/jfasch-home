``const`` Objects
=================

Given the following (incomplete) class definition ..

.. code-block:: c++

   class point
   {
   public:
       int x() const { return _x; }
   };

Question 1
----------

Would the following code snippet compile?

.. code-block:: c++

   const point p(1,2);
   cout << p.x() << endl;

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Yes
     * No
   * *
     *

Question 2
----------

Would the following code snippet compile?

.. code-block:: c++

   point p(1,2);
   cout << p.x() << endl;

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Yes
     * No
   * *
     *
