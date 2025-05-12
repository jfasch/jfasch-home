.. include:: <mmlalias.txt>

.. ot-topic:: cxx11.new_language_features.const_expr_init_eval.constexpr
   :dependencies: cxx11.new_language_features.const_expr_init_eval.const


``constexpr``
=============

.. contents::
   :local:

Compilers Always Did Runtime Work
---------------------------------

* Even back in the old C days, a compiler knew how to add two values
* *Compiler* calculates ``40+2``, and initializes ``answer`` with that
  *constant*

.. literalinclude:: code/constexpr-motivation.cpp
   :caption: :download:`code/constexpr-motivation.cpp`
   :language: c++

|longrightarrow| Continue on `Godbolt compiler explorer
<https://godbolt.org/>`__

Motivation: Let Compiler Do More Of This
----------------------------------------

* Extract ``40+2`` into a function
* |longrightarrow| this turns into a *function call*, rather than a
  precalculated constant
* **Would be cool if not**
* |longrightarrow| binary size reduction, startup time

.. literalinclude:: code/constexpr-add-simple-function.cpp
   :caption: :download:`code/constexpr-add-simple-function.cpp`
   :language: c++

Even ``-O3`` does not make it go away ...

.. code-block:: console

   $ g++ -O3 constexpr-add-simple-function.cpp
   $ nm --demangle a.out |grep add
   00000000004011a0 T add(int, int)

And ``static``? Why Not Use ``static``?
---------------------------------------

* ``static`` functions are only visible inside their own compilation
  unit
* |longrightarrow| compiler has complete freedom to do whatever with
  it

.. literalinclude:: code/constexpr-add-simple-function-static.cpp
   :caption: :download:`code/constexpr-add-simple-function-static.cpp`
   :language: c++

* Optimization off |longrightarrow| function call

.. code-block:: console

   $ g++ -O0 constexpr-add-simple-function-static.cpp
   $ nm --demangle a.out |grep add
   0000000000401136 t add(int, int)

* ``-O3`` |longrightarrow| compiler proves that eliminating ``add()``
  has no side effects (no outside calls possible) - and eliminates it

.. code-block:: console

   $ g++ -O3 constexpr-add-simple-function-static.cpp
   $ nm --demangle a.out |grep add

.. note:: This is not guaranteed! (Results produced with GCC 13)

Enter ``constexpr``
-------------------

* Historically, compilers always did such inlining and/or
  precalculations
* Not only for trivial functions as ``40+2``, but for varying degrees
  of complexity
* Nontrivial machinery: think about cross compilation, for example
* It's just that one cannot count on those optimizations
* They're gone with ``-O0`` |longrightarrow| *debug and release
  completely different*
* |longrightarrow| ``constexpr``

.. _cxx11-constexpr-force-necessary:

``constexpr`` Functions: Evaluated At Runtime *OR* Compiletime
--------------------------------------------------------------

.. literalinclude:: code/constexpr-add-constexpr-function.cpp
   :caption: :download:`code/constexpr-add-constexpr-function.cpp`
   :language: c++

.. code-block:: console

   $ g++ -O0 constexpr-add-constexpr-function.cpp
   $ nm --demangle a.out |grep add

* Again, this is not guaranteed!
* `Godbolt <https://godbolt.org/>`__

  * x86-64 GCC 15: evaluates in ``constexpr`` context
  * x86-64 clang 14: generates a call, **even though the parameters
    are immutable**

* |longrightarrow| not much better than ``static``
* ``constexpr`` implies ``inline`` though

*Forcing* Compiletime Evaluation
--------------------------------

.. sidebar:: See also

   * :doc:`consteval`

.. literalinclude:: code/constexpr-add-constexpr-function-request-constexpr.cpp
   :caption: :download:`code/constexpr-add-constexpr-function-request-constexpr.cpp`
   :language: c++

* This is necessary! |:thinking:|
* :doc:`consteval` fixes this

So What Are The Rules? ``constexpr`` Functions Are *Dual*
---------------------------------------------------------

**Rules**

* If the user wants compiletime evaluation, then they have to say so

  * Only *immutable* parameters!

* Runtime evaluation has no constraints - function is just called

.. literalinclude:: code/constexpr-add-constexpr-function-request-constexpr.cpp
   :caption: :download:`code/constexpr-add-constexpr-function-request-constexpr.cpp`
   :language: c++

* If the user wants to supply mutable parameters, they do *not*
  request compiletime evaluation

.. literalinclude:: code/constexpr-add-constexpr-function-runtime-call.cpp
   :caption: :download:`code/constexpr-add-constexpr-function-runtime-call.cpp`
   :language: c++

.. _cxx11-constexpr-uncool:

Uncool: Forcing Compiletime Evaluation Leads To ``constexpr`` Result
--------------------------------------------------------------------

.. sidebar:: See also

   * :ref:`cxx11-constexpr-force-necessary`

* One has to force ``constexpr`` context, even when calling with
  immutable parameters (see :ref:`here
  <cxx11-constexpr-force-necessary>`)
* Assigned-to variable has to be ``constexpr``
* |longrightarrow| this sucks somehow!

.. literalinclude:: code/constexpr-immutable-variable-uncool.cpp
   :caption: :download:`code/constexpr-immutable-variable-uncool.cpp`
   :language: c++

``constexpr`` Callchains
------------------------

* When a ``constexpr`` function is evaluated in ``constexpr`` context,
  all its calls have to be ``constexpr``

.. literalinclude:: code/constexpr-callchain.cpp
   :caption: :download:`code/constexpr-callchain.cpp`
   :language: c++

Recursion
---------

.. literalinclude:: code/constexpr-recursion.cpp
   :caption: :download:`code/constexpr-recursion.cpp`
   :language: c++

``constexpr`` Classes
---------------------

.. literalinclude:: code/constexpr-class.cpp
   :caption: :download:`code/constexpr-class.cpp`
   :language: c++

``constexpr`` Algorithms, ``constexpr std::vector``
---------------------------------------------------

* Rather new: C++20
* GCC 15 (newest, as of 2025-05-08) does not support this
* |longrightarrow| apparently, ``constexpr`` dynamic allocations are
  not trivial

.. literalinclude:: code/constexpr-sort.cpp
   :caption: :download:`code/constexpr-sort.cpp`
   :language: c++

Afterword: *Cool*
-----------------

* Compiler has a "virtual machine" of some sort that *evaluates* C
* When cross-compiling, that machine's architecture is the *target
  architecture*
* |longrightarrow| *This is not trivial!*
