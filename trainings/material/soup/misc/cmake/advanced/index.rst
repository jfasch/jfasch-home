.. include:: <mmlalias.txt>


CMake: Advanced Topics
======================

.. image:: ../logo.jpg
   :alt: CMake logo
   :align: right
   :scale: 50%

.. sidebar::

   .. list-table::
      :align: left

      * * **Duration**
 	* * Two days
      * * **Course Language**
	* * Course material language is English
	  * Trainer language is English or German
      * * **Booking**
	* training@faschingbauer.co.at
      * * **See also**
	* :doc:`../intro/index`

Topics
------

.. toctree::
   :maxdepth: 1

   targets-properties/topic
   targets-properties/screenplay
   language/index
   library-function/screenplay
   external-dependencies/screenplay-sqlite3
   external-dependencies/screenplay-sqlite3-optional-graph
   external-dependencies/screenplay-sqlite3-optional-configured-file
   external-dependencies/screenplay-mosquitto
   code-generators/screenplay
   testing/topic   

.. toctree::
   :hidden:

   targets-properties/global-incdir

Alternative Topics
------------------

.. toctree::
   :maxdepth: 1

   external-dependencies/topic
   configure-file/topic
   conditional-code-problem/topic
   conditional-code-approach-1/topic
   conditional-code-approach-2/topic

Todo jjj |:metal:|
------------------

* Modules

  * googletest how?

    * https://cmake.org/cmake/help/latest/module/GoogleTest.html#command:gtest_discover_tests
      probably not. read docs, "may not work cross"
    * https://cmake.org/cmake/help/latest/module/FindGTest.html
    * optional tests, depending on ``GTest::Main``
    * https://cliutils.gitlab.io/modern-cmake/

  * find modules: pkgconfig? suppose not

* reference https://cmake.org/cmake/help/latest/guide/using-dependencies/index.html#guide:Using%20Dependencies%20Guide
* fetchcontent() and
  https://cmake.org/cmake/help/latest/module/ExternalProject.html#module:ExternalProject

  if you find yourself doing this, you should better use conan or
  yocto or distribution pakage managers

