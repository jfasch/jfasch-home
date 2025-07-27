.. post:: Mar 2, 2020
   :category: sphinx


Deploying Sphinx Generated Documentation to Github Pages
========================================================

.. sidebar:: Contents

   .. contents::
      :local:

`Github Pages <https://pages.github.com/>`__, a hosting service for
static webpages, is free and easy, although run by Microsoft
[#well_theres_marketing]_. Times are changing.

It took me a while to figure out how to use the service properly,
although, retrospectively, it hasn't been so hard. The main points
were,

* Github Pages, by default, *builds* the stuff you push using `Jekyll
  <https://jekyllrb.com/>`__. I don't use Jekyll; rather I generate my
  site locally, and want to upload *generated content only*. This is
  the topic of this post.
* The uploaded content is then served as
  `https://jfasch.github.io/jfasch-home-pages/
  <https://jfasch.github.io/jfasch-home-pages/>`__. Bending things to
  serve it as `https://www.faschingbauer.me
  <https://www.faschingbauer.me>`__ is the topic of a :doc:`companion
  post </blog/2020-03-03--custom-domain-gh-pages>`.

Create "Site Publication Repo"
------------------------------

.. important::

   No, we do *not* pollute our `source repo
   <https://github.com/jfasch/jfasch-home>`__ (I refer to the local
   clone as ``jfasch-home``) with binary content, as Github
   suggests. Rather, we distinguish *content* (which is handwritten)
   from artifacts that are created during the build.

   This reminds me of a company I worked for many years ago:
   
   * They had a huge pile of incomprehensible C/C++ code.
   * They built all that in the source tree (no, not with `CMake
     <https://cmake.org/>`__, or `Meson <https://mesonbuild.com/>`__,
     or `Automake <https://www.gnu.org/software/automake/>`__ or
     anything else that can do out-of-source builds - but with another
     huge pile of incomprehensible Doze ``cmd`` code.).
   * They committed the build output. **Yes**: every build they made
     was a record in their version control system. The same repo that
     contained the source.
   * **Effect**: developers did not develop most of their time, but
     wait for VC operations. Rational Clearcase can be blamed for many
     things, but not for that.
   * The company does not exist anymore.

*So*, in parallel to the ``jfasch-home`` local copy of `the upstream
Github repo <https://github.com/jfasch/jfasch-home>`__, I create
another `Github repo <https://github.com/jfasch/jfasch-home-pages>`__
(cloned locally as ``jfasch-home-pages``). The intent is to use the
``jfasch-home-pages/docs/`` subdirectory as a *deployment location*
for the Sphinx-generated output from ``jfasch-home`` - *one
commit/push per deployment*.

Test that, by populating ``jfasch-home-pages`` with dummy HTML
content. Ah, Jekyll: we provide static files which are not source
code, technically, so we do not want Github to build our site with
Jekyll. This is what the ``.nojekyll`` file tells them to - *suppress
build*.

.. code-block:: console

   $ mkdir docs/
   $ cat <<EOF > docs/index.html
   <!DOCTYPE html>
   <head>
     <title>Dummy</title>
   </head>
   
   <body>
     <p>Hmm. Appears to work.</p>
   </body>
   </html>
   EOF
   $ touch docs/.nojekyll
   $ git add docs/index.html docs/.nojekyll
   $ git commit -am test
   $ git push

Maybe check on the Github page that the upstream content matches what
we just created.

Configure Github Pages for ``jfasch-home-pages``
------------------------------------------------

Go to the upstream deployment repo on Github,
`https://github.com/jfasch/jfasch-home-pages
<https://github.com/jfasch/jfasch-home-pages>`__. Make sure you are
logged in (I made that mistake and did not find the "Settings" tab :-)
). Go to the "Settings" tab.

We intend to serve content from ``docs/`` - the *Publishing Source* in
Github terminology -, so select "master branch / docs folder". Scroll
to the "Github Pages" section, and select that constellation.

.. image:: 2020-03-02--sphinx-gh-pages/master-docs.png

.. note::

   * You will not see the "Your site is published at ..." message
     immediately; the Github deployment machinery takes a while.
   * If the message appears, eventually, an innocent click on the link
     may lead to a 404 error. Edit the URL in the bar to explicitly
     add ``.../index.html``, or wait another few minutes for things to
     come in order (I do not have to understand why).

Time for Deployment
-------------------

Everything is in place now,

* We have a local ``$HOME/jfasch-home`` (say) clone (and its upstream
  repository that we work from)
* We have an `upstream
  <https://github.com/jfasch/jfasch-home-pages>`__
  ``https://github.com/jfasch/jfasch-home-pages`` repository; new
  revisions that are pushed are automatically deployed to pages.
* We have its local ``$HOME/jfasch-home-pages`` clone.

Lets perform the deployment dance for the first time; this will be
repeated for all further deployments. (This cries for scripting, but
that's another story.)

1. Build homepage, locally, with Sphinx

   .. code-block:: console

      $ cd $HOME/jfasch-home
      $ make html

2. (Optional) In the deployment repo, backup the :file:`docs/CNAME`
   file

   If you don't know what this is then you probably haven't configured
   a *custom subdomain* for your Github Pages project. See :doc:`here
   </blog/2020-03-02--sphinx-gh-pages>` for how that works. This step
   can be added as an afterthough so lets omit it for now, remembering
   that we have to preserve the :file:`docs/CNAME` file once we add a
   custom domain.

   .. code-block:: console

      $ cd $HOME/jfasch-home-pages
      $ cp docs/CNAME /tmp/

3. Remove existing site, and copy new site

   .. code-block:: console

      $ cd $HOME/jfasch-home-pages
      $ git rm -r docs/
      $ cp -r $HOME/jfasch-home/_build/html/ docs/
      $ touch docs/.nojekyll

4. (Optional) Restore :file:`docs/CNAME`

   .. code-block:: console

      $ cp /tmp/CNAME docs/

5. Deploy (i.e. commit and push)

   .. code-block:: console

      $ git add --all docs/
      $ git commit -am 'shiny new homepage version'
      $ git push

Wait a while. You may nervously poll the "Settings" tab of the
upstream deployment repo if you want, until machinery is done.

.. rubric:: Footnotes

.. [#well_theres_marketing] Well ok, if you view `their entry page
			    <https://pages.github.com>`__, all that
			    Marketingese sounds familiar.
