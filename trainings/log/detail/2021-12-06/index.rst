.. include:: <mmlalias.txt>


C Programming (2021-12-06 - 2021-12-10)
=======================================

.. sidebar::

   **Contents**

   .. contents::
      :local:

   **Material**

   * :doc:`Course Description </trainings/repertoire/c-like/c>`
   * :doc:`Slide Material </trainings/material/soup/c/group>`

   **Git**

   * Please create `GitHub <https://github.com/>`__ account
   * `Create access token
     <https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/creating-a-personal-access-token>`__
   * Clone our repository (https://github.com/jfasch/2021-12-06):

     .. code-block:: console

	$ git clone https://github.com/jfasch/2021-12-06

Day 1
-----

* :doc:`/trainings/material/soup/c/010-introduction/000-installation/topic`
* :doc:`/trainings/material/soup/c/010-introduction/010-introduction/topic`
* :doc:`/trainings/material/soup/c/010-introduction/020-getting-started/topic`
* :doc:`/trainings/material/soup/c/010-introduction/030-variables-and-arithmetic-expressions/topic`
* Pointers, Arrays, and Commandline

  .. image:: images/argv.png
     :scale: 40%

* :doc:`/trainings/material/soup/c/010-introduction/040-exercise-fahrenheit-float/topic`
* :doc:`/trainings/material/soup/c/010-introduction/050-the-for-statement/topic`
* :doc:`/trainings/material/soup/c/010-introduction/060-exercise-fahrenheit-for/topic`

  Solutions:

  * `fahrenheit-for.c <https://github.com/jfasch/2021-12-06/blob/main/exercises/joerg/fahrenheit-for.c>`__
  * `fahrenheit-for-reverse.c <https://github.com/jfasch/2021-12-06/blob/main/exercises/joerg/fahrenheit-for-reverse.c>`__
  * `fahrenheit-for-float.cpp <https://github.com/jfasch/2021-12-06/blob/main/exercises/joerg/fahrenheit-for-float.cpp>`__

Day 2
-----

* :doc:`/trainings/material/soup/c/010-introduction/070-symbolic-constants/topic`
* :doc:`/trainings/material/soup/c/010-introduction/080-exercise-fahrenheit-cpp/topic`

  Solutions:
  
  * `fahrenheit-nonconst.cpp (a stupid bug) <https://github.com/jfasch/2021-12-06/blob/main/exercises/joerg/fahrenheit-nonconst.cpp>`__
  * `fahrenheit-const.cpp (using C preprocessor macros to prevent stupid bug) <https://github.com/jfasch/2021-12-06/blob/main/exercises/joerg/fahrenheit-const.cpp>`__

* :doc:`/trainings/material/soup/c/010-introduction/090-character-input-and-output/topic`
* :doc:`/trainings/material/soup/c/010-introduction/100-exercise-wc/topic`
* :doc:`/trainings/material/soup/c/010-introduction/110-arrays/topic`
* :doc:`/trainings/material/soup/c/010-introduction/120-exercise-histogram/topic`

  .. image:: images/ascii-counter.png
     :scale: 40%

  * Solution: `histogram.cpp <https://github.com/jfasch/2021-12-06/blob/main/exercises/joerg/histogram.cpp>`__

Day 3
-----

* Reiterating on
  :doc:`/trainings/material/soup/c/010-introduction/120-exercise-histogram/topic`

  * ``while ((c = getchar()) != EOF) { ... }``: assignment has a value (DRY: *don't repeat yourself*)
  * Arrays (and everything else) in C are not range checked
    |longrightarrow| input needs verification
  * How far can I write past the end of an array? |longrightarrow|
    `out-of-bounds-write.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/out-of-bounds-write.cpp>`__
  * Aside: C has no ``bool`` datatype (C++ has) |longrightarrow|
    `infinite-loop.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/infinite-loop.cpp>`__
	     
* :doc:`/trainings/material/soup/c/010-introduction/130-functions/topic`
* :doc:`/trainings/material/soup/c/010-introduction/140-exercise-power-declaration/topic`

  Solution: `power.c <>`__

* :doc:`/trainings/material/soup/c/010-introduction/150-character-arrays/topic`
* :doc:`/trainings/material/soup/c/010-introduction/160-exercise-string-read-line/topic`
* :doc:`/trainings/material/soup/c/010-introduction/170-external-variables-and-scope/topic`
* :doc:`/trainings/material/soup/c/020-types-operators-expressions/010-introduction/topic`
* :doc:`/trainings/material/soup/c/020-types-operators-expressions/020-variable-names/topic`
* :doc:`/trainings/material/soup/c/020-types-operators-expressions/030-data-types-and-sizes/topic`
* :doc:`/trainings/material/soup/c/020-types-operators-expressions/040-constants/topic`
* :doc:`/trainings/material/soup/c/020-types-operators-expressions/040-constants/topic`
* :doc:`/trainings/material/soup/c/020-types-operators-expressions/050-declarations/topic`
* :doc:`/trainings/material/soup/c/020-types-operators-expressions/060-arithmetic-operators/topic`
* :doc:`/trainings/material/soup/c/020-types-operators-expressions/070-relational-and-logical-operators/topic`
* :doc:`/trainings/material/soup/c/020-types-operators-expressions/080-type-conversions/topic`
* :doc:`/trainings/material/soup/c/020-types-operators-expressions/090-increment-and-decrement-operators/topic`
* :doc:`/trainings/material/soup/c/020-types-operators-expressions/100-exercise-string-reduce/topic`
* :doc:`/trainings/material/soup/c/020-types-operators-expressions/110-bitwise-operators/topic`
* :doc:`/trainings/material/soup/c/020-types-operators-expressions/120-assignment-operators-and-expressions/topic`
* :doc:`/trainings/material/soup/c/020-types-operators-expressions/130-conditional-expressions/topic`
* :doc:`/trainings/material/soup/c/020-types-operators-expressions/140-precedence-and-order-of-evaluation/topic`
