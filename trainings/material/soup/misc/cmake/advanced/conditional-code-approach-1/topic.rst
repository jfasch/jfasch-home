.. include:: <mmlalias.txt>


Optional Code, Approach 1: Optional ``blacklist``, C Macro  (Global Flags)
==========================================================================

.. contents::
   :local:

.. sidebar::

   **Source**

   .. code-block:: console

      11-conditional-code-approach-1/
      ├── CMakeLists.txt
      ├── DemoConfig.h.in
      ├── bin
      │   ├── CMakeLists.txt
      │   ├── hello-first.cpp
      │   └── hello-second.cpp
      ├── blacklist
      │   ├── blacklist.cpp
      │   ├── blacklist.h
      │   └── CMakeLists.txt
      └── libhello
          ├── CMakeLists.txt
          ├── greeter.h
          ├── greeter-name.cpp
          ├── greeter-name.h
          ├── greeter-simple.cpp
          └── greeter-simple.h

   * :download:`code/CMakeLists.txt`
   * :download:`code/DemoConfig.h.in`
   * :download:`code/bin/CMakeLists.txt`
   * :download:`code/bin/hello-first.cpp`
   * :download:`code/bin/hello-second.cpp`
   * :download:`code/libhello/CMakeLists.txt`
   * :download:`code/libhello/greeter.h`
   * :download:`code/libhello/greeter-simple.h`
   * :download:`code/libhello/greeter-simple.cpp`
   * :download:`code/libhello/greeter-name.h`
   * :download:`code/libhello/greeter-name.cpp`
   * :download:`code/blacklist/CMakeLists.txt`
   * :download:`code/blacklist/blacklist.h`
   * :download:`code/blacklist/blacklist.cpp`

Optional ``blacklist``, C Macro
-------------------------------

* Descend into ``blacklist`` directory *optionally*

  .. code-block:: console
     :caption: Toplevel ``CMakeLists.txt``
  
     IF (${USE_BLACKLIST})
       ADD_SUBDIRECTORY(blacklist)
     ENDIF()

* Provide C macro for occasional C macro orgies

  .. code-block:: console
     :caption: Toplevel ``CMakeLists.txt``

     # for configure-file macro, define parallel variable with real bool
     # values
     IF (${USE_BLACKLIST})
       SET(MACRO_USE_BLACKLIST 1)
     ELSE()
       SET(MACRO_USE_BLACKLIST 0)
     ENDIF()

  .. code-block:: c++
     :caption: ``DemoConfig.h.in``

     #define DEMO_USE_BLACKLIST @MACRO_USE_BLACKLIST@

Optional Dependency In ``libhello``
-----------------------------------

* Optional ``TARGET_LINK_LIBRARIES()``

  .. code-block:: console
     :caption: ``libhello/CMakeLists.txt``
		  
     IF (${USE_BLACKLIST})
       TARGET_LINK_LIBRARIES(hello blacklist)
     ENDIF()

.. note::

   *This is a massacre!*

Optional Dependency In ``libhello`` Header File
-----------------------------------------------

.. note::

   *This is a software design choice*. Putting optional code in header
   file leads to messy code, no matter which build system.
		  
* Designer's / Architect's choice: dependency in ``greeter-name.h``
  header file
* |longrightarrow| massacre
* All users ("dependers") of ``libhello`` need to have include path to
  ``blacklist.h``
* Macro-conditionals all over the place

.. code-block:: c++

   #include <DemoConfig.h>                                // <--- dependency in header file!!!
   #ifndef DEMO_USE_BLACKLIST
   # error DEMO_USE_BLACKLIST not defined                 // <--- guard against build system bugs
   #endif
   #if DEMO_USE_BLACKLIST == 1                            
   #  include <blacklist.h>                               // <--- dependency in header file!!!
   #endif
   
   #include <string>
   
   class NameGreeter : public Greeter
   {
   private:
   #if DEMO_USE_BLACKLIST == 1                            // <--- dependency in header file!!!
       Blacklist _blacklist;
   #endif
   };

.. note::

   All **users** of ``libhello`` need to be aware!

Optional Dependency In ``libhello`` CPP File
--------------------------------------------

* If one likes macros, then this is normal business
* No implications on users, as opposed to conditional code in header
  file

.. code-block:: c++

   void NameGreeter::sayhello()
   {
   #if DEMO_USE_BLACKLIST == 1
       if (_blacklist.is_forbidden(_name))
           std::cout << "Goodbye " << _name << '\n';
   #else
       std::cout << "Hello " << _name << '\n';
   #endif
   }

Good Or Bad?
------------

*What is this approach?*

* |longrightarrow| Using "globals" a lot

  * ``USE_BACKLIST`` defined *toplevel*, and used in ``libhello`` to
    conditionally add dependency on ``blacklist``
  * C macro defined *toplevel* - in ``DemoConfig.h.in``

*Is there a better way?* 

* Almost always |:ninja:|
