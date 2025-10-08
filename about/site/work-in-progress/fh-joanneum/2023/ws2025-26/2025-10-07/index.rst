.. include:: <mmlalias.txt>


2025-10-07 (3 VO): Semester Kickoff
===================================

Quiz
----

Project Management
..................

.. list-table::
   :align: left
   :header-rows: 1
   :widths: 70 10 10 10

   * * Topic
     * Weak
     * Intermediate
     * Strong
   * * **CMake**

       * :ref:`2025-06-16 Nodes and dependencies
         <fh-2025-06-16-cmake-nodes-dependencies>`
       * :ref:`2025-06-16 Include paths
         <fh-2025-06-16-cmake-include-path>`

     * 
     *
     *
   * * **Git**

       * :ref:`2025-05-12 Git Basics <fh-2025-05-12-some-git>`
       * :ref:`2025-05-20 Git remote workflow
         <fh-2025-05-20-git-remote-workflow>`

     * 
     *
     *

C/C++
.....

.. list-table::
   :align: left
   :header-rows: 1
   :widths: 70 10 10 10

   * * Topic
     * Weak
     * Intermediate
     * Strong
   * * **Interfaces and implementation**

       * :ref:`Polymorphic types <fh-2025-05-19-polymorphic>`
       * :ref:`Interfaces <fh-2025-06-02-interfaces>`

     * 
     *
     *
   * * **References, and** ``const``

       * :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/050-references/topic`

     * 
     *
     *
   * * **Constructors, Destructors**
     * 
     *
     *

Linux
.....

.. list-table::
   :align: left
   :header-rows: 1
   :widths: 70 10 10 10

   * * Topic
     * Weak
     * Intermediate
     * Strong
   * * **Shell usage (files and directories, permissions)**

       * :doc:`/about/site/work-in-progress/fh-joanneum/2023/ss2025/2025-04-28/index`
       * :doc:`/about/site/work-in-progress/fh-joanneum/2023/ss2025/2025-05-06/index`

     * 
     *
     *
   * * **System calls, file IO, processes, error handling**
     * 
     *
     *
   * * **I2C** 
     * 
     *
     *
   * * **GPIO** (``libgpiod`` |:thumbsdown:|)
     * 
     *
     *

Semester Plan
-------------

More Linux (Systems Programming)
................................

.. topic:: Material

   From :doc:`/trainings/material/soup/linux/sysprog/index`
   
   * :doc:`/trainings/material/soup/linux/sysprog/syscalls-and-errors/index`
   * :doc:`/trainings/material/soup/linux/sysprog/file-io/index`
   * :doc:`/trainings/material/soup/linux/sysprog/process/index`
   * :doc:`/trainings/material/soup/linux/sysprog/signals/index`
   * :doc:`/trainings/material/soup/linux/sysprog/eventloop/index`

Process Creation/Lifetime
`````````````````````````

Use case: blocking on sensor readout. 

If, for example, a sensor takes 100ms to give the value that it
measures, this might keep other parts of the software from reacting
fast enough. *It blocks the entire control program*, leading to all
sorts of misbehavior (e.g. motor stops too late)

*Solution:* create a subprocess which does the sensor
readout. Communicate the value to the main/parent process.

Graceful Termination
````````````````````

When a process is requested to terminate (``Ctrl-C`` on the console,
or by ``kill``-ing it), the process's default behaviour is to just
exhaust its life immediately. For a nontrivial control program, this
might be too abrupt - it might want to do cleanup such as closing
files (databases?), terminating child/worker processes, etc.

No Busy Loops
`````````````

*A tight polling loop of 1ms is not friendly*. Lets save resources by
doing nothing when there is nothing to do, and learn how to react
intelligently on multiple event sources.

More C++
........

Ownership
`````````

.. topic:: Material

   From :doc:`/trainings/material/soup/cxx/cxx11/index`:

   * :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/index`
   * :doc:`/trainings/material/soup/cxx/cxx11/rule-of-5/topic`

This code from the main executable, `run-door.cpp
<https://github.com/jfasch/FH-STECE2023/blob/main/bin/run-door.cpp>`__,
has a number of shortcomings:

.. code-block:: c++

   InputSwitchMock button1(InputSwitch::State::INPUT_LOW);
   InputSwitchMock button2(InputSwitch::State::INPUT_LOW);
   InputSwitchMock light1(InputSwitch::State::INPUT_LOW);
   InputSwitchMock light2(InputSwitch::State::INPUT_HIGH);
   MotorMock motor(Motor::Direction::IDLE);

   Inputs inputs(&button1, &button2, &light1, &light2, time);
   Outputs outputs(&motor);

* ``Inputs`` and ``Outputs`` get passed *pointers* to their delegees,
  and *pointers are bad*
* The lifetime of ``InputSwitchMock`` and ``MotorMock`` is
  *automatic* (on main's stack frame). In less obvious code (the
  default) this can easily go wrong.

Lets decide on ownership semantics, and learn about C++11 *smart
pointers* ``std::unique_ptr`` and ``std::shared_ptr``. Also shed
some light on ownership rules, and how C++ tries really hard to
shoot you in the foot.

Bells and Whistles (Pythonicity)
````````````````````````````````

.. topic:: Material

   From :doc:`/trainings/material/soup/cxx/cxx11/index`:

   * :doc:`/trainings/material/soup/cxx/cxx11/auto/topic`
   * :doc:`/trainings/material/soup/cxx/cxx11/control-flow-locals/topic`
   * :doc:`/trainings/material/soup/cxx/cxx11/structured-binding/topic`
   * :doc:`/trainings/material/soup/cxx/cxx11/range-for/index`
   * :doc:`/trainings/material/soup/cxx/cxx11/lambda/index`?
   * Maybe (much) more

C++ is awful. C++11 (and onwards) tries to make it a better language
(but fails). Learn about the funky new stuff.

Today's Material
----------------

Error Handling Recap
....................

* :doc:`/trainings/material/soup/linux/sysprog/syscalls-and-errors/errorhandling/index`

File IO Recap
.............

* :doc:`/trainings/material/soup/linux/sysprog/file-io/open-read-write-close/overview`
* :doc:`/trainings/material/soup/linux/sysprog/file-io/open-read-write-close/example-O_RDONLY`
* :doc:`/trainings/material/soup/linux/sysprog/file-io/open-read-write-close/example-O_WRONLY`

Positions, And Duplicating
..........................

* :doc:`/trainings/material/soup/linux/sysprog/file-io/lseek/index`
* :doc:`/trainings/material/soup/linux/sysprog/file-io/dup/index`
