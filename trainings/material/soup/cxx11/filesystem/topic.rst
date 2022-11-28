.. ot-topic:: cxx11.filesystem

.. include:: <mmlalias.txt>


``std::filesystem``
===================

.. contents::
   :local:

.. note::

   This topic is usually live hacked.

Overview
--------

.. sidebar::

   **Documentation**

   * `std::filesystem
     <https://en.cppreference.com/w/cpp/filesystem>`__

* File system related stuff (obviously)

  * Path manipulation
  * Directory creation and iteration |longrightarrow| even recursive!
  * Stats linke size, access time
  * Permissions
  * Support routines like copy, remove, ...

* Since C++ 17
* Continually improved since then

Fixture
-------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/unittest/unittest_gtest_fixture/topic`

* Every test case has its own temporary directory, by a
  ``std::filesystem::path`` type variable, ``dirname``
* Directory is removed after each test run |longrightarrow|
  :doc:`fixture </trainings/material/soup/unittest/unittest_gtest_fixture/topic>`
* (Not central to this topic, just for completeness)

.. literalinclude:: code/suite.h
   :caption: :download:`code/suite.h`
   :language: c++

Paths: Composition, Comparison
------------------------------

.. sidebar::

   **Documentation**

   * `std::filesystem::path
     <https://en.cppreference.com/w/cpp/filesystem/path>`__

* ``std::filesystem::path`` does not access filesystem
* Used as input to higher level routines
* Main operators: ``/=``, ``/``
* Lexical comparison
* Largely compatible with ``str::string``

.. literalinclude:: code/path_compose_compare.cpp
   :caption: :download:`code/path_compose_compare.cpp`
   :language: c++

.. literalinclude:: code/path_compose_compare_2.cpp
   :caption: :download:`code/path_compose_compare_2.cpp`
   :language: c++

Absolute and Relative Paths
---------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/basics/shell/paths`

.. literalinclude:: code/path_abs_rel.cpp
   :caption: :download:`code/path_abs_rel.cpp`
   :language: c++

Path Component Access
---------------------

* Extracting filename from an entire path
* Extracting parent directory from an entire path
* ...

.. literalinclude:: code/path_component_access.cpp
   :caption: :download:`code/path_component_access.cpp`
   :language: c++

Iterating Over Path Components
------------------------------

* A ``path`` is basically a list of strings
* Separated by OS specific directory separators
* Absolute paths start with a separator

.. literalinclude:: code/path_iteration.cpp
   :caption: :download:`code/path_iteration.cpp`
   :language: c++

Directory Creation: ``std::filesystem::create_directory()``
-----------------------------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/basics/shell/file_dir_create_rm`

* Os wise, creating a directory fail if the parent directory does not
  exist (or has no permissions)
* |longrightarrow| E.g. ``mkdir -p`` allows you to create paths of
  multiple levels

.. literalinclude:: code/create_directory_error.cpp
   :caption: :download:`code/create_directory_error.cpp`
   :language: c++

* Create directories one at a time

.. literalinclude:: code/create_directory_single.cpp
   :caption: :download:`code/create_directory_single.cpp`
   :language: c++

Directory Creation: ``std::filesystem::create_directories()`` (``mkdir -p``)
----------------------------------------------------------------------------

* Creating multiple level of directories in one shot

.. literalinclude:: code/create_directory_multiple.cpp
   :caption: :download:`code/create_directory_multiple.cpp`
   :language: c++

Directory Entry Classification: ``std::filesystem::is_xxx()``
-------------------------------------------------------------

* Directories may contain files and directories
* Symbolic links, named pipes, character devices, block devices, ...
* |longrightarrow| classification routines

.. literalinclude:: code/is_xxx.cpp
   :caption: :download:`code/is_xxx.cpp`
   :language: c++

From `cppreference.com <https://en.cppreference.com/w/cpp/filesystem>`__:

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Function
     * Description
   * * ``is_block_file``
     * checks whether the given path refers to block device
   * * ``is_character_file``
     * checks whether the given path refers to a character device
   * * ``is_directory``
     * checks whether the given path refers to a directory
   * * ``is_empty``
     * checks whether the given path refers to an empty file or
       directory
   * * ``is_fifo``
     * checks whether the given path refers to a named pipe
   * * ``is_other``
     * checks whether the argument refers to an other file
   * * ``is_regular_file``
     * checks whether the argument refers to a regular file
   * * ``is_socket``
     * checks whether the argument refers to a named IPC socket
   * * ``is_symlink``
     * checks whether the argument refers to a symbolic link

Iterating Over Directory Entries
--------------------------------

.. sidebar::

   **Documentation**

   * `man -s 3 readdir
     <https://man7.org/linux/man-pages/man3/readdir.3.html>`__

   **See also**

   * :doc:`/trainings/material/soup/cxx03/060-stl/010-basics/topic`

* Directories contain entries

  * |longrightarrow| want to iterate over those
  * |longrightarrow| :doc:`C++ iterators
    </trainings/material/soup/cxx03/060-stl/010-basics/topic>`

* OS wise, directories are not read in any particular order
* File system specific (e.h. ``ext4`` might be different from
  ``btrfs`` from ``ntfs``)

.. literalinclude:: code/directory_iterator.cpp
   :caption: :download:`code/directory_iterator.cpp`
   :language: c++

Recursive Directory Iteration
-----------------------------

.. literalinclude:: code/recursive_directory_iterator.cpp
   :caption: :download:`code/recursive_directory_iterator.cpp`
   :language: c++
