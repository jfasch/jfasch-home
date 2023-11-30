.. ot-topic:: cxx11.drafts.crtp

.. include:: <mmlalias.txt>


Curiously Recurring Template Pattern (Will Be: How To Avoid ``virtual``)
========================================================================

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
  
