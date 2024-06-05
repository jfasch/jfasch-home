.. include:: <mmlalias.txt>


Advanced CMake (Course Date Yet Unknown)
========================================

.. contents::
   :local:

Basics
------

* :doc:`/trainings/material/soup/cmake/intro/basics`
* :doc:`/trainings/material/soup/cmake/intro/libraries`
* :doc:`/trainings/material/soup/cmake/intro/shared-libraries`
* :doc:`/trainings/material/soup/cmake/intro/installation`
* :doc:`/trainings/material/soup/cmake/intro/structure`
* :doc:`/trainings/material/soup/cmake/intro/cxx-and-rants`
* *Exercise*: see
  https://github.com/jfasch/2023-11-27/tree/main/exercise

Optional Code And External Dependencies
---------------------------------------

* :doc:`/trainings/material/soup/cmake/advanced/configure_file`
* :doc:`/trainings/material/soup/cmake/advanced/optional-code-problem`
* :doc:`/trainings/material/soup/cmake/advanced/optional-code-approach-1`
* :doc:`/trainings/material/soup/cmake/advanced/optional-code-approach-2`
* :doc:`/trainings/material/soup/cmake/advanced/targets-properties`
* :doc:`/trainings/material/soup/cmake/advanced/external-dependencies`
* *Exercise*

Testing, Code Coverage, Code Analysis
-------------------------------------

* :doc:`/trainings/material/soup/cmake/advanced/testing`
* OpenCppCoverage
* Sonarqube
* *Exercise*

Multiplatform (And Cross) Development
-------------------------------------

* Architecture/platform specific settings: best practices, and
  problems to avoid
* :doc:`/trainings/material/soup/linux/toolchain/cross/basics`
* :doc:`/trainings/material/soup/linux/toolchain/cmake/cross`

Code Generators
---------------

* Problems and limitations |longrightarrow| dependencies in generated
  code
* Possibilities

  * Code generation through CMake itself
  * Code generation in the backend build tool

* Example: generating stubs using Mico (www.mico.org)
* *Exercise*

Architectural Considerations
----------------------------

* Common build configuration: toolchain setting (compiler versions,
  compiler and linker flags, commandline macros, ...)
* Dependency management
* Relation with version control
* (Linux only) Shared library versioning, ABI
* Packaging and staging (preparing an installable image by installing
  into a staging area)
