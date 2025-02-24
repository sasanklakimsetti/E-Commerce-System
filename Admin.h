#ifndef ADMIN_H
#define ADMIN_H
#include "Role.h"
#include "User.h"
#include<bits/stdc++.h>
using namespace std;
class Admin:public Role, public User{
    public:
    const string adminFile="admins.csv";
    string email;
    Admin();
    Admin(string fname, string lname, string email, int date, int month, int year, string address, string password);
    void showServices() override;
    void manageProducts();
    void manageUsers();
    void manageAdmins();
    bool addAdmin();
    vector<Admin>loadAdmins();
};
#endif