#include "Product.h"
#include<bits/stdc++.h>
using namespace std;
Product::Product(int PID, string pname, string category, string seller, double price, int quantity){
    this->PID=PID;
    this->pname=pname;
    this->category=category;
    this->seller=seller;
    this->price=price;
    this->quantity=quantity;
}
void Product::display(){
    cout<<"Name: "<<pname<<endl;
    cout<<"Category: "<<category<<endl;
    cout<<"Seller: "<<seller<<endl;
    cout<<"Price: "<<price<<endl;
    cout<<"Quantity: "<<quantity<<endl;
}
// register this product in the database
void Product::registerProduct(){
}