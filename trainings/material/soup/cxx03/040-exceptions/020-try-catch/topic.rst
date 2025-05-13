.. include:: <mmlalias.txt>


``try`` - ``catch``
===================

``try`` - Block
---------------

**Try** do do something:

.. code-block:: c++

   try {
       dothat();
       dothis();
       dothose();
       finally();
   }
   ...


* Linear execution
* Error handling not after every step
* ... but rather in a separate block

``catch`` - Block
-----------------

.. code-block:: c++

   try {
       ...
   }
   catch (const ThisException &e) {
       std::cerr << e.what() << std::endl;
       // ... react ...
   }
   catch (const ThatException &e) {
       std::cerr << e.what() << std::endl;
       // ... react ...
   }
   catch (const std::exception &e) {
       std::cerr << e.what() << std::endl;
       // ... give up ...
   }

Exceptions
----------

**No restrictions**: everything can be thrown and caught

.. code-block:: c++

   try {
       ...
   }
   catch (int i) {
       ...
   }

* |longrightarrow| One has to think if it makes sense!
* Some structure is recommended

Standard Library: Exception-Hierarchy
-------------------------------------

.. image:: cpp_exceptions.jpg

Custom Exceptions (1)
---------------------

**Recommendation**:

* Don't throw numbers ...
* Don't throw strings ...
* ... fit yourself into the exception hierarchy
* |longrightarrow| minimal inheritance

.. code-block:: c++

   namespace std {
     class exception
     {
     public:
       virtual const char* what() const throw() = 0;
     };
   }

Custom Exceptions (2)
---------------------

.. code-block:: c++

   class MyException : public std::exception
   {
   public:
       virtual const char* what() const throw()
       {
           return "dammit!";
       }
   };

* Here: ``void`` constructor
* Can be arbitrary
* ... as far as interface is ok

Throwing Exceptions - ``throw``
-------------------------------

.. code-block:: c++

   void dothis()
   {
       // ...
       if (error_detected)
           throw MyException();
       // ...
   }

Last Words
----------

* ``return`` if ok, ``throw`` if error
* |longrightarrow| alternative return path
* Destructors of local objects are called
* Important design decision

  * How many custom exception do I define?
  * |longrightarrow| Error handling at which granularity?
