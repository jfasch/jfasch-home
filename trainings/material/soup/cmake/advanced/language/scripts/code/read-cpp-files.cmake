set(input_directory "${INPUT_DIRECTORY}")

message("input_directory=${input_directory}")

file(GLOB cpp_files "${input_directory}/*.cpp")

foreach (cpp_file ${cpp_files})
  message("${cpp_file}")
endforeach()
