Exercise: Write User Records To JSON File
=========================================

.. topic:: Documentation

   * `json module <https://docs.python.org/3/library/json.html>`__

Plan
----

Lets add more functionality to our ``userdb`` module. In
:doc:`read-csv-dicts`, we have read user records of the form 

.. code-block:: python

   {
       'id': 666,      # <-- int
       'firstname': 'Jörg',
       'lastname': 'Faschingbauer',
       'birth': '1966-06-19',
   }

Now, given that we can have a list - an *iterable* to be exact - of
such records, lets write them out in JSON format (`see here
<https://docs.python.org/3/library/json.html>`__, watch out for
functions like ``load()``, ``loads()``, ``dump()``, and ``dumps()``).

Again, download the test below which contains the requirements. Read
carefully, and note that the function writes the user records to
something that looks like a file (the test uses ``io.StringIO`` which
is not a file but behaves like one).

.. literalinclude:: code/test_write_userdicts_to_json.py
   :caption: :download:`code/test_write_userdicts_to_json.py`
   :language: python
