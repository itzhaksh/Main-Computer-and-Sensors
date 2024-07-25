target_link_libraries(MainComputer PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

target_sources(MainComputer PRIVATE
    Window.cpp
    ConditionWidgetsLayout.cpp
    ThenWidgetsLayout.cpp
    ConditionsBox.cpp
    ThenGroupBox.cpp
    ConditionsGroup.cpp
)