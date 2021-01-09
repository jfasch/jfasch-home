.. jf-topic:: ec.ec1.linux.basics

Basics
======

As opposed to bare metal and/or realtime operating systems, Linux (and
other general purpose operating systems) have a number of features
that can make development and usage easier.

* Virtual memory
* Processes
* File systems
* Commandline interface

Knowing which problems are solved here, one can go ahead and code.

* Not care about resources too much. (One should always care about
  resources, but when the design is right and all works, one can
  always optimze later). As Donald Knuth already put it, "Premature
  optimization is the root of all evil".
* Care about functionality and maintainability. No way rewriting the
  entire code base because one hardware part changes.
