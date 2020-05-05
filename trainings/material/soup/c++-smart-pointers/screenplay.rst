.. jf-screenplay:: c++-smart-pointers


Screenplay: C++: Smart Pointers
===============================

.. sidebar:: Contents

   .. contents::
      :local:

   **Code**: :doc:`code/index`


* copy structure and data.h from code/. start with empty test.
* fuzzy ownership. "one has to know who's owner"
* ``std::shared_ptr``: gradually transform.

  * "no known conversion" -> explain implicit conversion
    vs. ``explicit``.

    * note: ``SharedDataOwner`` ctor signature has
      ``std::shared_ptr<>`` in it. one solution is to implicitly take
      ownership, by accepting ``Data*``. *this is no win in
      readability/maintainability!*

* ``std::unique_ptr``: OMG!!

  * PDF slides: *move*
