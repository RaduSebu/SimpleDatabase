#include "gui.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>
#include <QSpacerItem>

void gui::execute() {
    QWidget *window = new QWidget();
    QHBoxLayout *layouth = new QHBoxLayout();
    QVBoxLayout *layoutv = new QVBoxLayout();
    QVBoxLayout *layoutBut = new QVBoxLayout();

    QListWidget *list = new QListWidget();

    QPushButton *button1 = new QPushButton("ADD");
    QPushButton *button2 = new QPushButton("EDIT");
    QPushButton *button3 = new QPushButton("REMOVE");
    QPushButton *button4 = new QPushButton("REFRESH");
    QPushButton *button5 = new QPushButton("INFO");

    layoutBut->addWidget(button1);
    layoutBut->addWidget(button2);
    layoutBut->addWidget(button3);
    layoutBut->addStretch();
    layoutBut->addWidget(button4);
    layoutBut->addWidget(button5);

    layouth->addLayout(layoutBut);
    layouth->addWidget(list);

    window->setWindowTitle("Simple Database");
    window->setLayout(layouth);
    window->show();
}
