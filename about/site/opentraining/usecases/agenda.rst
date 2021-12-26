.. include:: <mmlalias.txt>

Use Case: Compose Custom Training
=================================

Initial Customer Requirements
-----------------------------

A company is interested in a Python training. During an initial phone
call it becomes clear that they are interested in the following
topics,

* :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/group`
* :doc:`/trainings/material/soup/python/advanced/exceptions`
* :doc:`/trainings/material/soup/python/advanced/modules`

I promise them to come up with an agenda for the training.

Agenda Preparation
------------------

These four topics cannot be explained as they are, standing
alone. Rather, each topic has it own set of *prerequisite topics* that
must be explained *before* reaching the final topic. Those
prerequisite topics in turn have their own prerequisites.

Agenda preparation means to come up with a sequence of topics that
will be covered in the training. This is usually done manually. The
task is *error prone* and *time consuming*, which means that it is
usually also done half-heartedly - *bad work*.

Topics, together with their prerequisites, form an entire network of
topics. The *topic system*, at the heart of the project, formalizes
this information and makes it available to a number of tools.

Here you can see the structure of the hypothetical training that we
defined above. An arrow A |longrightarrow| B means that topic B must
be explained before topic A (A is said to *depend* on B).

.. ot-graph::
   :entries: python.advanced.python_1010_generators_yield,
	     python.advanced.oo,
	     python.advanced.exceptions,
	     python.advanced.modules

Based upon this knowledge, a tool can be used to *automatically*
generate an agenda.

* :doc:`/trainings/material/soup/python/basics/python_0140_variables/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`
* :doc:`/trainings/material/soup/python/basics/python_0270_functions/topic`
* :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/group`
* :doc:`/trainings/material/soup/python/advanced/exceptions`
* :doc:`/trainings/material/soup/python/basics/python_0225_range/topic`
* :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/topic`
* :doc:`/trainings/material/soup/python/advanced/modules`
