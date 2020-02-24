To Do
=====

Convert Content
---------------

Stack
.....

* :doc:`/index`

  * Links "Schulungen", once they are in place.

    * ``courses-sysprog``
    * ``courses-misc``

* :doc:`/courses/index`

  * why is content if index included in sidebar toc?

  * Links

    * misc

      * ``raspi-hands-on``
      * ``course-kettner-lfs``
      * ``course-svn``

  * sysprog: virtmem, ipc -> avl
  * CMake
  * CAN -> network
  * GPIO, libgpiod -> Embedded

References, Past Trainings
--------------------------

* mail people, send link when done (after style is in place)

Skills
------

* web programming as skills? ("ungern")

  * flask
  * skill: not getting lost; structuring js-accessible urls; json
    interfaces (link to openheating -> intersphinx)
  * sphinx, for documentation -> consulting, soft skills
  * picture of myself wearing "css sucks" t-shirt

Miscellaneous
-------------

* openheating/doc/glt2020/ sphinxize
  
  * nice tryout
  * cool for presentation at glt
  * split in two 

    * blink, main

      * link to Screenplay ... see below howto external link,
        consistency blah.
      * Screenplay

	* panel bohren schas. inline foto
	* code snippet includes. inline link to below.
	  
	  * entire files only?
	  * inline function bodies out of external code references?

    * heating, only as a reference, but possibly fully expanded as
      things settle

      * interfaces, names blah. docstrings pulled out of referenced
        python code? possibly with checked link constistency??
      * components

	* thremometers blah
	* switches blah
	* ... blah ... signals blah hmm how blah
	* ... mqtt blah ...

      * systemd once installed successfully. start with that right
        now!
      * setup.py crap
      * diagram, rst with svg, inkskape embed maybe?
      * ...

* when done, redirect faschingbauer.co.at. how?

Hmm
---

* https://thomas-cokelaer.info/tutorials/sphinx/rest_syntax.html#internal-and-external-links
* css class passthrough:

  * https://stackoverflow.com/questions/12900626/applying-css-and-roles-for-text-blocks-instead-of-inline-spans-in-sphinx/13039131

* Check external link consistency. What happens if target does not
  exist?

  saugeil: :ref:

* saugeil: https://www.sphinx-doc.org/en/1.5/markup/code.html

* nice

  * toctree, branching to subdocs. could be generated hehe confix
  * ref link consistency (make linkcheck)
  * download jo oida
  * productionlist, token
    https://www.sphinx-doc.org/en/master/usage/restructuredtext/directives.html#directive-productionlist
  * program, option
  * python domains
    https://www.sphinx-doc.org/en/master/usage/restructuredtext/domains.html#the-python-domain

    py:currentmodule und so

    * currentmodule, function, method, saugeiel!
    * signatures leck!

  * sphinx.ext.autodoc

    * https://www.sphinx-doc.org/en/master/usage/extensions/autodoc.html#module-sphinx.ext.autodoc
    * https://sphinx-rtd-tutorial.readthedocs.io/en/latest/docstrings.html

  * ...

* Examples

  .. csv-table:: 
   :header: "view", "rtd", "source"

   "https://weijias-homepage.readthedocs.io/en/latest/Publications.html", "https://readthedocs.org/projects/weijias-homepage/", "https://github.com/sun031/weijia_website"

   https://million-ether-homepage.readthedocs.io/en/million-ether-homepage-1/earn.html
   https://readthedocs.org/projects/million-ether-homepage/
   https://github.com/porobov/Million-Ether-Homepage-Docs
   Navigation! globaltoc


Categories
----------

* Me. blah, maybe modify hmm
* Trainings. blah move over one by one 

  * Blah beginner linux commandline usage and system concepts
  * Sysprog eh kloa
  * Kernel? kernel-course that i found recently :-|
  * Python beginner
  * Python advanced
  * ...

* Blog

  * ablog
  * blog comments:
    https://ablog.readthedocs.io/manual/posting-and-listing.html,
    bottom of page.
