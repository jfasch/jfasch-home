Installing ``googletest`` By Hand
=================================

This is for users of Ubuntu 16.04 LTS which does not come with a
proper package for this. There is ``gtest-dev`` (or so), but it
appears to only contain headers - libraries are missing.

.. contents:: Contents
   :local:

Clone ``googletest`` Repo
-------------------------

I use to store Git clones in ``~/work`` (you might like it different),

.. code-block:: console

   $ cd ~/work
   $ git clone https://github.com/google/googletest.git

Create Build Directory
----------------------

I put mines in ``~/build``; again, please deviate as you want. Create
directory, and ``cd`` into it.

.. code-block:: console

   $ mkdir -p ~/build/googletest
   $ cd ~/build/googletest

CMake, Build and Install
------------------------

``googletest`` uses CMake to build itself, and this is what the
remainder is: explanations of how to do things in CMake.

We pass two parameters down into the CMake build,

* ``-std=c++11``. ``googletest`` uses C++-11 features. Ubuntu 16.04
  LTS come with GCC version 5.<something> which does not build C++ as
  C++-11 by default. You can to force it to, though, by giving it that
  flag. The CMake way to pass compiler flags through is
  ``-DCMAKE_CXX_FLAGS=-std=c++11``.
* We do not want to become ``root``. I only want to make
  ``googletest`` available to other packages which are built by *me
  myself*. So we do not use standard paths (like ``/usr/local``) to
  install ``googletest`` to, but rather
  ``$HOME/install/googletest``. (Again, please deviate.)

Long story short,

.. code-block:: console

   $ pwd
   /home/jfasch/build/googletest
   $ cmake -DCMAKE_CXX_FLAGS=-std=c++11 -DCMAKE_INSTALL_PREFIX=$HOME/install/googletest ~/work/googletest
   $ make
   $ make install

``googletest`` is now available under ``/home/jfasch/install/googletest``,

.. code-block:: console

   $ ls ~/install/googletest/include/gtest/gtest.h
   /home/jfasch/install/googletest/include/gtest/gtest.h
   $ ls ~/install/googletest/lib64/libgtest.a
   /home/jfasch/install/googletest/lib64/libgtest.a

In other words, ``$HOME/install/googletest`` is the *root* of the
``googletest`` install. To build other packages to use that install,
we have to pass a parameter down into *their* build. (Did somebody
claim life was simlpe?)

Build Packages to Use Our Private ``googletest`` Install
--------------------------------------------------------

One popular such package (to me at least) that wants ``googletest`` is
my own training site, ``https://github.com/jfasch/jfasch-home``. I'll
take this as a concrete example; others should work just as
well. *Provided that they use CMake*, of course - this is what I'm
showing here.

``jfasch-home`` uses a CMake "find module" to determine information
about the ``googletest`` install, like follows.

Clone that repo,

.. code-block:: console

   $ cd ~/work
   $ git clone https://github.com/jfasch/jfasch-home

In the toplevel ``CMakeLists.txt`` file, it has,

.. code-block:: cmake

   FIND_PACKAGE(GTest REQUIRED)

Down into the tree, in a directory where tests are done, it has,

.. code-block:: cmake

   ADD_EXECUTABLE(simple simple.cc)
   TARGET_LINK_LIBRARIES(simple GTest::GTest)
   ADD_TEST(simple simple)

(``simple`` is a test program). The emphasis is on *how to use gtest*,
and the key is ``GTest::GTest``.

So how to pass out private ``googletest`` install in?

The ultimate source of information is *the code, Luke*. Information
about CMake "find modules" is hard to come by on the internet; I use
to look in the file that *implements* the "find module". Remember, in
thetoplevel ``CMakeLists.txt`` we have ``FIND_PACKAGE(GTest
REQUIRED)``; from this we know that there must be a file
``/usr/share/cmake/Modules/FindGTest.cmake``. It has its own
documentation inside it; read, and know that it accept a CMake
variable ``GTEST_ROOT`` which does what we want.

.. code-block:: console

   $ mkdir ~/build/jfasch-home
   $ cmake -DGTEST_ROOT=$HOME/install/googletest ~/work/jfasch-home

Maybe, paranoidly, verbosely verify that ``$HOME/install/googletest``
is used,

.. code-block:: console

   $ make VERBOSE=1
   ... watch out for build output that mention our googletest install ...

