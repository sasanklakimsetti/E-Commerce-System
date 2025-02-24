#include "Admin.h"
#include "Product.h"
#include "Users.h"
#include "Register.h"
#include<bits/stdc++.h>
using namespace std;
Admin::Admin(){
    showServices();
}
void Admin::manageProducts(){
    vector<Product>products=Product::loadProducts();
    int choice; cout<<"\n1. Add Product\n2. Remove Product\n3. Update Product\nEnter Choice: ";
    cin>>choice;
    if(choice==1){
        string id, name, category, seller;
        double price;
        int quantity;
        cout<<"Enter ID, Name, Category, Seller, Price, Quantity: ";
        cin>>id>>name>>category>>seller>>price>>quantity;
        products.emplace_back(id, name, category, seller, price, quantity);
        Product::registerProduct(products);
        cout<<"Product added successfully!"<<endl;
    }
    else if(choice==2){
        string id;
        cout<<"Enter Product ID to remove: "; cin>>id;
        products.erase(remove_if(products.begin(), products.end(),[&](Product &p){return p.id==id;}), products.end());
        Product::registerProduct(products);
        cout<<"Product removed."<<endl;
    }
    else if(choice==3){
        string id;
        cout<<"Enter Product ID to update: "; cin>>id;
        for(auto &p:products){
            if(p.id==id){
                cout<<"Enter new Name, Category, Price, Quantity: ";
                cin>>p.name>>p.category>>p.seller>>p.price>>p.quantity;
            }
        }
    }
}
void Admin::manageUsers(){
    vector<Users>users=Users::loadUsers();
    int choice;
    cout<<"\n1. Add user\n2. Remove user\n";
    cin>>choice;
    if(choice==1){
        Register::getUserDetails();
        cout<<"User added successfully"<<endl;
    }
    else if(choice==2){
        string email;
        cout<<"Enter the user with email to be deleted: "; getline(cin, email);
        //users.erase(remove_if(users.begin(), users.end(),[&](Users &u){return u.email==email}), users.end());
        
    }

}
void Admin::showServices(){
    cout<<"Admin Services.\n";
    cout<<"1. Manage Admins\n";
    cout<<"2. Manage Users\n";
    cout<<"3. Manage Products\n";
    cout<<"4. View Transactions\n";
}