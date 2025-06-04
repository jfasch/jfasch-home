.. include:: <mmlalias.txt>


2025-06-04 (3 VO): More C++, And A Little Git
=============================================

.. contents::
   :local:

Homework Anyone?
----------------

Collect remaining pull requests from
:ref:`fh-2025-05-20--exercise-door-polymorphic`

C++: References, ``auto``, and Structured Binding
-------------------------------------------------

* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/050-references/topic`
* :doc:`/trainings/material/soup/cxx11/auto/topic`
* :doc:`/trainings/material/soup/cxx11/structured-binding/topic`

Optional: ``git {rebase,stash}``, And CMake Dependencies
--------------------------------------------------------

* From :doc:`/trainings/material/soup/cmake/intro/index`

  * :doc:`/trainings/material/soup/cmake/intro/libraries`
    (dependencies and visualization)
  * :doc:`/trainings/material/soup/cmake/intro/structure` (include
    paths)

* Short explanation: ``git rebase ...``

  .. code-block:: console

     $ git branch
     * some-modification
     $ git rebase main
     ... ? ...

* Short explanation: ``git stash``

Group Project: Potential Tasks
------------------------------

* Error handling: ``ASSERT_THROW()`` (see `here
  <http://google.github.io/googletest/reference/assertions.html>`__)
* Requirements

  * Burglar detection
  * Close-request while open
  * Close-request while closed
  * Close-request while opening
  * Open-request while closing
  * Safety: pressure sensor
  * ...

* Hardware

  * GPIO (libgpiod)
  * PWM? (motor)
  * PushButton GPIO
  * LightBarrier GPIO
  * Edge events (need previous state), debouncing.

* SPS-like logic

  * Timespec wrapper, wegen libgpiod gpiod_line_event_wait. Oo
    Operator Arithmetik.
  * Externalize event detection into toplevel ``Door::check()``.

    Im Main bzw. Door check. -> wait on ios, and Dispatch Events to
    State machine. Timespec now reinreichen, Time Arithmetik ganz
    einfach mit unit Tests und Overflow condition mit assert. Halt
    schwer zu testen - exceptions ganz kalt hin was ist, mit errno

* Integrationstest, nachdem die Interfaces definiert sind. Mocks als
  erste Implementation, so wie wir's jetzt haben.

  Damit kommt man ziemlich weit, weil der immer rennt. Spätestens
  durch mich, das sowieso, mit den mock Tests die wir haben.

* Door state machine: convert to `State design pattern
  <https://en.wikipedia.org/wiki/State_pattern>`__

.. Immer alles mit jeweils aktuellen Versionen
..   der anderen. Sollen sich ruhig beschimpfen.  
.. 
.. Wenns dann mit der
..   Hardware Implementation geht, na bumm. Werma gach mit einem Bier in
..   der Hand feiern.  Sonst werden wir beim Error Handling was machen
..   müssen. Exceptions assert raus.  
.. 
.. * Hm, wir mach na ma das mit der SPS
..   cycle time. Timespec Arithmetik und in Injektion eines cycle overrun
..   Error in die door State machine. Ihre Sache: exception an den
..   caller, der dann weiss was zu tun ist. An besten terminieren mit
..   Errorunser exception und sonst System Error, einer von unseren, so
..   mit errno Watchdog, alle so und so Zeit.
.. 
.. Stoff
.. 
.. Errno
.. Exceptions noexcept (Transitiv?)
.. Memory Management und Model um vor Threads zu Schrecken
.. Lock und smart pointers -> shared einstweilen, über ownership and pointers.
.. Gleich mal einbauen und wieder fork updaten lassen
.. Patterns
..   Ausblick:
..   Fassade, composite mit Sensor Werten,
..   Oder besser Filter und Ranges. Iterate over state Changes aber Switch oder Them
..   Generator 😁
..   Filter zum numerischen Transform eines oder einer Queue von Sensor Werten

Links
-----

* `Bartosz Golaszewski: "New GPIO interface for linux user space" /
  #LinuxPiter <https://youtu.be/BK6gOLVRKuU?si=j_cm_tiBo3uL9s57>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/BK6gOLVRKuU?si=FfNfRC9Kslhqw35-" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     referrerpolicy="strict-origin-when-cross-origin" 
	     allowfullscreen>
     </iframe>


.. * Pullrequests einsammeln
.. 
..   * jeder mit seinem eigenen .vscode
..   * Conflict -> log von mir
..   * -> zentralisieren
.. 
..     * git rm -r .vscode
..     * merge von pullrequest eines teams (wer kennt sich aus?) auf
..       VSCode anzetzen. Config, die man sharen kann im repo, damit wir
..       alle gleich arbeiten. was schlaegt denn chatgpt so vor?
.. 
..       * indentation. big topic. was schlagt denn vscode so vor, bzw
..         kann man wo eine config hernehmen und erklaeren?
..       * und wie geht das mit dem emacs? was sagt er dazu :-)
..       * nach boesen .gitignores im tree suchen und erklaeren warum nur
..         buildBLAH und andere berechtigte da rein gehoeren, aber nicht
..         die unfaelle. wenn dann muessen wir uns eine nomenklatur
..         einfallen lassen, welches build{,x86-64,armv7,...}
..       * wie bekommt man ein externes build directory unter? wie sag
..         ich ihm, wo das BUILDDIR ist? usecases:
.. 
.. 	* ich will nicht 100000 builds verstreut haben im sourcedir
.. 	  und die realitaet verweigern, indem ich sie einfach
.. 	  .gitignoriere.
.. 	* ich will sie nicht nur aus dem tree draussen haben, ich will
..           sie sogar auf einem anderen filesystem. ein tmpfs gar,
..           superschnell weil memory.
.. 	* jjj das mal zammhacken, mit einem setup.sh wo ich
.. 	  /tmp/My-Builds hab. brauch ich, weil nach einem reboot is weg.
.. 	* jjj full rebuild, mitsamt dem gschissenen googletest
.. 	* jjj mit egon reden, wie er das so mit dem unittesten macht.
.. 	* -> CI pipeline hardware haufen memory

.. * const und * irgendwo aus c rausgraben und bringen

..   * https://www.youtube.com/watch?v=tA6LbPyYdco
..   * -> constinit: eine tour, wie man explizit steuert, wo memory hingeht
..     * viel mit nm --demangle, oder objdump
..     * 28:50 constexpr sort and vector

.. * bei der theoretischen pruefung fragen :-)
