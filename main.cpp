#include <cstring>
#include <iostream>
using namespace std;

char commandText[10];
int commandKey;

int command() {
    cin.getline(commandText, 10);
    if (strcmp(commandText, "exit") == 0) {
        return 0;
    }
    else if (strcmp(commandText, "info") == 0) {
        return 1;
    }
    else if (strcmp(commandText, "add") == 0) {
        return 2;
    }
    else if (strcmp(commandText, "remove") == 0) {
        return 3;
    }
    else if (strcmp(commandText, "list") == 0) {
        return 4;
    }
    else return -1;
}


int main() {
    commandKey = command();
    while (commandKey != 0) {
        if (commandKey == 1) {
            cout << "Member list:" << endl << "Radu Andrei Sebastian" << endl;
        }
        else if (commandKey == -1) {
            cout << "Invalid command!" << endl;
        }
        commandKey = command();
    }
    return 0;
}