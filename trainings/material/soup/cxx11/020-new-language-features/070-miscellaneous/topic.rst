.. ot-topic:: cxx11.new_language_features.miscellaneous
   :dependencies: cxx11.new_language_features.move.overview

.. include:: <mmlalias.txt>


Miscellaneous
=============

.. contents::
   :local:

``nullptr``
-----------
  
.. list-table::
   :align: left

   * * ``NULL`` **is insufficient ...**

       * Type is not defined
       * Could be ``void*``
       * Or just as well ``int``
       * |longrightarrow| Ambiguities
      
     * .. code-block:: c++
          :caption: ``nullptr``

          void f(int);
          void f(int*);
          
          f(NULL); // Hell!
          f(nullptr); // f(int*)

Templates end with "``>>``"
---------------------------
  
Small parser insufficiency got fixed ...

.. code-block:: c++
   :caption: ``> >`` vs. ``>>``

   std::map<int,vector<int> > ...;
   std::map<int,vector<int>> ...; // C++11: THANK YOU!

|longrightarrow| **It's about time!**

