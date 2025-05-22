.. include:: <mmlalias.txt>


Coroutines: An Overview
=======================

.. contents::
   :local:

Foreword
--------

.. sidebar:: Documentation

   * `Coroutines
     <https://en.cppreference.com/w/cpp/language/coroutines>`__
   * `std::generator
     <https://en.cppreference.com/w/cpp/coroutine/generator>`__

* A "function" that is not a function
* Entered multiple times (what?)

  * |longrightarrow| Suspended and resumed

* *"Stackless"* (whatever that means)
* Use case: Async

  * Looks like blocking, but isn't
  * *Event loop*, but without callbacks
  * Multithreading replacement
  * Much like Python's ``asyncio``
  * |longrightarrow| `Boost.Asio
    <https://www.boost.org/doc/libs/1_82_0/doc/html/boost_asio.html>`__

* Use case: `generators
  <https://en.cppreference.com/w/cpp/coroutine/generator>`__ (since
  C++23)

Prototypical Introductory Exampe: Fibonacci Numbers
---------------------------------------------------

.. toctree::
   :hidden:

   intro/fibonacci

.. sidebar::

   **Source**

   * :doc:`intro/fibonacci`

* Focus on usage
* Coroutine definition

  .. code-block:: c++

     Fibonacci fibonacci()
     {
         co_yield ...;
     }

* Coroutine instantiation

  .. code-block:: c++

     auto fibo = fibonacci();

* Coroutine usage |longrightarrow| Range-based-for on a generator?

Step By Step: Simplest
----------------------

**What I want is ...**

.. code-block:: c++

   Coro hello()
   {
       std::cout << "Hello" << std::endl;
       co_return;
   }
   
   int main()
   {
       auto hello_instance = hello();
       return 0;
   }

Simplest: Incremental Fixing And Explaining
-------------------------------------------

.. toctree::
   :hidden:

   intro/simplest

.. sidebar::

   **Source**

   * :doc:`intro/simplest`

* ``promise_type``: expected by the compiler

.. code-block:: c++

   #include <coroutine>
   struct Coro {
       struct promise_type
       {
           Coro get_return_object() { return {}; }
           std::suspend_always initial_suspend() { return {}; }
           std::suspend_always final_suspend() noexcept(true) { return {}; }
           void return_void() {}        
           void unhandled_exception() {}
       };
   };
   
* ``get_return_object()``: inserted be compiler when coroutine is
  *instantiated* (``hello()``)
* ``initial_suspend()``: don't execute any code before somebody calls
  ``resume()``
* ``final_suspend()``: don't execute any code after falling off the
  end
* ``void return_void()``: apparently that is another customization
  point
* ``void unhandled_exception()``: ideally an exception should be
  propagated to the caller (we ignore it)

**Try it out**

* Nothing happens |longrightarrow| "Hello" not printed
* Replace ``initial_suspend()`` return type to ``std::suspend_never``
* |longrightarrow| "Hello" printed
* Background: *customization*

  * ``<coroutine>`` is a set of building blocks
  * Async
  * Generators
  * ...

Driving Coroutines: Coroutine Anatomy
-------------------------------------

.. code-block:: c++

   auto hello_instance = hello();

* Coroutine object created *magically* (``Coro`` is only a wrapper
  type)
* Must be stored *somewhere*
* Associated with a ``promise_type`` object
* Coroutine type: ``std::coroutine_handle<promise_type>``
* Retrieving the coroutine object by ``promise_type``:
  ``std::coroutine_handle<promise_type>::from_promise(promise_type&)``
* Customization point: ``get_return_object()``

Driving Coroutines: Resuming
----------------------------

* Transform ``Coro`` into a class
* Add ``Coro`` member: ``std::coroutine_handle<promise_type> _coro``
* ``Coro::resume()``
* Call in ``main()``
* |longrightarrow| resumed until ``co_return``

.. literalinclude:: intro/resume.cpp
   :language: c++
   :caption: `Download resume.cpp <intro/resume.cpp>`

Suspension: Returning Control To Caller (``co_yield``)
------------------------------------------------------

.. toctree::
   :hidden:

   intro/suspend

.. sidebar::

   **Source**

   * :doc:`intro/suspend`

* ``co_yield``: returns control to coroutine caller
* ``.resume()``: re-enters coroutine - *this is the definition of
  coroutines*

.. code-block:: c++

    struct promise_type
    {
        std::suspend_always yield_value(std::string);
    }

