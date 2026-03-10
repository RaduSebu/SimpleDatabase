#include "gui.h"
#include "manager.h"
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
    QVBoxLayout *layoutv1 = new QVBoxLayout();
    QVBoxLayout *layoutv2 = new QVBoxLayout();

    QListWidget *list = new QListWidget();
    QLabel *label = new QLabel("[NAME]   [COUNT]   [PRICE]   [DESCRIPTION]");

    QPushButton *buttonAdd = new QPushButton("ADD");
    QPushButton *buttonEdit = new QPushButton("EDIT");
    QPushButton *buttonRemove = new QPushButton("REMOVE");
    QPushButton *buttonRefresh = new QPushButton("REFRESH");
    QPushButton *buttonInfo = new QPushButton("INFO");

    layoutv1->addWidget(buttonAdd);
    layoutv1->addWidget(buttonEdit);
    layoutv1->addWidget(buttonRemove);
    layoutv1->addStretch();
    layoutv1->addWidget(buttonInfo);

    layoutv2->addWidget(label);
    layoutv2->addWidget(list);
    layoutv2->addWidget(buttonRefresh);

    layouth->addLayout(layoutv1);
    layouth->addLayout(layoutv2);

    window->setWindowTitle("Simple Database");
    window->setLayout(layouth);
    window->setBaseSize(600, 500);
    window->setFixedSize(600,500);

    for (int i = 1; i < manager::getnumberoflines() + 1; i++) {
        std::ostringstream sout;
        manager::item item = manager::getline(i);
        sout << item.name << ' ' << item.count << ' ' << item.price << ' ' << item.description;

        QString s;
        s.assign(sout.str());

        list->addItem(s);
    }

    QObject::connect(buttonRefresh, &QPushButton::clicked, [list]() {
        list->clear();

        for (int i = 1; i < manager::getnumberoflines() + 1; i++) {
            std::ostringstream sout;
            manager::item item = manager::getline(i);
            sout << item.name << ' ' << item.count << ' ' << item.price << ' ' << item.description;

            QString s;
            s.assign(sout.str());

            list->addItem(s);
        }
    });

    QObject::connect(buttonInfo, &QPushButton::clicked, []() {
        std::ostringstream ss;
        ss << manager::getversion() << '\n' << manager::getinfo();
        QString s;
        s.assign(ss.str());
        QLabel *labelInfo = new QLabel(s);
        labelInfo->setFixedSize(300,50);
        labelInfo->show();
    });

    window->show();
}
