.. include:: <mmlalias.txt>

.. ot-topic:: cxx03.stl.sequential_containers
   :dependencies: cxx03.stl.searching


Sequential Containers
=====================

Characteristics of ``std::vector<>``
------------------------------------

``std::vector<>`` is an efficient sequential container because ...

* Organization: contiguous memory |longrightarrow| perfect utilization
  of processor caches
* Appending is performs liek with strings (logarithmic time)

But ...

* Removal at arbitrary position is slow
* Insertion at arbitrary position is slow
* |longrightarrow| Unwanted copies

``std::vector<>``: Modification at the Back
-------------------------------------------

.. list-table::

   * * * Appending at the back
     
         * There is room $\to$ immediate
	 * No room |longrightarrow| allocate (double the space), copy over, and append

       * Removing from the back

         * Immediate
         * ``capacity()`` remains same
         * ``size()`` decremented by one

     * 

       .. image:: 40-35-00-vector-push-back.dia

``std::vector<>``: Insertion
----------------------------

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

``std::list<>``: Insertion and Deletion
---------------------------------------

.. list-table::

   * * * Insertion at arbitrary position

         * Pointer rearrangement |longrightarrow| constant time

       * Deletion at arbitrary position

	 * Pointer rearrangement |longrightarrow| constant time

     * 

       .. image:: 40-35-00-list.dia

