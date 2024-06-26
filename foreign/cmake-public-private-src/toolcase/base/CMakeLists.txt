set(_public_inc_files 

  include/public/sensor.h
  include/public/sensor-const.h
  include/public/sensor-random.h
  include/public/sensor-avg.h
  include/public/sensor-w1.h
  include/public/switch.h
  include/public/sysfs-switch.h
  include/public/hysteresis.h
)

set(_private_inc_files

  include/private/file-util.h
)

set(_src_files

  src/sensor-const.cpp
  src/sensor-random.cpp
  src/sensor-avg.cpp
  src/sensor-w1.cpp
  src/sysfs-switch.cpp
  src/hysteresis.cpp

  src/file-util.cpp
)

add_library(
  base

  ${_public_inc_files}
  ${_private_inc_files}
  ${_src_files}
)

target_include_directories(base PUBLIC ./include/public)
target_include_directories(base PRIVATE ./include/private)

install(TARGETS base DESTINATION lib)
install(FILES ${_public_inc_files} DESTINATION include)
