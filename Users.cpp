#include "Users.h"
#include<bits/stdc++.h>
using namespace std;
Users::Users(){
    showServices();
}
void Users::showServices(){
    cout << "\nUser Services\n";
    cout << "1. Browse Products\n";
    cout << "2. Buy Products\n";
    cout << "3. Cancel Orders\n";
    cout<<"4. View Cart\n";
}
vector<Users> Users::loadUsers(){
    vector<Users>users;
    ifstream file("users.csv");
    if(!file){
        cout<<"Error accessing user data"<<endl;
        return users;
    }
    string line, fname, lname, email, date, month, year, password, address, role;
    while(getline(file, line)){
        stringstream ss(line);
        if(!getline(ss,fname,'n')||!getline(ss,lname,',')||!getline(ss,email,',')||getline(ss,date,',')||!getline(ss,month,',')||!getline(ss,year,',')||!getline(ss,address,',')||!getline(ss,password,',')||!getline(ss,role,',')){
            cout<<"Warning: Skipping invalid product entry!"<<endl;
            continue;
        }
        users.emplace_back(fname, lname, email, date, month, year, address, password, role);
    }
    file.close();
    return users;
}