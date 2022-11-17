#include "Admin.h"

Admin::Admin() {
    next = NULL;
}
Admin::Admin(string user, string password) {
    this->user = user;
    this->password = password;
    next = NULL;
}

QLAdmin::QLAdmin() {
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
}

void QLAdmin::addTail(string user, string password) {
    Admin* pAdd = new Admin(user, password);
    if (head == NULL) {
        head = tail = pAdd;
    }
    else {
        tail->next = pAdd;
        tail = pAdd;
    }
    size++;
}

void QLAdmin::loadData(string fn) {
    ifstream ifile;
    ifile.open(fn);
    if (ifile.is_open()) {
        string str;

        while (getline(ifile, str)) {
            if (str[0] == '/' && str[1] == '/') continue;
            stringstream ss(str);
            string word;
            vector<string> admin;
            while (!ss.eof()) {
                getline(ss, word, ',');
                word.erase(word.find_last_not_of(" ") + 1);
                word.erase(0, word.find_first_not_of(" "));
                admin.push_back(word);
            }
            if (admin.size() == 2) {
                string acc = admin[0];
                string pass = admin[1];
                addTail(acc, pass);
            }
        }
    }
    ifile.close();
}

bool QLAdmin::checkAuth(string user, string password) {
    Admin* i = head;
    while (i != NULL) {
        if (i->user == user && i->password == password) return true;
        i = i->next;
    }
    return false;
}

void QLAdmin::display() {
    Admin* i = head;
    while (i != NULL) {
        cout << i->user << "\t\t" << i->password << endl;
        i = i->next;
    }
}