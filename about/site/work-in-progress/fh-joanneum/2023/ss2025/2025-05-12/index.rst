.. include:: <mmlalias.txt>


2025-05-12 (3 VO): C++ "Door" Exercise Recap, Some Git
======================================================

.. contents::
   :local:

C++ Material
------------

* :doc:`/trainings/material/soup/cxx/cxx11/strongly-typed-enums/topic`

.. _fh-2025-05-12-some-git:

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

.. _fh-2025-05-12-change-origin:

Change ``origin``, And Push
...........................

.. image:: git-workflow.jpg

``origin`` is the default for ``git pull`` and ``git push``. We want
that these operation always go to something where we have write
access - our own "fork".

* On Github (https://github.com/FH-STECE2023-Org/FH-STECE2023), fork the project
  into something where you have write access; say,
  https://github.com/you/FH-STECE2023.git. Press the "Fork" button and
  follow the instructions.
* Change ``origin`` of your clone to be your fork

  .. code-block:: console

     $ git remote set-url origin git@github.com:you/FH-STECE2023.git

  Note the *SSH* URL, starting with ``git@github.com:``.

* Pull changes that you don't have. Reason: between the time you
  cloned your repo (remember, from
  https://github.com/FH-STECE2023-Org/FH-STECE2023), and the time you created
  the fork, some commits have been pushed to
  https://github.com/FH-STECE2023-Org/FH-STECE2023.

  .. code-block:: console

     $ git pull
     ... an editor will pop up. accept the prefilled "this is a merge commit" message ...

* Push your repo; this will now go into your new repo
  git@github.com:you/FH-STECE2023.git

  .. code-block:: console

     $ git push

.. _fh-2025-05-12-homework:

Homework
--------

Local C++ Transformation
........................

* Complete the C++ transformation according to the example in
  `lib/push-button.h
  <https://github.com/FH-STECE2023-Org/FH-STECE2023/blob/main/exercises/joerg.faschingbauer/lib/push-button.h>`__
  and `lib/push-button.cpp
  <https://github.com/FH-STECE2023-Org/FH-STECE2023/blob/main/exercises/joerg.faschingbauer/lib/push-button.cpp>`__

  See door sketch in :ref:`Door Exercise <fh_2023_door_exercise>`. For
  all the components in your ``exercise/firstname.lastname/lib``
  directory, change its implementation from C ``struct`` to C++
  ``class``.

  * ``PushButton``
  * ``LightBarrier``
  * ``Motor``
  * ``Door`` (the C struct has pointer members, and this does not
    change in the C++ class)

* Make sure the tests still run
* Make clean commits in your local repo that you cloned from
  https://github.com/FH-STECE2023-Org/FH-STECE2023.git the other day

Fork on Github, And Change Your ``origin``
..........................................

Following the procedure outlined in
:ref:`fh-2025-05-12-change-origin`,

* Create a fork of our project
* In your clone from earlier days, change ``origin`` to that fork.
* Push your repo to the new ``origin``

Submission: Pull Request
........................

To submit, send me a `pull request
<https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/creating-a-pull-request>`__.
