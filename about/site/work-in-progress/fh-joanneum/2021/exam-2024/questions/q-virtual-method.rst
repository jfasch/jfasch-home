To Be Or Not To Be Virtual
==========================

Program Output, Version 1
-------------------------

What will be the output of the following program? (Write an ``X`` in
the "True" or "False" columns)

.. literalinclude:: q-virtual-method/nonvirtual.cpp
   :language: c++

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * True
     * False
     * Possible output
   * *
     *
     * .. code-block:: console

          Derived::method()
          Derived::method()
   * *
     *
     * .. code-block:: console

          Derived::method()
          Base::method()

Program Output, Version 2
-------------------------

What will be the output of the following program? (Write an ``X`` in
the "True" or "False" columns)

.. literalinclude:: q-virtual-method/virtual.cpp
   :language: c++

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * True
     * False
     * Possible output
   * *
     *
     * .. code-block:: console

          Derived::method()
          Derived::method()
   * *
     *
     * .. code-block:: console

          Derived::method()
          Base::method()
