set(some_path "/path/to/parent")
cmake_path(APPEND some_path "child")
message("${some_path}")
