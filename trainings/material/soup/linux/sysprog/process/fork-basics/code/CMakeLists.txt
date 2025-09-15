# ---
# basic fork: blah returns twice. warning about code flow; everything
# is possible.
add_executable(sysprog-fork-basic basic.cpp)

# ---
# code leakage demo
add_executable(sysprog-fork-leak-code-flow leak-code-flow.cpp)

# ---
# omit output in child. parent is sufficient to get hold of both pids.

# what if both read from the same fd? (e.g. STDIN_FILENO)
# * fd inheritance semantics
# * -> see dup, dup2
# * which one wakes up is UNDEFINED

# show 
# $ echo -n ab > /tmp/input-file
# $ ./sysprog-fork-stdin-inherited-undefined < /tmp/input-file 

add_executable(sysprog-fork-stdin-inherited-undefined stdin-inherited-undefined.cpp)

# --- shared memory? No, COW!

# temporarily pull out one_byte into main() scope. what does that
# mean? do we share one_byte in two different processes?

# * short overview of COW (private memory)
# * -> see mmap, and shared memory in general

# SKETCH!!

# --- Caring for the kids: wait (and friends)

# let child wait for input on STDIN_FILENO, and parent do a wait on
# child
add_executable(sysprog-fork-wait wait.cpp)

# --- wait, and status

# modify child "return 42 from mainP" to exit(42)
# * see what wait(&status) is
# * -> print bitmask
# * next step: use macros
add_executable(sysprog-fork-wait-status wait-status.cpp)

# --- wait, and status other than WIFEXITED()

# modify wait() -> waitpid(-1 (or child pid), &status, WUNTRACED|WCONTINUED)

# * waitpid

#   * explicit pid (-1 for any)
#   * options

# * WIFSIGNALED

#   show
#   $ kill -TERM ...
#   $ kill -SEGV ...     (128 is true)

# * WIFSTOPPED
# * WIFCONTINUED

#   both in a loop:
#   $ kill -STOP ...
#   $ kill -CONT ...

add_executable(sysprog-fork-wait-status-alternatives wait-status-alternatives.cpp)

# --- list of signals (from PDFs?)

# --- Consequences of not caring for kids: zombie

# let child terminate
# see how child pid still there in ps
# -> <defunct>
# kill incompetent parent
# -> reparented
# -> zombie reaped by new parent

add_executable(sysprog-fork-zombie zombie.cpp)


# --- reparenting

# * until now we have taken care of child termination
# * what if parent terminates? child without parent? 
# * reparenting (c/v orphanage)

# * let parent process terminate
# * see how child is still alive
# * has been reparented to some systemd session manager (who is already responsible for many children)

# history -> pid 1
# nowadays (linux specific) -> child reaper
# https://man7.org/linux/man-pages/man2/PR_SET_CHILD_SUBREAPER.2const.html

add_executable(sysprog-fork-reparenting reparenting.cpp)
