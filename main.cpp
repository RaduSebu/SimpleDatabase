#include <iostream>
#include <QApplication>
#include "manager.h"
#include "gui.h"
using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    manager m;

    manager::items items = m.getalllines();
    m.printitems(items);

    gui g;
    g.exec();

    return app.exec();
}