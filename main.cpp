#include <fstream>
#include <iostream>
#include <QApplication>
#include "manager.h"
#include "gui.h"

using namespace std;
fstream ff("database", ios::in | ios::out);

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    manager m;
    manager::item item = m.getline(0);
    cout << item.name;

    gui *interface = new gui();
    interface->exec();

    return QApplication::exec();
}