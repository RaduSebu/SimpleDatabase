#include "manager.h"
#include <fstream>
#include <iostream>
#include <sstream>
fstream f("database", ios::in | ios::out);
string s, sp[1000000];
using namespace std;
manager::manager() = default;

void manager::setline(int line, item item) {
    ostringstream sout;
    sout << item.name << ' ' << item.count << ' ' << item.price << ' ' << item.description;
}

manager::item manager::getline(int line) {
    int i = 0;
    while (std::getline(f, s)) {
        i++;
        if (i == line) {
            break;
        }
    }
    istringstream sin(s);
    cout << s;
    item item;
    sin >> item.name >> item.count >> item.price >> item.description;
    return item;
}

manager::items manager::getalllines() {
    int i = 0;
    item item[1000000];
    while (std::getline(f, sp[i])) {
        i++;
        istringstream sin(sp[i]);
        sin >> item[i].name >> item[i].count >> item[i].price >> item[i].description;
    }
    items items;
    for (int j = 0; j <= i; j++) {
        items.itemm[j] = item[j];
    }
    items.nr = i;
    return items;
}

void manager::addline(item item) {

}

string manager::getinfo() {
    return "Facut cu iubire de Radu Andrei Sebastian!";
}
