# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CarDashBoard_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CarDashBoard_autogen.dir\\ParseCache.txt"
  "CarDashBoard_autogen"
  "DataBase\\CMakeFiles\\databaseLibrary_autogen.dir\\AutogenUsed.txt"
  "DataBase\\CMakeFiles\\databaseLibrary_autogen.dir\\ParseCache.txt"
  "DataBase\\databaseLibrary_autogen"
  "Service\\CMakeFiles\\SeriviceLibrary_autogen.dir\\AutogenUsed.txt"
  "Service\\CMakeFiles\\SeriviceLibrary_autogen.dir\\ParseCache.txt"
  "Service\\SeriviceLibrary_autogen"
  )
endif()
