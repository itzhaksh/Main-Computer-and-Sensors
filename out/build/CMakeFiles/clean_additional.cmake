# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MainComputer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MainComputer_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\test_and_condition_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\test_and_condition_autogen.dir\\ParseCache.txt"
  "MainComputer_autogen"
  "test_and_condition_autogen"
  )
endif()
