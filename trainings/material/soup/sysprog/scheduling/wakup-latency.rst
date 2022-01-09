.. ot-topic:: sysprog.scheduling.wakeup_latency
   :dependencies: sysprog.scheduling.basics

.. include:: <mmlalias.txt>


Wakeup Latency, CPU Frequency (Gotcha)
======================================

.. contents::
   :local:

Measuring Wakeup Latency
------------------------

.. literalinclude:: code/jitter.py
   :caption: :download:`code/jitter.py`

On a Raspberry Pi 4B, this gives ...

.. code-block:: console

   $ ./jitter.py 0.01 100
   mean: 0.000105s (0.105247ms, 105.24749755859354us)
   stdev: 0.000015s (0.014643ms, 14.64260525619006us)
   
* Wakeup time: from timer interrupt (handled inside the kernel) to
  userspace code
* Results show: a sleep of 10ms wakes up 105us late on average

Many Runnable Processes (Gotcha: CPU Frequency Scaling)
-------------------------------------------------------

Add tons of runnable processes

.. code-block:: console

   $ for i in $(seq 30); do sha1sum  /dev/zero& done

See how wakeup behaves. Expecting that wakeup time increases (alas,
more processes want their share)

.. code-block:: console

   $ ./jitter.py 0.01 100
   mean: 0.000067s (0.067263ms, 67.2626495361326us)
   stdev: 0.000003s (0.002883ms, 2.8827592917392217us)

**WHAT?** Wakeup time decreases as more processes are runnable?

* Gotcha: CPU frequency scaling (``ondemand`` governor)
* CPU bound processes make CPUs run faster

.. note::

   When wakeup latency is an issue, power saving is not a good idea!

CPU Frequency Scaling Out Of The Way
------------------------------------

Exchange ``ondemand`` governor with ``performance`` governor

.. code-block:: console

   # for i in $(seq 0 3); do 
   >   echo performance > /sys/devices/system/cpu/cpu$i/cpufreq/scaling_governor
   > done

CPUs run at maximum speed

.. code-block:: console

   # cat /sys/devices/system/cpu/cpu*/cpufreq/cpuinfo_cur_freq 
   1500000
   1500000
   1500000
   1500000

Kill CPU eaters

.. code-block:: console

   $ killall sha1sum

So how latency goes

.. code-block:: console

   $ ./jitter.py 0.01 100
   mean: 0.000067s (0.067036ms, 67.03615188598611us)
   stdev: 0.000001s (0.001257ms, 1.2571678380193383us)

*Voila!* Same as before, but without CPU (h)eaters

.. code-block:: console

   $ for i in $(seq 30); do sha1sum  /dev/zero& done
   $ ./jitter.py 0.01 100
   mean: 0.000065s (0.065188ms, 65.188407897949us)
   stdev: 0.000002s (0.002376ms, 2.3758434034066656us)

And the same as with the (h)eaters

Mysteries Remaining
-------------------

* Not everything is easily explainable though
* Apparently longer sleep times increase wakeup latency
* Naive explanation: to wake somebody from a deep sleep takes longer
  (not so naive though)

.. code-block:: console

   $ ./jitter.py 1 100
   mean: 0.001042s (1.042438ms, 1042.4375534057617us)
   stdev: 0.000017s (0.017123ms, 17.123423079175748us)
   $ ./jitter.py 0.1 100
   mean: 0.000143s (0.142646ms, 142.6458358764593us)
   stdev: 0.000005s (0.004995ms, 4.994855006705264us)
