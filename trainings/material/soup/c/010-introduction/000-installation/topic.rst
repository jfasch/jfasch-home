.. include:: <mmlalias.txt>

.. ot-topic:: c.introduction.installation


Installation
============

On Windows
----------


* https://code.visualstudio.com/docs/cpp/config-mingw
* https://www.msys2.org/

* OS specific ``settings.json``. Won't work. VSCode still has no
  platform specific settings.
  
  * https://github.com/microsoft/vscode/issues/5595 (live)
  * https://github.com/microsoft/vscode/issues/17619

* https://github.com/microsoft/vscode-cmake-tools/blob/main/docs/cmake-settings.md

.. code-block:: console

   $ pacman -S mingw64/mingw-w64-x86_64-cmake


* `C/C++ for Visual Studio Code <https://code.visualstudio.com/docs/languages/cpp>`__

  * Especially, `install mingw-x64 compiler
    <https://code.visualstudio.com/docs/languages/cpp#_example-install-mingwx64>`__
  
* `CMake download <https://cmake.org/download/>`__
* `Get started with CMake Tools on Linux
  <https://code.visualstudio.com/docs/cpp/cmake-linux>`__
* GTest (optional):
  https://medium.com/swlh/google-test-installation-guide-for-c-in-windows-for-visual-studio-code-2b2e66352456

On Linux
--------

* Install Tools

  .. code-block:: console
     :caption: As root ...
  
     # dnf install gcc-c++ cmake gtest

* `C/C++ for Visual Studio Code <https://code.visualstudio.com/docs/languages/cpp>`__
* `Get started with CMake Tools on Linux
  <https://code.visualstudio.com/docs/cpp/cmake-linux>`__
