Exercise: Verify, Repeat
========================

In the exercises 

* :doc:`mkdir-p-rm-r`
* :doc:`echo-create-files`
* :doc:`echo-copy-files`
* :doc:`echo-move-files`

, you created a tree rooted at ``/tmp/firstname.lastname/parent``.

1. Verify that all is correct

   * The hierarchy should look as follows,
   
     .. code-block:: console
     
        $ tree /tmp/firstname.lastname/parent
        /tmp/firstname.lastname/parent
        ├── child
        │   ├── business-card
        │   ├── garbage1.txt
        │   └── garbage2.txt
        ├── garbage1.txt
        ├── garbage2.txt
        └── hello
      
   * The file ``/tmp/firstname.lastname/parent/hello`` should look as follows,
   
     .. code-block:: console
   
        $ cat /tmp/firstname.lastname/parent/hello
        hello sweetheart
   
   * The file ``/tmp/firstname.lastname/parent/child/business-card`` should contain
     something like,
   
     .. code-block:: console
   
        $ cat /tmp/firstname.lastname/parent/child/business-card 
        Joerg
        Faschingbauer
        Prankergasse 33
        8020 Graz

2. If any of the above is not the case, :doc:`remove
   <../../file_dir_create_rm>` ``/tmp/firstname.lastname/parent`` again recursively, and
   recreate the hierarchy.
3. **Repeat until successful!**
