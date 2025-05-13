.. include:: <mmlalias.txt>


Exercises: Inspecting Text Files
================================

.. contents::
   :local:

#. Output the first two lines of ``/etc/passwd``
#. Output the third line of ``/etc/passwd`` Note: use ``head`` and
   ``tail`` in a pipe.
#. Show all groups in the system, together with their IDs (have a
   quick look in ``/etc/group`` to see how the group database is
   structured)
#. Find out through *grepping* which port number is used by the File
   Transfer Protocol (FTP). Note: port numbers (Unix speak:
   *services*) are registered in ``/etc/services``.
#. Use ``less`` for the same task.
#. Legen Sie zwei symbolische Links an, die aufeinander zeigen. Was
   geschieht, wenn Sie einen von ihnen dereferenzieren (z.B. mit
   ``cat``)?
#. Suchen Sie in ``/var`` alle Files, die ̈alter als eine Stunde und
   kleiner als 50k sind.
