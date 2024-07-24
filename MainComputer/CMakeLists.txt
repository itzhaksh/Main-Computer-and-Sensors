cmake_minimum_required(VERSION 3.16)
project(MainComputer LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

qt_add_executable(MainComputer
    src/main.cpp
    include/Window.h
    include/IfWidgetsLayout.h
    include/ThenWidgetsLayout
    include/IfGroupBox
    include/ThenGroupBox
    include/SimpleCondition.h
    include/CompositeCondition.h
    include/OrCondition.h 
    include/AndCondition.h
    include/ConditionBase.h
)

add_subdirectory(src)
include_directories(include)

set_target_properties(MainComputer PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

install(TARGETS MainComputer
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET MainComputer
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})