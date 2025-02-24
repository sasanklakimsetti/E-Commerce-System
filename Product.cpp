#include "Product.h"
#include<bits/stdc++.h>
using namespace std;
Product::Product(string id, string name, string category, string seller, double price, int quantity){
    this->id=id;
    this->name=name;
    this->category=category;
    this->seller=seller;
    this->price=price;
    this->quantity=quantity;
}
void Product::displayProducts(){
    vector<Product>products=loadProducts();
    if(products.empty()){
        cout<<"No products available."<<endl;
        return ;
    }
    cout << "\nAvailable Products:\n";
    cout << "----------------------------------------------------\n";
    cout << "ID\tName\tCategory\tSeller\tPrice\tStock\n";
    cout << "----------------------------------------------------\n";
    
    for (auto &p : products) {
        cout << p.id << "\t" << p.name << "\t" << p.category << "\t" << p.seller
             << "\t₹" << p.price << "\t" << p.quantity << endl;
    }
    cout << "----------------------------------------------------\n";

}
// register this product in the database
void Product::registerProduct(const vector<Product>&products){
    ofstream file("products.csv", ios::app);
    if(!file){
        cout<<"Error opening file!\n";
        return ;
    }
    for (auto &p : products) {
        if (p.id.empty() || p.name.empty() || p.category.empty() || p.seller.empty()) {
            cout << "Error: Invalid product data, skipping entry..." << endl;
            continue;
        }
        file << p.id << "," << p.name << "," << p.category << "," << p.seller
             << "," << p.price << "," << p.quantity << endl;
    }
    file.close();
    cout<<"Product(s) registered successfully!"<<endl;
}
// loading the products from csv
vector<Product>Product::loadProducts(){
    vector<Product>products;
    ifstream file("products.csv");
    if(!file) return products;
    string line, id, name, category, seller, priceStr, qtyStr;
    while (getline(file, line)) {
        stringstream ss(line);
        if (!getline(ss, id, ',') || !getline(ss, name, ',') || !getline(ss, category, ',') ||
            !getline(ss, seller, ',') || !getline(ss, priceStr, ',') || !getline(ss, qtyStr, ',')) {
            cout << "Warning: Skipping invalid product entry!" << endl;
            continue;
        }
        try {
            double price = stod(priceStr);
            int quantity = stoi(qtyStr);
            products.emplace_back(id, name, category, seller, price, quantity);
        } catch (exception &e) {
            cout << "Error: Skipping invalid data row!" << endl;
            continue;
        }
    }
    file.close();
    return products;
}