Polymorphic "Classes" In Good Ol' C
===================================

* bring C++
* C: implement by hand everything the C++ compiler does

* interface in c

  * func ptr type for each virtual
  * const method?
  * need .c file for vtable call implementation

    * init: vtable setup, called by base classes

* implementation

  * is-a -> containment
  * note: methods (incl. dtor) only used via base class and dynamic
    dispatch

    -> static in .c
