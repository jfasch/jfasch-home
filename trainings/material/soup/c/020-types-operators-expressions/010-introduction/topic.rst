.. include:: <mmlalias.txt>


Type System
===========

**A type system is in place, but it is complicated ...** at least with
respect to built-in datatypes like integers and floating point numbers

* ``signed`` and ``unsigned`` variants
* ``long`` and ``short`` variants
* *Signedness* of ``char`` is machine dependent (i.e. *undefined*)
* Implicit type conversions
* Sign propagation
* ... and lots more ...
* |longrightarrow| it is very important to understand how and why
* **... and to be defensive!**
