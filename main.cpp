#include <fstream>
#include <iostream>
#include <QApplication>
#include "manager.h"
#include "gui.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    manager m;
    manager::item item;
    item.name = "ok";
    item.count = 1;
    item.price = 1.5;
    item.description = "un_item";
    manager::setline(1, item);

    manager::item item2 = manager::getline(1);
    cout << item2.name << endl;
    cout << item2.count << endl;
    cout << item2.price << endl;
    cout << item2.description << endl;

    return 0;
}