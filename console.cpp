#include "console.h"
#include <iostream>
#include <qguiapplication_platform.h>

#include "manager.h"
using namespace std;
string command;
void console::execute() {
    cout << R"(
 _____   ____    ____
/ ___/  |  _ \  | __ )
\___ \  | | | | |  _ \
 ___) | | |_| | | |_) |
|____/  |____/  |____/
Simple Database
)";
    cout << "[sdb]: ";
    cin >> command;
    while (command != "exit") {
        if (command == "list") {
            cout << "[NAME] [COUNT] [PRICE] [DESCRIPTION]\n";
            manager::printitems(manager::getalllines());
        }
        else if (command == "add") {
            string name, description;
            int count;
            double price;
            manager::item item;

            cout << "Name: "; cin >> name;
            cout << "Count: "; cin >> count;
            cout << "Price: "; cin >> price;
            cout << "Description: "; cin >> description;

            item.name = name;
            item.price = price;
            item.description = description;
            item.count = count;

            manager::addline(item);
        }
        else if (command == "remove") {
            string name;
            cout << "Name: "; cin >> name;

            for (int i = 1; i <= manager::getnumberoflines() + 1; i++) {
                if (i == manager::getnumberoflines() + 1) {
                    cout << "No such item\n";
                    break;
                }

                if (manager::getline(i).name == name) {
                    manager::removeline(i);
                    cout << name << " removed\n";
                    break;
                }
            }
        }
        else if (command == "edit") {
            string setting;
            cout << "What to set: "; cin >> setting;
            if (setting == "price") {
                double price;
                string name;

                cout << "Item: "; cin >> name;
                cout << "Price: "; cin >> price;

                for (int i = 1; i <= manager::getnumberoflines() + 1; i++) {
                    if (i == manager::getnumberoflines() + 1) {
                        cout << "No such item";
                        break;
                    }

                    if (manager::getline(i).name == name) {
                        manager::item item;
                        item.price = price;

                        item.name = manager::getline(i).name;
                        item.description = manager::getline(i).description;
                        item.count = manager::getline(i).count;
                        item.price = manager::getline(i).price;

                        manager::setline(i, item);
                        cout << name << " price changed to " << price << '\n';
                        break;
                    }
                }
            }
            else if (setting == "count") {
                int count;
                string name;

                cout << "Item: "; cin >> name;
                cout << "Count: "; cin >> count;

                for (int i = 1; i <= manager::getnumberoflines() + 1; i++) {
                    if (i == manager::getnumberoflines() + 1) {
                        cout << "No such item";
                        break;
                    }

                    if (manager::getline(i).name == name) {
                        manager::item item;
                        item.count = count;

                        item.name = manager::getline(i).name;
                        item.description = manager::getline(i).description;
                        item.price = manager::getline(i).price;

                        manager::setline(i, item);
                        cout << name << " count changed to " << count << '\n';
                        break;
                    }
                }
            }
            else if (setting == "description") {
                string description;
                string name;

                cout << "Item: "; cin >> name;
                cout << "Description: "; cin >> description;

                for (int i = 1; i <= manager::getnumberoflines() + 1; i++) {
                    if (i == manager::getnumberoflines() + 1) {
                        cout << "No such item";
                        break;
                    }

                    if (manager::getline(i).name == name) {
                        manager::item item;
                        item.description = description;

                        item.name = manager::getline(i).name;
                        item.count = manager::getline(i).count;
                        item.price = manager::getline(i).price;

                        manager::setline(i, item);
                        cout << name << " description changed to " << description << '\n';
                        break;
                    }
                }
            }
            else if (setting == "name") {
                string newname;
                string name;

                cout << "Item: "; cin >> name;
                cout << "NewName: "; cin >> newname;

                for (int i = 1; i <= manager::getnumberoflines() + 1; i++) {
                    if (i == manager::getnumberoflines() + 1) {
                        cout << "No such item";
                        break;
                    }

                    if (manager::getline(i).name == name) {
                        manager::item item;
                        item.name = newname;

                        item.description = manager::getline(i).description;
                        item.count = manager::getline(i).count;
                        item.price = manager::getline(i).price;

                        manager::setline(i, item);
                        cout << name << " name changed to " << newname << '\n';
                        break;
                    }
                }
            }
            else cout << "No such field";
        }
        else if (command == "help") {
            cout << "List of available commands:\nadd, remove, list, edit, info, exit, help\n";
        }
        else if (command == "info") {
            cout << manager::getinfo() << '\n';
        }
        else {
            cout << "No such command";
        }
        cout << "[sdb]: ";
        cin >> command;
    }
}
