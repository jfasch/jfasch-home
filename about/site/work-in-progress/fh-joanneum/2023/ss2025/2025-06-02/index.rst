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
