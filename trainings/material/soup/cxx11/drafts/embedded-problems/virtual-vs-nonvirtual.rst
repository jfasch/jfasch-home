.. ot-topic:: cxx11.embedded_problems.virtual_vs_nonvirtual
   :dependencies: cxx11.miscellaneous.variant, cxx03.inheritance_oo.interface

.. include:: <mmlalias.txt>


Replacing ``virtual`` With ``std::variant<>`` (In Real Life)
============================================================

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/group`
   * :doc:`/trainings/material/soup/cxx11/100-miscellaneous/any-variant-optional/variant`

.. contents::
   :local:

Classic OO Design
-----------------

Source Hierarchy
................

.. literalinclude:: /trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-virtual/source.h
   :caption: :download:`Interface: source.h
             </trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-virtual/source.h>`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-virtual/source-a.h
   :caption: :download:`Implementation: source-a.h
	     </trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-virtual/source-a.h>`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-virtual/source-b.h
   :caption: :download:`Implementation: source-b.h
             </trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-virtual/source-b.h>`
   :language: c++

Sink Hierarchy
..............

.. literalinclude:: /trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-virtual/sink.h
   :caption: :download:`Interface: sink.h
	     </trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-virtual/sink.h>`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-virtual/sink-1.h
   :caption: :download:`Implementation: sink-1.h
	     </trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-virtual/sink-1.h>`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-virtual/sink-2.h
   :caption: :download:`Implementation: sink-2.h
	     </trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-virtual/sink-2.h>`
   :language: c++

Loop In The Middle
..................

.. literalinclude:: /trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-virtual/loop.h
   :caption: :download:`loop.h
	     </trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-virtual/loop.h>`
   :language: c++

Omitting ``virtual``: Cram All Alternatives Into ``std::variant<>``
-------------------------------------------------------------------

Source Non-Hierarchy
....................

.. literalinclude:: /trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/source.h
   :caption: :download:`Non-Interface: source.h
             </trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/source.h>`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/source-a.h
   :caption: :download:`Implementation: source-a.h
	     </trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/source-a.h>`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/source-b.h
   :caption: :download:`Implementation: source-b.h
             </trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/source-b.h>`
   :language: c++

Sink Non-Hierarchy
..................

.. literalinclude:: /trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/sink.h
   :caption: :download:`Non-Interface: sink.h
	     </trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/sink.h>`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/sink-1.h
   :caption: :download:`Implementation: sink-1.h
	     </trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/sink-1.h>`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/sink-2.h
   :caption: :download:`Implementation: sink-2.h
	     </trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/sink-2.h>`
   :language: c++

Loop In The Middle
..................

.. literalinclude:: /trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/loop.h
   :caption: :download:`loop.h
	     </trainings/material/soup/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/loop.h>`
   :language: c++
