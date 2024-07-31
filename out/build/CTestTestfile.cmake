# CMake generated Testfile for 
# Source directory: C:/Users/itzha/source/repos/VehicleCompSim/MainComputer
# Build directory: C:/Users/itzha/source/repos/VehicleCompSim/MainComputer/out/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_and_condition "C:/Users/itzha/source/repos/VehicleCompSim/MainComputer/out/build/test_and_condition.exe")
set_tests_properties(test_and_condition PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/itzha/source/repos/VehicleCompSim/MainComputer/CMakeLists.txt;33;add_test;C:/Users/itzha/source/repos/VehicleCompSim/MainComputer/CMakeLists.txt;0;")
subdirs("src")
subdirs("include")
subdirs("GUI/src")
subdirs("GUI/include")
