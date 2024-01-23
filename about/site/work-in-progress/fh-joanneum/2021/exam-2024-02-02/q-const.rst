``const``
=========

Given the following (incomplete) class definition ..

.. code-block:: c++

   class point
   {
   public:
       int x() const { return _x; }
   };

``const`` Objects
-----------------

Would the following code snippet compile?

.. code-block:: c++

   const point p(1,2);
   cout << p.x() << endl;

.. list-table::
   :align: left
   :widths: auto

   * * Yes
     * No
   * *
     *

Non-``const`` Objects
---------------------

Would the following code snippet compile?

.. code-block:: c++

   point p(1,2);
   cout << p.x() << endl;

.. list-table::
   :align: left
   :widths: auto

   * * Yes
     * No
   * *
     *
