Embedded Computing 2 (ECE 19)
=============================

.. contents::
   :local:

Group Project
-------------

**Topics**

.. figure:: ../EC1/Bullshit-Bingo-G2.jpg

**Random Ideas**

* MQTT for debug messages and status reports.

  Background: Christan Vogel thinking about how to watch a uC car
  (that from *Embedded Systems*) drive, internally. Students running
  side by side a car and watching what's on the display does not scale
  so well.

  Good opportunity to look into 

  * how debugging could be done in a real-world
    application. (``stderr`` first.)
  * how ``stderr`` could be replaced with MQTT client.
  * how the Python ``logging`` module is used. MQTT log sink.

* Fork openheating

  * First commit, tagged: remove all thermometer related
    implementations.

    Rationale: can pull them over later if need be. Git can handle
    that.

  * WHat it left is:

    * DBus framework, and interface definitions. Will use them later
      in the project, when we get to distribution. classes and oo (and
      duck/abc first maybe?)
    * Switch unit tests, unused first, one-by-one, and a sketch of the
      interface. *Maybe switch to pytest?*

    * Plan

      * move to gitlab/fh
      * pimp the oo topic which is outright crap. split apart into

	* use a see-also scheme (?) all over.
	* use live hacking; only short introductory slides
	* encapsulation, methods, attributes, self
	* properties (in the advanced section)
	* staticmethod, classmethod

      * rip apart ``openheating/plant/service_def.py``
      * Exercise

	* pull out switch implementation from ``blink`` into a class
	* modify ``blink`` to use that module. blah Switch
          instantiation blah.

      * overall: group reports, in a circular way. every member of a
        group gets to speak. hehe: database where groups and their
        members are registered. point system per report day. hehehehe.
      * Pull best implementation into framework
      * DBus: wrap Switch into a server, show interface
        definitions. write a program that exercises interface
        repo. document that damn thing, all over the project.
      * Show DBus client switching
      * Next: unittest for switch. how could that work? mocking. first
        manually, and then with pytest. this basically only defines
        that a mockswitch must remember an attribute state on/off, and
        use the same on() and off() methods as the real switch.
      * Next: thermometer, using the same schema. interface definiton,
        blah.
      * Next: hysteresis, on/off, again using TDD. one group going
        into exercise.
      * Next: kitt pattern as a class, using a configurable amount of
        leds/gpios. TDD means that it has to have a testable interface
        -> external clock.
      * What else?
      * System startup. maybe there's a good video on it.
