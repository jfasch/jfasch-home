.. ot-task:: clean_code.bugs.find_error


``UserDB::find()`` Crashes If User Not Found
============================================

During high speed feature hype, we did not care about error
handling. As a consequence, ``UserDB::find(unsigned int id)`` just
crashes (``assert(false)``) if no user with such an ID exists.

Introduce exception handling to fix that.

State
-----

Done, see "UserDB::find(): throws NotFoundError", `commit
cbda1e98040d084c31ff6e83f04d78dbebf5c1c2
<https://gitlab.cc-asp.fraunhofer.de/ndf/asc-team-training-2022-04/-/commit/cbda1e98040d084c31ff6e83f04d78dbebf5c1c2>`__


.. ot-graph:: 
   :entries: clean_code.bugs.find_error
