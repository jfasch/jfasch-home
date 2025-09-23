TODO
====

* fill :ref:`sysprog-filedesc-alloc` in
  :doc:`/trainings/material/soup/linux/sysprog/file-io/file-descriptors/index`
* signals

  * traditional/async delivery (-> on return from syscall)
  * when called: 

    * `man -s 2 sigreturn
      <https://man7.org/linux/man-pages/man2/sigreturn.2.html>`__

      "If the Linux kernel determines that an unblocked signal is
      pending for a process, then, at the next transition back to user
      mode in that process (e.g., upon return from a system call or
      when the process is rescheduled onto the CPU), it creates a new
      frame on the user-space stack"

  * catch SIGTERM

    * debug output -> async signal safety
    * should exit somehow, in the handler or gracefully
    * if not -> SIG_IGN
    * install SIG_IGN for SIGINT 

      * show SIGKILL (sigaction error on ign SIGKILL?)
      * send SIGSEGV

  * fork(): disposition inherited
  * EINTR
  * realtime signals

  * strsignal

