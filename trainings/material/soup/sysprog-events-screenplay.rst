.. jf-screenplay:: sysprog-events

.. meta::
   :description: This live-hacking screenplay is a guide for myself to
                 repeatably, didactically, demonstrate how event
                 driven programming works on Linux
   :keywords: linux, systemnah, schulung, training, programming,
              events, select, poll, epoll, posix, device, timer,
              timerfd, signal, signalfd, eventfd

Screenplay: Sysprog: POSIX IPC
==============================

.. sidebar:: Contents

   .. contents::
      :local:

   **Code**: :doc:`sysprog-events-code/index`

`select` on Device Files
------------------------

.. literalinclude:: sysprog-events-code/010-select-devices.cc
   :caption: :download:`sysprog-events-code/mq/010-select-devices.cc`
   :language: c++

