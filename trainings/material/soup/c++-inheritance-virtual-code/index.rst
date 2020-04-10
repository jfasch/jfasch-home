Code: C++: Inheritance, Interfaces, ``virtual``
===============================================

* start with concrete spi thermometer, thermometer.h (this is the first that we need)

  * main program ``spi.cc`` which reads temperature and writes it to
    output.

* hmm. i2c. duplicate code

  * two classes (spi and i2c) in thermometer.h
  * two exes likewise

* discuss: unrelated classes. similar (``get_temperature()``), but
  unrelated.
* proof of missing relationship: "algorithm": read temperatures in a
  loop, and give histogram
* algorithm inline in spi.cc
* extract as function (still in spi.cc)
* hmm. and i2c?
* duplicate code into i2c.cc
* hmm. like thermometer.h, collect histogram routines in
  histogram.{h,cc}. modify mains accordingly.
* hmm. look in histogram.{h,cc} and thermometer.{h,cc}.
* discuss. I want only one routine ``make_histogram()`` that makes me
  a histogram from *any* thermometer.
* histogram.{h,cc}: collapse into one, ``Thermometer``. without
  pointer, for the time being.
* thermometer.h: *base class* ... *interface*
* discuss *very* thoroughly

  * dynamic dispatch
  * runtime overhead (as opposed to copied code, like before we had a
    base class)

* discuss: mock

.. todo::

   Use this file to further describe what's there

.. literalinclude:: CMakeLists.txt
   :language: cmake

.. program-output:: tree
   :cwd: .
