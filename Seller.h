#ifndef SELLER_H
#define SELLER_H
#include "Role.h"
#include<bits/stdc++.h>
using namespace std;
class Seller:public Role{
    public:
    Seller();
    void showServices() override;
};
#endif