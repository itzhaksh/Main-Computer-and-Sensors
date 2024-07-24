#include "Window.h"

Window::Window()
{
    setWindowTitle("Main Computer");
    
    _ifGroupBox = new IfGroupBox;
    _thenGroupBox = new ThenGroupBox;

    _windowLayout = new QVBoxLayout;
    _windowLayout->addWidget(_ifGroupBox);
    _windowLayout->addWidget(_thenGroupBox);
    _windowLayout->addStretch(1);

    setLayout(_windowLayout);
}
