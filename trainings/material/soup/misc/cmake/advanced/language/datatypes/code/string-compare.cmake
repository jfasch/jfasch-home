set(lhs "Faschingbauer")
set(rhs "Zeilinger")

string(COMPARE LESS "${lhs}" "${rhs}" is_less)
if (is_less)
  message("${lhs} < ${rhs}")
endif()
