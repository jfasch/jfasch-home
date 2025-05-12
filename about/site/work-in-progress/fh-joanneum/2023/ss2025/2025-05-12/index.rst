.. include:: <mmlalias.txt>


2025-05-12 (3 VO): C++ "Door" Exercise Recap, Some Git
======================================================

.. contents::
   :local:

Recap Of :ref:`Door Exercise <fh_2023_door_exercise>`
-----------------------------------------------------

.. sidebar:: Exercise

   :ref:`Door Exercise <fh_2023_door_exercise>`   

**Notes**

* .h vs .cpp: where to put implementation?
* Ownership (why do we pass pointers into Door ctor?)

C++ Material
------------

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/010-strongly-typed-enums/topic`

Some Git
--------

Add/Commit
..........

* View changes

  Current working directory *somewhere inside* the tree,

  .. code-block:: console
  
     $ git status
     ...

* ``git add`` changes: stage for next commit

  .. code-block:: console

     $ git add file.h file.cpp
     ...

  Review repo situation

  .. code-block:: console
  
     $ git status
     ...

* ``git commit`` what you staged

  Either non-interactive (giving the commit message as a commandline
  parameter)

  .. code-block:: console
  
     $ git commit -m 'frobozz the foobar'

  Or letting git pop up your favorite ``$EDITOR``
  
  .. code-block:: console
  
     $ git commit

Access Github Over SSH Not HTTPS
................................

This is simpler. HTTPS requires two factor auth and jumping through
hoops.

Deploy SSH public on GH |longrightarrow| homework. On Github, *You ->
Settings -> SSH and GPG Keys*. Paste your public key.

Change Upstream, And Push
.........................

* Draw sketch

  * Upstream https://github.com/jfasch/FH-STECE2023 is unwriteable
  * Need own "fork" (the is a Github concept)

* Fork old upstream into something that belongs to you. On Github,
  press the "Fork" button and follow the instructions.
* Change upstream of your clone to be your fork (see
  https://stackoverflow.com/questions/25545613/how-can-i-push-to-my-fork-from-a-clone-of-the-original-repo
  )

  .. code-block:: console

     $ git remote set-url origin git@github.com:joerg.faschingbauer/My-Fork

  Note the *SSH* URL, starting with ``git@github.com:``.

* Push your repo

  .. code-block:: console

     $ git push
