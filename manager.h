//
// Created by geoki on 2/27/26.
//

#ifndef PROIECTINFO_MANAGER_H
#define PROIECTINFO_MANAGER_H
#include <string>

using namespace std;

class manager {
private:

public:
    struct item {
        string name, description;
        int count;
        double price;
    };

    struct items {
        int nr;
        item itemm[100];
    };

    manager();

    static void setline(int line, item item);
    static item getline(int line);
    static items getalllines();
    static void addline(item item);
    static void removeline(int line);
    static int getnumberoflines();
    static void changefile(string ff);

    static string getinfo();
    static string getversion();

    static void printitem(item item);
    static void printitems(items items);
};


#endif //PROIECTINFO_MANAGER_H