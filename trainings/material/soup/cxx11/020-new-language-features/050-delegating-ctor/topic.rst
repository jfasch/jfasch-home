.. include:: <mmlalias.txt>

.. ot-topic:: cxx11.new_language_features.delegating_ctor
   :dependencies: cxx11.new_language_features.range_based_for


Delegating Constructor
======================

.. contents::
   :local:

Delegating Constructor: Motivation
----------------------------------
  
**Every constructor does basically the same**

.. code-block:: c++

   class Data
   {
   public:
     Data(const void *p, size_t s) : data_(p), size_(s) {}
     Data(const string& s) : data_(s.c_str()), size_(s.size()) {}  // <--- DUPLICATION!
   private:
     const void *data_;
     size_t size_;
   };

Delegating Constructor: Solution
--------------------------------
  
**Constructor delegates**

.. code-block:: c++

   class Data
   {
   public:
     Data(const void *p, size_t s) : data_(p), size_(s) {}
     Data(const string& s) : Data(s.c_str(), s.size()) {}   // <--- DELEGATION
   private:
     const void *data_;
     size_t size_;
   };
