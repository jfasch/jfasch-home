Use Case: Use Training Material From Other Sites
================================================

A colleague of mine has no "Python Basics" training in his repertoire,
but is an expert in Data Science. I have convinced him that
OpenTraining is the way to go, and motivated him to use the relevant
parts of my own Python training - which is maintained with
OpenTraining, naturally.

A straighforward approach for him to use my Python material would be
to *copy* it. This is dumb, for reasons that are the same as for why
copying source code is dumb.

What is needed is a mechanism where training sites (*his* and *mine*)
could exchange meta information like dependency data - a topic on
*his* site would depend on a topic on *my* site. When *his* site is
built, it would retrieve the metadata from *mine*, and the build
process would be able to check and compute everything that needs
computation.

(Clearly this mechanism will be implemented on top of the `Intersphinx
<https://www.sphinx-doc.org/en/master/usage/extensions/intersphinx.html>`__
Spinx extension.)
