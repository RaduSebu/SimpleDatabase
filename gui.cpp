#include "gui.h"
#include "manager.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QDialog>
#include <QIcon>
#include <algorithm>
int n = 0;

bool cmp1(manager::item a, manager::item b) {
    return (strcmp(a.name.c_str(), b.name.c_str()) < 0);
}

bool cmp2(manager::item a, manager::item b) {
    return (strcmp(a.name.c_str(), b.name.c_str()) > 0);
}

bool cmp3(manager::item a, manager::item b) {
    return (a.count > b.count);
}

bool cmp4(manager::item a, manager::item b) {
    return (a.count < b.count);
}

bool cmp5(manager::item a, manager::item b) {
    return (a.price > b.price);
}

bool cmp6(manager::item a, manager::item b) {
    return (a.price < b.price);
}


void gui::execute() {
    QWidget *window = new QWidget();
    QHBoxLayout *layouth = new QHBoxLayout();
    QVBoxLayout *layoutv1 = new QVBoxLayout();
    QVBoxLayout *layoutv2 = new QVBoxLayout();
    QIcon icon = QIcon("data/Icon.jpg");

    QListWidget *list = new QListWidget();
    QLabel *label = new QLabel("[NAME]   [COUNT]   [PRICE]   [DESCRIPTION]");
    QLabel *picture = new QLabel();
    picture->setPixmap(QPixmap(icon.pixmap(100,100)));
   QPushButton *buttonAdd = new QPushButton("ADD");
    QPushButton *buttonEdit = new QPushButton("EDIT");
    QPushButton *buttonRemove = new QPushButton("REMOVE");
    QPushButton *buttonCount = new QPushButton("ITEM COUNT");
    QPushButton *buttonRefresh = new QPushButton("REFRESH");
    QPushButton *buttonInfo = new QPushButton("INFO");
    QPushButton *buttonSort = new QPushButton("SORT");

    layoutv1->addWidget(buttonAdd);
    layoutv1->addWidget(buttonEdit);
    layoutv1->addWidget(buttonRemove);
    layoutv1->addWidget(buttonSort);
    layoutv1->addWidget(buttonCount);
    layoutv1->addStretch();
    layoutv1->addWidget(picture);
    layoutv1->addWidget(buttonInfo);

    layoutv2->addWidget(label);
    layoutv2->addWidget(list);
    layoutv2->addWidget(buttonRefresh);

    layouth->addLayout(layoutv1);
    layouth->addLayout(layoutv2);

    window->setWindowTitle("Simple Database");
    window->setLayout(layouth);
    window->setBaseSize(600, 500);
    window->setWindowIcon(icon);
    for (int i = 1; i < manager::getnumberoflines() + 1; i++) {
        std::ostringstream sout;
        manager::item item = manager::getline(i);
        sout << item.name << "  |  " << item.count << "  |  " << item.price << "  |  " << item.description;

        QString s;
        s.assign(sout.str());

        list->addItem(s);
    }

    QObject::connect(buttonRefresh, &QPushButton::clicked, [list]() {
        list->clear();

        for (int i = 1; i < manager::getnumberoflines() + 1; i++) {
            std::ostringstream sout;
            manager::item item = manager::getline(i);
            sout << item.name << "  |  " << item.count << "  |  " << item.price << "  |  " << item.description;

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
        labelInfo->setFixedSize(400,50);
        labelInfo->show();
    });

    QObject::connect(buttonCount, &QPushButton::clicked, []() {
        std::ostringstream ss;
        ss << "Number of items: " << manager::getnumberoflines();
        QString s;
        s.assign(ss.str());
        QLabel *labelInfo = new QLabel(s);
        labelInfo->setFixedSize(300,50);
        labelInfo->show();
    });

    QObject::connect(buttonRemove, &QPushButton::clicked, [list]() {
        QListWidgetItem* selected = list->currentItem();
        if (selected == nullptr) return;

        int line = list->row(selected) + 1;
        manager::removeline(line);
    });

    QObject::connect(buttonAdd, &QPushButton::clicked, [list]() {
        QDialog *dialog = new QDialog();
        dialog->setWindowTitle("Add Item");
        dialog->setFixedSize(300,200);

        QVBoxLayout *layout = new QVBoxLayout();

        QLineEdit *inputName = new QLineEdit();
        QLineEdit *inputCount = new QLineEdit();
        QLineEdit *inputPrice = new QLineEdit();
        QLineEdit *inputDescription = new QLineEdit();

        inputName->setPlaceholderText("Name");
        inputCount->setPlaceholderText("Count");
        inputPrice->setPlaceholderText("Price");
        inputDescription->setPlaceholderText("Description");

        QPushButton *buttonConfirm = new QPushButton("CONFIRM");
        QPushButton *buttonCancel = new QPushButton("CANCEL");

        QHBoxLayout *buttons = new QHBoxLayout();
        buttons->addWidget(buttonCancel);
        buttons->addWidget(buttonConfirm);

        layout->addWidget(inputName);
        layout->addWidget(inputCount);
        layout->addWidget(inputPrice);
        layout->addWidget(inputDescription);
        layout->addLayout(buttons);

        dialog->setLayout(layout);

        QObject::connect(buttonConfirm, &QPushButton::clicked, [=]() {
            manager::item newItem;

            newItem.name = inputName->text().toStdString();
            newItem.count = inputCount->text().toInt();
            newItem.price = inputPrice->text().toDouble();
            newItem.description = inputDescription->text().toStdString();

            manager::addline(newItem);

            dialog->close();
        });

        QObject::connect(buttonCancel, &QPushButton::clicked, [=]() {
            dialog->close();
        });
        dialog->show();
    });

    QObject::connect(buttonEdit, &QPushButton::clicked, [list]() {
        QListWidgetItem* selected = list->currentItem();
        if (!selected) return;

        int line = list->row(selected) + 1;
        manager::item item = manager::getline(line);

        QDialog *dialog = new QDialog();
        dialog->setWindowTitle("Edit Item");
        dialog->setFixedSize(300,200);
        QVBoxLayout *layout = new QVBoxLayout();

        QLineEdit *inputName = new QLineEdit(QString::fromStdString(item.name));
        QLineEdit *inputCount = new QLineEdit(QString::number(item.count));
        QLineEdit *inputPrice = new QLineEdit(QString::number(item.price));
        QLineEdit *inputDescription = new QLineEdit(QString::fromStdString(item.description));

        QPushButton *buttonConfirm = new QPushButton("CONFIRM");
        QPushButton *buttonCancel = new QPushButton("CANCEL");

        QHBoxLayout *buttons = new QHBoxLayout();
        buttons->addWidget(buttonCancel);
        buttons->addWidget(buttonConfirm);

        layout->addWidget(inputName);
        layout->addWidget(inputCount);
        layout->addWidget(inputPrice);
        layout->addWidget(inputDescription);
        layout->addLayout(buttons);

        dialog->setLayout(layout);

        QObject::connect(buttonConfirm, &QPushButton::clicked, [=]() {
            manager::item newItem;

            newItem.name = inputName->text().toStdString();
            newItem.count = inputCount->text().toInt();
            newItem.price = inputPrice->text().toDouble();
            newItem.description = inputDescription->text().toStdString();

            manager::setline(line, newItem);
            dialog->close();
        });

        QObject::connect(buttonCancel, &QPushButton::clicked, [=]() {
            dialog->close();
        });
        dialog->show();
    });

    QObject::connect(buttonSort, &QPushButton::clicked, [list]() {
        list->clear();

        manager::item items[10000];

        for (int i = 1; i < manager::getnumberoflines() + 1; i++) {
            items[i] = manager::getline(i);
        }

        if (n % 7 == 0) {
            sort(items, items + manager::getnumberoflines() + 1, cmp1);
        }
        else if (n % 7 == 1) {
            sort(items, items + manager::getnumberoflines() + 1, cmp2);
        }
        else if (n % 7 == 2) {
            sort(items, items + manager::getnumberoflines() + 1, cmp3);
        }
        else if (n % 7 == 3) {
            sort(items, items + manager::getnumberoflines() + 1, cmp4);
        }
        else if (n % 7 == 4) {
            sort(items, items + manager::getnumberoflines() + 1, cmp5);
        }
        else if (n % 7 == 5) {
            sort(items, items + manager::getnumberoflines() + 1, cmp6);
        }

        n++;

        for (int i = 1; i < manager::getnumberoflines() + 1; i++) {
            std::ostringstream sout;
            manager::item item = items[i];

            sout << item.name << "  |  " << item.count << "  |  " << item.price << "  |  " << item.description;

            QString s;
            s.assign(sout.str());
            list->addItem(s);
        }
    });

    window->show();
}
