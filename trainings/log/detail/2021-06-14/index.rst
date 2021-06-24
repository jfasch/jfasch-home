.. include:: <mmlalias.txt>

Programmieren mit C (2021-06-14 - 2021-06-18)
=============================================

.. sidebar:: *Training Information*

   **Start**

   Montag 14.6.2021, 9:00

   **Offizielle Beschreibung**

   `tecTrain
   <https://www.tectrain.at/seminare/seminar-themen/programmierung/c-grundlagen-fuer-programmierer>`__

   **Material**

   * Slides, :download:`C </trainings/material/pdf/050-c.pdf>`
   * Slides, :download:`CMake </trainings/material/pdf/045-cmake.pdf>`
   * Slides, :download:`GNU Make </trainings/material/pdf/040-gnu-make.pdf>`
   * `Github Repository <https://github.com/jfasch/2021-06-14>`__

   **CPA Exam**

   * `Sample Questions
     <https://cppinstitute.org/wp-content/uploads/2016/07/CPA_sample_exam_questions.pdf>`__

.. contents::
   :local:

Preparation: Tools
------------------

* `C/C++ for Visual Studio Code <https://code.visualstudio.com/docs/languages/cpp>`__
* `Get started with CMake Tools on Linux
  <https://code.visualstudio.com/docs/cpp/cmake-linux>`__
* `CMake download <https://cmake.org/download/>`__

Log
---

Day 1
.....

* Introduction (from the :download:`C slides
  </trainings/material/pdf/050-c.pdf>`)

  * Hello World
  * Variables and Arithmetic
  * ``for`` Loops
  * Symbolic Constants
  * Character I/O

* Occasional live hacking

  * `hello.c <https://github.com/jfasch/2021-06-14/blob/main/hello.c>`__
  * `fahr.c <https://github.com/jfasch/2021-06-14/blob/main/fahr.c>`__
  * `fahr-for.c <https://github.com/jfasch/2021-06-14/blob/main/fahr-for.c>`__
  * `wc.c
    <https://github.com/jfasch/2021-06-14/blob/main/wc.c>`__. This is
    going to be morphed into a formal state machine tomorrow.

Day 2
.....

State machine
`````````````

It turns out that the correct solution to exercise on slide 37 of
:download:`the slide deck </trainings/material/pdf/050-c.pdf>` is a
*state machine*. It enables us to correctly cover all corner cases
(e.g. multiple consecutive spaces between two words) ...

  .. image:: state-machine.jpg
     :scale: 20%

* `wc.c <https://github.com/jfasch/2021-06-14/blob/main/wc.c>`__
  became a state machine, implementing the above state chart. Using
  ``if-then-else`` to cover the states.
* Introduced the ``switch`` statement (slightly :-) deviating from the
  regular course flow); changed the state maching to use that instead
  of ``if-then-else``. See `wc-switch.c
  <https://github.com/jfasch/2021-06-14/blob/main/wc-switch.c>`__

Regular Course Topics
`````````````````````

* Introduced pre and post increment operators (again severely
  deviating). See `pre-post-increment.c
  <https://github.com/jfasch/2021-06-14/blob/main/pre-post-increment.c>`__.
* Ah, arrays: leading to the "histogram" exercise (slide 41 from the
  :download:`slides </trainings/material/pdf/050-c.pdf>`). Solution see
  `here on Github <https://github.com/jfasch/2021-06-14/blob/main/histogram.c>`__
* Functions. Slides 44ff. from the :download:`slides
  </trainings/material/pdf/050-c.pdf>` (the ``power()`` function from
  the K&R book) as a live hacking gig. `See here on Github
  <https://github.com/jfasch/2021-06-14/blob/main/power-function.c>`__.
* Quick :download:`CMake </trainings/material/pdf/045-cmake.pdf>`
  intro, as a preparation for the upcoming group project. Confusing
  people.

Day 3
.....

* *Git*. See `here
  <https://code.visualstudio.com/docs/editor/versioncontrol>`__ for
  instructions about how to use Git with VS Code. It turns out that

  * `Git Extension Pack
    <https://marketplace.visualstudio.com/items?itemName=donjayamanne.git-extension-pack>`__
    guides users through workflows pretty well. Staging, commits,
    merges.
  * Except that we appear to have problems with Github authentication,
    which is why we use `Github Desktop
    <https://desktop.github.com/>`__ for remote stuff like clone,
    push, pull.

* *CMake*. `Doze installation <https://cmake.org/install>`__; use the
  MSI (the installer package).
* Fast run-through: slides 64-75
* Stop at enums/76: morph wc.c state machine into a perfect enum
  candidate. This is the time to ...

  * Show how to use ``enum`` in the state machine from above.
  * Enable ``-Wswitch-enum`` (nowadays included in ``-Wall``,
    apparently) `CMakeLists.txt
    <https://github.com/jfasch/2021-06-14/blob/main/CMakeLists.txt>`__
  * Show how ``default:``-less ``switch`` statements, ``enum``s, and
    ``-Wswitch-enum`` can work together and help me maintain code
    better.

  Program see `here
  <https://github.com/jfasch/2021-06-14/blob/main/live-hacking/wc-switch-enum.c>`__.

* "Variable Definitions" section. Slides 77ff. Emphasize on local
  variables (this is what we saw so far) more. Lifetime,
  initialization, etc.

* Almost skip 81-88. Operators, boring.
* Hard stop at "Type Conversions", slides 89ff. Make people run away
  screaming (intentionally).

Group Project Kick-Off :-)
``````````````````````````

Kick off "group project". Git, CMake, and team development, with
rather artificial use cases. But anyway, these are use case. See `here
<https://github.com/jfasch/2021-06-14/tree/main/group-project>`__.

*Exercise*: in the ``group-project/`` directory,

* Build a program that uses *declarations* from ``db.h``, to

  * Iterate over what is in the user database |longrightarrow|
    ``userdb`` alongside ``num_users``, *external variables*.
  * Write CSV output.

* Add build instructions to ``group-project/CMakeLists.txt``.
* When done, commit and push to Github.

Day 4
.....

Plan
````

* Reiterate on "Variable Definitions", and global vs. local. Blah
  build system blah.
* Hmm. Pointers. 200ff.

  * Missing slide: entire address space

    .. image:: address-space-and-pointers.jpg
       :scale: 40%

  * jjj live-hacking log

* Group project: hmm. Pointers. Iteration maybe. As always.

*Intro*

``userdb`` is something that lets us do something on it. interface.

* init() (not yet, lets keep it global)
* Search by name -> strcmp()
* Index, incl. range checking and error handling. 
* Add maybe. Preallocate, and keep track of fill
* Goodie: remove, collapsing. Pooh no.

*Exercise*

blah

Day 5
.....

* ``ar cq <files>``
* CMake
* Project structure
