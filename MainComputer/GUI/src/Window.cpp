#include "Window.h"

Window::Window()
{
    setWindowTitle("Main Computer");
    
    _ConditionsBox = new ConditionsBox;
    _thenGroupBox = new ThenGroupBox;

    _windowLayout = new QVBoxLayout;
    _windowLayout->addWidget(_ConditionsBox);
    _windowLayout->addWidget(_thenGroupBox);
    _windowLayout->addStretch(1);

    setLayout(_windowLayout);
}
