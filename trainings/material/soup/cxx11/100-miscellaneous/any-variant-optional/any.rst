.. include:: <mmlalias.txt>


A Better ``void*``: ``std::any``
================================

.. sidebar::

   **Documentation**

   * `std::any
     <https://en.cppreference.com/w/cpp/utility/any>`__

.. contents::
   :local:

Default Initialization
----------------------

.. literalinclude:: code/any-default-ctor.cpp
   :caption: :download:`code/any-default-ctor.cpp`
   :language: c++

Initialization, Assignment, Access
----------------------------------

.. literalinclude:: code/any-init-access.cpp
   :caption: :download:`code/any-init-access.cpp`
   :language: c++

Copy, And Resource Management
-----------------------------

.. literalinclude:: code/any-copy.cpp
   :caption: :download:`code/any-copy.cpp`
   :language: c++

Run-Time Type Errors
--------------------

.. literalinclude:: code/any-bad-cast.cpp
   :caption: :download:`code/any-bad-cast.cpp`
   :language: c++

``has_value()``: Null?
----------------------

.. literalinclude:: code/any-has-value.cpp
   :caption: :download:`code/any-has-value.cpp`
   :language: c++

Avoiding Exceptions
-------------------

* ``any_cast<>`` on a pointer *is different*
* |longrightarrow| **does not throw**
* |longrightarrow| suitable for ``if``

.. literalinclude:: code/any-ptr-cast.cpp
   :caption: :download:`code/any-ptr-cast.cpp`
   :language: c++

Modifying In-Place: ``std::any_cast<>`` To *Reference*
------------------------------------------------------

.. literalinclude:: code/any-reference-cast.cpp
   :caption: :download:`code/any-reference-cast.cpp`
   :language: c++

``std::string`` And ``const char*`` Are Different
-------------------------------------------------

.. literalinclude:: code/any-string-and-charp.cpp
   :caption: :download:`code/any-string-and-charp.cpp`
   :language: c++
