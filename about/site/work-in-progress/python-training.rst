Python Training Improvements
============================

.. contents::
   :local:

Beginner Course
---------------

Extract beginner course from *everything*. Take exercises from Herdt,
and create a chain of exercises, thereby covering all that is
necessary.

Look in :doc:`/trainings/log/detail/2021-01-13/index` which
exercises were made, and put them in order with dependencies. The
resulting dependency chain defines the main structure of the course.

* Split the "Executable Program" part out of "Hello World" (and rename
  the entire thing to something like executing python code).

  Don't forget about dependencies.

* Split "Commandline Arguments" out from
  :doc:`/trainings/material/soup/python/python_0130_syntax_etc/topic`.

  Depend on it:

  * :doc:`/trainings/material/soup/python/python_0165_exercises/exercise_cmdline_digit`
  * :doc:`/trainings/material/soup/python/python_0190_exercises/exercise_max_numbers`

* Create special purpose node type ``jf-exercise`` (rectangle shape),
  and convert all.

* ``while`` exercises: generalize
  :doc:`/trainings/material/soup/python/python_0190_exercises/exercise_max_numbers`
  to take any number of arguments, and use while to run over those.

* ``for`` exercise: simplify **all** ``while`` exercises to use
  ``for`` instead.

* Cram exercises in groups

Exercise Structure
------------------

* Continue to cram exercises in their respective groups
* Bring in all the exercises from the Herdt script

Split Exercises
...............

Custom trainings are defined by picking the appropriate
exercises. Improve existing exercise material by splitting existing
exercise-topics into more fine-grained pieces (maybe surrounded by a
group?)

Miscellaneous
-------------

* :doc:`/trainings/material/soup/python/python_0150_datatypes_overview_compound/topic`

  Cut example code linewise into tables, giving comments in the right
  column.
* :doc:`/trainings/material/soup/python/python_0193_while/topic`

  ``break`` and ``continue`` example, with a search in a
  sequence/list. Maybe as a livehacking screenplay.
* Eliminate Python 2 wherever I see it

  * :doc:`/trainings/material/soup/python/python_0150_datatypes_overview/topic`
  * :doc:`/trainings/material/soup/python/python_0120_helloworld/topic`
  * :doc:`/trainings/material/soup/python/python_0500_files/topic`

* "Dependencies" link in every topic
