#include "Window.h"

#include <iostream>
#include <fstream>

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
    std::ofstream file("temp.txt");
    
    file << "Window::save" << std::endl;

    _ConditionsBox->data(file);

    file.close();
}
