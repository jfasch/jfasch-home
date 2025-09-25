add_executable(sysprog-signals-simple-handler simple-handler.cpp)
add_executable(sysprog-signals-ignore-term ignore-term.cpp)
add_executable(sysprog-signals-ignore-term-int ignore-term-int.cpp)
add_executable(sysprog-signals-eintr eintr.cpp)
add_executable(sysprog-signals-eintr-wait-keypress eintr-wait-keypress.cpp)
add_executable(sysprog-signals-eintr-manual-restart eintr-manual-restart.cpp)
add_executable(sysprog-signals-eintr-auto-restart eintr-auto-restart.cpp)
add_executable(sysprog-signals-async-signal-unsafe async-signal-unsafe.cpp)
add_executable(sysprog-signals-sigmask sigmask.cpp)
add_executable(sysprog-signals-sigpending sigpending.cpp)

# realtime signals
# ----------------

# * use victim-block-pending.cpp, and send SIGUSR1 *twice*
# * -> only delivered once

# * replace SIGTERM with SIGRTMIN+1
# * see how rt signal is queued

# draw sketch

add_executable(sysprog-signals-rtsig-queued rtsig-queued.cpp)
