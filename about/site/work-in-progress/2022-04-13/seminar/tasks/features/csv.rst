.. ot-task:: clean_code.features.csv

.. include:: <mmlalias.txt>


``UserDB``: Alternative Output Format - CSV
===========================================

.. contents::
   :local:

Write CSV: Test
---------------

.. sidebar:: Snippets

   * ``read-file``
   * ``write-csv``

**Talk**

* We have tests, why not continue this way?
* Write test to see how it could be done

**Write test**

* Copy ``test-funny-overflow-file.cpp`` to ``test-csv.cpp``
* Expected content: 

  .. code-block:: c++

     std::string expected_content = "666;Joerg;Faschingbauer;joerg@home.com\n";
     
* Pull in ``read-file`` (at the top of the file -> function)
* Write out filled DB

  **Discuss implementation strategy**

  In a hurry |longrightarrow| ``bool binary``

* ``read_file()``
* Compare

**Implement**

* In ``UserDB::write(string filename, bool binary=true)``

  * ``if/else``
  * Pull in ``write-csv`` into CSV branch

Write CSV: Frontend Program
---------------------------

Build that functionality into ``bin/userdb-write-binaryfile.cpp``

* Rename to ``bin/userdb-write.cpp``
* ``argv[1]`` ... type
* ``argv[2]`` ... filename


Read CSV: Test
--------------

.. sidebar:: Snippets

   * ``read-csv-test``

**Discuss**

* Do we really want to write one file per test? 
* Doesn't writing and reading CSV belong together?

**Implement read test inside** ``tests/test-csv.cpp``

* Rename ``main()`` to ``test_write_csv()``
* Call that in ``main()``
* New (empty) test, ``test_read_csv()``

  * Pull ``read-csv-test`` into body

* Ah yes, ``UserDB::read(string filename, binary=true)``

  * ``if/else``
  * Pull in ``write-csv`` into CSV branch

Write CSV: Frontend Program
---------------------------

Build that functionality into ``bin/userdb-read-binaryfile.cpp``

* Rename to ``bin/userdb-read.cpp``
* ``argv[1]`` ... type
* ``argv[2]`` ... filename
