#ifndef ROLE_H
#define ROLE_H
#include<bits/stdc++.h>
using namespace std;

class Role{
    public:
    Role();
    virtual void showServices()=0;
    virtual ~Role();
};
#endif