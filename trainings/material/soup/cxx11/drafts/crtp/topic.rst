Curiously Recurring Template Pattern
====================================

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

* std::variant

  https://gist.github.com/olibre/3d0774df0f7a16e2da10fae2b2f26c4f

