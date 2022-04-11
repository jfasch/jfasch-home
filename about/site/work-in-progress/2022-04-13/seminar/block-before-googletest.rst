.. include:: <mmlalias.txt>


Live Hacking Before (Formal) Unit Testing
=========================================

.. contents::
   :local:

Initial Structure
-----------------

.. sidebar:: Snippets

   * Create tree from ``initial-tree.tar.xz``
   * Push to Github

.. code-block:: console

   $ tree
   .
   ├── bin
   │   └── CMakeLists.txt
   ├── CMakeLists.txt
   ├── src
   │   └── userdb
   │       └── CMakeLists.txt
   └── tests
       └── CMakeLists.txt

Talk about project plan

* In memory ``UserDB``. Features

  * Load/store from/to file
  * Search
  * Iterate

``User``
--------

.. sidebar:: Snippets

   ``user.h`` into ``src/userdb``

Talk

* Database payload
* ID is going to be primary key
* |longrightarrow| ``UserDB``

``UserDB``
----------

* Create file from scratch (it is the class that we will be talking
  about)

.. code-block:: console

   void insert(const User& u) { /*not caring about duplicates*/ }

``bin/userdb-write-binaryfile.cpp``
-----------------------------------

.. sidebar:: Snippets

   ``write-initial`` into ``bin/userdb-write-binaryfile.cpp``

Talk

* End goal: dump db into file format
* Start with program ``bin/userdb-write-binaryfile.cpp``

  Pull in ``write-initial``

* Think about writing

  * Commandline parameter |longrightarrow| ``filename``
  * How?
  * |longrightarrow| ``db.write(filename);``

Extend ``UserDB`` To Write
--------------------------

.. sidebar:: Snippets

   * ``binary-user``
   * ``user-from-stdin``

In ``bin/userdb-write-binaryfile.cpp``

* Add ``argv[1]`` |longrightarrow| filename
* Add call ``db.write(filename)``

In ``src/userdb/userdb.{h,cpp}``, implement ``UserDB::write(const string&)``

* *Write a chapter of method documentation!*
* Loop over ``std::map`` entries (using range based ``for``)
* Pull in ``binary-user``
* ``open(... O_CREAT|O_TRUNC|O_WRONLY, 0666)`` (``assert``'ing that
  all is well)

  **Mode** 0666!!

* Convert ``User`` to ``BinaryUser``

  * Use ``htons()`` from ``<arpa/inet.h>``
  * ``write()``, again only ``assert``'ing

* Look into written file, using ``od -c``
* Complete ``bin/userdb-write-binaryfile.cpp``, to not write hardwired
  users

  * Pull in ``user-from-stdin``

* Finally, use ``bin/userdb-write-binaryfile`` to enter

  * 666, "Joerg", "Huber", "joerg@home.com"
  * 42, "Caro", "Huber", "caro@home.com"
  * 7, "Johanna", "Huber", "johanna@home.com"

Extend ``UserDB`` To Read From File, And Iterate
------------------------------------------------

.. sidebar:: Snippets

   * ``read-and-dump``
   * ``userdb-iterator``

* Pull in ``read-and-dump`` into ``bin/userdb-read-binaryfile.cpp``
* Add to ``CMakeLists.txt``
* Implement ``UserDB::read()``

  * Pull in ``read-binary`` into body of ``read()``

* Compile, and see the iteration still not implemented
* Pull ``userdb-iterator`` into ``userdb.h``
* Pull ``begin-end`` into ``userdb.h``

Bug: Use "Faschingbauer" As Last Name
-------------------------------------

.. sidebar:: Snippets

   * ``test-funny-overflow``
   * ``temp-file``

* Create a new database,

  * 666, "Joerg", "Faschingbauer", "joerg@home.com"

* Dump it. See that ``email`` got overwritten.
* Write ``tests/test-funny-overflow.cpp``. Suspecting the inmem DB to
  loose things (foolishly).

  * Pull in ``test-funny-overflow`` into empty file
  * Add to ``CMakeLists.txt``
  * Build
  * Implement ``UserDB::find()``
  * Run
  * Works |longrightarrow| next test

* Write ``tests/test-funny-overflow-file.cpp``

  * Copy ``tests/test-funny-overflow.cpp`` to
    ``tests/test-funny-overflow-file.cpp``
  * Pull in ``temp-file``, right inside ``main()``
  * Find bug

* Discuss: either change everything (errorhandling!)

  * |longrightarrow| no, lets just silently truncate
  * |longrightarrow| document that as a feature (i.e. modify the test
    to require "Faschingb")

Wrap Up: What Do We Have?
-------------------------

* Code base that works, somehow
* How do we know?
* |longrightarrow| we have two tests

.. code-block:: console

   $ for test in ./test-*; do [ -x $test ] && ( $test && echo "SUCCESS: $test" 1>&2 || echo "FAILURE: $test" 1>&2 ) done
   SUCCESS: ./test-funny-overflow
   SUCCESS: ./test-funny-overflow-file

* ``test-funny-overflow`` is actually testing ``UserDB::find()``
* Rename to ``test-find``

Requirement: CSV File Format
----------------------------

Write CSV: Test
...............

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
...........................

Build that functionality into ``bin/userdb-write-binaryfile.cpp``

* Rename to ``bin/userdb-write.cpp``
* ``argv[1]`` ... type
* ``argv[2]`` ... filename


Read CSV: Test
..............

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
...........................

Build that functionality into ``bin/userdb-read-binaryfile.cpp``

* Rename to ``bin/userdb-read.cpp``
* ``argv[1]`` ... type
* ``argv[2]`` ... filename

Wrap Up
-------

**Convincing** ...

.. code-block:: console

   $ for test in ./test-*; do [ -x $test ] && ( $test && echo "SUCCESS: $test" 1>&2 || echo "FAILURE: $test" 1>&2 ) done
   SUCCESS: ./test-csv
   SUCCESS: ./test-find
   SUCCESS: ./test-funny-overflow-file

**See fixtures**

jjj
