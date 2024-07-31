include(C:/Users/itzha/source/repos/VehicleCompSim/MainComputer/out/build/.qt/QtDeploySupport.cmake)
include("${CMAKE_CURRENT_LIST_DIR}/MainComputer-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_ALL_MODULES_FOUND_VIA_FIND_PACKAGE "ZlibPrivate;EntryPointPrivate;Core;Gui;Widgets")

qt6_deploy_runtime_dependencies(
    EXECUTABLE C:/Users/itzha/source/repos/VehicleCompSim/MainComputer/out/build/MainComputer.exe
    GENERATE_QT_CONF
)
