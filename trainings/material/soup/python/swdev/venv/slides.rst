.. include:: <mmlalias.txt>

Virtual Environments (Slideshow)
================================

Problems Solved
---------------

* Python installation is global
* Worse: ``pip`` installed packages are global
* Packages available in different versions
* Different projects might require a package in different versions
  |longrightarrow| *conflicts*!

Solution
--------

* Creates "sandboxed" Python environment
* Integrates nicely with ``pip``
* Integrates nicely with version control

  * Nobody wants to version control an entire environment

* "Freeze" |longrightarrow| Manifest file

  * Usually called ``requirements.txt``
  * Version controlled inside (together with) the project
  * Updated as requirements change
