.. include:: <mmlalias.txt>


Ranges And Views: Good Or Bad?
==============================

.. contents::
   :local:

Dangling Iterator Protection
----------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/overview`

* A *range* is one object describing a ... well ... a range of
  elements
* Traditionally (pre-20), described by a pair of *iterators* ``[begin,
  end)``

  .. literalinclude:: good-bad/dangling-protection-1.cpp
     :language: c++
     :caption: :download:`Download dangling-protection-1.cpp
               <good-bad/dangling-protection-1.cpp>`

* *Ranges* do the same, using *one single object* of range (or view)
  type

  .. literalinclude:: good-bad/dangling-protection-2.cpp
     :language: c++
     :caption: :download:`Download dangling-protection-2.cpp
               <good-bad/dangling-protection-2.cpp>`

* |longrightarrow| much more possibilities

*For example ...* 

* Passing temporaries adds to readability
* ... but often also to bugginess

.. literalinclude:: good-bad/dangling-protection-3.cpp
   :language: c++
   :caption: :download:`Download dangling-protection-3.cpp
             <good-bad/dangling-protection-3.cpp>`

* ``std::ranges::dangling`` when passing an :doc:`RValue
  </trainings/material/soup/cxx11/020-new-language-features/060-move/overview>`
* |longrightarrow| *compiler error*

Performance: ``views::drop`` Is Easy
------------------------------------

* How fast can ``.size()`` be determined on a ``drop_view`` (the
  result of ``std::views::drop()``)
* |longrightarrow| It is simply a matter of subtracting 2 from the
  underlying range's ``.size()``

.. literalinclude:: good-bad/size-drop-ok.cpp
   :language: c++
   :caption: :download:`Download size-drop-ok.cpp
             <good-bad/size-drop-ok.cpp>`

Performance: ``views::filter`` Is Not Easy
------------------------------------------

* How long would ``.size()`` take on a ``filter_view``?
* |longrightarrow| *Apply* filter, and count how many are accepted
* |longrightarrow| *Rewind?*

.. literalinclude:: good-bad/size-filter-nok.cpp
   :language: c++
   :caption: :download:`Download size-filter-nok.cpp
             <good-bad/size-filter-nok.cpp>`

* Compiler error, saying that there is no ``.size()`` on it
* Trying to say that ``.size()`` cannot be computed in constant time
* |longrightarrow| **"... constraints not satisfied ..."**

.. code-block:: console

   size-filter-nok.cpp:9:27: error: no matching function for call to ‘std::ranges::filter_view<std::ranges::ref_view<std::vector<int, std::allocator<int> > >, main()::<lambda(auto:17)> >::size()’
       9 |     std::cout << even.size() << std::endl;             // <--- compiler error
         |                  ~~~~~~~~~^~
   In file included from /usr/include/c++/12/ranges:47,
                    from size-filter-nok.cpp:2:
   /usr/include/c++/12/bits/ranges_util.h:131:7: note: candidate: ‘constexpr auto std::ranges::view_interface<_Derived>::size() requires (forward_range<_Derived>) && (sized_sentinel_for<decltype(std::ranges::__cust::end((declval<_Tp&>)())), decltype(std::ranges::__cust_access::__begin((declval<_Container&>)()))>) [with _Derived = std::ranges::filter_view<std::ranges::ref_view<std::vector<int, std::allocator<int> > >, main()::<lambda(auto:17)> >]’
     131 |       size() noexcept(noexcept(_S_size(_M_derived())))
         |       ^~~~
   /usr/include/c++/12/bits/ranges_util.h:131:7: note: constraints not satisfied

Constraints: How To Read?
-------------------------

.. sidebar::

   **Documentation**

   * `forward_range
     <https://en.cppreference.com/w/cpp/ranges/forward_range>`__
     (|longrightarrow| `forward_iterator
     <https://en.cppreference.com/w/cpp/iterator/forward_iterator>`__)
   * `sized_sentinel_for
     <https://en.cppreference.com/w/cpp/iterator/sized_sentinel_for>`__

* Careful reading ...

