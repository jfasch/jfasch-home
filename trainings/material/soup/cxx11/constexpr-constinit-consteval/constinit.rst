.. include:: <mmlalias.txt>


``constinit`` And The *Static Initialization Order Fiasco*
==========================================================

Problem: The *Static Initialization Order Fiasco*
-------------------------------------------------

.. sidebar:: Documentation

   * `Static Initialization Order Fiasco
     <https://en.cppreference.com/w/cpp/language/siof>`__

**Definition: Initialization Of Globals**

* ``static`` locals

  * Initialized when program flow crosses initialization *the first
    time*

* Globals

  * Initialization in definition order per compilation unit
  * **Initialization order of compilation units is undefined**

* Since 1970-01-01 (`the epoch
  <https://en.wikipedia.org/wiki/Epoch_(computing)>`__): integrals are
  initialized at compile time |longrightarrow| this problem has been
  brought about by C++

SIOF Example: Mutex As A Global Variable (Demo Failure)
-------------------------------------------------------

.. sidebar:: Trainer's note

   * Prepare two files, ``main.cpp`` and ``other.cpp``
   * Morph those throughout this session

* This is a contrived example, but C++ Marketing stresses the
  *constant initialized mutex* feature a lot - so here it is
* Compilation unit #1 contains a global ``std::mutex`` (and ``main()``
  btw, which just pauses the process)
* Compilation unit #2 contains a global ``std::thread`` object *which
  references the mutex*
* Both ``the_mutex`` and ``the_thread`` are initialized at runtime
  before main in *undefined order*
* This is *undefined behavior* - the thread *could* run before the
  mutex is initialized
* To check, we link the program twice to reverse the order of
  initialization (see :download:`code/siof-mutex/CMakeLists.txt`)

.. literalinclude:: code/siof-mutex/CMakeLists.txt
   :caption: :download:`code/siof-mutex/CMakeLists.txt`
   :language: c++

.. literalinclude:: code/siof-mutex/main.cpp
   :caption: :download:`code/siof-mutex/main.cpp`
   :language: c++

.. literalinclude:: code/siof-mutex/other.cpp
   :caption: :download:`code/siof-mutex/other.cpp`
   :language: c++

SIOF Example: Global ``std::string`` Instances With Interdependencies (Demo Failure)
------------------------------------------------------------------------------------

* Similar situation: ``std::string my_string`` (defined in
  ``main.cpp``) depends on ``other_string`` (defined in ``other.cpp``)
* Demo failure: ``std::string`` constructor already appears to do
  magic to paper over bad language definition
* |longrightarrow| both programs show correct behavior - even though
  ill-formed

.. code-block:: console

   $ ./siof-string/c++11-constinit-string-runtime-init
   hello world
   $ ./siof-string/c++11-constinit-string-runtime-init-reversed 
   hello world

.. literalinclude:: code/siof-string/CMakeLists.txt
   :caption: :download:`code/siof-string/CMakeLists.txt`
   :language: c++

.. literalinclude:: code/siof-string/main.cpp
   :caption: :download:`code/siof-string/main.cpp`
   :language: c++

.. literalinclude:: code/siof-string/other.cpp
   :caption: :download:`code/siof-string/other.cpp`
   :language: c++

SIOF Example: Global ``Foo`` Instances With Interdependencies
-------------------------------------------------------------

* Becoming even more contrived - *although somewhat realistic*
* ``Foo`` instances depending on each other, just like ``std::string`` above
* |longrightarrow| Demo success

.. code-block:: console

   $ ./siof-foo/c++11-constinit-foo-runtime-init
   42
   $ ./siof-foo/c++11-constinit-foo-runtime-init-reversed 
   708

.. literalinclude:: code/siof-foo/CMakeLists.txt
   :caption: :download:`code/siof-foo/CMakeLists.txt`
   :language: c++

.. literalinclude:: code/siof-foo/main.cpp
   :caption: :download:`code/siof-foo/main.cpp`
   :language: c++

.. literalinclude:: code/siof-foo/other.cpp
   :caption: :download:`code/siof-foo/other.cpp`
   :language: c++

Solution: ``constinit``
-----------------------

.. sidebar:: Trainer's note

   * Start with making ``other_foo`` const-initialized/``constinit``
   * See how ``Foo::Foo()`` has to be ``constexpr``

* ``other_foo`` needs to be available *before* someone depends on it
* |longrightarrow| ``constinit``
* Note that the depender cannot be ``constinit``
* Note: ``my_foo`` cannot be ``constinit`` |longrightarrow| ``extern``
  has no idea

.. code-block:: console

   $ ./siof-foo-solution/c++11-constinit-foo-constinit
   708
   $ ./siof-foo-solution/c++11-constinit-foo-constinit-reversed 
   708

.. literalinclude:: code/siof-foo-solution/CMakeLists.txt
   :caption: :download:`code/siof-foo-solution/CMakeLists.txt`
   :language: c++

.. literalinclude:: code/siof-foo-solution/main.cpp
   :caption: :download:`code/siof-foo-solution/main.cpp`
   :language: c++

.. literalinclude:: code/siof-foo-solution/other.cpp
   :caption: :download:`code/siof-foo-solution/other.cpp`
   :language: c++
