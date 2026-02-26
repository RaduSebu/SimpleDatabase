#include <cstring>
#include <iostream>
#include "gui.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);


    gui interface;
    interface.exec();

    return app.exec();
}