Memory Leaks?
=============

.. sidebar::

   * :doc:`/trainings/material/soup/c/090-program-sanity/080-valgrind/topic`

Note that ``class SensorRepository`` takes ownership of sensor
objects, and that *sensor objects are managed as pointers*. This give
way to a number of problems, the least of which is *memory
leaks*. Eliminate those.

Use ``valgrind`` to check for memory leaks [#valgrind-install]_:

.. code-block:: console

   $ valgrind --leak-check=full <exe-name>

Fix any complaints. Use ``delete sensor-object`` in those situations
(likely ``remove()``, and the destructor) where ``SensorRepository``
gives up ownership of a sensor object.

*Hint:* a destructor is a special method of a class which is called in
 places where the object goes out of scope. Syntactically, for a
 ``class Foo``, this would look like follows:

.. code-block:: c++

   class Foo
   {
   public:
       ~Foo() { ... }
   };


.. rubric:: Footnotes

.. [#valgrind-install] If not yet installed, make it so:

		       *Debian-ish*

		       .. code-block:: console

			  $ sudo apt install valgrind

		       *Fedora*

		       .. code-block:: console

			  $ sudo dnf install valgrind


			 
