Daily Log
=========
   
2021-03-04
----------

* *Organizational Blah*

  * :doc:`plan`
  * :doc:`cloud-computer`

* *Discussion*

2021-03-05
----------

.. sidebar:: Cheat Sheets

   * :download:`Bash Help Sheet <bash-help-sheet.pdf>`
   * :download:`Default Keyboard Shortcuts for Bash <readline-emacs-editing-mode-cheat-sheet.pdf>`

From :download:`Linux Basics (PDF)
</trainings/material/pdf/010-linux-basics.pdf>` ...
     
* *Bausteine von Unix und Linux*

  5-7, 9-16

* *Die Shell (Bash - "Bourne Again Shell")*

  36-45, 58-61, 63, 64

2021-03-18
----------

From :download:`Linux Basics (PDF)
</trainings/material/pdf/010-linux-basics.pdf>` ...
     
* *Das Filesystem*

  Es ist wichtig, im Filesystem navigieren zu können. Die Basic Tools
  müssen sitzen (``cd``, ``ls``, ``pwd``, ``mkdir``, ``rm``, ``cp``,
  ``mv``, etc.). (Dazu muss man natürlich verstehen, was Files,
  Directories etc. sind.)

  Das *Permission*-Thema ist *extrem* wichtig, und man kann damit
  rechnen, dass zur Prüfung ein paar trockene Fragen zu dem Thema
  kommen.

  * Pfade: 67-71
  * Directories: 72-76
  * Symbolische Links: 77-79
  * Directory Listings (``ls``): 84-87
  * Kopieren und Verschieben (``cp`` und ``mv``): 88-91
  * Owner, Permissions: 92-97, 100

2021-03-26
----------

* *Das Filesystem*

  * Permissions

    * Die ``umask``: 98-99
    * Tools für Permissions: 100
    * Set-UID Bit: 101
    * Sticky Bit: 102

  * Das ``find`` Command: 105-109

* Tools für Textfiles: 113ff.

  Das Kapitel wurde ansatzweise durchgegangen - jedes Tool. Wichtig
  ist, zu verstehen,

  * dass die Tools von *Standard Input* lesen, auf *Standard Output*
    schreiben (und auf *Standard Error* Fehler und Debug-Messages
    schreiben).
  * dass diese und andere Tools durch die Benutzung von *Standard
    Input* und *Standard Output* in der *Pipe*

* IO Redirection und Pipes: 133ff.

  Dieses Kapitel wurde in einem mit den Tools durchgemacht,
  ansatzweise.

  Wichtig ist mir, dass die Wirkungsweise der Pipe verstanden wird,
  und dass man Tools mit ihrer Hilfe verknüpfen kann.

2021-04-15
----------

* Aufwärmen

  * SSH Public Key Authentication
  * **Das verdammte Directory eines fremden Users, das ein File drin
    hat, das ich aus dem Directory nicht löschen darf.**
  * Abschluss des Linux/Shell Kapitels: *Fragerunde*

* Python Setup

  * :doc:`/trainings/material/soup/python/draft/installation`
  * :doc:`/trainings/material/soup/python/draft/vscode`

* Python Intro

  * :download:`Python Course (PDF) </trainings/material/pdf/300-python.pdf>`

2021-04-21
----------

Git Intro
.........

.. sidebar:: Download and Installation

   * `Git for Windows <https://git-scm.com/download/win>`__
   * `Git for MacOS <https://git-scm.com/download/mac>`__

.. raw:: html

   <iframe width="560" 
           height="315" 
	   src="https://www.youtube.com/embed/HVsySz-h9r4" 
	   title="YouTube video player" 
	   frameborder="0" 
	   allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	   allowfullscreen>
   </iframe>

Github
......

* Private repository on Github: https://github.com/jfasch/FH-ECE-19
* Create Github account, and send it to jf@faschingbauer.co.at
* Clone the repository

  .. code-block:: console

     $ cd directory-where-i-have-my-ec-work
     $ git clone https://github.com/jfasch/FH-ECE-19.git

* If you are getting tired of entering a password for each repo
  transaction, you can always `deploy a SSH public key to Github
  <https://github.com/settings/keys>`__, and then re-clone using the
  SSH access method:

  .. code-block:: console

     $ git clone git@github.com:jfasch/FH-ECE-19.git

Python
......

.. _first-notebook-here:

.. list-table::
   :align: left
   :header-rows: 1

   * * Notebook Structure
     * Notebook Download
   * * .. toctree::

          Notebooks/Datatypes

     * :download:`Notebook: Datatypes <Notebooks/Datatypes.ipynb>`

.. _first-dag-here:

**Course material**

.. jf-topicgraph::
   :entries: python.basics.exercises.cmdline_digit

2021-04-29
----------

* Raspi Lab Setup

  * Image preparation using `script in our Github repo
    <https://github.com/jfasch/FH-ECE-19/blob/master/bin/fh-lab-image>`__
  * Me being Doze admin, configuring static IPs

* GPIO demo, using an LED
* OneWire demo, using one of those `DS18B20
  <https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf>`__
  sensors.

.. figure:: Bullshit-Bingo-G2.jpg

   Topics of interest, from Group 2

* Exercise recap:
  :doc:`/trainings/material/soup/python/python_0165_exercises/exercise_cmdline_digit`

2021-05-10
----------

Org Stuff
.........

* Course documentation

  * Notebooks now maintained here (moved over from Github) (see
    :ref:`here <first-notebook-here>`)
  * Topic dependency graphs inserted in random locations (see :ref:`here <first-dag-here>`)

* Github

  * Repo made private
  * FH VPN? Gitlab?

Python: Functions
.................

.. list-table::
   :align: left
   :header-rows: 1

   * * Course Material
     * Notebook Structure
     * Notebook Download
   * * * :doc:`/trainings/material/soup/python/python_0270_functions/topic`
       * :doc:`/trainings/material/soup/python/python_0270_functions/screenplay-scoping`
     * .. toctree::

          Notebooks/Functions

     * :download:`Notebook: Functions <Notebooks/Functions.ipynb>`

2021-05-12
----------

Python: Towards Object Oriented Programming
...........................................

Writing a checker for the exercise (live hacking). Covers these topics:

* Tuple unpacking
* Iteration
* Functions
* Modules
* Classes and ``namedtuple``
