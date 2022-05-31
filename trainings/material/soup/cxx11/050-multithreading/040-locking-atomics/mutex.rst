.. ot-topic:: cxx11.multithreading.mutex
   :dependencies: cxx11.multithreading.race_conditions, 
		  linux.sysprog.posix_threads.mutex

.. include:: <mmlalias.txt>


``std::mutex`` And Friends
==========================

.. contents::
   :local:

``std::mutex``
--------------

.. sidebar::
   
   **Documentation**

   * `std::mutex <https://en.cppreference.com/w/cpp/thread/mutex>`__

* Simplest mutual exclusion device
* Can be taken only once
* *Not* recursive |longrightarrow| self-deadlock when same thread
  tries to lock twice

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Operation
     * Description
   * * Constructor
     * * Default only
   * * ``lock()``
     * Locks, potentially suspending caller if locked by somebody else
   * * ``unlock()``
     * Unlocks
   * * ``try_lock()``
     * Does not block; returns ``true`` if successful, ``false``
       otherwise

       *Use is questionable though!*

``std::recursive_mutex``
------------------------

.. sidebar::
   
   **Documentation**

   * `std::recursive_mutex <https://en.cppreference.com/w/cpp/thread/recursive_mutex>`__

* Same thread may lock one mutex multiple times
* *Must unlock as many times!*

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Operation
     * Description
   * * Constructor
     * * Default only
   * * ``lock()``
     * Locks, potentially suspending caller if locked by somebody else
   * * ``unlock()``
     * Unlocks
   * * ``try_lock()``
     * Does not block; returns ``true`` if successful, ``false``
       otherwise

       *Use is questionable though!*

``std::timed_mutex``
--------------------

.. sidebar::
   
   **Documentation**

   * `std::timed_mutex
     <https://en.cppreference.com/w/cpp/thread/timed_mutex>`__

* Like ``std::mutex``, only with ``try_lock()`` timeouts

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Operation
     * Description
   * * ``try_lock_for()``
     * Blocks if unavailable, and returns ``false`` if not available
       some duration into the future
   * * ``try_lock_until()``
     * Timeout occurs at an absolute ``time_point`` in the future

``std::recursive_timed_mutex``
------------------------------

.. sidebar::
   
   **Documentation**

   * `std::recursive_timed_mutex
     <https://en.cppreference.com/w/cpp/thread/recursive_timed_mutex>`__

...
