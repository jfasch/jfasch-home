TODO
====

* fill :ref:`sysprog-filedesc-alloc` in
  :doc:`/trainings/material/soup/linux/sysprog/file-io/file-descriptors/index`
* signals / async

  * traditional/async delivery (-> on return from syscall)
  * when called: 

    * `man -s 2 sigreturn
      <https://man7.org/linux/man-pages/man2/sigreturn.2.html>`__

      "If the Linux kernel determines that an unblocked signal is
      pending for a process, then, at the next transition back to user
      mode in that process (e.g., upon return from a system call or
      when the process is rescheduled onto the CPU), it creates a new
      frame on the user-space stack"

* events

  * link from :doc:`signals/intro/index` signalfd
  * link from :doc:`signals/async/index` ``EINTR`` handling
  * link from :doc:`signals/async-self-pipe/index` (more with signals)
  * signalfd: link from

    * :doc:`/trainings/material/soup/linux/sysprog/signals/sync/index`
    * :doc:`/trainings/material/soup/linux/sysprog/signals/signalfd/index`

* replace ``sidebar`` with ``topic`` (better for mobile)
