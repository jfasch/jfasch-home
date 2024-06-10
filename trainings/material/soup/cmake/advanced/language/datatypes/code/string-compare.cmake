set(lhs "Faschingbauer")
set(rhs "Zeilinger")

string(COMPARE LESS "${lhs}" "${rhs}" is_less)
message("${lhs} < ${rhs}: ${is_less}")
