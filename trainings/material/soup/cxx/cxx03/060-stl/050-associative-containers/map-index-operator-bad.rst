.. include:: <mmlalias.txt>


Screenplay: Why Not To Use ``operator[]``
=========================================

.. contents::
   :local:

Basic Operation (Looks Fine)
----------------------------

* Insert two elements

  .. literalinclude:: code/map-index-operator.cpp
     :language: c++
     :caption: :download:`code/map-index-operator.cpp`

* Fine: they are in

  .. code-block:: console

     $ ./cxx-stl-map-index-operator 
     :one:
     :two:

And Elements That Have Never Been Inserted?
-------------------------------------------

* Now lets access an element that is not contained

  .. literalinclude:: code/map-index-operator-access-notexist.cpp
     :language: c++
     :caption: :download:`code/map-index-operator-access-notexist.cpp`

* It is in, but (apparently) with a default value

  .. code-block:: console

     $ ./cxx-stl-map-index-operator-access-notexist
     ::

Know It: ``operator[]`` Is *Not Made For Read Access*
-----------------------------------------------------

.. sidebar:: Documentation

   * `std::map::operator[]
     <https://en.cppreference.com/w/cpp/container/map/operator_at>`__

* Cannot use ``operator[]`` on a ``const`` map

  .. literalinclude:: code/map-index-operator-nonconst.cpp
     :language: c++
     :caption: :download:`code/map-index-operator-nonconst.cpp`

  .. code-block:: console

     map-index-operator-nonconst.cpp:7:35: error: passing ‘const std::map<int, std::__cxx11::basic_string<char> >’ as ‘this’ argument discards qualifiers [-fpermissive]
         7 |     std::cout << ':' << my_map[666] << ":\n";
           |                                   ^

* If an element exists with key, a *non-const* reference to it is returned
* If none exists, on is created |longrightarrow| *default constructed*
* |longrightarrow| May be overwritten
