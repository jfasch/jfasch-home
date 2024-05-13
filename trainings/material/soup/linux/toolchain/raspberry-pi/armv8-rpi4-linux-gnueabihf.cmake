# the name of the target operating system
set(CMAKE_SYSTEM_NAME Linux)

# toolchain base directory (crosstool-ng toolchains bring the sysroot
# with them)
set(TOOLCHAIN_BASE_DIR /home/jfasch/x-tools/armv8-rpi4-linux-gnueabihf)

# which compilers to use for C and C++
set(CMAKE_C_COMPILER   ${TOOLCHAIN_BASE_DIR}/bin/armv8-rpi4-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_BASE_DIR}/bin/armv8-rpi4-linux-gnueabihf-g++)

# where is the target environment located. funny enough, this doesn't
# appear to influence the --sysroot compiler setting
set(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_BASE_DIR}/armv8-rpi4-linux-gnueabihf/sysroot)
set(CMAKE_SYSROOT        ${TOOLCHAIN_BASE_DIR}/armv8-rpi4-linux-gnueabihf/sysroot)

# adjust the default behavior of the FIND_XXX() commands:
# search programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# search headers and libraries in the target environment
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
