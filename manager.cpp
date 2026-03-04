#include "manager.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
fstream f("data/database", ios::in | ios::out | ios::app);
string s;
using namespace std;
manager::manager() {
    if (f.is_open()) {
        std::cout << "File opened correctly\n";
    }
    else {
        f.close();
        f.open("data/database", ios::app);
        if (f.is_open()) {
            std::cout << "Created file\n";
        }
        else {
            std::cerr << "Error opening file\n";
        }
    }
};

void manager::setline(int line, item item) {
    f.close();
    f.open("data/database", ios::in);
    f.clear();

    vector<std::string> lines;

    while (std::getline(f, s)) {
        lines.push_back(s);
    }
    f.close();

    std::ostringstream sout;
    sout << item.name << ' ' << item.count << ' ' << item.price << ' ' << item.description;
    lines[line - 1] = sout.str();
    cout << "wrote line to file\n";

    f.open("data/database", ios::out | ios::trunc);
    for (string& l : lines) {
        f << l << "\n";
    }
}

manager::item manager::getline(int line) {
    f.close();
    f.open("data/database");
    f.clear();

    int i = 0;
    for (i; i < line; i++) {
        std::getline(f, s);
    }

    istringstream sin(s);
    item item;
    sin >> item.name >> item.count >> item.price >> item.description;
    return item;
}

manager::items manager::getalllines() {
    int i = 1;
    items items;
    for (int j = 1; j <= i; j++) {
        items.itemm[j] = getline(j);
        if (items.itemm[j].name.length() > 0) {
            i++;
        }
    }
    items.nr = i - 1;
    return items;
}

int manager::getnumberoflines() {
    int i = 1;
    while (getline(i).name.length() > 0) i++;
    return i - 1;
}

void manager::addline(item item) {
    items items = getalllines();
    setline(items.nr + 1, item);
}

string manager::getinfo() {
    return "Facut cu iubire de Radu Andrei Sebastian!";
}

void manager::printitem(item item) {
    ostringstream sout;
    sout << item.name << ' ' << item.count << ' ' << item.price << ' ' << item.description << endl;
    cout << sout.str();
}

void manager::printitems(items items) {
    for (int i = 1; i <= items.nr; i++) {
        printitem(items.itemm[i]);
    }
}
