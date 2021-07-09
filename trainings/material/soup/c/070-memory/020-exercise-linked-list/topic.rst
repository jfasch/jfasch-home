.. include:: <mmlalias.txt>

.. jf-exercise:: c.memory.exercise_linked_list
   :dependencies: c.memory.malloc

Singly Linked List
==================

Exercises (1)
-------------

**Singly linked list: public functions ("methods")**

.. code-block:: c

   int list_init(struct list *l);
   int list_destroy(struct list *l);
   int list_insert(
       struct list *l, 
       const char *key, struct point p);
   unsigned int list_remove(
       struct list *l,
       const char *key);
   unsigned int list_count(
       const struct list *l,
       const char *key);
   void list_print(
       const struct list *l);

Exercises (2)
-------------

**Singly linked list: public data structures**

.. code-block:: c

   #define KEYLEN 31
   
   struct point {
       int x;
       int y;
   };
   
   struct list {
       struct node *first;    
   };

Exercises (3)
-------------

**Singly linked list: internals**

.. code-block:: c

   struct node {
       char key[KEYLEN+1];
       struct point point;
   
       struct node *next;
   };

Exercises (4)
-------------

* Implement a linked list as has been sketched above

Exercises (5)
-------------

.. list-table::
   :align: left

   * * **Empty list**

       * Result of ``list_init()``
       * First element is ``NULL``

     * .. code-block:: c

          struct list {
              struct node *first;    
          };
          ...
          l->first = NULL;

       .. image:: 06-99-00-list-empty.dia

Exercises (6)
-------------

.. list-table:: 
   :align: left

   * * **List containing one element**

       .. code-block:: c

          struct node {
              char key[keylen+1];
              struct point point;
          
              struct node *next;
          };
          ...
          strcpy(n->key, key);
          n->point = point;
          n->next = NULL;

     *

       .. image:: 06-99-00-list-one-element.dia

Exercises (7)
-------------

**List containing two elements**

.. image:: 06-99-00-list-two-elements.dia

Exercises (8)
-------------

**Insertion**

* Looking up the position
* Where does ``"B"`` belong?

.. image:: 06-99-00-list-insert.dia

Exercises (9)
-------------

**Insertion**

* New ``struct node``
* ``malloc(sizeof(struct node))``
* Initialization: ``key``, ``data``, ``next``

.. image:: 06-99-00-list-insert-1.dia

Exercises (10)
--------------

**Insertion**

* Link new node
* Cut old connection

.. image:: 06-99-00-list-insert-2.dia

Exercises (11)
--------------

**Insertion: done**

.. image:: 06-99-00-list-insert-3.dia

