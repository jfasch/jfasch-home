.. include:: <mmlalias.txt>


2025-05-06 (3 UE): Shell/Permissions (Exercises)
================================================

.. contents::
   :local:

Basic File And Directory
------------------------

From :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/group`:

* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/mkdir-p-rm-r`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/echo-create-files`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/echo-copy-files`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/echo-move-files`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/verify-hierarchy`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/copy-tree`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/rm-tree`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/rm-rf`

Permissions
-----------

For this, we log in to our team computer. For example:

.. code-block:: console

   $ ssh -p 2020 joerg.faschingbauer@jfasch.bounceme.net

On the team computer, we check our identity, and see that we are all
members of the ``team`` group:

.. code-block:: console

   $ id
   uid=1001(joerg.faschingbauer) gid=1002(joerg.faschingbauer) groups=1002(joerg.faschingbauer),1001(team)

Knowing this, we can now tune permissions of files and directories to
explicitly *share* with other ``team`` members.

From :doc:`/trainings/material/soup/linux/basics/permissions/exercises/group`

* :doc:`/trainings/material/soup/linux/basics/permissions/exercises/credentials`
* :doc:`/trainings/material/soup/linux/basics/permissions/exercises/shared-file`
* :doc:`/trainings/material/soup/linux/basics/permissions/exercises/private-directory`
* :doc:`/trainings/material/soup/linux/basics/permissions/exercises/private-directory-question`
* :doc:`/trainings/material/soup/linux/basics/permissions/exercises/public-directory`
* :doc:`/trainings/material/soup/linux/basics/permissions/exercises/public-directory-question`
* :doc:`/trainings/material/soup/linux/basics/permissions/exercises/fh-questions-nocheat`
