.. include:: <mmlalias.txt>


``std::filesystem``
===================

.. contents::
   :local:

Overview
--------

.. sidebar::

   **Documentation**

   * `std::filesystem
     <https://en.cppreference.com/w/cpp/filesystem>`__

   **See also**

   * :doc:`/trainings/material/soup/linux/basics/shell/index`

* File system related stuff (obviously)

  * Path manipulation
  * Directory creation and iteration |longrightarrow| even recursive!
  * Stats like *size*, *access time*
  * Permissions
  * Support routines like copy, remove, ...

* Since C++ 17
* Continually improved since then

Fixture
-------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/unittest/unittest_gtest_fixture/topic`

(Not central to this topic, just for completeness)

This topic is mainly livehacked, along the test cases that
follow. Each test case is executed withing a :doc:`test fixture
</trainings/material/soup/unittest/unittest_gtest_fixture/topic>`;
that fixture works as follows:

* Every test case has its own temporary directory, by a
  ``std::filesystem::path`` type variable, ``dirname``
* The test case run *inside* that directory; i.e. the process's
  :doc:`current working directory </trainings/material/soup/linux/basics/shell/cwd>` is set to
  ``dirname`` before the test runs, and reset to whatever it was before.
* ``dirname`` is removed after each test run |longrightarrow|
  :doc:`fixture </trainings/material/soup/unittest/unittest_gtest_fixture/topic>`

.. literalinclude:: code/suite.h
   :caption: :download:`code/suite.h`
   :language: c++

Paths: Composition, Comparison
------------------------------

.. sidebar::

   **Documentation**

   * `std::filesystem::path
     <https://en.cppreference.com/w/cpp/filesystem/path>`__

* Paths are OS dependent

  * |longrightarrow| directory separators, for example (``/`` on
    Unixen, ``\`` on Doze)

* ``std::filesystem::path`` does not access filesystem
* Used as input to higher level routines
* Main operators: ``/=``, ``/``
* Lexical comparison
* Largely compatible with ``std::string``

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

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Method
     * Description
   * * ``path.is_absolute()``
     * Is ``path`` a absolute path
   * * ``path.is_relative()``
     * Is ``path`` a relative path

.. literalinclude:: code/path_abs_rel.cpp
   :caption: :download:`code/path_abs_rel.cpp`
   :language: c++

Path Component Access
---------------------

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Method
     * Description
   * * ``path.filename()``
     * extract filename part
   * * ``path.parent_path()``
     * extract parent directory
   * * ``path.remove_filename()``
     * remove filename part, leaving parent directory path in place
   * * ``path.replace_filename()``
     * replace filename part
   * * ``path.replace_extension()``
     * replace extension

.. literalinclude:: code/path_component_access.cpp
   :caption: :download:`code/path_component_access.cpp`
   :language: c++

Iterating Over Path Components
------------------------------

* A ``path`` is basically a list of strings
* Separated by OS specific directory separators
* *Absolute paths start with a separator*

.. literalinclude:: code/path_iteration.cpp
   :caption: :download:`code/path_iteration.cpp`
   :language: c++

Current Working Directory
-------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/basics/shell/cwd` (from
     :doc:`/trainings/material/soup/linux/basics/index`)

* Current working directory: process attribute
* Process can change CWD
* ... and get it of course

.. literalinclude:: code/current_directory.cpp
   :caption: :download:`code/current_directory.cpp`
   :language: c++

Directory Creation: ``std::filesystem::create_directory()``
-----------------------------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/basics/shell/file_dir_create_rm` (from
     :doc:`/trainings/material/soup/linux/basics/index`)

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

Directory Creation: ``std::filesystem::create_directories()``
-------------------------------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/basics/shell/file_dir_create_rm` (from
     :doc:`/trainings/material/soup/linux/basics/index`)

* Creating multiple level of directories in one shot
* Like ``mkdir -p ...``

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

.. sidebar::

   **Documentation**

   * `std::filesystem
     <https://en.cppreference.com/w/cpp/filesystem>`__

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

