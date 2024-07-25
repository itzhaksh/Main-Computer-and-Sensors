cmake_minimum_required(VERSION 3.16)

project(MainComputerHeaders LANGUAGES CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(HEADER_FILES
    SimpleCondition.h
    CompositeCondition.h
    conditionsManager.h
    ConditionBase.h
    OrCondition.h
    AndCondition.h
)

add_library(MainComputerHeaders INTERFACE)
target_sources(MainComputerHeaders INTERFACE ${HEADER_FILES})
target_include_directories(MainComputerHeaders INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

install(FILES ${HEADER_FILES} DESTINATION include)
