find_package(SQLite3)

# to be substituted as C macros
if (SQLite3_FOUND)
  set(CONFIG_HAVE_SQLITE3 1)
else()
  set(CONFIG_HAVE_SQLITE3 0)
endif()
