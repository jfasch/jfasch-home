.. include:: <mmlalias.txt>


2025-06-02 (3 VO): CMake, And More C++
======================================

.. contents::
   :local:

* Finish :ref:`fh-2025-05-20--exercise-door-polymorphic`
* cmake dependencies (-> gebaut wird nur toplevel)
* git: rebase, stash
* auto (mlinar)
* brace initialization
* polymorphic genauer -> screenplay
* syllabus grading nix laborklausur

Plan
----

.. Studenten bestechen: 10 für einen Doku Task, 20 für eine
   Implementation des Tür Werks. Wenns flott geht ... Dann kann man ja
   beides machen und in dieser Runde einen 30er verdienen.

Tasks
-----

* Timespec wrapper, wegen libgpiod gpiod_line_event_wait. Oo Operator
  Arithmetik.
* Externalize event detection into toplevel ``Door::check()``.

  Im Main bzw. Door check. -> wait on ios, and Dispatch Events to
  State machine. Timespec now reinreichen, Time Arithmetik ganz
  einfach mit unit Tests und Overflow condition mit assert. Halt
  schwer zu testen - exceptions ganz kalt hin was ist, mit errno

* Edge events (need previous state), debouncing.
* Integrationstest, nachdem die Interface definiert sind. Mocks als
  erste Implementation, so wie wir's jetzt haben.

  Damit kommt man ziemlich weit, weil der immer rennt. Spätestens
  durch mich, das sowieso, mit den mock Tests die wir haben.

* Derweil kann das State pattern vorangetrieben werden. Dingsbums?

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
