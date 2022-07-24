.. ot-topic:: cxx11.new_language_features.brace_initialization.implementor_view

.. include:: <mmlalias.txt>


``std::initializer_list``: Brace Initialization, Implementor's View
===================================================================

.. contents::
   :local:

``std::initializer_list``
-------------------------

.. sidebar::

   **Documentation**

   * `std::initializer_list
     <https://en.cppreference.com/w/cpp/utility/initializer_list>`__

* Used to implement brace initialization of custom datatypes, like ``std::vector``

  .. code-block:: c++

     std::vector<int> ints{1, 2, 3};
     std::vector<std::pair<int, std::string>> pairs{ {1, "one"}, {2, "two"} };

* When the compiler sees elements in braces, it creates a
  ``std::initializer_list<T>`` of those elements (deducing whatever
  types are necessary)
* Very lightweight |longrightarrow| no copy
* Shallow wrapper around compiler-specific internals

Direct Usage
------------

Works like any container datatype ...

.. code-block:: c++

   #include <initializer_list>

   std::initializer_list<point> points { {1, 2}, {3, 4} };
   for (auto p: points)
       do_something_with(p);

Custom Class That Supports Brace Initialization
-----------------------------------------------

.. code-block:: c++

   struct point
   {
       int x, y;
   };
   
   class PointCloud
   {
   public:
       PointCloud(std::initializer_list<point> points) : _points(points) {}
   private:
       std::vector<point> _points;
   };
   
   PointCloud cloud{ {1, 2}, {2, 3} };
