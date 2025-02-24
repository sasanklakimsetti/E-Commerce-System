#include "Admin.h"
#include "Product.h"
#include "User.h"
#include "Register.h"
#include<bits/stdc++.h>
using namespace std;
// Admin::Admin(){}
Admin::Admin(string fname, string lname, string email, int date, int month, int year, string address, string password)
    : User(fname, lname, email, date, month, year, address, password, "admin") {}
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
        auto it = remove_if(products.begin(), products.end(), [&](Product &p) { return p.id == id; });
        if (it != products.end()) {
            products.erase(it, products.end());
            Product::registerProduct(products);
            cout << "Product removed successfully." << endl;
        } 
        else cout << "Product not found." << endl;
    }
    else if (choice == 3) {
        string id;
        cout << "Enter Product ID to update: ";
        cin >> id;

        for (auto &p : products) {
            if (p.id == id) {
                cout << "Enter new Name, Category, Price, Quantity: ";
                cin >> p.name >> p.category >> p.price >> p.quantity;  // Removed seller update
                Product::registerProduct(products);
                cout << "Product updated successfully!" << endl;
                return;
            }
        }
        cout << "Product not found!" << endl;
    }
    else{
        cout<<"Invalid choice"<<endl;
    }
}
void Admin::manageUsers(){
    vector<User>users=User::loadUsers();
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
        auto it = remove_if(users.begin(), users.end(), [&](User &u) { return u.email == email; });
        if (it != users.end()) {
            users.erase(it, users.end());
            cout << "User removed successfully!" << endl;
        } else {
            cout << "User not found!" << endl;
        }
    }
    else {
        cout<<"Invalid choice!"<<endl;
        //manageUsers();
    }
}
void Admin::manageAdmins(){
    vector<Admin>admins=loadAdmins();
    int choice;
    cout<<"\n1. Add a new admin\n2. Remove an admin"<<endl;
    cin>>choice;
    if(choice==1){
        cout<<(addAdmin()?"Admin added successfully\n":"Couldn't add new admin\n");
    }
    else if(choice==2){
        vector<Admin>admins=loadAdmins();
        string email;
        cout<<"Enter email of the admin to be deleted: "; getline(cin,email);
        auto it = remove_if(admins.begin(), admins.end(), [&](Admin &a) { return a.email == email; });
        if (it != admins.end()) {
            admins.erase(it, admins.end());
            cout << "Admin removed successfully!" << endl;
        } else {
            cout << "Admin not found!" << endl;
        }
    }
    else cout<<"Invalid choice!"<<endl;
}
void Admin::showServices(){
    cout<<"Admin Services.\n";
    cout<<"1. Manage Admins\n";
    cout<<"2. Manage Users\n";
    cout<<"3. Manage Products\n";
    cout<<"4. View Transactions\n";
}
bool Admin::addAdmin(){
    ofstream file(adminFile, ios::app);
    string fname, lname, email, address, password, confirmPassword;
    int date, month, year;
    cin.ignore();
    cout<<"Enter First Name: "; getline(cin,fname);
    cout<<"Enter Last Name: "; getline(cin,lname);
    cout<<"Enter email: "; getline(cin,email);
    cout << "Enter Date of Birth (DD MM YYYY): "; cin >> date >> month >> year;
    cin.ignore();
    cout << "Enter Address: "; getline(cin, address);
    cout << "Enter Password: "; cin >> password;
    cout << "Confirm Password: "; cin >> confirmPassword;

    return Register::registerUser(fname, lname, email, date, month, year, address, password, confirmPassword, "admin", "admins.csv");
}
vector<Admin>Admin::loadAdmins(){
    vector<Admin>admins;
    ifstream file(adminFile);
    if(!file) return admins;
    string line, fname, lname, email, date, month, year, address, password;
    while(getline(file, line)){
        stringstream ss(line);
        if (!(getline(ss, fname, ',') && getline(ss, lname, ',') && getline(ss, email, ',') &&
              ss >> date && ss.ignore() && ss >> month && ss.ignore() && ss >> year &&
              ss.ignore() && getline(ss, address, ',') && getline(ss, password, ','))) {
            cout << "Invalid admin details!" << endl;
            continue;
        }
        admins.emplace_back(fname, lname, email, date, month, year, address, password);
    }
    file.close();
    return admins;
}