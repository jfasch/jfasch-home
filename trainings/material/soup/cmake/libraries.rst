.. ot-topic:: cmake.libraries
   :dependencies: cmake.basics
.. include:: <mmlalias.txt>


Libraries, And *Dependencies*
=============================

.. contents::
   :local:

Libraries And Executables
-------------------------

.. sidebar::

   **Source**

   .. code-block:: console

      05-static-libraries/
      ├── CMakeLists.txt
      ├── hello.c
      ├── hello-first.c
      ├── hello.h
      ├── hello-name.c
      ├── hello-name.h
      └── hello-second.c

   * :download:`05-static-libraries/CMakeLists.txt`
   * :download:`05-static-libraries/hello.h`
   * :download:`05-static-libraries/hello.c`
   * :download:`05-static-libraries/hello-name.c`
   * :download:`05-static-libraries/hello-name.h`
   * :download:`05-static-libraries/hello-first.c`
   * :download:`05-static-libraries/hello-second.c`

* Raw toolchain in action:
  :doc:`/trainings/material/soup/linux/toolchain/static-library/topic`
* Defining a *library*

  .. code-block:: console
     :caption: :download:`05-static-libraries/CMakeLists.txt`

     ADD_LIBRARY(hello                             # <--- target "hello"
       hello.h hello.c 
       hello-name.h hello-name.c)

  .. note::

     Header files are not compiled, but adding them is convenient for
     IDE usage.

* Executables only contain *main* code (all code that *depends* on is
  in the library)

  .. code-block:: console
     :caption: :download:`05-static-libraries/CMakeLists.txt`


     ADD_EXECUTABLE(hello-first hello-first.c)     # <--- target "hello-first"
     ADD_EXECUTABLE(hello-second hello-second.c hello.c hello-name.c)

.. code-block:: console

   $ cmake  ~/work/jfasch-home/trainings/material/soup/cmake/05-static-libraries/
   ...
   $ make
   [ 57%] Linking C executable hello-first
   /usr/bin/ld: CMakeFiles/hello-first.dir/hello-first.c.o: in function `main':
   hello-first.c:(.text+0x10): undefined reference to `hello'
   /usr/bin/ld: hello-first.c:(.text+0x29): undefined reference to `hello_name'
   collect2: error: ld returned 1 exit status

|longrightarrow| Dependencies!

Targets And Dependencies
------------------------

* Executables *depend* on libraries
* |longrightarrow| *dependencies*
* ``hello-first`` depends on ``hello``
* ``hello-second`` depends on ``hello``

.. code-block:: console
   :caption: :download:`05-static-libraries/CMakeLists.txt`

   TARGET_LINK_LIBRARIES(hello-first hello)      # <--- "hello-first" depends on "hello"
   TARGET_LINK_LIBRARIES(hello-second hello)     # <--- "hello-second" depends on "hello"

* Executables may depend on libraries
* Libraries may depend on libraries
* (Nothing ever depends on an executable)
* |longrightarrow| Directed Acyclic Graph (DAG)

Visualizing Dependencies
------------------------

* *Project sanity*: knowing your dependencies
* |longrightarrow| `Graphviz <https://graphviz.org/>`__ package

.. code-block:: console
   :caption: Generating ``dot`` files

   $ pwd
   /tmp/build
   $ cmake --graphviz=Demo.dot ~/work/jfasch-home/trainings/material/soup/cmake/05-static-libraries/
   $ ls -l *.dot*
   -rw-r--r--. 1 jfasch jfasch 1260 Jul 13 19:31 Demo.dot
   -rw-r--r--. 1 jfasch jfasch  336 Jul 13 19:31 Demo.dot.hello.dependers
   -rw-r--r--. 1 jfasch jfasch  222 Jul 13 19:31 Demo.dot.hello-first
   -rw-r--r--. 1 jfasch jfasch  225 Jul 13 19:31 Demo.dot.hello-second

.. code-block:: console
   :caption: Convert into viewable image

   $ dot -Tpng Demo.dot > Demo.png

.. image:: 05-static-libraries/Demo.png

