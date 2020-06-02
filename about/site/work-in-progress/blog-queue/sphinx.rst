Sphinx
======

pending_xref
------------

* a "post transform" is something that resolves
  references. apparently, because

  * ``BuildEnvironment.resolve_references()`` (called by
    ``Builder.write()`` calls back
    ``BuildEnvironment.get_and_resolve_doctree()``) calls
    ``apply_post_transforms()``. (Why not rename one of them?)
  * ``sphinx.addnodes.pending_xref``'s docstring says so.
  * ``BuildEnvironment.apply_post_transforms()`` emits
    ``'doctree-resolved'``
