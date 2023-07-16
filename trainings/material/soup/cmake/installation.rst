.. ot-topic:: cmake.installation
   :dependencies: cmake.libraries, cmake.shared_libraries_preview
.. include:: <mmlalias.txt>


Installation ("Deployment")
===========================

.. contents::
   :local:

.. sidebar::

   **Source**

   .. code-block:: console

      07-install-basic/
      ├── CMakeLists.txt
      ├── hello.c
      ├── hello-first.c
      ├── hello.h
      ├── hello-name.c
      ├── hello-name.h
      └── hello-second.c

   * :download:`07-install-basic/CMakeLists.txt`
   * :download:`07-install-basic/hello.h`
   * :download:`07-install-basic/hello.c`
   * :download:`07-install-basic/hello-name.c`
   * :download:`07-install-basic/hello-name.h`
   * :download:`07-install-basic/hello-first.c`
   * :download:`07-install-basic/hello-second.c`

"Prefix": Where Everything Comes Together
-----------------------------------------

* Multiple projects usually are *installed* at one *prefix*
  |longrightarrow| ``/usr``
* Subdirectories

  * ``bin/``: executables
  * ``lib/`` (or ``lib64``): libraries
  * ``include/``: header files (usually comes with ``-dev`` or
    ``-devel`` distro packages, as do static libraries)
  * ``share/``: data files
  * (more)

* Build parameter: ``CMAKE_INSTALL_PREFIX`` (default: ``/usr/local``)

.. code-block:: console

   $ cmake -DCMAKE_INSTALL_PREFIX=/tmp/install /home/jfasch/work/jfasch-home/trainings/material/soup/cmake/07-install-basic

Installing Targets
------------------

.. sidebar::

   **Documentation**

   * `INSTALL()
     <https://cmake.org/cmake/help/latest/command/install.html>`__

.. code-block:: console

   INSTALL(TARGETS hello DESTINATION lib)                 # <--- lands in <prefix>/lib/
   INSTALL(TARGETS hello-first DESTINATION bin)           # <--- lands in <prefix>/bin/
   INSTALL(TARGETS hello-second DESTINATION bin)          # <--- lands in <prefix>/bin/

Doing The Installation (``make install``)
-----------------------------------------

.. code-block:: console

   $ cmake -DCMAKE_INSTALL_PREFIX=/tmp/install /home/jfasch/work/jfasch-home/trainings/material/soup/cmake/07-install-basic
   $ make
   $ make install
   ...
   Install the project...
   -- Install configuration: ""
   -- Installing: /tmp/install/lib/libhello.a
   -- Installing: /tmp/install/bin/hello-first
   -- Installing: /tmp/install/bin/hello-second

.. code-block:: console

   $ tree /tmp/install/
   /tmp/install/
   ├── bin
   │   ├── hello-first
   │   └── hello-second
   └── lib
       └── libhello.a

And Shared Libraries?
---------------------

.. sidebar::

   **Teachers note:** 

   Comment out the following line from ``CMakeLists.txt``

   .. code-block:: console

      SET_PROPERTY(TARGET hello PROPERTY VERSION "1")

.. code-block:: console

   $ cmake -DBUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_PREFIX=/tmp/install /home/jfasch/work/jfasch-home/trainings/material/soup/cmake/07-install-basic
   $ make
   $ make install
   ...
   -- Set runtime path of "/tmp/install/bin/hello-first" to ""    # <--- RUNPATH?
   -- Set runtime path of "/tmp/install/bin/hello-second" to ""   # <--- RUNPATH?
   ...

.. code-block:: console

   $ tree /tmp/install/
   /tmp/install/
   ├── bin
   │   ├── hello-first
   │   └── hello-second
   └── lib
       └── libhello.so

Shared Libraries: Installed Vs. Local (``RUNPATH``)
---------------------------------------------------

.. sidebar::

   **Documentation**

   * `man -s 1 readelf
     <https://man7.org/linux/man-pages/man1/readelf.1.html>`__
   * `man -s 1 ldd
     <https://man7.org/linux/man-pages/man1/ldd.1.html>`__
   
   **See also** 

   * :doc:`libraries`

* ``NEEDED``

  .. code-block:: console
  
     $ readelf  --dynamic ./hello-first 
      ...
      0x0000000000000001 (NEEDED)             Shared library: [libhello.so]
      ...

  |longrightarrow| Executable ``hello-first`` *depends on* ``hello``
  (``CMakeLists.txt``: ``TARGET_LINK_LIBRARIES()``)

* Question: where is that external dependency found when program is
  started?
* Answer 1: local (uninstalled) case

  .. code-block:: console
  
     $ readelf  --dynamic ./hello-first 
      ...
      0x000000000000001d (RUNPATH)            Library runpath: [/home/jfasch/tmp/cmake-demo:]
      ...

  .. code-block:: console
     :caption: Which libraries would be loaded if I ran
               ``./hello-first``?
  
     $ ldd ./hello-first 
             ...
             libhello.so => /home/jfasch/tmp/cmake-demo/libhello.so (0x00007f773aefe000)
             ...

  |longrightarrow| uninstalled executable runs from the build
  directory

  .. code-block:: console

     $ ./hello-first 
     Hello World

* Answer 2: installed case

  .. code-block:: console

     $ readelf  --dynamic /tmp/install/bin/hello-first 
     ... no RUNPATH ...

  .. code-block:: console

     $ ldd /tmp/install/bin/hello-first 
             ...
             libhello.so.1 => not found
             ...

  |longrightarrow| installed executable does *not* run

  .. code-block:: console

     $ /tmp/install/bin/hello-first 
     /tmp/install/bin/hello-first: error while loading shared libraries: libhello.so: cannot open shared object file: No such file or directory

  Fix: set loader path, e.g.

  .. code-block:: console

     $ LD_LIBRARY_PATH=/tmp/install/lib /tmp/install/bin/hello-first 
     Hello World

Shared Libraries: ABI Versions
------------------------------

.. sidebar::

   **Documentation**

   * `man -s 5 elf
     <https://man7.org/linux/man-pages/man5/elf.5.html>`__
   * `man -s 8 ldconfig
     <https://man7.org/linux/man-pages/man8/ldconfig.8.html>`__

* Set ABI version (``SONAME``), and ``make install``

  .. code-block:: console
  
     SET_PROPERTY(TARGET hello PROPERTY VERSION "1")

* ``SONAME`` ELF attribute

  .. code-block:: console

     $ readelf  --dynamic /tmp/install/bin/hello-first 
     0x0000000000000001 (NEEDED)             Shared library: [libhello.so.1]

* ``SONAME`` link (done by ``ldconfig`` on a live system, after
  package installation)

  .. code-block:: console
  
     $ tree /tmp/install/
     /tmp/install/
     ├── bin
     │   ├── hello-first
     │   └── hello-second
     └── lib
         ├── libhello.so -> libhello.so.1
	 └── libhello.so.1
