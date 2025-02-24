#ifndef ADMIN_H
#define ADMIN_H
#include "Role.h"
#include<bits/stdc++.h>
using namespace std;
class Admin:public Role{
    public:
    Admin();
    void showServices() override;
    void manageProducts();
    void manageUsers();
};
#endif