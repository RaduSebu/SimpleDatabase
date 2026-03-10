#include <iostream>
#include <QApplication>

#include "console.h"
#include "manager.h"
#include "gui.h"
using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    if (argc == 1 || !strcmp(argv[1], "--help") || !strcmp(argv[1], "-h")) {
        cout << "Usage:\n-h --help shows this\n-g --gui shows gui version of program\n-t --terminal shows terminal version of program\n-v --version shows version info\n-i --info shows info about the creator";
        return 0;
    }
    else if (argc > 1 && (!strcmp(argv[1], "--terminal") || !strcmp(argv[1], "-t"))) {
        console::execute();
        return 0;
    }
    else if (argc > 1 && (!strcmp(argv[1], "--graphical") || !strcmp(argv[1], "-g"))) {
        gui::execute();
        return app.exec();
    }
    else if (argc > 1 && (!strcmp(argv[1], "--version") || !strcmp(argv[1], "-v"))) {
        cout << manager::getversion();
        return 0;
    }
    else if (argc > 1 && (!strcmp(argv[1], "--info") || !strcmp(argv[1], "-i"))) {
        cout << manager::getinfo();
        return 0;
    }
    else if (argc > 1) {
        cout << "Invalid usage\nrefer to -h or --help for command usage";
        return 2;
    }
}