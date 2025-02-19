#ifndef CATEGORY_H
#define CATEGORY_H
#include<bits/stdc++.h>
using namespace std;
class Category{
    public:
    int CID;
    string cname;
    double discount, tax;
    Category(int CID, string cname, double discount, double tax);
    void display();
};
#endif