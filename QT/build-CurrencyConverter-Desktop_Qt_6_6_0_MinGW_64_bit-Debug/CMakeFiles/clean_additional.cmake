# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CurrencyConverter_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CurrencyConverter_autogen.dir\\ParseCache.txt"
  "CurrencyConverter_autogen"
  )
endif()
