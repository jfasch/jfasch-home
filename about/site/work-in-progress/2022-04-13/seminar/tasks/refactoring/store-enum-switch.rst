.. ot-task:: clean_code.refactoring.store_enum_switch
   :dependencies: clean_code.features.csv


``UserDB::{read,write}()``: ``bool``, Really?
=============================================

.. code-block:: c++

   void write(const std::string& filename, bool binary=true);
   void read(const std::string& filename, bool binary=true);

Boolean parameters are forbidden (according to Uncle Bob).

* Introduce an ``enum`` (``enum class`` maybe), and pass that instead
* Eliminate the default value
* Show what ``switch`` can do for you, provided you don't put a
  ``default:`` label.
