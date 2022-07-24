.. include:: <mmlalias.txt>

.. ot-topic:: cxx11.new_language_features.range_based_for_map
   :dependencies: cxx11.new_language_features.range_based_for


Case Study: Range Based ``for`` On ``std::map``
===============================================

.. contents::
   :local:

Gool Ol' Days: Iteration In C++ < 11
------------------------------------

**Loud!**

* Cannot simply initialize ``std::map`` with content

  * Initialize empty map
  * Fill it in regular code flow

* Iterators are cool only if one likes pointer arithmetic (otherwise
  not)
* Manually unpacking a ``std::pair`` is not so cool

.. literalinclude:: code/c++11-range-based-for-suite--map-pre-11.cpp
   :caption: :download:`code/c++11-range-based-for-suite--map-pre-11.cpp`
   :language: c++

Basic C++11 Iteration: Range Based For, ``auto``, And Initialization
--------------------------------------------------------------------

.. sidebar:: 
   
   **See also**

   * :doc:`030-brace-initialization/group`
   * :doc:`auto`

* New initialization syntax (:doc:`user's view
  <030-brace-initialization/intro>`, :doc:`implementor's view
  <030-brace-initialization/implementor-view>`)
* Compiler knows the type of a ``std::map`` iterator anyway

  * |longrightarrow| let him write the type
  * |longrightarrow| :doc:`auto <auto>`

.. literalinclude:: code/c++11-range-based-for-suite--map-basic.cpp
   :caption: :download:`code/c++11-range-based-for-suite--map-basic.cpp`
   :language: c++

Variation: Preventing Accidental Copy Using ``const auto&``
-----------------------------------------------------------

Using plain ``auto`` can be expensive ...

.. code-block:: c++

   for (auto elem: translations) {
       ...
   }

* ``std::pair<int, std::string>`` is usually cheap (depends on
  ``std::string`` implementation though)
* But what if iterating over ``std::map<int, std::vector<std::string>>``?
* |longrightarrow| Copying a possibly huge ``std::vector``!

.. literalinclude:: code/c++11-range-based-for-suite--map-basic-const-auto-reference.cpp
   :caption: :download:`code/c++11-range-based-for-suite--map-basic-const-auto-reference.cpp`
   :language: c++

Still unwanted though: manual ``std::pair`` unpacking

Pythonicity: Tuple Unpacking, err *Structured Binding*
------------------------------------------------------

.. sidebar:: 
   
   **See also**

   * :doc:`structured-binding`

**Wanted:** Python's tuple unpacking, as used in dictionary iteration

.. code-block:: python

   translations = { 0: 'zero', 1: 'one', 2: 'two' }
   for key, value in translations.items():
       do_something_with(key, value)

* |longrightarrow| :doc:`structured-binding`
* C++-ification of Python
* Comes in many flavors since C++ cares more about types, obviously

**Structured binding**: simplest usage - *by copy*

.. literalinclude:: code/c++11-range-based-for-suite--map-unpack-copy.cpp
   :caption: :download:`code/c++11-range-based-for-suite--map-unpack-copy.cpp`
   :language: c++

Structured Binding - Preventing Accidental Copy
-----------------------------------------------

* :doc:`auto <auto>` understands references and ``const`` references
* :doc:`structured binding <structured-binding>` relies on :doc:`auto
  <auto>`

|longrightarrow| let's use references more ...

.. literalinclude:: code/c++11-range-based-for-suite--map-unpack-reference.cpp
   :caption: :download:`code/c++11-range-based-for-suite--map-unpack-reference.cpp`
   :language: c++

.. literalinclude:: code/c++11-range-based-for-suite--map-unpack-const-reference.cpp
   :caption: :download:`code/c++11-range-based-for-suite--map-unpack-const-reference.cpp`
   :language: c++

