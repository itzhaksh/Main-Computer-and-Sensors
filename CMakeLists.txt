cmake_minimum_required(VERSION 3.16)
project(MainComputer LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

# Add main executable
qt_add_executable(MainComputer
    src/main.cpp
)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(GUI/src)
add_subdirectory(GUI/include)

# Add tests
file(GLOB TEST_FILES "${CMAKE_SOURCE_DIR}/tests/*.cpp")

# Add Doctest
file(GLOB DOCTEST_FILES "${CMAKE_SOURCE_DIR}/tests/doctest.h")
include_directories(${CMAKE_SOURCE_DIR}/tests)

# Add test executable
add_executable(test_and_condition ${TEST_FILES})
target_include_directories(test_and_condition PRIVATE ${CMAKE_SOURCE_DIR}/tests)
target_compile_definitions(test_and_condition PRIVATE DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)

# Enable testing and add test
enable_testing()
add_test(NAME test_and_condition COMMAND test_and_condition)

# Link libraries
target_link_libraries(MainComputer PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    MainComputerHeaders  
    GuiHeaders
)

# Set target properties
set_target_properties(MainComputer PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

# Install targets
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

# Additional settings
set(CMAKE_CTEST_ARGUMENTS "--output-on-failure")
