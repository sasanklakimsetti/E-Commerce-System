#include "Register.h"
#include "User.h"
#include<bits/stdc++.h>
using namespace std;
void Register::saveUserToFile(const User& user){
    ofstream file(userFile, ios::app);
    if(!file){
        cout<<"Error: Unable to open the file for saving the user data."<<endl;
        return;
    }
    file<<user.fname<<","<<user.lname<<","<<user.email<<","<<user.date<<","<<user.month<<","<<user.year<<","<<user.address<<","<<user.password<<"\n";
    file.close();
}
bool Register::userExists(string email){
    ifstream file(userFile);
    if(!file) return false;
    string line, storedEmail;
    while(getline(file,line)){
        stringstream ss(line);
        vector<string>userDetails;
        string field;
        while(getline(ss,field,',')){
            userDetails.push_back(field);
        }
        if(userDetails.size()>2){
            storedEmail=userDetails[2];
            if(storedEmail==email){
                file.close();
                return true;
            }
        }
    }
    file.close();
    return false;
}
int Register::getCurrentYear(){
    time_t now=time(0);
    tm*lm=localtime(&now);
    int currentYear=1900+lm->tm_year;
    return currentYear;
}
bool Register::validateAge(int year){
    return getCurrentYear()-year>=18;
}
bool Register::validatePassword(string password, string confirmPassword){
    if(password!=confirmPassword) return false;
    if(password.length()<6){
        cout<<"Password must be atleast 6 characters long"<<endl;
        return false;
    }
    return true;
}
int Register::calculateAge(int year){
    return getCurrentYear()-year;
}
bool Register::checkLeapYear(int year){
    return (year%400==0)||(year%100!=0&&year%4==0);
}
bool Register::validateDate(int date, int month, int year){
    if(month<1||month>12) return false;
    int daysInMonth;
    switch(month){
        case 2:
        daysInMonth=checkLeapYear(year)?29:28;
        break;
        case 4: case 6: case 9: case 11:
        daysInMonth=30;
        break;
        default:
        daysInMonth=31;
        break;
    }
    return date>=1&&date<=daysInMonth;
}
bool Register::registerUser(string fname, string lname, string email, int date, int month, int year, string address, string password, string confirmPassword){
    if(userExists(email)){
        cout<<"User with this email already exists!"<<endl;
        return false;
    }
    if(year>getCurrentYear()){
        cout<<"Year must be less than or equal to 2025"<<endl;
        return false;
    }
    if(!validateDate(date, month, year)){
        cout<<"Invalid date! Please enter a valid date for the given month and year."<<endl;
        return false;
    }
    if(!validateAge(year)) {
        cout<<"User must be atleast 18 years old to register."<<endl;
        return false;
    }
    if(!validatePassword(password,confirmPassword)) {
        cout<<"Passwords must be same. Please try again."<<endl;
        return false;
    }
    User newUser(fname, lname, email,date,month,year,address,password);
    saveUserToFile(newUser);
    cout<<"User registered successfully"<<endl;
    newUser.welcome();
    newUser.display();
    return true;
}

void Register::getUserDetails(){
    string fname, lname, email, address, password, confirmPassword;
    int date, month, year;
    cin.ignore();
    cout << "Enter First Name: ";
    getline(cin,fname);
    cout << "Enter Last Name: ";
    getline(cin,lname);
    cout << "Enter Email: ";
    getline(cin,email);
    cout << "Enter Date of Birth (DD MM YYYY): ";
    cin >> date >> month >> year;
    cin.ignore();
    cout << "Enter Address: ";
    cin.ignore();
    getline(cin, address);
    cin.ignore();
    cout << "Enter Password: ";
    cin >> password;
    cout << "Confirm Password: ";
    cin >> confirmPassword;
    registerUser(fname, lname, email, date, month, year, address, password, confirmPassword);
}