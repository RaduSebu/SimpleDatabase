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
        int nr{};
        item itemm[1000000];
    };

    manager();

    static void setline(int line, item item);
    static item getline(int line);
    static items getalllines();
    static void addline(item item);

    void additem (item item);
    void removeitem (int id);
    item readitem(int id);
    string getinfo();
};


#endif //PROIECTINFO_MANAGER_H