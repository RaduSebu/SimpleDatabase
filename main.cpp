#include <cstring>
#include <iostream>
#include <QApplication>
#include <QPushButton>
using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QPushButton button("Salut din Qt pe Arch!");
    button.resize(300, 120);
    button.show();

    return QApplication::exec();
}