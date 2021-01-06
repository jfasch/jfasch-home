.. jf-topic:: fh.cxx_iface
   :dependencies: fh.cxx_oo_basics,
		  fh.dev_mgmt

C++: Interfaces (pure virtual)
==============================

Given that everytbody knows what a class is, differentiate between two
different inheritance techniques,

* Implementation inheritance (generally frowned upon in C++)
* Interface implementation. This is an unnecessarily complex topic.

  * *Pure virtual*, and runtime method dispatch
  * Why the hell does the destructor have to be virtual?
  * A lot more opportunities to shoot oneself in the foot

Put the *interface thinking* in relation to the different
:doc:`hardware sensor devices <dev_mgmt>` - thermometers, just
implemented differently.
