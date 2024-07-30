#include "Window.h"

#include <iostream>

Window::Window()
{
    setWindowTitle("Main Computer");
    
    _ConditionsBox = new ConditionsBox;
    _thenGroupBox = new ThenGroupBox;

    _saveButton = new QPushButton("save");
    connect(_saveButton, &QPushButton::clicked, this, &Window::save);

    _windowLayout = new QVBoxLayout;
    _windowLayout->addWidget(_ConditionsBox);
    _windowLayout->addWidget(_thenGroupBox);
    _windowLayout->addStretch(1);
    _windowLayout->addWidget(_saveButton);

    setLayout(_windowLayout);
}

void Window::save()
{
    
}
