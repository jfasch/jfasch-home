.. include:: <mmlalias.txt>


``std::bind``
=============

.. contents::
   :local:

.. sidebar:: 
   
   **Documentation**

   * `std::bind <https://en.cppreference.com/w/cpp/utility/functional/bind>`__

Why? What's The Problem?
------------------------

Clumsy code like below ...

* One-time functions, only used to do one stupid little thing
  (e.g. define ``double distance_origin(Point p)`` in terms of
  ``double distance(Point p, Point q)``)
* Function definition in places which are far off their call sites
  |longrightarrow| *readability suffers!*

Sample Program: All Done Manually
---------------------------------

.. literalinclude:: code/c++11-bind-distances-origin-manual.cpp
   :caption: :download:`code/c++11-bind-distances-origin-manual.cpp`
   :language: c++

Sideway: ``std::transform``
---------------------------

.. sidebar::

   **Documentation**

   * `std::transform
     <https://en.cppreference.com/w/cpp/algorithm/transform>`__

* Problem: manual loops to transform an array (or any container) into
  something else
* Loop body contains transformation code
* |longrightarrow| cries for duplicate code elimination (here: using
  `std::transform
  <https://en.cppreference.com/w/cpp/algorithm/transform>`__
* |longrightarrow| similar pattern across ``<algorithm>`` (see `here
  <https://en.cppreference.com/w/cpp/algorithm>`__)

  * Sorting criteria: ``std::sort``, ``std::map``, ...
  * Predicates: ``std::find_if``, ``std::equal``, ...
  * Arbitrary adaptations where helper functions are needed

Sample Program: Using ``std::transform``
----------------------------------------

Still using the one-time function ``double distance_origin(Point p)``
though ...

.. literalinclude:: code/c++11-bind-distances-origin-transform.cpp
   :caption: :download:`code/c++11-bind-distances-origin-transform.cpp`
   :language: c++

``std::bind``: Null Adaptation, Pointlessly
-------------------------------------------

.. literalinclude:: code/c++11-bind-null-adaptation.cpp
   :caption: :download:`code/c++11-bind-null-adaptation.cpp`
   :language: c++

``std::bind``: Adapting One Parameter To No Parameter
-----------------------------------------------------


.. literalinclude:: code/c++11-bind-one-to-zero-adaptation.cpp
   :caption: :download:`code/c++11-bind-one-to-zero-adaptation.cpp`
   :language: c++

``std::bind``: Hardcoding Parameters
------------------------------------

.. literalinclude:: code/c++11-bind-minus-hardcoded.cpp
   :caption: :download:`code/c++11-bind-minus-hardcoded.cpp`
   :language: c++

``std::bind``: Swapping Parameters |longrightarrow| ``std::placeholders``
-------------------------------------------------------------------------

.. literalinclude:: code/c++11-bind-minus-swap-params.cpp
   :caption: :download:`code/c++11-bind-minus-swap-params.cpp`
   :language: c++

``std::bind``: Hardcoding Only First Parameter |longrightarrow| ``std::placeholders``
-------------------------------------------------------------------------------------

.. literalinclude:: code/c++11-bind-minus-hardcode-first.cpp
   :caption: :download:`code/c++11-bind-minus-hardcode-first.cpp`
   :language: c++

``std::bind``: Functor (Is-A Callable)
--------------------------------------

.. literalinclude:: code/c++11-bind-functor.cpp
   :caption: :download:`code/c++11-bind-functor.cpp`
   :language: c++

``std::bind``: Lambda (Is-A Callable)
-------------------------------------

.. literalinclude:: code/c++11-bind-lambda.cpp
   :caption: :download:`code/c++11-bind-lambda.cpp`
   :language: c++

Sample Program: Using ``std::transform`` With ``std::bind``
-----------------------------------------------------------

See how we can eliminate the one-time function ``double
distance_origin(Point p)`` ...

.. literalinclude:: code/c++11-bind-distances-origin-transform-bind.cpp
   :caption: :download:`code/c++11-bind-distances-origin-transform-bind.cpp`
   :language: c++

Summary
-------

* Readability: what remains unreadable is only the language itself
* Have to get used to ``std::bind``

**What about types?**

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx11/bind-function/020-function/topic`

* Goal is to have *no runtime overhead*
* |longrightarrow| *Late binding (polymorphism)* ruled out
* |longrightarrow| No common base class
* Only the call signatures (parameter and return types) are the same
* If you want to define interfaces (i.e. share a type), use
  :doc:`std::function
  </trainings/material/soup/cxx11/bind-function/020-function/topic>`

**What does this mean?**

* Perfect for ``<algorithm>`` which is also designed for speed
* Have to be careful when code size is important
* Client code has to be instantiated with the type
* **Tradeoff**: speed, code size, elegance, design, taste ...

**And Lambdas?**

.. sidebar:: 

   **See also**

   * :doc:`/trainings/material/soup/cxx11/new-language-features/lambda/index`

* Lambdas are usually a better alternative
* |longrightarrow| more readable (?)

