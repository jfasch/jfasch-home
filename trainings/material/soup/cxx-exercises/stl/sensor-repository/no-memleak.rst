.. ot-exercise:: cxx.exercises.stl.sensor_repository.memory_leaks
   :dependencies: cxx.exercises.stl.sensor_repository.insert_no_overwrite,
		  cxx.exercises.stl.sensor_repository.insert_sunny,
		  cxx.exercises.stl.sensor_repository.lookup_not_found,
		  cxx.exercises.stl.sensor_repository.lookup_sunny,
		  cxx.exercises.stl.sensor_repository.remove_not_found,
		  cxx.exercises.stl.sensor_repository.remove_sunny,
		  cxx.exercises.stl.sensor_repository.size_const

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


			 
