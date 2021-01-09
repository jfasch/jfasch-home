.. jf-topic:: ec.ec1.cxx.build

C++: Building with CMake
========================

As a project become larger, it becomes increasingly difficult to
comprehensively manage it using :doc:`Make
</trainings/repertoire/make>`.

There are a number of open source alternatives to using Make whose
goal is to make project maintenance easier (software build and
configuration management is never easy though).

Here we learn about the `CMake <https://cmake.org/>`__ tools, which
provides a simpler syntax than Make (it is not easy to make it worse),
and which can *generate* Makefiles from the CMake input files.
