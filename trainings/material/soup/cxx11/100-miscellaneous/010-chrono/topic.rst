.. include:: <mmlalias.txt>

.. ot-topic:: cxx11.multithreading.chrono


``std::chrono``
===============

``std::chrono``
---------------

**Time is complex**

* ... and so is ``std::chrono``
* Time points, starting at Epoch

  * E.g. Good (?) old ``time_t``, in seconds since ``1970-01-01
    00:00:00``

* Multiple *clock domains*, each with their own notion of time points
  (varying in epoch and time unit)
* Duration

  * Difference between time points
  * Time point - duration between time point's epoch and itself

Clock Domains
-------------

* ``system_clock``

  * "Wall clock time", based upon the system's notation of time.
  * Unix: ``time_t``, starting ``1970-01-01``, in seconds.
  * Not monotonic - modified by e.g. NTP

* ``steady_clock``

  * Starts at arbitrary timepoint - commonly at system boot
  * *Monotonic*: advances steadily
  * E.g. POSIX's ``CLOCK_MONOTONIC``

* ``high_resolution_clock``

  * "High resolution timers" - ultimately, this is "brand new
    hardware"
  * Usually used to formulate high-precision wait periods etc.

Measuring Time (1)
------------------

**A snapshot of time:** a clock domain's ``time_point``

.. code-block:: c++
   :caption: Now

   #include <chrono>
   
   std::chrono::system_clock::time_point now = 
        std::chrono::system_clock::now();

Measuring Time (2)
------------------

**Duration:** difference between points

.. code-block:: c++
   :caption: Duration

   std::chrono::steady_clock::duration spent = after - before;
   std::chrono::milliseconds spent_milli = 
       std::chrono::duration_cast<std::chrono::milliseconds>(spent);
   std::cout << spent_milli.count() << std::endl;

.. note::

   Use ``steady_clock`` time points to compute intervals - other
   clocks are not immune against time modifications
