# Install script for directory: C:/Users/itzha/source/repos/VehicleCompSim/MainComputer/GUI/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/MainComputer")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "C:/Users/itzha/source/repos/VehicleCompSim/MainComputer/GUI/include/Window.h"
    "C:/Users/itzha/source/repos/VehicleCompSim/MainComputer/GUI/include/SingleCondition.h"
    "C:/Users/itzha/source/repos/VehicleCompSim/MainComputer/GUI/include/ThenWidgetsLayout.h"
    "C:/Users/itzha/source/repos/VehicleCompSim/MainComputer/GUI/include/ConditionsBox.h"
    "C:/Users/itzha/source/repos/VehicleCompSim/MainComputer/GUI/include/ThenGroupBox.h"
    "C:/Users/itzha/source/repos/VehicleCompSim/MainComputer/GUI/include/ConditionsGroup.h"
    "C:/Users/itzha/source/repos/VehicleCompSim/MainComputer/GUI/include/ConditionLayoutBase.h"
    )
endif()

