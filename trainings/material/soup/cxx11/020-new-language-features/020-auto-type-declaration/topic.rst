.. include:: <mmlalias.txt>

.. jf-topic:: cxx11.new_language_features.auto
   :dependencies: cxx11.new_language_features.strongly_typed_enums


``auto`` Type Declarations
==========================

``auto`` Type Declarations: Motivation
--------------------------------------
  
.. list-table::
   :align: left

   * * .. code-block:: c++
          :caption: Much ado about nothing ...

          vector<MyType>::iterator 
            iter = v.begin();

       .. code-block:: c++
	  :caption: Compiler knows anyway ...

	  auto iter = v.begin();

     * * *Type Deduction*
       * Compiler knows anyway
       * He always knew |longrightarrow| lookup of template
         specializations
       * |longrightarrow| Same rules apply

``auto`` Type Declarations: Details
-----------------------------------
  
.. list-table::
   :align: left

   * * .. code-block:: c++
          :caption: Simplest Type Deduction

	  auto i = 10; // int

       .. code-block:: c++
          :caption: ``cbegin()`` |longrightarrow| ``const_iterator``

	  auto iter = v.cbegin();

     * .. code-block:: c++
          :caption: ``const`` and References

	  const auto& cref = value;

       .. code-block:: c++
	  :caption: Arrays are Pointers

          int data[42];
          // int *no_copy ...
          auto no_copy = data;
