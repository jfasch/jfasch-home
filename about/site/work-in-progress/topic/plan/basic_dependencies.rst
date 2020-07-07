Basic Dependency Machinery
==========================

.. jf-task:: topic.basic_dependencies
   :initial-estimate: 24
   :spent: 24
   :percent-done: 100

Sphinx directive ``jf-topic`` to define a topic node, like so:

::

   .. jf-topic: <topic-name>
      :dependencies: <topic-name>, <topic-name>, ...
