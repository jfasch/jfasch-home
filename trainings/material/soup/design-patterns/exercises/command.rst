.. ot-exercise:: design_patterns.exercises.command
   :dependencies: design_patterns.interfaces,
		  design_patterns.exercises.composite

.. include:: <mmlalias.txt>


Exercise: Command
=================

.. contents::
   :local:

Motivation
----------

There is a database implementation, ``SocialDB``, with the operations

* ``insert()``
* ``find()``
* ``drop()``

Based on the situation described in :doc:`../command`, implement a
``SocialDBCommand`` hierarchy that provides a type for each of the
database operations.

Step 1: Basic ``insert()``
--------------------------

Start with the insert command - it is the simplest because is has no
return value, and naively we do not currently expect errors.

.. literalinclude:: code/tests/command-suite-insert.cpp
   :caption: :download:`code/tests/command-suite-insert.cpp`
   :language: c++

Ensure that the command implements the ``SocialDBCommand``
interface. (That is the entire point behind *Command*.)

.. literalinclude:: code/tests/command-suite-insert-by-base.cpp
   :caption: :download:`code/tests/command-suite-insert-by-base.cpp`
   :language: c++

Step 2: Basic ``find()``
------------------------

Like with ``insert()``, lets ignore the possiblity of errors for a
moment. ``find()`` differs from ``insert()``, though, in that it has a
return value the issuer is sure interested in.

The ``SocialDBCommand`` interface has only a very anonymous ``void
execute()`` method that does not have room for command-specific return
values. 

Solution: store the return value in the specific command object, and
let the issuer ask for it once the command has run.

.. literalinclude:: code/tests/command-suite-find.cpp
   :caption: :download:`code/tests/command-suite-find.cpp`
   :language: c++

Step 3: ``drop()``
------------------

Simplest!

.. literalinclude:: code/tests/command-suite-drop.cpp
   :caption: :download:`code/tests/command-suite-drop.cpp`
   :language: c++

Step 4: Handle ``find()`` Errors
--------------------------------

The way to quickly get to something that works is to ignore
errors. Let's not go in that directory for too long, and find a way to
communicate errors to the command's issuer.

The *find* command that we implemented above store the database
operation's return value, and make it available to the issuer via the
``result()`` method.

Now the ``find()`` database operation can throw an error (of type
``SocialDB::NotFound``) that also needs to be made available. Store
that in the object, and re-throw it in the ``result()`` method.

.. literalinclude:: code/tests/command-suite-notfound.cpp
   :caption: :download:`code/tests/command-suite-notfound.cpp`
   :language: c++

Step 5: Handle ``insert()`` Errors
----------------------------------

While ``insert()`` does not return a value, it can throw. Like in
``find()``, store the exception in the *insert* command, and re-throw
when the issuer requests the ``result()``.

.. literalinclude:: code/tests/command-suite-notinserted.cpp
   :caption: :download:`code/tests/command-suite-notinserted.cpp`
   :language: c++

Step 6: Bulk Insert?
--------------------

Now that we have an *insert* command that we can instantiate objects
from, we could create a sequence of such objects and encapsulate those
in a, say, ``BulkInsert`` command. Lets give it a try.

.. literalinclude:: code/tests/command-suite-bulk-insert.cpp
   :caption: :download:`code/tests/command-suite-bulk-insert.cpp`
   :language: c++

Step 6a: Bulk Insert Using ``std::initializer_list``?
-----------------------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/group`

To make matters less clumsy, they invented :doc:`brace initialization
</trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/group>`. Lets
try it out.

.. literalinclude:: code/tests/command-suite-bulk-insert--std_initializer_list.cpp
   :caption: :download:`code/tests/command-suite-bulk-insert--std_initializer_list.cpp`
   :language: c++
