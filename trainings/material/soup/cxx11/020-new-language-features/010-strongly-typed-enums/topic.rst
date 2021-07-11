.. include:: <mmlalias.txt>

.. jf-topic:: cxx11.new_language_features.strongly_typed_enums
   :dependencies: cxx11.introduction.introduction,
		  c.program_sanity.discrete_values


Strongly Typed ``enum``
=======================

C++03 ``enum`` Types: Motivation
--------------------------------

Why ``enum``? Why isn't ``int`` sufficient?

* Readability, Semantics
* ``switch`` statements without ``default`` label |longrightarrow|
  ``-Wswitch`` warns about missing enumerators
* Type safety: ``int`` cannot be assigned to an ``enum``

  * The other way around is possible

**Apart from that,** ``enum`` is crap!

C++03 ``enum`` Types: Problems
------------------------------

* Enumerators are not in the ``enum`` type's scope

  * Rather, they pollute the surrounding scope
  * |longrightarrow| no two enumerators with the same name

* Underlying type is not defined |longrightarrow| ``sizeof`` depends
  on compiler
* Implicit conversion to ``int``

.. attention::

   Workarounds possible, although much typing involved!

C++11 ``enum class``
--------------------

.. list-table::
   :align: left

   * * .. code-block::
          :caption: enum **class**

          enum class E1 {
            ONE,
            TWO
          };
          enum class E2 {
            ONE,
            TWO
          };
          E1 e1 = E1::ONE;
          E2 e2 = E2::ONE;
          int i = e1; // error

       * * No conflicts in surrounding scope
         * Body same as before
         * No conversion to ``int``
         * C++03 ``enum`` remains unchanged |longrightarrow| code
           compatibility
         * |longrightarrow| Cool!

C++11 ``enum class``: Underlying Type
-------------------------------------

.. list-table::
   :align: left

   * * .. code-block::
          :caption: Explicit type

          #include <cstdint>
          #include <cassert>
          enum E: uint8_t {
            ONE,
            TWO
          };
          void f() {
            assert(sizeof(E)==1);
          }

     * * In C++03 ``enum`` and ``enum class`` possible
       * Default: ``int``
       * Works with every integer types except ``wchar_t``


