#ifndef CART_H
#define CART_H
#include "Product.h"
#include<bits/stdc++.h>
using namespace std;
class Cart{
    public:
    vector<Product>products;
    double totalValue;
    Cart();
    void addToCart(Product product);
    void displayCart();
    void removeFromCart(const string& productName, int removeQuantity);
    void calculateTax(double taxRate);
    void checkout();
};
#endif