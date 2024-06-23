.. ot-topic:: cmake.advanced.external_dependencies_sqlite3_optional_configured_file
   :dependencies: cmake.advanced.external_dependencies_sqlite3
.. include:: <mmlalias.txt>


Screenplay: Making ``SQLite3`` Optional (``configure_file()``)
==============================================================

.. contents::
   :local:

Alternative: ``configure_file()`` Instead Of ``target_compile_definitions()``
-----------------------------------------------------------------------------

.. sidebar:: See also

   * :doc:`screenplay-sqlite3-optional-graph`

.. sidebar:: Documentation

   * `configure_file()
     <https://cmake.org/cmake/help/latest/command/configure_file.html>`

* In :doc:`screenplay-sqlite3-optional-graph`, we used
  ``target_compile_definitions()`` to *propagate*
  ``HAVE_SINK_SQLITE3`` from ``toolcase/base/`` right into
  ``firmware/data-logger.cpp``
* If done much, this can clutter compiler commandlines with macro
  definitions
* What if every user like ``firmware/data-logger.cpp`` pulls in that
  information via a dedicated - *generated* - header file?
* |longrightarrow| `configure_file()
  <https://cmake.org/cmake/help/latest/command/configure_file.html>`
* Beware: this is not less a massacre!

Make It So
----------

* Remove propagated commandline macro from ``toolcase/data-logger/``

  .. code-block:: cmake
  
     # if (SQLite3_FOUND)
     #   target_compile_definitions(data-logger INTERFACE HAVE_SINK_SQLITE3=1)
     # endif()

* ``firmware/data-logger.cpp`` still builds - it just does not see
  ``HAVE_SINK_SQLITE3`` defined
* ``firmware/data-logger.cpp`` to act differently
* |longrightarrow| pull in a header file that contains
  ``HAVE_SINK_SQLITE3`` (and possibly related) definitions

.. code-block:: c++

   #include <project-config.h>     // <--- defines HAVE_SINK_SQLITE3
   #if HAVE_SINK_SQLITE3==1
   #  include <sink-sqlite3.h>
   #else
   #  include <sink-terminal.h>
   #endif

.. code-block:: console

   .../firmware/data-logger.cpp:4:10: fatal error: project-config.h: No such file or directory
       4 | #include <project-config.h>     // <--- defines HAVE_SINK_SQLITE3
         |          ^~~~~~~~~~~~~~
