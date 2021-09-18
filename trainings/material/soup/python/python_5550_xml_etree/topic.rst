.. include:: <mmlalias.txt>

XML: ElementTree (``etree``)
============================

.. contents::
   :local:

.. ot-topic:: python.python_5550_xml_etree
   :dependencies: python.swdev.python_1200_modules,
		  python.basics.python_0220_for,
                  python.basics.python_0450_dictionaries

SAX and DOM
-----------

.. list-table::
   :align: left

   * - **SAX**

       * Event-driven (elements start and end)
       * Commonly used to parse long streams of structured data
       * "De-facto" standard
       * Available in multiple languages
       * Python: ``xml.sax``

     - **DOM**: "Document Object Model"

       * Document available as a *tree*
       * Programmatically navigable as a tree
       * Relatively comfortable
       * Python: ``xml.dom``
       * Problems

	 * Only *relatively* comfortable
	 * Not Pythonic enough

ElementTree
-----------

``xml.etree``: Python specific |longrightarrow| *absolutely*
  comfortable

* Seamless integration in Python (|longrightarrow| iteration)
* A document is a tree, and trees are lists of lists
* XML attributes represented as dictionaries

|longrightarrow| simple!

A Very Simple Document
----------------------

.. code-block:: python
   :caption: Python code

   from xml.etree.ElementTree import Element
   element = Element("root")
   child = Element("child")
   element.append(child)

.. code-block:: python
   :caption: Or alternatively ...

   element = Element("root")
   SubElement(element, "child")
  
.. code-block:: xml
   :caption: XML

   <root>
     <child />
   </root>

Attributes
----------

* XML elements have attributes
* Python's XML elements have the ``attrib`` dictionary

.. code-block:: python

   element = Element("root")
   child = SubElement(element, "child")
   child.attrib['age'] = '15'
   child = SubElement(element, "child")
   child.attrib['age'] = '17'

.. code-block:: xml

   <root>
     <child age="15" />
     <child age="17" />
   </root>

Text (1)
--------

In XML documents, free text is permitted ...

* Inside one element
* After one element, but before the start of another element

Accordingly, Python elements have members ...

* ``element.text``
* ``element.tail``
* No text |longrightarrow| ``None``

Text (2)
--------

.. code-block:: python

   element = Element("root")
   child = SubElement(element, "child")
   child.text = 'Text'
   child.tail = 'Tail'

.. code-block:: xml

   <root><child>Text</child>Tail</root>

*Careful with indentation*

* Whitespace, linefeed etc. is text, no matter what
* ``str.strip()`` may be helpful

Writing XML Documents
---------------------

* We have created ``Element`` objects
* Added child elements
* Now how do we create XML?
* Wrap into ``ElementTree`` - a helper

.. code-block:: python

   from xml.etree.ElementTree import ElementTree
   tree = ElementTree(element)
   tree.write(sys.stdout) # oder file(..., 'w')

* Output is very tight
* Text is preserved as-is
* Pretty output would be incorrect

  * Linefeed and indentation is *text*

Reading XML Documents
---------------------

.. code-block:: python
   :caption: This is simple ...

   from xml.etree.ElementTree import parse
   
   tree = parse(sys.stdin)
   for child in tree.getroot():
       age = child.attrib.get('age')
       if age is not None:
           print age
       if child.text is not None:
           print child.text
