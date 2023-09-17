:orphan:

.. ot-exercise:: linux.basics.permissions.fh_moodle_quiz
   :dependencies: linux.basics.permissions.basics


FH/Moodle Quiz: Permissions
===========================

.. contents::
   :local:

Questions
---------

* A permission mask of ``rwxr-xr-x`` on a file means that ... (multiple
  correct answers)

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Question
       * Yes
       * No
     * * Everyone may execute the file
       * y
       * 
     * * Everyone may read the file
       * y
       * 
     * * Members of the owning group may write the file
       * 
       * n
     * * The owner may write the file
       * y
       * 
     * * Any user that is neither the owner nor a member of the owning
         group may write the file
       * 
       * n

* A permission mask of ``rwxr-x---`` on a directory means that ... (multiple correct answers)

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Question
       * Yes
       * No
     * * The owner may create files in the directory
       * y
       * 
     * * Members of the owning group may create files in the directory
       * 
       * n
     * * Any user that is neither the owner nor a member of the owning
         group may not access the directory in any way
       * y
       * 
     * * The owner may remove the directory and its contents
       * y
       * 

Dependencies
------------

.. ot-graph::
   :entries: linux.basics.permissions.fh_moodle_quiz
