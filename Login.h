#ifndef LOGIN_H
#define LOGIN_H
#include<bits/stdc++.h>
using namespace std;
class Login{
    private:
    string email, password;
    const string userFile="users.csv";
    public:
    Login();
    bool authenticateUser();
    void getUserDetails();
};
#endif