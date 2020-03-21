Blog
====

Articles
--------

In the Works
............

.. toctree::
   :maxdepth: 1

   github-pages-custom-domains-ssl-bad-certificate

Not Yet in the Works
....................

* Add ``googletest`` to your ``CMake`` project. 

  * Cite `this bullshit
    <https://raymii.org/s/tutorials/Cpp_project_setup_with_cmake_and_unit_tests.html>`__
  * Complain a lot about everyone using Git subrepos, static linking,
    and The Internet as a whole. Subtitle: "Fighting Against Fake
    News". Use Four Letter Words a lot.
  * Well ok, `googletest <https://github.com/google/googletest>`__
    goes out of its way, describes the method, and goes on to `say
    that this is the simplest method, but also the most unprofessional
    <https://github.com/google/googletest/blob/master/googletest/README.md>`__.
  * `GTest "find module"
    <https://cmake.org/cmake/help/latest/module/FindGTest.html>`__. Explain
    roughly what "find modules" are.
  * Why am I not happy with this `populistic bullshit
    <https://cmake.org/cmake/help/v3.10/module/GoogleTest.html>`__?

    * They say "``gtest_discover_tests`` is more robust than ...", and
      in the same sentence they say "it may not work in a
      cross-compiling environment" - implicitly knowing that *it will
      not work*.
    * ``gtest_add_tests`` scans the source code in a rather primitive
      way, leaving the user with all sorts of errors.

* Scheduling: the porting trap (plus link to it in
  :doc:`/blog/2011/01/porting-to-linux-there-s-always-a-better-way`,
  "Processes are Threads")
* Timers in Linux hehe!!
* ``html_sidebars`` not respected in RTD theme. How to fix that?
  Alternative solution, like inheriting a template?
* Document my own sphinx usage

  * really cool: ``make linkcheck``. goes out and sees if anybody's at
    home.
  * sidebar
  * admonitions
  * tables (!), cite examples like training material download matrix
  * Learned a lot from 

    * `Thomas Cokelaer's cheat sheet
      <https://thomas-cokelaer.info/tutorials/sphinx/rest_syntax.html>`__
    * `Documentation on Sphinx Site <https://www.sphinx-doc.org/>`__

* ablog

  * doc roles have to absolute, apparently. couldn't figure out what
    the doc name was, at least.
  * ``conf.py`` pieces (especially that the atom feed is *silently*
    generated when ``blog_baseurl`` is not set).

Revisit Existing Posts
----------------------

* go over posts, and use sidebars and admonition more (looks nicer,
  provides structure (importance))
* pour tags in

  * linux
  * kernel
  * github
  * sphinx
  * python
  * c
  * c++
  * unittest
  * training
  * hardware
  * gpio
  * i2c
  * blah ...
