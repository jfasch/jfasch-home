.. include:: <mmlalias.txt>

.. jf-topic:: c.program_sanity.discrete_values
   :dependencies: c.program_sanity.integral_types


Discrete Values - ``enum``
==========================

.. contents::
   :local:

Discrete Values
---------------

Many times an integer's value does not take the full possible range
|longrightarrow| *Discrete values*

* Command identifiers (e.g. Unix ``ioctl``'s)
* Possible baud rates on a UART
* A state machine's state

Discrete Values - Traditional Approach (1)
------------------------------------------

.. list-table::
   :align: left

   * * .. code-block:: c

          #define IDLE              0
          #define WRITING_REQUEST   1
          #define READING_RESPONSE  2
          #define WAIT_RETRY        3
          
          struct protocol_engine
          {
            int state;
            ...
          };

     * **Traditional approach**

       * Declare a set of symbolic macros
       * Let an integer carry one of these values

       **Drawback**

       * One cannot deduce valid values from looking at the type

Discrete Values - Traditional Approach (2)
------------------------------------------

.. list-table::
   :align: left

   * * .. code-block:: c

          switch (engine->state) {
            case IDLE: ...;
            case WRITING_REQUEST: ...;
            case READING_RESPONSE: ...;
            case WAIT_RETRY: ...;
            default:
              error("bad state");
              break;
          }

     * * ``switch`` is *the* statement for discrete values
       * As everybody knows: ``default`` is obligatory


       **Questions**

       * Bad state? Why? How can this happen?
       * The ``switch`` handles every possible value anyhow
       * ... so why have a ``default``?

Discrete Values - Wishlist
--------------------------

**Wishlist:**

* The value of a state is pointless. I don't want to think about
  it. I.e., ``WRITING_REQUEST == 1`` for no reason.
* Separate type for a state, for

  * Readability
  * Type safety (to prevent mixing with e.g. integers)

* Compiler support in ``switch`` like, "forgot to add ``case`` label
  for newly introduced state".

  |longrightarrow| Fully met in C++, *only partly met* ("Type safety")
  in C

Discrete Values - ``enum``
--------------------------

.. list-table::
   :align: left

   * * .. code-block:: c

          enum state
          {
            IDLE,
            WRITING_REQUEST,
            READING_RESPONSE,
            WAIT_RETRY
          };
          
          struct protocol_engine
          {
            enum state state;
            ...
          };

     * **Advantage:**

       * **Wishlist item #1 and #2**
       * Separate type
       * Unambiguous when reading the code

       **But:**

       * The following is legal in C
       * *Illegal in C++*

       .. code-block:: c

	  enum state s = 42;

Discrete Values - ``enum`` and ``switch``
-----------------------------------------

**Wishlist item #3:** "forgot to add ``case`` label for newly
introduced state"

.. list-table:: 
   :align: left

   * * **Adding New State**

       .. code-block:: c

          enum state
          {
              IDLE,
              WRITING_REQUEST,
              READING_RESPONSE,
              WAIT_RETRY,
              /* Error handling */
              PROTOCOL_ERROR
          };

     * * State machines change
       * E.g. towards the end of the project everybody wants error
         handling
       * |longrightarrow| Code needs to react upon the new state

Discrete Values - ``enum`` and ``switch``
-----------------------------------------

.. list-table::
   :align: left

   * * .. code-block:: c

          switch (engine->state) {
            case IDLE: ...;
            case WRITING_REQUEST: ...;
            case READING_RESPONSE: ...;
            case WAIT_RETRY: ...;
            default:
              error("bad state");
              break;
          }

     * "``default:``" **considered harmful**

       * Eats all new states
       * |longrightarrow| *prevents the compiler from helping me*

Discrete Values - Close to Perfection
-------------------------------------

.. list-table::
   :align: left

   * * .. code-block:: c

          switch (engine->state) {
            case IDLE: ...;
            case WRITING_REQUEST: ...;
            case READING_RESPONSE: ...;
            case WAIT_RETRY: ...;
            /* no default here! */
          }

     * * GCC (at least) can warn about such cases
       * ``-Wswitch-enum``

.. code-block:: console

   $ gcc -Wswitch-enum ...
   warning: enumeration value ‘PROTOCOL_ERROR’ not handled ...
   $ gcc -Werror -Wswitch-enum ...
   error: enumeration value ‘PROTOCOL_ERROR’ not handled ...
