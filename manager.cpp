#include "manager.h"
#include <fstream>
#include <iostream>
#include <sstream>
string s, sp[1000000];
using namespace std;
manager::manager() {};

void manager::setline(int line, item item) {
    fstream f("database");
    f.clear();
    f.seekg(0);
    f.seekp(0);

    if (f.is_open()) {
        std::cout << "File opened correctly\n";
    }
    else {
        std::cerr << "Error opening file\n";
    }

    int i = 1;

    ostringstream sout;
    sout << item.name << ' ' << item.count << ' ' << item.price << ' ' << item.description;

    while (std::getline(f, s)) {
        if (i == line) {
            s = sout.str();
        }
        f << s << "\n";
        i++;
    }
    f.close();
}

manager::item manager::getline(int line) {
    fstream f("database");
    f.clear();
    f.seekg(0);
    f.seekp(0);

    if (f.is_open()) {
        std::cout << "File opened correctly\n";
    }
    else {
        std::cerr << "Error opening file\n";
    }

    int i = 0;
    for (i; i < line; i++) {
        std::getline(f, s);
    }

    istringstream sin(s);
    cout << s;
    item item;
    sin >> item.name >> item.count >> item.price >> item.description;
    f.close();
    return item;
}

manager::items manager::getalllines() {
    fstream f("database");
    f.clear();
    f.seekg(0);
    f.seekp(0);

    if (f.is_open()) {
        std::cout << "File opened correctly\n";
    }
    else {
        std::cerr << "Error opening file\n";
    }

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
    f.close();
    return items;
}

void manager::addline(item item) {

}

string manager::getinfo() {
    return "Facut cu iubire de Radu Andrei Sebastian!";
}
