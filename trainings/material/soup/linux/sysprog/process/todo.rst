TODO
====

* "Process" chapter

  * what happens to open file descriptors on fork()?

    * add lseek() and off_t and whence section
    * refactor/create dup section in file-io

      * intro/file descriptors

* Refactor old crap

  * file io basics: open/read/write/close
  * file io offset: lseek, off_t, whence -> file description, referred
    to userspace by file descriptor
  * file io dup
  * refer to fileio.dup in process.fork_basics
  * do this all the time
  * distinguish between a hard dependency as implemented in
    ``:dependencies:`` and something like ``:see-also:`` or
    ``:ways-from-here``.

* restructure sysprog

  * sysprog.basics title page and structure
