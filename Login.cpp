#include "Login.h"
#include<bits/stdc++.h>
using namespace std;
Login::Login(){}
bool Login::authenticateUser(){
    ifstream file(userFile);
    if(!file){
        cout<<"No user data found. Please register first."<<endl;
        return false;
    }
    string line, storedEmail, storedPassword;
    while(getline(file,line)){
        stringstream ss(line);
        vector<string>userDetails;
        string field;
        while(getline(ss,field,',')){
            userDetails.push_back(field);
        }
        if(userDetails.size()>7){
            storedEmail=userDetails[2];
            storedPassword=userDetails[7];
            if(storedEmail==email&&storedPassword==password){
                cout<<"\nLogin successful! Welcome, "<<userDetails[0]<<" "<<userDetails[1]<<endl;
                file.close();
                return true;
            }
        }
    }
    file.close();
    cout<<"Invalid email or password!"<<endl;
    return false;
}
void Login::getUserDetails(){
    string email, password;
    cin.ignore();
    cout<<"Enter email: ";
    getline(cin,this->email);
    cout << "Enter Password: ";
    cin >> this->password;
    authenticateUser();
}