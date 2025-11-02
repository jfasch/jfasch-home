.. include:: <mmlalias.txt>


C++: News Until C++20 (2025-05-14 - 2025-05-15)
===============================================

.. contents::
   :local:

.. toctree::
   :hidden:

   agenda

.. sidebar::

   * :doc:`agenda`

Day 1
-----

Lambda
......

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx/cxx11/lambda/index`

There was some controversy among the audience about the usage of
lambda in their code, so I tried to demystify it right at the
beginning.

* :doc:`/trainings/material/soup/cxx/cxx11/lambda/lambda`
* :doc:`/trainings/material/soup/cxx/cxx11/lambda/lambda-is-functor`
* :doc:`/trainings/material/soup/cxx/cxx11/lambda/lambda-is-functor-pitfall`
* :doc:`/trainings/material/soup/cxx/cxx11/lambda/lambda-capture`

Concepts (a.k.a. "Template error messages are a PITA")
......................................................

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx/cxx11/concepts/index`

Definitely new in C++20, concepts are there to bring better C++
template error messages to the world.

* :doc:`/trainings/material/soup/cxx/cxx11/concepts/intro/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/concepts/writing-concepts/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/concepts/links`

``constexpr``, and the C++20 ``consteval`` and ``constinit``
............................................................

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx/cxx11/constexpr-constinit-consteval/index`

C++20 has a ton of new keywords, all building upon the ``constexpr``
capability of modern C++.

* :doc:`/trainings/material/soup/cxx/cxx11/constexpr-constinit-consteval/const`
* :doc:`/trainings/material/soup/cxx/cxx11/constexpr-constinit-consteval/constexpr`
* :doc:`/trainings/material/soup/cxx/cxx11/constexpr-constinit-consteval/consteval`
* :doc:`/trainings/material/soup/cxx/cxx11/constexpr-constinit-consteval/constinit`
* :doc:`/trainings/material/soup/cxx/cxx11/constexpr-constinit-consteval/if`

The Spaceship Operator
......................

Created to bring some order to the ordering operators ``<``, ``>``,
``<=``, ``>=``, ``==``, ``!=``, the spaceship operator brings disorder
at first sight (`P1185R2
<https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p1185r2.html#motivation>`__).

* :doc:`/trainings/material/soup/cxx/cxx11/spaceship/topic`

Day 2
-----

The bigger part of the second day was dedicated to
multithreading. This is good thing because there's a lot to be said
and known.

The remaining time was used to somehow shutdown the course looking
over less relevant topics in a frontal way.

Multithreading (And Related Topics)
...................................

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx/cxx11/multithreading/index`

* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/atomic-shared-ptr/topic`. 

  * Discussed why a :doc:`"normal" shared pointer
    </trainings/material/soup/cxx/cxx11/smart-pointers/shared-ptr/topic>` is only
    half threadsafe
  * How to use it safely pre 20, to get to the solution - atomic
    shared pointer. 
  * On a sideway, we saw how to use :doc:`promise and future
    </trainings/material/soup/cxx/cxx11/multithreading/promise-future>`
    for one-shot synchronization (:ref:`here
    <cxx11-thread-atomic-shared-ptr-sync-thread-start>`)

* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/memory-model/topic`

  * Discussed *load-modify-store*, and non-atomicity in general.
  * Memory orders "acquire" and "release". A naive spinlock
    implementation to demonstrate what a mutex is.
  * Memory order "sequential consistency" (and its application to the
    load-modify-storeproblem).

* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/020-thread/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/040-locking-atomics/mutex`
* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/040-locking-atomics/scoped-locking`

  Not strictly C++20 news, we quickly ran over these.

Something Different: Coroutines
```````````````````````````````

Another form of parallelism. To get hold of it, a showed (in Python)
what generators are, and what ``asyncio`` is. The message: both are
applications of *coroutines*.

.. list-table::
   :align: left
   :header-rows: 1

   * * Generator
     * Async
   * * .. literalinclude:: fibonacci.py
          :caption: :download:`fibonacci.py`
	  :language: python
     * .. literalinclude:: asio.py
          :caption: :download:`asio.py`
          :language: python

In :doc:`/trainings/material/soup/cxx/cxx11/coroutines/intro` we see the
C++ approach. Neither generators nor async is already there in C++20,
although C++23 has `generators
<https://en.cppreference.com/w/cpp/coroutine/generator>`__.

Local variables in ``if`` and ``for`` statements
................................................

* :doc:`/trainings/material/soup/cxx/cxx11/control-flow-locals/topic`

Attributes
..........

* :doc:`/trainings/material/soup/cxx/cxx11/attributes/topic`

Ranges
......

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx/cxx11/ranges/index`

* :doc:`/trainings/material/soup/cxx/cxx11/ranges/intro`
* :doc:`/trainings/material/soup/cxx/cxx11/ranges/good-bad`
* :doc:`/trainings/material/soup/cxx/cxx11/ranges/links`
