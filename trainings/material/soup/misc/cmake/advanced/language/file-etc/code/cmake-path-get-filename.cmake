set(full_path "/home/jfasch/My-Projects/jfasch-home/trainings/material/soup/cmake/advanced/language/file-etc/code/file1.cpp")
cmake_path(GET full_path FILENAME filename_part)
message("${filename_part}")
