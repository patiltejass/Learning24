# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\dvc_trac_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\dvc_trac_autogen.dir\\ParseCache.txt"
  "Database\\CMakeFiles\\Database_autogen.dir\\AutogenUsed.txt"
  "Database\\CMakeFiles\\Database_autogen.dir\\ParseCache.txt"
  "Database\\Database_autogen"
  "Service\\CMakeFiles\\service_autogen.dir\\AutogenUsed.txt"
  "Service\\CMakeFiles\\service_autogen.dir\\ParseCache.txt"
  "Service\\service_autogen"
  "dvc_trac_autogen"
  )
endif()
