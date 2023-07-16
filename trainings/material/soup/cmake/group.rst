.. ot-group:: cmake

.. include:: <mmlalias.txt>


CMake: An Introduction
======================

.. image:: logo.jpg
   :alt: CMake logo
   :align: right
   :scale: 50%

.. sidebar::

   .. list-table::
      :align: left

      * * **Duration**
	* * One day
      * * **Course Language**
	* * Course material language is English
	  * Trainer language is English or German
      * * **Booking**
	* training@faschingbauer.co.at

.. toctree::
   :maxdepth: 1

   basics
   libraries
   shared-libraries
   installation
   structure
   cxx-and-rants
   configure_file
   optional-code-problem
   optional-code-approach-1
   optional-code-approach-2
   targets-properties
   external-dependencies

.. contents::
   :local:

To Do
-----

* Using installed project |longrightarrow| install headers

  https://stackoverflow.com/questions/10487256/cmake-how-to-properly-copy-static-librarys-header-file-into-usr-include

* Variables

  * ``CMAKE_SOURCE_DIR``
  * ``CMAKE_CURRENT_SOURCE_DIR``
  * ``CMAKE_BINARY_DIR``
  * ``CMAKE_CURRENT_BINARY_DIR``

Dependencies
------------

.. ot-graph::
   :entries: cmake
