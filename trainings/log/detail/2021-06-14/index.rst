Plan
````

* Talk to people about further goals

  * Thanks to Julia for the feedback, war sehr angenehm
  * Options to go into; survey

    * Usage of pointers. I could try to live hack a linked list but
      that would be an awful experience.
    * Further details about how to structure a project. We could move
      to github and work from there.

      * Explain basic problem - team work - and one possible and
	popular solution, git
      * Blah Linux blah Torvalds blah
      * Mention `Github <https://github.com/>`__
      * Mention `Team Foundation Server (TFS)
	<https://www.it-visions.de/glossar/alle/3762/Team_Foundation_Server_TFS.aspx>`__

    * Custom datatype definitions, ``struct``. I give an interface,
      and per user subdirs, equipped with CMake infrastructure
      skeletons to fill out.
    * Copy out relevant parts of the ``struct point`` stuff into
      (private?) repo. Options

      * be alone
        (`https://github.com/jfasch/2021-06-14/archive/refs/heads/main.zip`)
      * work in team (`https://github.com/jfasch/2021-06-14.git`)

    * Explain another braindead invention inside CPP: conditional
      acompilation using flags.

* Hm no

  * Establish Git. Cross finger and what can be done with `this <https://code.visualstudio.com/docs/editor/versioncontrol>`__.
  
    * Work together as a team. Create private repository on github.
    * Request people to give a github account 
    * Short git intro
  
  * Establish CMake. See tutorial `here <https://www.youtube.com/watch?v=V1YP7eJHDJE>`__.
  
    * `Doze installation <https://cmake.org/install>`__
    * Add CMake to path: maybe `this
      <https://stackoverflow.com/questions/61625880/vscode-cmake-windows-10-cmake-not-in-path>`__
      could help with ``PATH`` problems
    
* Fast run-through: 64-75
* Stop at enums/76: morph wc.c state machine into a perfect enum
  candidate. This is the time to enable ``-Wswitch-enum``.
* "Variable Definitions" section

  * emphasize on local variables (this is what we saw so far)
    more. Lifetime, initialization, etc.
  * Live-hack local/global: local initialization can be anything that
    is computed at runtime. global, otoh, can only be precomputed
    values.

* Almost skip 81-88. Operators, boring.
* Hard stop at "Type Conversions"
  

Day 4
.....

Day 5
.....

