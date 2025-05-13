.. include:: <mmlalias.txt>


Shared Libraries (Preview)
==========================

.. contents::
   :local:

.. sidebar::

   **Source**

   .. code-block:: console

      06-shared-libraries-preview/
      ├── CMakeLists.txt
      ├── hello.c
      ├── hello-first.c
      ├── hello.h
      ├── hello-name.c
      ├── hello-name.h
      └── hello-second.c

   * :download:`06-shared-libraries-preview/CMakeLists.txt`
   * :download:`06-shared-libraries-preview/hello-first.c`
   * :download:`06-shared-libraries-preview/hello-second.c`
   * :download:`06-shared-libraries-preview/hello.h`
   * :download:`06-shared-libraries-preview/hello.c`
   * :download:`06-shared-libraries-preview/hello-name.c`
   * :download:`06-shared-libraries-preview/hello-name.h`

"Normal" Libraries
------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cmake/advanced/targets-properties/topic`
   * :doc:`/trainings/material/soup/linux/toolchain/shared-libraries/topic`

   **Documentation**

   * `ADD_LIBRARY()
     <https://cmake.org/cmake/help/latest/command/add_library.html>`__

* ``STATIC``

  * Simple bag of objects
  * Linker copies objects out

* ``SHARED``

  * Loaded at runtime
  * |longrightarrow| Loader (usually ``/lib64/ld-linux-x86-64.so.2``)
  * More:
    :doc:`/trainings/material/soup/linux/toolchain/shared-libraries/topic`

* ``MODULE``

  * No ``SONAME``, no version symlinks

Building Shared Libraries
-------------------------

* In the ``CMakeLists.txt``, using ``SHARED`` tag

  .. code-block:: console

     ADD_LIBRARY(hello SHARED hello.c hello-name.c)

* From the commandline, setting ``BUILD_SHARED_LIBS`` to ``ON``

  .. code-block:: console

     $ cmake -DBUILD_SHARED_LIBS=ON ...

More About *Loading*
--------------------

* Program interpreter |longrightarrow| hash bang in scripts
* ``/etc/ld.so.conf``
* Library ``SONAME`` and ``NEEDED`` tags |longrightarrow| look in
  ``/usr/lib64/``

  .. code-block:: console

     $ rpm -qf /usr/lib64/libboost_regex.so.1.76.0
     $ sudo dnf install boost-devel

* A-ha: development versions
  
  .. code-block:: console
  
     $ ls -l /usr/lib64/libboost_regex*
     lrwxrwxrwx. 1 root root     24 Jul 14  2022 /usr/lib64/libboost_regex.so -> libboost_regex.so.1.76.0
     -rwxr-xr-x. 1 root root 289264 Jul 14  2022 /usr/lib64/libboost_regex.so.1.76.0

* Temporarily add 

  .. code-block:: console

     SET_PROPERTY(TARGET hello PROPERTY VERSION "1")``

  and modify to 

  .. code-block:: console

     PROJECT(Demo VERSION "1.0.0")
     SET_PROPERTY(TARGET hello PROPERTY VERSION ${PROJECT_VERSION})

* Discuss ABI versions |longrightarrow| **rarely project versions can
  be used as ABI versions**
* |longrightarrow| can of worms: **installation/deployment**

