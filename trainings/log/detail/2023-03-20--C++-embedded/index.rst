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
trainer-side knowledge to help you out f anything goes wrong.

Skeleton Project Setup
......................

Follow the instructions in the `course project README
<https://github.com/jfasch/2023-03-20>`__ to setup the initial version
of the course project.

Day 1
-----

Object Oriented Programming
...........................

* From
  :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/group`

  * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/c`
  * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`
  * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-custom`
  * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-default`
  * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/copy-basics`
  * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-dtor`
  * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/object-copy`

* From :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/group`

  * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/010-overloading/topic`
  * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/020-methods/topic`
  * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/030-const/topic`
  * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/040-this/topic`
  * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/050-references/topic`
  * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/060-static/topic`
  * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/070-operators/topic`

  **Exercises**

  * :doc:`/trainings/material/soup/cxx-exercises/oo-shapes/shapes`

jjj live hacking references, explanations

Day 2
-----

* ODR, static inline, ...: :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/065-static-member-variables/topic`
* ``constexpr`` livehacking, revisited. :doc:`/trainings/material/soup/cxx11/020-new-language-features/055-constexpr/topic`
* Global objects? Ctor order?


* From
  :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/group`

  * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/basics`
  * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/private-protected`
  * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/virtual-method`
  * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/polymorphism`
  * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/destructor`
  * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/virtual-destructor`
  * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/interface`

C++ Standard Library
--------------------

* :doc:`Managed Pointers
  </trainings/material/soup/cxx11/030-smart-pointers/group>`
* Pointer Arithmetic Recap:
  :doc:`/trainings/material/soup/c/050-pointers-and-arrays/040-pointers-and-arrays/topic`
* :doc:`/trainings/material/soup/cxx03/060-stl/010-basics/topic`
* Basic Algorithms

  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/for_each`
  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/copy`
  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/reverse`
  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/reverse_copy`
  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/find`
  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/find_if`

* Sorted Array Algorithms

  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/sort`
  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/binary_search`
  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/lower_bound`

* Sequential Containers

  * :doc:`/trainings/material/soup/cxx03/060-stl/040-sequential-containers/basics`
  * :doc:`/trainings/material/soup/cxx03/060-stl/040-sequential-containers/vector`
  * :doc:`/trainings/material/soup/cxx03/060-stl/040-sequential-containers/list`

* Associative Containers

  * :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/basics`
  * :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/map`
  * :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/multimap`

Miscellaneous Topics
--------------------

* Optimization (optional)

  * :doc:`/trainings/material/soup/c/100-performance/010-introduction/topic`
  * :doc:`/trainings/material/soup/c/100-performance/020-computebound/topic`
  * :doc:`/trainings/material/soup/c/100-performance/030-memory/topic`

Exercise Series
---------------

Based upon an object oriented encapsulation for OS primitives (timers
and GPIOs, mainly),

* Sensors (roughly taken from :doc:`here
  </trainings/material/soup/cxx-exercises/oo-sensors/group>`)

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

To Be Done
----------

* ``std::array``
* Overloading the ``new`` operator
* Global objects initialization order
