#ifndef LOGIN_H
#define LOGIN_H
#include "Role.h"
#include<bits/stdc++.h>
using namespace std;
class Login{
    private:
    string email, password;
    //Role *getRoleByType(const string &roleType);
    // const string adminFile="admins.csv";
    // const string userFile="users.csv";
    public:
    Login();
    bool authenticateUser();
    void getUserDetails();
    bool isAdmin(string email);
    void displayAdminDashboard();
    void displayUserDashboard();
    void displaySellerDashboard();
};
#endif