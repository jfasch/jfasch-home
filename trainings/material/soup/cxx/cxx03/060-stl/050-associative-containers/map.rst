.. include:: <mmlalias.txt>


``std::map``
============

.. contents::
   :local:

.. toctree::
   :hidden:

   map-init-fill
   map-insert
   map-remove
   map-search
   map-index-operator-bad

Basics
------

.. sidebar:: Documentation

   * `std::map <https://en.cppreference.com/w/cpp/container/map>`__

* Implementation of a *key* to *value* mapping
* Internally realized as a `red-black tree
  <https://en.wikipedia.org/wiki/Red%E2%80%93black_tree>`__
* Template type, parameterized as ``std::map<keytype, valuetype>``

  .. code-block:: c++

     std::map<int, std::string> some_map;

* Tree nodes are *pairs* ``(key, value)``

  .. image:: 40-40-00-map.dia
     :scale: 40%

Type Instantiation
------------------

* Type of a map is, e.g. ``std::map<int, std::string>``
* |longrightarrow| Compiler instantiates red-black tree implementation
  of the mapping
* Key and value types not limited to built-in type, naturally
* Type has *member types* (used when operating on object of the map
  type)

  * ``key_type``: the *key*
  * ``mapped_type``: the *value* that the key maps to
  * ``value_type``: the *node* type that the red-black tree has
    (``std::pair<int, std::string>``)
  * ...
  * |longrightarrow| later

Filling The Container
---------------------

.. sidebar::

   **Live Hacking**

   * :doc:`map-init-fill`

* Default constructor |longrightarrow| empty container, obviously
* Pre C++11, containers can only be *initialized* as being empty

  * To be filled explicitly during runtime

* Since C++11:
  :doc:`/trainings/material/soup/cxx/cxx11/brace-initialization/index`
* Type definition with ``using`` is strongly recommended when working
  with maps

.. _cxx_map_inserting:
  
Inserting Elements
------------------

.. sidebar::

   **Documentation**

   * `map::operator[]()
     <https://en.cppreference.com/w/cpp/container/map/operator_at>`__
   * `map::insert()
     <https://en.cppreference.com/w/cpp/container/map/insert>`__
   * `map::emplace()
     <https://en.cppreference.com/w/cpp/container/map/emplace>`__

   **Live Hacking**

   * :doc:`map-insert`

Many ways to bring elements into the container, varying in their
key-collision semantics, and many other facets ...

* Subscript operator (``[]``): ``my_map[42] = "zweiundvierzig";``.
  Overwrites keys that are already there.
* ``insert()``. Does not overwrite; return value has an indicator if
  element was inserted.
* ``emplace()``. Like ``insert()``, but rather constructs element
  in-place. (Performance!)

Removing Elements
-----------------

.. sidebar::

   **Documentation**

   * `map::erase()
     <https://en.cppreference.com/w/cpp/container/map/erase>`__

   **Live Hacking**

   * :doc:`map-remove`

Many overloads ...

* ``erase(iterator)``: if one has a pointer to the element (for some
  reason)
* ``erase(begin-iterator, end-iterator)``: same rationale
* ``erase(key)``

Searching
---------

.. sidebar::

   **Documentation**

   * `map::find()
     <https://en.cppreference.com/w/cpp/container/map/find>`__
   * `map::operator[]()
     <https://en.cppreference.com/w/cpp/container/map/operator_at>`__
   * `map::at()
     <https://en.cppreference.com/w/cpp/container/map/at>`__

   **Live Hacking**

   * :doc:`map-search`

* ``find(key)``

  * if found, returns a pointer (err, iterator) to tree node (``(key,
    value)``)
  * otherwise, returns ``map.end()``
  * |longrightarrow| requires an ``if`` statement to check

* ``operator[]()`` is unusable in most cases

  * Mainly there for insertion
  * For technical reasons, can also be used to search
  * Creates new entry if key not found

* ``at(key)``

  * Like ``[key]`` if ``key`` is found
  * Throws ``std::out_of_range`` otherwise
