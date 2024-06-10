set(some_name "Faschingbauer")

if (some_name STRLESS "Zeilinger")      # <--- better: "${some_name}" or ${some_name}
  message("yes")
endif()
