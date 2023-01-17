Git Notes
=========

.. contents:
   :local:

Bring Local Branch Upstream
---------------------------

We have a local branch, ``the-branch`` that we want to push to our
upstream repo.

.. code-block:: console

   $ git push -u git@github.com:jfasch/jfasch-home.git the-branch
    
Create Remote Tracking Branch
-----------------------------

.. code-block:: console

   $ git clone git@github.com:jfasch/jfasch-home.git
   $ git checkout --track origin/the-branch

Create, Submit, Apply Patches
-----------------------------

.. code-block:: console

   $ git format-patch -o dir branch-von-wo
   $ git format-patch -o dir --root         # since beginning of project
   $ git send-email --compose dir
   $ git send-email --compose /tmp/libgpiod --from jf@faschingbauer.co.at --to jf@faschingbauer.co.at -cc joerg.faschingbauer@aon.at master 

Single commit: -1

Miscellaneous
-------------

* repo am server, initial push

  * On server
    $ git init --bare blah.git
  * Client, one possibility
    $ git push --set-upstream ssh://jfasch.no-ip.biz/share/homes/Joerg/SVN-Repositories/blah.git master
  * Client, other possibility (Github recommendation)
    $ git remote add origin git@github.com:jfasch/jf-kernel-course.git
    $ git push -u origin master

* Remote in lokalen Branch

  git remote add <my-remote-name> <repo>
  git fetch <myremote-name>
  git checkout -b <my-branch> <my-remote-name>/<remote-branch>

* remote branches

  git remote add orig-work ~/work/non-vc/STIA.git
  git remote -v
  git fetch orig-work

  Create tracking branch:

  git checkout -b my-rpi-3.12.y remotes/raspberry/rpi-3.12.y

