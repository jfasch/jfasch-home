.. ot-topic:: cmake.optional_code_approach_1
   :dependencies: cmake.optional_code_problem
.. include:: <mmlalias.txt>

Optional Code, Approach 1 (Global Flags): Optional ``blacklist``, C Macro
=========================================================================

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

   * :download:`11-conditional-code-approach-1/CMakeLists.txt`
   * :download:`11-conditional-code-approach-1/DemoConfig.h.in`
   * :download:`11-conditional-code-approach-1/bin/CMakeLists.txt`
   * :download:`11-conditional-code-approach-1/bin/hello-first.cpp`
   * :download:`11-conditional-code-approach-1/bin/hello-second.cpp`
   * :download:`11-conditional-code-approach-1/libhello/CMakeLists.txt`
   * :download:`11-conditional-code-approach-1/libhello/greeter.h`
   * :download:`11-conditional-code-approach-1/libhello/greeter-simple.h`
   * :download:`11-conditional-code-approach-1/libhello/greeter-simple.cpp`
   * :download:`11-conditional-code-approach-1/libhello/greeter-name.h`
   * :download:`11-conditional-code-approach-1/libhello/greeter-name.cpp`
   * :download:`11-conditional-code-approach-1/blacklist/CMakeLists.txt`
   * :download:`11-conditional-code-approach-1/blacklist/blacklist.h`
   * :download:`11-conditional-code-approach-1/blacklist/blacklist.cpp`

Approach 1 (Global Flags): Optional ``blacklist``, C Macro
----------------------------------------------------------

* 10-conditional-code-approach-1
* Descend into ``blacklist`` directory *optionally*

  .. code-block:: console
     :caption: Toplevel ``CMakeLists.txt``
  
     IF (${USE_BLACKLIST})
       ADD_SUBDIRECTORY(blacklist)
     ENDIF()

* Provide C macro for occasional C macro orgies

  .. code-block:: console
     :caption: Toplevel ``CMakeLists.txt``

     # for configure-file macro, define parallel variable with bool values
     IF (${USE_BLACKLIST})
       SET(MACRO_USE_BLACKLIST 1)
     ELSE()
       SET(MACRO_USE_BLACKLIST 0)
     ENDIF()

  .. code-block:: c++
     :caption: ``DemoConfig.h.in``

     #define DEMO_USE_BLACKLIST @MACRO_USE_BLACKLIST@

Approach 1 (Global Flags): Optional Dependency In ``libhello``
--------------------------------------------------------------

.. note::

   This is a massacre!

* Optional ``TARGET_LINK_LIBRARIES()``

  .. code-block:: console
     :caption: ``libhello/CMakeLists.txt``
		  
     IF (${USE_BLACKLIST})
       TARGET_LINK_LIBRARIES(hello blacklist)
     ENDIF()

Approach 1 (Global Flags): Optional Dependency In ``libhello`` Header File
--------------------------------------------------------------------------
		  
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

Approach 1 (Global Flags): Optional Dependency In ``libhello`` CPP File
-----------------------------------------------------------------------
 
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

Approach 1: Good Or Bad?
------------------------

What is approach 1? |longrightarrow| use "globals" a lot

* ``USE_BACKLIST`` used in ``libhello`` to conditionally add
  dependency on ``blacklist``
* C macro defined globally - in ``DemoConfig.h.in``

