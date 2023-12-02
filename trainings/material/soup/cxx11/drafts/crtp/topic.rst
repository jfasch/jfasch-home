.. ot-topic:: cxx11.drafts.crtp

.. include:: <mmlalias.txt>


Curiously Recurring Template Pattern (Will Be: How To Avoid ``virtual``)
========================================================================

Options ``code/problem-definition/``
------------------------------------

* Classic virtual
* Related, non-virtual, type field in base
* Completely unrelated: equivalent, but not storable in e.g. vector

Problems
........

* want unrelated, like Python - but union is cumbersome
* only storing pointers to real instances (because union)

jjj

Solution: ``std::variant<>``
----------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx11/100-miscellaneous/any-variant-optional/variant`



* Start with ``code/problem-definition/unrelated.h``
* Replace ``union`` with ``using Sensor = std::variant<Sensor1, Sensor2>``
* Insert some into vector -> ok
* ``delete`` copy (ctor and ass.) -> ``default`` moves
* |longrightarrow| move into vector
* Use ``avg.h`` as-is: *Abbreviated Function Template*






* Add another sensor type? Comiler support to not crash the variant
  access in avg()?
* CRTP to prevent copy etc




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

Omit ``virtual``: Non-Related ``Sensor`` Implementations
........................................................

* jjj blah cannot store because no commmon type

jjj bring code

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
  