.. code-block:: console

   candidate: ‘constexpr auto std::ranges::view_interface<_Derived>::size() requires (forward_range<_Derived>) && (sized_sentinel_for<...

* ``forward_range``: Can be iterated from beginning to end multiple
  times
* ``sized_sentinel_for``: 

  | The sized_sentinel_for concept specifies that an object of the
  | iterator type I and an object of the sentinel type S can be subtracted
  | to compute the distance between them in **constant time**.

* |longrightarrow| *A-ha!* ``.size()`` is not there because
  ``filter_view`` is **linear time**

And ``drop()``? ``std::vector`` Is Easy
---------------------------------------

* Drop 2 elements means ignoring the first two elements
* Cheap with a ``std::vector`` |longrightarrow| ``v.begin() + 2``
  (simple arithmetic)

.. literalinclude:: good-bad/drop-ok.cpp
   :language: c++
   :caption: :download:`Download drop-ok.cpp <good-bad/drop-ok.cpp>`

And ``drop()``? ``std::list`` Is Not Easy
-----------------------------------------

* Expensive with ``std::list`` |longrightarrow| manually forwarding a
  linked list to 2nd element

.. literalinclude:: good-bad/drop-nok.cpp
   :language: c++
   :caption: :download:`Download drop-nok.cpp <good-bad/drop-nok.cpp>`

* Compiler error, saying that ``print()`` cannot be instantiated
  because ...
* ``passing ‘const std::ranges::drop_view as ‘this’ argument discards
  qualifiers``

.. code-block:: console

   drop-nok.cpp: In instantiation of ‘void print(const auto:17&) [with auto:17 = std::ranges::drop_view<std::ranges::ref_view<std::__cxx11::list<int, std::allocator<int> > > >]’:
   drop-nok.cpp:14:10:   required from here
   drop-nok.cpp:7:5: error: passing ‘const std::ranges::drop_view<std::ranges::ref_view<std::__cxx11::list<int, std::allocator<int> > > >’ as ‘this’ argument discards qualifiers [-fpermissive]
       7 |     for (const auto& elem: coll)
         |     ^~~
   In file included from drop-nok.cpp:2:
   /usr/include/c++/12/ranges:2460:7: note:   in call to ‘constexpr auto std::ranges::drop_view<_Vp>::begin() requires !((__simple_view<_Vp>) && (random_access_range<const _Vp>) && (sized_range<const _Vp>)) [with _Vp = std::ranges::ref_view<std::__cxx11::list<int, std::allocator<int> > >]’
    2460 |       begin()
         |       ^~~~~

* Point is: ``drop_view`` cannot be passed as ``const`` because it
  *caches* ``begin()``
* **Bullshit**
* |longrightarrow| **ALL SORTS OF BUGS!**

One Of Many Bugs, Introduced By ``.begin()`` Caching
----------------------------------------------------

* Caching means that ``const`` is not easily pretended
* ``mutable`` is only a lie
* Everything that I expect does not hold - *at least not in any case*
* **In some cases I cannot read-only iterate a** ``const`` **range**
* **In some cases concurrent read-only iteration is not safe**
  |longrightarrow| race condition in ``.begin()``

*What is the output of the following program?*
  
.. literalinclude:: good-bad/modify-view-nok.cpp
   :language: c++
   :caption: :download:`Download modify-view-nok.cpp
             <good-bad/modify-view-nok.cpp>`

*Answer:*

.. code-block:: console

   $ ./c++11-ranges-modify-view-nok 
   5

* ``5`` is at index ``[2]`` which is cached as ex ``4`` - the first even number in the ex-vector
* |longrightarrow| *be careful!*

Exceptions From Rules |longrightarrow| Dogmatic Don'ts (Sigh, C++)
------------------------------------------------------------------

* Don't re-use views
* Don't modify collections through views
* Don't use multiple threads (not a good idea anyway)
* Many more, I'm certain - watch out!

Thanks to Nicolai Josuttis who is bashing the C++ standards comittee
in `this video <https://youtu.be/qv29fo9sUjY>`__. He is much less
polite than I am.