Directory Entries: Basics
-------------------------

.. sidebar::

   **Documentation**

   * `std::filesystem::directory_entry
     <https://en.cppreference.com/w/cpp/filesystem/directory_entry>`__
   * `man -s 2 stat
     <https://man7.org/linux/man-pages/man2/statx.2.html>`__

* Represents a *thing* that can be contained in a directory
* OS dependent (as everything in ``std::filesystem``)
* Contains

  * File type (regular file, directory, symlink, character/block
    device, pipe, ...)
  * File status (permissions, etc.)

* Tries to implement the greatest common divisor across different OSen

  * ... and fails (in my opinion)

* Unix ``ls -l``

.. code-block:: console

   $ ls -l /etc/passwd
   -rw-r--r--. 1 root root 2691 Nov 15 15:45 /etc/passwd

* More information: Unix ``stat``

.. code-block:: console

   $ stat /etc/passwd
     File: /etc/passwd
     Size: 2691      	Blocks: 8          IO Block: 4096   regular file
   Device: 0,36	Inode: 919153      Links: 1
   Access: (0644/-rw-r--r--)  Uid: (    0/    root)   Gid: (    0/    root)
   Context: system_u:object_r:passwd_file_t:s0
   Access: 2022-12-06 15:00:15.111282886 +0100
   Modify: 2022-11-15 15:45:06.737858445 +0100
   Change: 2022-11-15 15:45:06.743858359 +0100
    Birth: 2022-11-15 15:45:06.737858445 +0100

Directory Entries: ``std::filesystem::directory_entry``
-------------------------------------------------------

.. sidebar::

   **Documentation**

   * `std::filesystem::directory_entry
     <https://en.cppreference.com/w/cpp/filesystem/directory_entry>`__

* Commonly used when iterating over directories (see below)
* Carries information about what's being iterated over

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Method
     * Description
   * * ``entry.path()``
     * returns the path the entry refers to
   * * ``entry.exists()``
     * checks whether directory entry refers to existing file system
       object
   * * ``entry.is_block_file()``
     * checks whether the directory entry refers to block device
   * * ``entry.is_character_file()``
     * checks whether the directory entry refers to a character device
   * * ``entry.is_directory()``
     * checks whether the directory entry refers to a directory
   * * ``entry.is_fifo()``
     * checks whether the directory entry refers to a named pipe
   * * ``entry.is_other()``
     * checks whether the directory entry refers to an other file
   * * ``entry.is_regular_file()``
     * checks whether the directory entry refers to a regular file
   * * ``entry.is_socket()``
     * checks whether the directory entry refers to a named IPC socket
   * * ``entry.is_symlink()``
     * checks whether the directory entry refers to a symbolic link
   * * ``entry.file_size()``
     * returns the size of the file to which the directory entry
       refers
   * * ``entry.hard_link_count()``
     * returns the number of hard links referring to the file to which
       the directory entry refers
   * * ``entry.last_write_time()``
     * gets or sets the time of the last data modification of the file
       to which the directory entry refers
   * * ``entry.status()``
     * status of the file designated by this directory entry

.. literalinclude:: code/directory_entry.cpp
   :caption: :download:`code/directory_entry.cpp`
   :language: c++

Iterating Over Directory Entries
--------------------------------

.. sidebar::

   **Documentation**

   * `man -s 3 readdir
     <https://man7.org/linux/man-pages/man3/readdir.3.html>`__

   **See also**

   * :doc:`/trainings/material/soup/cxx/cxx03/060-stl/010-basics/topic`

* Directories contain entries

  * |longrightarrow| want to iterate over those
  * |longrightarrow| :doc:`C++ iterators
    </trainings/material/soup/cxx/cxx03/060-stl/010-basics/topic>`

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
