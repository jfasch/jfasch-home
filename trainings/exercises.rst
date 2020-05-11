Exercises
=========

.. sidebar:: Contents

   .. contents::
      :local:

Each training is accompanied with a number of exercises. To share code
with each other, and with the trainer, I usually setup a Github
repository (see the :doc:`privacy guidelines <log/codex>`) which is
active for the duration of the training. The workflow that is used in
the trainings is rather simple; following a description of it for the
Git-unaware.

Installing Git
--------------

Linux
.....

If you are on Linux, then Git is almost certainly provided by your
distribution's package manager.

In Fedora (or Redhat, for that matter), you say,

.. code-block:: console

   $ sudo dnf install git gitk

The Debian and Ubuntu way is

.. code-block:: console

   $ sudo apt install git gitk

(``gitk`` is a lightweight and fast GUI that lets you perform
read-only tasks in a repository.)

Windows
.......

For Windows users, there is an installer executable available from
`here <https://git-scm.com/download/win>`__. By the way, that site is
the home of an open source Git book; you can download and/or browse it
online directly from that site.

Workflow
--------

Lets say the training takes place on 2020-05-12; then the Github
repository's URL is named something like
``https://github.com/jfasch/jfasch-home-2020-05-12`` (the actual
repository name to clone is communicated to the trainees).

Cloning the Repository
......................

First, you create a local copy of the repo by *cloning* it. ``cd`` to
a directory which should be the parent directory of the clone, and
say,

.. code-block:: console

   $ git clone https://github.com/jfasch/jfasch-home-2020-05-12

What you just cloned into directory ``jfasch-home-2020-05-12`` is the
entire source code for the website that you are browsing,
`<https://www.faschingbauer.me>`__. Besides course descriptions, the
training material, a blog where I occasionally drop an article, and
other stuff, that site contains one subdirectory for your
training. That directory is visible through the URL
`<https://www.faschingbauer.me/trainings/log/detail/2020-05-12/>`__
(the training *metadata*, so to say).

In the clone, there is a corresponding directory,
``jfasch-home-2020-05-12/trainings/log/detail/2020-05-12/``, which is
the home for your training. This is where material for the training
starts to pile up - short programs written by the trainer as a
response to questions, occasional `Jupyter notebooks
<https://jupyter.org/>`__ (if the training is a Python training), and
the exercises that you provide solutions to.

Lets make this our current working directory from now on, 

.. code-block:: console

   $ cd jfasch-home-2020-05-12/trainings/log/detail/2020-05-12/

Exercise Time
.............

Sooner than you might wish, there will be time to do our first
exercise. At that point, the trainer will create an appropriate
skeleton that you are supposed to fill. Once created, the skeleton is
*committed* and *pushed* to the *upstream* respository (where you
cloned from initially).

You pull the trainer's modification like so,

.. code-block:: console

   $ git pull

Lets say the directory structure looks like

.. code-block:: console

   exercise-1/
   ├── user1
   ├── user2
   └── user3

If you are ``user2``, then ``exercise-1/user2`` is the place for you to
the exercise,

.. code-block:: console

   $ cd exercise-1/user2
   $ # think, hack, fix, loop

When done, you will have created on or more files in your directory,

.. code-block:: console

   exercise-1/
   ├── user1
   ├── user2
   │   └── my-unique-solution.py
   └── user3

Git knows nothing of them, so you ask it which ones these are,

.. code-block:: console

   $ git status
   On branch master
   Your branch is up to date with 'origin/master'.
   
   Untracked files:
     (use "git add <file>..." to include in what will be committed)
   	exercise-1/user2/my-unique-solution.py
   
   nothing added to commit but untracked files present (use "git add" to track)
   
While Git is a complex beast, you notice that it tries to take you by
your hand and guide you as much as it can. "``git add``" is next: you
"add" files that you have created (or modified - Git will report those
similarly),

.. code-block:: console

   $ git add exercise-1/user2/my-unique-solution.py

Now Git knows; the modifications are said to be *staged* for
commit. (Note again that Git tries to help you by telling you how to
*unstage* something that you accidentally staged.)

