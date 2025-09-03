set(input_directory "${INPUT_DIRECTORY}")
set(output_file "${OUTPUT_FILE}")

message("input_directory=${input_directory}")

file(GLOB cpp_files "${input_directory}/*.cpp")

foreach (cpp_file ${cpp_files})
  cmake_path(GET cpp_file FILENAME base_cpp_file)
  file(APPEND "${output_file}" "${base_cpp_file}\n")
endforeach()
