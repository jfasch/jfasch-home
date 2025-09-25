# INTRO
# =====


# process termination
# -------------------

# demo SIGTERM, SIGINT
# use strace in a second run
add_executable(sysprog-signals-stupid stupid.cpp)

# bug
# ---

# demo SIGSEGV
add_executable(sysprog-signals-segv segv.cpp)

# demo fpe
# -Wno-div-by-zero
add_executable(sysprog-signals-fpe fpe.cpp)
target_compile_options(sysprog-signals-fpe PRIVATE -Wno-div-by-zero)

# discuss core dump -> refer to wait interfaces WCOREDUMP()

# cat /proc/sys/kernel/core_pattern
# echo core > /proc/sys/kernel/core_pattern

# vs

# echo core.%p > /proc/sys/kernel/core_pattern

# table with actions and dispositions
# -----------------------------------

# ASYNC DELIVERY
# ==============

# my first signal handler
# -----------------------

# debug output only - no effect otherwise
# async-signal-safe -> write()
add_executable(sysprog-signals-simple-handler simple-handler.cpp)

# ignoring
# --------

add_executable(sysprog-signals-ignore ignore.cpp)

# SIGKILL
# -------

# ignore SIGTERM and SIGINT -> SIGSEGV, SIGKILL

# EINTR
# -----

# * not for(;;), but pause

# * pause() block until signal (-> man)
add_executable(sysprog-signals-eintr eintr.cpp)
add_executable(sysprog-signals-eintr-another-syscall eintr-another-syscall.cpp)

# how to deal with EINTR, generally
# ---------------------------------

# * from read(STDIN_FILENO, ...) to read_one_byte()

# * if (EINTR) ...

# * restarting manually

add_executable(sysprog-signals-eintr-coping eintr-coping.cpp)

# restarting
# ----------

# * better than a manual restart

add_executable(sysprog-signals-restart restart.cpp)

# async signal safety
# -------------------

# * main prog does something with global list

# * SIGUSR1 does something with global list

# * pthread lock nix

# * malloc() nix safe!!!

# * block signals in main? -> no!

# list of what's safe

add_executable(sysprog-signals-async-signal-unsafe async-signal-unsafe.cpp)

# blocking async delivery, "pending"
# ----------------------------------

# * block SIGUSR1
# * send it
# * unblock
# * -> see SIGTERM delivered

# note: CALLED IMMEDIATELY after unblock, on return to userspace

# sidenote: pthread_sigmask()

add_executable(sysprog-signals-block block.cpp)

# * ask for pending signals

add_executable(sysprog-signals-block-pending block-pending.cpp)

# realtime signals
# ----------------

# * use victim-block-pending.cpp, and send SIGUSR1 *twice*
# * -> only delivered once

# * replace SIGTERM with SIGRTMIN+1
# * see how rt signal is queued

# draw sketch

add_executable(sysprog-signals-rtsig-queued rtsig-queued.cpp)