.. code-block:: console

   $ git status
   On branch master
   Your branch is up to date with 'origin/master'.
   
   Changes to be committed:
     (use "git restore --staged <file>..." to unstage)
          new file:   exercise-1/user2/my-unique-solution.py

What Git does not suggest as next step (maybe because it is so basic
and obvious, I don't know), is to *commit* what you have staged.

.. code-block:: console

   $ git commit -m 'my rather cool solution'
   [master 7434a5b] my rather cool solution
    1 file changed, 3 insertions(+)
    create mode 100755 trainings/log/detail/2020-05-12/code/exercise-1/user2/my-unique-solution.py

This created a commit with ID ``7434a5b``, and the message you
provided. In real life, out of respect from your coworkers and your
employer, you will want to provide longer commit messages. In this
case you omit the ``-m`` option, and Git will start an editor where
you type in the message (it takes the value of the ``EDITOR``
environment variable to know which is your favourite editor).

See what we have,

.. code-block:: console

   $ git status
   On branch master
   Your branch is ahead of 'origin/master' by 1 commit.
     (use "git push" to publish your local commits)
   
   nothing to commit, working tree clean

Ok, all clean, all committed. Commits are only local in our clone,
though (Git is a *distributed* version control system), so we need to
publicize - *push* - what we have local. "``git push``" is next.

.. code-block:: console

   $ git push
   Username for 'https://github.com': user2
   Password for 'https://user2@github.com': 
   To https://github.com/jfasch/jfasch-home-2020-05-12
    ! [rejected]        master -> master (fetch first)
   error: failed to push some refs to 'https://github.com/jfasch/jfasch-home-2020-05-12'
   hint: Updates were rejected because the remote contains work that you do
   hint: not have locally. This is usually caused by another repository pushing
   hint: to the same ref. You may want to first integrate the remote changes
   hint: (e.g., 'git pull ...') before pushing again.
   hint: See the 'Note about fast-forwards' in 'git push --help' for details.

A-ha! While there are not normally any errors of that kind when you
work alone, this will happen frequently in the trainings. No need to
panic though. Read the message carefully, and you'll understand that
somebody else created a commit in the upstream repository, *on top of
the version that you have based your own commit on*. A lightweight
conflict, so to say, which can be resolved by simply pulling the
offending version,

.. code-block:: console

   $ git pull
   Username for 'https://github.com': user2
   Password for 'https://user2@github.com': 
   remote: Enumerating objects: 17, done.
   remote: Counting objects: 100% (17/17), done.
   remote: Compressing objects: 100% (9/9), done.
   remote: Total 9 (delta 3), reused 6 (delta 0), pack-reused 0
   Unpacking objects: 100% (9/9), 869 bytes | 124.00 KiB/s, done.
   From https://github.com/jfasch/jfasch-home-2020-05-12
      a4b9666..bf5bb75  master     -> origin/master
   Updating 7434a5b..bf5bb75
   Fast-forward
    trainings/log/detail/2020-05-12/code/exercise-1/user1/another-perfect-solution.py | 3 +++
    1 file changed, 3 insertions(+)
    create mode 100755 trainings/log/detail/2020-05-12/code/exercise-1/user1/another-perfect-solution.py

This went ok; now it's time to retry the ``git push`` above.

Conflicts
.........

What has been said should be sufficient for an exercise scenario
during a training, where everyone works in their own
subdirectory. Noone edits files of another user, no two people edit
the same file - no *conflicts* will happen. Conflicts are usually a
sign of a lack of communication: when a team works on a code base,
team members usually *talk* before making a change.

Sometimes there is no other way though; in this case conflicts are
unavoidable. For the exercises I suggest you keep modifications as
local as possible, to avoid conflicts. In group exercises you talk to
each other, and normally a group is in a *pair programming* like mode;
one member hacks, and the others complain at her.

Conflicts happen though, eventually. Git is good at resolving these
automatically; and if it isn't (for example because two parties made
conflicting modifications *in the same file in the same line*), I'm
confident that we'll be able to manually resolve the conflict
together.

If you are interested, I suggest you read the `section on branching
and merging in the Git book
<https://git-scm.com/book/en/v2/Git-Branching-Basic-Branching-and-Merging>`__.
