.. include:: <mmlalias.txt>


Replacing ``virtual`` With ``std::variant<>`` (In Real Life)
============================================================

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx/cxx03/inheritance-oo-design/index`
   * :doc:`/trainings/material/soup/cxx/cxx11/any-variant-optional/variant`

.. contents::
   :local:

Classic OO Design
-----------------

Source Hierarchy
................

.. literalinclude:: /trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-virtual/toolcase/source.h
   :caption: :download:`Interface: source.h
             </trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-virtual/toolcase/source.h>`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-virtual/toolcase/source-copyable.h
   :caption: :download:`Implementation: source-copyable.h
	     </trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-virtual/toolcase/source-copyable.h>`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-virtual/toolcase/source-movable.h
   :caption: :download:`Implementation: source-movable.h
             </trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-virtual/toolcase/source-movable.h>`
   :language: c++

Sink Hierarchy
..............

.. literalinclude:: /trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-virtual/toolcase/sink.h
   :caption: :download:`Interface: sink.h
	     </trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-virtual/toolcase/sink.h>`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-virtual/toolcase/sink-copyable.h
   :caption: :download:`Implementation: sink-copyable.h
	     </trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-virtual/toolcase/sink-copyable.h>`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-virtual/toolcase/sink-movable.h
   :caption: :download:`Implementation: sink-movable.h
	     </trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-virtual/toolcase/sink-movable.h>`
   :language: c++

Loop In The Middle
..................

.. literalinclude:: /trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-virtual/toolcase/loop.h
   :caption: :download:`loop.h
	     </trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-virtual/toolcase/loop.h>`
   :language: c++

Omitting ``virtual``: Cram All Alternatives Into ``std::variant<>``
-------------------------------------------------------------------

Source Non-Hierarchy
....................

.. literalinclude:: /trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/source.h
   :caption: :download:`Non-Interface: source.h
             </trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/source.h>`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/source-a.h
   :caption: :download:`Implementation: source-a.h
	     </trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/source-a.h>`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/source-b.h
   :caption: :download:`Implementation: source-b.h
             </trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/source-b.h>`
   :language: c++

Sink Non-Hierarchy
..................

.. literalinclude:: /trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/sink.h
   :caption: :download:`Non-Interface: sink.h
	     </trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/sink.h>`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/sink-1.h
   :caption: :download:`Implementation: sink-1.h
	     </trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/sink-1.h>`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/sink-2.h
   :caption: :download:`Implementation: sink-2.h
	     </trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/sink-2.h>`
   :language: c++

Loop In The Middle
..................

.. literalinclude:: /trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/loop.h
   :caption: :download:`loop.h
	     </trainings/material/soup/cxx/cxx-code/embedded-virtual-or-not/embedded-nonvirtual/loop.h>`
   :language: c++
