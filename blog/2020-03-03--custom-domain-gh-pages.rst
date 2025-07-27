.. post:: Mar 3, 2020
   :category: sphinx


Adding a Custom Domain to a Github Pages Project Site
=====================================================

.. in ablog, apparently, <sphinx-gh-pages> is not a document
   name. have to reference absolutely.

In the :doc:`previous post </blog/2020-03-02--sphinx-gh-pages>` I
pushed generated static site content to `Github Pages
<https://pages.github.com/>`__, to be served as
`https://jfasch.github.io/jfasch-home-pages/
<https://jfasch.github.io/jfasch-home-pages/>`__.

Not being a marketing expert (the opposite is the case), I do suspect
that promoting that URL as my homepage would appear unprofessional. Rather,

* I own a domain, ``faschingbauer.me``
* To make things easy for people who have the intention of throwing
  money at me, I want to have the following URLs point to the above
  Github Pages site:

  * `http://www.faschingbauer.me <http://www.faschingbauer.me>`__
  * `https://www.faschingbauer.me <https://www.faschingbauer.me>`__
  * `http://faschingbauer.me <http://faschingbauer.me>`__
  * `https://faschingbauer.me <https://faschingbauer.me>`__

This is remarkably simple nowadays. The Github Pages documentation is
a little confusing: they only talk about user and organization pages,
and *not* about project pages. There are `numerous posts
<https://stackoverflow.com/questions/9082499/custom-domain-for-github-project-pages>`__
on the internet that suggest that adding a custom domain to a *project
page* has been cumbersome in the past - these days are over,
apparently. Following is what I did.

.. sidebar:: Contents

   .. contents::
      :local:

Configure a Subdomain, ``www.faschingbauer.me``
-----------------------------------------------

1. For the ``jfasch-home-pages`` project, configure a custom domain

   (Enforcing HTTPS also makes sense, while we are at it)

   .. image:: 2020-03-03--custom-domain-gh-pages/custom-domain.png

   All this does is to create a :file:`docs/CNAME`; pull the changes,

   .. code-block:: console

      $ cd $HOME/jfasch-home-pages
      $ git pull

2. Point ``www.faschingbauer.me`` to ``jfasch.github.io``

   At your DNS provider, create a ``CNAME`` DNS record for
   ``www.faschingbauer.me`` and set its value to point to
   ``jfasch.github.io``. Wait a day before you publish the new site
   URL - it may take some time until the changes have propagated to
   other name servers. Check like so,

   .. code-block:: console

      $ dig www.faschingbauer.me
      
      ;www.faschingbauer.me.		IN	A
      
      ;; ANSWER SECTION:
      www.faschingbauer.me.	1100	IN	CNAME	jfasch.github.io.
      jfasch.github.io.	3600	IN	A	185.199.109.153
      jfasch.github.io.	3600	IN	A	185.199.111.153
      jfasch.github.io.	3600	IN	A	185.199.110.153
      jfasch.github.io.	3600	IN	A	185.199.108.153
      
   (Output stripped for brevity.) In the ``ANSWER SECTION`` you can
   see that ``www.faschingbauer.me.`` (the trailing dot says this is a
   FQDN "Fully Qualified Domain Name") is an alias (``CNAME``) for
   ``jfasch.github.io.``. And btw., ``jfasch.github.io.`` has four
   addresses (``A``).

3. Done; surf to `https://www.faschingbauer.me
   <https://www.faschingbauer.me>`__.

Configure an Apex Domain, ``faschingbauer.me``
----------------------------------------------

We have the subdomain ``www.faschingbauer.me`` in place, pointing to
our site; now we want ``faschingbauer.me`` to go to the same
site. Github automatically, magically, apparently, redirects between
apex and subdomains. Consequentially, it is just a matter of DNS
configuration: at the DNS provider, arrange that ``faschingbauer.me``
points to one or more of Github's static IP addresses (taken from the
output of the above ``dig`` command). These are,

.. code-block:: console

   185.199.108.153
   185.199.109.153
   185.199.110.153
   185.199.111.153

Go to the DNS provider, and arrange that the DNS *address* (A) record
for ``faschingbauer.me`` points to one or all of these addresses.
