WS2023/2024: Exam 2024-02-02 (Sample)
=====================================

.. list-table::
   :align: left

   * * **Name**
     * 

Question 1
----------

Given the following (incomplete) class definition ..

.. code-block:: c++

   class point
   {
   public:
       int x() const { return _x; }
   };

Question 1.1
............

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

Question 1.2
............

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

Question 2
----------

Question 2.1
............

Which of the following (partial) class definition would lead to better
performance in object initialization

.. code-block:: c++
   :caption: Variant A

   class Person
   {
   public:
       Person(std::string firstname, std::string lastname);
   };

.. code-block:: c++
   :caption: Variant B

   class Person
   {
   public:
       Person(const std::string& firstname, const std::string& lastname);
   };

.. list-table::
   :align: left
   :widths: auto

   * * Variant A
     * Variant B
   * *
     *

Question 2.2 (Why?)
...................

Why does the chosen variant perform better? (Write an ``X`` in the
"True" or "False" columns)

.. list-table::
   :align: left
   :widths: auto

   * * True
     * False
     * Statement
   * *
     *
     * Variant A has a shorter calling sequence
   * *
     *
     * Variant A is better at moving the parameters into the object
   * *
     *
     * Variant B does not create temporary copies

Question 3
..........

Consider the following ``Sensor`` hierarchy (and imagine that there
are many more implementations like ``W1Sensor`` out there that
implement the ``Sensor`` interface).

.. literalinclude:: q-solid--sensor-with-id/sensor.h
   :language: c++

.. literalinclude:: q-solid--sensor-with-id/sensor-w1.h
   :language: c++

Here is a sampe usage of the ``W1Sensor`` class.

.. literalinclude:: q-solid--sensor-with-id/sensor-with-id-main.cpp
   :language: c++

Which of the five SOLID principles are violated? (Wrong answers are
subtracted from correct answers)

.. list-table::
   :align: left
   :widths: auto

   * * `X` if violated
     * Principle
   * * 
     * Single Responsibility
   * * 
     * Open/Closed
   * * 
     * Liskov Substitution
   * * 
     * Interface Segregation
   * * 
     * Dependency Inversion
