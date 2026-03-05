#include <iostream>
#include <QApplication>
#include "manager.h"
#include "gui.h"
using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    manager m;

    m.getline(1);

    gui g;
    g.exec();

    return app.exec();
}