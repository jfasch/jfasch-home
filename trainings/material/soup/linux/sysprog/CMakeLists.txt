add_subdirectory(blocking-io)
add_subdirectory(process)

add_subdirectory(scheduling/code)

add_subdirectory(sysprog_events/code)
add_subdirectory(sysprog_ipc/code)
add_subdirectory(sysprog_signals/code)

add_subdirectory(file-io)
add_subdirectory(file-locking)

add_subdirectory(mmap)
add_subdirectory(ipc-mqueue)



# ---------------- new stuff ------------------
add_subdirectory(fork)
# jjj fd, dup, dup2
# jjj mmap
# jjj signals
# jjj event loops?
