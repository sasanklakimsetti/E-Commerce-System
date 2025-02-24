#ifndef PRODUCT_H
#define PRODUCT_H
#include<bits/stdc++.h>
using namespace std;
class Product{
    public:
    string id, name, category, seller;
    double price;
    int quantity;
    Product(string id, string name, string category, string seller, double price, int quantity);
    static vector<Product>loadProducts();
    static void displayProducts();
    static void registerProduct(const vector<Product>&products);
};
#endif