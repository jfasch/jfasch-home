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

Links
-----

Virtual Environments (Links)
============================

* Python Tutorial: VENV (Mac & Linux) - How to Use Virtual Environments with the Built-In venv Module (Corey Schafer)

  .. raw:: html
  
     <iframe 
         width="560" height="315" src="https://www.youtube.com/embed/Kg1Yvry_Ydk" 
         title="YouTube video player" 
         frameborder="0" 
         allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
         allowfullscreen>
     </iframe>

* `Using Python environments in VS Code
  <https://code.visualstudio.com/docs/python/environments>`__
