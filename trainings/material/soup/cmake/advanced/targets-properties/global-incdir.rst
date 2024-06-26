Why Noy Use ``include_directories()`` For That
==============================================

**Discuss**

* ``include_directories("<top>/toolcase/{base,data-logger,boiling-pot}")`` 
  globally

Vs.

* ``target_include_directories()`` at the *used* node, not the using
