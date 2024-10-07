add_executable(
  embedded-firmware-virtual
  firmware.cpp
)

target_link_libraries(
  embedded-firmware-virtual
  embedded-virtual-toolcase
)
