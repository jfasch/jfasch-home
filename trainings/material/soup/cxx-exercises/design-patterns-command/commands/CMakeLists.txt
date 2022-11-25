ADD_LIBRARY(
  cxx-exercises-design-patterns-command-commands

  social-db-commands.h
  social-db-commands.cpp
)  

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-design-patterns-command-commands
  
  PUBLIC
  .
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-design-patterns-command-commands

  cxx-exercises-socialdb
)
