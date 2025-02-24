#include<bits/stdc++.h>
using namespace std;
#include "User.h"

User::User(string fname, string lname, string email, int date, int month, int year, string address, string password, string role){
    this->fname=fname;
    this->lname=lname;
    this->email=email;
    this->date=date;
    this->month=month;
    this->year=year;
    this->address=address;
    this->password=password;
    this->role=role;

    dob=to_string(date)+'-'+to_string(month)+'-'+to_string(year);

}
void User::welcome(){
    cout<<"Hello, "<<fname<<"!"<<endl;
}
void User::display(){
    cout<<"Email: "<<email<<endl;
    cout<<"Date Of Birth: "<<dob<<endl;
    cout<<"Address: "<<address<<endl;
}
vector<User> User::loadUsers(){
    vector<User>users;
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