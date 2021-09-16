.. jf-topic:: ecproposal.ec1.cxx.iface
   :dependencies: ecproposal.ec1.cxx.oo_basics

C++: Interfaces
===============

Given that everytbody knows what a class is, differentiate between two
different inheritance techniques,

* Implementation inheritance (generally frowned upon in C++)
* Interface implementation. This is an unnecessarily complex topic.

  * *Pure virtual*, and runtime method dispatch
  * Why the hell does the destructor have to be virtual?
  * A lot more opportunities to shoot oneself in the foot

Put the *interface thinking* in relation to the different
:doc:`hardware sensor devices <linux_dev_mgmt>` - thermometers, just
implemented differently.
