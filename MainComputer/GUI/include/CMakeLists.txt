cmake_minimum_required(VERSION 3.16)

project(MainComputerHeaders LANGUAGES CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(HEADER_FILES
    Window.h
    ConditionWidgetsLayout.h
    ThenWidgetsLayout.h
    ConditionsBox.h
    ThenGroupBox.h
    ConditionsGroup.h
)

add_library(GuiHeaders INTERFACE)
target_sources(GuiHeaders INTERFACE ${HEADER_FILES})
target_include_directories(GuiHeaders INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

install(FILES ${HEADER_FILES} DESTINATION include)
