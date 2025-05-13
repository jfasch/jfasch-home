.. include:: <mmlalias.txt>


``static`` Member Variables
===========================

.. contents::
   :local:

Good Old C: ``extern`` Global Variables
---------------------------------------

* Declaration (and usage)

  * Hey compiler, please don't care: the linker will bring that
    in. Not your business.
  * Hey linker, insist in bringing that in: find it in all the other
    compilation units. But only if it is "odr-used" (i.e., if it is
    *referenced*)

  .. literalinclude:: code/main-extern-declaration.cpp
     :caption: :download:`code/main-extern-declaration.cpp`
     :language: c++

* Definition

  * Hey linker, if someone outside needs that, please happily offer
    it.

  .. literalinclude:: code/extern-definition-plain.cpp
     :caption: :download:`code/extern-definition-plain.cpp`
     :language: c++

ODR: One Definition Rule
------------------------

.. sidebar::

   **Documentation**

   * `Definitions and ODR (One Definition Rule)
     <https://en.cppreference.com/w/cpp/language/definition>`__

* A variable must be defined at most once
* Can be left undefined if not used (|longrightarrow| *odr-used*)

**Duplicate definition***

.. literalinclude:: code/definition1.cpp
   :caption: :download:`code/definition1.cpp`
   :language: c++

.. literalinclude:: code/definition2.cpp
   :caption: :download:`code/definition2.cpp`
   :language: c++

.. literalinclude:: code/odr-duplicate-main.cpp
   :caption: :download:`code/odr-duplicate-main.cpp`
   :language: c++

**Left undefined if unused***

.. literalinclude:: code/odr-unused-but-declared-main.cpp
   :caption: :download:`code/odr-unused-but-declared-main.cpp`
   :language: c++

(A Litte) More Overengineered: Declaration In Header File
---------------------------------------------------------

* *Declaration and definition always pairwise: header file and c file*
* Don't place ``extern`` declaration directly at the user's site
* |longrightarrow| Use a *header file*

  .. literalinclude:: code/extern-declaration.h
     :caption: :download:`code/extern-declaration.h`
     :language: c++

* As above, ``.c`` file defines it (including ``.h`` file only for
  type sanity checks)

  .. literalinclude:: code/extern-definition.cpp
     :caption: :download:`code/extern-definition.cpp`
     :language: c++

* Using entity (``main()``) include ``.h`` to pull in ``extern``
  declaration, and to ``odr-use`` the variable

  .. literalinclude:: code/main-includes-extern-declaration-uses-global.cpp
     :caption: :download:`code/main-includes-extern-declaration-uses-global.cpp`
     :language: c++

Same Inside A Class: ``static`` Member Variable
-----------------------------------------------

* ``extern`` declaration, only prettier

  .. literalinclude:: code/class-good-old.h
     :caption: :download:`code/class-good-old.h`
     :language: c++

* Definition: same, only inside class

  .. literalinclude:: code/class-good-old.cpp
     :caption: :download:`code/class-good-old.cpp`
     :language: c++

* Using entity, again. Not much different.

  .. literalinclude:: code/main-static-class-member-good-old.cpp
     :caption: :download:`code/main-static-class-member-good-old.cpp`
     :language: c++

Sideway: *Definition* In A Header File?
---------------------------------------

* Definition of ``static`` class member not possible
* C++ appears to enforce the *ODR*

.. code-block:: c++
   
   class Class
   {
   public:
       static int global = 666;
   };

.. code-block:: console

   error: ISO C++ forbids in-class initialization of non-const static member ‘Class::global’
       7 |     static int global = 666;        // <--- "extern" declaration
         |                ^~~~~~

``static inline`` Member Defnition (Since C++17)
------------------------------------------------

* Major trickery from C++ 17 onwards
* ODR *definition* in class definition

  * |longrightarrow| no ``.cpp`` file anymore to satisfy ODR

* Immune to multiple includers of the class

  * ... which is the regular case
  * Burden placed upon the linker

.. literalinclude:: code/class-static-inline.h
   :caption: :download:`code/class-static-inline.h`
   :language: c++
