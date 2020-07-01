.. include:: <mmlalias.txt>


Netidee *Projekt Call 2020*: Video Screenplay
=============================================

.. toctree::
   :hidden:

   demo/agenda
   demo/python

Draft 2
-------

.. contents::
   :local:

Open Source Training Material
.............................

**Why?**

* Nobody does it
* Trainers (even those in Open Source tech) *don't work together*
* ... although, historically, OSS has gained incredible momentum
* Expecting the same in training context

**How?** (This project)

* Define and implement common basis
* Provide in-depth documentation
* Provide representative examples

Walk-Through
............

* Python training (:download:`PDF
  </trainings/material/pdf/300-python.pdf>`)
* Show :doc:`graph: Python training <demo/python>`

  * Pinpoint: "Iteration and Generators" *depends on* "Functions"

* Show :doc:`"Iteration and Generators"
  </trainings/material/soup/python_1010_generators_yield/topic>`
* Show :doc:`agenda <demo/agenda>`, and *how easy it is*

Requirements
............

* Web-native
* Easy markup
* No binary format |Longrightarrow| no Libreoffice, no PowerPoint, no Keynote
* No prorietary format |Longrightarrow| no PowerPoint, no Keynote
* No closed source |Longrightarrow| no nothing
* Small topics of manageable size (ideally 15-30min, the average size
  of a screencast/tutorial)
* Dependencies: "Iteration and Generators" *depends on* "Functions"
* Various other metadata easily introduced

Open Ends
.........

* Slide/Presentation

  * `S5
    <https://docutils.sourceforge.io/docs/user/slide-shows.html>`__
  * `reveal.js <https://revealjs.com/>`__
  * `Webslides <https://webslides.tv/>`__

* Use dependency metadata more

  * Compute textual agenda
  * Fisheye view on one topic
  * ...

* Structure

  * Groups and subgroups
  * Relations between multiple training material websites

* Visual enhancements (many)

Communication
.............

* Github Repositories
* Announce and promote (Facebook/LinkedIn)

Draft 1
-------

Why Me?
.......

* Good trainings are rare
* Independent trainers usually don't collaborate (which is why good
  trainings are rare)

Problem
.......

*Training material shows its age*

* Monolithic 

  * No two trainings have the same agenda
  * Custom training material possible but more work than I'd wish
  * Same with after-training material ("What have we learned?")
  * Consequence: bad work, bad memorization, no matter how the
    training went

* Latex (Beamer) is not a contemporary format

  * Immensely verbose
  * Incomprehensible
  * Build takes ages

* No fun

Problem: Demo
.............

* Python training (:download:`PDF </trainings/material/pdf/300-python.pdf>`)
* Skipped topics

  * "Strings and Encoding": nobody wants that

* Wanted topics and dependencies

  * "Iteration and Generators" *depends on* "Functions"
  * ... and possibly others

* Hypothetical agenda, say ...

  * "Iteration and Generators"
  * "OO Programming"
  * "Exception Handling"
  * "Modules"

Solution: Requirements
......................

* Easy markup
* No binary format |Longrightarrow| no Libreoffice, no PowerPoint, no Keynote
* No prorietary format |Longrightarrow| no PowerPoint, no Keynote
* No closed source |Longrightarrow| no nothing
* Small topics of manageable size (ideally 15-30min, the average size
  of a screencast/tutorial)
* Dependencies: "Iteration and Generators" *depends on* "Functions"
* Various other metadata easily introduced
* Web-native

Solution: Demo
..............

* Show :doc:`graph: Python training <demo/python>`

  * Pinpoint: "Iteration and Generators" *depends on* "Functions"

* Show :doc:`"Iteration and Generators"
  </trainings/material/soup/python_1010_generators_yield/topic>`

* Show :doc:`agenda <demo/agenda>`, and *how easy it is*

Solution: Technicalities
........................

* `Sphinx <https://www.sphinx-doc.org/>`__: an extensible
  *documentation generator*

  * Initially conceived to maintain `Python documentation
    <https://docs.python.org/3/>`__
  * `Linux Kernel documentation
    <https://www.kernel.org/doc/html/v4.10/doc-guide/sphinx.html>`__
  * `Blender <https://www.blender.org/get-involved/documentation/>`__
  * `Many others
    <https://www.sphinx-doc.org/en/master/examples.html>`__

* `Set of Sphinx extensions
  <https://github.com/jfasch/jfasch-home/tree/master/jf>`__

Missing Pieces
..............

* Slideshow generation; use one of

  * `S5 <https://docutils.sourceforge.io/docs/user/slide-shows.html>`__
  * `reveal.js <https://revealjs.com/>`__
  * `Webslides <https://webslides.tv/>`__

* Use graph algorithms to ...

  * Compute textual agenda
  * Fisheye view on one topic

* More structure

  * Grouping (e.g. "Python" *has* "Python Very Basics", "Python
    Advanced", "Standard Library")
  * "See also"
  * Sphinx references by *topic name*

* Visual enhancements

  * Many

* Foster trainer collaboration

  * Decouple training material from homepage |longrightarrow| multiple
    distinct websites, one per training
  * Use `Intersphinx
    <https://www.sphinx-doc.org/en/master/usage/extensions/intersphinx.html>`__
    to draw dependency arrows *between* sites
  * Documentation
