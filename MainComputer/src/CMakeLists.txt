target_link_libraries(MainComputer PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

target_sources(MainComputer PRIVATE
    Window.cpp
    IfWidgetsLayout.cpp
    ThenWidgetsLayout.cpp
    IfGroupBox.cpp
    ThenGroupBox.cpp
    SimpleCondition.cpp
    CompositeCondition.cpp
    OrCondition.cpp
    AndCondition.cpp
)