#include<bits/stdc++.h>
using namespace std;
#include "User.h"

User::User(string fname, string lname, string email, int date, int month, int year, string address, string password){
    this->fname=fname;
    this->lname=lname;
    this->email=email;
    this->date=date;
    this->month=month;
    this->year=year;
    this->address=address;
    this->password=password;

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