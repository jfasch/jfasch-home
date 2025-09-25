# self pipe
# ---------

# * handling signals in process context
# * often used in conjunction with event driven programming
# * better: signalfd(), but Linux-specific

add_executable(sysprog-signals-self-pipe self-pipe.cpp)
