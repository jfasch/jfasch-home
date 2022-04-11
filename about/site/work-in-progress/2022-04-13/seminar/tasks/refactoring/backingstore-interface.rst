.. ot-task:: clean_code.refactoring.backingstore_interface
   :dependencies: clean_code.refactoring.backingstore_monolithic


``BackingStore`` Responsibilities: Too Many Formats
===================================================

That ``BackingStore`` violates the "Open/Closed" principle.

Create an *interface*, and move the branches from the two ``switch``
statements into the respective methods of the two implementation.

