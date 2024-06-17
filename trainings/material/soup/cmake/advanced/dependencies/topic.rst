More Topics
===========

.. content:
   :local:

Faschingbauer Toybox
--------------------

Boilingpot
..........

* Restrukturierung in public/private Inc
* Zuvor erklärung “” <> hehe
* Targetincdir private, Demo Inc von woandersher -> error
* Targetincdir public beide
* Targetincdir interface …

Datalogger
..........

... detto ...

Base
....

* Basic tools
* Maybe exclude w1 and sysfs, and bring them in later. together with
  libgpoid2, as an external dependency? MAybe examples 

  * one simple such as zlib
  * one like protobuf
  * libgpiod2

Tests
.....

Blah

Topics
------

* Experimentation with elf utils, im zusammenhang mit ... b?
  
  Das mit runpath raus in ein eigenes kapitel, und zusammen mit dem
  rein in ein generelleres bild mit cmake und toolchain (das mit dem
  gebaut wird) und runtime ( das was installert deployed ist)

* Object libraries -> libfaschingbauer.a 
* Aggregation statics into shared library.

  * Pic 
  * Verweis auf binutis (?) Kapitel von hier irgendwo
  * Rumspielen mit aggregation: Bowling pot und datalogger in
    libfaschingbauer.so mit Versionen und so. -> loader ecplanation
    ueber binutils hier irgendwo)

* Erklärung runtime dependencies in cmake Intro shared libraries,
  rausrupfen und hierher

* Example protobuf Proxy ``Sensor`` über protobuf 

  * Link auf design patterns
  * Server inline in python :-)

* B ist eine shared library, die aus mehreren statische libraries
  gelinkt iist. Die, und alle ihre staischen teile, haben build
  abhängigkeiten. Intern visible mit private includedirs extern
  visible mit public/interface. Oder einfach nur interne headers _
  nennen?

What else?
----------

* Build time properties
* Presets
* User configurable siehe postit
* Reference book author

.. attention:: Request reference book author mention referencing his book.

* Propagation Chart. Irgendwas der Isi erklären, mit Output -> dependencies
* External targets, transitive dependencies - conan. Eventuell mit
  einem schwesterrepo über pkgconfig? Conan? Gibts was in cmake?
