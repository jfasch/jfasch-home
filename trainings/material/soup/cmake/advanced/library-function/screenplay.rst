.. ot-topic:: cmake.advanced.library_function_screenplay
   :dependencies: cmake.advanced.targets_properties_pub_priv_inc_screenplay
.. include:: <mmlalias.txt>


Screenplay: Function Wrapping ``add_library()``
===============================================

.. contents::
   :local:

.. sidebar:: Trainer's note

   * Source code in ``.../cmake/project/function-add-library/``

* Start in base/CMakeLists.txt

  .. code-block:: cmake

     function(my_add_library)
       cmake_parse_arguments(MY_ADD_LIBRARY "SHARED;STATIC" "NAME" "PRIVATE_HEADERS;PUBLIC_HEADERS;SOURCES" ${ARGN})
     
       message("MY_ADD_LIBRARY_SHARED: >${MY_ADD_LIBRARY_SHARED}<")
       message("MY_ADD_LIBRARY_STATIC: >${MY_ADD_LIBRARY_STATIC}<")
       message("MY_ADD_LIBRARY_NAME: >${MY_ADD_LIBRARY_NAME}<")
       message("MY_ADD_LIBRARY_PRIVATE_HEADERS: >${MY_ADD_LIBRARY_PRIVATE_HEADERS}<")
       message("MY_ADD_LIBRARY_PUBLIC_HEADERS: >${MY_ADD_LIBRARY_PUBLIC_HEADERS}<")
       message("MY_ADD_LIBRARY_SOURCES: >${MY_ADD_LIBRARY_SOURCES}<")
     endfunction()
  
  ... and a call reflaecting the situation

* Hmm ... how about error checking? ``SHARED`` *and* ``STATIC``
  passed?
* |longrightarrow| externalize into ``my_add_library.cmake``, and
  develop there (in script mode)
* |longrightarrow| no ``add_library()`` etc. possible in script mode
* |longrightarrow| ``include()``
