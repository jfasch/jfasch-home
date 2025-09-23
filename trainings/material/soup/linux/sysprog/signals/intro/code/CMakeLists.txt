# --- process termination

# demo SIGTERM, SIGINT
add_executable(sysprog-signals-victim victim.cpp)

# --- bug

# demo SIGSEGV
add_executable(sysprog-signals-victim-segv victim-segv.cpp)

# demo fpe
# -Wno-div-by-zero
add_executable(sysprog-signals-victim-fpe victim-fpe.cpp)
target_compile_options(sysprog-signals-victim-fpe PRIVATE -Wno-div-by-zero)

# discuss core dump -> refer to wait interfaces WCOREDUMP()

# cat /proc/sys/kernel/core_pattern
# echo core > /proc/sys/kernel/core_pattern

# vs

# echo core.%p > /proc/sys/kernel/core_pattern

# --- my first signal handler

# debug output only - no effect otherwise
# async-signal-safe -> write()
add_executable(sysprog-signals-victim-simple-handler victim-simple-handler.cpp)

# --- just as well use SIG_IGN
add_executable(sysprog-signals-victim-ignore victim-ignore.cpp)

# --- EINTR

# * pause() block until signal (-> man)
add_executable(sysprog-signals-victim-eintr victim-eintr.cpp)
add_executable(sysprog-signals-victim-eintr-another-syscall victim-eintr-another-syscall.cpp)

# --- how to deal with EINTR, generally

# * from read(STDIN_FILENO, ...) to read_one_byte()

# * if (EINTR) ...

# * "restarting"

add_executable(sysprog-signals-victim-eintr-coping victim-eintr-coping.cpp)

# --- restarting syscalls

# * better than a manual restart

add_executable(sysprog-signals-victim-restart victim-restart.cpp)
