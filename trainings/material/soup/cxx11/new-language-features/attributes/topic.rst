.. include:: <mmlalias.txt>


Attributes
==========

.. contents::
   :local:

``[[noreturn]]``
----------------

.. sidebar:: Documentation

   * `C++ attribute: noreturn (since C++11)
     <https://en.cppreference.com/w/cpp/language/attributes/noreturn>`__

* *Function* attribute
* Compiler can know that control flow will not return to the caller
* |longrightarrow| warnings
* |longrightarrow| optimizations

.. literalinclude:: code/noreturn.cpp
   :caption: :download:`code/noreturn.cpp`
   :language: c++

* GCC 13 does not say anything though

``[[deprecated]]``
------------------

.. sidebar:: Documentation

   * `C++ attribute: deprecated (since C++14)
     <https://en.cppreference.com/w/cpp/language/attributes/deprecated>`__

.. literalinclude:: code/deprecated.cpp
   :caption: :download:`code/deprecated.cpp`
   :language: c++

``[[fallthrough]]``: Problem
----------------------------

.. sidebar:: Documentation

   * `C++ attribute: fallthrough (since C++17)
     <https://en.cppreference.com/w/cpp/language/attributes/fallthrough>`__

* GCC: ``-Wimplicit-fallthrough`` is highly recommended (also enabled
  by ``-Wextra``)
* Omitting ``break`` is usually a bug
* Similar functionality available from other compilers too
* (GCC?) observation: have to have a statement before falling through

.. literalinclude:: code/fallthrough-warn.cpp
   :caption: :download:`code/fallthrough-warn.cpp`
   :language: c++

* Sometimes ``break``-less ``case`` is desired
* |longrightarrow| Want to selectively disable

``[[fallthrough]]``: Usage
--------------------------

.. literalinclude:: code/fallthrough-warn-suppress.cpp
   :caption: :download:`code/fallthrough-warn-suppress.cpp`
   :language: c++

``[[nodiscard]]``: Problem
--------------------------

.. sidebar:: Documentation

   * `C++ attribute: nodiscard (since C++17)
     <https://en.cppreference.com/w/cpp/language/attributes/nodiscard>`__

* Compiler does not insist that function return values are respected
* There might be warning options, but these are probably too loud (and
  unwanted in most cases)

.. literalinclude:: code/nodiscard-problem.cpp
   :caption: :download:`code/nodiscard-problem.cpp`
   :language: c++

``[[nodiscard]]``: Solution
---------------------------

* ``[[nodiscard]]``, best together with ``-Werror``
* |longrightarrow| Usage has to be fixed  

.. literalinclude:: code/nodiscard-warning.cpp
   :caption: :download:`code/nodiscard-warning.cpp`
   :language: c++

* |longrightarrow| fix it

.. literalinclude:: code/nodiscard-fix.cpp
   :caption: :download:`code/nodiscard-fix.cpp`
   :language: c++

``[[nodiscard]]`` On Entire Types
---------------------------------

.. literalinclude:: code/nodiscard-entire-type.cpp
   :caption: :download:`code/nodiscard-entire-type.cpp`
   :language: c++

``[[maybe_unused]]``
--------------------

.. sidebar:: Documentation

   * `C++ attribute: maybe_unused (since C++17)
     <https://en.cppreference.com/w/cpp/language/attributes/maybe_unused>`__

* Compiler warns about unused variables (``-Wunused-variable``,
  ``-Wall``)
* Hard to find a usecase where this is not wanted
* I don't believe there is one

.. literalinclude:: code/maybe-unused-problem.cpp
   :caption: :download:`code/maybe-unused-problem.cpp`
   :language: c++

.. literalinclude:: code/maybe-unused-solution.cpp
   :caption: :download:`code/maybe-unused-solution.cpp`
   :language: c++

``[[likely]]``
--------------

.. sidebar:: Documentation

   * `C++ attribute: likely, unlikely (since C++20)
     <https://en.cppreference.com/w/cpp/language/attributes/likely>`__
   * `LWN: How likely should likely() be?
     <https://lwn.net/Articles/70473/>`__

* Help the compiler with branch optimization
* Attention though (see `here <https://lwn.net/Articles/70473/>`__):
  there may be a performance penalty for misguessing

That said ...

.. literalinclude:: code/likely-if.cpp
   :caption: :download:`code/likely-if.cpp`
   :language: c++

.. literalinclude:: code/likely-switch.cpp
   :caption: :download:`code/likely-switch.cpp`
   :language: c++
