#include "Role.h"
#ifndef USERS_H
#define USERS_H
#include<bits/stdc++.h>
using namespace std;
class Users:public Role{
    public:
    Users();
    void showServices() override;
    static vector<Users>loadUsers();
};
#endif