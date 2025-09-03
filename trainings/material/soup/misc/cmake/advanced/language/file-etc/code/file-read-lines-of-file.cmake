file(STRINGS "/etc/passwd" passwd_lines)
foreach(line ${passwd_lines})
  message("${line}")
endforeach()
