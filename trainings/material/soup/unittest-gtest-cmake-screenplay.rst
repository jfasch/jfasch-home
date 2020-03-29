.. jf-screenplay:: unittest-gtest-cmake

Screenplay: Unittest: GTest and CMake
=====================================

.. sidebar:: Contents

   .. contents::
      :local:

   **Code**: :doc:`unittest-gtest-basics-code/index`

**Discussion**

* How to use external code like googletest?

  * *Copy* it into self's repo

    * Will remain a copy, nobody will update, bitrot
    * Git has `sub-repositories
      <https://git-scm.com/book/en/v2/Git-Tools-Submodules>`__. Still
      *you* have to build it.

  * Use distro's package manager

    * This is what we will do here
    * Installed it already in :doc:`unittest-gtest-basics-screenplay`

Installed: to be found in Standard Paths
----------------------------------------

What happens when I say one of these for example?

* ``#include <gtest/gtest.h>``
* ``-lgtest``

.. code-block:: console

   $ dnf repoquery -l gtest-devel
   ...
   /usr/include/gtest/gtest.h
   ...
   /usr/lib64/libgtest.so
   ...

.. code-block:: console

   $ dpkg --listfiles libgtest-dev
   ... likewise ...

**Discussion**

Standard paths

* Include path: ``/usr/include/``
* Library path: ``/usr/lib64/``

CMake: "Find Modules"
---------------------

* CMake is a "declarative language" (nah, so to say)
* User declares "I insist in gtest being there"
* ``FIND_PACKAGE(GTest REQUIRED)``

  * Usually in toplevel ``CMakeLists.txt``
  * ... but not necessarily so

.. literalinclude:: ../../../CMakeLists.txt
   :caption: :download:`../../../CMakeLists.txt`
   
**Discussion**

* Hm. CMake find modules. Hm.
* Google is your friend
* Better yet: use the source, Luke

Show ``GTest`` find module; point to documentation,

.. code-block:: console

   less /usr/share/cmake/Modules/FindGTest.cmake
   ...

Consequentially, usage:

.. code-block::

   ADD_EXECUTABLE(assert assert.cc)
   TARGET_LINK_LIBRARIES(assert GTest::GTest)

Executing Tests As Part of Build
--------------------------------

.. code-block:: console

   ADD_TEST(assert assert)

* 1st arg: test name (cmake reports failures as such)
* 2nd arg: command (from ``ADD_EXECUTABLE()``)

Tests That Are Expected to Fail
-------------------------------

.. code-block:: console

   SET_TESTS_PROPERTIES(
     assert ... (maybe more)
     PROPERTIES WILL_FAIL true)
