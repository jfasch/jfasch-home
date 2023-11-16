.. include:: <mmlalias.txt>

.. ot-task:: fh2021.datalogger_csv_sink
   :dependencies: fh2021.datalogger


Data Logger: CSV Sink
=====================

Requirements
------------

.. sidebar::

   **See also**

   * Predecessor task: :doc:`datalogger`

* A CSV implementation of the ``SinkLogger`` interface
* Configurable columns: mapping sensor names (from ``SensorValues``
  onto column names). Like so,

  .. code-block:: c++

     sink = CSVSink(
                "/path/to/logfile.csv",
		{
                   { "LinksOben", "links-oben" },
		   { "RechtsUnten", "rechts-unten" },
	        });

     SensorValues values;
     values.addMeasurement("links-oben", 37.5);
     values.addMeasurement("rechts-unten", 42.666);

     sink.output(values);

  This results in a CSV format similar to the following:

  .. code-block:: 

     LinksOben;RechtsUnten
     37.5;42.666

Implementation
--------------

Column name configuration
.........................

``class CSVSink`` takes a ``std::vector<std::pair<std::string,
std::string>>`` as column configuration. It remembers that object
internally, as it will be used on every call to ``output()``.

``output()``
............

To bring the ``SensorValues`` into a CSV line, you iterate over the
config, and lookup each entry in the ``SensorValues``,

.. code-block:: c++

   for (auto [csvname, valuename]: _config) {
        double value = sensor_values.getMeasurement(valuename);
	... write value into "csvname" column ...
   }
   

Testing
-------

* Basic (ok) case
* Error: bad config: referred name not found in ``SensorValues``
* Whatever error cases might come to mind

Future (*Not* Part Of This Development Cycle)
---------------------------------------------

* Log rotation. Users might want to backup what was logged, remove old
  data, and start a new file. The class must somehow support this.

Dependencies
------------

.. ot-graph::
   :entries: fh2021.datalogger_csv_sink
