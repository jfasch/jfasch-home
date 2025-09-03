.. include:: <mmlalias.txt>


C++ For Embedded Developers (2023-03-20 - 2023-03-23)
=====================================================

.. contents::
   :local:

.. sidebar::

   * Start: Monday 9:00
   * 3 days
   * Project on Github: https://github.com/jfasch/2023-03-20

Goal
----

Give an idea how an experienced C programmer can benefit from the C++
toolcase. The following aspects are covered, accompanied with many
exercises.

* C++ is an *object oriented* language. That term alone has many
  facets, and a solid understanding of each is given. Constructors,
  destructors, automatic pointer/base-class conversion, late binding
  ("abstract"?), and all that.
* C++ also brings a rich toolset in form of its *standard
  library*. After a short conceptual introduction, *containers* and
  *algorithms* are something that is immediately useful for non-OO
  programmers.
* C++ does not stop there; :doc:`starting from its 2011 definition
  </trainings/repertoire/c-like/cxx11>`, the language has undergone a
  major revolution. An overview is given.

Work Environment
----------------

Preferred: Ubuntu under Windows (WSL)
.....................................

I suggest you use the :doc:`Windows Subsystem For Linux (WSL2)
</trainings/material/soup/linux/basics/intro/wsl>` (Microsoft
documentation `here
<https://docs.microsoft.com/en-us/windows/wsl/>`__). This sets up a
virtualized Ubuntu inside Windows, together with all interoperability
wazoo.

When installed, open a Ubuntu terminal, and install the software that
is required for this training.

.. code-block::

   $ sudo apt update
   $ sudo apt install git build-essential cmake libgtest-dev libgmock-dev

Unsupported Environments
........................

It is also possible to setup a Linux-like environment on native
Windows, using the following emulation layers:

* `Cygwin <https://www.cygwin.com/>`__
* `MinGW <https://www.mingw-w64.org/>`__ (known to have problems when
  it comes to threading)

You may use these, but be warned that there might not exist enough
trainer-side knowledge to help you out if anything goes wrong.

Skeleton Project Setup
......................

Follow the instructions in the `course project README
<https://github.com/jfasch/2023-03-20>`__ to setup the initial version
of the course project.

Day 1
-----

Classes, Objects, Methods
.........................

* From
  :doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/index`

  * :doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/c`
  * :doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/cpp-introduction`
  * :doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/ctor-custom`
  * :doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/ctor-default`
  * :doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/copy-basics`
  * :doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/ctor-dtor`
  * :doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/object-copy`

* From :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/index`

  * :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/010-overloading/topic`
  * :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/020-methods/topic`
  * :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/040-this/topic`
  * :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/050-references/topic`
  * :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/060-static/topic`
  * :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/070-operators/topic`

Exercises
.........

* :doc:`/trainings/material/soup/cxx/cxx-exercises/oo-shapes/shapes`

Miscellaneous
.............

* One Definition Rule (ODR), and ``static inline`` class members:
  :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/065-static-member-variables/topic`
* ``constexpr`` explored. How is it used to populate the ``rodata``
  section and save RAM?

  * :doc:`/trainings/material/soup/cxx/cxx11/constexpr-constinit-consteval/constexpr`
  * Sample code: `rodata.cpp
    <https://github.com/jfasch/2023-03-20/blob/main/livehacking/rodata.cpp>`__

* Global objects from different compilation units are initialized in
  *unspecified* order. See `here <https://github.com/jfasch/2023-03-20/tree/main/livehacking/global-ctor>`__.

Day 2
-----

Heavy Weight OO |:muscle:|
..........................

* From
  :doc:`/trainings/material/soup/cxx/cxx03/inheritance-oo-design/index`

  * :doc:`/trainings/material/soup/cxx/cxx03/inheritance-oo-design/basics`
  * :doc:`/trainings/material/soup/cxx/cxx03/inheritance-oo-design/virtual-method`
  * :doc:`/trainings/material/soup/cxx/cxx03/inheritance-oo-design/pure-virtual`
  * :doc:`/trainings/material/soup/cxx/cxx03/inheritance-oo-design/destructor`
  * :doc:`/trainings/material/soup/cxx/cxx03/inheritance-oo-design/interface`

Resource Management Pitfalls
............................

* Exploring object copy when resources have to be explicitly managed:
  :doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/object-copy`

Day 3
-----

R-Value References/Moving, And Managed Pointers
...............................................

* :doc:`/trainings/material/soup/cxx/cxx11/move/index`
* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/index`

A Little Concurrency
....................

* Only if there is time (and fun): have a look at
  :doc:`/trainings/material/soup/cxx/cxx11/multithreading/index`

Exercise
........

Based upon an object oriented encapsulation for OS primitives (timers
and GPIOs, mainly),

* Sensors

  * A sensor *abstract base class* - an *interface*
  * A number of concrete sensor implementations
  * A configured set of those, measuring live data
  * Live data is *posted* via another interface

* Display(s)

  * Another *interface* in the system
  * Display measurement values
  * Concrete implementation: a software PWM using a timer and a GPIO
    (as opposed to :doc:`hardware PWM
    </trainings/material/soup/linux/hardware/pwm/topic>`

Untold So Far
-------------

C++ Standard Library
....................

* :doc:`Managed Pointers
  </trainings/material/soup/cxx/cxx11/smart-pointers/index>`
* Pointer Arithmetic Recap:
  :doc:`/trainings/material/soup/c/050-pointers-and-arrays/040-pointers-and-arrays/topic`
* :doc:`/trainings/material/soup/cxx/cxx03/060-stl/010-basics/topic`
* Basic Algorithms

  * :doc:`/trainings/material/soup/cxx/cxx03/060-stl/020-algorithm/for_each`
  * :doc:`/trainings/material/soup/cxx/cxx03/060-stl/020-algorithm/copy`
  * :doc:`/trainings/material/soup/cxx/cxx03/060-stl/020-algorithm/reverse`
  * :doc:`/trainings/material/soup/cxx/cxx03/060-stl/020-algorithm/reverse_copy`
  * :doc:`/trainings/material/soup/cxx/cxx03/060-stl/020-algorithm/find`
  * :doc:`/trainings/material/soup/cxx/cxx03/060-stl/020-algorithm/find_if`

* Sorted Array Algorithms

  * :doc:`/trainings/material/soup/cxx/cxx03/060-stl/020-algorithm/sort`
  * :doc:`/trainings/material/soup/cxx/cxx03/060-stl/020-algorithm/binary_search`
  * :doc:`/trainings/material/soup/cxx/cxx03/060-stl/020-algorithm/lower_bound`

* Sequential Containers

  * :doc:`/trainings/material/soup/cxx/cxx03/060-stl/040-sequential-containers/basics`
  * :doc:`/trainings/material/soup/cxx/cxx03/060-stl/040-sequential-containers/vector`
  * :doc:`/trainings/material/soup/cxx/cxx03/060-stl/040-sequential-containers/list`

* Associative Containers

  * :doc:`/trainings/material/soup/cxx/cxx03/060-stl/050-associative-containers/basics`
  * :doc:`/trainings/material/soup/cxx/cxx03/060-stl/050-associative-containers/map`
  * :doc:`/trainings/material/soup/cxx/cxx03/060-stl/050-associative-containers/multimap`

Miscellaneous Topics
....................

* Optimization

  * :doc:`/trainings/material/soup/c/100-performance/010-introduction/topic`
  * :doc:`/trainings/material/soup/c/100-performance/020-computebound/topic`
  * :doc:`/trainings/material/soup/c/100-performance/030-memory/topic`
