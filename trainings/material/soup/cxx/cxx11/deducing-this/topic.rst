.. include:: <mmlalias.txt>


Explicit Object Member Functions (A.k.a Deducing ``this``)
==========================================================

.. contents:: 
   :local:

.. sidebar:: Documentation

   * `Explicit object member functions
     <https://en.cppreference.com/w/cpp/language/member_functions.html#Explicit_object_member_functions>`__

Problem: Repeated Code
----------------------

* Typical problem: (non)``const`` getter overloads
  * |longrightarrow| Repeated code

.. literalinclude:: code/problem-dry.cpp
   :caption: :download:`code/problem-dry.cpp`
   :language: c++

Python Excursion: Explicit Object Parameter
-------------------------------------------

* In Python, there is no *implicit* ``this``
* According to Zen, *Explicit is better than implicit* (`here <PEP 20
  – The Zen of Python>`__)
* Also, in Python, there is no overloading
* Problem solved
* (Assignment to ``[]`` expressions works differently in Python)

.. literalinclude:: code/python-class.py
   :caption: :download:`code/python-class.py`
   :language: c++

C++: Explicit Object Parameter (Since C++23)
--------------------------------------------

* Really bad syntax
* ``this`` *is only an annotation*: "pass the object as (const)
  reference"
* |longrightarrow| No ``const`` method, but ``const`` object instead
* Still duplicate code!

.. literalinclude:: code/problem-dry.cpp
   :caption: :download:`code/problem-dry.cpp`
   :language: c++

Template Method To Deduplicate
------------------------------

* Return type deduction
* Deduced from selected ``vector::at()`` method

.. literalinclude:: code/deduplicated.cpp
   :caption: :download:`code/deduplicated.cpp`
   :language: c++

Even Shorter: Abbreviated Function Template
-------------------------------------------

* Cool
* Readable?

.. literalinclude:: code/deduplicated-abbrev-fun-template.cpp
   :caption: :download:`code/deduplicated-abbrev-fun-template.cpp`
   :language: c++

Links
-----

* `Deducing this Patterns - Ben Deane - CppCon 2021
  <https://youtu.be/jXf--bazhJw?si=LhID985yQv5f--hY>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/jXf--bazhJw?si=LhID985yQv5f--hY" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     referrerpolicy="strict-origin-when-cross-origin" 
	     allowfullscreen>
     </iframe>

* `C++23’s Deducing this: what it is, why it is, how to use it (Sy
  Brand)
  <https://devblogs.microsoft.com/cppblog/cpp23-deducing-this/>`__
