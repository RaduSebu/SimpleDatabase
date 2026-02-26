#include <cstring>
#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget w;
    QVBoxLayout layout(&w);
    QPushButton list_button;
    QPushButton add_button;
    QPushButton remove_button;
    QPushButton info_button;
    QPushButton exit_button;

    list_button.setFixedSize(40,20);
    add_button.setFixedSize(40,20);
    remove_button.setFixedSize(40,20);
    info_button.setFixedSize(40,20);
    exit_button.setFixedSize(40,20);

    layout.addWidget(&list_button);
    layout.addWidget(&add_button);
    layout.addWidget(&remove_button);
    layout.addWidget(&info_button);
    layout.addWidget(&exit_button);



    w.setFixedSize(500,400);
    w.show();
    return QApplication::exec();
}