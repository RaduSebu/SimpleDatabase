//
// Created by geoki on 2/27/26.
//

#ifndef PROIECTINFO_MANAGER_H
#define PROIECTINFO_MANAGER_H
#include <string>

using namespace std;

class manager {
private:
    string selection;
    struct item {
        string name, description;
        int price, count, id;
    };
    void setline(int line, item item);
    item getline(int line);
    item getalllines();
    void addline(item item);
public:
    manager();
    void additem (item item);
    void removeitem (int id);
    item readitem(int id);
    string getinfo();
};


#endif //PROIECTINFO_MANAGER_H