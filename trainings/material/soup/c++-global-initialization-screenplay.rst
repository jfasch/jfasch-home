Screenplay: C++: Global Objects Initialization
==============================================

.. sidebar:: Contents

   .. contents::
      :local:

   **Code**: :doc:`c++-global-initialization-code/index`

Global Variables
----------------

.. literalinclude:: c++-global-initialization-code/01-global.cc
   :caption: :download:`c++-global-initialization-code/01-global.cc`
   :language: c++

**Discussion**

* obviously somebody must call constructor and destructor
* discuss ELF and sections?

Define class with output ...

.. literalinclude:: c++-global-initialization-code/thing.h
   :caption: :download:`c++-global-initialization-code/thing.h`
   :language: c++

Constructor and Destructor Order in Same File
--------------------------------------------- 

.. literalinclude:: c++-global-initialization-code/10-same-file.cc
   :caption: :download:`c++-global-initialization-code/10-same-file.cc`
   :language: c++

**Discussion**

* ``thing1`` and ``thing2`` constructed in definition order
* ``thing1`` and ``thing2`` denstructed in reverse definition order
* *This can be counted on!*

Constructor and Destructor Order Across Files
--------------------------------------------- 

.. literalinclude:: c++-global-initialization-code/20-different-files.cc
   :caption: :download:`c++-global-initialization-code/20-different-files.cc`
   :language: c++

.. literalinclude:: c++-global-initialization-code/20-thing1.cc
   :caption: :download:`c++-global-initialization-code/20-thing1.cc`
   :language: c++

.. literalinclude:: c++-global-initialization-code/20-thing2.cc
   :caption: :download:`c++-global-initialization-code/20-thing2.cc`
   :language: c++

From this build two different executables (:doc:`see
<c++-global-initialization-code/index>` ``CMakeLists.txt``)

.. code-block:: console

   $ ./20-different-files
   ctor: thing1
   ctor: thing2
   dtor: thing2
   dtor: thing1

.. code-block:: console

   $ ./20-different-files-reversed 
   ctor: thing2
   ctor: thing1
   dtor: thing1
   dtor: thing2
   
**Discussion**

* Standard says, initialization (and destruction) order is
  *unspecified* across compilation units
* Here, Linux, ``gcc``, ``ld``: *link order*
* Static libraries: *different story*
* Shared libraries: *different story*

Constructor and Destructor Order Across Files: Dependencies, Bugs
-----------------------------------------------------------------

.. literalinclude:: c++-global-initialization-code/30-different-files-bug.cc
   :caption: :download:`c++-global-initialization-code/30-different-files-bug.cc`
   :language: c++

.. literalinclude:: c++-global-initialization-code/30-thing1.cc
   :caption: :download:`c++-global-initialization-code/30-thing1.cc`
   :language: c++

Here is the dependency: ``thing2``'s content is ``thing1``'s plus
extra stuff,

.. literalinclude:: c++-global-initialization-code/30-thing2.cc
   :caption: :download:`c++-global-initialization-code/30-thing2.cc`
   :language: c++

From this build two different executables (:doc:`see
<c++-global-initialization-code/index>` ``CMakeLists.txt``)

.. code-block:: console

   $ ./30-different-files-bug 
   ctor: thing1
   ctor: thing1 BUG!!
   dtor: thing1 BUG!!
   dtor: thing1

.. code-block:: console

   $ ./30-different-files-bug-reversed 
   ctor:  BUG!!
   ctor: thing1
   dtor: thing1
   dtor:  BUG!!
   
**Discussion**

* One has to *know* this
* Or experience it the hard way
* **Essence**: *don't do it!* (:ref:`There are other cases like this
  <cpp-pointer-const-const-delete>`)
