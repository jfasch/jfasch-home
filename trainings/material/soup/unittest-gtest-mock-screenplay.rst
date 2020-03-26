Screenplay: Unittest: GTest Mocks
=================================

.. sidebar:: Contents

   .. contents::
      :local:
      :depth: 1

   **Code**: :doc:`unittest-gtest-mock-code/index`

.. todo::

   This needs some more work

This is going to be larger, and it spans multiple files. The code
directory contains the final version; here's a sequence of steps how
to get there.

First Step
----------

* ``EEPROM`` interface, like so:

  .. code-block:: c++

     class EEPROM
     {
     public:
         virtual ~EEPROM() {}
     
         virtual void write(uint32_t offset, const void* data, uint32_t size) = 0;
         virtual void read(uint32_t offset, void* data, uint32_t size) const = 0;
     };
          
* ``NameValueStore`` implemention, doing nothing, like so:

  .. code-block:: c++

     class NameValueStore
     {
     public:
         NameValueStore(EEPROM*);
     
         void set(const std::string& name, const std::string& value);
         std::string get(const std::string& name);
     
     private:
         EEPROM* eeprom_;
     };
     
* A test that fails. It will setup ``NameValueStore`` with an
  ``EEPROM`` that can't take anything (size: 0 bytes), and then store
  a name/value pair. We fill figure how to handle that error, letting
  us drive by the tests. *Test Driven Development*.

  .. code-block:: c++

     TEST(EEPROM_RangeViolations, ZeroSize)
     {
         FAIL() << "to be implemented";
     }
     
