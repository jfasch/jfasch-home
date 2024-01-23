Parameter Passing
=================

Which One Is Better?
--------------------

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

Why?
----

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

