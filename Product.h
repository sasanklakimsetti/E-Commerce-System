#ifndef PRODUCT_H
#define PRODUCT_H
#include<bits/stdc++.h>
using namespace std;
class Product{
    public:
    int PID;
    string pname, category, seller;
    double price;
    int quantity;
    Product(int PID, string pname, string category, string seller, double price, int quantity);
    void display();
    void registerProduct();
};
#endif