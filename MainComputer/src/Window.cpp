#include "Window.h"

Window::Window()
{
    setWindowTitle("Main Computer");
    
    _ConditionsGroupBox = new ConditionsGroupBox;
    _thenGroupBox = new ThenGroupBox;

    _windowLayout = new QVBoxLayout;
    _windowLayout->addWidget(_ConditionsGroupBox);
    _windowLayout->addWidget(_thenGroupBox);
    _windowLayout->addStretch(1);

    setLayout(_windowLayout);
}
