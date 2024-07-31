#include <QApplication>

#include "Window.h"

int main(int argv, char* args[])
{
    QApplication app(argv, args);
    Window window;
    window.show();
    return app.exec();
}

/*
[+] [dropdown] [condition] [value] // A
    [and]
[+]     [dropdown] [condition] [value] // B
        [or]
[+]     [dropdown] [condition] [value] // C
    [and]
    [dropdown] [condition] [value] // D

[then] [dropdown] [value]
*/
