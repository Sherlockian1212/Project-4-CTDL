#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Admin {
private:
    friend class QLAdmin;
    string user;
    string password;
    Admin* next;
public:
    Admin();
    Admin(string user, string password);
};

class QLAdmin {
private:
    Admin* head;
    Admin* tail;
    int size;
public:
    QLAdmin();

    void addTail(string user, string password);

    void loadData(string fn);

    bool checkAuth(string user, string password);

    void display();
};