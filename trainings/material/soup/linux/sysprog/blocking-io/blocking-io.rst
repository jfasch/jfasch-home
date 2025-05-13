.. include:: <mmlalias.txt>


Blocking I/O: What is That? ("Everything is a file")
====================================================

.. contents::
   :local:

.. sidebar:: Examples/Live Demos

   * :doc:`blocking-io-file`
   * :doc:`blocking-io-network`
   * :doc:`blocking-io-timer`

Problem
-------

Communication with hardware is rarely *synchronous*

* Initiate an action: "Hey, disk: move heads to position
  such-and-such"
* Do something else (?) until action is complete |longrightarrow|
  *interrupt*
* React; for example: setup DMA to receive data from disk heads
* Do something else (?) until DMA is complete |longrightarrow|
  interrupt

.. danger::

   Nobody wants to do this in day-to-day code!

Solution: This Is What An Operating System Is There For
-------------------------------------------------------

*Say what you want:*

* Open a file, for example, such as ``/etc/passwd``. Do not bother me
  with asynchronicity, like ...

  * I don't have anything else to do in the meantime, so I don't want
    to be *notified*. *Me stupid!*
  * I just want to sit there until everything is complete (don't want
    to think about what "Everything" is)
  * When all is fine, I want a *handle* to that open file
  * When nothing's fine, I want an error

* Read me ``n`` bytes into a buffer I supply. *Again, no
  asynchronicity, please!*
* |longrightarrow| **Simplicity rules!**
* |longrightarrow| **The "File" Abstraction!**
* **Question**: who's *me*? |longrightarrow| a process

