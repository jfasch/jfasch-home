.. include:: <mmlalias.txt>


``override``
============

.. contents::
   :local:

.. sidebar:: 

   **Documentation**

   * `override
     <https://en.cppreference.com/w/cpp/language/override>`__

Correct Overriding ...
----------------------

Here is a correct example ...

.. literalinclude:: code/c++11-override-ok.cpp
   :caption: :download:`code/c++11-override-ok.cpp`
   :language: c++

.. code-block:: console

   $ ./c++11-override-ok 
   Derived::method

.. important::

   Both ``Base::method()`` and ``Derived::method()`` have exact same
   signature

... Is Very Hard
----------------

For example, one could accidentally omit the ``const``

* |longrightarrow| completely different, *new*, method!
* |longrightarrow| base class method called (when accessed via base
  class pointer)

.. literalinclude:: code/c++11-override-omit-const.cpp
   :caption: :download:`code/c++11-override-omit-const.cpp`
   :language: c++

.. code-block:: console

   $ ./c++11-override-omit-const 
   Base::method

More Problems Arise
-------------------

* Accidentally omitting (or adding) ``const``
* Adding parameters
* Changing parameter types
* Refactoring: renaming base class (or interface) methods
* In any case ...

  * |longrightarrow| Have to find out all implementations
  * |longrightarrow| Might not even be in the same code base
    (plugins?)

* ...

Solution: ``override``
----------------------

.. literalinclude:: code/c++11-override-keyword.cpp
   :caption: :download:`code/c++11-override-keyword.cpp`
   :language: c++

.. code-block:: console

   code/c++11-override-keyword.cpp:18:18: error: ‘virtual void Derived::method()’ marked ‘override’, but does not override
      18 |     virtual void method() override
         |                  ^~~~~~