.. code-block:: c++

   Coro hello()
   {
       std::cout << "Saying Hello" << std::endl;
       co_yield "Hello";
       std::cout << "Not Saying Bye" << std::endl;
       co_return;
   }
   
   int main()
   {
       auto hello_instance = hello();
       hello_instance.resume();                           // <--- yields into promise
       auto value = hello_instance.last_value();          // <--- get yielded value from promise
       std::cout << "coro produced: " << value << std::endl;
       hello_instance.resume();                           // <--- terminate: resume until co_return
       return 0;
   }

* Customization point: ``yield_value()``
* ``co_yield`` parameter ideally stored in promise object

  * Made available though wrapper class ``Coro``

Playing Around: Iteration, Mimicking Python Iterator Protocol
-------------------------------------------------------------

.. toctree::
   :hidden:

   intro/suspend-next

.. sidebar::

   **Source**

   * :doc:`intro/suspend-next`

* ``Coro::StopIteration``
* ``Coro::next()``
* Iteration ...

  .. code-block:: c++

     while (true) {
         try {
             std::cout << hello_instance.next() << std::endl;
         }
         catch (const Coro::StopIteration&) {
             break;
         }
     }

Playing Around: Iteration, Range-Based-For
------------------------------------------

.. toctree::
   :hidden:

   intro/suspend-iter

.. sidebar::

   **Source**

   * :doc:`intro/suspend-iter`

.. sidebar:: 

   **See also**

   * :doc:`/trainings/material/soup/cxx11/range-for/range-based-for`

* ``Coro``'s own iterator

  .. code-block:: c++

     struct sentinel {};
     struct iterator
     {
         std::coroutine_handle<promise_type> coro;
         bool operator==(sentinel) const { return coro.done(); }
         iterator& operator++()
         {
             coro.resume();
             return *this;
         }
         std::string operator*() const
         {
             return coro.promise().last_value;
         }
     };
 
     iterator begin() const { return {std::coroutine_handle<promise_type>::from_promise(*_promise)}; }
     sentinel end() const { return {}; }

* Iteration ...

  .. code-block:: c++

     for (auto elem: hello_instance)
         std::cout << elem << std::endl;

* **Bug fix**: ``std::suspend_never()`` must have return type
  ``std::suspend_never``!

Playing Around: Generic Generator
---------------------------------

.. toctree::
   :hidden:

   intro/generator-h
   intro/generator-hello

.. sidebar::

   **Source**

   * :doc:`intro/generator-h`
   * :doc:`intro/generator-hello`

* Future of C++: more tooling
* Writing all that coroutine glue is not for beginners
* |longrightarrow| ``Generator<T>``
* (Simply replace ``Coro`` with a template)
* A future C++ version will deduce coroutine type to just that
  ``Generator<T>`` (or similar)

Playing Around: Fibonacci Numbers, Generator Version
----------------------------------------------------

.. toctree::
   :hidden:

   intro/fibo-generator

.. sidebar::

   **Source**

   * :doc:`intro/fibo-generator`

* Using ``Generator<T>`` for fibonacci coroutine (see beginning)

Pitfalls: Coroutines Are Stateful!
----------------------------------

* Debugging is close to impossible
* |longrightarrow| Get it right from the beginning
* Pitfall (only one of many, I'm certain):

  **Don't access coroutine parameters by reference!**

**Broken version**

.. literalinclude:: intro/cycle-broken.cpp
   :language: c++
   :caption: `Download cycle-broken.cpp <intro/cycle-broken.cpp>`

**Fixed version**

(Move is ok too, clearly)

.. literalinclude:: intro/cycle-fixed.cpp
   :language: c++
   :caption: `Download cycle-fixed.cpp <intro/cycle-fixed.cpp>`

Links
-----

* `C++20’s Coroutines for Beginners - Andreas Fertig - CppCon 2022
  <https://youtu.be/8sEe-4tig_A>`__

  .. raw:: html
  
     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/8sEe-4tig_A" 
  	   title="YouTube video player" 
  	   frameborder="0" 
  	   allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
  	   allowfullscreen>
     </iframe>

* `Deciphering C++ Coroutines - A Diagrammatic Coroutine Cheat Sheet -
  Andreas Weis - CppCon 2022 <https://youtu.be/J7fYddslH0Q>`__

  .. raw:: html
  
     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/J7fYddslH0Q" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>
