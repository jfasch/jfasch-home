.. include:: <mmlalias.txt>

Spinlock (vs. Mutex) (Screenplay)
=================================

.. contents::
   :local:

Simple Spinlock Usage: ``spin_lock()``
--------------------------------------

* Replace ``struct mutex`` with ``spinlock_t``
* Use plain ``spin_lock()``
* Test

  * Two tight loop injecting events via ``ioctl()``
  * Generate interrupts in parallel
  * |longrightarrow| hang sooner or later

Discuss Call Chain, IRQ State
-----------------------------

* Event: spin lock taken from ISR directly, top-level
* What if caller already holds a spinlock?
* |longrightarrow| ``spin_unlock()`` *unconditionally* reenables
  interrupts
* |longrightarrow| conversely, ``spin_lock()`` *unconditionally*
  disables interrupts

Enter ``spin_lock_irqsave()``, ``spin_unlock_irqrestore()``
-----------------------------------------------------------

* Fix
* Test
* Gone
