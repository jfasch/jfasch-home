.. ot-topic:: cxx11.new_language_features.coroutines.intro

.. include:: <mmlalias.txt>


Coroutines: Introduction
========================

.. contents::
   :local:

Prototypical Introductory Exampe: Fibonacci Numbers
---------------------------------------------------

.. literalinclude:: intro/fibonacci.cpp
   :language: c++
   :caption: `Download fibonacci.cpp <intro/fibonacci.cpp>`

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

* Coroutine usage

Step By Step: Simplest
----------------------

.. https://www.youtube.com/watch?v=J7fYddslH0Q (16:43 - 24:54)

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

``promise_type``: expected by the compiler 

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
  ``resume()`` jjj check
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

.. literalinclude:: intro/simplest.cpp
   :language: c++
   :caption: `Download simplest.cpp <intro/simplest.cpp>`

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

* ``co_yield``: returns control to coroutine caller
* ``.resume()``: re-enters coroutine - *this is the definition of
  coroutines*

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
       hello_instance.resume();                        // <--- run until first yield
       hello_instance.resume();                        // <--- resume after yield
       return 0;
   }
   
* Customization point: ``yield_value()``
* ``co_yield`` parameter ideally stored in promise object

  * Made available though wrapper class ``Coro``

.. literalinclude:: intro/suspend.cpp
   :language: c++
   :caption: `Download suspend.cpp <intro/suspend.cpp>`

