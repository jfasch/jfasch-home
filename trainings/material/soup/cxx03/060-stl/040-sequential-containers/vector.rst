.. ot-topic:: cxx03.stl.sequential_containers.vector
   :dependencies: cxx03.stl.sequential_containers.basics

.. include:: <mmlalias.txt>


``vector<>``
============

.. sidebar:: Documentation
  
   * `std::vector <https://en.cppreference.com/w/cpp/container/vector>`__
     @ `cppreference.com <https://cppreference.com>`__
   * `std::vector
     <http://www.cplusplus.com/reference/vector/vector/>`__ @
     `cplusplus.com <https://cplusplus.com>`__

.. contents::
   :local:


Characteristics
---------------

``std::vector<>`` is an efficient sequential container because ...

* Organization: contiguous memory |longrightarrow| perfect utilization
  of processor caches
* Appending is performs liek with strings (logarithmic time)

But ...

* Removal at arbitrary position is slow
* Insertion at arbitrary position is slow
* |longrightarrow| Unwanted copies

Modification at the Back
------------------------

.. list-table::

   * * * Appending at the back
     
         * There is room |longrightarrow| immediate
	 * No room |longrightarrow| allocate (double the space), copy over, and append

       * Removing from the back

         * Immediate
         * ``capacity()`` remains same
         * ``size()`` decremented by one

     * 

       .. image:: 40-35-00-vector-push-back.dia

Insertion
---------

.. list-table::

   * * **Performance is miserable!**


       * Insert at arbitrary position

	 * All elements from there on have to be shifted (copied) toward the
           end by one position
	 * Reallocation is also possible

       * Removal at arbitrary position

	 * All elements from there have to be copied one down

     * 

       .. image:: 40-35-00-vector-insert.dia

Example
-------

.. literalinclude:: code/vector.cpp
   :caption: :download:`code/vector.cpp`
