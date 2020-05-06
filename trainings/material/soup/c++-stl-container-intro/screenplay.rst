Screenplay: C++: STL Containers (Intro)
=======================================

.. sidebar:: Contents

   .. contents::
      :local:

   **Code**: :doc:`code/index`

Pointer Arithmetics Recap
-------------------------

.. literalinclude:: code/10-pointer-arith-basics.cc
   :caption: :download:`code/10-pointer-arith-basics.cc`
   :language: c++

**Discussion**

* Step width, pointer increment
* No range checks: *performance*
* *Note* how ``valgrind`` does not say *invalid write*, but
  *conditional jump depends on uninitialized ...*
* :download:`C++03 slides </trainings/material/pdf/055-c++03.pdf>`,
  105ff.

**Next: "copy" algorithm**

* start without ``const``
* ``const`` on ``begin``, ``end``; fix ``copy()`` prototype

.. literalinclude:: code/11-pointer-arith-ranges.cc
   :caption: :download:`code/11-pointer-arith-ranges.cc`
   :language: c++

**Discussion**

* ``[begin, end)``
* emphasize ```const`` *a lot*
* ``copy()``: *algorithm*
* :download:`C++03 slides </trainings/material/pdf/055-c++03.pdf>`,
  108ff.

Container: ``std::vector``
--------------------------

**Steps**

* slowly morph C program from above
* C++03: separate step
* C++11: separate step

.. literalinclude:: code/20-vector.cc
   :caption: :download:`code/20-vector.cc`
   :language: c++

**Discussion**

* *brace initialization* (see more in :download:`C++11 slides, "Brace
  Initialization" </trainings/material/pdf/056-c++11.pdf>`.
* note how ``iterator`` feels like a pointer

  * index operator ``[]``
  * increment

Algorithm: ``std::vector`` and Naive Copy
-----------------------------------------

**Steps**

* start out with function ``copy()`` from C pointer arith above
* WTF does the compiler not choose my ``copy``, but rather complains
  about something from ``std``? do they have a namespace leak
  somewhere?
* rename to ``my_copy()``
* see how we end up with two versions of ``my_copy()``

  * different prototypes, but identical body

.. literalinclude:: code/25-vector-naive-copy.cc
   :caption: :download:`code/25-vector-naive-copy.cc`
   :language: c++

**Discussion**

* this cannot be the positive side
* enter ``std::copy<>``

Algorithm: ``std::vector`` and ``std::copy<>``
----------------------------------------------

**Steps**

* again, morph from previous ``my_copy``

.. literalinclude:: code/26-vector-algo-copy.cc
   :caption: :download:`code/26-vector-algo-copy.cc`
   :language: c++

**Discussion**

* ``std::copy`` works like ``my_copy``: no range checks, nothing
  special
* 

Container: ``std::list``
------------------------

**Steps**

* Nah, these are trivial. Show ``vector`` pendants
* erase is difficult. 

  * show naive variant first; ``valgrind`` will complain.
  * check doc of erase. return value is what we need.

.. literalinclude:: code/25-list.cc
   :caption: :download:`code/25-list.cc`
   :language: c++

Container: ``std::map``
------------------------

.. literalinclude:: code/30-map.cc
   :caption: :download:`code/30-map.cc`
   :language: c++
