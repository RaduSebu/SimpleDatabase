#include <cstring>
#include <iostream>
#include "gui.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    gui *interface = new gui();
    interface->exec();

    return QApplication::exec();
}