.. include:: <mmlalias.txt>

Filesystem Interaction, Pathname Manipulation
=============================================

.. contents::
   :local:

``file``: Host Filesystem Access
--------------------------------

.. sidebar:: Documentation

   * `file <https://cmake.org/cmake/help/latest/command/file.html>`__
   * `cmake_path (since 3.20)
     <https://cmake.org/cmake/help/latest/command/cmake_path.html>`__

* Set of methods to interact with the host filesystem
* Complemented by ``cmake_path()``: path manipulation, without any
  filesystem interaction

``file(READ ...)``: Read Entire File
------------------------------------

.. sidebar:: Documentation

   * `file(READ ...)
     <https://cmake.org/cmake/help/latest/command/file.html#read>`__

* Reads an entire file into a variable
* |longrightarrow| optional size limit

.. literalinclude:: code/file-read.cmake
   :caption: :download:`file-read.cmake (download)
	     <code/file-read.cmake>`
   :language: cmake

.. command-output:: cmake -P file-read.cmake
   :ellipsis: 5
   :cwd: code
   :shell:

``file(STRINGS ...)``: Read Lines Of File
-----------------------------------------

.. sidebar:: Documentation

   * `file(STRINGS ...)
     <https://cmake.org/cmake/help/latest/command/file.html#strings>`__

* Reads file as list of lines
* Can do filtering based on regular expressions
* ... encoding ...

.. literalinclude:: code/file-read-lines-of-file.cmake
   :caption: :download:`file-read-lines-of-file.cmake (download)
	     <code/file-read-lines-of-file.cmake>`
   :language: cmake

.. command-output:: cmake -P file-read-lines-of-file.cmake
   :ellipsis: 5
   :cwd: code
   :shell:

``file(<HASH> ...)``: Checksumming
----------------------------------

.. sidebar:: Documentation

   * `file(<HASH> ...)
     <https://cmake.org/cmake/help/latest/command/string.html#hash>`__

.. literalinclude:: code/file-hash.cmake
   :caption: :download:`file-hash.cmake (download)
	     <code/file-hash.cmake>`
   :language: cmake

.. command-output:: cmake -P file-hash.cmake
   :cwd: code
   :shell:

``file(WRITE ...), file(APPEND ...)``: Writing Files
----------------------------------------------------

.. sidebar:: Documentation

   * `file(WRITE ...)
     <https://cmake.org/cmake/help/latest/command/file.html#writing>`__

.. literalinclude:: code/file-append.cmake
   :caption: :download:`file-append.cmake (download)
	     <code/file-append.cmake>`
   :language: cmake

.. command-output:: cmake -P file-append.cmake
   :cwd: code
   :shell:

``file(GLOB ...)``: Read Directory Contents
-------------------------------------------

.. sidebar:: Documentation

   * `file(GLOB ...)
     <https://cmake.org/cmake/help/latest/command/file.html#filesystem>`__

For example, read all ``*.cpp`` files from current working directory

.. literalinclude:: code/file-glob-cpp.cmake
   :caption: :download:`file-glob-cpp.cmake (download)
	     <code/file-glob-cpp.cmake>`
   :language: cmake

.. command-output:: cmake -P file-glob-cpp.cmake
   :cwd: code
   :shell:

``cmake_path(GET ...)``: Decompose Paths
----------------------------------------

.. sidebar:: Documentation

   * `cmake_path(GET ...)
     <https://cmake.org/cmake/help/latest/command/cmake_path.html#decomposition>`__

* ``ROOT_NAME``, ``ROOT_DIRECTORY``, ``ROOT_PATH``, ``FILENAME``,
  ``EXTENSION``, ``STEM``, ``RELATIVE_PART``, ``PARENT_PATH``
* For example, how to get the filename component (``FILENAME``) of an
  absolute path

.. literalinclude:: code/cmake-path-get-filename.cmake
   :caption: :download:`cmake-path-get-filename.cmake (download)
	     <code/cmake-path-get-filename.cmake>`
   :language: cmake

.. command-output:: cmake -P cmake-path-get-filename.cmake
   :cwd: code
   :shell:

``cmake_path(APPEND ...)``: Compose Paths
-----------------------------------------

.. sidebar:: Documentation

   * `cmake_path(APPEND ...)
     <https://cmake.org/cmake/help/latest/command/cmake_path.html#modification>`__

For example, add one path component to existing path

.. literalinclude:: code/cmake-path-append.cmake
   :caption: :download:`cmake-path-append.cmake (download)
	     <code/cmake-path-append.cmake>`
   :language: cmake

.. command-output:: cmake -P cmake-path-append.cmake
   :cwd: code
   :shell:

