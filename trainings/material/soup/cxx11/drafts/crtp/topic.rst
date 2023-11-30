.. ot-topic:: cxx11.drafts.crtp

.. include:: <mmlalias.txt>


Curiously Recurring Template Pattern (Will Be: How To Avoid ``virtual``)
========================================================================

Structure/Plan
--------------

Straightforward

* ``related-virtual``: classic polymorphic types. ``average()``
  calculated over a range of pointers-to-base, calling
  ``get_temperature()`` on each polymorphically.
* ``related-no-virtual``: related types, non-polymorphic. Base class
  only has a type field that derived classes set. ``average()``
  calculated by ``switch``'ing over the type field, and
  ``static_cast``'ing to derived class.
* ``unrelated``: completely unrelated types, much like :doc:`duck
  typing in dynamic languages like Python
  </trainings/material/soup/python/advanced/oo/abc/topic>`. ``average()``
  on a range of ``union`` crammed into a ``struct`` that adds a type
  field. This way we can store them "polymorphically" in an array.

Future

* ``average()`` in each namespaces is an :doc:`Abbreviated Function
  Template
  </trainings/material/soup/cxx11/020-new-language-features/ranges/intro>`

  * All implementations look the same
  * Global ``get_temperature()`` is used to implement "polymorphism"
  * |longrightarrow| unify
  * |longrightarrow| add :doc:`concepts
    </trainings/material/soup/cxx11/020-new-language-features/concepts/group>`
    to each

* Use a :doc:`variant
  </trainings/material/soup/cxx11/100-miscellaneous/any-variant-optional/variant>`
  to achive "polymorphism", with ``std::variant``'s methods for
  inspectation.
* ``std::visit``, twofold

  * manually, ``if`` |longrightarrow| unsafe
  * Visitor, overloading ``operator()`` |longrightarrow| safe

* Sideways: ``unrelated`` with CRTP (maybe bring that first,
  before moving to ``std::variant``). **NO** that crap "pattern" (it's
  an idiom at most) does not solve any real problem.

``virtual``
-----------

* Pros

  * Beautiful interfaces
  * Late binding (calling code does not need to be aware of
    implementations)

    * Dynamic loading
    * :doc:`SOLID
      </trainings/material/soup/cxx-design-patterns/oo-principles>`
    * Maximum flexibility

  * Storing of polymorphic objects easy (e.g.,
    ``std::vector<Interface*>``)

* Cons

  * Blah overhead blah
  * *Runtime decision* when called through base class/interface
  * Code bloat (lotsa runtime decision/type-info stuff)
    |longrightarrow| ``-no-rtti`` to eliminate some

Typical ``virtual`` Usecase: Polymorphic ``Sensor`` Type
........................................................

.. literalinclude:: code/related-virtual.h
   :language: c++
   :caption: :download:`Download <code/related-virtual.h>`

Building average across multiple sensors:

.. literalinclude:: code/avg--related-virtual.h
   :language: c++
   :caption: :download:`Download <code/avg--related-virtual.h>`

Main program:

.. literalinclude:: code/avg--related-virtual-main.cpp
   :language: c++
   :caption: :download:`Download <code/avg--related-virtual-main.cpp>`

Omit ``virtual``: Non-Related ``Sensor`` Implementations
........................................................

* jjj blah cannot store because no commmon type

jjj bring code

Type Field
----------

Solution to handmade polymorphism

.. literalinclude:: code/related-no-virtual.h
   :language: c++
   :caption: :download:`Download <code/related-no-virtual.h>`

Building average across multiple sensors:

.. literalinclude:: code/avg--related-no-virtual.h
   :language: c++
   :caption: :download:`Download <code/avg--related-no-virtual.h>`

Main program:

.. literalinclude:: code/avg--related-no-virtual-main.cpp
   :language: c++
   :caption: :download:`Download <code/avg--related-no-virtual-main.cpp>`

Union? C++? ``std::variant<>``!
-------------------------------

https://gist.github.com/olibre/3d0774df0f7a16e2da10fae2b2f26c4f
    
And CRTP?
---------

Future
------

https://en.cppreference.com/w/cpp/utility/functional/function_ref

* Bullshit

  * https://stackoverflow.com/questions/4173254/what-is-the-curiously-recurring-template-pattern-crtp
  
    .. code-block:: c++
    		
       template <typename T>
       struct Base {
         void foo() {
           (static_cast<T*>(this))->foo();
         }
       };
       
       struct Derived : public Base<Derived> {
         void foo() {
           cout << "derived foo" << endl;
         }
       };
       
       struct AnotherDerived : public Base<AnotherDerived> {
         void foo() {
           cout << "AnotherDerived foo" << endl;
         }
       };
       
       template<typename T>
       void ProcessFoo(Base<T>* b) {
         b->foo();
       }
  
