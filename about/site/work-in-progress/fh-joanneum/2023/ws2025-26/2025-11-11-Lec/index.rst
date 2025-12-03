.. include:: <mmlalias.txt>


2025-11-11 (3 Lec): Processes, Project Management
=================================================

Project
-------

`Task list
<https://github.com/orgs/FH-STECE2023-Org/projects/3/views/1?filterQuery=has%3Atype>`__

``override``
------------

.. topic:: See also

   * :doc:`/trainings/material/soup/cxx/cxx11/oo/override`

In ``input-switch-gpio-sysfs.h`` ...

.. code-block:: c++

   State get_state() override;

Weil sonst kommt ein depp daher, versteht nicht warum ein lesen ueber
hardware protokoll unweigerlich eine schreiboperation zur folge hat
und deswegen nicht const sein kann, und der depp kommt nun und
schreibt im interface const dazu.

* Compiler warnt eh schon ...
* Aendern ``override`` viel schoener jetzt

Liskow Substitution Principle (And All Others)
----------------------------------------------

.. topic:: See also

   * :doc:`/trainings/material/soup/cxx/cxx-design-patterns/oo-principles`

* Is the sysfs IO usable as per liskow
* How about export? in the ctor?

Event Driven Programming
------------------------

From :doc:`/trainings/material/soup/linux/sysprog/index`

* :doc:`/trainings/material/soup/linux/sysprog/eventloop/problem/index`
* :doc:`/trainings/material/soup/linux/sysprog/eventloop/poll/index`
* :doc:`/trainings/material/soup/linux/sysprog/eventloop/poll-cpp/index`
* :doc:`/trainings/material/soup/linux/sysprog/eventloop/exercise-graceful-termination/index`
* :doc:`/trainings/material/soup/linux/sysprog/eventloop/exercise-commit-rollback/index`
