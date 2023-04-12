.. include:: <mmlalias.txt>


``asyncio`` Overview
====================

.. contents::
   :local:

Multiple Background Threads
---------------------------

* 0.5s ``"hello left"``
* 0.8s ``"hello right"`` (``str.rjust(60)``)
* 1s ``"hello middle"`` (``str.center(60)``)

.. literalinclude:: code/thread-multi.py
   :caption: :download:`code/thread-multi.py`
   :language: python

.. code-block:: console

   $ strace -f python3 code/thread-multi.py
   ...
   [pid  4677] write(1, "hello left\n", 11hello left
   ) = 11
   [pid  4677] clock_gettime64(CLOCK_MONOTONIC, {tv_sec=164646, tv_nsec=833862215}) = 0
   [pid  4677] _newselect(0, NULL, NULL, NULL, {tv_sec=0, tv_usec=500000} <unfinished ...>
   [pid  4679] <... _newselect resumed>)   = 0 (Timeout)
   [pid  4679] write(1, "                        hello mi"..., 61                        hello middle                        
   ) = 61
   [pid  4679] clock_gettime64(CLOCK_MONOTONIC, {tv_sec=164646, tv_nsec=845864201}) = 0
   [pid  4679] _newselect(0, NULL, NULL, NULL, {tv_sec=1, tv_usec=0} <unfinished ...>
   [pid  4678] <... _newselect resumed>)   = 0 (Timeout)
   [pid  4678] write(1, "                                "..., 61                                                 hello right
   ) = 61

* Three independent PIDs, using ``select()`` to implement
  ``time.sleep()`` (``NULL`` fds)
* Managed by OS scheduler
* |longrightarrow| scheduling jitter, heavy (?) OS load

Enter ``asyncio``
-----------------

* Replace ``threading`` and ``time`` with ``asyncio``
* ``async`` functions, ``await asyncio.sleep(...)``
* ``async def main()``
* ``asyncio.run(main())``

.. literalinclude:: code/async-multi.py
   :caption: :download:`code/async-multi.py`
   :language: python

.. code-block:: console

   $ strace -f code/async-multi.py
   ...
   epoll_wait(3, [], 1, 201)               = 0
   ...

* *Single thread!*
* Timeouts apparently multiplexed on the *event loop's* timeout
  parameter
